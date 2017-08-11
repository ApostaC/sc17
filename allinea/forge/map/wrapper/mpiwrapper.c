
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _EXTERN_C_
#ifdef __cplusplus
#define _EXTERN_C_ extern "C"
#else /* __cplusplus */
#define _EXTERN_C_
#endif /* __cplusplus */
#endif /* _EXTERN_C_ */

#ifdef MPICH_HAS_C2F
_EXTERN_C_ void *MPIR_ToPointer(int);
#endif // MPICH_HAS_C2F

#if defined(__GNUC__) || defined(__INTEL_COMPILER) || defined(__PGI) || defined(_CRAYC)
#if defined(__GNUC__)
#define WEAK_POSTFIX __attribute__ ((weak))
#else
#define WEAK_POSTFIX
#define USE_WEAK_PRAGMA
#endif

#define WRAPPER_MPI_STATUS_SIZE (sizeof(MPI_Status)/sizeof(MPI_Fint))

/* OpenMPI */
_EXTERN_C_ MPI_Fint mpi_fortran_in_place WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint MPI_FORTRAN_IN_PLACE WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint mpi_fortran_in_place_ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint MPI_FORTRAN_IN_PLACE_ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint mpi_fortran_in_place__ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint MPI_FORTRAN_IN_PLACE__ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint mpi_fortran_bottom WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint MPI_FORTRAN_BOTTOM WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint mpi_fortran_bottom_ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint MPI_FORTRAN_BOTTOM_ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint mpi_fortran_bottom__ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint MPI_FORTRAN_BOTTOM__ WEAK_POSTFIX;
/* MPICH 2 */
_EXTERN_C_ MPI_Fint MPIFCMB3 WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint mpifcmb3 WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint MPIFCMB3_ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint mpifcmb3_ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint MPIFCMB3__ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint mpifcmb3__ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint MPIFCMB4 WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint mpifcmb4 WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint MPIFCMB4_ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint mpifcmb4_ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint MPIFCMB4__ WEAK_POSTFIX;
_EXTERN_C_ MPI_Fint mpifcmb4__ WEAK_POSTFIX;
/* Argonne Fortran MPI wrappers */
static char allinea_undefined_symbol;
_EXTERN_C_ void *MPIR_F_MPI_BOTTOM WEAK_POSTFIX = &allinea_undefined_symbol;
_EXTERN_C_ void *MPIR_F_MPI_IN_PLACE WEAK_POSTFIX = &allinea_undefined_symbol;
_EXTERN_C_ void *MPI_F_MPI_BOTTOM WEAK_POSTFIX = &allinea_undefined_symbol;
_EXTERN_C_ void *MPI_F_MPI_IN_PLACE WEAK_POSTFIX = &allinea_undefined_symbol;
/* SGI MPT */
_EXTERN_C_ MPI_Fint mpi_sgi_private_inplace_ WEAK_POSTFIX;


#ifdef USE_WEAK_PRAGMA
#pragma weak mpi_fortran_in_place
#pragma weak MPI_FORTRAN_IN_PLACE
#pragma weak mpi_fortran_in_place_
#pragma weak MPI_FORTRAN_IN_PLACE_
#pragma weak mpi_fortran_in_place__
#pragma weak MPI_FORTRAN_IN_PLACE__
#pragma weak mpi_fortran_bottom
#pragma weak MPI_FORTRAN_BOTTOM
#pragma weak mpi_fortran_bottom_
#pragma weak MPI_FORTRAN_BOTTOM_
#pragma weak mpi_fortran_bottom__
#pragma weak MPI_FORTRAN_BOTTOM__
/* MPICH 2 */
#pragma weak MPIFCMB3
#pragma weak mpifcmb3
#pragma weak MPIFCMB3_
#pragma weak mpifcmb3_
#pragma weak MPIFCMB3__
#pragma weak mpifcmb3__
#pragma weak MPIFCMB4
#pragma weak mpifcmb4
#pragma weak MPIFCMB4_
#pragma weak mpifcmb4_
#pragma weak MPIFCMB4__
#pragma weak mpifcmb4__
/* Argonne Fortran MPI wrappers */
#pragma weak MPIR_F_MPI_BOTTOM
#pragma weak MPIR_F_MPI_IN_PLACE
#pragma weak MPI_F_MPI_BOTTOM
#pragma weak MPI_F_MPI_IN_PLACE
/* SGI MPI */
#pragma weak mpi_sgi_private_inplace_
#endif

/* MPICH 2 requires no special handling - MPI_BOTTOM may (must!) be passed through as-is. */
#define IsBottom(x) ((x) == (void *) &mpi_fortran_bottom ||                      (x) == (void *) &MPI_FORTRAN_BOTTOM ||                      (x) == (void *) &mpi_fortran_bottom_ ||                      (x) == (void *) &MPI_FORTRAN_BOTTOM_ ||                      (x) == (void *) &mpi_fortran_bottom__ ||                      (x) == (void *) &MPI_FORTRAN_BOTTOM__)
#define IsInPlace(x) ((x) == (void *) &mpi_fortran_in_place ||                       (x) == (void *) &MPI_FORTRAN_IN_PLACE ||                       (x) == (void *) &mpi_fortran_in_place_ ||                       (x) == (void *) &MPI_FORTRAN_IN_PLACE_ ||                       (x) == (void *) &mpi_fortran_in_place__ ||                       (x) == (void *) &MPI_FORTRAN_IN_PLACE__ ||                       (x) == (void *) &MPIFCMB4 ||                       (x) == (void *) &mpifcmb4 ||                       (x) == (void *) &MPIFCMB4_ ||                       (x) == (void *) &mpifcmb4_ ||                       (x) == (void *) &MPIFCMB4__ ||                       (x) == (void *) &mpifcmb4__ ||                       (x) == MPIR_F_MPI_IN_PLACE ||                       (x) == MPI_F_MPI_IN_PLACE ||                       (x) == (void *) &mpi_sgi_private_inplace_)


#if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH has no MPI_IN_PLACE */
#define BufferF2C(x) (IsBottom(x) ? MPI_BOTTOM : (x))
#else
#define BufferF2C(x) (IsBottom(x) ? MPI_BOTTOM : (IsInPlace(x) ? MPI_IN_PLACE : (x)))
#endif /* defined(MPICH_NAME) && (MPICH_NAME == 1) */

#else
#define BufferF2C(x) (x)
#endif /* defined(__GNUC__) || defined(__INTEL_COMPILER) || defined(__PGI) || defined(_CRAYC) */

/* Convert a Fortran string into a C string. The returned C string must be 
 * explicitly freed with free() once it is no longer needed. */
static char* wrapper_fortran_to_c_string(const char *fortranStr, int length)
{
    const char *end;
    char *rtn;

    /* Discard leading blanks */
    while (' ' == *fortranStr && length > 0)
    {
        ++fortranStr;
        --length;
    }

    /* Discard trailing blanks */
    end = fortranStr + length -1;
    while (' ' == *end && length > 0)
    {
        --end;
        --length;
    }

    /* The caller must free this memory later. */
    rtn = (char*)malloc(length + 1);
    if (rtn)
    {
        strncpy(rtn, fortranStr, length);
        rtn[length] = '\0';
    }
    return rtn;
}


#if (defined(PIC) || defined(__PIC__))
/* For shared libraries, declare these weak and figure out which one was linked
   based on which init wrapper was called.  See mpi_init wrappers.  */
#pragma weak pmpi_init
#pragma weak PMPI_INIT
#pragma weak pmpi_init_
#pragma weak pmpi_init__
#pragma weak pmpi_init_thread
#pragma weak PMPI_INIT_THREAD
#pragma weak pmpi_init_thread_
#pragma weak pmpi_init_thread__
#endif /* PIC */

_EXTERN_C_ void pmpi_init(MPI_Fint *ierr);
_EXTERN_C_ void PMPI_INIT(MPI_Fint *ierr);
_EXTERN_C_ void pmpi_init_(MPI_Fint *ierr);
_EXTERN_C_ void pmpi_init__(MPI_Fint *ierr);
_EXTERN_C_ void pmpi_init_thread(MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr);
_EXTERN_C_ void PMPI_INIT_THREAD(MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr);
_EXTERN_C_ void pmpi_init_thread_(MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr);
_EXTERN_C_ void pmpi_init_thread__(MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr);

static int in_wrapper = 0;

#include "mapsampler_api.h"
#include "mapsampler_api_private.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

extern int allinea_mapNoBarrierCount;
extern int allinea_mapHasEnteredInit;

extern void allinea_mapSamplerEnter(const char *functionName,
                     unsigned long long bytesSent,
                     unsigned long long bytesRecv,
                     unsigned int mpiType);

extern void allinea_mapSamplerEnterDataless(const char *functionName);

extern void allinea_mapSamplerExit(int returnVal);

extern int allinea_mapMpiWrapperVersion(void);

extern void allinea_type_size(MPI_Datatype type, int * size);

extern void allinea_mapWrapperPreMpiInit(void);
extern void allinea_mapWrapperPostMpiInit(void);

// avoid implicit prototype warnings for these Fortran functions:
// (MPI_Fint *ierr)
// (MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr)
void pmpi_init(MPI_Fint *);
void pmpi_init_(MPI_Fint *);
void pmpi_init__(MPI_Fint *);
void PMPI_INIT(MPI_Fint *);
void pmpi_init_thread(MPI_Fint *, MPI_Fint *, MPI_Fint *);
void pmpi_init_thread_(MPI_Fint *, MPI_Fint *, MPI_Fint *);
void pmpi_init_thread__(MPI_Fint *, MPI_Fint *, MPI_Fint *);
void PMPI_INIT_THREAD(MPI_Fint *, MPI_Fint *, MPI_Fint *);



int allinea_mapNoBarrierCount = 0;
int allinea_mapHasEnteredInit = 0;

int allinea_wrapperEnter()
{
    if(in_wrapper)
    {
        return 0;
    }
    else
    {
        in_wrapper = 1;
        return 1;
    }
}

void allinea_wrapperExit()
{
    in_wrapper = 0;
}

void allinea_mapSamplerEnter(const char *functionName,
                     unsigned long long bytesSent,
                     unsigned long long bytesRecv,
                     unsigned int mpiType)
{
    allinea_suspend_traces_for_mpi(functionName);
    allinea_add_mpi_call(functionName, bytesSent, bytesRecv, mpiType);
}

void allinea_mapSamplerEnterDataless(const char *functionName)
{
    allinea_suspend_traces_for_mpi(functionName);
    allinea_add_mpi_call(functionName, 0, 0, MPI_TYPE_OTHER);
}

void allinea_mapSamplerExit(int returnVal)
{
    allinea_resume_traces_for_mpi();
}

int allinea_mapMpiWrapperVersion()
{
    return MAP_WRAPPER_VERSION_CURRENT;
}

void allinea_mapWrapperPreMpiInit()
{
    allinea_mapHasEnteredInit = 1;
    allinea_mapNoBarrierCount = 1;
    allinea_pre_mpi_init();
}

void allinea_mapWrapperPostMpiInit()
{
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    allinea_set_is_rank_0(rank==0? 1 : 0);

    allinea_suspend_traces_for_mpi("allinea_mapWrapperPostMpiInit");
    MPI_Barrier(MPI_COMM_WORLD);
    allinea_resume_traces_for_mpi();

    allinea_mid_mpi_init(); /* sampler will be initialised here */

    allinea_suspend_traces_for_mpi("allinea_mapWrapperPostMpiInit");
    MPI_Barrier(MPI_COMM_WORLD);
    allinea_resume_traces_for_mpi();

    allinea_mapNoBarrierCount = 0;
    allinea_post_mpi_init();
}

void allinea_type_size(MPI_Datatype const _type, int * const _size)
{
    if (_type == MPI_DATATYPE_NULL) {
        *_size = 0;
    }
    else {
        PMPI_Type_size(_type, _size);
    }
}

static int fortran_init = 0;
/* ================== C Wrappers for MPI_Init ================== */
_EXTERN_C_ int PMPI_Init(int *argc, char ***argv);
_EXTERN_C_ int MPI_Init(int *argc, char ***argv) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Init(argc, argv);
    in_wrapper = 1;

    int initMap = 0;
    if (!allinea_mapHasEnteredInit)
    {
        initMap = 1;
        allinea_mapWrapperPreMpiInit();
    }

    allinea_suspend_traces_for_mpi("MPI_Init");
        if (fortran_init) {
#if (defined(PIC) || defined(__PIC__)) && !defined(STATIC)
        if (!PMPI_INIT && !pmpi_init && !pmpi_init_ && !pmpi_init__) {
            fprintf(stderr, "ERROR: Couldn't find fortran pmpi_init function.  Link against static library instead.\n");
            exit(1);
        }        switch (fortran_init) {
        case 1: PMPI_INIT(&_wrap_py_return_val);   break;
        case 2: pmpi_init(&_wrap_py_return_val);   break;
        case 3: pmpi_init_(&_wrap_py_return_val);  break;
        case 4: pmpi_init__(&_wrap_py_return_val); break;
        default:
            fprintf(stderr, "NO SUITABLE FORTRAN MPI_INIT BINDING\n");
            break;
        }
#else /* !PIC */
        pmpi_init_(&_wrap_py_return_val);
#endif /* !PIC */
    } else {
        _wrap_py_return_val = PMPI_Init(argc, argv);
    }

    allinea_resume_traces_for_mpi();

    if (initMap)
    {
        allinea_mapWrapperPostMpiInit();
    }
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Init =============== */
static void MPI_Init_fortran_wrapper(MPI_Fint *ierr) { 
    int argc = 0;
    char ** argv = NULL;
    int _wrap_py_return_val = 0;
    _wrap_py_return_val = MPI_Init(&argc, &argv);
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INIT(MPI_Fint *ierr) { 
    fortran_init = 1;
    MPI_Init_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_init(MPI_Fint *ierr) { 
    fortran_init = 2;
    MPI_Init_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_init_(MPI_Fint *ierr) { 
    fortran_init = 3;
    MPI_Init_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_init__(MPI_Fint *ierr) { 
    fortran_init = 4;
    MPI_Init_fortran_wrapper(ierr);
}

/* ================= End Wrappers for MPI_Init ================= */




static int fortran_init_thread = 0;
/* ================== C Wrappers for MPI_Init_thread ================== */
_EXTERN_C_ int PMPI_Init_thread(int *argc, char ***argv, int required, int *provided);
_EXTERN_C_ int MPI_Init_thread(int *argc, char ***argv, int required, int *provided) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Init_thread(argc, argv, required, provided);
    in_wrapper = 1;

    int initMap = 0;
    if (!allinea_mapHasEnteredInit)
    {
        initMap = 1;
        allinea_mapWrapperPreMpiInit();
    }
    if ((getenv("ALLINEA_FORCE_MPI_THREAD_FUNNELED") ||
         getenv("MAP_FORCE_MPI_THREAD_FUNNELED")) &&
        (required == MPI_THREAD_SERIALIZED ||
         required == MPI_THREAD_MULTIPLE)) {
        required = MPI_THREAD_FUNNELED;
    }

    allinea_suspend_traces_for_mpi("MPI_Init_thread");
        if (fortran_init_thread) {
#if (defined(PIC) || defined(__PIC__)) && !defined(STATIC)
        if (!PMPI_INIT_THREAD && !pmpi_init_thread && !pmpi_init_thread_ && !pmpi_init_thread__) {
            fprintf(stderr, "ERROR: Couldn't find fortran pmpi_init_thread function.  Link against static library instead.\n");
            exit(1);
        }        switch (fortran_init_thread) {
        case 1: PMPI_INIT_THREAD(&required, provided, &_wrap_py_return_val);   break;
        case 2: pmpi_init_thread(&required, provided, &_wrap_py_return_val);   break;
        case 3: pmpi_init_thread_(&required, provided, &_wrap_py_return_val);  break;
        case 4: pmpi_init_thread__(&required, provided, &_wrap_py_return_val); break;
        default:
            fprintf(stderr, "NO SUITABLE FORTRAN MPI_INIT_THREAD BINDING\n");
            break;
        }
#else /* !PIC */
        pmpi_init_thread_(&required, provided, &_wrap_py_return_val);
#endif /* !PIC */
    } else {
        _wrap_py_return_val = PMPI_Init_thread(argc, argv, required, provided);
    }

    allinea_resume_traces_for_mpi();

    if (initMap)
    {
        allinea_mpi_thread_support_t threadSupport = ALLINEA_MPI_THREAD_SUPPORT_UNSPECIFIED;
        switch (required)
        {
        case MPI_THREAD_SINGLE:     threadSupport = ALLINEA_MPI_THREAD_SUPPORT_SINGLE;     break;
        case MPI_THREAD_FUNNELED:   threadSupport = ALLINEA_MPI_THREAD_SUPPORT_FUNNELED;   break;
        case MPI_THREAD_SERIALIZED: threadSupport = ALLINEA_MPI_THREAD_SUPPORT_SERIALIZED; break;
        case MPI_THREAD_MULTIPLE:   threadSupport = ALLINEA_MPI_THREAD_SUPPORT_MULTIPLE;   break;
        default:                    threadSupport = ALLINEA_MPI_THREAD_SUPPORT_UNSPECIFIED;
        }

        allinea_set_mpi_thread_support(threadSupport);
        allinea_mapWrapperPostMpiInit();
    }
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Init_thread =============== */
static void MPI_Init_thread_fortran_wrapper(MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr) { 
    int argc = 0;
    char ** argv = NULL;
    int _wrap_py_return_val = 0;
    _wrap_py_return_val = MPI_Init_thread(&argc, &argv, *required, provided);
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INIT_THREAD(MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr) { 
    fortran_init_thread = 1;
    MPI_Init_thread_fortran_wrapper(required, provided, ierr);
}

_EXTERN_C_ void mpi_init_thread(MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr) { 
    fortran_init_thread = 2;
    MPI_Init_thread_fortran_wrapper(required, provided, ierr);
}

_EXTERN_C_ void mpi_init_thread_(MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr) { 
    fortran_init_thread = 3;
    MPI_Init_thread_fortran_wrapper(required, provided, ierr);
}

_EXTERN_C_ void mpi_init_thread__(MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr) { 
    fortran_init_thread = 4;
    MPI_Init_thread_fortran_wrapper(required, provided, ierr);
}

/* ================= End Wrappers for MPI_Init_thread ================= */





/* ================== C Wrappers for MPI_Send ================== */
_EXTERN_C_ int PMPI_Send(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
_EXTERN_C_ int MPI_Send(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Send(buf, count, datatype, dest, tag, comm);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesSent;
    allinea_type_size(datatype, &_size);
    _bytesSent = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Send", _bytesSent, 0, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Send(buf, count, datatype, dest, tag, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Send =============== */
static void MPI_Send_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Send(BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Send(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Send_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_send(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Send_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_send_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Send_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_send__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Send_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

/* ================= End Wrappers for MPI_Send ================= */


/* ================== C Wrappers for MPI_Isend ================== */
_EXTERN_C_ int PMPI_Isend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Isend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Isend(buf, count, datatype, dest, tag, comm, request);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesSent;
    allinea_type_size(datatype, &_size);
    _bytesSent = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Isend", _bytesSent, 0, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Isend(buf, count, datatype, dest, tag, comm, request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Isend =============== */
static void MPI_Isend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Isend(BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    _wrap_py_return_val = MPI_Isend(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ISEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Isend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_isend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Isend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_isend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Isend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_isend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Isend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Isend ================= */


/* ================== C Wrappers for MPI_Ibsend ================== */
_EXTERN_C_ int PMPI_Ibsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Ibsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Ibsend(buf, count, datatype, dest, tag, comm, request);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesSent;
    allinea_type_size(datatype, &_size);
    _bytesSent = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Ibsend", _bytesSent, 0, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Ibsend(buf, count, datatype, dest, tag, comm, request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Ibsend =============== */
static void MPI_Ibsend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ibsend(BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    _wrap_py_return_val = MPI_Ibsend(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IBSEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_ibsend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_ibsend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_ibsend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Ibsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Ibsend ================= */


/* ================== C Wrappers for MPI_Irsend ================== */
_EXTERN_C_ int PMPI_Irsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Irsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Irsend(buf, count, datatype, dest, tag, comm, request);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesSent;
    allinea_type_size(datatype, &_size);
    _bytesSent = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Irsend", _bytesSent, 0, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Irsend(buf, count, datatype, dest, tag, comm, request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Irsend =============== */
static void MPI_Irsend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Irsend(BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    _wrap_py_return_val = MPI_Irsend(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IRSEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irsend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irsend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irsend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Irsend ================= */


/* ================== C Wrappers for MPI_Issend ================== */
_EXTERN_C_ int PMPI_Issend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Issend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Issend(buf, count, datatype, dest, tag, comm, request);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesSent;
    allinea_type_size(datatype, &_size);
    _bytesSent = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Issend", _bytesSent, 0, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Issend(buf, count, datatype, dest, tag, comm, request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Issend =============== */
static void MPI_Issend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Issend(BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    _wrap_py_return_val = MPI_Issend(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ISSEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Issend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_issend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Issend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_issend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Issend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_issend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Issend_fortran_wrapper(buf, count, datatype, dest, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Issend ================= */


/* ================== C Wrappers for MPI_Ssend ================== */
_EXTERN_C_ int PMPI_Ssend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
_EXTERN_C_ int MPI_Ssend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Ssend(buf, count, datatype, dest, tag, comm);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesSent;
    allinea_type_size(datatype, &_size);
    _bytesSent = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Ssend", _bytesSent, 0, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Ssend(buf, count, datatype, dest, tag, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Ssend =============== */
static void MPI_Ssend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Ssend(BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Ssend(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SSEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Ssend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_ssend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Ssend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_ssend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Ssend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_ssend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Ssend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

/* ================= End Wrappers for MPI_Ssend ================= */


/* ================== C Wrappers for MPI_Rsend ================== */
_EXTERN_C_ int PMPI_Rsend(void *ibuf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
_EXTERN_C_ int MPI_Rsend(void *ibuf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Rsend(ibuf, count, datatype, dest, tag, comm);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesSent;
    allinea_type_size(datatype, &_size);
    _bytesSent = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Rsend", _bytesSent, 0, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Rsend(ibuf, count, datatype, dest, tag, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Rsend =============== */
static void MPI_Rsend_fortran_wrapper(MPI_Fint *ibuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Rsend(BufferF2C((void*)ibuf), *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Rsend(BufferF2C((void*)ibuf), *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_RSEND(MPI_Fint *ibuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Rsend_fortran_wrapper(ibuf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_rsend(MPI_Fint *ibuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Rsend_fortran_wrapper(ibuf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_rsend_(MPI_Fint *ibuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Rsend_fortran_wrapper(ibuf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_rsend__(MPI_Fint *ibuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Rsend_fortran_wrapper(ibuf, count, datatype, dest, tag, comm, ierr);
}

/* ================= End Wrappers for MPI_Rsend ================= */


/* ================== C Wrappers for MPI_Bsend ================== */
_EXTERN_C_ int PMPI_Bsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
_EXTERN_C_ int MPI_Bsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Bsend(buf, count, datatype, dest, tag, comm);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesSent;
    allinea_type_size(datatype, &_size);
    _bytesSent = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Bsend", _bytesSent, 0, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Bsend(buf, count, datatype, dest, tag, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Bsend =============== */
static void MPI_Bsend_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Bsend(BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), *dest, *tag, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Bsend(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *dest, *tag, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_BSEND(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_bsend(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_bsend_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

_EXTERN_C_ void mpi_bsend__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bsend_fortran_wrapper(buf, count, datatype, dest, tag, comm, ierr);
}

/* ================= End Wrappers for MPI_Bsend ================= */


/* ================== C Wrappers for MPI_Accumulate ================== */
_EXTERN_C_ int PMPI_Accumulate(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);
_EXTERN_C_ int MPI_Accumulate(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesSent;
    allinea_type_size(origin_datatype, &_size);
    _bytesSent = origin_count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Accumulate", _bytesSent, 0, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Accumulate =============== */
static void MPI_Accumulate_fortran_wrapper(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *op, MPI_Fint *win, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Accumulate(BufferF2C((void*)origin_addr), *origin_count, (MPI_Datatype)(*origin_datatype), *target_rank, *target_disp, *target_count, (MPI_Datatype)(*target_datatype), (MPI_Op)(*op), (MPI_Win)(*win));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Accumulate(BufferF2C((void*)origin_addr), *origin_count, MPI_Type_f2c(*origin_datatype), *target_rank, *target_disp, *target_count, MPI_Type_f2c(*target_datatype), MPI_Op_f2c(*op), MPI_Win_f2c(*win));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ACCUMULATE(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *op, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Accumulate_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}

_EXTERN_C_ void mpi_accumulate(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *op, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Accumulate_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}

_EXTERN_C_ void mpi_accumulate_(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *op, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Accumulate_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}

_EXTERN_C_ void mpi_accumulate__(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *op, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Accumulate_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierr);
}

/* ================= End Wrappers for MPI_Accumulate ================= */


/* ================== C Wrappers for MPI_Put ================== */
_EXTERN_C_ int PMPI_Put(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win);
_EXTERN_C_ int MPI_Put(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesSent;
    allinea_type_size(origin_datatype, &_size);
    _bytesSent = origin_count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Put", _bytesSent, 0, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Put =============== */
static void MPI_Put_fortran_wrapper(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Put(BufferF2C((void*)origin_addr), *origin_count, (MPI_Datatype)(*origin_datatype), *target_rank, *target_disp, *target_count, (MPI_Datatype)(*target_datatype), (MPI_Win)(*win));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Put(BufferF2C((void*)origin_addr), *origin_count, MPI_Type_f2c(*origin_datatype), *target_rank, *target_disp, *target_count, MPI_Type_f2c(*target_datatype), MPI_Win_f2c(*win));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_PUT(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Put_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}

_EXTERN_C_ void mpi_put(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Put_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}

_EXTERN_C_ void mpi_put_(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Put_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}

_EXTERN_C_ void mpi_put__(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Put_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}

/* ================= End Wrappers for MPI_Put ================= */




/* ================== C Wrappers for MPI_Recv ================== */
_EXTERN_C_ int PMPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status);
_EXTERN_C_ int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Recv(buf, count, datatype, source, tag, comm, status);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesRecv;
    allinea_type_size(datatype, &_size);
    _bytesRecv = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Recv", 0, _bytesRecv, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Recv(buf, count, datatype, source, tag, comm, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Recv =============== */
static void MPI_Recv_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Recv(BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), *source, *tag, (MPI_Comm)(*comm), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Recv(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *source, *tag, MPI_Comm_f2c(*comm), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Recv(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *source, *tag, MPI_Comm_f2c(*comm), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_RECV(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Recv_fortran_wrapper(buf, count, datatype, source, tag, comm, status, ierr);
}

_EXTERN_C_ void mpi_recv(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Recv_fortran_wrapper(buf, count, datatype, source, tag, comm, status, ierr);
}

_EXTERN_C_ void mpi_recv_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Recv_fortran_wrapper(buf, count, datatype, source, tag, comm, status, ierr);
}

_EXTERN_C_ void mpi_recv__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Recv_fortran_wrapper(buf, count, datatype, source, tag, comm, status, ierr);
}

/* ================= End Wrappers for MPI_Recv ================= */


/* ================== C Wrappers for MPI_Irecv ================== */
_EXTERN_C_ int PMPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request);
_EXTERN_C_ int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Irecv(buf, count, datatype, source, tag, comm, request);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesRecv;
    allinea_type_size(datatype, &_size);
    _bytesRecv = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Irecv", 0, _bytesRecv, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Irecv(buf, count, datatype, source, tag, comm, request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Irecv =============== */
static void MPI_Irecv_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Irecv(BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), *source, *tag, (MPI_Comm)(*comm), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    _wrap_py_return_val = MPI_Irecv(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *source, *tag, MPI_Comm_f2c(*comm), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_IRECV(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irecv_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irecv(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irecv_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irecv_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irecv_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

_EXTERN_C_ void mpi_irecv__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Irecv_fortran_wrapper(buf, count, datatype, source, tag, comm, request, ierr);
}

/* ================= End Wrappers for MPI_Irecv ================= */


/* ================== C Wrappers for MPI_Get ================== */
_EXTERN_C_ int PMPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win);
_EXTERN_C_ int MPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesRecv;
    allinea_type_size(origin_datatype, &_size);
    _bytesRecv = origin_count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Get", 0, _bytesRecv, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Get =============== */
static void MPI_Get_fortran_wrapper(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Get(BufferF2C((void*)origin_addr), *origin_count, (MPI_Datatype)(*origin_datatype), *target_rank, *target_disp, *target_count, (MPI_Datatype)(*target_datatype), (MPI_Win)(*win));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Get(BufferF2C((void*)origin_addr), *origin_count, MPI_Type_f2c(*origin_datatype), *target_rank, *target_disp, *target_count, MPI_Type_f2c(*target_datatype), MPI_Win_f2c(*win));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_GET(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Get_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}

_EXTERN_C_ void mpi_get(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Get_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}

_EXTERN_C_ void mpi_get_(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Get_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}

_EXTERN_C_ void mpi_get__(MPI_Fint *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) { 
    MPI_Get_fortran_wrapper(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierr);
}

/* ================= End Wrappers for MPI_Get ================= */




/* ================== C Wrappers for MPI_Sendrecv ================== */
_EXTERN_C_ int PMPI_Sendrecv(void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status);
_EXTERN_C_ int MPI_Sendrecv(void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytesSent, _bytesRecv;
    allinea_type_size(sendtype, &_size);
    _bytesSent = sendcount * (unsigned long long)_size;
    allinea_type_size(recvtype, &_size);
    _bytesRecv = recvcount * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Sendrecv", _bytesSent, _bytesRecv, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Sendrecv =============== */
static void MPI_Sendrecv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Sendrecv(BufferF2C((void*)sendbuf), *sendcount, (MPI_Datatype)(*sendtype), *dest, *sendtag, BufferF2C((void*)recvbuf), *recvcount, (MPI_Datatype)(*recvtype), *source, *recvtag, (MPI_Comm)(*comm), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Sendrecv(BufferF2C((void*)sendbuf), *sendcount, MPI_Type_f2c(*sendtype), *dest, *sendtag, BufferF2C((void*)recvbuf), *recvcount, MPI_Type_f2c(*recvtype), *source, *recvtag, MPI_Comm_f2c(*comm), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Sendrecv(BufferF2C((void*)sendbuf), *sendcount, MPI_Type_f2c(*sendtype), *dest, *sendtag, BufferF2C((void*)recvbuf), *recvcount, MPI_Type_f2c(*recvtype), *source, *recvtag, MPI_Comm_f2c(*comm), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SENDRECV(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_fortran_wrapper(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_fortran_wrapper(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_fortran_wrapper(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_fortran_wrapper(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr);
}

/* ================= End Wrappers for MPI_Sendrecv ================= */




/* ================== C Wrappers for MPI_Sendrecv_replace ================== */
_EXTERN_C_ int PMPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status);
_EXTERN_C_ int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status);
    in_wrapper = 1;

    int _size;
    unsigned long long _bytes;
    allinea_type_size(datatype, &_size);
    _bytes = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Sendrecv_replace", _bytes, _bytes, MPI_TYPE_P2P);
    _wrap_py_return_val = PMPI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Sendrecv_replace =============== */
static void MPI_Sendrecv_replace_fortran_wrapper(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Sendrecv_replace(BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), *dest, *sendtag, *source, *recvtag, (MPI_Comm)(*comm), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Sendrecv_replace(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *dest, *sendtag, *source, *recvtag, MPI_Comm_f2c(*comm), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Sendrecv_replace(BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), *dest, *sendtag, *source, *recvtag, MPI_Comm_f2c(*comm), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SENDRECV_REPLACE(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_replace_fortran_wrapper(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv_replace(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_replace_fortran_wrapper(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv_replace_(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_replace_fortran_wrapper(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}

_EXTERN_C_ void mpi_sendrecv_replace__(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Sendrecv_replace_fortran_wrapper(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr);
}

/* ================= End Wrappers for MPI_Sendrecv_replace ================= */




/* ================== C Wrappers for MPI_Bcast ================== */
_EXTERN_C_ int PMPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Bcast(buffer, count, datatype, root, comm);
    in_wrapper = 1;

    int _size, _rank;
    unsigned long long _bytes;
    const char* const mpiBcastName = "MPI_Bcast";

    PMPI_Comm_rank(comm, &_rank);
    allinea_type_size(datatype, &_size);
    _bytes = count * (unsigned long long)_size;

    if (_rank == root)
        allinea_mapSamplerEnter(mpiBcastName, _bytes, 0, MPI_TYPE_COLLECTIVE);
    else
        allinea_mapSamplerEnter(mpiBcastName, 0, _bytes, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Bcast(buffer, count, datatype, root, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Bcast =============== */
static void MPI_Bcast_fortran_wrapper(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Bcast(BufferF2C((void*)buffer), *count, (MPI_Datatype)(*datatype), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Bcast(BufferF2C((void*)buffer), *count, MPI_Type_f2c(*datatype), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_BCAST(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bcast_fortran_wrapper(buffer, count, datatype, root, comm, ierr);
}

_EXTERN_C_ void mpi_bcast(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bcast_fortran_wrapper(buffer, count, datatype, root, comm, ierr);
}

_EXTERN_C_ void mpi_bcast_(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bcast_fortran_wrapper(buffer, count, datatype, root, comm, ierr);
}

_EXTERN_C_ void mpi_bcast__(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Bcast_fortran_wrapper(buffer, count, datatype, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Bcast ================= */




/* ================== C Wrappers for MPI_Gather ================== */
_EXTERN_C_ int PMPI_Gather(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Gather(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);
    in_wrapper = 1;

    int _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size(comm, &_commSize);
    PMPI_Comm_rank(comm, &_rank);
    allinea_type_size(sendtype, &_size);
    _bytesSent = sendcount * (unsigned long long)_size;
    if (_rank == root)
    {
        allinea_type_size(recvtype, &_size);
        _bytesRecv = recvcount * (unsigned long long)_size * _commSize;
    }
    else 
        _bytesRecv = 0;
    allinea_mapSamplerEnter("MPI_Gather", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Gather =============== */
static void MPI_Gather_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Gather(BufferF2C((void*)sendbuf), *sendcount, (MPI_Datatype)(*sendtype), BufferF2C((void*)recvbuf), *recvcount, (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Gather(BufferF2C((void*)sendbuf), *sendcount, MPI_Type_f2c(*sendtype), BufferF2C((void*)recvbuf), *recvcount, MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_GATHER(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gather(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gather_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gather__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Gather ================= */




/* ================== C Wrappers for MPI_Gatherv ================== */
_EXTERN_C_ int PMPI_Gatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int *recvcounts, int *displs, MPI_Datatype recvtype, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Gatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int *recvcounts, int *displs, MPI_Datatype recvtype, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm);
    in_wrapper = 1;

    int _i, _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size(comm, &_commSize);
    PMPI_Comm_rank(comm, &_rank);
    allinea_type_size(sendtype, &_size);
    _bytesSent = sendcount * (unsigned long long)_size;
    if (_rank == root && recvcounts != 0)
    {
        allinea_type_size(recvtype, &_size);
        _bytesRecv = 0;
        for (_i=0; _i<_commSize; ++_i)
        {
            _bytesRecv += recvcounts[_i] * (unsigned long long)_size;
        }
    }
    else 
        _bytesRecv = 0;
    allinea_mapSamplerEnter("MPI_Gatherv", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Gatherv =============== */
static void MPI_Gatherv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Gatherv(BufferF2C((void*)sendbuf), *sendcount, (MPI_Datatype)(*sendtype), BufferF2C((void*)recvbuf), BufferF2C((int*)recvcounts), BufferF2C((int*)displs), (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Gatherv(BufferF2C((void*)sendbuf), *sendcount, MPI_Type_f2c(*sendtype), BufferF2C((void*)recvbuf), BufferF2C((int*)recvcounts), BufferF2C((int*)displs), MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_GATHERV(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gatherv(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gatherv_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_gatherv__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Gatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Gatherv ================= */




/* ================== C Wrappers for MPI_Scatter ================== */
_EXTERN_C_ int PMPI_Scatter(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Scatter(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);
    in_wrapper = 1;

    int _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size(comm, &_commSize);
    PMPI_Comm_rank(comm, &_rank);
    allinea_type_size(recvtype, &_size);
    _bytesRecv = recvcount * (unsigned long long)_size;
    if (_rank == root)
    {
        allinea_type_size(sendtype, &_size);
        _bytesSent = sendcount * (unsigned long long)_size * _commSize;
    }
    else 
        _bytesSent = 0;
    allinea_mapSamplerEnter("MPI_Scatter", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Scatter =============== */
static void MPI_Scatter_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Scatter(BufferF2C((void*)sendbuf), *sendcount, (MPI_Datatype)(*sendtype), BufferF2C((void*)recvbuf), *recvcount, (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Scatter(BufferF2C((void*)sendbuf), *sendcount, MPI_Type_f2c(*sendtype), BufferF2C((void*)recvbuf), *recvcount, MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SCATTER(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatter(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatter_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatter__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatter_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Scatter ================= */




/* ================== C Wrappers for MPI_Scatterv ================== */
_EXTERN_C_ int PMPI_Scatterv(void *sendbuf, int *sendcounts, int *displs, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Scatterv(void *sendbuf, int *sendcounts, int *displs, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm);
    in_wrapper = 1;

    int _i, _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size(comm, &_commSize);
    PMPI_Comm_rank(comm, &_rank);
    allinea_type_size(recvtype, &_size);
    _bytesRecv = recvcount * (unsigned long long)_size;
    if (_rank == root && sendcounts != 0)
    {
        allinea_type_size(sendtype, &_size);
        _bytesSent = 0;
        for (_i=0; _i<_commSize; ++_i)
        {
            _bytesSent += sendcounts[_i] * (unsigned long long)_size;
        }
    }
    else 
        _bytesSent = 0;
    allinea_mapSamplerEnter("MPI_Scatterv", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Scatterv =============== */
static void MPI_Scatterv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *displs, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Scatterv(BufferF2C((void*)sendbuf), BufferF2C((int*)sendcounts), BufferF2C((int*)displs), (MPI_Datatype)(*sendtype), BufferF2C((void*)recvbuf), *recvcount, (MPI_Datatype)(*recvtype), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Scatterv(BufferF2C((void*)sendbuf), BufferF2C((int*)sendcounts), BufferF2C((int*)displs), MPI_Type_f2c(*sendtype), BufferF2C((void*)recvbuf), *recvcount, MPI_Type_f2c(*recvtype), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SCATTERV(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *displs, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatterv(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *displs, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatterv_(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *displs, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

_EXTERN_C_ void mpi_scatterv__(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *displs, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scatterv_fortran_wrapper(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Scatterv ================= */




/* ================== C Wrappers for MPI_Reduce ================== */
_EXTERN_C_ int PMPI_Reduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm);
_EXTERN_C_ int MPI_Reduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm);
    in_wrapper = 1;

    int _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size(comm, &_commSize);
    PMPI_Comm_rank(comm, &_rank);
    allinea_type_size(datatype, &_size);
    _bytesSent = count * (unsigned long long)_size;
    if (_rank == root)
    {
        _bytesRecv = _bytesSent;
    }
    else 
        _bytesRecv = 0;
    allinea_mapSamplerEnter("MPI_Reduce", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Reduce =============== */
static void MPI_Reduce_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Reduce(BufferF2C((void*)sendbuf), BufferF2C((void*)recvbuf), *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), *root, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Reduce(BufferF2C((void*)sendbuf), BufferF2C((void*)recvbuf), *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), *root, MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_REDUCE(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}

_EXTERN_C_ void mpi_reduce(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}

_EXTERN_C_ void mpi_reduce_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}

_EXTERN_C_ void mpi_reduce__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
}

/* ================= End Wrappers for MPI_Reduce ================= */




/* ================== C Wrappers for MPI_Reduce_scatter ================== */
_EXTERN_C_ int PMPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcounts, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
_EXTERN_C_ int MPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcounts, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm);
    in_wrapper = 1;

    int _i, _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size(comm, &_commSize);
    PMPI_Comm_rank(comm, &_rank);
    allinea_type_size(datatype, &_size);
    _bytesRecv = recvcounts[_rank] * (unsigned long long)_size;

    _bytesSent = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        _bytesSent += recvcounts[_i] * (unsigned long long)_size;
    }

    allinea_mapSamplerEnter("MPI_Reduce_scatter", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Reduce_scatter =============== */
static void MPI_Reduce_scatter_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Reduce_scatter(BufferF2C((void*)sendbuf), BufferF2C((void*)recvbuf), BufferF2C((int*)recvcounts), (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Reduce_scatter(BufferF2C((void*)sendbuf), BufferF2C((void*)recvbuf), BufferF2C((int*)recvcounts), MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_REDUCE_SCATTER(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_reduce_scatter(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_reduce_scatter_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_reduce_scatter__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Reduce_scatter_fortran_wrapper(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
}

/* ================= End Wrappers for MPI_Reduce_scatter ================= */






/* ================== C Wrappers for MPI_Allreduce ================== */
_EXTERN_C_ int PMPI_Allreduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
_EXTERN_C_ int MPI_Allreduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm);
    in_wrapper = 1;

    int _size, _commSize, _rank;
    unsigned long long _bytes;
    PMPI_Comm_size(comm, &_commSize);
    PMPI_Comm_rank(comm, &_rank);
    allinea_type_size(datatype, &_size);
    _bytes = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Allreduce", _bytes, _bytes, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Allreduce =============== */
static void MPI_Allreduce_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Allreduce(BufferF2C((void*)sendbuf), BufferF2C((void*)recvbuf), *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Allreduce(BufferF2C((void*)sendbuf), BufferF2C((void*)recvbuf), *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLREDUCE(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_allreduce(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_allreduce_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_allreduce__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allreduce_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

/* ================= End Wrappers for MPI_Allreduce ================= */


/* ================== C Wrappers for MPI_Scan ================== */
_EXTERN_C_ int PMPI_Scan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
_EXTERN_C_ int MPI_Scan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Scan(sendbuf, recvbuf, count, datatype, op, comm);
    in_wrapper = 1;

    int _size, _commSize, _rank;
    unsigned long long _bytes;
    PMPI_Comm_size(comm, &_commSize);
    PMPI_Comm_rank(comm, &_rank);
    allinea_type_size(datatype, &_size);
    _bytes = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Scan", _bytes, _bytes, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Scan(sendbuf, recvbuf, count, datatype, op, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Scan =============== */
static void MPI_Scan_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Scan(BufferF2C((void*)sendbuf), BufferF2C((void*)recvbuf), *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Scan(BufferF2C((void*)sendbuf), BufferF2C((void*)recvbuf), *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_SCAN(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_scan(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_scan_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_scan__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Scan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

/* ================= End Wrappers for MPI_Scan ================= */


/* ================== C Wrappers for MPI_Exscan ================== */
_EXTERN_C_ int PMPI_Exscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
_EXTERN_C_ int MPI_Exscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm);
    in_wrapper = 1;

    int _size, _commSize, _rank;
    unsigned long long _bytes;
    PMPI_Comm_size(comm, &_commSize);
    PMPI_Comm_rank(comm, &_rank);
    allinea_type_size(datatype, &_size);
    _bytes = count * (unsigned long long)_size;
    allinea_mapSamplerEnter("MPI_Exscan", _bytes, _bytes, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Exscan =============== */
static void MPI_Exscan_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Exscan(BufferF2C((void*)sendbuf), BufferF2C((void*)recvbuf), *count, (MPI_Datatype)(*datatype), (MPI_Op)(*op), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Exscan(BufferF2C((void*)sendbuf), BufferF2C((void*)recvbuf), *count, MPI_Type_f2c(*datatype), MPI_Op_f2c(*op), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_EXSCAN(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Exscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_exscan(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Exscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_exscan_(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Exscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

_EXTERN_C_ void mpi_exscan__(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Exscan_fortran_wrapper(sendbuf, recvbuf, count, datatype, op, comm, ierr);
}

/* ================= End Wrappers for MPI_Exscan ================= */




/* ================== C Wrappers for MPI_Allgather ================== */
_EXTERN_C_ int PMPI_Allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
    in_wrapper = 1;

    int _size, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size(comm, &_commSize);
    allinea_type_size(sendtype, &_size);
    _bytesSent = sendcount * (unsigned long long)_size * _commSize;

    allinea_type_size(recvtype, &_size);
    _bytesRecv = recvcount * (unsigned long long)_size * _commSize;
    allinea_mapSamplerEnter("MPI_Allgather", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Allgather =============== */
static void MPI_Allgather_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Allgather(BufferF2C((void*)sendbuf), *sendcount, (MPI_Datatype)(*sendtype), BufferF2C((void*)recvbuf), *recvcount, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Allgather(BufferF2C((void*)sendbuf), *sendcount, MPI_Type_f2c(*sendtype), BufferF2C((void*)recvbuf), *recvcount, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLGATHER(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgather(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgather_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgather__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgather_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Allgather ================= */


/* ================== C Wrappers for MPI_Alltoall ================== */
_EXTERN_C_ int PMPI_Alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
    in_wrapper = 1;

    int _size, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size(comm, &_commSize);
    allinea_type_size(sendtype, &_size);
    _bytesSent = sendcount * (unsigned long long)_size * _commSize;

    allinea_type_size(recvtype, &_size);
    _bytesRecv = recvcount * (unsigned long long)_size * _commSize;
    allinea_mapSamplerEnter("MPI_Alltoall", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Alltoall =============== */
static void MPI_Alltoall_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Alltoall(BufferF2C((void*)sendbuf), *sendcount, (MPI_Datatype)(*sendtype), BufferF2C((void*)recvbuf), *recvcount, (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Alltoall(BufferF2C((void*)sendbuf), *sendcount, MPI_Type_f2c(*sendtype), BufferF2C((void*)recvbuf), *recvcount, MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLTOALL(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoall(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoall_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoall__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoall_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Alltoall ================= */




/* ================== C Wrappers for MPI_Allgatherv ================== */
_EXTERN_C_ int PMPI_Allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int *recvcounts, int *displs, MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int *recvcounts, int *displs, MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
    in_wrapper = 1;

    int _i, _size, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size(comm, &_commSize);
    allinea_type_size(sendtype, &_size);
    _bytesSent = sendcount * (unsigned long long)_size;

    allinea_type_size(recvtype, &_size);
    _bytesRecv = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        _bytesRecv += recvcounts[_i] * (unsigned long long)_size;
    }

    allinea_mapSamplerEnter("MPI_Allgatherv", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Allgatherv =============== */
static void MPI_Allgatherv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Allgatherv(BufferF2C((void*)sendbuf), *sendcount, (MPI_Datatype)(*sendtype), BufferF2C((void*)recvbuf), BufferF2C((int*)recvcounts), BufferF2C((int*)displs), (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Allgatherv(BufferF2C((void*)sendbuf), *sendcount, MPI_Type_f2c(*sendtype), BufferF2C((void*)recvbuf), BufferF2C((int*)recvcounts), BufferF2C((int*)displs), MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLGATHERV(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgatherv(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgatherv_(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_allgatherv__(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Allgatherv_fortran_wrapper(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Allgatherv ================= */




/* ================== C Wrappers for MPI_Alltoallv ================== */
_EXTERN_C_ int PMPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls, MPI_Datatype sendtype, void *recvbuf, int *recvcounts, int *rdispls, MPI_Datatype recvtype, MPI_Comm comm);
_EXTERN_C_ int MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls, MPI_Datatype sendtype, void *recvbuf, int *recvcounts, int *rdispls, MPI_Datatype recvtype, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
    in_wrapper = 1;

    int _i, _sendTypeSize, _recvTypeSize, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size(comm, &_commSize);
    allinea_type_size(sendtype, &_sendTypeSize);
    allinea_type_size(recvtype, &_recvTypeSize);

    _bytesSent = 0;
    _bytesRecv = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        _bytesSent += sendcounts[_i] * (unsigned long long)_sendTypeSize;
        _bytesRecv += recvcounts[_i] * (unsigned long long)_recvTypeSize;
    }

    allinea_mapSamplerEnter("MPI_Alltoallv", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Alltoallv =============== */
static void MPI_Alltoallv_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Alltoallv(BufferF2C((void*)sendbuf), BufferF2C((int*)sendcounts), BufferF2C((int*)sdispls), (MPI_Datatype)(*sendtype), BufferF2C((void*)recvbuf), BufferF2C((int*)recvcounts), BufferF2C((int*)rdispls), (MPI_Datatype)(*recvtype), (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Alltoallv(BufferF2C((void*)sendbuf), BufferF2C((int*)sendcounts), BufferF2C((int*)sdispls), MPI_Type_f2c(*sendtype), BufferF2C((void*)recvbuf), BufferF2C((int*)recvcounts), BufferF2C((int*)rdispls), MPI_Type_f2c(*recvtype), MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLTOALLV(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallv(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallv_(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallv__(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallv_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
}

/* ================= End Wrappers for MPI_Alltoallv ================= */




/* ================== C Wrappers for MPI_Alltoallw ================== */
_EXTERN_C_ int PMPI_Alltoallw(void *sendbuf, int *sendcounts, int *sdispls, MPI_Datatype *sendtypes, void *recvbuf, int *recvcounts, int *rdispls, MPI_Datatype *recvtypes, MPI_Comm comm);
_EXTERN_C_ int MPI_Alltoallw(void *sendbuf, int *sendcounts, int *sdispls, MPI_Datatype *sendtypes, void *recvbuf, int *recvcounts, int *rdispls, MPI_Datatype *recvtypes, MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm);
    in_wrapper = 1;

    int _i, _sendTypeSize, _recvTypeSize, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size(comm, &_commSize);

    _bytesSent = 0;
    _bytesRecv = 0;
    if( sendbuf == MPI_IN_PLACE)
    {
        for (_i=0; _i<_commSize; ++_i)
        {
            allinea_type_size(recvtypes[_i], &_recvTypeSize);
            _bytesRecv += recvcounts[_i] * (unsigned long long)_recvTypeSize;
        }
        _bytesSent=_bytesRecv;
    }
    else
    {
        for (_i=0; _i<_commSize; ++_i)
        {
            allinea_type_size(sendtypes[_i], &_sendTypeSize);
            allinea_type_size(recvtypes[_i], &_recvTypeSize);

            _bytesSent += sendcounts[_i] * (unsigned long long)_sendTypeSize;
            _bytesRecv += recvcounts[_i] * (unsigned long long)_recvTypeSize;
        }
    }

    allinea_mapSamplerEnter("MPI_Alltoallw", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    _wrap_py_return_val = PMPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Alltoallw =============== */
static void MPI_Alltoallw_fortran_wrapper(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtypes, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Alltoallw(BufferF2C((void*)sendbuf), BufferF2C((int*)sendcounts), BufferF2C((int*)sdispls), (MPI_Datatype*)sendtypes, BufferF2C((void*)recvbuf), BufferF2C((int*)recvcounts), BufferF2C((int*)rdispls), (MPI_Datatype*)recvtypes, (MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    MPI_Datatype* temp_recvtypes;
    int i;
    int temp_count_sendtypes;
    int temp_count_recvtypes;
    MPI_Datatype* temp_sendtypes;
    MPI_Comm_size(MPI_Comm_f2c(*comm), &temp_count_sendtypes);
    temp_sendtypes = (MPI_Datatype*)malloc(sizeof(MPI_Datatype) * temp_count_sendtypes);
    for (i=0; i < temp_count_sendtypes; i++)
        temp_sendtypes[i] = MPI_Type_f2c(sendtypes[i]);
    MPI_Comm_size(MPI_Comm_f2c(*comm), &temp_count_recvtypes);
    temp_recvtypes = (MPI_Datatype*)malloc(sizeof(MPI_Datatype) * temp_count_recvtypes);
    for (i=0; i < temp_count_recvtypes; i++)
        temp_recvtypes[i] = MPI_Type_f2c(recvtypes[i]);
    _wrap_py_return_val = MPI_Alltoallw(BufferF2C((void*)sendbuf), BufferF2C((int*)sendcounts), BufferF2C((int*)sdispls), temp_sendtypes, BufferF2C((void*)recvbuf), BufferF2C((int*)recvcounts), BufferF2C((int*)rdispls), temp_recvtypes, MPI_Comm_f2c(*comm));
    free(temp_sendtypes);
    free(temp_recvtypes);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_ALLTOALLW(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtypes, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallw(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtypes, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallw_(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtypes, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

_EXTERN_C_ void mpi_alltoallw__(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtypes, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Alltoallw_fortran_wrapper(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
}

/* ================= End Wrappers for MPI_Alltoallw ================= */




/* ================== C Wrappers for MPI_Barrier ================== */
_EXTERN_C_ int PMPI_Barrier(MPI_Comm comm);
_EXTERN_C_ int MPI_Barrier(MPI_Comm comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Barrier(comm);
    in_wrapper = 1;

    if (allinea_mapNoBarrierCount)
        _wrap_py_return_val = PMPI_Barrier(comm);
    else
    {
        allinea_mapSamplerEnter("MPI_Barrier", 0, 0, MPI_TYPE_COLLECTIVE);
        _wrap_py_return_val = PMPI_Barrier(comm);
        allinea_mapSamplerExit(_wrap_py_return_val);
    }
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Barrier =============== */
static void MPI_Barrier_fortran_wrapper(MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Barrier((MPI_Comm)(*comm));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Barrier(MPI_Comm_f2c(*comm));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_BARRIER(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Barrier_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_barrier(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Barrier_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_barrier_(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Barrier_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_barrier__(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Barrier_fortran_wrapper(comm, ierr);
}

/* ================= End Wrappers for MPI_Barrier ================= */




/* ================== C Wrappers for MPI_Wait ================== */
_EXTERN_C_ int PMPI_Wait(MPI_Request *request, MPI_Status *status);
_EXTERN_C_ int MPI_Wait(MPI_Request *request, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Wait(request, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Wait");
    _wrap_py_return_val = PMPI_Wait(request, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Wait =============== */
static void MPI_Wait_fortran_wrapper(MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Wait((MPI_Request*)request, (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    temp_request = MPI_Request_f2c(*request);
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Wait(&temp_request, &temp_status);
    *request = MPI_Request_c2f(temp_request);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    temp_request = MPI_Request_f2c(*request);
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Wait(&temp_request, ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    *request = MPI_Request_c2f(temp_request);
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_WAIT(MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Wait_fortran_wrapper(request, status, ierr);
}

_EXTERN_C_ void mpi_wait(MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Wait_fortran_wrapper(request, status, ierr);
}

_EXTERN_C_ void mpi_wait_(MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Wait_fortran_wrapper(request, status, ierr);
}

_EXTERN_C_ void mpi_wait__(MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Wait_fortran_wrapper(request, status, ierr);
}

/* ================= End Wrappers for MPI_Wait ================= */


/* ================== C Wrappers for MPI_Waitsome ================== */
_EXTERN_C_ int PMPI_Waitsome(int incount, MPI_Request *array_of_requests, int *outcount, int *array_of_indices, MPI_Status *array_of_statuses);
_EXTERN_C_ int MPI_Waitsome(int incount, MPI_Request *array_of_requests, int *outcount, int *array_of_indices, MPI_Status *array_of_statuses) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Waitsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Waitsome");
    _wrap_py_return_val = PMPI_Waitsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Waitsome =============== */
static void MPI_Waitsome_fortran_wrapper(MPI_Fint *incount, MPI_Fint *array_of_requests, MPI_Fint *outcount, MPI_Fint *array_of_indices, MPI_Fint *array_of_statuses, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Waitsome(*incount, (MPI_Request*)array_of_requests, BufferF2C((int*)outcount), array_of_indices, (MPI_Status*)array_of_statuses);
#else /* MPI-2 safe call */
    MPI_Status* temp_array_of_statuses;
    MPI_Request* temp_array_of_requests;
    int i;
    temp_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request) * *incount);
    for (i=0; i < *incount; i++)
        temp_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
    if (array_of_statuses == MPI_F_STATUSES_IGNORE)
        temp_array_of_statuses = MPI_STATUSES_IGNORE;
    else
        temp_array_of_statuses = (MPI_Status*)malloc(sizeof(MPI_Status) * *incount);
    _wrap_py_return_val = MPI_Waitsome(*incount, temp_array_of_requests, BufferF2C((int*)outcount), array_of_indices, temp_array_of_statuses);
    for (i=0; i < *incount; i++)
        array_of_requests[i] = MPI_Request_c2f(temp_array_of_requests[i]);
    free(temp_array_of_requests);
    if (*outcount != MPI_UNDEFINED) {
        for (i=0; i < *outcount; ++i)
            ++array_of_indices[i];
    }
    if (array_of_statuses != MPI_F_STATUSES_IGNORE) {
        for (i=0; i < *incount; i++)
            MPI_Status_c2f(&temp_array_of_statuses[i], &array_of_statuses[WRAPPER_MPI_STATUS_SIZE*i]);
    }
    if (array_of_statuses != MPI_F_STATUSES_IGNORE)
        free(temp_array_of_statuses);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_WAITSOME(MPI_Fint *incount, MPI_Fint *array_of_requests, MPI_Fint *outcount, MPI_Fint *array_of_indices, MPI_Fint *array_of_statuses, MPI_Fint *ierr) { 
    MPI_Waitsome_fortran_wrapper(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierr);
}

_EXTERN_C_ void mpi_waitsome(MPI_Fint *incount, MPI_Fint *array_of_requests, MPI_Fint *outcount, MPI_Fint *array_of_indices, MPI_Fint *array_of_statuses, MPI_Fint *ierr) { 
    MPI_Waitsome_fortran_wrapper(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierr);
}

_EXTERN_C_ void mpi_waitsome_(MPI_Fint *incount, MPI_Fint *array_of_requests, MPI_Fint *outcount, MPI_Fint *array_of_indices, MPI_Fint *array_of_statuses, MPI_Fint *ierr) { 
    MPI_Waitsome_fortran_wrapper(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierr);
}

_EXTERN_C_ void mpi_waitsome__(MPI_Fint *incount, MPI_Fint *array_of_requests, MPI_Fint *outcount, MPI_Fint *array_of_indices, MPI_Fint *array_of_statuses, MPI_Fint *ierr) { 
    MPI_Waitsome_fortran_wrapper(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierr);
}

/* ================= End Wrappers for MPI_Waitsome ================= */


/* ================== C Wrappers for MPI_Waitany ================== */
_EXTERN_C_ int PMPI_Waitany(int count, MPI_Request *array_of_requests, int *index, MPI_Status *status);
_EXTERN_C_ int MPI_Waitany(int count, MPI_Request *array_of_requests, int *index, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Waitany(count, array_of_requests, index, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Waitany");
    _wrap_py_return_val = PMPI_Waitany(count, array_of_requests, index, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Waitany =============== */
static void MPI_Waitany_fortran_wrapper(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *index, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Waitany(*count, (MPI_Request*)array_of_requests, index, (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Request* temp_array_of_requests;
    MPI_Status temp_status;
    int i;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    temp_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request) * *count);
    for (i=0; i < *count; i++)
        temp_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Waitany(*count, temp_array_of_requests, index, &temp_status);
    for (i=0; i < *count; i++)
        array_of_requests[i] = MPI_Request_c2f(temp_array_of_requests[i]);
    free(temp_array_of_requests);
    if (*index != MPI_UNDEFINED) ++(*index);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    temp_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request) * *count);
    for (i=0; i < *count; i++)
        temp_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_Waitany(*count, temp_array_of_requests, index, ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    for (i=0; i < *count; i++)
        array_of_requests[i] = MPI_Request_c2f(temp_array_of_requests[i]);
    free(temp_array_of_requests);
    if (*index != MPI_UNDEFINED) ++(*index);
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_WAITANY(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *index, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Waitany_fortran_wrapper(count, array_of_requests, index, status, ierr);
}

_EXTERN_C_ void mpi_waitany(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *index, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Waitany_fortran_wrapper(count, array_of_requests, index, status, ierr);
}

_EXTERN_C_ void mpi_waitany_(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *index, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Waitany_fortran_wrapper(count, array_of_requests, index, status, ierr);
}

_EXTERN_C_ void mpi_waitany__(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *index, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_Waitany_fortran_wrapper(count, array_of_requests, index, status, ierr);
}

/* ================= End Wrappers for MPI_Waitany ================= */


/* ================== C Wrappers for MPI_Waitall ================== */
_EXTERN_C_ int PMPI_Waitall(int count, MPI_Request *array_of_requests, MPI_Status *array_of_statuses);
_EXTERN_C_ int MPI_Waitall(int count, MPI_Request *array_of_requests, MPI_Status *array_of_statuses) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Waitall(count, array_of_requests, array_of_statuses);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Waitall");
    _wrap_py_return_val = PMPI_Waitall(count, array_of_requests, array_of_statuses);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Waitall =============== */
static void MPI_Waitall_fortran_wrapper(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *array_of_statuses, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Waitall(*count, (MPI_Request*)array_of_requests, (MPI_Status*)array_of_statuses);
#else /* MPI-2 safe call */
    MPI_Status* temp_array_of_statuses;
    MPI_Request* temp_array_of_requests;
    int i;
    temp_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request) * *count);
    for (i=0; i < *count; i++)
        temp_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
    if (array_of_statuses == MPI_F_STATUSES_IGNORE)
        temp_array_of_statuses = MPI_STATUSES_IGNORE;
    else
        temp_array_of_statuses = (MPI_Status*)malloc(sizeof(MPI_Status) * *count);
    _wrap_py_return_val = MPI_Waitall(*count, temp_array_of_requests, temp_array_of_statuses);
    for (i=0; i < *count; i++)
        array_of_requests[i] = MPI_Request_c2f(temp_array_of_requests[i]);
    free(temp_array_of_requests);
    if (array_of_statuses != MPI_F_STATUSES_IGNORE) {
        for (i=0; i < *count; i++)
            MPI_Status_c2f(&temp_array_of_statuses[i], &array_of_statuses[WRAPPER_MPI_STATUS_SIZE*i]);
    }
    if (array_of_statuses != MPI_F_STATUSES_IGNORE)
        free(temp_array_of_statuses);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_WAITALL(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *array_of_statuses, MPI_Fint *ierr) { 
    MPI_Waitall_fortran_wrapper(count, array_of_requests, array_of_statuses, ierr);
}

_EXTERN_C_ void mpi_waitall(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *array_of_statuses, MPI_Fint *ierr) { 
    MPI_Waitall_fortran_wrapper(count, array_of_requests, array_of_statuses, ierr);
}

_EXTERN_C_ void mpi_waitall_(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *array_of_statuses, MPI_Fint *ierr) { 
    MPI_Waitall_fortran_wrapper(count, array_of_requests, array_of_statuses, ierr);
}

_EXTERN_C_ void mpi_waitall__(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *array_of_statuses, MPI_Fint *ierr) { 
    MPI_Waitall_fortran_wrapper(count, array_of_requests, array_of_statuses, ierr);
}

/* ================= End Wrappers for MPI_Waitall ================= */


/* ================== C Wrappers for MPI_Start ================== */
_EXTERN_C_ int PMPI_Start(MPI_Request *request);
_EXTERN_C_ int MPI_Start(MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Start(request);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Start");
    _wrap_py_return_val = PMPI_Start(request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Start =============== */
static void MPI_Start_fortran_wrapper(MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Start((MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Start(&temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_START(MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Start_fortran_wrapper(request, ierr);
}

_EXTERN_C_ void mpi_start(MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Start_fortran_wrapper(request, ierr);
}

_EXTERN_C_ void mpi_start_(MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Start_fortran_wrapper(request, ierr);
}

_EXTERN_C_ void mpi_start__(MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Start_fortran_wrapper(request, ierr);
}

/* ================= End Wrappers for MPI_Start ================= */


/* ================== C Wrappers for MPI_Startall ================== */
_EXTERN_C_ int PMPI_Startall(int count, MPI_Request *array_of_requests);
_EXTERN_C_ int MPI_Startall(int count, MPI_Request *array_of_requests) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Startall(count, array_of_requests);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Startall");
    _wrap_py_return_val = PMPI_Startall(count, array_of_requests);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Startall =============== */
static void MPI_Startall_fortran_wrapper(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Startall(*count, (MPI_Request*)array_of_requests);
#else /* MPI-2 safe call */
    MPI_Request* temp_array_of_requests;
    int i;
    temp_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request) * *count);
    for (i=0; i < *count; i++)
        temp_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
    _wrap_py_return_val = MPI_Startall(*count, temp_array_of_requests);
    for (i=0; i < *count; i++)
        array_of_requests[i] = MPI_Request_c2f(temp_array_of_requests[i]);
    free(temp_array_of_requests);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_STARTALL(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *ierr) { 
    MPI_Startall_fortran_wrapper(count, array_of_requests, ierr);
}

_EXTERN_C_ void mpi_startall(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *ierr) { 
    MPI_Startall_fortran_wrapper(count, array_of_requests, ierr);
}

_EXTERN_C_ void mpi_startall_(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *ierr) { 
    MPI_Startall_fortran_wrapper(count, array_of_requests, ierr);
}

_EXTERN_C_ void mpi_startall__(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *ierr) { 
    MPI_Startall_fortran_wrapper(count, array_of_requests, ierr);
}

/* ================= End Wrappers for MPI_Startall ================= */


/* ================== C Wrappers for MPI_Cancel ================== */
_EXTERN_C_ int PMPI_Cancel(MPI_Request *request);
_EXTERN_C_ int MPI_Cancel(MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Cancel(request);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Cancel");
    _wrap_py_return_val = PMPI_Cancel(request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Cancel =============== */
static void MPI_Cancel_fortran_wrapper(MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Cancel((MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    temp_request = MPI_Request_f2c(*request);
    _wrap_py_return_val = MPI_Cancel(&temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_CANCEL(MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Cancel_fortran_wrapper(request, ierr);
}

_EXTERN_C_ void mpi_cancel(MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Cancel_fortran_wrapper(request, ierr);
}

_EXTERN_C_ void mpi_cancel_(MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Cancel_fortran_wrapper(request, ierr);
}

_EXTERN_C_ void mpi_cancel__(MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_Cancel_fortran_wrapper(request, ierr);
}

/* ================= End Wrappers for MPI_Cancel ================= */


/* ================== C Wrappers for MPI_Cart_create ================== */
_EXTERN_C_ int PMPI_Cart_create(MPI_Comm old_comm, int ndims, int *dims, int *periods, int reorder, MPI_Comm *comm_cart);
_EXTERN_C_ int MPI_Cart_create(MPI_Comm old_comm, int ndims, int *dims, int *periods, int reorder, MPI_Comm *comm_cart) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Cart_create(old_comm, ndims, dims, periods, reorder, comm_cart);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Cart_create");
    _wrap_py_return_val = PMPI_Cart_create(old_comm, ndims, dims, periods, reorder, comm_cart);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Cart_create =============== */
static void MPI_Cart_create_fortran_wrapper(MPI_Fint *old_comm, MPI_Fint *ndims, MPI_Fint *dims, MPI_Fint *periods, MPI_Fint *reorder, MPI_Fint *comm_cart, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Cart_create((MPI_Comm)(*old_comm), *ndims, BufferF2C((int*)dims), BufferF2C((int*)periods), *reorder, (MPI_Comm*)comm_cart);
#else /* MPI-2 safe call */
    MPI_Comm temp_comm_cart;
    _wrap_py_return_val = MPI_Cart_create(MPI_Comm_f2c(*old_comm), *ndims, BufferF2C((int*)dims), BufferF2C((int*)periods), *reorder, &temp_comm_cart);
    *comm_cart = MPI_Comm_c2f(temp_comm_cart);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_CART_CREATE(MPI_Fint *old_comm, MPI_Fint *ndims, MPI_Fint *dims, MPI_Fint *periods, MPI_Fint *reorder, MPI_Fint *comm_cart, MPI_Fint *ierr) { 
    MPI_Cart_create_fortran_wrapper(old_comm, ndims, dims, periods, reorder, comm_cart, ierr);
}

_EXTERN_C_ void mpi_cart_create(MPI_Fint *old_comm, MPI_Fint *ndims, MPI_Fint *dims, MPI_Fint *periods, MPI_Fint *reorder, MPI_Fint *comm_cart, MPI_Fint *ierr) { 
    MPI_Cart_create_fortran_wrapper(old_comm, ndims, dims, periods, reorder, comm_cart, ierr);
}

_EXTERN_C_ void mpi_cart_create_(MPI_Fint *old_comm, MPI_Fint *ndims, MPI_Fint *dims, MPI_Fint *periods, MPI_Fint *reorder, MPI_Fint *comm_cart, MPI_Fint *ierr) { 
    MPI_Cart_create_fortran_wrapper(old_comm, ndims, dims, periods, reorder, comm_cart, ierr);
}

_EXTERN_C_ void mpi_cart_create__(MPI_Fint *old_comm, MPI_Fint *ndims, MPI_Fint *dims, MPI_Fint *periods, MPI_Fint *reorder, MPI_Fint *comm_cart, MPI_Fint *ierr) { 
    MPI_Cart_create_fortran_wrapper(old_comm, ndims, dims, periods, reorder, comm_cart, ierr);
}

/* ================= End Wrappers for MPI_Cart_create ================= */


/* ================== C Wrappers for MPI_Cart_sub ================== */
_EXTERN_C_ int PMPI_Cart_sub(MPI_Comm comm, int *remain_dims, MPI_Comm *new_comm);
_EXTERN_C_ int MPI_Cart_sub(MPI_Comm comm, int *remain_dims, MPI_Comm *new_comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Cart_sub(comm, remain_dims, new_comm);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Cart_sub");
    _wrap_py_return_val = PMPI_Cart_sub(comm, remain_dims, new_comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Cart_sub =============== */
static void MPI_Cart_sub_fortran_wrapper(MPI_Fint *comm, MPI_Fint *remain_dims, MPI_Fint *new_comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Cart_sub((MPI_Comm)(*comm), BufferF2C((int*)remain_dims), (MPI_Comm*)new_comm);
#else /* MPI-2 safe call */
    MPI_Comm temp_new_comm;
    _wrap_py_return_val = MPI_Cart_sub(MPI_Comm_f2c(*comm), BufferF2C((int*)remain_dims), &temp_new_comm);
    *new_comm = MPI_Comm_c2f(temp_new_comm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_CART_SUB(MPI_Fint *comm, MPI_Fint *remain_dims, MPI_Fint *new_comm, MPI_Fint *ierr) { 
    MPI_Cart_sub_fortran_wrapper(comm, remain_dims, new_comm, ierr);
}

_EXTERN_C_ void mpi_cart_sub(MPI_Fint *comm, MPI_Fint *remain_dims, MPI_Fint *new_comm, MPI_Fint *ierr) { 
    MPI_Cart_sub_fortran_wrapper(comm, remain_dims, new_comm, ierr);
}

_EXTERN_C_ void mpi_cart_sub_(MPI_Fint *comm, MPI_Fint *remain_dims, MPI_Fint *new_comm, MPI_Fint *ierr) { 
    MPI_Cart_sub_fortran_wrapper(comm, remain_dims, new_comm, ierr);
}

_EXTERN_C_ void mpi_cart_sub__(MPI_Fint *comm, MPI_Fint *remain_dims, MPI_Fint *new_comm, MPI_Fint *ierr) { 
    MPI_Cart_sub_fortran_wrapper(comm, remain_dims, new_comm, ierr);
}

/* ================= End Wrappers for MPI_Cart_sub ================= */


/* ================== C Wrappers for MPI_Comm_create ================== */
_EXTERN_C_ int PMPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Comm_create(comm, group, newcomm);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Comm_create");
    _wrap_py_return_val = PMPI_Comm_create(comm, group, newcomm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Comm_create =============== */
static void MPI_Comm_create_fortran_wrapper(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_create((MPI_Comm)(*comm), (MPI_Group)(*group), (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    _wrap_py_return_val = MPI_Comm_create(MPI_Comm_f2c(*comm), MPI_Group_f2c(*group), &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_CREATE(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_fortran_wrapper(comm, group, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_create(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_fortran_wrapper(comm, group, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_create_(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_fortran_wrapper(comm, group, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_create__(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_create_fortran_wrapper(comm, group, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_create ================= */


/* ================== C Wrappers for MPI_Comm_dup ================== */
_EXTERN_C_ int PMPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Comm_dup(comm, newcomm);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Comm_dup");
    _wrap_py_return_val = PMPI_Comm_dup(comm, newcomm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Comm_dup =============== */
static void MPI_Comm_dup_fortran_wrapper(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_dup((MPI_Comm)(*comm), (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    _wrap_py_return_val = MPI_Comm_dup(MPI_Comm_f2c(*comm), &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_DUP(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_fortran_wrapper(comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_dup(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_fortran_wrapper(comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_dup_(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_fortran_wrapper(comm, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_dup__(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_dup_fortran_wrapper(comm, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_dup ================= */


/* ================== C Wrappers for MPI_Comm_accept ================== */
_EXTERN_C_ int PMPI_Comm_accept(char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_accept(char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Comm_accept(port_name, info, root, comm, newcomm);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Comm_accept");
    _wrap_py_return_val = PMPI_Comm_accept(port_name, info, root, comm, newcomm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Comm_accept =============== */
static void MPI_Comm_accept_fortran_wrapper(char *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr, int port_name_length) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_accept(temp_port_name, (MPI_Info)(*info), *root, (MPI_Comm)(*comm), (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    char* temp_port_name;
    temp_port_name = wrapper_fortran_to_c_string(port_name, port_name_length);
    if (!temp_port_name)
    {
        fprintf(stderr, "Error in Allinea MPI Fortran wrapper for MPI_Comm_accept - unable to allocate (at most) %i+1 bytes for copy of the port_name argument string\n", port_name_length);
        abort();
    }
    _wrap_py_return_val = MPI_Comm_accept(temp_port_name, MPI_Info_f2c(*info), *root, MPI_Comm_f2c(*comm), &temp_newcomm);
    free(temp_port_name);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_ACCEPT(char *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr, int port_name_length) { 
    MPI_Comm_accept_fortran_wrapper(port_name, info, root, comm, newcomm, ierr, port_name_length);
}

_EXTERN_C_ void mpi_comm_accept(char *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr, int port_name_length) { 
    MPI_Comm_accept_fortran_wrapper(port_name, info, root, comm, newcomm, ierr, port_name_length);
}

_EXTERN_C_ void mpi_comm_accept_(char *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr, int port_name_length) { 
    MPI_Comm_accept_fortran_wrapper(port_name, info, root, comm, newcomm, ierr, port_name_length);
}

_EXTERN_C_ void mpi_comm_accept__(char *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr, int port_name_length) { 
    MPI_Comm_accept_fortran_wrapper(port_name, info, root, comm, newcomm, ierr, port_name_length);
}

/* ================= End Wrappers for MPI_Comm_accept ================= */


/* ================== C Wrappers for MPI_Comm_connect ================== */
_EXTERN_C_ int PMPI_Comm_connect(char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_connect(char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Comm_connect(port_name, info, root, comm, newcomm);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Comm_connect");
    _wrap_py_return_val = PMPI_Comm_connect(port_name, info, root, comm, newcomm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Comm_connect =============== */
static void MPI_Comm_connect_fortran_wrapper(char *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr, int port_name_length) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_connect(temp_port_name, (MPI_Info)(*info), *root, (MPI_Comm)(*comm), (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    char* temp_port_name;
    temp_port_name = wrapper_fortran_to_c_string(port_name, port_name_length);
    if (!temp_port_name)
    {
        fprintf(stderr, "Error in Allinea MPI Fortran wrapper for MPI_Comm_connect - unable to allocate (at most) %i+1 bytes for copy of the port_name argument string\n", port_name_length);
        abort();
    }
    _wrap_py_return_val = MPI_Comm_connect(temp_port_name, MPI_Info_f2c(*info), *root, MPI_Comm_f2c(*comm), &temp_newcomm);
    free(temp_port_name);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_CONNECT(char *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr, int port_name_length) { 
    MPI_Comm_connect_fortran_wrapper(port_name, info, root, comm, newcomm, ierr, port_name_length);
}

_EXTERN_C_ void mpi_comm_connect(char *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr, int port_name_length) { 
    MPI_Comm_connect_fortran_wrapper(port_name, info, root, comm, newcomm, ierr, port_name_length);
}

_EXTERN_C_ void mpi_comm_connect_(char *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr, int port_name_length) { 
    MPI_Comm_connect_fortran_wrapper(port_name, info, root, comm, newcomm, ierr, port_name_length);
}

_EXTERN_C_ void mpi_comm_connect__(char *port_name, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr, int port_name_length) { 
    MPI_Comm_connect_fortran_wrapper(port_name, info, root, comm, newcomm, ierr, port_name_length);
}

/* ================= End Wrappers for MPI_Comm_connect ================= */


/* ================== C Wrappers for MPI_Comm_disconnect ================== */
_EXTERN_C_ int PMPI_Comm_disconnect(MPI_Comm *comm);
_EXTERN_C_ int MPI_Comm_disconnect(MPI_Comm *comm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Comm_disconnect(comm);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Comm_disconnect");
    _wrap_py_return_val = PMPI_Comm_disconnect(comm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Comm_disconnect =============== */
static void MPI_Comm_disconnect_fortran_wrapper(MPI_Fint *comm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_disconnect((MPI_Comm*)comm);
#else /* MPI-2 safe call */
    MPI_Comm temp_comm;
    temp_comm = MPI_Comm_f2c(*comm);
    _wrap_py_return_val = MPI_Comm_disconnect(&temp_comm);
    *comm = MPI_Comm_c2f(temp_comm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_DISCONNECT(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Comm_disconnect_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_comm_disconnect(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Comm_disconnect_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_comm_disconnect_(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Comm_disconnect_fortran_wrapper(comm, ierr);
}

_EXTERN_C_ void mpi_comm_disconnect__(MPI_Fint *comm, MPI_Fint *ierr) { 
    MPI_Comm_disconnect_fortran_wrapper(comm, ierr);
}

/* ================= End Wrappers for MPI_Comm_disconnect ================= */


/* ================== C Wrappers for MPI_Comm_join ================== */
_EXTERN_C_ int PMPI_Comm_join(int fd, MPI_Comm *intercomm);
_EXTERN_C_ int MPI_Comm_join(int fd, MPI_Comm *intercomm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Comm_join(fd, intercomm);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Comm_join");
    _wrap_py_return_val = PMPI_Comm_join(fd, intercomm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Comm_join =============== */
static void MPI_Comm_join_fortran_wrapper(MPI_Fint *fd, MPI_Fint *intercomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_join(*fd, (MPI_Comm*)intercomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_intercomm;
    _wrap_py_return_val = MPI_Comm_join(*fd, &temp_intercomm);
    *intercomm = MPI_Comm_c2f(temp_intercomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_JOIN(MPI_Fint *fd, MPI_Fint *intercomm, MPI_Fint *ierr) { 
    MPI_Comm_join_fortran_wrapper(fd, intercomm, ierr);
}

_EXTERN_C_ void mpi_comm_join(MPI_Fint *fd, MPI_Fint *intercomm, MPI_Fint *ierr) { 
    MPI_Comm_join_fortran_wrapper(fd, intercomm, ierr);
}

_EXTERN_C_ void mpi_comm_join_(MPI_Fint *fd, MPI_Fint *intercomm, MPI_Fint *ierr) { 
    MPI_Comm_join_fortran_wrapper(fd, intercomm, ierr);
}

_EXTERN_C_ void mpi_comm_join__(MPI_Fint *fd, MPI_Fint *intercomm, MPI_Fint *ierr) { 
    MPI_Comm_join_fortran_wrapper(fd, intercomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_join ================= */


/* ================== C Wrappers for MPI_Comm_spawn ================== */
_EXTERN_C_ int PMPI_Comm_spawn(char *command, char **argv, int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int *array_of_errcodes);
_EXTERN_C_ int MPI_Comm_spawn(char *command, char **argv, int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int *array_of_errcodes) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Comm_spawn");
    _wrap_py_return_val = PMPI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Comm_spawn =============== */
/* ================= End Wrappers for MPI_Comm_spawn ================= */


/* ================== C Wrappers for MPI_Comm_spawn_multiple ================== */
_EXTERN_C_ int PMPI_Comm_spawn_multiple(int count, char **array_of_commands, char ***array_of_argv, int *array_of_maxprocs, MPI_Info *array_of_info, int root, MPI_Comm comm, MPI_Comm *intercomm, int *array_of_errcodes);
_EXTERN_C_ int MPI_Comm_spawn_multiple(int count, char **array_of_commands, char ***array_of_argv, int *array_of_maxprocs, MPI_Info *array_of_info, int root, MPI_Comm comm, MPI_Comm *intercomm, int *array_of_errcodes) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Comm_spawn_multiple");
    _wrap_py_return_val = PMPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Comm_spawn_multiple =============== */
/* ================= End Wrappers for MPI_Comm_spawn_multiple ================= */


/* ================== C Wrappers for MPI_Comm_remote_group ================== */
_EXTERN_C_ int PMPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group);
_EXTERN_C_ int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Comm_remote_group(comm, group);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Comm_remote_group");
    _wrap_py_return_val = PMPI_Comm_remote_group(comm, group);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Comm_remote_group =============== */
static void MPI_Comm_remote_group_fortran_wrapper(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_remote_group((MPI_Comm)(*comm), (MPI_Group*)group);
#else /* MPI-2 safe call */
    MPI_Group temp_group;
    _wrap_py_return_val = MPI_Comm_remote_group(MPI_Comm_f2c(*comm), &temp_group);
    *group = MPI_Group_c2f(temp_group);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_REMOTE_GROUP(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_remote_group_fortran_wrapper(comm, group, ierr);
}

_EXTERN_C_ void mpi_comm_remote_group(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_remote_group_fortran_wrapper(comm, group, ierr);
}

_EXTERN_C_ void mpi_comm_remote_group_(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_remote_group_fortran_wrapper(comm, group, ierr);
}

_EXTERN_C_ void mpi_comm_remote_group__(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_Comm_remote_group_fortran_wrapper(comm, group, ierr);
}

/* ================= End Wrappers for MPI_Comm_remote_group ================= */


/* ================== C Wrappers for MPI_Comm_remote_size ================== */
_EXTERN_C_ int PMPI_Comm_remote_size(MPI_Comm comm, int *size);
_EXTERN_C_ int MPI_Comm_remote_size(MPI_Comm comm, int *size) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Comm_remote_size(comm, size);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Comm_remote_size");
    _wrap_py_return_val = PMPI_Comm_remote_size(comm, size);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Comm_remote_size =============== */
static void MPI_Comm_remote_size_fortran_wrapper(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_remote_size((MPI_Comm)(*comm), BufferF2C((int*)size));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_Comm_remote_size(MPI_Comm_f2c(*comm), BufferF2C((int*)size));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_REMOTE_SIZE(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_remote_size_fortran_wrapper(comm, size, ierr);
}

_EXTERN_C_ void mpi_comm_remote_size(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_remote_size_fortran_wrapper(comm, size, ierr);
}

_EXTERN_C_ void mpi_comm_remote_size_(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_remote_size_fortran_wrapper(comm, size, ierr);
}

_EXTERN_C_ void mpi_comm_remote_size__(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) { 
    MPI_Comm_remote_size_fortran_wrapper(comm, size, ierr);
}

/* ================= End Wrappers for MPI_Comm_remote_size ================= */


/* ================== C Wrappers for MPI_Comm_split ================== */
_EXTERN_C_ int PMPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm);
_EXTERN_C_ int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Comm_split(comm, color, key, newcomm);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Comm_split");
    _wrap_py_return_val = PMPI_Comm_split(comm, color, key, newcomm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Comm_split =============== */
static void MPI_Comm_split_fortran_wrapper(MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Comm_split((MPI_Comm)(*comm), *color, *key, (MPI_Comm*)newcomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newcomm;
    _wrap_py_return_val = MPI_Comm_split(MPI_Comm_f2c(*comm), *color, *key, &temp_newcomm);
    *newcomm = MPI_Comm_c2f(temp_newcomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_COMM_SPLIT(MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_fortran_wrapper(comm, color, key, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_split(MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_fortran_wrapper(comm, color, key, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_split_(MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_fortran_wrapper(comm, color, key, newcomm, ierr);
}

_EXTERN_C_ void mpi_comm_split__(MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key, MPI_Fint *newcomm, MPI_Fint *ierr) { 
    MPI_Comm_split_fortran_wrapper(comm, color, key, newcomm, ierr);
}

/* ================= End Wrappers for MPI_Comm_split ================= */


/* ================== C Wrappers for MPI_Intercomm_create ================== */
_EXTERN_C_ int PMPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm bridge_comm, int remote_leader, int tag, MPI_Comm *newintercomm);
_EXTERN_C_ int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm bridge_comm, int remote_leader, int tag, MPI_Comm *newintercomm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Intercomm_create(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Intercomm_create");
    _wrap_py_return_val = PMPI_Intercomm_create(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Intercomm_create =============== */
static void MPI_Intercomm_create_fortran_wrapper(MPI_Fint *local_comm, MPI_Fint *local_leader, MPI_Fint *bridge_comm, MPI_Fint *remote_leader, MPI_Fint *tag, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Intercomm_create((MPI_Comm)(*local_comm), *local_leader, (MPI_Comm)(*bridge_comm), *remote_leader, *tag, (MPI_Comm*)newintercomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newintercomm;
    _wrap_py_return_val = MPI_Intercomm_create(MPI_Comm_f2c(*local_comm), *local_leader, MPI_Comm_f2c(*bridge_comm), *remote_leader, *tag, &temp_newintercomm);
    *newintercomm = MPI_Comm_c2f(temp_newintercomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INTERCOMM_CREATE(MPI_Fint *local_comm, MPI_Fint *local_leader, MPI_Fint *bridge_comm, MPI_Fint *remote_leader, MPI_Fint *tag, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_create_fortran_wrapper(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_create(MPI_Fint *local_comm, MPI_Fint *local_leader, MPI_Fint *bridge_comm, MPI_Fint *remote_leader, MPI_Fint *tag, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_create_fortran_wrapper(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_create_(MPI_Fint *local_comm, MPI_Fint *local_leader, MPI_Fint *bridge_comm, MPI_Fint *remote_leader, MPI_Fint *tag, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_create_fortran_wrapper(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_create__(MPI_Fint *local_comm, MPI_Fint *local_leader, MPI_Fint *bridge_comm, MPI_Fint *remote_leader, MPI_Fint *tag, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_create_fortran_wrapper(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm, ierr);
}

/* ================= End Wrappers for MPI_Intercomm_create ================= */


/* ================== C Wrappers for MPI_Intercomm_merge ================== */
_EXTERN_C_ int PMPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintercomm);
_EXTERN_C_ int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintercomm) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Intercomm_merge(intercomm, high, newintercomm);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_Intercomm_merge");
    _wrap_py_return_val = PMPI_Intercomm_merge(intercomm, high, newintercomm);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Intercomm_merge =============== */
static void MPI_Intercomm_merge_fortran_wrapper(MPI_Fint *intercomm, MPI_Fint *high, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_Intercomm_merge((MPI_Comm)(*intercomm), *high, (MPI_Comm*)newintercomm);
#else /* MPI-2 safe call */
    MPI_Comm temp_newintercomm;
    _wrap_py_return_val = MPI_Intercomm_merge(MPI_Comm_f2c(*intercomm), *high, &temp_newintercomm);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_INTERCOMM_MERGE(MPI_Fint *intercomm, MPI_Fint *high, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_merge_fortran_wrapper(intercomm, high, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_merge(MPI_Fint *intercomm, MPI_Fint *high, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_merge_fortran_wrapper(intercomm, high, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_merge_(MPI_Fint *intercomm, MPI_Fint *high, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_merge_fortran_wrapper(intercomm, high, newintercomm, ierr);
}

_EXTERN_C_ void mpi_intercomm_merge__(MPI_Fint *intercomm, MPI_Fint *high, MPI_Fint *newintercomm, MPI_Fint *ierr) { 
    MPI_Intercomm_merge_fortran_wrapper(intercomm, high, newintercomm, ierr);
}

/* ================= End Wrappers for MPI_Intercomm_merge ================= */




/* ================== C Wrappers for MPI_Finalize ================== */
_EXTERN_C_ int PMPI_Finalize();
_EXTERN_C_ int MPI_Finalize() { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_Finalize();
    in_wrapper = 1;

    int _ret = 0;
    allinea_mapSamplerEnter("MPI_Finalize", 0, 0, MPI_TYPE_COLLECTIVE); /* #33608 */

    allinea_mapNoBarrierCount = 1;
    _ret = MPI_Barrier(MPI_COMM_WORLD);
    allinea_mapNoBarrierCount = 0;

    allinea_mapSamplerExit(_ret);
    allinea_set_stop_reason(MAP_STOP_REASON_MPI_FINALIZE);
    allinea_stop_sampling();
    _wrap_py_return_val = PMPI_Finalize();
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_Finalize =============== */
static void MPI_Finalize_fortran_wrapper(MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
    _wrap_py_return_val = MPI_Finalize();
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FINALIZE(MPI_Fint *ierr) { 
    MPI_Finalize_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_finalize(MPI_Fint *ierr) { 
    MPI_Finalize_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_finalize_(MPI_Fint *ierr) { 
    MPI_Finalize_fortran_wrapper(ierr);
}

_EXTERN_C_ void mpi_finalize__(MPI_Fint *ierr) { 
    MPI_Finalize_fortran_wrapper(ierr);
}

/* ================= End Wrappers for MPI_Finalize ================= */




/* ================== C Wrappers for MPI_File_close ================== */
_EXTERN_C_ int PMPI_File_close(MPI_File *fh);
_EXTERN_C_ int MPI_File_close(MPI_File *fh) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_close(fh);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_close");
    _wrap_py_return_val = PMPI_File_close(fh);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_close =============== */
static void MPI_File_close_fortran_wrapper(MPI_Fint *fh, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_close((MPI_File*)fh);
#else /* MPI-2 safe call */
    MPI_File temp_fh;
    temp_fh = MPI_File_f2c(*fh);
    _wrap_py_return_val = MPI_File_close(&temp_fh);
    *fh = MPI_File_c2f(temp_fh);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_CLOSE(MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_close_fortran_wrapper(fh, ierr);
}

_EXTERN_C_ void mpi_file_close(MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_close_fortran_wrapper(fh, ierr);
}

_EXTERN_C_ void mpi_file_close_(MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_close_fortran_wrapper(fh, ierr);
}

_EXTERN_C_ void mpi_file_close__(MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_close_fortran_wrapper(fh, ierr);
}

/* ================= End Wrappers for MPI_File_close ================= */


/* ================== C Wrappers for MPI_File_delete ================== */
_EXTERN_C_ int PMPI_File_delete(char *filename, MPI_Info info);
_EXTERN_C_ int MPI_File_delete(char *filename, MPI_Info info) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_delete(filename, info);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_delete");
    _wrap_py_return_val = PMPI_File_delete(filename, info);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_delete =============== */
static void MPI_File_delete_fortran_wrapper(char *filename, MPI_Fint *info, MPI_Fint *ierr, int filename_length) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_delete(temp_filename, (MPI_Info)(*info));
#else /* MPI-2 safe call */
    char* temp_filename;
    temp_filename = wrapper_fortran_to_c_string(filename, filename_length);
    if (!temp_filename)
    {
        fprintf(stderr, "Error in Allinea MPI Fortran wrapper for MPI_File_delete - unable to allocate (at most) %i+1 bytes for copy of the filename argument string\n", filename_length);
        abort();
    }
    _wrap_py_return_val = MPI_File_delete(temp_filename, MPI_Info_f2c(*info));
    free(temp_filename);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_DELETE(char *filename, MPI_Fint *info, MPI_Fint *ierr, int filename_length) { 
    MPI_File_delete_fortran_wrapper(filename, info, ierr, filename_length);
}

_EXTERN_C_ void mpi_file_delete(char *filename, MPI_Fint *info, MPI_Fint *ierr, int filename_length) { 
    MPI_File_delete_fortran_wrapper(filename, info, ierr, filename_length);
}

_EXTERN_C_ void mpi_file_delete_(char *filename, MPI_Fint *info, MPI_Fint *ierr, int filename_length) { 
    MPI_File_delete_fortran_wrapper(filename, info, ierr, filename_length);
}

_EXTERN_C_ void mpi_file_delete__(char *filename, MPI_Fint *info, MPI_Fint *ierr, int filename_length) { 
    MPI_File_delete_fortran_wrapper(filename, info, ierr, filename_length);
}

/* ================= End Wrappers for MPI_File_delete ================= */


/* ================== C Wrappers for MPI_File_get_amode ================== */
_EXTERN_C_ int PMPI_File_get_amode(MPI_File fh, int *amode);
_EXTERN_C_ int MPI_File_get_amode(MPI_File fh, int *amode) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_get_amode(fh, amode);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_get_amode");
    _wrap_py_return_val = PMPI_File_get_amode(fh, amode);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_get_amode =============== */
static void MPI_File_get_amode_fortran_wrapper(MPI_Fint *fh, MPI_Fint *amode, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_get_amode((MPI_File)(*fh), BufferF2C((int*)amode));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_get_amode(MPI_File_f2c(*fh), BufferF2C((int*)amode));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_GET_AMODE(MPI_Fint *fh, MPI_Fint *amode, MPI_Fint *ierr) { 
    MPI_File_get_amode_fortran_wrapper(fh, amode, ierr);
}

_EXTERN_C_ void mpi_file_get_amode(MPI_Fint *fh, MPI_Fint *amode, MPI_Fint *ierr) { 
    MPI_File_get_amode_fortran_wrapper(fh, amode, ierr);
}

_EXTERN_C_ void mpi_file_get_amode_(MPI_Fint *fh, MPI_Fint *amode, MPI_Fint *ierr) { 
    MPI_File_get_amode_fortran_wrapper(fh, amode, ierr);
}

_EXTERN_C_ void mpi_file_get_amode__(MPI_Fint *fh, MPI_Fint *amode, MPI_Fint *ierr) { 
    MPI_File_get_amode_fortran_wrapper(fh, amode, ierr);
}

/* ================= End Wrappers for MPI_File_get_amode ================= */


/* ================== C Wrappers for MPI_File_get_atomicity ================== */
_EXTERN_C_ int PMPI_File_get_atomicity(MPI_File fh, int *flag);
_EXTERN_C_ int MPI_File_get_atomicity(MPI_File fh, int *flag) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_get_atomicity(fh, flag);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_get_atomicity");
    _wrap_py_return_val = PMPI_File_get_atomicity(fh, flag);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_get_atomicity =============== */
static void MPI_File_get_atomicity_fortran_wrapper(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_get_atomicity((MPI_File)(*fh), BufferF2C((int*)flag));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_get_atomicity(MPI_File_f2c(*fh), BufferF2C((int*)flag));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_GET_ATOMICITY(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_File_get_atomicity_fortran_wrapper(fh, flag, ierr);
}

_EXTERN_C_ void mpi_file_get_atomicity(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_File_get_atomicity_fortran_wrapper(fh, flag, ierr);
}

_EXTERN_C_ void mpi_file_get_atomicity_(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_File_get_atomicity_fortran_wrapper(fh, flag, ierr);
}

_EXTERN_C_ void mpi_file_get_atomicity__(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_File_get_atomicity_fortran_wrapper(fh, flag, ierr);
}

/* ================= End Wrappers for MPI_File_get_atomicity ================= */


/* ================== C Wrappers for MPI_File_get_byte_offset ================== */
_EXTERN_C_ int PMPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp);
_EXTERN_C_ int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_get_byte_offset(fh, offset, disp);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_get_byte_offset");
    _wrap_py_return_val = PMPI_File_get_byte_offset(fh, offset, disp);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_get_byte_offset =============== */
static void MPI_File_get_byte_offset_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Offset *disp, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_get_byte_offset((MPI_File)(*fh), *offset, BufferF2C((MPI_Offset*)disp));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_get_byte_offset(MPI_File_f2c(*fh), *offset, BufferF2C((MPI_Offset*)disp));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_GET_BYTE_OFFSET(MPI_Fint *fh, MPI_Offset *offset, MPI_Offset *disp, MPI_Fint *ierr) { 
    MPI_File_get_byte_offset_fortran_wrapper(fh, offset, disp, ierr);
}

_EXTERN_C_ void mpi_file_get_byte_offset(MPI_Fint *fh, MPI_Offset *offset, MPI_Offset *disp, MPI_Fint *ierr) { 
    MPI_File_get_byte_offset_fortran_wrapper(fh, offset, disp, ierr);
}

_EXTERN_C_ void mpi_file_get_byte_offset_(MPI_Fint *fh, MPI_Offset *offset, MPI_Offset *disp, MPI_Fint *ierr) { 
    MPI_File_get_byte_offset_fortran_wrapper(fh, offset, disp, ierr);
}

_EXTERN_C_ void mpi_file_get_byte_offset__(MPI_Fint *fh, MPI_Offset *offset, MPI_Offset *disp, MPI_Fint *ierr) { 
    MPI_File_get_byte_offset_fortran_wrapper(fh, offset, disp, ierr);
}

/* ================= End Wrappers for MPI_File_get_byte_offset ================= */


/* ================== C Wrappers for MPI_File_get_group ================== */
_EXTERN_C_ int PMPI_File_get_group(MPI_File fh, MPI_Group *group);
_EXTERN_C_ int MPI_File_get_group(MPI_File fh, MPI_Group *group) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_get_group(fh, group);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_get_group");
    _wrap_py_return_val = PMPI_File_get_group(fh, group);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_get_group =============== */
static void MPI_File_get_group_fortran_wrapper(MPI_Fint *fh, MPI_Fint *group, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_get_group((MPI_File)(*fh), (MPI_Group*)group);
#else /* MPI-2 safe call */
    MPI_Group temp_group;
    _wrap_py_return_val = MPI_File_get_group(MPI_File_f2c(*fh), &temp_group);
    *group = MPI_Group_c2f(temp_group);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_GET_GROUP(MPI_Fint *fh, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_File_get_group_fortran_wrapper(fh, group, ierr);
}

_EXTERN_C_ void mpi_file_get_group(MPI_Fint *fh, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_File_get_group_fortran_wrapper(fh, group, ierr);
}

_EXTERN_C_ void mpi_file_get_group_(MPI_Fint *fh, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_File_get_group_fortran_wrapper(fh, group, ierr);
}

_EXTERN_C_ void mpi_file_get_group__(MPI_Fint *fh, MPI_Fint *group, MPI_Fint *ierr) { 
    MPI_File_get_group_fortran_wrapper(fh, group, ierr);
}

/* ================= End Wrappers for MPI_File_get_group ================= */


/* ================== C Wrappers for MPI_File_get_info ================== */
_EXTERN_C_ int PMPI_File_get_info(MPI_File fh, MPI_Info *info_used);
_EXTERN_C_ int MPI_File_get_info(MPI_File fh, MPI_Info *info_used) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_get_info(fh, info_used);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_get_info");
    _wrap_py_return_val = PMPI_File_get_info(fh, info_used);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_get_info =============== */
static void MPI_File_get_info_fortran_wrapper(MPI_Fint *fh, MPI_Fint *info_used, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_get_info((MPI_File)(*fh), (MPI_Info*)info_used);
#else /* MPI-2 safe call */
    MPI_Info temp_info_used;
    _wrap_py_return_val = MPI_File_get_info(MPI_File_f2c(*fh), &temp_info_used);
    *info_used = MPI_Info_c2f(temp_info_used);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_GET_INFO(MPI_Fint *fh, MPI_Fint *info_used, MPI_Fint *ierr) { 
    MPI_File_get_info_fortran_wrapper(fh, info_used, ierr);
}

_EXTERN_C_ void mpi_file_get_info(MPI_Fint *fh, MPI_Fint *info_used, MPI_Fint *ierr) { 
    MPI_File_get_info_fortran_wrapper(fh, info_used, ierr);
}

_EXTERN_C_ void mpi_file_get_info_(MPI_Fint *fh, MPI_Fint *info_used, MPI_Fint *ierr) { 
    MPI_File_get_info_fortran_wrapper(fh, info_used, ierr);
}

_EXTERN_C_ void mpi_file_get_info__(MPI_Fint *fh, MPI_Fint *info_used, MPI_Fint *ierr) { 
    MPI_File_get_info_fortran_wrapper(fh, info_used, ierr);
}

/* ================= End Wrappers for MPI_File_get_info ================= */


/* ================== C Wrappers for MPI_File_get_position ================== */
_EXTERN_C_ int PMPI_File_get_position(MPI_File fh, MPI_Offset *offset);
_EXTERN_C_ int MPI_File_get_position(MPI_File fh, MPI_Offset *offset) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_get_position(fh, offset);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_get_position");
    _wrap_py_return_val = PMPI_File_get_position(fh, offset);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_get_position =============== */
static void MPI_File_get_position_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_get_position((MPI_File)(*fh), BufferF2C((MPI_Offset*)offset));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_get_position(MPI_File_f2c(*fh), BufferF2C((MPI_Offset*)offset));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_GET_POSITION(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) { 
    MPI_File_get_position_fortran_wrapper(fh, offset, ierr);
}

_EXTERN_C_ void mpi_file_get_position(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) { 
    MPI_File_get_position_fortran_wrapper(fh, offset, ierr);
}

_EXTERN_C_ void mpi_file_get_position_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) { 
    MPI_File_get_position_fortran_wrapper(fh, offset, ierr);
}

_EXTERN_C_ void mpi_file_get_position__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) { 
    MPI_File_get_position_fortran_wrapper(fh, offset, ierr);
}

/* ================= End Wrappers for MPI_File_get_position ================= */


/* ================== C Wrappers for MPI_File_get_position_shared ================== */
_EXTERN_C_ int PMPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset);
_EXTERN_C_ int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_get_position_shared(fh, offset);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_get_position_shared");
    _wrap_py_return_val = PMPI_File_get_position_shared(fh, offset);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_get_position_shared =============== */
static void MPI_File_get_position_shared_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_get_position_shared((MPI_File)(*fh), BufferF2C((MPI_Offset*)offset));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_get_position_shared(MPI_File_f2c(*fh), BufferF2C((MPI_Offset*)offset));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_GET_POSITION_SHARED(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) { 
    MPI_File_get_position_shared_fortran_wrapper(fh, offset, ierr);
}

_EXTERN_C_ void mpi_file_get_position_shared(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) { 
    MPI_File_get_position_shared_fortran_wrapper(fh, offset, ierr);
}

_EXTERN_C_ void mpi_file_get_position_shared_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) { 
    MPI_File_get_position_shared_fortran_wrapper(fh, offset, ierr);
}

_EXTERN_C_ void mpi_file_get_position_shared__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) { 
    MPI_File_get_position_shared_fortran_wrapper(fh, offset, ierr);
}

/* ================= End Wrappers for MPI_File_get_position_shared ================= */


/* ================== C Wrappers for MPI_File_get_size ================== */
_EXTERN_C_ int PMPI_File_get_size(MPI_File fh, MPI_Offset *size);
_EXTERN_C_ int MPI_File_get_size(MPI_File fh, MPI_Offset *size) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_get_size(fh, size);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_get_size");
    _wrap_py_return_val = PMPI_File_get_size(fh, size);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_get_size =============== */
static void MPI_File_get_size_fortran_wrapper(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_get_size((MPI_File)(*fh), BufferF2C((MPI_Offset*)size));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_get_size(MPI_File_f2c(*fh), BufferF2C((MPI_Offset*)size));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_GET_SIZE(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_get_size_fortran_wrapper(fh, size, ierr);
}

_EXTERN_C_ void mpi_file_get_size(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_get_size_fortran_wrapper(fh, size, ierr);
}

_EXTERN_C_ void mpi_file_get_size_(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_get_size_fortran_wrapper(fh, size, ierr);
}

_EXTERN_C_ void mpi_file_get_size__(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_get_size_fortran_wrapper(fh, size, ierr);
}

/* ================= End Wrappers for MPI_File_get_size ================= */


/* ================== C Wrappers for MPI_File_get_type_extent ================== */
_EXTERN_C_ int PMPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent);
_EXTERN_C_ int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_get_type_extent(fh, datatype, extent);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_get_type_extent");
    _wrap_py_return_val = PMPI_File_get_type_extent(fh, datatype, extent);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_get_type_extent =============== */
static void MPI_File_get_type_extent_fortran_wrapper(MPI_Fint *fh, MPI_Fint *datatype, MPI_Aint *extent, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_get_type_extent((MPI_File)(*fh), (MPI_Datatype)(*datatype), BufferF2C((MPI_Aint*)extent));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_get_type_extent(MPI_File_f2c(*fh), MPI_Type_f2c(*datatype), BufferF2C((MPI_Aint*)extent));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_GET_TYPE_EXTENT(MPI_Fint *fh, MPI_Fint *datatype, MPI_Aint *extent, MPI_Fint *ierr) { 
    MPI_File_get_type_extent_fortran_wrapper(fh, datatype, extent, ierr);
}

_EXTERN_C_ void mpi_file_get_type_extent(MPI_Fint *fh, MPI_Fint *datatype, MPI_Aint *extent, MPI_Fint *ierr) { 
    MPI_File_get_type_extent_fortran_wrapper(fh, datatype, extent, ierr);
}

_EXTERN_C_ void mpi_file_get_type_extent_(MPI_Fint *fh, MPI_Fint *datatype, MPI_Aint *extent, MPI_Fint *ierr) { 
    MPI_File_get_type_extent_fortran_wrapper(fh, datatype, extent, ierr);
}

_EXTERN_C_ void mpi_file_get_type_extent__(MPI_Fint *fh, MPI_Fint *datatype, MPI_Aint *extent, MPI_Fint *ierr) { 
    MPI_File_get_type_extent_fortran_wrapper(fh, datatype, extent, ierr);
}

/* ================= End Wrappers for MPI_File_get_type_extent ================= */


/* ================== C Wrappers for MPI_File_get_view ================== */
_EXTERN_C_ int PMPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep);
_EXTERN_C_ int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_get_view(fh, disp, etype, filetype, datarep);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_get_view");
    _wrap_py_return_val = PMPI_File_get_view(fh, disp, etype, filetype, datarep);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_get_view =============== */
static void MPI_File_get_view_fortran_wrapper(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep, MPI_Fint *ierr, int datarep_length) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_get_view((MPI_File)(*fh), BufferF2C((MPI_Offset*)disp), (MPI_Datatype*)etype, (MPI_Datatype*)filetype, temp_datarep);
#else /* MPI-2 safe call */
    char* temp_datarep;
    int temp_datarep_length;
    MPI_Datatype temp_filetype;
    MPI_Datatype temp_etype;
    temp_datarep = wrapper_fortran_to_c_string(datarep, datarep_length);
    if (!temp_datarep)
    {
        fprintf(stderr, "Error in Allinea MPI Fortran wrapper for MPI_File_get_view - unable to allocate (at most) %i+1 bytes for copy of the datarep argument string\n", datarep_length);
        abort();
    }
    _wrap_py_return_val = MPI_File_get_view(MPI_File_f2c(*fh), BufferF2C((MPI_Offset*)disp), &temp_etype, &temp_filetype, temp_datarep);
    *etype = MPI_Type_c2f(temp_etype);
    *filetype = MPI_Type_c2f(temp_filetype);
    strncpy(datarep,temp_datarep,datarep_length);
    temp_datarep_length = strlen(temp_datarep);
    if (temp_datarep_length < datarep_length)
        memset(datarep+temp_datarep_length, ' ', datarep_length - temp_datarep_length);
    free(temp_datarep);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_GET_VIEW(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep, MPI_Fint *ierr, int datarep_length) { 
    MPI_File_get_view_fortran_wrapper(fh, disp, etype, filetype, datarep, ierr, datarep_length);
}

_EXTERN_C_ void mpi_file_get_view(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep, MPI_Fint *ierr, int datarep_length) { 
    MPI_File_get_view_fortran_wrapper(fh, disp, etype, filetype, datarep, ierr, datarep_length);
}

_EXTERN_C_ void mpi_file_get_view_(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep, MPI_Fint *ierr, int datarep_length) { 
    MPI_File_get_view_fortran_wrapper(fh, disp, etype, filetype, datarep, ierr, datarep_length);
}

_EXTERN_C_ void mpi_file_get_view__(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep, MPI_Fint *ierr, int datarep_length) { 
    MPI_File_get_view_fortran_wrapper(fh, disp, etype, filetype, datarep, ierr, datarep_length);
}

/* ================= End Wrappers for MPI_File_get_view ================= */


/* ================== C Wrappers for MPI_File_iread ================== */
_EXTERN_C_ int PMPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request);
_EXTERN_C_ int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_iread(fh, buf, count, datatype, request);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_iread");
    _wrap_py_return_val = PMPI_File_iread(fh, buf, count, datatype, request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_iread =============== */
static void MPI_File_iread_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_iread((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    _wrap_py_return_val = MPI_File_iread(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_IREAD(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iread(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iread_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iread__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

/* ================= End Wrappers for MPI_File_iread ================= */


/* ================== C Wrappers for MPI_File_iread_at ================== */
_EXTERN_C_ int PMPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request);
_EXTERN_C_ int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_iread_at(fh, offset, buf, count, datatype, request);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_iread_at");
    _wrap_py_return_val = PMPI_File_iread_at(fh, offset, buf, count, datatype, request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_iread_at =============== */
static void MPI_File_iread_at_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_iread_at((MPI_File)(*fh), *offset, BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    _wrap_py_return_val = MPI_File_iread_at(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_IREAD_AT(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_at_fortran_wrapper(fh, offset, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iread_at(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_at_fortran_wrapper(fh, offset, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iread_at_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_at_fortran_wrapper(fh, offset, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iread_at__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_at_fortran_wrapper(fh, offset, buf, count, datatype, request, ierr);
}

/* ================= End Wrappers for MPI_File_iread_at ================= */


/* ================== C Wrappers for MPI_File_iread_shared ================== */
_EXTERN_C_ int PMPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request);
_EXTERN_C_ int MPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_iread_shared(fh, buf, count, datatype, request);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_iread_shared");
    _wrap_py_return_val = PMPI_File_iread_shared(fh, buf, count, datatype, request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_iread_shared =============== */
static void MPI_File_iread_shared_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_iread_shared((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    _wrap_py_return_val = MPI_File_iread_shared(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_IREAD_SHARED(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_shared_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iread_shared(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_shared_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iread_shared_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_shared_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iread_shared__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iread_shared_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

/* ================= End Wrappers for MPI_File_iread_shared ================= */


/* ================== C Wrappers for MPI_File_iwrite ================== */
_EXTERN_C_ int PMPI_File_iwrite(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request);
_EXTERN_C_ int MPI_File_iwrite(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_iwrite(fh, buf, count, datatype, request);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_iwrite");
    _wrap_py_return_val = PMPI_File_iwrite(fh, buf, count, datatype, request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_iwrite =============== */
static void MPI_File_iwrite_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_iwrite((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    _wrap_py_return_val = MPI_File_iwrite(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_IWRITE(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iwrite(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iwrite_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iwrite__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

/* ================= End Wrappers for MPI_File_iwrite ================= */


/* ================== C Wrappers for MPI_File_iwrite_at ================== */
_EXTERN_C_ int PMPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request);
_EXTERN_C_ int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_iwrite_at(fh, offset, buf, count, datatype, request);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_iwrite_at");
    _wrap_py_return_val = PMPI_File_iwrite_at(fh, offset, buf, count, datatype, request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_iwrite_at =============== */
static void MPI_File_iwrite_at_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_iwrite_at((MPI_File)(*fh), *offset, BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    _wrap_py_return_val = MPI_File_iwrite_at(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_IWRITE_AT(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_at_fortran_wrapper(fh, offset, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iwrite_at(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_at_fortran_wrapper(fh, offset, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iwrite_at_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_at_fortran_wrapper(fh, offset, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iwrite_at__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_at_fortran_wrapper(fh, offset, buf, count, datatype, request, ierr);
}

/* ================= End Wrappers for MPI_File_iwrite_at ================= */


/* ================== C Wrappers for MPI_File_iwrite_shared ================== */
_EXTERN_C_ int PMPI_File_iwrite_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request);
_EXTERN_C_ int MPI_File_iwrite_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_iwrite_shared(fh, buf, count, datatype, request);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_iwrite_shared");
    _wrap_py_return_val = PMPI_File_iwrite_shared(fh, buf, count, datatype, request);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_iwrite_shared =============== */
static void MPI_File_iwrite_shared_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_iwrite_shared((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Request*)request);
#else /* MPI-2 safe call */
    MPI_Request temp_request;
    _wrap_py_return_val = MPI_File_iwrite_shared(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_request);
    *request = MPI_Request_c2f(temp_request);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_IWRITE_SHARED(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_shared_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iwrite_shared(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_shared_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iwrite_shared_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_shared_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

_EXTERN_C_ void mpi_file_iwrite_shared__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) { 
    MPI_File_iwrite_shared_fortran_wrapper(fh, buf, count, datatype, request, ierr);
}

/* ================= End Wrappers for MPI_File_iwrite_shared ================= */


/* ================== C Wrappers for MPI_File_open ================== */
_EXTERN_C_ int PMPI_File_open(MPI_Comm comm, char *filename, int amode, MPI_Info info, MPI_File *fh);
_EXTERN_C_ int MPI_File_open(MPI_Comm comm, char *filename, int amode, MPI_Info info, MPI_File *fh) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_open(comm, filename, amode, info, fh);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_open");
    _wrap_py_return_val = PMPI_File_open(comm, filename, amode, info, fh);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_open =============== */
static void MPI_File_open_fortran_wrapper(MPI_Fint *comm, char *filename, MPI_Fint *amode, MPI_Fint *info, MPI_Fint *fh, MPI_Fint *ierr, int filename_length) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_open((MPI_Comm)(*comm), temp_filename, *amode, (MPI_Info)(*info), (MPI_File*)fh);
#else /* MPI-2 safe call */
    MPI_File temp_fh;
    char* temp_filename;
    temp_filename = wrapper_fortran_to_c_string(filename, filename_length);
    if (!temp_filename)
    {
        fprintf(stderr, "Error in Allinea MPI Fortran wrapper for MPI_File_open - unable to allocate (at most) %i+1 bytes for copy of the filename argument string\n", filename_length);
        abort();
    }
    _wrap_py_return_val = MPI_File_open(MPI_Comm_f2c(*comm), temp_filename, *amode, MPI_Info_f2c(*info), &temp_fh);
    free(temp_filename);
    *fh = MPI_File_c2f(temp_fh);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_OPEN(MPI_Fint *comm, char *filename, MPI_Fint *amode, MPI_Fint *info, MPI_Fint *fh, MPI_Fint *ierr, int filename_length) { 
    MPI_File_open_fortran_wrapper(comm, filename, amode, info, fh, ierr, filename_length);
}

_EXTERN_C_ void mpi_file_open(MPI_Fint *comm, char *filename, MPI_Fint *amode, MPI_Fint *info, MPI_Fint *fh, MPI_Fint *ierr, int filename_length) { 
    MPI_File_open_fortran_wrapper(comm, filename, amode, info, fh, ierr, filename_length);
}

_EXTERN_C_ void mpi_file_open_(MPI_Fint *comm, char *filename, MPI_Fint *amode, MPI_Fint *info, MPI_Fint *fh, MPI_Fint *ierr, int filename_length) { 
    MPI_File_open_fortran_wrapper(comm, filename, amode, info, fh, ierr, filename_length);
}

_EXTERN_C_ void mpi_file_open__(MPI_Fint *comm, char *filename, MPI_Fint *amode, MPI_Fint *info, MPI_Fint *fh, MPI_Fint *ierr, int filename_length) { 
    MPI_File_open_fortran_wrapper(comm, filename, amode, info, fh, ierr, filename_length);
}

/* ================= End Wrappers for MPI_File_open ================= */


/* ================== C Wrappers for MPI_File_preallocate ================== */
_EXTERN_C_ int PMPI_File_preallocate(MPI_File fh, MPI_Offset size);
_EXTERN_C_ int MPI_File_preallocate(MPI_File fh, MPI_Offset size) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_preallocate(fh, size);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_preallocate");
    _wrap_py_return_val = PMPI_File_preallocate(fh, size);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_preallocate =============== */
static void MPI_File_preallocate_fortran_wrapper(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_preallocate((MPI_File)(*fh), *size);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_preallocate(MPI_File_f2c(*fh), *size);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_PREALLOCATE(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_preallocate_fortran_wrapper(fh, size, ierr);
}

_EXTERN_C_ void mpi_file_preallocate(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_preallocate_fortran_wrapper(fh, size, ierr);
}

_EXTERN_C_ void mpi_file_preallocate_(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_preallocate_fortran_wrapper(fh, size, ierr);
}

_EXTERN_C_ void mpi_file_preallocate__(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_preallocate_fortran_wrapper(fh, size, ierr);
}

/* ================= End Wrappers for MPI_File_preallocate ================= */


/* ================== C Wrappers for MPI_File_read ================== */
_EXTERN_C_ int PMPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read(fh, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read");
    _wrap_py_return_val = PMPI_File_read(fh, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read =============== */
static void MPI_File_read_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_read ================= */


/* ================== C Wrappers for MPI_File_read_all ================== */
_EXTERN_C_ int PMPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read_all(fh, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read_all");
    _wrap_py_return_val = PMPI_File_read_all(fh, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read_all =============== */
static void MPI_File_read_all_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read_all((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_all(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_all(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ_ALL(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_all_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_all(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_all_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_all_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_all_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_all__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_all_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_read_all ================= */


/* ================== C Wrappers for MPI_File_read_all_begin ================== */
_EXTERN_C_ int PMPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype);
_EXTERN_C_ int MPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read_all_begin(fh, buf, count, datatype);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read_all_begin");
    _wrap_py_return_val = PMPI_File_read_all_begin(fh, buf, count, datatype);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read_all_begin =============== */
static void MPI_File_read_all_begin_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read_all_begin((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_read_all_begin(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ_ALL_BEGIN(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_all_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_read_all_begin(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_all_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_read_all_begin_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_all_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_read_all_begin__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_all_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

/* ================= End Wrappers for MPI_File_read_all_begin ================= */


/* ================== C Wrappers for MPI_File_read_all_end ================== */
_EXTERN_C_ int PMPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status);
_EXTERN_C_ int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read_all_end(fh, buf, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read_all_end");
    _wrap_py_return_val = PMPI_File_read_all_end(fh, buf, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read_all_end =============== */
static void MPI_File_read_all_end_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read_all_end((MPI_File)(*fh), BufferF2C((void*)buf), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_all_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_all_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ_ALL_END(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_read_all_end(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_read_all_end_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_read_all_end__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_all_end_fortran_wrapper(fh, buf, status, ierr);
}

/* ================= End Wrappers for MPI_File_read_all_end ================= */


/* ================== C Wrappers for MPI_File_read_at ================== */
_EXTERN_C_ int PMPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read_at(fh, offset, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read_at");
    _wrap_py_return_val = PMPI_File_read_at(fh, offset, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read_at =============== */
static void MPI_File_read_at_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read_at((MPI_File)(*fh), *offset, BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_at(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_at(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ_AT(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_at(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_at_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_at__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_read_at ================= */


/* ================== C Wrappers for MPI_File_read_at_all ================== */
_EXTERN_C_ int PMPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read_at_all(fh, offset, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read_at_all");
    _wrap_py_return_val = PMPI_File_read_at_all(fh, offset, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read_at_all =============== */
static void MPI_File_read_at_all_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read_at_all((MPI_File)(*fh), *offset, BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_at_all(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_at_all(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ_AT_ALL(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_all_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_at_all(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_all_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_at_all_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_all_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_at_all__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_all_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_read_at_all ================= */


/* ================== C Wrappers for MPI_File_read_at_all_begin ================== */
_EXTERN_C_ int PMPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype);
_EXTERN_C_ int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read_at_all_begin(fh, offset, buf, count, datatype);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read_at_all_begin");
    _wrap_py_return_val = PMPI_File_read_at_all_begin(fh, offset, buf, count, datatype);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read_at_all_begin =============== */
static void MPI_File_read_at_all_begin_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read_at_all_begin((MPI_File)(*fh), *offset, BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_read_at_all_begin(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ_AT_ALL_BEGIN(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_at_all_begin_fortran_wrapper(fh, offset, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_read_at_all_begin(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_at_all_begin_fortran_wrapper(fh, offset, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_read_at_all_begin_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_at_all_begin_fortran_wrapper(fh, offset, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_read_at_all_begin__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_at_all_begin_fortran_wrapper(fh, offset, buf, count, datatype, ierr);
}

/* ================= End Wrappers for MPI_File_read_at_all_begin ================= */


/* ================== C Wrappers for MPI_File_read_at_all_end ================== */
_EXTERN_C_ int PMPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status);
_EXTERN_C_ int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read_at_all_end(fh, buf, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read_at_all_end");
    _wrap_py_return_val = PMPI_File_read_at_all_end(fh, buf, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read_at_all_end =============== */
static void MPI_File_read_at_all_end_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read_at_all_end((MPI_File)(*fh), BufferF2C((void*)buf), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_at_all_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_at_all_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ_AT_ALL_END(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_read_at_all_end(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_read_at_all_end_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_read_at_all_end__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_at_all_end_fortran_wrapper(fh, buf, status, ierr);
}

/* ================= End Wrappers for MPI_File_read_at_all_end ================= */


/* ================== C Wrappers for MPI_File_read_ordered ================== */
_EXTERN_C_ int PMPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read_ordered(fh, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read_ordered");
    _wrap_py_return_val = PMPI_File_read_ordered(fh, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read_ordered =============== */
static void MPI_File_read_ordered_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read_ordered((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_ordered(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_ordered(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ_ORDERED(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_ordered_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_ordered(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_ordered_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_ordered_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_ordered_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_ordered__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_ordered_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_read_ordered ================= */


/* ================== C Wrappers for MPI_File_read_ordered_begin ================== */
_EXTERN_C_ int PMPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype);
_EXTERN_C_ int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read_ordered_begin(fh, buf, count, datatype);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read_ordered_begin");
    _wrap_py_return_val = PMPI_File_read_ordered_begin(fh, buf, count, datatype);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read_ordered_begin =============== */
static void MPI_File_read_ordered_begin_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read_ordered_begin((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_read_ordered_begin(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ_ORDERED_BEGIN(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_ordered_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_read_ordered_begin(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_ordered_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_read_ordered_begin_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_ordered_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_read_ordered_begin__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_read_ordered_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

/* ================= End Wrappers for MPI_File_read_ordered_begin ================= */


/* ================== C Wrappers for MPI_File_read_ordered_end ================== */
_EXTERN_C_ int PMPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status);
_EXTERN_C_ int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read_ordered_end(fh, buf, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read_ordered_end");
    _wrap_py_return_val = PMPI_File_read_ordered_end(fh, buf, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read_ordered_end =============== */
static void MPI_File_read_ordered_end_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read_ordered_end((MPI_File)(*fh), BufferF2C((void*)buf), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_ordered_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_ordered_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ_ORDERED_END(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_ordered_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_read_ordered_end(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_ordered_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_read_ordered_end_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_ordered_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_read_ordered_end__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_ordered_end_fortran_wrapper(fh, buf, status, ierr);
}

/* ================= End Wrappers for MPI_File_read_ordered_end ================= */


/* ================== C Wrappers for MPI_File_read_shared ================== */
_EXTERN_C_ int PMPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_read_shared(fh, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_read_shared");
    _wrap_py_return_val = PMPI_File_read_shared(fh, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_read_shared =============== */
static void MPI_File_read_shared_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_read_shared((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_shared(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_read_shared(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_READ_SHARED(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_shared_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_shared(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_shared_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_shared_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_shared_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_read_shared__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_read_shared_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_read_shared ================= */


/* ================== C Wrappers for MPI_File_seek ================== */
_EXTERN_C_ int PMPI_File_seek(MPI_File fh, MPI_Offset offset, int whence);
_EXTERN_C_ int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_seek(fh, offset, whence);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_seek");
    _wrap_py_return_val = PMPI_File_seek(fh, offset, whence);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_seek =============== */
static void MPI_File_seek_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_seek((MPI_File)(*fh), *offset, *whence);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_seek(MPI_File_f2c(*fh), *offset, *whence);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_SEEK(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) { 
    MPI_File_seek_fortran_wrapper(fh, offset, whence, ierr);
}

_EXTERN_C_ void mpi_file_seek(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) { 
    MPI_File_seek_fortran_wrapper(fh, offset, whence, ierr);
}

_EXTERN_C_ void mpi_file_seek_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) { 
    MPI_File_seek_fortran_wrapper(fh, offset, whence, ierr);
}

_EXTERN_C_ void mpi_file_seek__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) { 
    MPI_File_seek_fortran_wrapper(fh, offset, whence, ierr);
}

/* ================= End Wrappers for MPI_File_seek ================= */


/* ================== C Wrappers for MPI_File_seek_shared ================== */
_EXTERN_C_ int PMPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence);
_EXTERN_C_ int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_seek_shared(fh, offset, whence);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_seek_shared");
    _wrap_py_return_val = PMPI_File_seek_shared(fh, offset, whence);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_seek_shared =============== */
static void MPI_File_seek_shared_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_seek_shared((MPI_File)(*fh), *offset, *whence);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_seek_shared(MPI_File_f2c(*fh), *offset, *whence);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_SEEK_SHARED(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) { 
    MPI_File_seek_shared_fortran_wrapper(fh, offset, whence, ierr);
}

_EXTERN_C_ void mpi_file_seek_shared(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) { 
    MPI_File_seek_shared_fortran_wrapper(fh, offset, whence, ierr);
}

_EXTERN_C_ void mpi_file_seek_shared_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) { 
    MPI_File_seek_shared_fortran_wrapper(fh, offset, whence, ierr);
}

_EXTERN_C_ void mpi_file_seek_shared__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) { 
    MPI_File_seek_shared_fortran_wrapper(fh, offset, whence, ierr);
}

/* ================= End Wrappers for MPI_File_seek_shared ================= */


/* ================== C Wrappers for MPI_File_set_atomicity ================== */
_EXTERN_C_ int PMPI_File_set_atomicity(MPI_File fh, int flag);
_EXTERN_C_ int MPI_File_set_atomicity(MPI_File fh, int flag) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_set_atomicity(fh, flag);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_set_atomicity");
    _wrap_py_return_val = PMPI_File_set_atomicity(fh, flag);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_set_atomicity =============== */
static void MPI_File_set_atomicity_fortran_wrapper(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_set_atomicity((MPI_File)(*fh), *flag);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_set_atomicity(MPI_File_f2c(*fh), *flag);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_SET_ATOMICITY(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_File_set_atomicity_fortran_wrapper(fh, flag, ierr);
}

_EXTERN_C_ void mpi_file_set_atomicity(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_File_set_atomicity_fortran_wrapper(fh, flag, ierr);
}

_EXTERN_C_ void mpi_file_set_atomicity_(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_File_set_atomicity_fortran_wrapper(fh, flag, ierr);
}

_EXTERN_C_ void mpi_file_set_atomicity__(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) { 
    MPI_File_set_atomicity_fortran_wrapper(fh, flag, ierr);
}

/* ================= End Wrappers for MPI_File_set_atomicity ================= */


/* ================== C Wrappers for MPI_File_set_info ================== */
_EXTERN_C_ int PMPI_File_set_info(MPI_File fh, MPI_Info info);
_EXTERN_C_ int MPI_File_set_info(MPI_File fh, MPI_Info info) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_set_info(fh, info);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_set_info");
    _wrap_py_return_val = PMPI_File_set_info(fh, info);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_set_info =============== */
static void MPI_File_set_info_fortran_wrapper(MPI_Fint *fh, MPI_Fint *info, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_set_info((MPI_File)(*fh), (MPI_Info)(*info));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_set_info(MPI_File_f2c(*fh), MPI_Info_f2c(*info));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_SET_INFO(MPI_Fint *fh, MPI_Fint *info, MPI_Fint *ierr) { 
    MPI_File_set_info_fortran_wrapper(fh, info, ierr);
}

_EXTERN_C_ void mpi_file_set_info(MPI_Fint *fh, MPI_Fint *info, MPI_Fint *ierr) { 
    MPI_File_set_info_fortran_wrapper(fh, info, ierr);
}

_EXTERN_C_ void mpi_file_set_info_(MPI_Fint *fh, MPI_Fint *info, MPI_Fint *ierr) { 
    MPI_File_set_info_fortran_wrapper(fh, info, ierr);
}

_EXTERN_C_ void mpi_file_set_info__(MPI_Fint *fh, MPI_Fint *info, MPI_Fint *ierr) { 
    MPI_File_set_info_fortran_wrapper(fh, info, ierr);
}

/* ================= End Wrappers for MPI_File_set_info ================= */


/* ================== C Wrappers for MPI_File_set_size ================== */
_EXTERN_C_ int PMPI_File_set_size(MPI_File fh, MPI_Offset size);
_EXTERN_C_ int MPI_File_set_size(MPI_File fh, MPI_Offset size) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_set_size(fh, size);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_set_size");
    _wrap_py_return_val = PMPI_File_set_size(fh, size);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_set_size =============== */
static void MPI_File_set_size_fortran_wrapper(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_set_size((MPI_File)(*fh), *size);
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_set_size(MPI_File_f2c(*fh), *size);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_SET_SIZE(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_set_size_fortran_wrapper(fh, size, ierr);
}

_EXTERN_C_ void mpi_file_set_size(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_set_size_fortran_wrapper(fh, size, ierr);
}

_EXTERN_C_ void mpi_file_set_size_(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_set_size_fortran_wrapper(fh, size, ierr);
}

_EXTERN_C_ void mpi_file_set_size__(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) { 
    MPI_File_set_size_fortran_wrapper(fh, size, ierr);
}

/* ================= End Wrappers for MPI_File_set_size ================= */


/* ================== C Wrappers for MPI_File_set_view ================== */
_EXTERN_C_ int PMPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, char *datarep, MPI_Info info);
_EXTERN_C_ int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, char *datarep, MPI_Info info) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_set_view(fh, disp, etype, filetype, datarep, info);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_set_view");
    _wrap_py_return_val = PMPI_File_set_view(fh, disp, etype, filetype, datarep, info);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_set_view =============== */
static void MPI_File_set_view_fortran_wrapper(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep, MPI_Fint *info, MPI_Fint *ierr, int datarep_length) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_set_view((MPI_File)(*fh), *disp, (MPI_Datatype)(*etype), (MPI_Datatype)(*filetype), temp_datarep, (MPI_Info)(*info));
#else /* MPI-2 safe call */
    char* temp_datarep;
    temp_datarep = wrapper_fortran_to_c_string(datarep, datarep_length);
    if (!temp_datarep)
    {
        fprintf(stderr, "Error in Allinea MPI Fortran wrapper for MPI_File_set_view - unable to allocate (at most) %i+1 bytes for copy of the datarep argument string\n", datarep_length);
        abort();
    }
    _wrap_py_return_val = MPI_File_set_view(MPI_File_f2c(*fh), *disp, MPI_Type_f2c(*etype), MPI_Type_f2c(*filetype), temp_datarep, MPI_Info_f2c(*info));
    free(temp_datarep);
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_SET_VIEW(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep, MPI_Fint *info, MPI_Fint *ierr, int datarep_length) { 
    MPI_File_set_view_fortran_wrapper(fh, disp, etype, filetype, datarep, info, ierr, datarep_length);
}

_EXTERN_C_ void mpi_file_set_view(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep, MPI_Fint *info, MPI_Fint *ierr, int datarep_length) { 
    MPI_File_set_view_fortran_wrapper(fh, disp, etype, filetype, datarep, info, ierr, datarep_length);
}

_EXTERN_C_ void mpi_file_set_view_(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep, MPI_Fint *info, MPI_Fint *ierr, int datarep_length) { 
    MPI_File_set_view_fortran_wrapper(fh, disp, etype, filetype, datarep, info, ierr, datarep_length);
}

_EXTERN_C_ void mpi_file_set_view__(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep, MPI_Fint *info, MPI_Fint *ierr, int datarep_length) { 
    MPI_File_set_view_fortran_wrapper(fh, disp, etype, filetype, datarep, info, ierr, datarep_length);
}

/* ================= End Wrappers for MPI_File_set_view ================= */


/* ================== C Wrappers for MPI_File_sync ================== */
_EXTERN_C_ int PMPI_File_sync(MPI_File fh);
_EXTERN_C_ int MPI_File_sync(MPI_File fh) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_sync(fh);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_sync");
    _wrap_py_return_val = PMPI_File_sync(fh);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_sync =============== */
static void MPI_File_sync_fortran_wrapper(MPI_Fint *fh, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_sync((MPI_File)(*fh));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_sync(MPI_File_f2c(*fh));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_SYNC(MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_sync_fortran_wrapper(fh, ierr);
}

_EXTERN_C_ void mpi_file_sync(MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_sync_fortran_wrapper(fh, ierr);
}

_EXTERN_C_ void mpi_file_sync_(MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_sync_fortran_wrapper(fh, ierr);
}

_EXTERN_C_ void mpi_file_sync__(MPI_Fint *fh, MPI_Fint *ierr) { 
    MPI_File_sync_fortran_wrapper(fh, ierr);
}

/* ================= End Wrappers for MPI_File_sync ================= */


/* ================== C Wrappers for MPI_File_write ================== */
_EXTERN_C_ int PMPI_File_write(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_write(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write(fh, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write");
    _wrap_py_return_val = PMPI_File_write(fh, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write =============== */
static void MPI_File_write_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_write ================= */


/* ================== C Wrappers for MPI_File_write_all ================== */
_EXTERN_C_ int PMPI_File_write_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_write_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write_all(fh, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write_all");
    _wrap_py_return_val = PMPI_File_write_all(fh, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write_all =============== */
static void MPI_File_write_all_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write_all((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_all(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_all(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE_ALL(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_all_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_all(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_all_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_all_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_all_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_all__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_all_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_write_all ================= */


/* ================== C Wrappers for MPI_File_write_all_begin ================== */
_EXTERN_C_ int PMPI_File_write_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype);
_EXTERN_C_ int MPI_File_write_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write_all_begin(fh, buf, count, datatype);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write_all_begin");
    _wrap_py_return_val = PMPI_File_write_all_begin(fh, buf, count, datatype);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write_all_begin =============== */
static void MPI_File_write_all_begin_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write_all_begin((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_write_all_begin(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE_ALL_BEGIN(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_all_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_write_all_begin(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_all_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_write_all_begin_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_all_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_write_all_begin__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_all_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

/* ================= End Wrappers for MPI_File_write_all_begin ================= */


/* ================== C Wrappers for MPI_File_write_all_end ================== */
_EXTERN_C_ int PMPI_File_write_all_end(MPI_File fh, void *buf, MPI_Status *status);
_EXTERN_C_ int MPI_File_write_all_end(MPI_File fh, void *buf, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write_all_end(fh, buf, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write_all_end");
    _wrap_py_return_val = PMPI_File_write_all_end(fh, buf, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write_all_end =============== */
static void MPI_File_write_all_end_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write_all_end((MPI_File)(*fh), BufferF2C((void*)buf), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_all_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_all_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE_ALL_END(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_write_all_end(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_write_all_end_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_write_all_end__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_all_end_fortran_wrapper(fh, buf, status, ierr);
}

/* ================= End Wrappers for MPI_File_write_all_end ================= */


/* ================== C Wrappers for MPI_File_write_at ================== */
_EXTERN_C_ int PMPI_File_write_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_write_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write_at(fh, offset, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write_at");
    _wrap_py_return_val = PMPI_File_write_at(fh, offset, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write_at =============== */
static void MPI_File_write_at_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write_at((MPI_File)(*fh), *offset, BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_at(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_at(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE_AT(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_at(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_at_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_at__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_write_at ================= */


/* ================== C Wrappers for MPI_File_write_at_all ================== */
_EXTERN_C_ int PMPI_File_write_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write_at_all(fh, offset, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write_at_all");
    _wrap_py_return_val = PMPI_File_write_at_all(fh, offset, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write_at_all =============== */
static void MPI_File_write_at_all_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write_at_all((MPI_File)(*fh), *offset, BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_at_all(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_at_all(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE_AT_ALL(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_all_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_at_all(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_all_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_at_all_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_all_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_at_all__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_all_fortran_wrapper(fh, offset, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_write_at_all ================= */


/* ================== C Wrappers for MPI_File_write_at_all_begin ================== */
_EXTERN_C_ int PMPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype);
_EXTERN_C_ int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write_at_all_begin(fh, offset, buf, count, datatype);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write_at_all_begin");
    _wrap_py_return_val = PMPI_File_write_at_all_begin(fh, offset, buf, count, datatype);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write_at_all_begin =============== */
static void MPI_File_write_at_all_begin_fortran_wrapper(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write_at_all_begin((MPI_File)(*fh), *offset, BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_write_at_all_begin(MPI_File_f2c(*fh), *offset, BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE_AT_ALL_BEGIN(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_at_all_begin_fortran_wrapper(fh, offset, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_write_at_all_begin(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_at_all_begin_fortran_wrapper(fh, offset, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_write_at_all_begin_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_at_all_begin_fortran_wrapper(fh, offset, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_write_at_all_begin__(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_at_all_begin_fortran_wrapper(fh, offset, buf, count, datatype, ierr);
}

/* ================= End Wrappers for MPI_File_write_at_all_begin ================= */


/* ================== C Wrappers for MPI_File_write_at_all_end ================== */
_EXTERN_C_ int PMPI_File_write_at_all_end(MPI_File fh, void *buf, MPI_Status *status);
_EXTERN_C_ int MPI_File_write_at_all_end(MPI_File fh, void *buf, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write_at_all_end(fh, buf, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write_at_all_end");
    _wrap_py_return_val = PMPI_File_write_at_all_end(fh, buf, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write_at_all_end =============== */
static void MPI_File_write_at_all_end_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write_at_all_end((MPI_File)(*fh), BufferF2C((void*)buf), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_at_all_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_at_all_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE_AT_ALL_END(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_write_at_all_end(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_write_at_all_end_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_all_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_write_at_all_end__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_at_all_end_fortran_wrapper(fh, buf, status, ierr);
}

/* ================= End Wrappers for MPI_File_write_at_all_end ================= */


/* ================== C Wrappers for MPI_File_write_ordered ================== */
_EXTERN_C_ int PMPI_File_write_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_write_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write_ordered(fh, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write_ordered");
    _wrap_py_return_val = PMPI_File_write_ordered(fh, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write_ordered =============== */
static void MPI_File_write_ordered_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write_ordered((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_ordered(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_ordered(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE_ORDERED(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_ordered_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_ordered(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_ordered_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_ordered_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_ordered_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_ordered__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_ordered_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_write_ordered ================= */


/* ================== C Wrappers for MPI_File_write_ordered_begin ================== */
_EXTERN_C_ int PMPI_File_write_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype);
_EXTERN_C_ int MPI_File_write_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write_ordered_begin(fh, buf, count, datatype);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write_ordered_begin");
    _wrap_py_return_val = PMPI_File_write_ordered_begin(fh, buf, count, datatype);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write_ordered_begin =============== */
static void MPI_File_write_ordered_begin_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write_ordered_begin((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype));
#else /* MPI-2 safe call */
    _wrap_py_return_val = MPI_File_write_ordered_begin(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype));
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE_ORDERED_BEGIN(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_ordered_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_write_ordered_begin(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_ordered_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_write_ordered_begin_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_ordered_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

_EXTERN_C_ void mpi_file_write_ordered_begin__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) { 
    MPI_File_write_ordered_begin_fortran_wrapper(fh, buf, count, datatype, ierr);
}

/* ================= End Wrappers for MPI_File_write_ordered_begin ================= */


/* ================== C Wrappers for MPI_File_write_ordered_end ================== */
_EXTERN_C_ int PMPI_File_write_ordered_end(MPI_File fh, void *buf, MPI_Status *status);
_EXTERN_C_ int MPI_File_write_ordered_end(MPI_File fh, void *buf, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write_ordered_end(fh, buf, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write_ordered_end");
    _wrap_py_return_val = PMPI_File_write_ordered_end(fh, buf, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write_ordered_end =============== */
static void MPI_File_write_ordered_end_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write_ordered_end((MPI_File)(*fh), BufferF2C((void*)buf), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_ordered_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_ordered_end(MPI_File_f2c(*fh), BufferF2C((void*)buf), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE_ORDERED_END(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_ordered_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_write_ordered_end(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_ordered_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_write_ordered_end_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_ordered_end_fortran_wrapper(fh, buf, status, ierr);
}

_EXTERN_C_ void mpi_file_write_ordered_end__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_ordered_end_fortran_wrapper(fh, buf, status, ierr);
}

/* ================= End Wrappers for MPI_File_write_ordered_end ================= */


/* ================== C Wrappers for MPI_File_write_shared ================== */
_EXTERN_C_ int PMPI_File_write_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
_EXTERN_C_ int MPI_File_write_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { 
    int _wrap_py_return_val = 0;
    if (in_wrapper) return PMPI_File_write_shared(fh, buf, count, datatype, status);
    in_wrapper = 1;

    allinea_mapSamplerEnterDataless("MPI_File_write_shared");
    _wrap_py_return_val = PMPI_File_write_shared(fh, buf, count, datatype, status);
    allinea_mapSamplerExit(_wrap_py_return_val);
    in_wrapper = 0;
    return _wrap_py_return_val;
}

/* =============== Fortran Wrappers for MPI_File_write_shared =============== */
static void MPI_File_write_shared_fortran_wrapper(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    int _wrap_py_return_val = 0;
#if (!defined(MPICH_HAS_C2F) && defined(MPICH_NAME) && (MPICH_NAME == 1)) /* MPICH test */
    _wrap_py_return_val = MPI_File_write_shared((MPI_File)(*fh), BufferF2C((void*)buf), *count, (MPI_Datatype)(*datatype), (MPI_Status*)status);
#else /* MPI-2 safe call */
    MPI_Status temp_status;
# if defined(MPICH_NAME) && (MPICH_NAME == 1) /* MPICH test */
    MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_shared(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), &temp_status);
    MPI_Status_c2f(&temp_status, status);
# else /* MPI-2 safe call */
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_f2c(status, &temp_status);
    _wrap_py_return_val = MPI_File_write_shared(MPI_File_f2c(*fh), BufferF2C((void*)buf), *count, MPI_Type_f2c(*datatype), ((status == MPI_F_STATUS_IGNORE) ? MPI_STATUS_IGNORE : &temp_status));
    if (status != MPI_F_STATUS_IGNORE) MPI_Status_c2f(&temp_status, status);
# endif /* MPICH test */
#endif /* MPICH test */
    *ierr = _wrap_py_return_val;
}

_EXTERN_C_ void MPI_FILE_WRITE_SHARED(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_shared_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_shared(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_shared_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_shared_(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_shared_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

_EXTERN_C_ void mpi_file_write_shared__(MPI_Fint *fh, MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) { 
    MPI_File_write_shared_fortran_wrapper(fh, buf, count, datatype, status, ierr);
}

/* ================= End Wrappers for MPI_File_write_shared ================= */




























