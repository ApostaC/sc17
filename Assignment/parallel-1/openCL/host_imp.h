#ifndef _HOST_IMP_H_
#define _HOST_IMP_H_ 

#include <iostream>
#include <CL/cl.h>

#define READ_WRITE		CL_MEM_READ_WRITE
#define WRITE_ONLY		CL_MEM_WRITE_ONLY
#define READ_ONLY		CL_MEM_READ_ONLY
#define USE_HOST_PTR	CL_MEM_USE_HOST_PTR
#define ALLOC_HOST_PTR	CL_MEM_ALLOC_HOST_PTR
#define COPY_HOST_PTR	CL_MEM_COPY_HOST_PTR

/*
cl_platform_id platform_id=NULL;
cl_device_id device_id=NULL;
cl_context context=NULL;
cl_command_queue command_queue=NULL;
cl_program program=NULL;
cl_kernel kernel=NULL;
*/
typedef cl_mem		Memobj;
typedef cl_program	Program;
typedef cl_kernel	Kernel;

void initCL();
Memobj allocateMemory(cl_mem_flags flags, size_t size, void * host_ptr);
void releaseMemObject(Memobj m);
void cleanUp();

Program loadProgramFromSource(cl_uint count, const char ** fileNames, const size_t *fileSizes);

Program loadProgramFromOneFile(const char * fileName);
void buildProgram(
		Program p,
		cl_int num_devices, 
		const cl_device_id * device_list, 
		const char * options, 
		void (*pfn_notify)(cl_program,void *user_data),
		void * user_data);

Kernel getKernel(Program p, const char *kernel_name);

#endif
