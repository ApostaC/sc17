#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 20
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
/* Need to handle BETA=0 case by assigning y to zero outside of loop */
void ATL_UGEMV(ATL_CINT M, ATL_CINT N, const TYPE *A, ATL_CINT lda,
               const TYPE *X, TYPE *Y)
/*
 * 16x20 unrolled mvn_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N20=(N/20)*20, M16=(M/16)*16, lda20=lda*20;
   ATL_INT j;

   #ifdef BETA0
      for (j=0; j < M; j++)
         Y[j] = ATL_rzero;
   #endif
   for (j=N20; j; j -= 20, A += lda20, X += 20)
   {
      const float *A0=A, *A1=A0+lda, *A2=A1+lda, *A3=A2+lda, *A4=A3+lda,
                  *A5=A4+lda, *A6=A5+lda, *A7=A6+lda, *A8=A7+lda, *A9=A8+lda,
                  *A10=A9+lda, *A11=A10+lda, *A12=A11+lda, *A13=A12+lda,
                  *A14=A13+lda, *A15=A14+lda, *A16=A15+lda, *A17=A16+lda,
                  *A18=A17+lda, *A19=A18+lda;
      const register float x0=X[0], x1=X[1], x2=X[2], x3=X[3], x4=X[4], x5=X[5],
                           x6=X[6], x7=X[7], x8=X[8], x9=X[9], x10=X[10],
                           x11=X[11], x12=X[12], x13=X[13], x14=X[14],
                           x15=X[15], x16=X[16], x17=X[17], x18=X[18],
                           x19=X[19];
      ATL_INT i;
      prefY(Y+20+20-1);
      for (i=0; i < M16; i += 16)
      {
         const float a0_0=A0[i+0], a1_0=A0[i+1], a2_0=A0[i+2], a3_0=A0[i+3],
                     a4_0=A0[i+4], a5_0=A0[i+5], a6_0=A0[i+6], a7_0=A0[i+7],
                     a8_0=A0[i+8], a9_0=A0[i+9], a10_0=A0[i+10], a11_0=A0[i+11],
                     a12_0=A0[i+12], a13_0=A0[i+13], a14_0=A0[i+14],
                     a15_0=A0[i+15], a0_1=A1[i+0], a1_1=A1[i+1], a2_1=A1[i+2],
                     a3_1=A1[i+3], a4_1=A1[i+4], a5_1=A1[i+5], a6_1=A1[i+6],
                     a7_1=A1[i+7], a8_1=A1[i+8], a9_1=A1[i+9], a10_1=A1[i+10],
                     a11_1=A1[i+11], a12_1=A1[i+12], a13_1=A1[i+13],
                     a14_1=A1[i+14], a15_1=A1[i+15], a0_2=A2[i+0], a1_2=A2[i+1],
                     a2_2=A2[i+2], a3_2=A2[i+3], a4_2=A2[i+4], a5_2=A2[i+5],
                     a6_2=A2[i+6], a7_2=A2[i+7], a8_2=A2[i+8], a9_2=A2[i+9],
                     a10_2=A2[i+10], a11_2=A2[i+11], a12_2=A2[i+12],
                     a13_2=A2[i+13], a14_2=A2[i+14], a15_2=A2[i+15],
                     a0_3=A3[i+0], a1_3=A3[i+1], a2_3=A3[i+2], a3_3=A3[i+3],
                     a4_3=A3[i+4], a5_3=A3[i+5], a6_3=A3[i+6], a7_3=A3[i+7],
                     a8_3=A3[i+8], a9_3=A3[i+9], a10_3=A3[i+10], a11_3=A3[i+11],
                     a12_3=A3[i+12], a13_3=A3[i+13], a14_3=A3[i+14],
                     a15_3=A3[i+15], a0_4=A4[i+0], a1_4=A4[i+1], a2_4=A4[i+2],
                     a3_4=A4[i+3], a4_4=A4[i+4], a5_4=A4[i+5], a6_4=A4[i+6],
                     a7_4=A4[i+7], a8_4=A4[i+8], a9_4=A4[i+9], a10_4=A4[i+10],
                     a11_4=A4[i+11], a12_4=A4[i+12], a13_4=A4[i+13],
                     a14_4=A4[i+14], a15_4=A4[i+15], a0_5=A5[i+0], a1_5=A5[i+1],
                     a2_5=A5[i+2], a3_5=A5[i+3], a4_5=A5[i+4], a5_5=A5[i+5],
                     a6_5=A5[i+6], a7_5=A5[i+7], a8_5=A5[i+8], a9_5=A5[i+9],
                     a10_5=A5[i+10], a11_5=A5[i+11], a12_5=A5[i+12],
                     a13_5=A5[i+13], a14_5=A5[i+14], a15_5=A5[i+15],
                     a0_6=A6[i+0], a1_6=A6[i+1], a2_6=A6[i+2], a3_6=A6[i+3],
                     a4_6=A6[i+4], a5_6=A6[i+5], a6_6=A6[i+6], a7_6=A6[i+7],
                     a8_6=A6[i+8], a9_6=A6[i+9], a10_6=A6[i+10], a11_6=A6[i+11],
                     a12_6=A6[i+12], a13_6=A6[i+13], a14_6=A6[i+14],
                     a15_6=A6[i+15], a0_7=A7[i+0], a1_7=A7[i+1], a2_7=A7[i+2],
                     a3_7=A7[i+3], a4_7=A7[i+4], a5_7=A7[i+5], a6_7=A7[i+6],
                     a7_7=A7[i+7], a8_7=A7[i+8], a9_7=A7[i+9], a10_7=A7[i+10],
                     a11_7=A7[i+11], a12_7=A7[i+12], a13_7=A7[i+13],
                     a14_7=A7[i+14], a15_7=A7[i+15], a0_8=A8[i+0], a1_8=A8[i+1],
                     a2_8=A8[i+2], a3_8=A8[i+3], a4_8=A8[i+4], a5_8=A8[i+5],
                     a6_8=A8[i+6], a7_8=A8[i+7], a8_8=A8[i+8], a9_8=A8[i+9],
                     a10_8=A8[i+10], a11_8=A8[i+11], a12_8=A8[i+12],
                     a13_8=A8[i+13], a14_8=A8[i+14], a15_8=A8[i+15],
                     a0_9=A9[i+0], a1_9=A9[i+1], a2_9=A9[i+2], a3_9=A9[i+3],
                     a4_9=A9[i+4], a5_9=A9[i+5], a6_9=A9[i+6], a7_9=A9[i+7],
                     a8_9=A9[i+8], a9_9=A9[i+9], a10_9=A9[i+10], a11_9=A9[i+11],
                     a12_9=A9[i+12], a13_9=A9[i+13], a14_9=A9[i+14],
                     a15_9=A9[i+15], a0_10=A10[i+0], a1_10=A10[i+1],
                     a2_10=A10[i+2], a3_10=A10[i+3], a4_10=A10[i+4],
                     a5_10=A10[i+5], a6_10=A10[i+6], a7_10=A10[i+7],
                     a8_10=A10[i+8], a9_10=A10[i+9], a10_10=A10[i+10],
                     a11_10=A10[i+11], a12_10=A10[i+12], a13_10=A10[i+13],
                     a14_10=A10[i+14], a15_10=A10[i+15], a0_11=A11[i+0],
                     a1_11=A11[i+1], a2_11=A11[i+2], a3_11=A11[i+3],
                     a4_11=A11[i+4], a5_11=A11[i+5], a6_11=A11[i+6],
                     a7_11=A11[i+7], a8_11=A11[i+8], a9_11=A11[i+9],
                     a10_11=A11[i+10], a11_11=A11[i+11], a12_11=A11[i+12],
                     a13_11=A11[i+13], a14_11=A11[i+14], a15_11=A11[i+15],
                     a0_12=A12[i+0], a1_12=A12[i+1], a2_12=A12[i+2],
                     a3_12=A12[i+3], a4_12=A12[i+4], a5_12=A12[i+5],
                     a6_12=A12[i+6], a7_12=A12[i+7], a8_12=A12[i+8],
                     a9_12=A12[i+9], a10_12=A12[i+10], a11_12=A12[i+11],
                     a12_12=A12[i+12], a13_12=A12[i+13], a14_12=A12[i+14],
                     a15_12=A12[i+15], a0_13=A13[i+0], a1_13=A13[i+1],
                     a2_13=A13[i+2], a3_13=A13[i+3], a4_13=A13[i+4],
                     a5_13=A13[i+5], a6_13=A13[i+6], a7_13=A13[i+7],
                     a8_13=A13[i+8], a9_13=A13[i+9], a10_13=A13[i+10],
                     a11_13=A13[i+11], a12_13=A13[i+12], a13_13=A13[i+13],
                     a14_13=A13[i+14], a15_13=A13[i+15], a0_14=A14[i+0],
                     a1_14=A14[i+1], a2_14=A14[i+2], a3_14=A14[i+3],
                     a4_14=A14[i+4], a5_14=A14[i+5], a6_14=A14[i+6],
                     a7_14=A14[i+7], a8_14=A14[i+8], a9_14=A14[i+9],
                     a10_14=A14[i+10], a11_14=A14[i+11], a12_14=A14[i+12],
                     a13_14=A14[i+13], a14_14=A14[i+14], a15_14=A14[i+15],
                     a0_15=A15[i+0], a1_15=A15[i+1], a2_15=A15[i+2],
                     a3_15=A15[i+3], a4_15=A15[i+4], a5_15=A15[i+5],
                     a6_15=A15[i+6], a7_15=A15[i+7], a8_15=A15[i+8],
                     a9_15=A15[i+9], a10_15=A15[i+10], a11_15=A15[i+11],
                     a12_15=A15[i+12], a13_15=A15[i+13], a14_15=A15[i+14],
                     a15_15=A15[i+15], a0_16=A16[i+0], a1_16=A16[i+1],
                     a2_16=A16[i+2], a3_16=A16[i+3], a4_16=A16[i+4],
                     a5_16=A16[i+5], a6_16=A16[i+6], a7_16=A16[i+7],
                     a8_16=A16[i+8], a9_16=A16[i+9], a10_16=A16[i+10],
                     a11_16=A16[i+11], a12_16=A16[i+12], a13_16=A16[i+13],
                     a14_16=A16[i+14], a15_16=A16[i+15], a0_17=A17[i+0],
                     a1_17=A17[i+1], a2_17=A17[i+2], a3_17=A17[i+3],
                     a4_17=A17[i+4], a5_17=A17[i+5], a6_17=A17[i+6],
                     a7_17=A17[i+7], a8_17=A17[i+8], a9_17=A17[i+9],
                     a10_17=A17[i+10], a11_17=A17[i+11], a12_17=A17[i+12],
                     a13_17=A17[i+13], a14_17=A17[i+14], a15_17=A17[i+15],
                     a0_18=A18[i+0], a1_18=A18[i+1], a2_18=A18[i+2],
                     a3_18=A18[i+3], a4_18=A18[i+4], a5_18=A18[i+5],
                     a6_18=A18[i+6], a7_18=A18[i+7], a8_18=A18[i+8],
                     a9_18=A18[i+9], a10_18=A18[i+10], a11_18=A18[i+11],
                     a12_18=A18[i+12], a13_18=A18[i+13], a14_18=A18[i+14],
                     a15_18=A18[i+15], a0_19=A19[i+0], a1_19=A19[i+1],
                     a2_19=A19[i+2], a3_19=A19[i+3], a4_19=A19[i+4],
                     a5_19=A19[i+5], a6_19=A19[i+6], a7_19=A19[i+7],
                     a8_19=A19[i+8], a9_19=A19[i+9], a10_19=A19[i+10],
                     a11_19=A19[i+11], a12_19=A19[i+12], a13_19=A19[i+13],
                     a14_19=A19[i+14], a15_19=A19[i+15];
         register float y0=Y[i+0], y1=Y[i+1], y2=Y[i+2], y3=Y[i+3], y4=Y[i+4],
                        y5=Y[i+5], y6=Y[i+6], y7=Y[i+7], y8=Y[i+8], y9=Y[i+9],
                        y10=Y[i+10], y11=Y[i+11], y12=Y[i+12], y13=Y[i+13],
                        y14=Y[i+14], y15=Y[i+15];

         prefX(X);
         y0 += a0_0 * x0;
         prefA(A0);
         y1 += a1_0 * x0;
         y2 += a2_0 * x0;
         y3 += a3_0 * x0;
         y4 += a4_0 * x0;
         y5 += a5_0 * x0;
         y6 += a6_0 * x0;
         y7 += a7_0 * x0;
         y8 += a8_0 * x0;
         y9 += a9_0 * x0;
         y10 += a10_0 * x0;
         y11 += a11_0 * x0;
         y12 += a12_0 * x0;
         y13 += a13_0 * x0;
         y14 += a14_0 * x0;
         y15 += a15_0 * x0;
         y0 += a0_1 * x1;
         prefA(A1);
         y1 += a1_1 * x1;
         y2 += a2_1 * x1;
         y3 += a3_1 * x1;
         y4 += a4_1 * x1;
         y5 += a5_1 * x1;
         y6 += a6_1 * x1;
         y7 += a7_1 * x1;
         y8 += a8_1 * x1;
         y9 += a9_1 * x1;
         y10 += a10_1 * x1;
         y11 += a11_1 * x1;
         y12 += a12_1 * x1;
         y13 += a13_1 * x1;
         y14 += a14_1 * x1;
         y15 += a15_1 * x1;
         y0 += a0_2 * x2;
         prefA(A2);
         y1 += a1_2 * x2;
         y2 += a2_2 * x2;
         y3 += a3_2 * x2;
         y4 += a4_2 * x2;
         y5 += a5_2 * x2;
         y6 += a6_2 * x2;
         y7 += a7_2 * x2;
         y8 += a8_2 * x2;
         y9 += a9_2 * x2;
         y10 += a10_2 * x2;
         y11 += a11_2 * x2;
         y12 += a12_2 * x2;
         y13 += a13_2 * x2;
         y14 += a14_2 * x2;
         y15 += a15_2 * x2;
         y0 += a0_3 * x3;
         prefA(A3);
         y1 += a1_3 * x3;
         y2 += a2_3 * x3;
         y3 += a3_3 * x3;
         y4 += a4_3 * x3;
         y5 += a5_3 * x3;
         y6 += a6_3 * x3;
         y7 += a7_3 * x3;
         y8 += a8_3 * x3;
         y9 += a9_3 * x3;
         y10 += a10_3 * x3;
         y11 += a11_3 * x3;
         y12 += a12_3 * x3;
         y13 += a13_3 * x3;
         y14 += a14_3 * x3;
         y15 += a15_3 * x3;
         y0 += a0_4 * x4;
         prefA(A4);
         y1 += a1_4 * x4;
         y2 += a2_4 * x4;
         y3 += a3_4 * x4;
         y4 += a4_4 * x4;
         y5 += a5_4 * x4;
         y6 += a6_4 * x4;
         y7 += a7_4 * x4;
         y8 += a8_4 * x4;
         y9 += a9_4 * x4;
         y10 += a10_4 * x4;
         y11 += a11_4 * x4;
         y12 += a12_4 * x4;
         y13 += a13_4 * x4;
         y14 += a14_4 * x4;
         y15 += a15_4 * x4;
         y0 += a0_5 * x5;
         prefA(A5);
         y1 += a1_5 * x5;
         y2 += a2_5 * x5;
         y3 += a3_5 * x5;
         y4 += a4_5 * x5;
         y5 += a5_5 * x5;
         y6 += a6_5 * x5;
         y7 += a7_5 * x5;
         y8 += a8_5 * x5;
         y9 += a9_5 * x5;
         y10 += a10_5 * x5;
         y11 += a11_5 * x5;
         y12 += a12_5 * x5;
         y13 += a13_5 * x5;
         y14 += a14_5 * x5;
         y15 += a15_5 * x5;
         y0 += a0_6 * x6;
         prefA(A6);
         y1 += a1_6 * x6;
         y2 += a2_6 * x6;
         y3 += a3_6 * x6;
         y4 += a4_6 * x6;
         y5 += a5_6 * x6;
         y6 += a6_6 * x6;
         y7 += a7_6 * x6;
         y8 += a8_6 * x6;
         y9 += a9_6 * x6;
         y10 += a10_6 * x6;
         y11 += a11_6 * x6;
         y12 += a12_6 * x6;
         y13 += a13_6 * x6;
         y14 += a14_6 * x6;
         y15 += a15_6 * x6;
         y0 += a0_7 * x7;
         prefA(A7);
         y1 += a1_7 * x7;
         y2 += a2_7 * x7;
         y3 += a3_7 * x7;
         y4 += a4_7 * x7;
         y5 += a5_7 * x7;
         y6 += a6_7 * x7;
         y7 += a7_7 * x7;
         y8 += a8_7 * x7;
         y9 += a9_7 * x7;
         y10 += a10_7 * x7;
         y11 += a11_7 * x7;
         y12 += a12_7 * x7;
         y13 += a13_7 * x7;
         y14 += a14_7 * x7;
         y15 += a15_7 * x7;
         y0 += a0_8 * x8;
         prefA(A8);
         y1 += a1_8 * x8;
         y2 += a2_8 * x8;
         y3 += a3_8 * x8;
         y4 += a4_8 * x8;
         y5 += a5_8 * x8;
         y6 += a6_8 * x8;
         y7 += a7_8 * x8;
         y8 += a8_8 * x8;
         y9 += a9_8 * x8;
         y10 += a10_8 * x8;
         y11 += a11_8 * x8;
         y12 += a12_8 * x8;
         y13 += a13_8 * x8;
         y14 += a14_8 * x8;
         y15 += a15_8 * x8;
         y0 += a0_9 * x9;
         prefA(A9);
         y1 += a1_9 * x9;
         y2 += a2_9 * x9;
         y3 += a3_9 * x9;
         y4 += a4_9 * x9;
         y5 += a5_9 * x9;
         y6 += a6_9 * x9;
         y7 += a7_9 * x9;
         y8 += a8_9 * x9;
         y9 += a9_9 * x9;
         y10 += a10_9 * x9;
         y11 += a11_9 * x9;
         y12 += a12_9 * x9;
         y13 += a13_9 * x9;
         y14 += a14_9 * x9;
         y15 += a15_9 * x9;
         y0 += a0_10 * x10;
         prefA(A10);
         y1 += a1_10 * x10;
         y2 += a2_10 * x10;
         y3 += a3_10 * x10;
         y4 += a4_10 * x10;
         y5 += a5_10 * x10;
         y6 += a6_10 * x10;
         y7 += a7_10 * x10;
         y8 += a8_10 * x10;
         y9 += a9_10 * x10;
         y10 += a10_10 * x10;
         y11 += a11_10 * x10;
         y12 += a12_10 * x10;
         y13 += a13_10 * x10;
         y14 += a14_10 * x10;
         y15 += a15_10 * x10;
         y0 += a0_11 * x11;
         prefA(A11);
         y1 += a1_11 * x11;
         y2 += a2_11 * x11;
         y3 += a3_11 * x11;
         y4 += a4_11 * x11;
         y5 += a5_11 * x11;
         y6 += a6_11 * x11;
         y7 += a7_11 * x11;
         y8 += a8_11 * x11;
         y9 += a9_11 * x11;
         y10 += a10_11 * x11;
         y11 += a11_11 * x11;
         y12 += a12_11 * x11;
         y13 += a13_11 * x11;
         y14 += a14_11 * x11;
         y15 += a15_11 * x11;
         y0 += a0_12 * x12;
         prefA(A12);
         y1 += a1_12 * x12;
         y2 += a2_12 * x12;
         y3 += a3_12 * x12;
         y4 += a4_12 * x12;
         y5 += a5_12 * x12;
         y6 += a6_12 * x12;
         y7 += a7_12 * x12;
         y8 += a8_12 * x12;
         y9 += a9_12 * x12;
         y10 += a10_12 * x12;
         y11 += a11_12 * x12;
         y12 += a12_12 * x12;
         y13 += a13_12 * x12;
         y14 += a14_12 * x12;
         y15 += a15_12 * x12;
         y0 += a0_13 * x13;
         prefA(A13);
         y1 += a1_13 * x13;
         y2 += a2_13 * x13;
         y3 += a3_13 * x13;
         y4 += a4_13 * x13;
         y5 += a5_13 * x13;
         y6 += a6_13 * x13;
         y7 += a7_13 * x13;
         y8 += a8_13 * x13;
         y9 += a9_13 * x13;
         y10 += a10_13 * x13;
         y11 += a11_13 * x13;
         y12 += a12_13 * x13;
         y13 += a13_13 * x13;
         y14 += a14_13 * x13;
         y15 += a15_13 * x13;
         y0 += a0_14 * x14;
         prefA(A14);
         y1 += a1_14 * x14;
         y2 += a2_14 * x14;
         y3 += a3_14 * x14;
         y4 += a4_14 * x14;
         y5 += a5_14 * x14;
         y6 += a6_14 * x14;
         y7 += a7_14 * x14;
         y8 += a8_14 * x14;
         y9 += a9_14 * x14;
         y10 += a10_14 * x14;
         y11 += a11_14 * x14;
         y12 += a12_14 * x14;
         y13 += a13_14 * x14;
         y14 += a14_14 * x14;
         y15 += a15_14 * x14;
         y0 += a0_15 * x15;
         prefA(A15);
         y1 += a1_15 * x15;
         y2 += a2_15 * x15;
         y3 += a3_15 * x15;
         y4 += a4_15 * x15;
         y5 += a5_15 * x15;
         y6 += a6_15 * x15;
         y7 += a7_15 * x15;
         y8 += a8_15 * x15;
         y9 += a9_15 * x15;
         y10 += a10_15 * x15;
         y11 += a11_15 * x15;
         y12 += a12_15 * x15;
         y13 += a13_15 * x15;
         y14 += a14_15 * x15;
         y15 += a15_15 * x15;
         y0 += a0_16 * x16;
         prefA(A16);
         y1 += a1_16 * x16;
         y2 += a2_16 * x16;
         y3 += a3_16 * x16;
         y4 += a4_16 * x16;
         y5 += a5_16 * x16;
         y6 += a6_16 * x16;
         y7 += a7_16 * x16;
         y8 += a8_16 * x16;
         y9 += a9_16 * x16;
         y10 += a10_16 * x16;
         y11 += a11_16 * x16;
         y12 += a12_16 * x16;
         y13 += a13_16 * x16;
         y14 += a14_16 * x16;
         y15 += a15_16 * x16;
         y0 += a0_17 * x17;
         prefA(A17);
         y1 += a1_17 * x17;
         y2 += a2_17 * x17;
         y3 += a3_17 * x17;
         y4 += a4_17 * x17;
         y5 += a5_17 * x17;
         y6 += a6_17 * x17;
         y7 += a7_17 * x17;
         y8 += a8_17 * x17;
         y9 += a9_17 * x17;
         y10 += a10_17 * x17;
         y11 += a11_17 * x17;
         y12 += a12_17 * x17;
         y13 += a13_17 * x17;
         y14 += a14_17 * x17;
         y15 += a15_17 * x17;
         y0 += a0_18 * x18;
         prefA(A18);
         y1 += a1_18 * x18;
         y2 += a2_18 * x18;
         y3 += a3_18 * x18;
         y4 += a4_18 * x18;
         y5 += a5_18 * x18;
         y6 += a6_18 * x18;
         y7 += a7_18 * x18;
         y8 += a8_18 * x18;
         y9 += a9_18 * x18;
         y10 += a10_18 * x18;
         y11 += a11_18 * x18;
         y12 += a12_18 * x18;
         y13 += a13_18 * x18;
         y14 += a14_18 * x18;
         y15 += a15_18 * x18;
         y0 += a0_19 * x19;
         prefA(A19);
         y1 += a1_19 * x19;
         y2 += a2_19 * x19;
         y3 += a3_19 * x19;
         y4 += a4_19 * x19;
         y5 += a5_19 * x19;
         y6 += a6_19 * x19;
         y7 += a7_19 * x19;
         y8 += a8_19 * x19;
         y9 += a9_19 * x19;
         y10 += a10_19 * x19;
         y11 += a11_19 * x19;
         y12 += a12_19 * x19;
         y13 += a13_19 * x19;
         y14 += a14_19 * x19;
         y15 += a15_19 * x19;
         Y[i+0] = y0;
         Y[i+1] = y1;
         Y[i+2] = y2;
         Y[i+3] = y3;
         Y[i+4] = y4;
         Y[i+5] = y5;
         Y[i+6] = y6;
         Y[i+7] = y7;
         Y[i+8] = y8;
         Y[i+9] = y9;
         Y[i+10] = y10;
         Y[i+11] = y11;
         Y[i+12] = y12;
         Y[i+13] = y13;
         Y[i+14] = y14;
         Y[i+15] = y15;
      }
      for (i=M16; i < M; i++)
      {
         const float a0_0=A0[i], a0_1=A1[i], a0_2=A2[i], a0_3=A3[i], a0_4=A4[i],
                     a0_5=A5[i], a0_6=A6[i], a0_7=A7[i], a0_8=A8[i], a0_9=A9[i],
                     a0_10=A10[i], a0_11=A11[i], a0_12=A12[i], a0_13=A13[i],
                     a0_14=A14[i], a0_15=A15[i], a0_16=A16[i], a0_17=A17[i],
                     a0_18=A18[i], a0_19=A19[i];
         register float y0 = Y[i];

         y0 += a0_0 * x0;
         y0 += a0_1 * x1;
         y0 += a0_2 * x2;
         y0 += a0_3 * x3;
         y0 += a0_4 * x4;
         y0 += a0_5 * x5;
         y0 += a0_6 * x6;
         y0 += a0_7 * x7;
         y0 += a0_8 * x8;
         y0 += a0_9 * x9;
         y0 += a0_10 * x10;
         y0 += a0_11 * x11;
         y0 += a0_12 * x12;
         y0 += a0_13 * x13;
         y0 += a0_14 * x14;
         y0 += a0_15 * x15;
         y0 += a0_16 * x16;
         y0 += a0_17 * x17;
         y0 += a0_18 * x18;
         y0 += a0_19 * x19;
         Y[i] = y0;
      }
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N20; j; j--, A += lda, X++)
   {
      const float *A0=A;
      const register float x0=X[0];
      ATL_INT i;
      prefY(Y+1+1-1);
      for (i=0; i < M16; i += 16)
      {
         const float a0_0=A0[i+0], a1_0=A0[i+1], a2_0=A0[i+2], a3_0=A0[i+3],
                     a4_0=A0[i+4], a5_0=A0[i+5], a6_0=A0[i+6], a7_0=A0[i+7],
                     a8_0=A0[i+8], a9_0=A0[i+9], a10_0=A0[i+10], a11_0=A0[i+11],
                     a12_0=A0[i+12], a13_0=A0[i+13], a14_0=A0[i+14],
                     a15_0=A0[i+15];
         register float y0=Y[i+0], y1=Y[i+1], y2=Y[i+2], y3=Y[i+3], y4=Y[i+4],
                        y5=Y[i+5], y6=Y[i+6], y7=Y[i+7], y8=Y[i+8], y9=Y[i+9],
                        y10=Y[i+10], y11=Y[i+11], y12=Y[i+12], y13=Y[i+13],
                        y14=Y[i+14], y15=Y[i+15];

         prefX(X);
         y0 += a0_0 * x0;
         prefA(A0);
         y1 += a1_0 * x0;
         y2 += a2_0 * x0;
         y3 += a3_0 * x0;
         y4 += a4_0 * x0;
         y5 += a5_0 * x0;
         y6 += a6_0 * x0;
         y7 += a7_0 * x0;
         y8 += a8_0 * x0;
         y9 += a9_0 * x0;
         y10 += a10_0 * x0;
         y11 += a11_0 * x0;
         y12 += a12_0 * x0;
         y13 += a13_0 * x0;
         y14 += a14_0 * x0;
         y15 += a15_0 * x0;
         Y[i+0] = y0;
         Y[i+1] = y1;
         Y[i+2] = y2;
         Y[i+3] = y3;
         Y[i+4] = y4;
         Y[i+5] = y5;
         Y[i+6] = y6;
         Y[i+7] = y7;
         Y[i+8] = y8;
         Y[i+9] = y9;
         Y[i+10] = y10;
         Y[i+11] = y11;
         Y[i+12] = y12;
         Y[i+13] = y13;
         Y[i+14] = y14;
         Y[i+15] = y15;
      }
      for (i=M16; i < M; i++)
      {
         const float a0_0=A0[i];
         register float y0 = Y[i];

         y0 += a0_0 * x0;
         Y[i] = y0;
      }
   }
}
