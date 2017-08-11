/*! \file
 *  \brief Header containing declarations for functions to be implemented by any Allinea metric plugin library.
 *
 */

#ifndef ALLINEA_METRIC_PLUGIN_TEMPLATE_H
#define ALLINEA_METRIC_PLUGIN_TEMPLATE_H

#include "allinea_metric_plugin_types.h"

#ifdef __cplusplus
extern "C" {
#endif

//! Initialises a metric plugin.
/*! This function must be implemented by each metric plugin library. It will be
 *  called when that plugin library is loaded. Use this function to
 *  setup data structures and do one-off resource checks. Unlike most functions
 *  used in a metric plugin library this is \e not called from a signal handler.
 *  It is therefore safe to make general function calls and even allocate /
 *  deallocate memory using the normal libc malloc/free new/delete functions.
 *
 *  If it can be determined that this metric plugin cannot function (e.g. the
 *  required information is not available on this machine) then it should
 *  call allinea_set_plugin_error_message() or allinea_set_plugin_error_messagef()
 *  to explain the situation then return -1.
 *
 *  \param plugin_id Opaque handle for the metric plugin. Use this when making calls
 *          to allinea_set_plugin_error_message() or allinea_set_plugin_error_messagef()
 *  \param data Currently unused, will always be \c NULL
 *  \return 0 on success; -1 on error. A description of the error should be supplied
 *          using allinea_set_plugin_error_message() or allinea_set_plugin_error_messagef()
 *          before returning.
 *  \ingroup template
 */
int allinea_plugin_initialize(plugin_id_t plugin_id, void* data);

//! Cleans up a metric plugin.
/*! This function must be implemented by each metric plugin library. It will be
 *  called when that plugin library is unloaded. Use this function to
 *  release any held resources (open files etc). Unlike most functions
 *  used in a metric plugin library this is \e not called from a signal handler.
 *  It is therefore safe to make general function calls and even allocate /
 *  deallocate memory using the normal libc malloc/free new/delete functions.
 *
 *  Note that this will be called after metric data has been extracted and
 *  transferred to the frontend. Plugin error messages set by
 *  allinea_set_plugin_error_message() or allinea_set_plugin_error_messagef()
 *  may therefore not be seen by the end user.
 *
 *  \param plugin_id Opaque handle for the metric plugin. Use this when making calls
 *          to allinea_set_plugin_error_message() or allinea_set_plugin_error_messagef()
 *  \param data Currently unused, will always be \c NULL
 *  \return 0 on success; -1 on error. A description of the error should be supplied
 *          using allinea_set_plugin_error_message() or allinea_set_plugin_error_messagef()
 *          before returning.
 *  \ingroup template
 */
int allinea_plugin_cleanup(plugin_id_t plugin_id, void* data);

//! Example of a integer metric getter function
/*! An example of a getter function that returns an integer metric value. Real getter
 *  functions must be registered with the profiler using a \ref xml "Metric definition file".
 *  For example, this function (if it existed) would be registered by having a \c \<metric\>
 *  element along the lines of :
 * \code
 *    <metric id="com.allinea.metrics.myplugin.mymetric">
 *        <units>%</units>
 *        <dataType>uint64_t</dataType>
 *        <domain>time</domain>
 *        <source ref="com.allinea.metrics.myplugin_src" functionName="mymetric_getValue"/>
 *        <display>
 *            <description>Human readable description</description>
 *            <displayName>Human readable display name</displayName>
 *            <type>instructions</type>
 *            <colour>green</colour>
 *        </display>
 *    </metric>
 * \endcode
 * The most relevant line being the one containing \c functionName="mymetric_getValue".
 * See \ref xml for more details on the format this XML file.
 * \param[in] id An id used by the profiler to identify this metric. This can be
 *              used in calls to \ref api functions i.e. allinea_set_metric_error_message().
 * \param[in] currentSampleTime The current time. This is passed in from the profiler to avoid
 *              unnecessary calls to allinea_get_current_time()
 * \param[out] outValue The return value to be provided to the profiler
 * \return 0 if a metric was written to \a outValue successfully, a non-zero value if there
 *              was an error. In the case of an error this function should call
 *              allinea_set_metric_error_message() before returning.
 * \warning This function may have been called from inside a signal handler. Implementations
 *          must not make calls that are not async-signal safe. Do not use any function that
 *          implicitly or explicitly allocates/frees memory or uses non-reentrant
 *          functions, with the exception of the memory allocators provided by the \ref api (i.e.
 *          allinea_safe_malloc() / allinea_safe_free()). Failure to observe async-signal
 *          safety can result in deadlocks, segfaults or undefined/unpredictable behaviour.
 * \note Do not implement this function! Instead implement functions with the same signature
 *              but with a more appropriate function name.
 * \ingroup template */
int mymetric_getIntValue(metric_id_t id, struct timespec *currentSampleTime, uint64_t *outValue);

//! Example of a floating-point metric getter function
/*! An example of a getter function that returns a floating point metric value. Real getter
 *  functions must be registered with the profiler using a \ref xml "Metric definition file".
 *  For example, this function (if it existed) would be registered by having a \c \<metric\>
 *  element along the lines of :
 * \code
 *    <metric id="com.allinea.metrics.myplugin.mymetric">
 *        <units>%</units>
 *        <dataType>double</dataType>
 *        <domain>time</domain>
 *        <source ref="com.allinea.metrics.myplugin_src" functionName="mymetric_getValue"/>
 *        <display>
 *            <description>Human readable description</description>
 *            <displayName>Human readable display name</displayName>
 *            <type>instructions</type>
 *            <colour>green</colour>
 *        </display>
 *    </metric>
 * \endcode
 * The most relevant line being the one containing \c functionName="mymetric_getValue".
 * See \ref xml for more details on the format this XML file.
 * \param[in] id An id used by the profiler to identify this metric. This can be
 *              used in calls to \ref api functions i.e. allinea_set_metric_error_message().
 * \param[in] currentSampleTime The current time. This is passed in from the profiler to avoid
 *              unnecessary calls to allinea_get_current_time()
 * \param[out] outValue The return value to be provided to the profiler
 * \return 0 if a metric was written to \a outValue successfully, a non-zero value if there
 *              was an error. In the case of an error this function should call
 *              allinea_set_metric_error_message() before returning.
 * \warning This function may have been called from inside a signal handler. Implementations
 *          must not make calls that are not async-signal safe. Do not use any function that
 *          implicitly or explicitly allocates/frees memory or uses non-reentrant
 *          functions, with the exception of the memory allocators provided by the \ref api (i.e.
 *          allinea_safe_malloc() / allinea_safe_free()). Failure to observe async-signal
 *          safety can result in deadlocks, segfaults or undefined/unpredictable behaviour.
 * \note Do not implement this function! Instead implement functions with the same signature
 *              but with a more appropriate function name.
 * \ingroup template */
int mymetric_getDoubleValue(metric_id_t id, struct timespec *currentSampleTime, double *outValue);


#ifdef __cplusplus
}
#endif

#endif // ALLINEA_METRIC_PLUGIN_TEMPLATE_H
