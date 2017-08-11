#ifndef MAPSAMPLER_API_PRIVATE_H
#define MAPSAMPLER_API_PRIVATE_H

#include <stdint.h>
#include <stdlib.h>

/* This file defines the private API used by Allinea MAP. */
/* This API is subject to change without notice - do not use it in your own code. */

#if defined MAP_SAMPLER_LIBRARY || defined MAP_PROFILER_LIBRARY
  #include "sampler_global.h"
#else
  #define MAP_SAMPLER_API
#endif

#define MAP_STOP_AT_EXIT    1
#define MAP_NO_STOP_AT_EXIT 0

#define MAP_LAST_COMPATIBLE_SAMPLER_VERSION 700
#define MAP_SAMPLER_VERSION_CURRENT         700
#define MAP_WRAPPER_VERSION_CURRENT         600

#define MAP_TEST_MODE_ENABLED  1
#define MAP_TEST_MODE_DISABLED 0

typedef enum
{
    ALLINEA_INIT_SUCCESS = 0,
    ALLINEA_INIT_ERROR_ALREADY_INITIALISED,
    ALLINEA_INIT_ERROR_ALREADY_STOPPED,
    ALLINEA_INIT_BAD_BASENAME,
    ALLINEA_INIT_SIGPROF_USED,
    ALLINEA_INIT_PROC_CPUINFO_FAILED,
    ALLINEA_INIT_NOT_IN_PRELOAD_LIBRARY,
    ALLINEA_INIT_SIGPROF_HANDLER_SET_TWICE,
    ALLINEA_INIT_MAINTHREAD_SET_TWICE,
    ALLINEA_INIT_BAD_SLEEPING_THRESHOLD,
    ALLINEA_INIT_BAD_METRIC,
    ALLINEA_INIT_BAD_LIBRARY_LOAD,
    ALLINEA_INIT_UNSUPPORTED_MPI_THREAD_MODE
} allinea_init_err_t;

typedef enum
{
    ALLINEA_MPI_THREAD_SUPPORT_UNSPECIFIED,
    ALLINEA_MPI_THREAD_SUPPORT_SINGLE,
    ALLINEA_MPI_THREAD_SUPPORT_FUNNELED,
    ALLINEA_MPI_THREAD_SUPPORT_SERIALIZED,
    ALLINEA_MPI_THREAD_SUPPORT_MULTIPLE
} allinea_mpi_thread_support_t;

typedef enum
{
    ALLINEA_DESTROY_NOW,
    ALLINEA_WAIT_FOR_FILE_TRANSFER
} allinea_destroy_sampler_mode_t;

#ifdef __cplusplus
extern "C"
{
#endif
    MAP_SAMPLER_API int allinea_init_sampler(int numSamples, int initialIntervalMs, const char *filename, int rank);
    MAP_SAMPLER_API int allinea_init_sampler_now(int numSamples, int initialIntervalMs, const char* filename, int stopAtExit,
                                                 const unsigned int startOffset, const unsigned int stopOffset);
#ifdef UNITTEST
    MAP_SAMPLER_API void allinea_destroy_sampler(allinea_destroy_sampler_mode_t mode);
#endif
    MAP_SAMPLER_API void allinea_pre_mpi_init();
    MAP_SAMPLER_API void allinea_mid_mpi_init();
    MAP_SAMPLER_API void allinea_post_mpi_init();
    MAP_SAMPLER_API void allinea_set_is_rank_0(int b);
    MAP_SAMPLER_API void allinea_set_mpi_thread_support(allinea_mpi_thread_support_t support);
    MAP_SAMPLER_API void allinea_suspend_traces_for_mpi(const char *functionName);
    MAP_SAMPLER_API void allinea_resume_traces_for_mpi();
    MAP_SAMPLER_API void allinea_suspend_traces_for_openmp(); 
    MAP_SAMPLER_API void allinea_resume_traces_for_openmp();
    MAP_SAMPLER_API void allinea_add_mpi_call(const char* funcName,
                                              unsigned long long bytesSent,
                                              unsigned long long bytesRecv,
                                              unsigned int mpiType);
    MAP_SAMPLER_API void allinea_in_mpi_call(int inMpi);
    MAP_SAMPLER_API void allinea_write_samples();
    MAP_SAMPLER_API void allinea_write_debug_log(int enabled);
    MAP_SAMPLER_API void allinea_set_GPUProfiler_configuration(int enablePcsampling);
    MAP_SAMPLER_API void allinea_set_sampler_test_mode(int testmode);
    MAP_SAMPLER_API void allinea_ui_stop_sampling();
    MAP_SAMPLER_API int  allinea_sampler_version();
    MAP_SAMPLER_API size_t allinea_get_bytes_read_by_map();
    MAP_SAMPLER_API size_t allinea_get_bytes_written_by_map();
    MAP_SAMPLER_API size_t allinea_get_num_read_calls_by_map();
    MAP_SAMPLER_API size_t allinea_get_num_write_calls_by_map();
    MAP_SAMPLER_API int  allinea_read_proc_file_fields(const char* procFile, const char* fields[], uint64_t values[]);
    MAP_SAMPLER_API int  allinea_read_proc_file_fields2(const char* procFile, const char* fields[], int *words[], uint64_t values[]);
    MAP_SAMPLER_API void allinea_start_sampler_io_accounting();
    MAP_SAMPLER_API void allinea_stop_sampler_io_accounting();
    MAP_SAMPLER_API int  allinea_sampler_has_stopped();
    MAP_SAMPLER_API size_t allinea_get_metric_configuration_filename(const char * metric_id, char * filename, size_t len);
#ifdef __cplusplus
}
#endif

#define MPI_TYPE_OTHER      0
#define MPI_TYPE_P2P        1
#define MPI_TYPE_COLLECTIVE 2

#endif // MAPSAMPLER_API_PRIVATE_H
