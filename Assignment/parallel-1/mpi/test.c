#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
	MPI_Init(NULL,NULL);
	int wr,ws;
	MPI_Comm_rank(MPI_COMM_WORLD,&wr);
	MPI_Comm_size(MPI_COMM_WORLD,&ws);

	if(ws!=2){
	   	fprintf(stderr,"world size must be 2\n");
		exit(-1);
	}
	int a[10];
	if(wr==0)
	{
		for(int i=0;i<10;i++) a[i]=i;
	}
	MPI_Barrier(MPI_COMM_WORLD);
	fprintf(stdout,"scatter begin at rank %d !\n",wr);
	int *b=(int *) malloc(sizeof(int)*6);
	MPI_Scatter(a,6,MPI_INT,b,6,MPI_INT,0,MPI_COMM_WORLD);
	for(int i=0;i<6;i++) fprintf(stdout,"from rank %d, b[%d] is %d; \n",wr,i,b[i]);
	MPI_Barrier(MPI_COMM_WORLD);
	return 0;
}
