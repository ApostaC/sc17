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
void ATL_UGEMV(ATL_CINT M, ATL_CINT N, const TYPE *A, ATL_CINT lda,
               const TYPE *X, TYPE *Y)
/*
 * 16x12 unrolled mvt_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N12=(N/12)*12, M16=(M/16)*16, lda12=lda*12;
   ATL_INT j;

   for (j=N12; j; j -= 12, A += lda12, Y += 12)
   {
      const float *A0=A, *A1=A0+lda, *A2=A1+lda, *A3=A2+lda, *A4=A3+lda,
                  *A5=A4+lda, *A6=A5+lda, *A7=A6+lda, *A8=A7+lda, *A9=A8+lda,
                  *A10=A9+lda, *A11=A10+lda;
      register float y0=ATL_rzero, y1=ATL_rzero, y2=ATL_rzero, y3=ATL_rzero,
                     y4=ATL_rzero, y5=ATL_rzero, y6=ATL_rzero, y7=ATL_rzero,
                     y8=ATL_rzero, y9=ATL_rzero, y10=ATL_rzero, y11=ATL_rzero;
      ATL_INT i;
      prefY(Y+12+12-1);
      for (i=0; i < M16; i += 16)
      {
         const register float x0=X[i+0], x1=X[i+1], x2=X[i+2], x3=X[i+3],
                              x4=X[i+4], x5=X[i+5], x6=X[i+6], x7=X[i+7],
                              x8=X[i+8], x9=X[i+9], x10=X[i+10], x11=X[i+11],
                              x12=X[i+12], x13=X[i+13], x14=X[i+14],
                              x15=X[i+15];

         prefX(X);
         y0 += A0[i+0] * x0;
         prefA(A0);
         y1 += A1[i+0] * x0;
         prefA(A1);
         y2 += A2[i+0] * x0;
         prefA(A2);
         y3 += A3[i+0] * x0;
         prefA(A3);
         y4 += A4[i+0] * x0;
         prefA(A4);
         y5 += A5[i+0] * x0;
         prefA(A5);
         y6 += A6[i+0] * x0;
         prefA(A6);
         y7 += A7[i+0] * x0;
         prefA(A7);
         y8 += A8[i+0] * x0;
         prefA(A8);
         y9 += A9[i+0] * x0;
         prefA(A9);
         y10 += A10[i+0] * x0;
         prefA(A10);
         y11 += A11[i+0] * x0;
         prefA(A11);
         y0 += A0[i+1] * x1;
         y1 += A1[i+1] * x1;
         y2 += A2[i+1] * x1;
         y3 += A3[i+1] * x1;
         y4 += A4[i+1] * x1;
         y5 += A5[i+1] * x1;
         y6 += A6[i+1] * x1;
         y7 += A7[i+1] * x1;
         y8 += A8[i+1] * x1;
         y9 += A9[i+1] * x1;
         y10 += A10[i+1] * x1;
         y11 += A11[i+1] * x1;
         y0 += A0[i+2] * x2;
         y1 += A1[i+2] * x2;
         y2 += A2[i+2] * x2;
         y3 += A3[i+2] * x2;
         y4 += A4[i+2] * x2;
         y5 += A5[i+2] * x2;
         y6 += A6[i+2] * x2;
         y7 += A7[i+2] * x2;
         y8 += A8[i+2] * x2;
         y9 += A9[i+2] * x2;
         y10 += A10[i+2] * x2;
         y11 += A11[i+2] * x2;
         y0 += A0[i+3] * x3;
         y1 += A1[i+3] * x3;
         y2 += A2[i+3] * x3;
         y3 += A3[i+3] * x3;
         y4 += A4[i+3] * x3;
         y5 += A5[i+3] * x3;
         y6 += A6[i+3] * x3;
         y7 += A7[i+3] * x3;
         y8 += A8[i+3] * x3;
         y9 += A9[i+3] * x3;
         y10 += A10[i+3] * x3;
         y11 += A11[i+3] * x3;
         y0 += A0[i+4] * x4;
         y1 += A1[i+4] * x4;
         y2 += A2[i+4] * x4;
         y3 += A3[i+4] * x4;
         y4 += A4[i+4] * x4;
         y5 += A5[i+4] * x4;
         y6 += A6[i+4] * x4;
         y7 += A7[i+4] * x4;
         y8 += A8[i+4] * x4;
         y9 += A9[i+4] * x4;
         y10 += A10[i+4] * x4;
         y11 += A11[i+4] * x4;
         y0 += A0[i+5] * x5;
         y1 += A1[i+5] * x5;
         y2 += A2[i+5] * x5;
         y3 += A3[i+5] * x5;
         y4 += A4[i+5] * x5;
         y5 += A5[i+5] * x5;
         y6 += A6[i+5] * x5;
         y7 += A7[i+5] * x5;
         y8 += A8[i+5] * x5;
         y9 += A9[i+5] * x5;
         y10 += A10[i+5] * x5;
         y11 += A11[i+5] * x5;
         y0 += A0[i+6] * x6;
         y1 += A1[i+6] * x6;
         y2 += A2[i+6] * x6;
         y3 += A3[i+6] * x6;
         y4 += A4[i+6] * x6;
         y5 += A5[i+6] * x6;
         y6 += A6[i+6] * x6;
         y7 += A7[i+6] * x6;
         y8 += A8[i+6] * x6;
         y9 += A9[i+6] * x6;
         y10 += A10[i+6] * x6;
         y11 += A11[i+6] * x6;
         y0 += A0[i+7] * x7;
         y1 += A1[i+7] * x7;
         y2 += A2[i+7] * x7;
         y3 += A3[i+7] * x7;
         y4 += A4[i+7] * x7;
         y5 += A5[i+7] * x7;
         y6 += A6[i+7] * x7;
         y7 += A7[i+7] * x7;
         y8 += A8[i+7] * x7;
         y9 += A9[i+7] * x7;
         y10 += A10[i+7] * x7;
         y11 += A11[i+7] * x7;
         y0 += A0[i+8] * x8;
         y1 += A1[i+8] * x8;
         y2 += A2[i+8] * x8;
         y3 += A3[i+8] * x8;
         y4 += A4[i+8] * x8;
         y5 += A5[i+8] * x8;
         y6 += A6[i+8] * x8;
         y7 += A7[i+8] * x8;
         y8 += A8[i+8] * x8;
         y9 += A9[i+8] * x8;
         y10 += A10[i+8] * x8;
         y11 += A11[i+8] * x8;
         y0 += A0[i+9] * x9;
         y1 += A1[i+9] * x9;
         y2 += A2[i+9] * x9;
         y3 += A3[i+9] * x9;
         y4 += A4[i+9] * x9;
         y5 += A5[i+9] * x9;
         y6 += A6[i+9] * x9;
         y7 += A7[i+9] * x9;
         y8 += A8[i+9] * x9;
         y9 += A9[i+9] * x9;
         y10 += A10[i+9] * x9;
         y11 += A11[i+9] * x9;
         y0 += A0[i+10] * x10;
         y1 += A1[i+10] * x10;
         y2 += A2[i+10] * x10;
         y3 += A3[i+10] * x10;
         y4 += A4[i+10] * x10;
         y5 += A5[i+10] * x10;
         y6 += A6[i+10] * x10;
         y7 += A7[i+10] * x10;
         y8 += A8[i+10] * x10;
         y9 += A9[i+10] * x10;
         y10 += A10[i+10] * x10;
         y11 += A11[i+10] * x10;
         y0 += A0[i+11] * x11;
         y1 += A1[i+11] * x11;
         y2 += A2[i+11] * x11;
         y3 += A3[i+11] * x11;
         y4 += A4[i+11] * x11;
         y5 += A5[i+11] * x11;
         y6 += A6[i+11] * x11;
         y7 += A7[i+11] * x11;
         y8 += A8[i+11] * x11;
         y9 += A9[i+11] * x11;
         y10 += A10[i+11] * x11;
         y11 += A11[i+11] * x11;
         y0 += A0[i+12] * x12;
         y1 += A1[i+12] * x12;
         y2 += A2[i+12] * x12;
         y3 += A3[i+12] * x12;
         y4 += A4[i+12] * x12;
         y5 += A5[i+12] * x12;
         y6 += A6[i+12] * x12;
         y7 += A7[i+12] * x12;
         y8 += A8[i+12] * x12;
         y9 += A9[i+12] * x12;
         y10 += A10[i+12] * x12;
         y11 += A11[i+12] * x12;
         y0 += A0[i+13] * x13;
         y1 += A1[i+13] * x13;
         y2 += A2[i+13] * x13;
         y3 += A3[i+13] * x13;
         y4 += A4[i+13] * x13;
         y5 += A5[i+13] * x13;
         y6 += A6[i+13] * x13;
         y7 += A7[i+13] * x13;
         y8 += A8[i+13] * x13;
         y9 += A9[i+13] * x13;
         y10 += A10[i+13] * x13;
         y11 += A11[i+13] * x13;
         y0 += A0[i+14] * x14;
         y1 += A1[i+14] * x14;
         y2 += A2[i+14] * x14;
         y3 += A3[i+14] * x14;
         y4 += A4[i+14] * x14;
         y5 += A5[i+14] * x14;
         y6 += A6[i+14] * x14;
         y7 += A7[i+14] * x14;
         y8 += A8[i+14] * x14;
         y9 += A9[i+14] * x14;
         y10 += A10[i+14] * x14;
         y11 += A11[i+14] * x14;
         y0 += A0[i+15] * x15;
         y1 += A1[i+15] * x15;
         y2 += A2[i+15] * x15;
         y3 += A3[i+15] * x15;
         y4 += A4[i+15] * x15;
         y5 += A5[i+15] * x15;
         y6 += A6[i+15] * x15;
         y7 += A7[i+15] * x15;
         y8 += A8[i+15] * x15;
         y9 += A9[i+15] * x15;
         y10 += A10[i+15] * x15;
         y11 += A11[i+15] * x15;
      }
      for (i=M16; i < M; i++)
      {
         const register float x0 = X[i];
         y0 += A0[i] * x0;
         y1 += A1[i] * x0;
         y2 += A2[i] * x0;
         y3 += A3[i] * x0;
         y4 += A4[i] * x0;
         y5 += A5[i] * x0;
         y6 += A6[i] * x0;
         y7 += A7[i] * x0;
         y8 += A8[i] * x0;
         y9 += A9[i] * x0;
         y10 += A10[i] * x0;
         y11 += A11[i] * x0;
      }
      #ifdef BETA0
         Y[0] = y0;
         Y[1] = y1;
         Y[2] = y2;
         Y[3] = y3;
         Y[4] = y4;
         Y[5] = y5;
         Y[6] = y6;
         Y[7] = y7;
         Y[8] = y8;
         Y[9] = y9;
         Y[10] = y10;
         Y[11] = y11;
      #else
         Y[0] += y0;
         Y[1] += y1;
         Y[2] += y2;
         Y[3] += y3;
         Y[4] += y4;
         Y[5] += y5;
         Y[6] += y6;
         Y[7] += y7;
         Y[8] += y8;
         Y[9] += y9;
         Y[10] += y10;
         Y[11] += y11;
      #endif
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N12; j; j--, A += lda, Y++)
   {
      const float *A0=A;
      register float y0=ATL_rzero;
      ATL_INT i;
      prefY(Y+1+1-1);
      for (i=0; i < M16; i += 16)
      {
         const register float x0=X[i+0], x1=X[i+1], x2=X[i+2], x3=X[i+3],
                              x4=X[i+4], x5=X[i+5], x6=X[i+6], x7=X[i+7],
                              x8=X[i+8], x9=X[i+9], x10=X[i+10], x11=X[i+11],
                              x12=X[i+12], x13=X[i+13], x14=X[i+14],
                              x15=X[i+15];

         prefX(X);
         y0 += A0[i+0] * x0;
         prefA(A0);
         y0 += A0[i+1] * x1;
         y0 += A0[i+2] * x2;
         y0 += A0[i+3] * x3;
         y0 += A0[i+4] * x4;
         y0 += A0[i+5] * x5;
         y0 += A0[i+6] * x6;
         y0 += A0[i+7] * x7;
         y0 += A0[i+8] * x8;
         y0 += A0[i+9] * x9;
         y0 += A0[i+10] * x10;
         y0 += A0[i+11] * x11;
         y0 += A0[i+12] * x12;
         y0 += A0[i+13] * x13;
         y0 += A0[i+14] * x14;
         y0 += A0[i+15] * x15;
      }
      for (i=M16; i < M; i++)
      {
         const register float x0 = X[i];
         y0 += A0[i] * x0;
      }
      #ifdef BETA0
         Y[0] = y0;
      #else
         Y[0] += y0;
      #endif
   }
}
