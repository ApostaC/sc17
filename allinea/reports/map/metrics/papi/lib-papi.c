/*
 * An Allinea metric plugin library for reading PAPI metrics for the main thread.
 * PAPI metrics for non-main threads are not tracked.
 */

#include "lib-papi.h"
#include "papi.h"

#include <string.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

#define ONE_SECOND_NS      1000000000   // The number of nanoseconds in one second
#define UNSET_INDEX              -999   // Value used for an event counter index before the counter has been given either a valid index or an PAPI error code
#define MAX_NUM_EVENTS              5   // Maximum number of hardware counters that will be used by this library

#define SET_NAME_MAX_LEN 100            // The maximum size of the name of the metric set
static char set[SET_NAME_MAX_LEN];      // The name of the metric set to be used

static const int ERRNO = -1; // Returned by a function when there is an error
static const int minHardwareCountersForExtendedOverview = 5; // # hardware counters required for gathering metrics for the 'extended overview' content

static int maxHardwareCounters = -1;            // The number of hardware counters available on this system
static int papiEventSet        = PAPI_NULL;     // Handle to an event set created with PAPI_create_eventset()
static long long eventValues[MAX_NUM_EVENTS];   // Array of event values (see below for the values stored at each index)

// Indexes of the event counter values in eventValues elements
static int dpOpsIndex  = UNSET_INDEX; // Double precision floating-point operations
static int totInsIndex = UNSET_INDEX; // Total instructions
static int totCycIndex = UNSET_INDEX; // Total cycles

static int fpInsIndex  = UNSET_INDEX; // Floating-point instructions
static int intInsIndex = UNSET_INDEX; // Integer instructions
static int brInsIndex  = UNSET_INDEX; // Branch instructions
static int vecInsIndex = UNSET_INDEX; // Vector instructions

static int brMspIndex  = UNSET_INDEX; // Mispredicted branch instructions

static int vecSpIndex  = UNSET_INDEX; // SP vector instructions
static int vecDpIndex  = UNSET_INDEX; // DP vector instructions

static int l1TcmIndex  = UNSET_INDEX; // L1 total cache misses
static int l2TcmIndex  = UNSET_INDEX; // L2 total cache misses
static int l3TcmIndex  = UNSET_INDEX; // L3 total cache misses

static int l1DcmIndex  = UNSET_INDEX; // L1 data cache misses
static int l2DcmIndex  = UNSET_INDEX; // L2 data cache misses
static int l3DcmIndex  = UNSET_INDEX; // L3 data cache misses

// Integer constat used to represet the 'Overview' metric set internally
static const int METRIC_SET_OVERVIEW     = 10001;
// Integer constat used to represet the 'CacheMisses' metric set internally
static const int METRIC_SET_CACHE_MISSES = 10002;
// Integer constat used to represet the 'BranchInstructions' metric set internally
static const int METRIC_SET_BRANCH_INSTR = 10003;
// Integer constat used to represet the 'VectorInstructions' metric set internally
static const int METRIC_SET_FLOAT_INSTR  = 10004;

// The currently enabled metric set. One of the above METRIC_SET_* constants.
static int enabledMetricSet = 0;



//! Returns the thread id of the calling thread
static unsigned long int allinea_get_thread_id()
{
    return syscall(__NR_gettid);
}

//! Initialise PAPI
/*!
 *  This function will initialise the PAPI library and check that it was initialised correctly. It will then enable
 *  thread support in the PAPI library.
 *
 *  \param[in] plugin_id
 *      The ID of the plugin (used for setting error messages).
 *  \return
 *       0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_initialise_papi(plugin_id_t plugin_id)
{
    // Initialise the library and check the initialisation was successful
    int retval = PAPI_library_init(PAPI_VER_CURRENT);
    if (retval != PAPI_VER_CURRENT  &&  retval > 0)
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "PAPI library version mismatch. PAPI error: %s", PAPI_strerror(retval));
        return ERRNO;
    }
    if (retval < 0)
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "Could not initialise PAPI library. PAPI error: %s", PAPI_strerror(retval));
        return ERRNO;
    }
    retval = PAPI_is_initialized();
    if (retval != PAPI_LOW_LEVEL_INITED)
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "PAPI incorrectly initialised. PAPI error: %s", PAPI_strerror(retval));
        return ERRNO;
    }
    // Initialise thread support (as the program being profiled may be multithreaded).
    retval = PAPI_thread_init(allinea_get_thread_id);
    if (retval != PAPI_VER_CURRENT  &&  retval > 0)
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "Could not enable thread support (error in PAPI_thread_init). PAPI error: %s", PAPI_strerror(retval));
        return ERRNO;
    }
    retval = PAPI_is_initialized();
    if (retval != PAPI_THREAD_LEVEL_INITED+PAPI_LOW_LEVEL_INITED)
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "PAPI not initialised with thread support. PAPI error: %s", PAPI_strerror(retval));
        return ERRNO;
    }

    maxHardwareCounters = PAPI_num_counters();
    if (maxHardwareCounters < 0)
    {
        allinea_set_plugin_error_messagef(plugin_id, maxHardwareCounters, "This installation does not support PAPI");
        return ERRNO;
    }
    else if (maxHardwareCounters == 0)
    {
        allinea_set_plugin_error_messagef(plugin_id, 0, "This machine does not provide hardware counters");
        return ERRNO;
    }

    return 0;
}


//! Add an event to an event set and update the event's index
/*!
 *  This function will add the specified event to the specified event set and update the index of said event. It also
 *  updates a counter so that the index of any subsequently added events can also be updated accurately.
 *
 *  This function is only ever called by allinea_populate_and_start_eventset.
 *
 *  \param[in] plugin_id
 *      The ID of the plugin (used for setting error messages).
 *  \param[in] eventSet
 *      The event set, created by PAPI_create_eventset.
 *  \param[in] event
 *      The PAPI PRESET event.
 *  \param[out] eventIndex
 *      The index of the event in the eventValues array.
 *      If an error occured this will be set to \c PAPI_ error value (NB: all PAPI error codes
 *      are negative).
 *  \param[in, out] counter
 *      The counter; used to calculate eventIndex.
 *  \return retval
 *      The return value of PAPI_add_event, indicating if the event was successfully added or not.
 */
int allinea_add_event(const plugin_id_t plugin_id, const int eventSet, const int event, int *eventIndex, int *counter)
{
    int retval = PAPI_add_event(eventSet, event);
    if (retval == PAPI_OK)
    {
        *eventIndex = *counter;
        *counter    = *counter + 1;
    }
    else if (retval < 0) // PAPI_ error codes should all be negative
    {
        // Don't report a plugin error here - we'll report the error against the specific metric that needs
        // this PAPI counter later.
        *eventIndex = retval;
    }
    else // PAPI_add_event shouldn't return a positive non-zero (PAPI_OK) return value.
    {
        allinea_set_plugin_error_messagef(plugin_id, ERRNO, "Unexpected non-negative return code from PAPI_add_event. Event: %i, Return Value: %i\n", event, retval);
    }
    return retval;
}


//! Check the name of the metric set and add the specified events the PAPI EventSet used by this library
/*!
 *  This function will add events (up to PAPI_MAX_HWCTRS, hardware dependent) to the calling thread's event set according to which metric set has been
 *  selected. It will return an error if all of the events cannot be added or if the metric set name cannot be
 *  identified. If only some events cannot be added no error will be returned so that the user can still view any events
 *  that are added.
 *
 *  \param[in] plugin_id
 *      The ID of the plugin (used for setting error messages).
 *  \param[out] localEventSet
 *      The calling thread's eventSet, which has already been created by PAPI_create_eventset.
 *  \param[in] metricSet
 *      The name of the metric set to be used
 *  \return
 *       0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_populate_and_start_eventset(const plugin_id_t plugin_id, const int localEventSet, const char *metricSet)
{
    int eventCounter     = 0;   // The number of events that have been successfully added

    // Add events according to the name of the metric set
    if (strcasecmp(metricSet, "Overview") == 0)
    { // FLOPS and CPI
        enabledMetricSet = METRIC_SET_OVERVIEW;
        allinea_add_event(plugin_id, localEventSet, PAPI_DP_OPS,  &dpOpsIndex,  &eventCounter); // Double precision floating point operations
        allinea_add_event(plugin_id, localEventSet, PAPI_TOT_INS, &totInsIndex, &eventCounter); // Total instructions
        allinea_add_event(plugin_id, localEventSet, PAPI_TOT_CYC, &totCycIndex, &eventCounter); // Total cycles
        if (maxHardwareCounters >= minHardwareCountersForExtendedOverview)
        {
            allinea_add_event(plugin_id, localEventSet, PAPI_L2_DCM, &l2DcmIndex, &eventCounter); // Level 2 data cache misses
        }
    }
    else if (strcasecmp(metricSet, "CacheMisses") == 0)
    {   // L1, L2 and L3 total cache misses. If a total cache miss metric (TCM) metric is
        // unavailable fallback to collecting the data cache misses instead.
        enabledMetricSet = METRIC_SET_CACHE_MISSES;
        int rtn = -1;
        rtn = allinea_add_event(plugin_id, localEventSet, PAPI_L1_TCM, &l1TcmIndex, &eventCounter); // Level 1 total cache misses
        if (rtn < 0)
            allinea_add_event(plugin_id, localEventSet, PAPI_L1_DCM, &l1DcmIndex, &eventCounter);   // Level 1 data cache misses

        rtn = allinea_add_event(plugin_id, localEventSet, PAPI_L2_TCM, &l2TcmIndex, &eventCounter); // Level 2 total cache misses
        if (rtn < 0)
            allinea_add_event(plugin_id, localEventSet, PAPI_L2_DCM, &l2DcmIndex, &eventCounter);   // Level 2 data cache misses

        rtn = allinea_add_event(plugin_id, localEventSet, PAPI_L3_TCM, &l3TcmIndex, &eventCounter); // Level 3 total cache misses
        if (rtn < 0)
            allinea_add_event(plugin_id, localEventSet, PAPI_L3_DCM, &l3DcmIndex, &eventCounter);   // Level 3 data cache misses
    }
    else if (strcasecmp(metricSet, "BranchPrediction") == 0)
    { // Total and mispredicted branch instructions
        enabledMetricSet = METRIC_SET_BRANCH_INSTR;
        allinea_add_event(plugin_id, localEventSet, PAPI_BR_INS,  &brInsIndex,  &eventCounter); // Total branch instructions
        allinea_add_event(plugin_id, localEventSet, PAPI_TOT_INS, &totInsIndex, &eventCounter); // Total instructions
        allinea_add_event(plugin_id, localEventSet, PAPI_BR_MSP,  &brMspIndex,  &eventCounter); // Mispredicted branch instructions
    }
    else if (strcasecmp(metricSet, "FloatingPoint") == 0)
    { // Total and single and double precision vector instructions
        enabledMetricSet = METRIC_SET_FLOAT_INSTR;
        allinea_add_event(plugin_id, localEventSet, PAPI_TOT_INS, &totInsIndex, &eventCounter); // Total instructions
        allinea_add_event(plugin_id, localEventSet, PAPI_FP_INS,  &fpInsIndex,  &eventCounter); // Scalar floating-point instructions

        const int rtn1 = allinea_add_event(plugin_id, localEventSet, PAPI_VEC_SP,  &vecSpIndex,  &eventCounter); // Single precision vector instructions
        const int rtn2 = allinea_add_event(plugin_id, localEventSet, PAPI_VEC_DP,  &vecDpIndex,  &eventCounter); // Double precision vector instructions

        // If vec_sp and vec_dp aren't available, use vec_ins instead.
        if (rtn1 < 0 || rtn2 < 0)
            allinea_add_event(plugin_id, localEventSet, PAPI_VEC_INS, &vecInsIndex, &eventCounter); // Vector instructions
    }
    else
    {
        allinea_set_plugin_error_messagef(plugin_id, ERRNO, "Unrecognised PAPI metrics set \"%s\"", metricSet);
        return ERRNO;
    }

    // NB: Don't error here if eventCounter==0; the metric-specific error messages
    // will be more useful than a plugin-wide error message.

    if (eventCounter > MAX_NUM_EVENTS)
    {
        allinea_set_plugin_error_messagef(plugin_id, ERRNO,
                                          "Internal error in "__FILE__": %i events added but MAX_NUM_EVENTS is hard-coded to %i. Increase the MAX_NUM_EVENTS constant.\n",
                                          eventCounter, MAX_NUM_EVENTS);
    }

    if (eventCounter > maxHardwareCounters)
    {
        allinea_set_plugin_error_messagef(plugin_id, ERRNO,
                                          "Insufficient hardware counters to track all requested PAPI metrics "
                                          "(%d counters available)",
                                          maxHardwareCounters);
        return ERRNO;
    }

    // Start counting the events
    int retval = PAPI_start(localEventSet);
    if (retval != PAPI_OK)
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "Could not get PAPI_start: %s", PAPI_strerror(retval));
        return retval;
    }
    return 0;
}

//! Initialise PAPI and the event sets
/*!
 *  This function will initialise the PAPI library and thread support for it, read the configuration file for the name
 *  of the metric set to be used, create several event sets and start PAPI.
 *
 *  \param[in] plugin_id
 *      The ID of the plugin (used for setting error messages).
 *  \param[in] unused
 *      Currently unused, will always be NULL.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error
 */
int allinea_plugin_initialize(plugin_id_t plugin_id, void *unused)
{
    if (allinea_initialise_papi(plugin_id) != 0)
    {
        // alliena_set_plugin_error_message() should have been called by allinea_initialise_papi()
        return ERRNO;
    }

    // Create the event sets
    int retval = PAPI_create_eventset(&papiEventSet);
    if (retval != PAPI_OK)
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "Could not create event set: %s", PAPI_strerror(retval));
        return ERRNO;
    }

    // Read the configuration file to get the metric set
    memset(set, 0, sizeof set);
    retval = allinea_read_config_file("set", "com.allinea.metrics.papi.flops", set, SET_NAME_MAX_LEN);
    switch (retval)
    {
    case  0: break; // Success!
    case -1:
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "Error reading PAPI.config: file name is too long");
        return ERRNO;
    }
    case -2:
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "Error reading PAPI.config: file not found.\nHave you exported \
the PAPI.config file as it was said at the end of the PAPI installation script? e.g.'export ALLINEA_PAPI_CONFIG=/installation/path/to/PAPI.config");
        return ERRNO;
    }
    case -3:
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "Error reading PAPI.config: variable \"set\" was not found or improperly declared");
        return ERRNO;
    }
    default:
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "Unhandled return value from allinea_read_config_file() when reading PAPI.config: %i", retval);
        return ERRNO;
    }
    }

    // Initialise the array of values to be used for this event set, add events to the set and start counting
    memset(eventValues, 0, MAX_NUM_EVENTS*sizeof(long long));

    if (allinea_populate_and_start_eventset(plugin_id, papiEventSet, set) != 0)
    {
        // alliena_set_plugin_error_message() should have been called by allinea_populate_and_start_eventset()
        return ERRNO;
    }
    return 0;
}


//! Stop counting, clean up and destroy all event sets
/*!
 *  This function will stop, clean up and destroy each event set that was used, and destroy the mutex lock.
 *
 *  \param[in] plugin_id
 *      The ID of the plugin (used for setting error messages).
 *  \param[in] unused
 *      Currently unused, will always be NULL.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error
 */
int allinea_plugin_cleanup(plugin_id_t plugin_id, void *unused)
{
    // Stop the event set counting
    int retval = PAPI_stop(papiEventSet, eventValues);
    if (retval != PAPI_OK)
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "Error in PAPI_stop: %s", PAPI_strerror(retval));
        return ERRNO;
    }
    // Remove all events from the event set
    retval = PAPI_cleanup_eventset(papiEventSet);
    if (retval != PAPI_OK)
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "Error in PAPI_cleanup_eventset: %s", PAPI_strerror(retval));
        return ERRNO;
    }

    // Destroy the event set
    retval = PAPI_destroy_eventset(&papiEventSet);
    if (retval != PAPI_OK)
    {
        allinea_set_plugin_error_messagef(plugin_id, retval, "Error in PAPI_destroy_eventset: %s", PAPI_strerror(retval));
        return ERRNO;
    }

    // Reset the event set
    papiEventSet = PAPI_NULL;

    return 0;
}


//! Get the latest values from the event counters
/*!
 *  This function will check if time has passed since the last time it was called, if so the PAPI metric values
 *  will be read and the counters reset.
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time. This is passed in from the profiler to avoid unnecessary calls to allinea_get_current_time().
 *  \param[in] metricSet
 *      The name of the metric set.
 *  \return
 *       0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int get_values(metric_id_t metric_id, struct timespec current_sample_time, const char *metricSet)
{
    static unsigned long int lastSampleTime = 0;

    // Check if time has passed since the last time this function was called
    const unsigned long int now = current_sample_time.tv_nsec + (current_sample_time.tv_sec)*ONE_SECOND_NS;
    if (now != lastSampleTime)
    {
        // Read the values in the event counters and reset the counters. In the function PAPI_accum,
        // the counters are reset after all of the values have been read, so the counters do not count
        // while other counters are being read.
        memset(eventValues, 0, MAX_NUM_EVENTS*sizeof(long long));
        int retval = PAPI_accum(papiEventSet, eventValues);
        if (retval != PAPI_OK)
        {
            allinea_set_metric_error_messagef(metric_id, retval, "Error in PAPI_accum: %s", PAPI_strerror(retval));
            return ERRNO;
        }

        lastSampleTime = now;
    }
    return 0;
}


//! Set the error message when an event is not found
/*!
 *  This function will set the error message to "Event not available to count: [PAPI event name]" when the event is not
 *  available, or "This metric is unavailable because a different metric set has been selected" if the metric set it
 *  belongs to is not the set being used.
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] event
 *      The name of the event.
 *  \param[in] expectedMetricSet
 *      The METRIC_SET_* constant indicating the metric set this value will be used for.
 *      Used to report the correct error if this metric is unavailable due to being
 *      for the wrong metric set.
 *  \param[in] errorCode
 *      The error code to handle. Either one of the PAPI error handling codes or \c UNSET_INDEX
 *  \return ERRNO
 *      An error.
 */
int handle_error(metric_id_t metric_id, const char *event, const int expectedMetricSet, int errorCode)
{
    int i;

    // if that set is the one currently in use
    if (expectedMetricSet == enabledMetricSet)
    {
        // the event is unavailable
        if (errorCode==UNSET_INDEX)
            allinea_set_metric_error_messagef(metric_id, ERRNO,
                                        "PAPI event %s is not supported on your system.\n"
                                        "Check the supported PAPI events on your system with 'papi_avail' tool.",
                                        event);
        else
            allinea_set_metric_error_messagef(metric_id, ERRNO,
                                        "PAPI event %s is not supported on your system: %s.\n"
                                        "Check the supported PAPI events on your system with 'papi_avail' tool.",
                                        event, PAPI_strerror(errorCode));
        return ERRNO;
    }
    else
    {
        // if none of the sets that the metric belongs to is the set currently in use, print a different message
        allinea_set_metric_error_messagef(metric_id, ERRNO,
                                        "Disabled by PAPI.config\n"
                                        "This metric is not in the currently enabled metric set (\"%s\"). "
                                        "Edit PAPI.config to enable a different set of metrics.",
                                        set);
    }
    return ERRNO;
}


//! Convienience function for providing a raw PAPI counter from a metric plugin getter function.
/*!
 *  \param[in] papiName,
 *      The name of the PAPI counter to be obtained. Used in error messages.
 *  \param[in] eventValuesIndex
 *      Index in the eventValues array at which the PAPI counter's value can be found.
 *      A value < 0 indicates the metric was unavailable; more specifically a value of
 *      \c UNSET_INDEX indicates this PAPI counter is intentionally not being fetched,
 *      otherwise \c eventValuesIndex should be the PAPI error code indicating why the
 *      hardware counter was unavailable.
 *  \param[in] expectedMetricSet
 *      The METRIC_SET_* constant indicating the metric set this value will be used for.
 *      Used to report the correct error if this metric is unavailable due to being
 *      for the wrong metric set.
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int get_papi_value(const char *papiName,
                   const int  eventValuesIndex,
                   const int  expectedMetricSet,
                   metric_id_t metric_id,
                   struct timespec *current_sample_time,
                   double *out_value
                  )
{
    if (eventValuesIndex < 0 || expectedMetricSet!=enabledMetricSet)
        return handle_error(metric_id, papiName, expectedMetricSet, eventValuesIndex);

    get_values(metric_id, *current_sample_time, set);
    *out_value = (double)eventValues[eventValuesIndex];
    return 0;
}


//! Double precision floating-point operations per second (Overview metric set)
/*!
 *  This function counts double precision floating-point operations per second.
 *  It checks that the following PAPI events are in the event set:
 *      PAPI_DP_OPS (double precision floating-point operations)
 *  It then calls get_values() to get the current event counter values and sets out_value to the value of the
 *  PAPI_DP_OPS counter.
 *  In the XML file, for this metric divideBySampleTime is true so MAP will convert this to a per-second measurement.
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_flops(metric_id_t metric_id, struct timespec *current_sample_time, uint64_t *out_value)
{
    // TODO: Document inaccuracies in the counting of this metric
    // TODO: Make per node rather than per process
    if (dpOpsIndex < 0 || METRIC_SET_OVERVIEW!=enabledMetricSet)
        return handle_error(metric_id, "PAPI_DP_OPS", METRIC_SET_OVERVIEW, dpOpsIndex);

    get_values(metric_id, *current_sample_time, set);

    *out_value = eventValues[dpOpsIndex];

    return 0;
}

//! Cycles per instruction (Overview metric set)
/*!
 *  This function counts cycles per isntruction.
 *  It checks that the following PAPI events are in the event set:
 *      PAPI_TOT_INS (total isntructions)
 *      PAPI_TOT_CYC (total cycles)
 *  It then calls get_values() to get the current event counter values, checks that PAPI_TOT_INS is non-zero and sets
 *  out_value to the value of the PAPI_TOT_CYC counter divided by the value of the PAPI_TOT_INS counter.
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_cycles_per_instruction(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    if (totInsIndex < 0 || METRIC_SET_OVERVIEW!=enabledMetricSet)
        return handle_error(metric_id, "PAPI_TOT_INS", METRIC_SET_OVERVIEW, totInsIndex);

    if (totCycIndex < 0)
        return handle_error(metric_id, "PAPI_TOT_CYC", METRIC_SET_OVERVIEW, totCycIndex);

    get_values(metric_id, *current_sample_time, set);

    if (eventValues[totInsIndex] == 0)
        *out_value = 0.0;
    else
        *out_value = (double)eventValues[totCycIndex] / eventValues[totInsIndex];

    return 0;
}


//! Number of l2 data cache misses for the Overview preset
/*!
 *  This function counts L2 data cache misses.
 *  Function naming convention:
 *      _o postfix stands for overview (Overview preset)
 *  This function counts L2 data cache misses using the PAPI_L2_DCM preset.
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_l2_data_cache_misses_o(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    if (maxHardwareCounters < minHardwareCountersForExtendedOverview)
    {
        allinea_set_metric_error_messagef(metric_id, ERRNO,
                                          "Not enough hardware counters on your system to collect events required by this metric using this preset.\n"
                                          "Hardware counters required=%d, found=%d.\n",
                                          minHardwareCountersForExtendedOverview,
                                          maxHardwareCounters);
        return ERRNO;
    }
    else
        return get_papi_value("PAPI_L2_DCM", l2DcmIndex,
                              METRIC_SET_OVERVIEW,
                              metric_id, current_sample_time, out_value);
}

//! Number of l1 total cache misses
/*!
 *  This function counts L1 cache misses using the PAPI_L1_TCM preset
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_l1_total_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    return get_papi_value("PAPI_L1_TCM", l1TcmIndex,
                          METRIC_SET_CACHE_MISSES,
                          metric_id, current_sample_time, out_value);
}

//! Number of l1 data cache misses
/*!
 *  This function counts L1 data cache misses using the PAPI_L1_DCM preset
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_l1_data_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    if (l1DcmIndex == UNSET_INDEX && l1TcmIndex >= 0)
    {
        allinea_set_metric_error_messagef(metric_id, ERRNO,
                "L1 total cache misses collected instead.\n"
                "Unavailable as total cache misses are being collected in preference to data cache misses.");
        return ERRNO;
    }
    else
        return get_papi_value("PAPI_L1_DCM", l1DcmIndex,
                              METRIC_SET_CACHE_MISSES,
                              metric_id, current_sample_time, out_value);
}

//! Number of l2 total cache misses
/*!
 *  This function counts L2 cache misses using the PAPI_L2_TCM preset
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_l2_total_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    return get_papi_value("PAPI_L2_TCM", l2TcmIndex,
                          METRIC_SET_CACHE_MISSES,
                          metric_id, current_sample_time, out_value);

}

//! Number of l2 data cache misses
/*!
 *  This function counts L2 data cache misses using the PAPI_L2_DCM preset
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_l2_data_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    if (l2DcmIndex == UNSET_INDEX && l2TcmIndex >= 0)
    {
        allinea_set_metric_error_messagef(metric_id, ERRNO,
                "L2 total cache misses collected instead.\n"
                "Unavailable as total cache misses are being collected in preference to data cache misses.");
        return ERRNO;
    }
    else
        return get_papi_value("PAPI_L2_DCM", l2DcmIndex,
                              METRIC_SET_CACHE_MISSES,
                              metric_id, current_sample_time, out_value);
}


//! Number of l3 total cache misses
/*!
 *  This function counts L3 cache misses using the PAPI_L3_TCM preset
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_l3_total_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    return get_papi_value("PAPI_L3_TCM", l3TcmIndex,
                          METRIC_SET_CACHE_MISSES,
                          metric_id, current_sample_time, out_value);

}

//! Number of l3 data cache misses
/*!
 *  This function counts L3 data cache misses using the PAPI_L3_DCM preset
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_l3_data_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    if (l3DcmIndex == UNSET_INDEX && l3TcmIndex >= 0)
    {
        allinea_set_metric_error_messagef(metric_id, ERRNO,
                "L3 total cache misses collected instead.\n"
                "Unavailable as total cache misses are being collected in preference to data cache misses.");
        return ERRNO;
    }
    else
        return get_papi_value("PAPI_L3_DCM", l3DcmIndex,
                              METRIC_SET_CACHE_MISSES,
                              metric_id, current_sample_time, out_value);
}




//! Returns the number of branch instructions since the last sample
/*!
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_branch_instructions(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    return get_papi_value("PAPI_BR_INS", brInsIndex,
                          METRIC_SET_BRANCH_INSTR,
                          metric_id, current_sample_time, out_value);
}

//! Returns the number of branch misprediction instructions since the last sample
/*!
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_mispredicted_branch_instructions(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    return get_papi_value("PAPI_BR_MSP", brMspIndex,
                          METRIC_SET_BRANCH_INSTR,
                          metric_id, current_sample_time, out_value);
}

//! Returns the number of completed instructions since the last sample (for the 'branch instructions' metric set)
/*!
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_total_instructions_b(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    return get_papi_value("PAPI_TOT_INS", totInsIndex,
                          METRIC_SET_BRANCH_INSTR,
                          metric_id, current_sample_time, out_value);
}

//! Returns the number of scalar floating point instructions completed instructions since the last sample
/*!
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_fp_scalar_instructions(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    return get_papi_value("PAPI_FP_INS", fpInsIndex,
                          METRIC_SET_FLOAT_INSTR,
                          metric_id, current_sample_time, out_value);
}

//! Returns the number of floating-point vectorised instructions since the last sample
/*!
 *  This will be the sum of the PAPI_VEC_SP and PAPI_VEC_DP counter values.
 *
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_fp_vector_instructions(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    if (vecSpIndex < 0 || METRIC_SET_FLOAT_INSTR!=enabledMetricSet)
        return handle_error(metric_id, "PAPI_VEC_SP", METRIC_SET_FLOAT_INSTR, vecSpIndex);

    if (vecDpIndex < 0)
        return handle_error(metric_id, "PAPI_VEC_DP", METRIC_SET_FLOAT_INSTR, vecDpIndex);

    get_values(metric_id, *current_sample_time, set);

    *out_value = eventValues[vecSpIndex] + eventValues[vecDpIndex];

    return 0;
}

//! Returns the number of vector instructions (whether floating-point or integer) since the last sample
/*!
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_vector_instructions(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    if (vecInsIndex == UNSET_INDEX && vecSpIndex >= 0 && vecDpIndex)
    {
        allinea_set_metric_error_messagef(metric_id, ERRNO,
                "Floating-point vector instructions collected instead.\n"
                "Unavailable as single precision + double precision vector instructions are being collected in preference to all vector instructions (which may include integer operations).");
        return ERRNO;
    }
    else
        return get_papi_value("PAPI_VEC_INS", vecInsIndex,
                             METRIC_SET_FLOAT_INSTR,
                             metric_id, current_sample_time, out_value);
}

//! Returns the number of completed instructions since the last sample (for the 'floating-point' metric set)
/*!
 *  \param[in] metric_id
 *      The ID of the metric (used for setting error messages).
 *  \param[in] current_sample_time
 *      The current time of this sample.
 *  \param[out] out_value
 *      The value of the metric.
 *  \return
 *      0 if there are no errors
 *      ERRNO if there is an error (and the error message is set)
 */
int allinea_total_instructions_f(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value)
{
    return get_papi_value("PAPI_TOT_INS", totInsIndex,
                          METRIC_SET_FLOAT_INSTR,
                          metric_id, current_sample_time, out_value);
}
