#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0X100000)

int main()
{
	cl_device_id devicd_id = NULL;
	cl_context context = NULL;
	cl_command_queue command_queue = NULL;
	cl_mem memobj = NULL;
	cl_program program = NULL;
	cl_kernel kernel = NULL;
	cl_platform_id platform_id=NULL;
	cl_uint ret_num_devicds;
	cl_uint ret_num_platforms;
	cl_int ret;
	
	char string[MEM_SIZE];

	FILE *fp;
	char filename[]="./hello.cl";
	char *source_str;
	size_t source_size;

	//LOAD THE SOURCE CODE IN THE KERNEL
	fp=fopen(filename,"r");
	if(!fp)
	{
		fprintf(stderr,"Failed to load kernel!\n");
		exit(1);
	}
	source_str=(char*)malloc(MAX_SOURCE_SIZE);
	source_size=fread(source_str,1,MAX_SOURCE_SIZE,fp);
	fclose(fp);

	//GET PLATFORM AND DEVICE INFO
	ret=clGetPlatformIDs(1,&platform_id,&ret_num_platforms);
	ret=clGetDeviceIDs(platform_id,CL_DEVICE_TYPE_DEFAULT,1,&devicd_id,&ret_num_devicds);

	//CREATE OPENCL CONTEXT
	context = clCreateContext(NULL,1,&devicd_id,NULL,NULL,&ret);

	//CREATE COMMAND QUEUE
	command_queue=clCreateCommandQueue(context,devicd_id,0,&ret);

	//CREATE MEMORY BUFFER
	memobj=clCreateBuffer(context,CL_MEM_READ_WRITE, MEM_SIZE*sizeof(char),NULL,&ret);

	//CREATE KERNEL PROGRAM FROM THE SOURCE
	program=clCreateProgramWithSource(context,1,(const char **)&source_str,(const size_t*)&source_size,&ret);
	
	//BUILD KERNEL PROGRAM
	ret=clBuildProgram(program,1,&devicd_id,NULL,NULL,NULL);

	//CREATE OPENCL KERNEL
	kernel=clCreateKernel(program,"hello",&ret);

	//SET OPENCL KERNEL PARAMS
	ret=clSetKernelArg(kernel,0,sizeof(cl_mem),(void*)&memobj);

	//EXCUTE OPENCL KERNEL
	ret=clEnqueueTask(command_queue,kernel,0,NULL,NULL);

	//COPY RESULTS FORM THE MEMORY BUFFER
	ret=clEnqueueReadBuffer(command_queue,memobj,CL_TRUE,0,MEM_SIZE*sizeof(char),string,0,NULL,NULL);

	//DISPLAY RESULT
	puts(string);

	//CLEAN UPs
	ret=clFlush(command_queue);
	ret=clFinish(command_queue);
	ret=clReleaseKernel(kernel);
	ret=clReleaseProgram(program);
	ret=clReleaseMemObject(memobj);
	ret=clReleaseCommandQueue(command_queue);
	ret=clReleaseContext(context);

	free(source_str);

	return 0;

}
