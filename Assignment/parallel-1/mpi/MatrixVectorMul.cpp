#define DEBUG
#include <mpi.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#define MAX_ELEM 10

using namespace std;

void sendError(const char * s)
{
	fprintf(stderr,s);
	exit(-1);
}
void allocateMatrix(size_t rows, size_t cols, float *** dest)
{
	float * all;
	all=(float *)malloc(rows*cols*sizeof(float));
	*dest=(float**)malloc(rows*sizeof(float*));
	for(size_t i=0;i<rows;i++)
		(*dest)[i]=&all[i*cols];
}		
void generateMatrix(size_t rows, size_t cols, float *** matrix)
{
	allocateMatrix(rows,cols,matrix);
	for(size_t i=0;i<rows;i++)
	for(size_t j=0;j<cols;j++)
	{
		(*matrix)[i][j]=rand()/(float)RAND_MAX*MAX_ELEM;
	}	
}

void printMatrix(size_t rows, size_t cols, float ** matrix)
{
	for(size_t i=0;i<rows;i++)
	{
		for(size_t j=0;j<cols;j++)
			fprintf(stdout,"%.2f ",matrix[i][j]);
		fprintf(stdout,"\n");
	}
}
int main(int argc , char *argv[])
{
	if(argc!=3)
	{
		sendError("Usage: ./MatrixVectorMul <size_M> <size_N>\n");
	}
	//INITIALIZE THE SIZE M AND N
	
	int m,n; 
	m=atoi(argv[1]);
	n=atoi(argv[2]);

	//INITIALIZE MPI ENVIRONMENT
	MPI_Init(NULL,NULL);
	int worldRank,worldSize;
	MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);
	MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
	if(worldSize==0)
		sendError("# of processes must be larger than 1!\n");
	MPI_Status status;
	double starttime,endtime;

	//GENERATING
	srand(time(NULL));
	float ** mat=NULL;
	float * B=new float[n],*C=new float[m];
	if(worldRank==0){
		//GENERATING VECTOR
		fprintf(stdout,"generating vector...\n");
		for(int i=0;i<n;i++)
			B[i]=rand()/(float)RAND_MAX*MAX_ELEM;
		fprintf(stdout,"generated!\n");
		printMatrix(1,n,&B);
		
		//GENERATING MATRIX
		fprintf(stdout,"generating matrix\n");
		starttime=MPI_Wtime();
		generateMatrix(m,n,&mat);	
		endtime=MPI_Wtime();
		fprintf(stdout,"matrix generated! used %lf secs\n", endtime-starttime);
		printMatrix(m,n,mat);
		starttime=MPI_Wtime();
	}

	//MPI_BCAST
	MPI_Bcast(B,n,MPI_FLOAT,0,MPI_COMM_WORLD);
	

	//scatter the matrix
	float *mat_buf=new float[n];
	if(worldRank==0)
	{
		//MPI_SEND
		for(int i=1;i<worldSize;i++)	//enumrate the processor
		{
			for(int r=i;r<m;r+=worldSize)
			{
				MPI_Send(mat[r],n,MPI_FLOAT,i,r,MPI_COMM_WORLD);
			}
		}

		for(int r=0;r<m;r+=worldSize)
		{
			//TODO: POCESSING MULTIPLICATION
			float ans=0;
			for(int i=0;i<m;i++)
				ans+=mat[r][i]*B[i];
			C[r]=ans;
		}
	}
	else{
		//MPI_RECV
		for(int r=worldRank;r<m;r+=worldSize)
		{
			MPI_Recv(mat_buf,n,MPI_FLOAT,0,r,MPI_COMM_WORLD,&status);
			float ans=0;
			for(int i=0;i<n;i++)
				ans+=mat_buf[i]*B[i];
			MPI_Send(&ans,1,MPI_FLOAT,0,r,MPI_COMM_WORLD);
		}
	}

	if(worldRank==0)
	{
		float tempans;
		for(int i=1;i<m;i++)
		{
			if(i%worldSize==0) continue;
			MPI_Recv(&tempans,1,MPI_FLOAT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
			C[status.MPI_TAG]=tempans;
		}
		endtime=MPI_Wtime();
		fprintf(stdout,"finished! Time elapsed %lf secs\n",endtime-starttime);
		for(int i=0;i<m;i++)
			fprintf(stdout,"%.2f ",C[i]);
	}
	MPI_Barrier(MPI_COMM_WORLD);
	return 0;
}
