#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 12
#endif
#ifndef PFXDIST
   #define PFXDIST 0
#endif
#ifndef PFADIST
   #define PFADIST 0
#endif

#if !defined(ATL_3DNow) && !defined(ATL_SSE1) && \
    (PFADIST != 0 || PFXDIST != 0 || PFYDIST != 0)
   #include "atlas_prefetch.h"
#endif

#if defined(ATL_3DNow) || defined(ATL_SSE1)
   #ifndef PFIY
      #define PFIY prefetchnta
   #endif
   #ifndef PFIX
      #define PFIX prefetchnta
   #endif
   #ifndef PFIA
      #ifdef ATL_3DNow
         #define PFIA prefetchw
      #else
         #define PFIA prefetcht0
      #endif
   #endif
#endif
/*
 * X & A are prefetched in M loop PF[A,X]DIST (in bytes) ahead
 */
#if PFADIST == 0                /* flag for no prefetch */
   #define prefA(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefA(mem) __asm__ __volatile__ \
         (Mstr(PFIA) " %0" : : "m" (*(((char *)(mem))+PFADIST)))
   #else
      #if PFLVL == 2
         #define prefA(mem) ATL_pfl2W(((char*)mem)+PFADIST)
      #else
         #define prefA(mem) ATL_pfl1W(((char*)mem)+PFADIST)
      #endif
   #endif
#endif
#if PFXDIST == 0                /* flag for no prefetch */
   #define prefX(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefX(mem) __asm__ __volatile__ \
         (Mstr(PFIX) " %0" : : "m" (*(((char *)(mem))+PFXDIST)))
   #else
      #if PFLVL == 2
         #define prefX(mem) ATL_pfl2R(((char*)mem)+PFXDIST)
      #else
         #define prefX(mem) ATL_pfl1R(((char*)mem)+PFXDIST)
      #endif
   #endif
#endif
/*
 * Y is prefetched in N-loop, and always fetches next NU piece
 */
#if PFYDIST == 0                /* flag for no prefetch */
   #define prefY(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefY(mem) \
         __asm__ __volatile__ (Mstr(PFIY) " %0" : : "m" (*(((char *)(mem)))))
   #else
      #if PFLVL == 2
         #define prefY(mem) ATL_pfl2R(mem)
      #else
         #define prefY(mem) ATL_pfl1R(mem)
      #endif
   #endif
#endif
#ifndef ATL_CINT
   #define ATL_CINT const int
#endif
#ifndef ATL_INT
   #define ATL_INT int
#endif
void ATL_UGERK(ATL_CINT M, ATL_CINT N, const double *X, const double *Y, 
               double *A, ATL_CINT lda)
/*
 * 8x12 unrolled r1_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N12=(N/12)*12, M8=(M/8)*8, lda12=lda*12;
   ATL_INT j;

   for (j=N12; j; j -= 12, A += lda12, Y += 12)
   {
      double *A0=A, *A1=A0+lda, *A2=A1+lda, *A3=A2+lda, *A4=A3+lda, *A5=A4+lda,
             *A6=A5+lda, *A7=A6+lda, *A8=A7+lda, *A9=A8+lda, *A10=A9+lda,
             *A11=A10+lda;
      const register double y0=Y[0], y1=Y[1], y2=Y[2], y3=Y[3], y4=Y[4],
                            y5=Y[5], y6=Y[6], y7=Y[7], y8=Y[8], y9=Y[9],
                            y10=Y[10], y11=Y[11];
      ATL_INT i;
      prefY(Y+12+12-1);
      for (i=0; i < M8; i += 8)
      {
         const register double x0=X[i+0], x1=X[i+1], x2=X[i+2], x3=X[i+3],
                               x4=X[i+4], x5=X[i+5], x6=X[i+6], x7=X[i+7];

         prefX(X);
         A0[i+0] += y0 * x0;
         prefA(A0);
         A1[i+0] += y1 * x0;
         prefA(A1);
         A2[i+0] += y2 * x0;
         prefA(A2);
         A3[i+0] += y3 * x0;
         prefA(A3);
         A4[i+0] += y4 * x0;
         prefA(A4);
         A5[i+0] += y5 * x0;
         prefA(A5);
         A6[i+0] += y6 * x0;
         prefA(A6);
         A7[i+0] += y7 * x0;
         prefA(A7);
         A8[i+0] += y8 * x0;
         prefA(A8);
         A9[i+0] += y9 * x0;
         prefA(A9);
         A10[i+0] += y10 * x0;
         prefA(A10);
         A11[i+0] += y11 * x0;
         prefA(A11);
         A0[i+1] += y0 * x1;
         A1[i+1] += y1 * x1;
         A2[i+1] += y2 * x1;
         A3[i+1] += y3 * x1;
         A4[i+1] += y4 * x1;
         A5[i+1] += y5 * x1;
         A6[i+1] += y6 * x1;
         A7[i+1] += y7 * x1;
         A8[i+1] += y8 * x1;
         A9[i+1] += y9 * x1;
         A10[i+1] += y10 * x1;
         A11[i+1] += y11 * x1;
         A0[i+2] += y0 * x2;
         A1[i+2] += y1 * x2;
         A2[i+2] += y2 * x2;
         A3[i+2] += y3 * x2;
         A4[i+2] += y4 * x2;
         A5[i+2] += y5 * x2;
         A6[i+2] += y6 * x2;
         A7[i+2] += y7 * x2;
         A8[i+2] += y8 * x2;
         A9[i+2] += y9 * x2;
         A10[i+2] += y10 * x2;
         A11[i+2] += y11 * x2;
         A0[i+3] += y0 * x3;
         A1[i+3] += y1 * x3;
         A2[i+3] += y2 * x3;
         A3[i+3] += y3 * x3;
         A4[i+3] += y4 * x3;
         A5[i+3] += y5 * x3;
         A6[i+3] += y6 * x3;
         A7[i+3] += y7 * x3;
         A8[i+3] += y8 * x3;
         A9[i+3] += y9 * x3;
         A10[i+3] += y10 * x3;
         A11[i+3] += y11 * x3;
         A0[i+4] += y0 * x4;
         A1[i+4] += y1 * x4;
         A2[i+4] += y2 * x4;
         A3[i+4] += y3 * x4;
         A4[i+4] += y4 * x4;
         A5[i+4] += y5 * x4;
         A6[i+4] += y6 * x4;
         A7[i+4] += y7 * x4;
         A8[i+4] += y8 * x4;
         A9[i+4] += y9 * x4;
         A10[i+4] += y10 * x4;
         A11[i+4] += y11 * x4;
         A0[i+5] += y0 * x5;
         A1[i+5] += y1 * x5;
         A2[i+5] += y2 * x5;
         A3[i+5] += y3 * x5;
         A4[i+5] += y4 * x5;
         A5[i+5] += y5 * x5;
         A6[i+5] += y6 * x5;
         A7[i+5] += y7 * x5;
         A8[i+5] += y8 * x5;
         A9[i+5] += y9 * x5;
         A10[i+5] += y10 * x5;
         A11[i+5] += y11 * x5;
         A0[i+6] += y0 * x6;
         A1[i+6] += y1 * x6;
         A2[i+6] += y2 * x6;
         A3[i+6] += y3 * x6;
         A4[i+6] += y4 * x6;
         A5[i+6] += y5 * x6;
         A6[i+6] += y6 * x6;
         A7[i+6] += y7 * x6;
         A8[i+6] += y8 * x6;
         A9[i+6] += y9 * x6;
         A10[i+6] += y10 * x6;
         A11[i+6] += y11 * x6;
         A0[i+7] += y0 * x7;
         A1[i+7] += y1 * x7;
         A2[i+7] += y2 * x7;
         A3[i+7] += y3 * x7;
         A4[i+7] += y4 * x7;
         A5[i+7] += y5 * x7;
         A6[i+7] += y6 * x7;
         A7[i+7] += y7 * x7;
         A8[i+7] += y8 * x7;
         A9[i+7] += y9 * x7;
         A10[i+7] += y10 * x7;
         A11[i+7] += y11 * x7;
      }
      for (i=M8; i < M; i++)
      {
         const register double x0 = X[i];
         A0[i] += y0 * x0;
         A1[i] += y1 * x0;
         A2[i] += y2 * x0;
         A3[i] += y3 * x0;
         A4[i] += y4 * x0;
         A5[i] += y5 * x0;
         A6[i] += y6 * x0;
         A7[i] += y7 * x0;
         A8[i] += y8 * x0;
         A9[i] += y9 * x0;
         A10[i] += y10 * x0;
         A11[i] += y11 * x0;
      }
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N12; j; j--, A += lda, Y++)
   {
      double *A0=A;
      const register double y0=Y[0];
      ATL_INT i;
      prefY(Y+1+1-1);
      for (i=0; i < M8; i += 8)
      {
         const register double x0=X[i+0], x1=X[i+1], x2=X[i+2], x3=X[i+3],
                               x4=X[i+4], x5=X[i+5], x6=X[i+6], x7=X[i+7];

         prefX(X);
         A0[i+0] += y0 * x0;
         prefA(A0);
         A0[i+1] += y0 * x1;
         A0[i+2] += y0 * x2;
         A0[i+3] += y0 * x3;
         A0[i+4] += y0 * x4;
         A0[i+5] += y0 * x5;
         A0[i+6] += y0 * x6;
         A0[i+7] += y0 * x7;
      }
      for (i=M8; i < M; i++)
      {
         const register double x0 = X[i];
         A0[i] += y0 * x0;
      }
   }
}
