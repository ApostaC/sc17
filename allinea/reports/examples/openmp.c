#include <math.h>
#include <mpi.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int thread_model_id;

#pragma omp threadprivate(thread_model_id)

void ring(int rank, int nproc, MPI_Comm comm[])
{
    int tag, to, from, loops, thread;
    int i;
    double a;
    MPI_Status status;
    clock_t begin, end;
    tag = 1;
    to = (rank + 1) % nproc;
    from = (rank + nproc - 1) % nproc;

    begin = clock();

#pragma omp parallel private(loops, thread, a, status)
    {
        a = 2.2;
        thread = omp_get_thread_num();

        if (rank == 0)
        {
            loops = thread + 1; /* Some threads go more times round the ring */
            MPI_Send(&loops, 1, MPI_INTEGER, to, tag, comm[thread]);
        }
        /* If I get loops=0, pass on one more time, but give up myself */
        while (1)
        {
            MPI_Recv(&loops, 1, MPI_INTEGER, from, tag, comm[thread], &status);

            if (rank == 0)
            {
                --loops;
            }
            /* delaying tactics */
            for (i = 0;i < 40000000;++i)
            {
                a = sqrt(a) + 2.2;
            }
            MPI_Send(&loops, 1, MPI_INTEGER, to, tag, comm[thread]);
            if (loops == 0)
            {
                break;
            }
        }
        /* one last recv to finish */
        if (rank == 0)
        {
            MPI_Recv(&loops, 1, MPI_INTEGER, from, tag, comm[thread], &status);
        }
    }

    end = clock();

    if (rank == 0)
    {
        printf("%lf rings/s\n", (double)(end - begin) / CLOCKS_PER_SEC);
    }
}

int main(int argc, char* argv[])
{
    const int levs = 100;
    const int repeats = 100;
    const int xm = 100;
    const int ym = 100;
    int threads, mpiprovided;
    clock_t clocks[5];
    int rank, nproc;
    int p, rpt;
    double scale, scale1;
    MPI_Comm* comm;
    double* random1;
    double* a;
    double* b;
    double* c;
    double* d;
    int i, j, k;

    random1 = (double*)malloc(xm * ym * levs * sizeof(double));
    a = (double*)malloc(xm * ym * levs * sizeof(double));
    b = (double*)malloc(xm * ym * levs * sizeof(double));
    c = (double*)malloc(xm * ym * levs * sizeof(double));
    d = (double*)malloc(xm * ym * levs * sizeof(double));

    MPI_Init_thread(&argc, &argv, MPI_THREAD_FUNNELED, &mpiprovided);

    threads = omp_get_max_threads();    
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    comm = (MPI_Comm*)malloc(threads * sizeof(MPI_Comm));
    comm[0] = MPI_COMM_WORLD;
    for (i = 1;i < threads;++i)
    {
        MPI_Comm_dup(comm[0], &comm[i]);
    }

    if (rank == 0)
    {
        printf("openmp running with %d threads\n", threads);
    }
    srand(time(NULL));
    for (i = 0;i < (xm * ym * levs);++i)
    {
        random1[i] = (double) rand() / RAND_MAX;
    }

    memcpy(c, random1, xm * ym * levs * sizeof(double));
    memcpy(d, random1, xm * ym * levs * sizeof(double));

    clocks[0] = clock();
 
    /* Do the initial assignments threaded so the 
       allocation is spread across threads */
#pragma omp parallel
    {
        memcpy(a, random1, xm * ym * levs * sizeof(double));
    }

#pragma omp parallel
    {
        memcpy(b, random1, xm * ym * levs * sizeof(double));
    }

    clocks[1] = clock();

#pragma omp parallel
    {
        thread_model_id = omp_get_thread_num();
        printf("rank %d, thread %d\n", rank, thread_model_id);
    }

    for (rpt = 0;rpt < repeats;++rpt)
    {
#pragma omp parallel
        {
#pragma omp for schedule(static) private(i, j, k)
            for (k = 0;k < levs;++k)
            {
                for (j = 0;j < ym;++j)
                {
                    for (i = 0;i < xm;++i)
                    {
                        a[i + (j * xm) + (k * xm * ym)] = 1.0 / a[i + (j * xm) + (k * xm * ym)] + b[i + (j * xm) + (k * xm * ym)];
                    }
                }
            }
        }
    }

    clocks[2] = clock();

    for (rpt = 0;rpt < repeats;++rpt)
    {
#pragma omp parallel private(i)
        {
            for (i = 0;i < (xm * ym * levs);++i)
            {
                a[i] = (1.0/a[i]) + b[i];
            }
        }
    }

    clocks[3] = clock();

    for (rpt = 0;rpt < repeats;++rpt)
    {
#pragma omp parallel
        {
#pragma omp for schedule(static) private(i, j, k)
            for (k = 0;k < levs;++k)
            {
                for (j = 0;j < ym;++j)
                {
                    for (i = 0;i < xm;++i)
                    {
                        c[i + (j * xm) + (k * xm * ym)] = 1.0 / c[i + (j * xm) + (k * xm * ym)] + d[i + (j * xm) + (k * xm * ym)];
                    }
                }
            }
        }
    }

    clocks[4] = clock();

    scale1 = (double)(xm * ym * levs) * (double)CLOCKS_PER_SEC / 1000000.0;
    scale = (double)repeats * (double)(xm * ym * levs) * (double)CLOCKS_PER_SEC / 1000000.0;

    if (rank == 0)
    {
        printf("%12.2lf openmp initial assignments/s\n", scale1/(double)(clocks[1] - clocks[0]));
        printf("%12.2lf openmp 3d loops/s\n", scale/(double)(clocks[2] - clocks[1]));
        printf("%12.2lf openmp 3d workshares/s\n", scale/(double)(clocks[3] - clocks[2]));
        printf("%12.2lf openmp 3d touched workshares/s\n", scale/(double)(clocks[4] - clocks[3]));
    }

    if (mpiprovided == MPI_THREAD_MULTIPLE)
    {
        ring(rank, nproc, comm);
    }

    free(random1);
    free(a);
    free(b);
    free(c);
    free(d);

    if (rank == 0)
    {
        printf("openmp finished\n");
    }

    MPI_Finalize();
}
