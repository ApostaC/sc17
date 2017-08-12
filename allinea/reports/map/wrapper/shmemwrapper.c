#define _GNU_SOURCE // required for RTLD_NEXT

#include "mapsampler_api.h"
#include "mapsampler_api_private.h"

// external SHMEM functions, explicitly declared so this will always compile
#ifdef STATIC
extern void pshmem_init(void);
extern void pstart_pes(int npes);
extern int p_my_pe(void);
extern void pshmem_barrier_all(void);
extern void pshmem_finalize(void);
#else
#include <stdio.h>
#include <dlfcn.h>
static void (*pshmem_init)(void);
static void (*pstart_pes)(int npes);
static int (*p_my_pe)(void);
static void (*pshmem_barrier_all)(void);
static void (*pshmem_finalize)(void);
#endif

extern int allinea_mapNoBarrierCount;
extern int allinea_mapHasEnteredInit;

static int allinea_shmemShutdown = 0;
int allinea_mapHasEnteredStartPes = 0;

int allinea_wrapperEnter();
int allinea_wrapperExit();

void allinea_mapSamplerEnter(
    const char *functionName,
    unsigned long long bytesSent,
    unsigned long long bytesRecv,
    unsigned int mpiType);
void allinea_mapSamplerExit(int returnVal);

typedef enum
{
    ShmemInit,
    StartPes
} shmem_init_function_t;

/* Shared wrapper function for start_pes() / shmem_init().
 * useStartPes determines which is called, and i is the parameter
 * to start_pes(). It is unused if called by shmem_init().
 */
void allinea_shmem_init(shmem_init_function_t useStartPes, int i)
{
#ifndef STATIC
    const char *missing_symbol = NULL;
#endif
    int initMap = 0;
    
    if (!allinea_mapHasEnteredInit)
    {
        initMap = 1;
        allinea_mapHasEnteredInit = 1;
        allinea_mapNoBarrierCount = 1;
        allinea_mapHasEnteredStartPes = 1;
        allinea_pre_mpi_init();

#ifndef STATIC
        if (useStartPes) {
            pstart_pes = dlsym(RTLD_NEXT, "pstart_pes");
        } else {
            pshmem_init = dlsym(RTLD_NEXT, "pshmem_init");
        }
        
        /* ALL-2041: This is to ensure that there is always a
         * valid pstart_pes and pshmem_init, even when they
         * are not directly called, which is necessary as on
         * (at least) OpenMPI 1.8.7 pstart_pes() is implemented
         * in terms of shmem_init(), while pshmem_init is not
         * defined. Without this the wrapper would call itself
         * recursively instead of the original function.
         */
        if (!pshmem_init) {
            pshmem_init = dlsym(RTLD_NEXT, "shmem_init");
        }
        
        p_my_pe = dlsym(RTLD_NEXT, "p_my_pe");
        
        pshmem_barrier_all = dlsym(RTLD_NEXT, "pshmem_barrier_all");
        
        pshmem_finalize = dlsym(RTLD_NEXT, "pshmem_finalize");

        if (useStartPes && !pstart_pes)
            missing_symbol = "pstart_pes";
        else if (!useStartPes && !pshmem_init)
            missing_symbol = "(p)shmem_init";
        else if(!p_my_pe)
            missing_symbol = "p_my_pe";
        else if(!pshmem_barrier_all)
            missing_symbol = "pshmem_barrier_all";
        else if(!pshmem_finalize)
            missing_symbol = "pshmem_finalize";
        
        if(missing_symbol)
        {
            fprintf(stderr,
                "ERROR: unable to find the symbol '%s' in your program.\n"
                "Please check you have linked your SHMEM implementation *after* the Allinea\n"
                "sampler and MPI wrapper libraries. You can always contact support@allinea.com\n"
                "for assistance.\n",
                missing_symbol
            );
            abort();
        }
#endif
    }
    if (useStartPes) {
        pstart_pes(i);
    } else {
        pshmem_init();
    }
    if (initMap)
    {
        allinea_set_is_rank_0(p_my_pe()==0? 1 : 0);

        pshmem_barrier_all();
        allinea_mid_mpi_init();
        pshmem_barrier_all();
        allinea_mapNoBarrierCount = 0;
        allinea_post_mpi_init();
    }

    allinea_wrapperExit();
}

/* Wrapper for start_pes() when called from C */
void start_pes(int i)
{
    allinea_shmem_init(StartPes, i);
}

/* Wrapper for start_pes() when called from Fortran */
void start_pes_(int* i)
{
    start_pes(*i);
}

/* Wrapper for shmem_init() when called from C */
void shmem_init(void)
{
    allinea_shmem_init(ShmemInit, 0);
}

/* Wrapper for shmem_init() when called from Fortran */
void shmem_init_(void)
{
    shmem_init();
}

void shmem_barrier_all()
{
#ifndef STATIC
    if(!pshmem_barrier_all)
    {
        fprintf(stderr,
            "ERROR: the Allinea wrapped start_pes has not been called.\n"
            "Please check you have called start_pes, and that you have linked your SHMEM\n"
            "implementation *after* the Allinea sampler and MPI wrapper libraries. You can\n"
            "always contact support@allinea.com if you need assistance.\n"
        );
        abort();
    }
#endif

    if (allinea_mapNoBarrierCount || allinea_shmemShutdown)
    {
        pshmem_barrier_all();
    }
    else
    {
        if(!allinea_wrapperEnter())
        {
            pshmem_barrier_all();
            return;
        }

        allinea_mapSamplerEnter("shmem_barrier_all", 0, 0, MPI_TYPE_COLLECTIVE);
        pshmem_barrier_all();
        allinea_mapSamplerExit(0);

        allinea_wrapperExit();
    }
}

void shmem_barrier_all_()
{
    shmem_barrier_all();
}

void shmem_finalize(void)
{
    allinea_shmemShutdown = 1;
    if(pshmem_finalize)
    {
        pshmem_finalize();
    }
    else
    {
        // this is an atexit handler, we probably can't do much about a failure
        // at this point
    }
}

void shmem_finalize_(void)
{
    shmem_finalize();
}
