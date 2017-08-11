#define DEBUG
#define MAIN1D

#ifdef MAIN2D
	#define KERNEL_NAME "matrixMulVector2D"
#endif

#ifdef MAIN1D
	#define KERNEL_NAME "matrixMulVector1D"
#endif 

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <CL/cl.h>
#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0x100000)
#define Memobj  cl_mem
#define Program cl_program
#define Kernel cl_kernel

#ifdef MAIN2D
	#define LOCAL_DIM_ROW 1
	#define LOCAL_DIM_COL 2
#endif

#ifdef MAIN1D
	#define LOCAL_SIZE 2
#endif 

using namespace std;
int rows,cols;
void readInfo(int ** vector, int *** matrix)
{
	cout<<"Input the number of rows and columns please: "<<endl;
	cin>>rows>>cols;
	//ALLOCATE MEMORY
	int * temp=new int[rows*cols];
	(*matrix)=(int **) malloc(rows*sizeof(int *));
	for(int i=0;i<rows;i++) (*matrix)[i]=&temp[i*cols];

	(*vector)=new int[cols];

	//READ INPUT
	cout<<"Matrix:"<<endl;
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			cin>>(*matrix)[i][j];
	cout<<"Vector:"<<endl;
	for(int i=0;i<cols;i++)
		cin>>(*vector)[i];
}

void printMatrix(int row,int col,int ** m)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++) cout<<m[i][j]<<" ";
		cout<<endl;
	}
}

size_t shrRoundUp(size_t elem, size_t floor)
{
	size_t aa=floor/elem;
	size_t bb=aa*elem;
	if(bb<floor) return (aa+1)*elem;
	else return bb;
}

int main()
{
	//INIT VARIABLES
	int * vector=NULL;
	int ** matrix= NULL;
	readInfo(&vector,&matrix);


	//PRELOAD KERNEL FILE
	FILE *fp;
	char filename[]="./mmv.cl";
	char *source_str;
	size_t source_size;
	
	cout<<"loading kernel file at "<<filename<<" ..."<<endl;

	fp=fopen(filename,"r");
	if(!fp)
	{
		cerr<<"cannot open kernel file!"<<endl;
		return -1;
	}
	source_str=(char *)malloc(MAX_SOURCE_SIZE);
	source_size=fread(source_str,1,MAX_SOURCE_SIZE,fp);
	fclose(fp);


	//INIT OPENCL ENVIRONMENT

	cl_platform_id platform=NULL;
	cl_device_id device=NULL;
	cl_context context;
	cl_command_queue queue;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;
	cl_int errcode;

	errcode=clGetPlatformIDs(1,&platform,&ret_num_platforms);
	errcode=clGetDeviceIDs(platform,CL_DEVICE_TYPE_DEFAULT,1,&device,&ret_num_devices);

	context=clCreateContext(0,1,&device,NULL,NULL,&errcode);
	queue = clCreateCommandQueue(context, device, 0, &errcode);

	cout<<"basic info got!"<<endl;

	//CREATING OPENCL MEMORY OBJECT	
	Memobj mat=clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(int)*rows*cols, (void *)(&matrix[0][0]), &errcode);
	Memobj vec=clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(int)*cols, (void *)vector, &errcode);
	Memobj ret=clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int)*rows,NULL, &errcode);

	cout<<"memobj created!"<<endl;
	
	//CREATE AND BUILD PROGRAM
	Program p=clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &errcode);
	cout<<"program created! "<<errcode<<endl;
	errcode= clBuildProgram(p, 1, &device, NULL, NULL, NULL);
	char* build_log;  
	size_t log_size;  
	clGetProgramBuildInfo(p, device, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);  // First call to know the proper size  
	build_log = new char[log_size+1];  
	clGetProgramBuildInfo(p, device, CL_PROGRAM_BUILD_LOG, log_size, build_log, NULL);  // Second call to get the log  
	build_log[log_size] = '\0';  
	cout << build_log << endl;  
	delete[] build_log;  

	cout<<"program built! "<<errcode <<endl;

	//CREATE KERNEL AND SET ARGS
	Kernel k=clCreateKernel(p, KERNEL_NAME, &errcode);

	cout<<"kernel loaded!"<<errcode<<" "<<endl;

	errcode|=clSetKernelArg(k,0,sizeof(Memobj),&mat);
	errcode|=clSetKernelArg(k,1,sizeof(Memobj),&vec);
	errcode|=clSetKernelArg(k,2,sizeof(Memobj),&ret);
	errcode|=clSetKernelArg(k,3,sizeof(int),&rows);
	errcode|=clSetKernelArg(k,4,sizeof(int),&cols);
	cout<<"Args set!"<<endl;

	//SET WORK DIMENSIONS AND EXECUTE THE KERNEL
#ifdef MAIN2D 
	cout<<"working at CPU local work group dimenson "<<LOCAL_DIM_ROW<<"*"<<LOCAL_DIM_COL<<endl;
	size_t gs[2],ls[2]={LOCAL_DIM_ROW,LOCAL_DIM_COL};
	gs[0]=shrRoundUp(ls[0],rows);
	gs[1]=shrRoundUp(ls[1],cols);
	errcode = clEnqueueNDRangeKernel(queue, k, 2, NULL,gs,ls,0,NULL,NULL);
	cout<<"exceuted!"<<endl;
#endif

#ifdef MAIN1D 
	size_t gs,ls;
	ls=LOCAL_SIZE;
	gs=shrRoundUp(ls,rows);
	errcode =clEnqueueNDRangeKernel(queue, k, 1, NULL,&gs,&ls,0,NULL,NULL);
	cout<<"exceuted!"<<endl;
#endif 
	//LOAD THE ANSWER
	int * ans=new int[rows];
	errcode=clEnqueueReadBuffer(queue, ret, CL_TRUE, 0, sizeof(int)*(rows), ans,0,NULL,NULL);
	cout<<"got ans"<<endl;

	printMatrix(1,rows,&ans);

	//CLEAN UP
	delete[] ans;
	delete[] vector;
	delete[] source_str;
#ifdef DEBUG
	for(int i=0;i<rows;i++) {
		cout<<matrix[i]<<" : ";
		for(int j=0;j<cols;j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
#endif 
	//for(int i=0;i<rows;i++)  
		//delete[] matrix[i];
	delete[] matrix;
	clReleaseKernel(k);
	clReleaseContext(context);
	clReleaseProgram(p);
	clReleaseMemObject(mat);
	clReleaseMemObject(vec);
	clReleaseMemObject(ret);
	clReleaseCommandQueue(queue);

	return 0;

}
