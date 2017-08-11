#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include <mpi.h>

/*
 * Very simple MPI threaded program. Each MPI process kicks off 2 theads which
 * wait 2 seconds, print a message and then return
 */

void *thread_function( void *ptr )
{	
	sleep(2);
	
	char *message = (char *) ptr;
	printf("%s \n", message);
}

int main(int argc, char* argv[])
{
	pthread_t thread1, thread2;
	char message1[50];
	char message2[50];
	int ret1, ret2;
	int id;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	
	sprintf(message1, "Process %d, Thread 1", id);
	sprintf(message2, "Process %d, Thread 1", id);
	
	 // Create threads
	ret1 = pthread_create( &thread1, NULL, thread_function, (void*) &message1);
	ret2 = pthread_create( &thread2, NULL, thread_function, (void*) &message2);
	
	 // Wait for threads to return
	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL); 

	printf("Process %d: Thread 1 returns: %d\n",id,ret1);
	printf("Process %d: Thread 2 returns: %d\n",id,ret2);
	
	MPI_Finalize();
	
	return 0;
}

