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
void ATL_UGER2K(ATL_CINT M, ATL_CINT N, const double *X, const double *Y, 
                const double *W, const double *Z, double *A, ATL_CINT lda)
/*
 * 8x12 unrolled r2_c.
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
      const register double y0=Y[0], z0=Z[0], y1=Y[1], z1=Z[1], y2=Y[2],
                            z2=Z[2], y3=Y[3], z3=Z[3], y4=Y[4], z4=Z[4],
                            y5=Y[5], z5=Z[5], y6=Y[6], z6=Z[6], y7=Y[7],
                            z7=Z[7], y8=Y[8], z8=Z[8], y9=Y[9], z9=Z[9],
                            y10=Y[10], z10=Z[10], y11=Y[11], z11=Z[11];
      ATL_INT i;
      prefY(Y+12+12-1);
      prefY(Z+12+12-1);
      for (i=0; i < M8; i += 8)
      {
         register double a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11;
         const double x0=X[i+0], w0=W[i+0], x1=X[i+1], w1=W[i+1], x2=X[i+2],
                      w2=W[i+2], x3=X[i+3], w3=W[i+3], x4=X[i+4], w4=W[i+4],
                      x5=X[i+5], w5=W[i+5], x6=X[i+6], w6=W[i+6], x7=X[i+7],
                      w7=W[i+7];

         prefX(X);
         a0 = A0[i+0];
         a0 += x0 * y0;
         a1 = A1[i+0];
         a1 += x0 * y1;
         a2 = A2[i+0];
         a2 += x0 * y2;
         a3 = A3[i+0];
         a3 += x0 * y3;
         a4 = A4[i+0];
         a4 += x0 * y4;
         a5 = A5[i+0];
         a5 += x0 * y5;
         a6 = A6[i+0];
         a6 += x0 * y6;
         a7 = A7[i+0];
         a7 += x0 * y7;
         a8 = A8[i+0];
         a8 += x0 * y8;
         a9 = A9[i+0];
         a9 += x0 * y9;
         a10 = A10[i+0];
         a10 += x0 * y10;
         a11 = A11[i+0];
         a11 += x0 * y11;
         prefX(W);
         a0 += w0 * z0;
         prefA(A0);
         A0[i+0] = a0;
         a1 += w0 * z1;
         prefA(A1);
         A1[i+0] = a1;
         a2 += w0 * z2;
         prefA(A2);
         A2[i+0] = a2;
         a3 += w0 * z3;
         prefA(A3);
         A3[i+0] = a3;
         a4 += w0 * z4;
         prefA(A4);
         A4[i+0] = a4;
         a5 += w0 * z5;
         prefA(A5);
         A5[i+0] = a5;
         a6 += w0 * z6;
         prefA(A6);
         A6[i+0] = a6;
         a7 += w0 * z7;
         prefA(A7);
         A7[i+0] = a7;
         a8 += w0 * z8;
         prefA(A8);
         A8[i+0] = a8;
         a9 += w0 * z9;
         prefA(A9);
         A9[i+0] = a9;
         a10 += w0 * z10;
         prefA(A10);
         A10[i+0] = a10;
         a11 += w0 * z11;
         prefA(A11);
         A11[i+0] = a11;
         a0 = A0[i+1];
         a0 += x1 * y0;
         a1 = A1[i+1];
         a1 += x1 * y1;
         a2 = A2[i+1];
         a2 += x1 * y2;
         a3 = A3[i+1];
         a3 += x1 * y3;
         a4 = A4[i+1];
         a4 += x1 * y4;
         a5 = A5[i+1];
         a5 += x1 * y5;
         a6 = A6[i+1];
         a6 += x1 * y6;
         a7 = A7[i+1];
         a7 += x1 * y7;
         a8 = A8[i+1];
         a8 += x1 * y8;
         a9 = A9[i+1];
         a9 += x1 * y9;
         a10 = A10[i+1];
         a10 += x1 * y10;
         a11 = A11[i+1];
         a11 += x1 * y11;
         a0 += w1 * z0;
         A0[i+1] = a0;
         a1 += w1 * z1;
         A1[i+1] = a1;
         a2 += w1 * z2;
         A2[i+1] = a2;
         a3 += w1 * z3;
         A3[i+1] = a3;
         a4 += w1 * z4;
         A4[i+1] = a4;
         a5 += w1 * z5;
         A5[i+1] = a5;
         a6 += w1 * z6;
         A6[i+1] = a6;
         a7 += w1 * z7;
         A7[i+1] = a7;
         a8 += w1 * z8;
         A8[i+1] = a8;
         a9 += w1 * z9;
         A9[i+1] = a9;
         a10 += w1 * z10;
         A10[i+1] = a10;
         a11 += w1 * z11;
         A11[i+1] = a11;
         a0 = A0[i+2];
         a0 += x2 * y0;
         a1 = A1[i+2];
         a1 += x2 * y1;
         a2 = A2[i+2];
         a2 += x2 * y2;
         a3 = A3[i+2];
         a3 += x2 * y3;
         a4 = A4[i+2];
         a4 += x2 * y4;
         a5 = A5[i+2];
         a5 += x2 * y5;
         a6 = A6[i+2];
         a6 += x2 * y6;
         a7 = A7[i+2];
         a7 += x2 * y7;
         a8 = A8[i+2];
         a8 += x2 * y8;
         a9 = A9[i+2];
         a9 += x2 * y9;
         a10 = A10[i+2];
         a10 += x2 * y10;
         a11 = A11[i+2];
         a11 += x2 * y11;
         a0 += w2 * z0;
         A0[i+2] = a0;
         a1 += w2 * z1;
         A1[i+2] = a1;
         a2 += w2 * z2;
         A2[i+2] = a2;
         a3 += w2 * z3;
         A3[i+2] = a3;
         a4 += w2 * z4;
         A4[i+2] = a4;
         a5 += w2 * z5;
         A5[i+2] = a5;
         a6 += w2 * z6;
         A6[i+2] = a6;
         a7 += w2 * z7;
         A7[i+2] = a7;
         a8 += w2 * z8;
         A8[i+2] = a8;
         a9 += w2 * z9;
         A9[i+2] = a9;
         a10 += w2 * z10;
         A10[i+2] = a10;
         a11 += w2 * z11;
         A11[i+2] = a11;
         a0 = A0[i+3];
         a0 += x3 * y0;
         a1 = A1[i+3];
         a1 += x3 * y1;
         a2 = A2[i+3];
         a2 += x3 * y2;
         a3 = A3[i+3];
         a3 += x3 * y3;
         a4 = A4[i+3];
         a4 += x3 * y4;
         a5 = A5[i+3];
         a5 += x3 * y5;
         a6 = A6[i+3];
         a6 += x3 * y6;
         a7 = A7[i+3];
         a7 += x3 * y7;
         a8 = A8[i+3];
         a8 += x3 * y8;
         a9 = A9[i+3];
         a9 += x3 * y9;
         a10 = A10[i+3];
         a10 += x3 * y10;
         a11 = A11[i+3];
         a11 += x3 * y11;
         a0 += w3 * z0;
         A0[i+3] = a0;
         a1 += w3 * z1;
         A1[i+3] = a1;
         a2 += w3 * z2;
         A2[i+3] = a2;
         a3 += w3 * z3;
         A3[i+3] = a3;
         a4 += w3 * z4;
         A4[i+3] = a4;
         a5 += w3 * z5;
         A5[i+3] = a5;
         a6 += w3 * z6;
         A6[i+3] = a6;
         a7 += w3 * z7;
         A7[i+3] = a7;
         a8 += w3 * z8;
         A8[i+3] = a8;
         a9 += w3 * z9;
         A9[i+3] = a9;
         a10 += w3 * z10;
         A10[i+3] = a10;
         a11 += w3 * z11;
         A11[i+3] = a11;
         a0 = A0[i+4];
         a0 += x4 * y0;
         a1 = A1[i+4];
         a1 += x4 * y1;
         a2 = A2[i+4];
         a2 += x4 * y2;
         a3 = A3[i+4];
         a3 += x4 * y3;
         a4 = A4[i+4];
         a4 += x4 * y4;
         a5 = A5[i+4];
         a5 += x4 * y5;
         a6 = A6[i+4];
         a6 += x4 * y6;
         a7 = A7[i+4];
         a7 += x4 * y7;
         a8 = A8[i+4];
         a8 += x4 * y8;
         a9 = A9[i+4];
         a9 += x4 * y9;
         a10 = A10[i+4];
         a10 += x4 * y10;
         a11 = A11[i+4];
         a11 += x4 * y11;
         a0 += w4 * z0;
         A0[i+4] = a0;
         a1 += w4 * z1;
         A1[i+4] = a1;
         a2 += w4 * z2;
         A2[i+4] = a2;
         a3 += w4 * z3;
         A3[i+4] = a3;
         a4 += w4 * z4;
         A4[i+4] = a4;
         a5 += w4 * z5;
         A5[i+4] = a5;
         a6 += w4 * z6;
         A6[i+4] = a6;
         a7 += w4 * z7;
         A7[i+4] = a7;
         a8 += w4 * z8;
         A8[i+4] = a8;
         a9 += w4 * z9;
         A9[i+4] = a9;
         a10 += w4 * z10;
         A10[i+4] = a10;
         a11 += w4 * z11;
         A11[i+4] = a11;
         a0 = A0[i+5];
         a0 += x5 * y0;
         a1 = A1[i+5];
         a1 += x5 * y1;
         a2 = A2[i+5];
         a2 += x5 * y2;
         a3 = A3[i+5];
         a3 += x5 * y3;
         a4 = A4[i+5];
         a4 += x5 * y4;
         a5 = A5[i+5];
         a5 += x5 * y5;
         a6 = A6[i+5];
         a6 += x5 * y6;
         a7 = A7[i+5];
         a7 += x5 * y7;
         a8 = A8[i+5];
         a8 += x5 * y8;
         a9 = A9[i+5];
         a9 += x5 * y9;
         a10 = A10[i+5];
         a10 += x5 * y10;
         a11 = A11[i+5];
         a11 += x5 * y11;
         a0 += w5 * z0;
         A0[i+5] = a0;
         a1 += w5 * z1;
         A1[i+5] = a1;
         a2 += w5 * z2;
         A2[i+5] = a2;
         a3 += w5 * z3;
         A3[i+5] = a3;
         a4 += w5 * z4;
         A4[i+5] = a4;
         a5 += w5 * z5;
         A5[i+5] = a5;
         a6 += w5 * z6;
         A6[i+5] = a6;
         a7 += w5 * z7;
         A7[i+5] = a7;
         a8 += w5 * z8;
         A8[i+5] = a8;
         a9 += w5 * z9;
         A9[i+5] = a9;
         a10 += w5 * z10;
         A10[i+5] = a10;
         a11 += w5 * z11;
         A11[i+5] = a11;
         a0 = A0[i+6];
         a0 += x6 * y0;
         a1 = A1[i+6];
         a1 += x6 * y1;
         a2 = A2[i+6];
         a2 += x6 * y2;
         a3 = A3[i+6];
         a3 += x6 * y3;
         a4 = A4[i+6];
         a4 += x6 * y4;
         a5 = A5[i+6];
         a5 += x6 * y5;
         a6 = A6[i+6];
         a6 += x6 * y6;
         a7 = A7[i+6];
         a7 += x6 * y7;
         a8 = A8[i+6];
         a8 += x6 * y8;
         a9 = A9[i+6];
         a9 += x6 * y9;
         a10 = A10[i+6];
         a10 += x6 * y10;
         a11 = A11[i+6];
         a11 += x6 * y11;
         a0 += w6 * z0;
         A0[i+6] = a0;
         a1 += w6 * z1;
         A1[i+6] = a1;
         a2 += w6 * z2;
         A2[i+6] = a2;
         a3 += w6 * z3;
         A3[i+6] = a3;
         a4 += w6 * z4;
         A4[i+6] = a4;
         a5 += w6 * z5;
         A5[i+6] = a5;
         a6 += w6 * z6;
         A6[i+6] = a6;
         a7 += w6 * z7;
         A7[i+6] = a7;
         a8 += w6 * z8;
         A8[i+6] = a8;
         a9 += w6 * z9;
         A9[i+6] = a9;
         a10 += w6 * z10;
         A10[i+6] = a10;
         a11 += w6 * z11;
         A11[i+6] = a11;
         a0 = A0[i+7];
         a0 += x7 * y0;
         a1 = A1[i+7];
         a1 += x7 * y1;
         a2 = A2[i+7];
         a2 += x7 * y2;
         a3 = A3[i+7];
         a3 += x7 * y3;
         a4 = A4[i+7];
         a4 += x7 * y4;
         a5 = A5[i+7];
         a5 += x7 * y5;
         a6 = A6[i+7];
         a6 += x7 * y6;
         a7 = A7[i+7];
         a7 += x7 * y7;
         a8 = A8[i+7];
         a8 += x7 * y8;
         a9 = A9[i+7];
         a9 += x7 * y9;
         a10 = A10[i+7];
         a10 += x7 * y10;
         a11 = A11[i+7];
         a11 += x7 * y11;
         a0 += w7 * z0;
         A0[i+7] = a0;
         a1 += w7 * z1;
         A1[i+7] = a1;
         a2 += w7 * z2;
         A2[i+7] = a2;
         a3 += w7 * z3;
         A3[i+7] = a3;
         a4 += w7 * z4;
         A4[i+7] = a4;
         a5 += w7 * z5;
         A5[i+7] = a5;
         a6 += w7 * z6;
         A6[i+7] = a6;
         a7 += w7 * z7;
         A7[i+7] = a7;
         a8 += w7 * z8;
         A8[i+7] = a8;
         a9 += w7 * z9;
         A9[i+7] = a9;
         a10 += w7 * z10;
         A10[i+7] = a10;
         a11 += w7 * z11;
         A11[i+7] = a11;

      }
      for (i=M8; i < M; i++)
      {
         const register double x0 = X[i], w0 = W[i];
         register double a0=A0[i], a1=A1[i], a2=A2[i], a3=A3[i], a4=A4[i],
                         a5=A5[i], a6=A6[i], a7=A7[i], a8=A8[i], a9=A9[i],
                         a10=A10[i], a11=A11[i];

         a0 += x0 * y0;
         a1 += x0 * y1;
         a2 += x0 * y2;
         a3 += x0 * y3;
         a4 += x0 * y4;
         a5 += x0 * y5;
         a6 += x0 * y6;
         a7 += x0 * y7;
         a8 += x0 * y8;
         a9 += x0 * y9;
         a10 += x0 * y10;
         a11 += x0 * y11;
         a0 += w0 * z0;
         A0[i] = a0;
         a1 += w0 * z1;
         A1[i] = a1;
         a2 += w0 * z2;
         A2[i] = a2;
         a3 += w0 * z3;
         A3[i] = a3;
         a4 += w0 * z4;
         A4[i] = a4;
         a5 += w0 * z5;
         A5[i] = a5;
         a6 += w0 * z6;
         A6[i] = a6;
         a7 += w0 * z7;
         A7[i] = a7;
         a8 += w0 * z8;
         A8[i] = a8;
         a9 += w0 * z9;
         A9[i] = a9;
         a10 += w0 * z10;
         A10[i] = a10;
         a11 += w0 * z11;
         A11[i] = a11;
      }
      Z += 12;
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N12; j; j--, A += lda, Y++)
   {
      double *A0=A;
      const register double y0=Y[0], z0=Z[0];
      ATL_INT i;
      prefY(Y+1+1-1);
      prefY(Z+1+1-1);
      for (i=0; i < M8; i += 8)
      {
         register double a0;
         const double x0=X[i+0], w0=W[i+0], x1=X[i+1], w1=W[i+1], x2=X[i+2],
                      w2=W[i+2], x3=X[i+3], w3=W[i+3], x4=X[i+4], w4=W[i+4],
                      x5=X[i+5], w5=W[i+5], x6=X[i+6], w6=W[i+6], x7=X[i+7],
                      w7=W[i+7];

         prefX(X);
         a0 = A0[i+0];
         a0 += x0 * y0;
         prefX(W);
         a0 += w0 * z0;
         prefA(A0);
         A0[i+0] = a0;
         a0 = A0[i+1];
         a0 += x1 * y0;
         a0 += w1 * z0;
         A0[i+1] = a0;
         a0 = A0[i+2];
         a0 += x2 * y0;
         a0 += w2 * z0;
         A0[i+2] = a0;
         a0 = A0[i+3];
         a0 += x3 * y0;
         a0 += w3 * z0;
         A0[i+3] = a0;
         a0 = A0[i+4];
         a0 += x4 * y0;
         a0 += w4 * z0;
         A0[i+4] = a0;
         a0 = A0[i+5];
         a0 += x5 * y0;
         a0 += w5 * z0;
         A0[i+5] = a0;
         a0 = A0[i+6];
         a0 += x6 * y0;
         a0 += w6 * z0;
         A0[i+6] = a0;
         a0 = A0[i+7];
         a0 += x7 * y0;
         a0 += w7 * z0;
         A0[i+7] = a0;

      }
      for (i=M8; i < M; i++)
      {
         const register double x0 = X[i], w0 = W[i];
         register double a0=A0[i];

         a0 += x0 * y0;
         a0 += w0 * z0;
         A0[i] = a0;
      }
      Z++;
   }
}
