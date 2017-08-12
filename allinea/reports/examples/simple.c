#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char** argv) {
  int x=2;
  int y=3;
  int z,i;
  z=x*y;
  printf("Value: %d\n",z);
  i=1;
  for(i=1;i<argc;i++) {
    if (!strcmp(argv[i], "sleepy"))
      while(argc)
       sleep(5);
    if (!strcmp(argv[i], "crash"))
      while(argc)
       argv[argc++] = '\0';
    if (!strcmp(argv[i], "busy"))
      while(argc)
       z = z*z+z - (z*z+z);
  }
  return 0;
}
