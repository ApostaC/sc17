{{decls}}
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

{{enddecls}}

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

{{fn func MPI_Init}}
    int initMap = 0;
    if (!allinea_mapHasEnteredInit)
    {
        initMap = 1;
        allinea_mapWrapperPreMpiInit();
    }

    allinea_suspend_traces_for_mpi("{{func}}");
    {{callfn}}
    allinea_resume_traces_for_mpi();

    if (initMap)
    {
        allinea_mapWrapperPostMpiInit();
    }
{{endfn}}

{{fn func MPI_Init_thread}}
    int initMap = 0;
    if (!allinea_mapHasEnteredInit)
    {
        initMap = 1;
        allinea_mapWrapperPreMpiInit();
    }
    if ((getenv("ALLINEA_FORCE_MPI_THREAD_FUNNELED") ||
         getenv("MAP_FORCE_MPI_THREAD_FUNNELED")) &&
        ({{2}} == MPI_THREAD_SERIALIZED ||
         {{2}} == MPI_THREAD_MULTIPLE)) {
        {{2}} = MPI_THREAD_FUNNELED;
    }

    allinea_suspend_traces_for_mpi("{{func}}");
    {{callfn}}
    allinea_resume_traces_for_mpi();

    if (initMap)
    {
        allinea_mpi_thread_support_t threadSupport = ALLINEA_MPI_THREAD_SUPPORT_UNSPECIFIED;
        switch ({{2}})
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
{{endfn}}


{{fn func MPI_Send MPI_Isend MPI_Ibsend MPI_Irsend MPI_Issend MPI_Ssend MPI_Rsend MPI_Bsend MPI_Accumulate? MPI_Put?}}
    int _size;
    unsigned long long _bytesSent;
    allinea_type_size({{2}}, &_size);
    _bytesSent = {{1}} * (unsigned long long)_size;
    allinea_mapSamplerEnter("{{func}}", _bytesSent, 0, MPI_TYPE_P2P);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Recv MPI_Irecv MPI_Get?}}
    int _size;
    unsigned long long _bytesRecv;
    allinea_type_size({{2}}, &_size);
    _bytesRecv = {{1}} * (unsigned long long)_size;
    allinea_mapSamplerEnter("{{func}}", 0, _bytesRecv, MPI_TYPE_P2P);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Sendrecv}}
    int _size;
    unsigned long long _bytesSent, _bytesRecv;
    allinea_type_size({{2}}, &_size);
    _bytesSent = {{1}} * (unsigned long long)_size;
    allinea_type_size({{7}}, &_size);
    _bytesRecv = {{6}} * (unsigned long long)_size;
    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_P2P);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Sendrecv_replace}}
    int _size;
    unsigned long long _bytes;
    allinea_type_size({{2}}, &_size);
    _bytes = {{1}} * (unsigned long long)_size;
    allinea_mapSamplerEnter("{{func}}", _bytes, _bytes, MPI_TYPE_P2P);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Bcast}}
    int _size, _rank;
    unsigned long long _bytes;
    const char* const mpiBcastName = "{{func}}";

    PMPI_Comm_rank({{4}}, &_rank);
    allinea_type_size({{2}}, &_size);
    _bytes = {{1}} * (unsigned long long)_size;

    if (_rank == {{3}})
        allinea_mapSamplerEnter(mpiBcastName, _bytes, 0, MPI_TYPE_COLLECTIVE);
    else
        allinea_mapSamplerEnter(mpiBcastName, 0, _bytes, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Gather}}
    int _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{7}}, &_commSize);
    PMPI_Comm_rank({{7}}, &_rank);
    allinea_type_size({{2}}, &_size);
    _bytesSent = {{1}} * (unsigned long long)_size;
    if (_rank == {{6}})
    {
        allinea_type_size({{5}}, &_size);
        _bytesRecv = {{4}} * (unsigned long long)_size * _commSize;
    }
    else 
        _bytesRecv = 0;
    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Gatherv}}
    int _i, _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{8}}, &_commSize);
    PMPI_Comm_rank({{8}}, &_rank);
    allinea_type_size({{2}}, &_size);
    _bytesSent = {{1}} * (unsigned long long)_size;
    if (_rank == {{7}} && {{4}} != 0)
    {
        allinea_type_size({{6}}, &_size);
        _bytesRecv = 0;
        for (_i=0; _i<_commSize; ++_i)
        {
            _bytesRecv += {{4}}[_i] * (unsigned long long)_size;
        }
    }
    else 
        _bytesRecv = 0;
    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Scatter}}
    int _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{7}}, &_commSize);
    PMPI_Comm_rank({{7}}, &_rank);
    allinea_type_size({{5}}, &_size);
    _bytesRecv = {{4}} * (unsigned long long)_size;
    if (_rank == {{6}})
    {
        allinea_type_size({{2}}, &_size);
        _bytesSent = {{1}} * (unsigned long long)_size * _commSize;
    }
    else 
        _bytesSent = 0;
    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Scatterv}}
    int _i, _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{8}}, &_commSize);
    PMPI_Comm_rank({{8}}, &_rank);
    allinea_type_size({{6}}, &_size);
    _bytesRecv = {{5}} * (unsigned long long)_size;
    if (_rank == {{7}} && {{1}} != 0)
    {
        allinea_type_size({{3}}, &_size);
        _bytesSent = 0;
        for (_i=0; _i<_commSize; ++_i)
        {
            _bytesSent += {{1}}[_i] * (unsigned long long)_size;
        }
    }
    else 
        _bytesSent = 0;
    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Reduce}}
    int _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{6}}, &_commSize);
    PMPI_Comm_rank({{6}}, &_rank);
    allinea_type_size({{3}}, &_size);
    _bytesSent = {{2}} * (unsigned long long)_size;
    if (_rank == {{5}})
    {
        _bytesRecv = _bytesSent;
    }
    else 
        _bytesRecv = 0;
    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Reduce_scatter}}
    int _i, _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{5}}, &_commSize);
    PMPI_Comm_rank({{5}}, &_rank);
    allinea_type_size({{3}}, &_size);
    _bytesRecv = {{2}}[_rank] * (unsigned long long)_size;

    _bytesSent = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        _bytesSent += {{2}}[_i] * (unsigned long long)_size;
    }

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Reduce_scatter_block?}}
    int _i, _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{5}}, &_commSize);
    PMPI_Comm_rank({{5}}, &_rank);
    allinea_type_size({{3}}, &_size);
    _bytesRecv = {{2}} * (unsigned long long)_size;
    _bytesSent = {{2}} * (unsigned long long)_size * _commSize;

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Allreduce MPI_Scan MPI_Exscan?}}
    int _size, _commSize, _rank;
    unsigned long long _bytes;
    PMPI_Comm_size({{5}}, &_commSize);
    PMPI_Comm_rank({{5}}, &_rank);
    allinea_type_size({{3}}, &_size);
    _bytes = {{2}} * (unsigned long long)_size;
    allinea_mapSamplerEnter("{{func}}", _bytes, _bytes, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Allgather MPI_Alltoall}}
    int _size, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{6}}, &_commSize);
    allinea_type_size({{2}}, &_size);
    _bytesSent = {{1}} * (unsigned long long)_size * _commSize;

    allinea_type_size({{5}}, &_size);
    _bytesRecv = {{4}} * (unsigned long long)_size * _commSize;
    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Allgatherv}}
    int _i, _size, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{7}}, &_commSize);
    allinea_type_size({{2}}, &_size);
    _bytesSent = {{1}} * (unsigned long long)_size;

    allinea_type_size({{6}}, &_size);
    _bytesRecv = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        _bytesRecv += {{4}}[_i] * (unsigned long long)_size;
    }

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Alltoallv}}
    int _i, _sendTypeSize, _recvTypeSize, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{8}}, &_commSize);
    allinea_type_size({{3}}, &_sendTypeSize);
    allinea_type_size({{7}}, &_recvTypeSize);

    _bytesSent = 0;
    _bytesRecv = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        _bytesSent += {{1}}[_i] * (unsigned long long)_sendTypeSize;
        _bytesRecv += {{5}}[_i] * (unsigned long long)_recvTypeSize;
    }

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Alltoallw?}}
    int _i, _sendTypeSize, _recvTypeSize, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{8}}, &_commSize);

    _bytesSent = 0;
    _bytesRecv = 0;
    if( {{0}} == MPI_IN_PLACE)
    {
        for (_i=0; _i<_commSize; ++_i)
        {
            allinea_type_size({{7}}[_i], &_recvTypeSize);
            _bytesRecv += {{5}}[_i] * (unsigned long long)_recvTypeSize;
        }
        _bytesSent=_bytesRecv;
    }
    else
    {
        for (_i=0; _i<_commSize; ++_i)
        {
            allinea_type_size({{3}}[_i], &_sendTypeSize);
            allinea_type_size({{7}}[_i], &_recvTypeSize);

            _bytesSent += {{1}}[_i] * (unsigned long long)_sendTypeSize;
            _bytesRecv += {{5}}[_i] * (unsigned long long)_recvTypeSize;
        }
    }

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Barrier}}
    if (allinea_mapNoBarrierCount)
        {{callfn}}
    else
    {
        allinea_mapSamplerEnter("{{func}}", 0, 0, MPI_TYPE_COLLECTIVE);
        {{callfn}}
        allinea_mapSamplerExit({{returnVal}});
    }
{{endfn}}

{{fn func MPI_Wait MPI_Waitsome MPI_Waitany MPI_Waitall 
          MPI_Reduce_local?
          MPI_Start MPI_Startall MPI_Cancel MPI_Cart_create MPI_Cart_sub 
          MPI_Comm_create MPI_Comm_dup
          MPI_Comm_accept? MPI_Comm_clone? MPI_Comm_connect?
          MPI_Comm_disconnect? MPI_Comm_join? MPI_Comm_spawn?
          MPI_Comm_spawn_multiple?
          MPI_Comm_remote_group MPI_Comm_remote_size
          MPI_Comm_split
          MPI_Intercomm_create MPI_Intercomm_merge}}
    allinea_mapSamplerEnterDataless("{{func}}");
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Finalize}}
    int _ret = 0;
    allinea_mapSamplerEnter("{{func}}", 0, 0, MPI_TYPE_COLLECTIVE); /* #33608 */

    allinea_mapNoBarrierCount = 1;
    _ret = MPI_Barrier(MPI_COMM_WORLD);
    allinea_mapNoBarrierCount = 0;

    allinea_mapSamplerExit(_ret);
    allinea_set_stop_reason(MAP_STOP_REASON_MPI_FINALIZE);
    allinea_stop_sampling();
    {{callfn}}
{{endfn}}

{{fn func MPI_File_c2f? MPI_File_close? MPI_File_delete? MPI_File_f2c? MPI_File_get_amode? MPI_File_get_atomicity? MPI_File_get_byte_offset? MPI_File_get_group? MPI_File_get_info? MPI_File_get_position? MPI_File_get_position_shared? MPI_File_get_size? MPI_File_get_type_extent? MPI_File_get_view? MPI_File_iread? MPI_File_iread_at? MPI_File_iread_shared? MPI_File_iwrite? MPI_File_iwrite_at? MPI_File_iwrite_shared? MPI_File_open? MPI_File_preallocate? MPI_File_read? MPI_File_read_all? MPI_File_read_all_begin? MPI_File_read_all_end? MPI_File_read_at? MPI_File_read_at_all? MPI_File_read_at_all_begin? MPI_File_read_at_all_end? MPI_File_read_ordered? MPI_File_read_ordered_begin? MPI_File_read_ordered_end? MPI_File_read_shared? MPI_File_seek? MPI_File_seek_shared? MPI_File_set_atomicity? MPI_File_set_info? MPI_File_set_size? MPI_File_set_view? MPI_File_sync? MPI_File_write? MPI_File_write_all? MPI_File_write_all_begin? MPI_File_write_all_end? MPI_File_write_at? MPI_File_write_at_all? MPI_File_write_at_all_begin? MPI_File_write_at_all_end? MPI_File_write_ordered? MPI_File_write_ordered_begin? MPI_File_write_ordered_end? MPI_File_write_shared? }}
    allinea_mapSamplerEnterDataless("{{func}}");
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Ireduce?}}
    int _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{6}}, &_commSize);
    PMPI_Comm_rank({{6}}, &_rank);
    allinea_type_size({{3}}, &_size);
    _bytesSent = {{2}} * (unsigned long long)_size;
    if (_rank == {{5}})
    {
        _bytesRecv = _bytesSent;
    }
    else
        _bytesRecv = 0;
    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Ireduce_scatter?}}
    int _i, _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{5}}, &_commSize);
    PMPI_Comm_rank({{5}}, &_rank);
    allinea_type_size({{3}}, &_size);
    _bytesRecv = {{2}}[_rank] * (unsigned long long)_size;

    _bytesSent = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        _bytesSent += {{2}}[_i] * (unsigned long long)_size;
    }

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Ireduce_scatter_block?}}
    int _i, _size, _commSize, _rank;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{5}}, &_commSize);
    PMPI_Comm_rank({{5}}, &_rank);
    allinea_type_size({{3}}, &_size);
    _bytesRecv = {{2}} * (unsigned long long)_size;
    _bytesSent = {{2}} * (unsigned long long)_size * _commSize;

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}


{{fn func MPI_Neighbor_Allgather? MPI_Neighbor_Alltoall?}}
    int _size, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{6}}, &_commSize);
    allinea_type_size({{2}}, &_size);
    _bytesSent = {{1}} * (unsigned long long)_size * _commSize;

    allinea_type_size({{5}}, &_size);
    _bytesRecv = {{4}} * (unsigned long long)_size * _commSize;
    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Neighbor_Allgatherv?}}
    int _i, _size, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{7}}, &_commSize);
    allinea_type_size({{2}}, &_size);
    _bytesSent = {{1}} * (unsigned long long)_size;

    allinea_type_size({{6}}, &_size);
    _bytesRecv = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        _bytesRecv += {{4}}[_i] * (unsigned long long)_size;
    }

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Neighbor_Alltoallv?}}
    int _i, _sendTypeSize, _recvTypeSize, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{8}}, &_commSize);
    allinea_type_size({{3}}, &_sendTypeSize);
    allinea_type_size({{7}}, &_recvTypeSize);

    _bytesSent = 0;
    _bytesRecv = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        _bytesSent += {{1}}[_i] * (unsigned long long)_sendTypeSize;
        _bytesRecv += {{5}}[_i] * (unsigned long long)_recvTypeSize;
    }

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Neighbor_alltoallw?}}
    int _i, _sendTypeSize, _recvTypeSize, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{8}}, &_commSize);

    _bytesSent = 0;
    _bytesRecv = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        allinea_type_size({{3}}[_i], &_sendTypeSize);
        allinea_type_size({{7}}[_i], &_recvTypeSize);

        _bytesSent += {{1}}[_i] * (unsigned long long)_sendTypeSize;
        _bytesRecv += {{5}}[_i] * (unsigned long long)_recvTypeSize;
    }

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}



{{fn func MPI_Ineighbor_allgather? MPI_Ineighbor_alltoall?}}
    int _size, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{6}}, &_commSize);
    allinea_type_size({{2}}, &_size);
    _bytesSent = {{1}} * (unsigned long long)_size * _commSize;

    allinea_type_size({{5}}, &_size);
    _bytesRecv = {{4}} * (unsigned long long)_size * _commSize;
    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Ineighbor_allgatherv?}}
    int _i, _size, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{7}}, &_commSize);
    allinea_type_size({{2}}, &_size);
    _bytesSent = {{1}} * (unsigned long long)_size;

    allinea_type_size({{6}}, &_size);
    _bytesRecv = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        _bytesRecv += {{4}}[_i] * (unsigned long long)_size;
    }

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Ineighbor_alltoallv?}}
    int _i, _sendTypeSize, _recvTypeSize, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{8}}, &_commSize);
    allinea_type_size({{3}}, &_sendTypeSize);
    allinea_type_size({{7}}, &_recvTypeSize);

    _bytesSent = 0;
    _bytesRecv = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        _bytesSent += {{1}}[_i] * (unsigned long long)_sendTypeSize;
        _bytesRecv += {{5}}[_i] * (unsigned long long)_recvTypeSize;
    }

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}

{{fn func MPI_Ineighbor_alltoallw?}}
    int _i, _sendTypeSize, _recvTypeSize, _commSize;
    unsigned long long _bytesSent, _bytesRecv;
    PMPI_Comm_size({{8}}, &_commSize);

    _bytesSent = 0;
    _bytesRecv = 0;
    for (_i=0; _i<_commSize; ++_i)
    {
        allinea_type_size({{3}}[_i], &_sendTypeSize);
        allinea_type_size({{7}}[_i], &_recvTypeSize);

        _bytesSent += {{1}}[_i] * (unsigned long long)_sendTypeSize;
        _bytesRecv += {{5}}[_i] * (unsigned long long)_recvTypeSize;
    }

    allinea_mapSamplerEnter("{{func}}", _bytesSent, _bytesRecv, MPI_TYPE_COLLECTIVE);
    {{callfn}}
    allinea_mapSamplerExit({{returnVal}});
{{endfn}}
