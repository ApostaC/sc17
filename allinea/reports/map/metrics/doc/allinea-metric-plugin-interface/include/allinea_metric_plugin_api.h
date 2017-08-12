/*! \file
 *  \brief Header for the Allinea sampler metric plugin API, includes all other API header files.
 */

#ifndef ALLINEA_METRIC_PLUGIN_API_H
#define ALLINEA_METRIC_PLUGIN_API_H

#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "allinea_metric_plugin_types.h"
#include "allinea_metric_plugin_errors.h"
#include "allinea_safe_malloc.h"
#include "allinea_safe_syscalls.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \name System Info Functions
 * Functions that provide information about the system or the enclosing profiler.
 * @{ */

//! Returns the number of logical cores on this system
/*! This count will include 'effective' cores reported by hyperthreading.
 *  \return The number of CPU cores known to the kernel (including those added by hyperthreading).
 *          -1 if this information is not available.
 *  \sa allinea_get_physical_core_count
 *  \ingroup api */
int allinea_get_logical_core_count();

//! Returns the number of physical cores on this system
/*! This count will \e not include the 'effective' cores reported when using
 *  hyperthreading.
 *  \return The number of CPU cores known to the kernel (excluding those added by hyperthreading).
 *          -1 if this information is not available
 *  \sa allinea_get_logical_core_count
 *  \ingroup api */
int allinea_get_physical_core_count();

/// It returns the "customData" attribute of the "source" element from the metric definition defined in
/// the xml file.
/// \param metricId metric id
/// \return  the custom data for the given metric id
const char* allinea_get_custom_data(metric_id_t metricId);

//!@} // Doxygen grouping comment

#ifdef __cplusplus
}
#endif

#endif // ALLINEA_METRIC_PLUGIN_API_H
