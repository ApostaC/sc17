#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 1
#endif
#ifndef PFXDIST
   #define PFXDIST 256
#endif
#ifndef PFADIST
   #define PFADIST 256
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
void ATL_UGER2K(ATL_CINT M0, ATL_CINT N, const float *X, const float *Y, 
                const float *W, const float *Z, float *A, ATL_CINT lda0)
/*
 * 2x1 unrolled r2_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N1=(N/1)*1, M=M0+M0, M2=((M0/2)*2)<<1,
            lda=lda0+lda0, lda1=lda*1;
   ATL_INT j;

   for (j=N1; j; j -= 1, A += lda1, Y += 2)
   {
      float *A0=A;
      const register float ry0=Y[0], rz0=Z[0], iy0=Y[1], iz0=Z[1];
      ATL_INT i;
      prefY(Y+2+2-1);
      for (i=0; i < M2; i += 4)
      {
         register float ra00, ia00, ra10, ia10;
         const float rx0=X[i+0], rw0=W[i+0], ix0=X[i+1], iw0=W[i+1], rx1=X[i+2],
                     rw1=W[i+2], ix1=X[i+3], iw1=W[i+3];

         prefX(X);
         ra00 = A0[i+0];
         ia00 = A0[i+0+1];
         ra10 = A0[i+0+2];
         ia10 = A0[i+0+3];
         ra00 += rx0 * ry0;
         ia00 += rx0 * iy0;
         ra10 += rx1 * ry0;
         ia10 += rx1 * iy0;
         prefA(A0);
         ra00 -= ix0 * iy0;
         ia00 += ix0 * ry0;
         ra10 -= ix1 * iy0;
         ia10 += ix1 * ry0;
         prefX(W);
         ra00 += rw0 * rz0;
         ia00 += rw0 * iz0;
         ra10 += rw1 * rz0;
         ia10 += rw1 * iz0;
         ra00 -= iw0 * iz0;
         A0[i+0] = ra00;
         ia00 += iw0 * rz0;
         A0[i+0+1] = ia00;
         ra10 -= iw1 * iz0;
         A0[i+0+2] = ra10;
         ia10 += iw1 * rz0;
         A0[i+0+3] = ia10;

      }
      if (M != M2)
      {
         const float rx0 = X[i], ix0 = X[i+1], rw0 = W[i], iw0 = W[i+1];
         A0[i] += rx0 * ry0 - ix0 * iy0 + rw0 * rz0 - iw0 * iz0 ;
         A0[i+1] += ix0 * ry0 + rx0 * iy0 + iw0 * rz0 + rw0 * iz0;
      }
      Z += 2;
   }
}
