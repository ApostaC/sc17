#ifndef LIBPAPI_H
#define LIBPAPI_H

#ifndef ALLINEA_METRIC_PLUGIN_API_H
#include "allinea_metric_plugin_api.h"
#endif

int allinea_initialise_papi(plugin_id_t plugin_id);
int allinea_add_event(const plugin_id_t plugin_id, const int eventSet, const int event, int *eventIndex, int *counter);
int allinea_populate_and_start_eventset(const plugin_id_t plugin_id, const int localEventSet, const char *metricSet);

int allinea_plugin_initialize(plugin_id_t plugin_id, void *unused);
int allinea_plugin_cleanup(plugin_id_t plugin_id, void *unused);

int get_values(metric_id_t metric_id, struct timespec current_sample_time, const char *metricSet);


int allinea_flops(metric_id_t metric_id, struct timespec *current_sample_time, uint64_t *out_value);
int allinea_cycles_per_instruction(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);
int allinea_l2_data_cache_misses_o(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);

int allinea_l1_total_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);
int allinea_l1_data_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);

int allinea_l2_total_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);
int allinea_l2_data_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);

int allinea_l3_total_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);
int allinea_l3_data_cache_misses(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);

int allinea_branch_instructions(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);
int allinea_mispredicted_branch_instructions(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);

int allinea_vector_instructions(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);
int allinea_sp_vector_instructions(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);
int allinea_dp_vector_instructions(metric_id_t metric_id, struct timespec *current_sample_time, double *out_value);

#endif // LIBPAPI_H
