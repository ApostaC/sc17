#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 4
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
 * 4x4 unrolled mvt_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N4=(N/4)*4, M=M0+M0, M4=((M0/4)*4)<<1,
            lda=lda0+lda0, lda4=lda*4;
   ATL_INT j;

   for (j=N4; j; j -= 4, A += lda4, Y += 8)
   {
      const double *A0=A, *A1=A0+lda, *A2=A1+lda, *A3=A2+lda;
      register double ry0=ATL_rzero, iy0=ATL_rzero, ry1=ATL_rzero,
                      iy1=ATL_rzero, ry2=ATL_rzero, iy2=ATL_rzero,
                      ry3=ATL_rzero, iy3=ATL_rzero;
      ATL_INT i;
      prefY(Y+8+8-1);
      for (i=0; i < M4; i += 8)
      {
         const register double ra0_0=A0[i+0], ia0_0=A0[i+1], ra1_0=A0[i+2],
                               ia1_0=A0[i+3], ra2_0=A0[i+4], ia2_0=A0[i+5],
                               ra3_0=A0[i+6], ia3_0=A0[i+7], ra0_1=A1[i+0],
                               ia0_1=A1[i+1], ra1_1=A1[i+2], ia1_1=A1[i+3],
                               ra2_1=A1[i+4], ia2_1=A1[i+5], ra3_1=A1[i+6],
                               ia3_1=A1[i+7], ra0_2=A2[i+0], ia0_2=A2[i+1],
                               ra1_2=A2[i+2], ia1_2=A2[i+3], ra2_2=A2[i+4],
                               ia2_2=A2[i+5], ra3_2=A2[i+6], ia3_2=A2[i+7],
                               ra0_3=A3[i+0], ia0_3=A3[i+1], ra1_3=A3[i+2],
                               ia1_3=A3[i+3], ra2_3=A3[i+4], ia2_3=A3[i+5],
                               ra3_3=A3[i+6], ia3_3=A3[i+7];
         const register double rx0=X[i+0], ix0=X[i+1], rx1=X[i+2], ix1=X[i+3],
                               rx2=X[i+4], ix2=X[i+5], rx3=X[i+6], ix3=X[i+7];

         prefX(X);
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry1 += ra0_1 * rx0;
         iy1 += ra0_1 * ix0;
         ry2 += ra0_2 * rx0;
         iy2 += ra0_2 * ix0;
         ry3 += ra0_3 * rx0;
         iy3 += ra0_3 * ix0;
         ry0 += ra1_0 * rx1;
         iy0 += ra1_0 * ix1;
         ry1 += ra1_1 * rx1;
         iy1 += ra1_1 * ix1;
         ry2 += ra1_2 * rx1;
         iy2 += ra1_2 * ix1;
         ry3 += ra1_3 * rx1;
         iy3 += ra1_3 * ix1;
         ry0 += ra2_0 * rx2;
         iy0 += ra2_0 * ix2;
         ry1 += ra2_1 * rx2;
         iy1 += ra2_1 * ix2;
         ry2 += ra2_2 * rx2;
         iy2 += ra2_2 * ix2;
         ry3 += ra2_3 * rx2;
         iy3 += ra2_3 * ix2;
         ry0 += ra3_0 * rx3;
         iy0 += ra3_0 * ix3;
         ry1 += ra3_1 * rx3;
         iy1 += ra3_1 * ix3;
         ry2 += ra3_2 * rx3;
         iy2 += ra3_2 * ix3;
         ry3 += ra3_3 * rx3;
         iy3 += ra3_3 * ix3;

         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         prefA(A0);
         ry1 -= ia0_1 * ix0;
         iy1 += ia0_1 * rx0;
         prefA(A1);
         ry2 -= ia0_2 * ix0;
         iy2 += ia0_2 * rx0;
         prefA(A2);
         ry3 -= ia0_3 * ix0;
         iy3 += ia0_3 * rx0;
         prefA(A3);
         ry0 -= ia1_0 * ix1;
         iy0 += ia1_0 * rx1;
         ry1 -= ia1_1 * ix1;
         iy1 += ia1_1 * rx1;
         ry2 -= ia1_2 * ix1;
         iy2 += ia1_2 * rx1;
         ry3 -= ia1_3 * ix1;
         iy3 += ia1_3 * rx1;
         ry0 -= ia2_0 * ix2;
         iy0 += ia2_0 * rx2;
         ry1 -= ia2_1 * ix2;
         iy1 += ia2_1 * rx2;
         ry2 -= ia2_2 * ix2;
         iy2 += ia2_2 * rx2;
         ry3 -= ia2_3 * ix2;
         iy3 += ia2_3 * rx2;
         ry0 -= ia3_0 * ix3;
         iy0 += ia3_0 * rx3;
         ry1 -= ia3_1 * ix3;
         iy1 += ia3_1 * rx3;
         ry2 -= ia3_2 * ix3;
         iy2 += ia3_2 * rx3;
         ry3 -= ia3_3 * ix3;
         iy3 += ia3_3 * rx3;
      }
      for (i=M4; i < M; i += 2)
      {
         const register double rx0 = X[i], ix0 = X[i+1];
         const register double ra0_0=A0[i], ia0_0=A0[i+1], ra0_1=A1[i],
                               ia0_1=A1[i+1], ra0_2=A2[i], ia0_2=A2[i+1],
                               ra0_3=A3[i], ia0_3=A3[i+1];
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry1 += ra0_1 * rx0;
         iy1 += ra0_1 * ix0;
         ry2 += ra0_2 * rx0;
         iy2 += ra0_2 * ix0;
         ry3 += ra0_3 * rx0;
         iy3 += ra0_3 * ix0;
         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         ry1 -= ia0_1 * ix0;
         iy1 += ia0_1 * rx0;
         ry2 -= ia0_2 * ix0;
         iy2 += ia0_2 * rx0;
         ry3 -= ia0_3 * ix0;
         iy3 += ia0_3 * rx0;
      }
      #ifdef BETA0
         Y[0] = ry0;
         Y[1] = iy0;
         Y[2] = ry1;
         Y[3] = iy1;
         Y[4] = ry2;
         Y[5] = iy2;
         Y[6] = ry3;
         Y[7] = iy3;
      #else
         Y[0] += ry0;
         Y[1] += iy0;
         Y[2] += ry1;
         Y[3] += iy1;
         Y[4] += ry2;
         Y[5] += iy2;
         Y[6] += ry3;
         Y[7] += iy3;
      #endif
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N4; j; j--, A += lda, Y += 2)
   {
      const double *A0=A;
      register double ry0=ATL_rzero, iy0=ATL_rzero;
      ATL_INT i;
      prefY(Y+8+8-1);
      for (i=0; i < M4; i += 8)
      {
         const register double ra0_0=A0[i+0], ia0_0=A0[i+1], ra1_0=A0[i+2],
                               ia1_0=A0[i+3], ra2_0=A0[i+4], ia2_0=A0[i+5],
                               ra3_0=A0[i+6], ia3_0=A0[i+7];
         const register double rx0=X[i+0], ix0=X[i+1], rx1=X[i+2], ix1=X[i+3],
                               rx2=X[i+4], ix2=X[i+5], rx3=X[i+6], ix3=X[i+7];

         prefX(X);
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry0 += ra1_0 * rx1;
         iy0 += ra1_0 * ix1;
         ry0 += ra2_0 * rx2;
         iy0 += ra2_0 * ix2;
         ry0 += ra3_0 * rx3;
         iy0 += ra3_0 * ix3;

         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         prefA(A0);
         ry0 -= ia1_0 * ix1;
         iy0 += ia1_0 * rx1;
         ry0 -= ia2_0 * ix2;
         iy0 += ia2_0 * rx2;
         ry0 -= ia3_0 * ix3;
         iy0 += ia3_0 * rx3;
      }
      for (i=M4; i < M; i += 2)
      {
         const register double rx0 = X[i], ix0 = X[i+1];
         const register double ra0_0=A0[i], ia0_0=A0[i+1];
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
