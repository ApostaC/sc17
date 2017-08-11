#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 2
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
void ATL_UGEMV(ATL_CINT M0, ATL_CINT N, const TYPE *A, ATL_CINT lda0,
               const TYPE *X, TYPE *Y)
/*
 * 8x2 unrolled mvt_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N2=(N/2)*2, M=M0+M0, M8=((M0/8)*8)<<1,
            lda=lda0+lda0, lda2=lda*2;
   ATL_INT j;

   for (j=N2; j; j -= 2, A += lda2, Y += 4)
   {
      const float *A0=A, *A1=A0+lda;
      register float ry0=ATL_rzero, iy0=ATL_rzero, ry1=ATL_rzero,
                     iy1=ATL_rzero;
      ATL_INT i;
      prefY(Y+4+4-1);
      for (i=0; i < M8; i += 16)
      {
         const register float ra0_0=A0[i+0], ia0_0=A0[i+1], ra1_0=A0[i+2],
                              ia1_0=A0[i+3], ra2_0=A0[i+4], ia2_0=A0[i+5],
                              ra3_0=A0[i+6], ia3_0=A0[i+7], ra4_0=A0[i+8],
                              ia4_0=A0[i+9], ra5_0=A0[i+10], ia5_0=A0[i+11],
                              ra6_0=A0[i+12], ia6_0=A0[i+13], ra7_0=A0[i+14],
                              ia7_0=A0[i+15], ra0_1=A1[i+0], ia0_1=A1[i+1],
                              ra1_1=A1[i+2], ia1_1=A1[i+3], ra2_1=A1[i+4],
                              ia2_1=A1[i+5], ra3_1=A1[i+6], ia3_1=A1[i+7],
                              ra4_1=A1[i+8], ia4_1=A1[i+9], ra5_1=A1[i+10],
                              ia5_1=A1[i+11], ra6_1=A1[i+12], ia6_1=A1[i+13],
                              ra7_1=A1[i+14], ia7_1=A1[i+15];
         const register float rx0=X[i+0], ix0=X[i+1], rx1=X[i+2], ix1=X[i+3],
                              rx2=X[i+4], ix2=X[i+5], rx3=X[i+6], ix3=X[i+7],
                              rx4=X[i+8], ix4=X[i+9], rx5=X[i+10], ix5=X[i+11],
                              rx6=X[i+12], ix6=X[i+13], rx7=X[i+14],
                              ix7=X[i+15];

         prefX(X);
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry1 += ra0_1 * rx0;
         iy1 += ra0_1 * ix0;
         ry0 += ra1_0 * rx1;
         iy0 += ra1_0 * ix1;
         ry1 += ra1_1 * rx1;
         iy1 += ra1_1 * ix1;
         ry0 += ra2_0 * rx2;
         iy0 += ra2_0 * ix2;
         ry1 += ra2_1 * rx2;
         iy1 += ra2_1 * ix2;
         ry0 += ra3_0 * rx3;
         iy0 += ra3_0 * ix3;
         ry1 += ra3_1 * rx3;
         iy1 += ra3_1 * ix3;
         ry0 += ra4_0 * rx4;
         iy0 += ra4_0 * ix4;
         ry1 += ra4_1 * rx4;
         iy1 += ra4_1 * ix4;
         ry0 += ra5_0 * rx5;
         iy0 += ra5_0 * ix5;
         ry1 += ra5_1 * rx5;
         iy1 += ra5_1 * ix5;
         ry0 += ra6_0 * rx6;
         iy0 += ra6_0 * ix6;
         ry1 += ra6_1 * rx6;
         iy1 += ra6_1 * ix6;
         ry0 += ra7_0 * rx7;
         iy0 += ra7_0 * ix7;
         ry1 += ra7_1 * rx7;
         iy1 += ra7_1 * ix7;

         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         prefA(A0);
         ry1 -= ia0_1 * ix0;
         iy1 += ia0_1 * rx0;
         prefA(A1);
         ry0 -= ia1_0 * ix1;
         iy0 += ia1_0 * rx1;
         ry1 -= ia1_1 * ix1;
         iy1 += ia1_1 * rx1;
         ry0 -= ia2_0 * ix2;
         iy0 += ia2_0 * rx2;
         ry1 -= ia2_1 * ix2;
         iy1 += ia2_1 * rx2;
         ry0 -= ia3_0 * ix3;
         iy0 += ia3_0 * rx3;
         ry1 -= ia3_1 * ix3;
         iy1 += ia3_1 * rx3;
         ry0 -= ia4_0 * ix4;
         iy0 += ia4_0 * rx4;
         ry1 -= ia4_1 * ix4;
         iy1 += ia4_1 * rx4;
         ry0 -= ia5_0 * ix5;
         iy0 += ia5_0 * rx5;
         ry1 -= ia5_1 * ix5;
         iy1 += ia5_1 * rx5;
         ry0 -= ia6_0 * ix6;
         iy0 += ia6_0 * rx6;
         ry1 -= ia6_1 * ix6;
         iy1 += ia6_1 * rx6;
         ry0 -= ia7_0 * ix7;
         iy0 += ia7_0 * rx7;
         ry1 -= ia7_1 * ix7;
         iy1 += ia7_1 * rx7;
      }
      for (i=M8; i < M; i += 2)
      {
         const register float rx0 = X[i], ix0 = X[i+1];
         const register float ra0_0=A0[i], ia0_0=A0[i+1], ra0_1=A1[i],
                              ia0_1=A1[i+1];
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry1 += ra0_1 * rx0;
         iy1 += ra0_1 * ix0;
         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         ry1 -= ia0_1 * ix0;
         iy1 += ia0_1 * rx0;
      }
      #ifdef BETA0
         Y[0] = ry0;
         Y[1] = iy0;
         Y[2] = ry1;
         Y[3] = iy1;
      #else
         Y[0] += ry0;
         Y[1] += iy0;
         Y[2] += ry1;
         Y[3] += iy1;
      #endif
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N2; j; j--, A += lda, Y += 2)
   {
      const float *A0=A;
      register float ry0=ATL_rzero, iy0=ATL_rzero;
      ATL_INT i;
      prefY(Y+4+4-1);
      for (i=0; i < M8; i += 16)
      {
         const register float ra0_0=A0[i+0], ia0_0=A0[i+1], ra1_0=A0[i+2],
                              ia1_0=A0[i+3], ra2_0=A0[i+4], ia2_0=A0[i+5],
                              ra3_0=A0[i+6], ia3_0=A0[i+7], ra4_0=A0[i+8],
                              ia4_0=A0[i+9], ra5_0=A0[i+10], ia5_0=A0[i+11],
                              ra6_0=A0[i+12], ia6_0=A0[i+13], ra7_0=A0[i+14],
                              ia7_0=A0[i+15];
         const register float rx0=X[i+0], ix0=X[i+1], rx1=X[i+2], ix1=X[i+3],
                              rx2=X[i+4], ix2=X[i+5], rx3=X[i+6], ix3=X[i+7],
                              rx4=X[i+8], ix4=X[i+9], rx5=X[i+10], ix5=X[i+11],
                              rx6=X[i+12], ix6=X[i+13], rx7=X[i+14],
                              ix7=X[i+15];

         prefX(X);
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry0 += ra1_0 * rx1;
         iy0 += ra1_0 * ix1;
         ry0 += ra2_0 * rx2;
         iy0 += ra2_0 * ix2;
         ry0 += ra3_0 * rx3;
         iy0 += ra3_0 * ix3;
         ry0 += ra4_0 * rx4;
         iy0 += ra4_0 * ix4;
         ry0 += ra5_0 * rx5;
         iy0 += ra5_0 * ix5;
         ry0 += ra6_0 * rx6;
         iy0 += ra6_0 * ix6;
         ry0 += ra7_0 * rx7;
         iy0 += ra7_0 * ix7;

         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         prefA(A0);
         ry0 -= ia1_0 * ix1;
         iy0 += ia1_0 * rx1;
         ry0 -= ia2_0 * ix2;
         iy0 += ia2_0 * rx2;
         ry0 -= ia3_0 * ix3;
         iy0 += ia3_0 * rx3;
         ry0 -= ia4_0 * ix4;
         iy0 += ia4_0 * rx4;
         ry0 -= ia5_0 * ix5;
         iy0 += ia5_0 * rx5;
         ry0 -= ia6_0 * ix6;
         iy0 += ia6_0 * rx6;
         ry0 -= ia7_0 * ix7;
         iy0 += ia7_0 * rx7;
      }
      for (i=M8; i < M; i += 2)
      {
         const register float rx0 = X[i], ix0 = X[i+1];
         const register float ra0_0=A0[i], ia0_0=A0[i+1];
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
      }
      #ifdef BETA0
         Y[0] = ry0;
         Y[1] = iy0;
      #else
         Y[0] += ry0;
         Y[1] += iy0;
      #endif
   }
}
