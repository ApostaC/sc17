#include <mpi.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <string.h>
#define MAX_ELEM 10

void debug(const char * msg)
{
	fprintf(stderr,msg);
}
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
int calSize(int rows,int cols,int wsize)
{
	if(rows % wsize==0)
	{
		return rows/wsize*cols;
	}
	return (rows/wsize+1)*cols;
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
	
	//COPY MATRIX TO AN 1D ARRAY FOR MPI_SCATTER
	float *buf_all=NULL;
	if(worldRank==0){
		buf_all=new float[m*n];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				buf_all[i*m+j]=mat[i][j];	
	}

	//MPI_SCATTER
	int buf_size=calSize(m,n,worldSize);
	float *mat_buf=new float[buf_size];
	memset(mat_buf,0,buf_size*sizeof(float));
	
	MPI_Scatter(buf_all,buf_size,MPI_FLOAT,mat_buf,buf_size,MPI_FLOAT,0,MPI_COMM_WORLD);

	MPI_Barrier(MPI_COMM_WORLD);

	//CALCULATE THE ANS
	float *temp_ans=new float[buf_size/n];
	for(int i=0;i<buf_size/n;i++)
	{
		temp_ans[i]=0;
		for(int j=0;j<n;j++)
			temp_ans[i]+=B[j]*mat_buf[i*n+j];
	}

	MPI_Barrier(MPI_COMM_WORLD);
	float *ans=NULL;
	if(worldRank==0)
	   ans=new float[buf_size/n*worldSize];
	MPI_Gather(temp_ans,buf_size/n,MPI_FLOAT,ans,buf_size/n,MPI_FLOAT,0,MPI_COMM_WORLD);

	if(worldRank==0)
	{
		fprintf(stdout,"calculated! answers are following:\n");
		for(int i=0;i<m;i++) 
			fprintf(stdout,"%.3f ",ans[i]);
		fprintf(stdout,"\n");
	}
	MPI_Barrier(MPI_COMM_WORLD);
	return 0;
}
