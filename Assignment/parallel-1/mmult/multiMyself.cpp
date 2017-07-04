#include <iostream>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX_SIZE 5000

ofstream fout("output2",ios::out);

void rerror(const string & s)
{
	cerr<<s<<endl;
	exit(-1);
}


void allocate_matrix (float ***subs, int rows, int cols) {
   int    i;
   float *storage;

   storage = (float *) malloc (rows * cols * sizeof(float));
   *subs = (float **) malloc (rows * sizeof(float *));
   for (i = 0; i < rows; i++)
      (*subs)[i] = &storage[i*cols];
   return;
}

void read_matrix (
   char    *s,          /* File name */
   float ***subs,       /* 2D submatrix indices */
   int     *m,          /* Number of rows in matrix */
   int     *n)          /* Number of columns in matrix */
{
   char     error_msg[80];
   FILE    *fptr;          /* Input file pointer */

   fptr = fopen (s, "r");
   if (fptr == NULL) {
      sprintf (error_msg, "Can't open file '%s'", s);
      rerror (error_msg);
   }
   fread (m, sizeof(int), 1, fptr);
   fread (n, sizeof(int), 1, fptr);
   allocate_matrix (subs, *m, *n);
   fread ((*subs)[0], sizeof(float), *m * *n, fptr);
   fclose (fptr);
   return;
}

void print_matrix(float **m, int r , int c)
{
	fout.setf(ios::fixed);
	fout.precision(2);
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++) fout<<m[i][j]<<" ";
		fout<<endl;
	}
	fout<<endl<<endl;
}

void matrix_multiply(float **a,float **b,float **c,int m,int n,int r)
{
#pragma omp parallel for 
	for(int i=0;i<m;i++){
//#pragma omp parallel for 
		for(int j=0;j<r;j++)
		{
			float sum=0.0;
			for(int k=0;k<n;k++) sum+=a[i][k]+b[k][j];
			c[i][j]=sum;
		}
	}
}
int main(int argc,char *argv[])
{
	int m1,n1;
	int m2,n2;
	
   float **a, **b;    /* Two matrices being multiplied */
   float **c;         /* Product matrix */

    if(argc!=3)
    {
 	   rerror("./MatrixMultply <file1> <file2>");
    }
    read_matrix (argv[1], &a, &m1, &n1);
    print_matrix (a, m1, n1);
    read_matrix (argv[2], &b, &m2, &n2);
    print_matrix (b, m2, n2);
    if (n1 != m2) rerror ("Incompatible matrix dimensions");
    allocate_matrix (&c, m1, n2);
    matrix_multiply (a, b, c, m1, n1, n2);
    print_matrix (c, m1, n2);
	fout.close();
	return 0;
}
