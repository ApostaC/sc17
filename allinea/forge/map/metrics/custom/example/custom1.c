//! \file
/*! This example metric plugin provides a custom metric showing the number of
 *  interrupts handled by the system.
 *
 *  The information is obtained from /proc/interrupts.
 *  
 *  This file is paired with an XML file (custom1.xml) which informs the Allinea 
 *  tools as to how this custom metric is loaded and displayed.
 */

/* The following functions are assumed to be async-signal-safe, although not
 * required by POSIX:
 * 
 * strchr strstr strtoull
 */

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "allinea_metric_plugin_api.h"

#define PROC_STAT "/proc/stat"

//! Error code if /proc/interrupts does not exist.
#define ERROR_NO_PROC_STAT                        1000

#define BUFSIZE     256
#define OVERLAP    64

#ifndef min
#define min(x, y) ( ((x) < (y)) ? (x) : (y) )
#endif

//! previous value.
static uint64_t previous = 0;
//! Do we have a previous value?
static int have_previous = 0;

//! This function is called when the metric plugin is loaded.
/*!
 *  We do not have to restrict ourselves to async-signal-safe functions because
 *  the initialization function will be called without any locks held.
 * 
 *  \param plugin_id an opaque handle for the plugin.
 *  \param unused unused
 *  \return 0 on success; -1 on failure and set errno
 */
int allinea_plugin_initialize(plugin_id_t plugin_id, void *unused)
{
    // Check that /proc/interrupts exists.
    if (access(PROC_STAT, F_OK) != 0) {
        if (errno == ENOENT)
            allinea_set_plugin_error_messagef(plugin_id, ERROR_NO_PROC_STAT,
                "Not supported (no /proc/interrupts)");
        else
            allinea_set_plugin_error_messagef(plugin_id, errno,
                "Error accessing %s: %s", PROC_STAT, strerror(errno));
        return -1;
    }
}

//! This function is called when the metric plugin is unloaded.
/*!
 *  We do not have to restrict ourselves to async-signal-safe functions because
 *  the initialization function will be called without any locks held.
 * 
 *  \param plugin_id an opaque handle for the plugin.
 *  \param unused unused
 *  \return 0 on success; -1 on failure and set errno
 */
int allinea_plugin_cleanup(plugin_id_t plugin_id, void *unused)
{
}

//! This callback is called once every sample.
/*!
 *  The current value of the metric (the number of interrupts taken since the
 *  start of the run) is copied to out_value. This value is modified by the
 *  Allinea tools depending on the value of the divideBySampleTime XML switch
 *  in \c custom1.xml. If the switch is set to true then out_value is divided
 *  by the sample interval, else it is left untouched.
 * 
 *  This function is called from a signal handler so it must be async-signal-safe.
 * 
 *  \param metric_id an opaque handle for the metric.
 *  \param in_out_sample_time [in, out] the time at which this sample is being taken
 *         We set this to the current time just before opening /proc/stat to get
 *         the most accurate sample time.
 *  \param out_value [out] the value of the metric
 *
 *  \return 0 on success; -1 on failure and set errno
 */
int sample_interrupts(metric_id_t metric_id, struct timespec *in_out_sample_time, uint64_t *out_value)
{
    // Main buffer. Add an extra byte for the '\0' we add below.
    char buf[BUFSIZE + 1];

    *in_out_sample_time = allinea_get_current_time();

    // We must use the allinea_safe variants of open / read / write / close so
    // that we are not included in the Allinea sampler's I/O accounting.
    const int fd = allinea_safe_open(PROC_STAT, O_RDONLY);
    if (fd == -1) {
        allinea_set_metric_error_messagef(metric_id, errno, 
            "Error opening %s: %d", PROC_STAT, strerror(errno));
        return -1;
    }
    for (;;) {
        const ssize_t bytes_read = allinea_safe_read_line(fd, buf, BUFSIZE);
        if (bytes_read == -1) {
            // read failed
            allinea_set_metric_error_messagef(metric_id, errno,
                "Error opening %s: %d", PROC_STAT, strerror(errno));
            break;
        }
        if (bytes_read == 0) {
            // end of file
            break;
        }

        if (strncmp(buf, "intr ", 5)==0) { // Check if this is the interrupts line.
            // The format of the line is:
            // intr <total> <intr 1 count> <intr 2 count> ...
            // Check we have the total by looking for the space after it.
            const char *total = buf + /* strlen("intr ") */ 5;
            char *space = strchr(total, ' ');
            if (space) {
                uint64_t current;
                // NUL-terminate the total.
                *space = '\0';
                // total now points to the NUL-terminated total. Convert it to
                // an integer.
                current = strtoull(total, NULL, 10);
                if (have_previous)
                    *out_value = current - previous;
                previous = current;
                have_previous = 1;
                break;
            }
        }
    }
    allinea_safe_close(fd);
}
