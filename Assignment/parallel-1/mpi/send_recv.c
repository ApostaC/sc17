// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// MPI_Send, MPI_Recv example. Communicates the number -1 from process 0
// to process 1.
//
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
const int MSG = 0x3f3f3f3f;
const int MAXS=1100000;
int main(int argc, char** argv) {
  //INITIALIZE msg
  char msg[MAXS];
  memset(msg,MSG,sizeof(msg));
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // We are assuming at least 2 processes for this task
  if (world_size < 2) {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  if(argc!=2) 
  {
	  fprintf(stderr,"./send_recv <message_size>\n");
	  exit(0);
  }

  int size=atoi(argv[1]);

  int number;
  
  double stt,ent;
  stt=MPI_Wtime();
  if (world_rank == 0) {
    // If we are rank 0, set the number to -1 and send it to process 1
    number = -1;
    MPI_Send(msg, size, MPI_BYTE, 1, 0, MPI_COMM_WORLD);
  } else if (world_rank == 1) {
    MPI_Recv(msg, size, MPI_BYTE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from process 0\n", msg[0]);
  }
  ent=MPI_Wtime();
  MPI_Finalize();
  fprintf(stdout,"time used on rank %d are %lf\n",world_rank,ent-stt);
}
