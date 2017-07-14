#pragma once

#include <CL/cl.h>
#include "host_imp.h"
#include <CL/opencl.h>
#include <iostream>

cl_platform_id platform_id=NULL;
cl_device_id device_id=NULL;
cl_context context=NULL;
cl_command_queue command_queue=NULL;
cl_program program=NULL;
cl_kernel kernel=NULL;

bool inited=false;

void sendError(const char * msg)
{
	std::cerr<<msg<<std::endl;
	exit(-1);
}

void initCheck()
{
	if(!inited) {sendError("CL environment is not initialized!");}
}

void initCL()
{
	inited=true;
	cl_int ret;
	cl_uint ret_num_platforms,ret_num_devices;

	//GET PLATFORM AND DEVICE
	ret=clGetPlatformIDs(1,&platform_id,&ret_num_platforms);
	ret=clGetDeviceIDs(platform_id,CL_DEVICE_TYPE_DEFAULT,1,&device_id,&ret_num_devices);
	//GET CONTEXT
	context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

	//GET COMMAND_QUEUE
	command_queue=clCreateCommandQueue(context, device_id, 0, &ret);
}

Memobj allocateMemory(cl_mem_flags flags, size_t size, void * host_ptr)
{
	initCheck();
	cl_int ret;
	//ALLOCATE MEMORY TO MEMOBJ
	cl_mem memO;
	memO=clCreateBuffer(context, flags, size, host_ptr, &ret);
	return memO;
}

Program loadProgramFromSource(cl_uint count, const char **sources, const size_t *fileSizes)
{
	initCheck();
	cl_int ret;
	//load program
	cl_program prog=clCreateProgramWithSource(context, count, sources, fileSizes, &ret);
	return prog;
}		

Program loadProgramFromOneFile(const char * filename,const int MAX_S_SIZE)
{
	
	//LOAD THE SOURCE CODE IN THE KERNEL
	FILE *fp=fopen(filename,"r");
	char * source_str;
	size_t source_size;
	if(!fp)
		sendError("Failed to load kernel from file!\n");
	source_str=(char*)malloc(MAX_S_SIZE);
	source_size=fread(source_str,1,MAX_S_SIZE,fp);
	fclose(fp);
	return loadProgramFromSource(1,(const char **)&source_str,(const size_t *)&source_size);

}

void buildProgram(Program p,
		cl_int num_devices,
		const cl_device_id * device_list,
		const char *options,
		void (*pfn_notify)(cl_program,void *user_data),
		void *user_data){
	clBuildProgram(p,num_devices,device_list,options,pfn_notify,user_data);
}

Kernel getKernel(Program p,const char * kernel_name)
{

	cl_int errcode;
	return 	clCreateKernel(p,kernel_name,&errcode);

}

void releaseMemObject(Memobj m)
{
	clReleaseMemObject(m);
}

void cleanUp()
{
	initCheck();
	clReleaseProgram(program);
	clReleaseKernel(kernel);
	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);
}
