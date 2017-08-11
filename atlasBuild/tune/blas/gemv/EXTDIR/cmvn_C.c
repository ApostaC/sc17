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
/* Need to handle BETA=0 case by assigning y to zero outside of loop */
void ATL_UGEMV(ATL_CINT M0, ATL_CINT N, const TYPE *A, ATL_CINT lda0,
               const TYPE *X, TYPE *Y)
/*
 * 8x1 unrolled mvn_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N1=(N/1)*1, M=M0+M0, M8=((M0/8)*8)<<1,
            lda=lda0+lda0, lda1=lda*1;
   ATL_INT j;

   #ifdef BETA0
      for (j=0; j < M; j++)
         Y[j] = ATL_rzero;
   #endif
   for (j=N1; j; j -= 1, A += lda1, X += 2)
   {
      const float *A0=A;
      register float rx0=X[0], ix0=X[1];
      ATL_INT i;
      prefY(X+2+2-1);
      for (i=0; i < M8; i += 16)
      {
         const float ra0_0=A0[i+0], ia0_0=A0[i+1], ra1_0=A0[i+2], ia1_0=A0[i+3],
                     ra2_0=A0[i+4], ia2_0=A0[i+5], ra3_0=A0[i+6], ia3_0=A0[i+7],
                     ra4_0=A0[i+8], ia4_0=A0[i+9], ra5_0=A0[i+10],
                     ia5_0=A0[i+11], ra6_0=A0[i+12], ia6_0=A0[i+13],
                     ra7_0=A0[i+14], ia7_0=A0[i+15];
         register float ry0=Y[i+0], iy0=Y[i+1], ry1=Y[i+2], iy1=Y[i+3],
                        ry2=Y[i+4], iy2=Y[i+5], ry3=Y[i+6], iy3=Y[i+7],
                        ry4=Y[i+8], iy4=Y[i+9], ry5=Y[i+10], iy5=Y[i+11],
                        ry6=Y[i+12], iy6=Y[i+13], ry7=Y[i+14], iy7=Y[i+15];

         prefY(Y);
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry1 += ra1_0 * rx0;
         iy1 += ra1_0 * ix0;
         ry2 += ra2_0 * rx0;
         iy2 += ra2_0 * ix0;
         ry3 += ra3_0 * rx0;
         iy3 += ra3_0 * ix0;
         ry4 += ra4_0 * rx0;
         iy4 += ra4_0 * ix0;
         ry5 += ra5_0 * rx0;
         iy5 += ra5_0 * ix0;
         ry6 += ra6_0 * rx0;
         iy6 += ra6_0 * ix0;
         ry7 += ra7_0 * rx0;
         iy7 += ra7_0 * ix0;
         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         prefA(A0);
         ry1 -= ia1_0 * ix0;
         iy1 += ia1_0 * rx0;
         ry2 -= ia2_0 * ix0;
         iy2 += ia2_0 * rx0;
         ry3 -= ia3_0 * ix0;
         iy3 += ia3_0 * rx0;
         ry4 -= ia4_0 * ix0;
         iy4 += ia4_0 * rx0;
         ry5 -= ia5_0 * ix0;
         iy5 += ia5_0 * rx0;
         ry6 -= ia6_0 * ix0;
         iy6 += ia6_0 * rx0;
         ry7 -= ia7_0 * ix0;
         iy7 += ia7_0 * rx0;


         Y[i+0] = ry0;
         Y[i+1] = iy0;
         Y[i+2] = ry1;
         Y[i+3] = iy1;
         Y[i+4] = ry2;
         Y[i+5] = iy2;
         Y[i+6] = ry3;
         Y[i+7] = iy3;
         Y[i+8] = ry4;
         Y[i+9] = iy4;
         Y[i+10] = ry5;
         Y[i+11] = iy5;
         Y[i+12] = ry6;
         Y[i+13] = iy6;
         Y[i+14] = ry7;
         Y[i+15] = iy7;
      }
      for (i=M8; i < M; i += 2)
      {
         register float ry0 = Y[i], iy0 = Y[i+1];
         const float ra0_0=A0[i], ia0_0=A0[i+1];
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         Y[i] = ry0;
         Y[i+1] = iy0;
      }
   }
}
