#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  int myInt;
  char* charStar;
} typeOne;

typedef struct {
  int myInt;
  int yourInt;
  typeOne subList;
} typeTwo;

typedef struct {
  double myDouble;
  unsigned int unsignedInt;
  typeTwo anotherList;
  typeOne hippo;
  char c;
} typeThree;

int func2()
{
  typeTwo a;

  a.myInt = 1;
  a.yourInt = 3;

  return 17;
}

void func1()
{
  int test;
  test = func2();
  if(test>1)
    test=0;
  else
    test=-1;
}

void func3()
{
  int* i = (int*) 1;
  while(i++ || !i)
    free(i);
}

int main(int argc, char** argv, char** environ)
{
  typeThree test;
  typeThree* t2;
  int i;
  int my_rank;		/* Rank of process */
  int p;		/* Number of processors */
  int source;		/* Rank of sender */
  int dest;		/* Rank of receiver */
  int tag = 50;		/* Tag for messages */
  char message[100];	/* Storage for the message */

  int bigArray[10000];
  float tables[12][12];
  int x,y;
  int beingWatched;
  int* dynamicArray;

  void (*s)(int);

  MPI_Status status;	/* Return status for receive */

  t2 = malloc(sizeof(typeThree));

  for(p=0;p<100;p++)
    bigArray[p]=80000+p;

  for(x=0;x<12;x++)
    for(y=0;y<12;y++)
      tables[x][y] = (x+1)*(y+1);
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &p);


  dynamicArray = malloc(sizeof(int)*100/*000*/);
  for(x=0;x<100/*00*/;x++)
    {
      dynamicArray[x] = x%10;
    }

  printf("my rank is %d\n", my_rank);

  printf("sizeof(int) = %ld\nsizeof(void*) = %ld\n", (unsigned long) sizeof(int), (unsigned long) sizeof(void*));
  printf("My pid is %d.\n", getpid());
  printf("I have %d arguments.\n", argc);
  printf("\tHow many did I say?\n");
  printf("They are:\n");
  for(i=0;i<argc;i++)
    printf("%d: %s\n", i, argv[i]);


  if (environ) {
    printf("\tI have an environment too\n");
    printf("They are:\n");
    for (;*environ;environ++) 
      printf("%s\n", *environ);

  }


  for(i=1;i<argc;i++) {
    if (argv[i] && !strcmp(argv[i], "crash")) {
      argv[i] = 0;
      printf("%s", *(char **)argv[i]);
      /* we shall seg fault deliberately if there's an argument called crash!*/
    }
  }

  func1();

  func2();
  fprintf(stderr, "I can write to stderr too\n");

  beingWatched = 1;


  test.anotherList.subList.charStar = "hello";
  test.c = 'p';
  beingWatched = 0;

  if (my_rank != 0 && !(p==7 && my_rank==3)) /* deliberately mismatch send-recv with 7 procs */
    {
      sprintf(message, "Greetings from process %d!", my_rank);
      printf("sending message from (%d)\n",my_rank);
      dest = 0;
      /* Use strlen(message)+1 to include '\0' */
      MPI_Send(message, strlen(message)+1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
      beingWatched--;
    } else {
    /* my_rank == 0 */
    for (source = 1; source < p; source++)
      {
        printf("waiting for message from (%d)\n",source);
        MPI_Recv(message, 100, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
        printf("%s\n", message);
        beingWatched++;
      }
  }

  for(i=1;i<argc;i++) 
    if (argv[i] && !strcmp(argv[i], "memcrash")) 
      func3();

  for(i=1;i<argc;i++) 
    if (argv[i] && !strcmp(argv[i], "guardafter")) 
        dynamicArray[100/*000*/] = 2;

  for(i=1;i<argc;i++)
    if (argv[i] && !strcmp(argv[i], "sleepy")) 
    {
      int waiting = 1;
      while(waiting) sleep(1);
    }

  beingWatched = 12;
  if(p==7) /* prevent any procs reaching MPI_Finalize on mismatched 7-proc run */
    {
      sleep(500000);
    }

  MPI_Finalize();

  beingWatched = 0;

  printf("all done...(%d)\n",my_rank);

  return 0;
} /* main */
