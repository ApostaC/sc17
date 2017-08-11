#define LOOPS 1000000000
#define SIZE 1000000

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void fusion()
{
    float *x;
    float *y;
    float alpha = 3.3f;
    float dot   = 0.0f;
    int i, j;

    x = (float *) malloc(sizeof(float)*SIZE);
    y = (float *) malloc(sizeof(float)*SIZE);

    for (i=0; i<SIZE; ++i)
        x[i] = 4.4f;
    for (i=0; i<SIZE; ++i)
        y[i] = 5.5f;

    alpha = 3.3f;
    dot = 0.0f;

    for (j=0; j<500; ++j)
    {
        for (i=0; i<SIZE; ++i)
            y[i] = y[i] + alpha*x[i];
        for (i=0; i<SIZE; ++i)
            dot = dot + y[i]*y[i];
        for (i=0; i<SIZE; ++i)
        {
            y[i] = y[i] + alpha*x[i];
            dot = dot + y[i]*y[i];
        }
    }

    free(x);
    free(y);

    printf(" fusion answer %e\n", dot);
}

void stride()
{
    float **a;
    float sum;
    int i, j, l, header, body;

    header = 2000*sizeof(float*);
    body   = 2000*2000*sizeof(float);
    a = (float**) malloc(header+body); 
    a[0] = (float*)(a + 2000);
    for (i=1; i<2000; ++i)
        a[i] = a[i-1] + 2000;

    for (l=0; l<LOOPS/4000000; ++l)
        for (i=0; i<2000; ++i)
            for (j=0; j<2000; ++j)
                a[i][j] = (i+1)*(j+1);

    for (l=0; l<LOOPS/4000000; ++l)
        for (j=0; j<2000; ++j)
            for (i=0; i<2000; ++i)
                a[i][j] = (i+1)*(j+1);

    sum = 0;
    for (i=0; i<2000; ++i)
        for (j=0; j<2000; ++j)
            sum += a[i][j];

    free(a);

    printf(" stride answer %e\n", sum);
}

void power()
{
    int i, n;
    float a,b;

    a = 1.1f;
    b = 1.1f;
    for (i=0; i<LOOPS; ++i)
        b += pow(a,4);

    n = 4;
    for (i=0; i<LOOPS; ++i)
        b -= pow(a,n);

    for (i=0; i<LOOPS; ++i)
        b += a*a*a*a;

    printf(" power answer %e\n", b);
}

void lookup()
{
    float table1[10];
    float table2[10];
    const float pi=3.1415926f;
    float a;
    int i;

    for (i=0; i<10; ++i)
    {
        table1[i] = pi/(i+1);
        table2[i] = cosf(table1[i]);
    }

    a=1.1f;
    for (i=1; i<=LOOPS; ++i)
        a += i*cosf(pi/4.0f);

    for (i=1; i<=LOOPS; ++i)
        a -= i*cosf(table1[4]);

    for (i=1; i<=LOOPS; ++i)
        a += i*table2[4];

    printf(" lookup answer %e\n", a);
}

int main()
{
    fusion();
    stride();
    power();
    lookup();

    printf(" serial finished\n");
    return 0;
}
