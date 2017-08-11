#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 16
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
void ATL_UGERK(ATL_CINT M0, ATL_CINT N, const float *X, const float *Y, 
               float *A, ATL_CINT lda0)
/*
 * 8x16 unrolled r1_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N16=(N/16)*16, M=M0+M0, M8=((M0/8)*8)<<1,
            lda=lda0+lda0, lda16=lda*16;
   ATL_INT j;

   for (j=N16; j; j -= 16, A += lda16, Y += 32)
   {
      float *A0=A, *A1=A0+lda, *A2=A1+lda, *A3=A2+lda, *A4=A3+lda, *A5=A4+lda,
            *A6=A5+lda, *A7=A6+lda, *A8=A7+lda, *A9=A8+lda, *A10=A9+lda,
            *A11=A10+lda, *A12=A11+lda, *A13=A12+lda, *A14=A13+lda,
            *A15=A14+lda;
      const register float ry0=Y[0], iy0=Y[1], ry1=Y[2], iy1=Y[3], ry2=Y[4],
                           iy2=Y[5], ry3=Y[6], iy3=Y[7], ry4=Y[8], iy4=Y[9],
                           ry5=Y[10], iy5=Y[11], ry6=Y[12], iy6=Y[13],
                           ry7=Y[14], iy7=Y[15], ry8=Y[16], iy8=Y[17],
                           ry9=Y[18], iy9=Y[19], ry10=Y[20], iy10=Y[21],
                           ry11=Y[22], iy11=Y[23], ry12=Y[24], iy12=Y[25],
                           ry13=Y[26], iy13=Y[27], ry14=Y[28], iy14=Y[29],
                           ry15=Y[30], iy15=Y[31];
      ATL_INT i;
      prefY(Y+32+32-1);
      for (i=0; i < M8; i += 16)
      {
         const register float rx0=X[i+0], ix0=X[i+1], rx1=X[i+2], ix1=X[i+3],
                              rx2=X[i+4], ix2=X[i+5], rx3=X[i+6], ix3=X[i+7],
                              rx4=X[i+8], ix4=X[i+9], rx5=X[i+10], ix5=X[i+11],
                              rx6=X[i+12], ix6=X[i+13], rx7=X[i+14],
                              ix7=X[i+15];

         prefX(X);
         A0[i+0] += ry0*rx0 - iy0*ix0;
         prefA(A0);
         A0[i+0+1] += ry0*ix0 + iy0*rx0;
         A1[i+0] += ry1*rx0 - iy1*ix0;
         prefA(A1);
         A1[i+0+1] += ry1*ix0 + iy1*rx0;
         A2[i+0] += ry2*rx0 - iy2*ix0;
         prefA(A2);
         A2[i+0+1] += ry2*ix0 + iy2*rx0;
         A3[i+0] += ry3*rx0 - iy3*ix0;
         prefA(A3);
         A3[i+0+1] += ry3*ix0 + iy3*rx0;
         A4[i+0] += ry4*rx0 - iy4*ix0;
         prefA(A4);
         A4[i+0+1] += ry4*ix0 + iy4*rx0;
         A5[i+0] += ry5*rx0 - iy5*ix0;
         prefA(A5);
         A5[i+0+1] += ry5*ix0 + iy5*rx0;
         A6[i+0] += ry6*rx0 - iy6*ix0;
         prefA(A6);
         A6[i+0+1] += ry6*ix0 + iy6*rx0;
         A7[i+0] += ry7*rx0 - iy7*ix0;
         prefA(A7);
         A7[i+0+1] += ry7*ix0 + iy7*rx0;
         A8[i+0] += ry8*rx0 - iy8*ix0;
         prefA(A8);
         A8[i+0+1] += ry8*ix0 + iy8*rx0;
         A9[i+0] += ry9*rx0 - iy9*ix0;
         prefA(A9);
         A9[i+0+1] += ry9*ix0 + iy9*rx0;
         A10[i+0] += ry10*rx0 - iy10*ix0;
         prefA(A10);
         A10[i+0+1] += ry10*ix0 + iy10*rx0;
         A11[i+0] += ry11*rx0 - iy11*ix0;
         prefA(A11);
         A11[i+0+1] += ry11*ix0 + iy11*rx0;
         A12[i+0] += ry12*rx0 - iy12*ix0;
         prefA(A12);
         A12[i+0+1] += ry12*ix0 + iy12*rx0;
         A13[i+0] += ry13*rx0 - iy13*ix0;
         prefA(A13);
         A13[i+0+1] += ry13*ix0 + iy13*rx0;
         A14[i+0] += ry14*rx0 - iy14*ix0;
         prefA(A14);
         A14[i+0+1] += ry14*ix0 + iy14*rx0;
         A15[i+0] += ry15*rx0 - iy15*ix0;
         prefA(A15);
         A15[i+0+1] += ry15*ix0 + iy15*rx0;
         A0[i+2] += ry0*rx1 - iy0*ix1;
         A0[i+2+1] += ry0*ix1 + iy0*rx1;
         A1[i+2] += ry1*rx1 - iy1*ix1;
         A1[i+2+1] += ry1*ix1 + iy1*rx1;
         A2[i+2] += ry2*rx1 - iy2*ix1;
         A2[i+2+1] += ry2*ix1 + iy2*rx1;
         A3[i+2] += ry3*rx1 - iy3*ix1;
         A3[i+2+1] += ry3*ix1 + iy3*rx1;
         A4[i+2] += ry4*rx1 - iy4*ix1;
         A4[i+2+1] += ry4*ix1 + iy4*rx1;
         A5[i+2] += ry5*rx1 - iy5*ix1;
         A5[i+2+1] += ry5*ix1 + iy5*rx1;
         A6[i+2] += ry6*rx1 - iy6*ix1;
         A6[i+2+1] += ry6*ix1 + iy6*rx1;
         A7[i+2] += ry7*rx1 - iy7*ix1;
         A7[i+2+1] += ry7*ix1 + iy7*rx1;
         A8[i+2] += ry8*rx1 - iy8*ix1;
         A8[i+2+1] += ry8*ix1 + iy8*rx1;
         A9[i+2] += ry9*rx1 - iy9*ix1;
         A9[i+2+1] += ry9*ix1 + iy9*rx1;
         A10[i+2] += ry10*rx1 - iy10*ix1;
         A10[i+2+1] += ry10*ix1 + iy10*rx1;
         A11[i+2] += ry11*rx1 - iy11*ix1;
         A11[i+2+1] += ry11*ix1 + iy11*rx1;
         A12[i+2] += ry12*rx1 - iy12*ix1;
         A12[i+2+1] += ry12*ix1 + iy12*rx1;
         A13[i+2] += ry13*rx1 - iy13*ix1;
         A13[i+2+1] += ry13*ix1 + iy13*rx1;
         A14[i+2] += ry14*rx1 - iy14*ix1;
         A14[i+2+1] += ry14*ix1 + iy14*rx1;
         A15[i+2] += ry15*rx1 - iy15*ix1;
         A15[i+2+1] += ry15*ix1 + iy15*rx1;
         A0[i+4] += ry0*rx2 - iy0*ix2;
         A0[i+4+1] += ry0*ix2 + iy0*rx2;
         A1[i+4] += ry1*rx2 - iy1*ix2;
         A1[i+4+1] += ry1*ix2 + iy1*rx2;
         A2[i+4] += ry2*rx2 - iy2*ix2;
         A2[i+4+1] += ry2*ix2 + iy2*rx2;
         A3[i+4] += ry3*rx2 - iy3*ix2;
         A3[i+4+1] += ry3*ix2 + iy3*rx2;
         A4[i+4] += ry4*rx2 - iy4*ix2;
         A4[i+4+1] += ry4*ix2 + iy4*rx2;
         A5[i+4] += ry5*rx2 - iy5*ix2;
         A5[i+4+1] += ry5*ix2 + iy5*rx2;
         A6[i+4] += ry6*rx2 - iy6*ix2;
         A6[i+4+1] += ry6*ix2 + iy6*rx2;
         A7[i+4] += ry7*rx2 - iy7*ix2;
         A7[i+4+1] += ry7*ix2 + iy7*rx2;
         A8[i+4] += ry8*rx2 - iy8*ix2;
         A8[i+4+1] += ry8*ix2 + iy8*rx2;
         A9[i+4] += ry9*rx2 - iy9*ix2;
         A9[i+4+1] += ry9*ix2 + iy9*rx2;
         A10[i+4] += ry10*rx2 - iy10*ix2;
         A10[i+4+1] += ry10*ix2 + iy10*rx2;
         A11[i+4] += ry11*rx2 - iy11*ix2;
         A11[i+4+1] += ry11*ix2 + iy11*rx2;
         A12[i+4] += ry12*rx2 - iy12*ix2;
         A12[i+4+1] += ry12*ix2 + iy12*rx2;
         A13[i+4] += ry13*rx2 - iy13*ix2;
         A13[i+4+1] += ry13*ix2 + iy13*rx2;
         A14[i+4] += ry14*rx2 - iy14*ix2;
         A14[i+4+1] += ry14*ix2 + iy14*rx2;
         A15[i+4] += ry15*rx2 - iy15*ix2;
         A15[i+4+1] += ry15*ix2 + iy15*rx2;
         A0[i+6] += ry0*rx3 - iy0*ix3;
         A0[i+6+1] += ry0*ix3 + iy0*rx3;
         A1[i+6] += ry1*rx3 - iy1*ix3;
         A1[i+6+1] += ry1*ix3 + iy1*rx3;
         A2[i+6] += ry2*rx3 - iy2*ix3;
         A2[i+6+1] += ry2*ix3 + iy2*rx3;
         A3[i+6] += ry3*rx3 - iy3*ix3;
         A3[i+6+1] += ry3*ix3 + iy3*rx3;
         A4[i+6] += ry4*rx3 - iy4*ix3;
         A4[i+6+1] += ry4*ix3 + iy4*rx3;
         A5[i+6] += ry5*rx3 - iy5*ix3;
         A5[i+6+1] += ry5*ix3 + iy5*rx3;
         A6[i+6] += ry6*rx3 - iy6*ix3;
         A6[i+6+1] += ry6*ix3 + iy6*rx3;
         A7[i+6] += ry7*rx3 - iy7*ix3;
         A7[i+6+1] += ry7*ix3 + iy7*rx3;
         A8[i+6] += ry8*rx3 - iy8*ix3;
         A8[i+6+1] += ry8*ix3 + iy8*rx3;
         A9[i+6] += ry9*rx3 - iy9*ix3;
         A9[i+6+1] += ry9*ix3 + iy9*rx3;
         A10[i+6] += ry10*rx3 - iy10*ix3;
         A10[i+6+1] += ry10*ix3 + iy10*rx3;
         A11[i+6] += ry11*rx3 - iy11*ix3;
         A11[i+6+1] += ry11*ix3 + iy11*rx3;
         A12[i+6] += ry12*rx3 - iy12*ix3;
         A12[i+6+1] += ry12*ix3 + iy12*rx3;
         A13[i+6] += ry13*rx3 - iy13*ix3;
         A13[i+6+1] += ry13*ix3 + iy13*rx3;
         A14[i+6] += ry14*rx3 - iy14*ix3;
         A14[i+6+1] += ry14*ix3 + iy14*rx3;
         A15[i+6] += ry15*rx3 - iy15*ix3;
         A15[i+6+1] += ry15*ix3 + iy15*rx3;
         A0[i+8] += ry0*rx4 - iy0*ix4;
         A0[i+8+1] += ry0*ix4 + iy0*rx4;
         A1[i+8] += ry1*rx4 - iy1*ix4;
         A1[i+8+1] += ry1*ix4 + iy1*rx4;
         A2[i+8] += ry2*rx4 - iy2*ix4;
         A2[i+8+1] += ry2*ix4 + iy2*rx4;
         A3[i+8] += ry3*rx4 - iy3*ix4;
         A3[i+8+1] += ry3*ix4 + iy3*rx4;
         A4[i+8] += ry4*rx4 - iy4*ix4;
         A4[i+8+1] += ry4*ix4 + iy4*rx4;
         A5[i+8] += ry5*rx4 - iy5*ix4;
         A5[i+8+1] += ry5*ix4 + iy5*rx4;
         A6[i+8] += ry6*rx4 - iy6*ix4;
         A6[i+8+1] += ry6*ix4 + iy6*rx4;
         A7[i+8] += ry7*rx4 - iy7*ix4;
         A7[i+8+1] += ry7*ix4 + iy7*rx4;
         A8[i+8] += ry8*rx4 - iy8*ix4;
         A8[i+8+1] += ry8*ix4 + iy8*rx4;
         A9[i+8] += ry9*rx4 - iy9*ix4;
         A9[i+8+1] += ry9*ix4 + iy9*rx4;
         A10[i+8] += ry10*rx4 - iy10*ix4;
         A10[i+8+1] += ry10*ix4 + iy10*rx4;
         A11[i+8] += ry11*rx4 - iy11*ix4;
         A11[i+8+1] += ry11*ix4 + iy11*rx4;
         A12[i+8] += ry12*rx4 - iy12*ix4;
         A12[i+8+1] += ry12*ix4 + iy12*rx4;
         A13[i+8] += ry13*rx4 - iy13*ix4;
         A13[i+8+1] += ry13*ix4 + iy13*rx4;
         A14[i+8] += ry14*rx4 - iy14*ix4;
         A14[i+8+1] += ry14*ix4 + iy14*rx4;
         A15[i+8] += ry15*rx4 - iy15*ix4;
         A15[i+8+1] += ry15*ix4 + iy15*rx4;
         A0[i+10] += ry0*rx5 - iy0*ix5;
         A0[i+10+1] += ry0*ix5 + iy0*rx5;
         A1[i+10] += ry1*rx5 - iy1*ix5;
         A1[i+10+1] += ry1*ix5 + iy1*rx5;
         A2[i+10] += ry2*rx5 - iy2*ix5;
         A2[i+10+1] += ry2*ix5 + iy2*rx5;
         A3[i+10] += ry3*rx5 - iy3*ix5;
         A3[i+10+1] += ry3*ix5 + iy3*rx5;
         A4[i+10] += ry4*rx5 - iy4*ix5;
         A4[i+10+1] += ry4*ix5 + iy4*rx5;
         A5[i+10] += ry5*rx5 - iy5*ix5;
         A5[i+10+1] += ry5*ix5 + iy5*rx5;
         A6[i+10] += ry6*rx5 - iy6*ix5;
         A6[i+10+1] += ry6*ix5 + iy6*rx5;
         A7[i+10] += ry7*rx5 - iy7*ix5;
         A7[i+10+1] += ry7*ix5 + iy7*rx5;
         A8[i+10] += ry8*rx5 - iy8*ix5;
         A8[i+10+1] += ry8*ix5 + iy8*rx5;
         A9[i+10] += ry9*rx5 - iy9*ix5;
         A9[i+10+1] += ry9*ix5 + iy9*rx5;
         A10[i+10] += ry10*rx5 - iy10*ix5;
         A10[i+10+1] += ry10*ix5 + iy10*rx5;
         A11[i+10] += ry11*rx5 - iy11*ix5;
         A11[i+10+1] += ry11*ix5 + iy11*rx5;
         A12[i+10] += ry12*rx5 - iy12*ix5;
         A12[i+10+1] += ry12*ix5 + iy12*rx5;
         A13[i+10] += ry13*rx5 - iy13*ix5;
         A13[i+10+1] += ry13*ix5 + iy13*rx5;
         A14[i+10] += ry14*rx5 - iy14*ix5;
         A14[i+10+1] += ry14*ix5 + iy14*rx5;
         A15[i+10] += ry15*rx5 - iy15*ix5;
         A15[i+10+1] += ry15*ix5 + iy15*rx5;
         A0[i+12] += ry0*rx6 - iy0*ix6;
         A0[i+12+1] += ry0*ix6 + iy0*rx6;
         A1[i+12] += ry1*rx6 - iy1*ix6;
         A1[i+12+1] += ry1*ix6 + iy1*rx6;
         A2[i+12] += ry2*rx6 - iy2*ix6;
         A2[i+12+1] += ry2*ix6 + iy2*rx6;
         A3[i+12] += ry3*rx6 - iy3*ix6;
         A3[i+12+1] += ry3*ix6 + iy3*rx6;
         A4[i+12] += ry4*rx6 - iy4*ix6;
         A4[i+12+1] += ry4*ix6 + iy4*rx6;
         A5[i+12] += ry5*rx6 - iy5*ix6;
         A5[i+12+1] += ry5*ix6 + iy5*rx6;
         A6[i+12] += ry6*rx6 - iy6*ix6;
         A6[i+12+1] += ry6*ix6 + iy6*rx6;
         A7[i+12] += ry7*rx6 - iy7*ix6;
         A7[i+12+1] += ry7*ix6 + iy7*rx6;
         A8[i+12] += ry8*rx6 - iy8*ix6;
         A8[i+12+1] += ry8*ix6 + iy8*rx6;
         A9[i+12] += ry9*rx6 - iy9*ix6;
         A9[i+12+1] += ry9*ix6 + iy9*rx6;
         A10[i+12] += ry10*rx6 - iy10*ix6;
         A10[i+12+1] += ry10*ix6 + iy10*rx6;
         A11[i+12] += ry11*rx6 - iy11*ix6;
         A11[i+12+1] += ry11*ix6 + iy11*rx6;
         A12[i+12] += ry12*rx6 - iy12*ix6;
         A12[i+12+1] += ry12*ix6 + iy12*rx6;
         A13[i+12] += ry13*rx6 - iy13*ix6;
         A13[i+12+1] += ry13*ix6 + iy13*rx6;
         A14[i+12] += ry14*rx6 - iy14*ix6;
         A14[i+12+1] += ry14*ix6 + iy14*rx6;
         A15[i+12] += ry15*rx6 - iy15*ix6;
         A15[i+12+1] += ry15*ix6 + iy15*rx6;
         A0[i+14] += ry0*rx7 - iy0*ix7;
         A0[i+14+1] += ry0*ix7 + iy0*rx7;
         A1[i+14] += ry1*rx7 - iy1*ix7;
         A1[i+14+1] += ry1*ix7 + iy1*rx7;
         A2[i+14] += ry2*rx7 - iy2*ix7;
         A2[i+14+1] += ry2*ix7 + iy2*rx7;
         A3[i+14] += ry3*rx7 - iy3*ix7;
         A3[i+14+1] += ry3*ix7 + iy3*rx7;
         A4[i+14] += ry4*rx7 - iy4*ix7;
         A4[i+14+1] += ry4*ix7 + iy4*rx7;
         A5[i+14] += ry5*rx7 - iy5*ix7;
         A5[i+14+1] += ry5*ix7 + iy5*rx7;
         A6[i+14] += ry6*rx7 - iy6*ix7;
         A6[i+14+1] += ry6*ix7 + iy6*rx7;
         A7[i+14] += ry7*rx7 - iy7*ix7;
         A7[i+14+1] += ry7*ix7 + iy7*rx7;
         A8[i+14] += ry8*rx7 - iy8*ix7;
         A8[i+14+1] += ry8*ix7 + iy8*rx7;
         A9[i+14] += ry9*rx7 - iy9*ix7;
         A9[i+14+1] += ry9*ix7 + iy9*rx7;
         A10[i+14] += ry10*rx7 - iy10*ix7;
         A10[i+14+1] += ry10*ix7 + iy10*rx7;
         A11[i+14] += ry11*rx7 - iy11*ix7;
         A11[i+14+1] += ry11*ix7 + iy11*rx7;
         A12[i+14] += ry12*rx7 - iy12*ix7;
         A12[i+14+1] += ry12*ix7 + iy12*rx7;
         A13[i+14] += ry13*rx7 - iy13*ix7;
         A13[i+14+1] += ry13*ix7 + iy13*rx7;
         A14[i+14] += ry14*rx7 - iy14*ix7;
         A14[i+14+1] += ry14*ix7 + iy14*rx7;
         A15[i+14] += ry15*rx7 - iy15*ix7;
         A15[i+14+1] += ry15*ix7 + iy15*rx7;
      }
      for (i=M8; i < M; i += 2)
      {
         const register float rx0 = X[i], ix0 = X[i+1];
         A0[i] += ry0 * rx0 - iy0 * ix0;
         A0[i+1] += ry0 * ix0 + iy0 * rx0;
         A1[i] += ry1 * rx0 - iy1 * ix0;
         A1[i+1] += ry1 * ix0 + iy1 * rx0;
         A2[i] += ry2 * rx0 - iy2 * ix0;
         A2[i+1] += ry2 * ix0 + iy2 * rx0;
         A3[i] += ry3 * rx0 - iy3 * ix0;
         A3[i+1] += ry3 * ix0 + iy3 * rx0;
         A4[i] += ry4 * rx0 - iy4 * ix0;
         A4[i+1] += ry4 * ix0 + iy4 * rx0;
         A5[i] += ry5 * rx0 - iy5 * ix0;
         A5[i+1] += ry5 * ix0 + iy5 * rx0;
         A6[i] += ry6 * rx0 - iy6 * ix0;
         A6[i+1] += ry6 * ix0 + iy6 * rx0;
         A7[i] += ry7 * rx0 - iy7 * ix0;
         A7[i+1] += ry7 * ix0 + iy7 * rx0;
         A8[i] += ry8 * rx0 - iy8 * ix0;
         A8[i+1] += ry8 * ix0 + iy8 * rx0;
         A9[i] += ry9 * rx0 - iy9 * ix0;
         A9[i+1] += ry9 * ix0 + iy9 * rx0;
         A10[i] += ry10 * rx0 - iy10 * ix0;
         A10[i+1] += ry10 * ix0 + iy10 * rx0;
         A11[i] += ry11 * rx0 - iy11 * ix0;
         A11[i+1] += ry11 * ix0 + iy11 * rx0;
         A12[i] += ry12 * rx0 - iy12 * ix0;
         A12[i+1] += ry12 * ix0 + iy12 * rx0;
         A13[i] += ry13 * rx0 - iy13 * ix0;
         A13[i+1] += ry13 * ix0 + iy13 * rx0;
         A14[i] += ry14 * rx0 - iy14 * ix0;
         A14[i+1] += ry14 * ix0 + iy14 * rx0;
         A15[i] += ry15 * rx0 - iy15 * ix0;
         A15[i+1] += ry15 * ix0 + iy15 * rx0;
      }
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N16; j; j--, A += lda, Y += 2)
   {
      float *A0=A;
      const register float ry0=Y[0], iy0=Y[1];
      ATL_INT i;
      prefY(Y+32+32-1);
      for (i=0; i < M8; i += 16)
      {
         const register float rx0=X[i+0], ix0=X[i+1], rx1=X[i+2], ix1=X[i+3],
                              rx2=X[i+4], ix2=X[i+5], rx3=X[i+6], ix3=X[i+7],
                              rx4=X[i+8], ix4=X[i+9], rx5=X[i+10], ix5=X[i+11],
                              rx6=X[i+12], ix6=X[i+13], rx7=X[i+14],
                              ix7=X[i+15];

         prefX(X);
         A0[i+0] += ry0*rx0 - iy0*ix0;
         prefA(A0);
         A0[i+0+1] += ry0*ix0 + iy0*rx0;
         A0[i+2] += ry0*rx1 - iy0*ix1;
         A0[i+2+1] += ry0*ix1 + iy0*rx1;
         A0[i+4] += ry0*rx2 - iy0*ix2;
         A0[i+4+1] += ry0*ix2 + iy0*rx2;
         A0[i+6] += ry0*rx3 - iy0*ix3;
         A0[i+6+1] += ry0*ix3 + iy0*rx3;
         A0[i+8] += ry0*rx4 - iy0*ix4;
         A0[i+8+1] += ry0*ix4 + iy0*rx4;
         A0[i+10] += ry0*rx5 - iy0*ix5;
         A0[i+10+1] += ry0*ix5 + iy0*rx5;
         A0[i+12] += ry0*rx6 - iy0*ix6;
         A0[i+12+1] += ry0*ix6 + iy0*rx6;
         A0[i+14] += ry0*rx7 - iy0*ix7;
         A0[i+14+1] += ry0*ix7 + iy0*rx7;
      }
      for (i=M8; i < M; i += 2)
      {
         const register float rx0 = X[i], ix0 = X[i+1];
         A0[i] += ry0 * rx0 - iy0 * ix0;
         A0[i+1] += ry0 * ix0 + iy0 * rx0;
      }
   }
}
