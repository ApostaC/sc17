/*! \file
 *  \brief Types and typedefs used by the Allinea metric plugin API
 */

#ifndef ALLINEA_METRIC_PLUGIN_TYPES_H
#define ALLINEA_METRIC_PLUGIN_TYPES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//! Opaque handle to a metric plugin.
typedef uintptr_t plugin_id_t;
//! Opaque handle to a metric.
typedef uintptr_t metric_id_t;


#ifdef __cplusplus
}
#endif

#endif // ALLINEA_METRIC_PLUGIN_TYPES_H
