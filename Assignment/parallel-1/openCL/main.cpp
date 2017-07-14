#include <iostream>
#include "host_imp.h" 

#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0x100000)
using namespace std;
int main()
{
	initCL();
	Memobj mm=allocateMemory(READ_WRITE, MEM_SIZE*sizeof(char), NULL);
	cout<<"hello?"<<endl;
	cleanUp();
	return 0;
}
