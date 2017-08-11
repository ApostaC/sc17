
int main(int argc,char** argv)
{
  int *intArray = new int[10];
  for( int i=0; i <= 10; ++i)
  {
    intArray[i] = i;
  }
  delete []intArray;
  return 0;
}
