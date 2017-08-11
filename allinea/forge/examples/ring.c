#include <stdio.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
  int pe, nprocs, tag, to, from, loops;
  float a;
  int i;
  MPI_Status status;
    
  tag=1;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pe);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

  to = (pe + 1) % nprocs;
  from = (pe + nprocs - 1) % nprocs;

  if (pe == 0) {
    loops = 5; /* times round ring */
    MPI_Send(&loops, 1, MPI_INT, to, tag, MPI_COMM_WORLD); 
  }

  while (1) {
    MPI_Recv(&loops, 1, MPI_INT, from, tag, MPI_COMM_WORLD, &status);

    if (pe == 0) loops--;
    
    /* delaying tactics */
    a=2.2;
    for (i=0;i<100000000;i++) {a=sqrt(a)+2.2;}

    printf("pe %i calculated %10.2f for loop %i\n",pe,a,loops);
    MPI_Send(&loops, 1, MPI_INT, to, tag, MPI_COMM_WORLD);
    if (loops == 0) break;
  }

  if (pe == 0) {
    MPI_Recv(&loops, 1, MPI_INT, from, tag, MPI_COMM_WORLD, &status);
  }
    
  if (pe == 0) printf("ring finished\n");
  MPI_Finalize();
  return 0;
}
