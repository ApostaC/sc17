#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 1
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
void ATL_UGER2K(ATL_CINT M, ATL_CINT N, const float *X, const float *Y, 
                const float *W, const float *Z, float *A, ATL_CINT lda)
/*
 * 16x1 unrolled r2_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N1=(N/1)*1, M16=(M/16)*16, lda1=lda*1;
   ATL_INT j;

   for (j=N1; j; j -= 1, A += lda1, Y += 1)
   {
      float *A0=A;
      const register float y0=Y[0], z0=Z[0];
      ATL_INT i;
      prefY(Y+1+1-1);
      prefY(Z+1+1-1);
      for (i=0; i < M16; i += 16)
      {
         register float a0;
         const float x0=X[i+0], w0=W[i+0], x1=X[i+1], w1=W[i+1], x2=X[i+2],
                     w2=W[i+2], x3=X[i+3], w3=W[i+3], x4=X[i+4], w4=W[i+4],
                     x5=X[i+5], w5=W[i+5], x6=X[i+6], w6=W[i+6], x7=X[i+7],
                     w7=W[i+7], x8=X[i+8], w8=W[i+8], x9=X[i+9], w9=W[i+9],
                     x10=X[i+10], w10=W[i+10], x11=X[i+11], w11=W[i+11],
                     x12=X[i+12], w12=W[i+12], x13=X[i+13], w13=W[i+13],
                     x14=X[i+14], w14=W[i+14], x15=X[i+15], w15=W[i+15];

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
         a0 = A0[i+8];
         a0 += x8 * y0;
         a0 += w8 * z0;
         A0[i+8] = a0;
         a0 = A0[i+9];
         a0 += x9 * y0;
         a0 += w9 * z0;
         A0[i+9] = a0;
         a0 = A0[i+10];
         a0 += x10 * y0;
         a0 += w10 * z0;
         A0[i+10] = a0;
         a0 = A0[i+11];
         a0 += x11 * y0;
         a0 += w11 * z0;
         A0[i+11] = a0;
         a0 = A0[i+12];
         a0 += x12 * y0;
         a0 += w12 * z0;
         A0[i+12] = a0;
         a0 = A0[i+13];
         a0 += x13 * y0;
         a0 += w13 * z0;
         A0[i+13] = a0;
         a0 = A0[i+14];
         a0 += x14 * y0;
         a0 += w14 * z0;
         A0[i+14] = a0;
         a0 = A0[i+15];
         a0 += x15 * y0;
         a0 += w15 * z0;
         A0[i+15] = a0;

      }
      for (i=M16; i < M; i++)
      {
         const register float x0 = X[i], w0 = W[i];
         register float a0=A0[i];

         a0 += x0 * y0;
         a0 += w0 * z0;
         A0[i] = a0;
      }
      Z += 1;
   }
}
