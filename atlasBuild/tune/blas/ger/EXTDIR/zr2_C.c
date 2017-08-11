#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 12
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
void ATL_UGER2K(ATL_CINT M0, ATL_CINT N, const double *X, const double *Y, 
                const double *W, const double *Z, double *A, ATL_CINT lda0)
/*
 * 4x12 unrolled r2_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N12=(N/12)*12, M=M0+M0, M4=((M0/4)*4)<<1,
            lda=lda0+lda0, lda12=lda*12;
   ATL_INT j;

   for (j=N12; j; j -= 12, A += lda12, Y += 24)
   {
      double *A0=A, *A1=A0+lda, *A2=A1+lda, *A3=A2+lda, *A4=A3+lda, *A5=A4+lda,
             *A6=A5+lda, *A7=A6+lda, *A8=A7+lda, *A9=A8+lda, *A10=A9+lda,
             *A11=A10+lda;
      const register double ry0=Y[0], rz0=Z[0], iy0=Y[1], iz0=Z[1], ry1=Y[2],
                            rz1=Z[2], iy1=Y[3], iz1=Z[3], ry2=Y[4], rz2=Z[4],
                            iy2=Y[5], iz2=Z[5], ry3=Y[6], rz3=Z[6], iy3=Y[7],
                            iz3=Z[7], ry4=Y[8], rz4=Z[8], iy4=Y[9], iz4=Z[9],
                            ry5=Y[10], rz5=Z[10], iy5=Y[11], iz5=Z[11],
                            ry6=Y[12], rz6=Z[12], iy6=Y[13], iz6=Z[13],
                            ry7=Y[14], rz7=Z[14], iy7=Y[15], iz7=Z[15],
                            ry8=Y[16], rz8=Z[16], iy8=Y[17], iz8=Z[17],
                            ry9=Y[18], rz9=Z[18], iy9=Y[19], iz9=Z[19],
                            ry10=Y[20], rz10=Z[20], iy10=Y[21], iz10=Z[21],
                            ry11=Y[22], rz11=Z[22], iy11=Y[23], iz11=Z[23];
      ATL_INT i;
      prefY(Y+24+24-1);
      for (i=0; i < M4; i += 8)
      {
         register double ra00, ia00, ra10, ia10;
         const double rx0=X[i+0], rw0=W[i+0], ix0=X[i+1], iw0=W[i+1],
                      rx1=X[i+2], rw1=W[i+2], ix1=X[i+3], iw1=W[i+3],
                      rx2=X[i+4], rw2=W[i+4], ix2=X[i+5], iw2=W[i+5],
                      rx3=X[i+6], rw3=W[i+6], ix3=X[i+7], iw3=W[i+7];

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
         ra00 = A0[i+4];
         ia00 = A0[i+4+1];
         ra10 = A0[i+4+2];
         ia10 = A0[i+4+3];
         ra00 += rx2 * ry0;
         ia00 += rx2 * iy0;
         ra10 += rx3 * ry0;
         ia10 += rx3 * iy0;
         ra00 -= ix2 * iy0;
         ia00 += ix2 * ry0;
         ra10 -= ix3 * iy0;
         ia10 += ix3 * ry0;
         ra00 += rw2 * rz0;
         ia00 += rw2 * iz0;
         ra10 += rw3 * rz0;
         ia10 += rw3 * iz0;
         ra00 -= iw2 * iz0;
         A0[i+4] = ra00;
         ia00 += iw2 * rz0;
         A0[i+4+1] = ia00;
         ra10 -= iw3 * iz0;
         A0[i+4+2] = ra10;
         ia10 += iw3 * rz0;
         A0[i+4+3] = ia10;

         ra00 = A1[i+0];
         ia00 = A1[i+0+1];
         ra10 = A1[i+0+2];
         ia10 = A1[i+0+3];
         ra00 += rx0 * ry1;
         ia00 += rx0 * iy1;
         ra10 += rx1 * ry1;
         ia10 += rx1 * iy1;
         prefA(A1);
         ra00 -= ix0 * iy1;
         ia00 += ix0 * ry1;
         ra10 -= ix1 * iy1;
         ia10 += ix1 * ry1;
         ra00 += rw0 * rz1;
         ia00 += rw0 * iz1;
         ra10 += rw1 * rz1;
         ia10 += rw1 * iz1;
         ra00 -= iw0 * iz1;
         A1[i+0] = ra00;
         ia00 += iw0 * rz1;
         A1[i+0+1] = ia00;
         ra10 -= iw1 * iz1;
         A1[i+0+2] = ra10;
         ia10 += iw1 * rz1;
         A1[i+0+3] = ia10;
         ra00 = A1[i+4];
         ia00 = A1[i+4+1];
         ra10 = A1[i+4+2];
         ia10 = A1[i+4+3];
         ra00 += rx2 * ry1;
         ia00 += rx2 * iy1;
         ra10 += rx3 * ry1;
         ia10 += rx3 * iy1;
         ra00 -= ix2 * iy1;
         ia00 += ix2 * ry1;
         ra10 -= ix3 * iy1;
         ia10 += ix3 * ry1;
         ra00 += rw2 * rz1;
         ia00 += rw2 * iz1;
         ra10 += rw3 * rz1;
         ia10 += rw3 * iz1;
         ra00 -= iw2 * iz1;
         A1[i+4] = ra00;
         ia00 += iw2 * rz1;
         A1[i+4+1] = ia00;
         ra10 -= iw3 * iz1;
         A1[i+4+2] = ra10;
         ia10 += iw3 * rz1;
         A1[i+4+3] = ia10;

         ra00 = A2[i+0];
         ia00 = A2[i+0+1];
         ra10 = A2[i+0+2];
         ia10 = A2[i+0+3];
         ra00 += rx0 * ry2;
         ia00 += rx0 * iy2;
         ra10 += rx1 * ry2;
         ia10 += rx1 * iy2;
         prefA(A2);
         ra00 -= ix0 * iy2;
         ia00 += ix0 * ry2;
         ra10 -= ix1 * iy2;
         ia10 += ix1 * ry2;
         ra00 += rw0 * rz2;
         ia00 += rw0 * iz2;
         ra10 += rw1 * rz2;
         ia10 += rw1 * iz2;
         ra00 -= iw0 * iz2;
         A2[i+0] = ra00;
         ia00 += iw0 * rz2;
         A2[i+0+1] = ia00;
         ra10 -= iw1 * iz2;
         A2[i+0+2] = ra10;
         ia10 += iw1 * rz2;
         A2[i+0+3] = ia10;
         ra00 = A2[i+4];
         ia00 = A2[i+4+1];
         ra10 = A2[i+4+2];
         ia10 = A2[i+4+3];
         ra00 += rx2 * ry2;
         ia00 += rx2 * iy2;
         ra10 += rx3 * ry2;
         ia10 += rx3 * iy2;
         ra00 -= ix2 * iy2;
         ia00 += ix2 * ry2;
         ra10 -= ix3 * iy2;
         ia10 += ix3 * ry2;
         ra00 += rw2 * rz2;
         ia00 += rw2 * iz2;
         ra10 += rw3 * rz2;
         ia10 += rw3 * iz2;
         ra00 -= iw2 * iz2;
         A2[i+4] = ra00;
         ia00 += iw2 * rz2;
         A2[i+4+1] = ia00;
         ra10 -= iw3 * iz2;
         A2[i+4+2] = ra10;
         ia10 += iw3 * rz2;
         A2[i+4+3] = ia10;

         ra00 = A3[i+0];
         ia00 = A3[i+0+1];
         ra10 = A3[i+0+2];
         ia10 = A3[i+0+3];
         ra00 += rx0 * ry3;
         ia00 += rx0 * iy3;
         ra10 += rx1 * ry3;
         ia10 += rx1 * iy3;
         prefA(A3);
         ra00 -= ix0 * iy3;
         ia00 += ix0 * ry3;
         ra10 -= ix1 * iy3;
         ia10 += ix1 * ry3;
         ra00 += rw0 * rz3;
         ia00 += rw0 * iz3;
         ra10 += rw1 * rz3;
         ia10 += rw1 * iz3;
         ra00 -= iw0 * iz3;
         A3[i+0] = ra00;
         ia00 += iw0 * rz3;
         A3[i+0+1] = ia00;
         ra10 -= iw1 * iz3;
         A3[i+0+2] = ra10;
         ia10 += iw1 * rz3;
         A3[i+0+3] = ia10;
         ra00 = A3[i+4];
         ia00 = A3[i+4+1];
         ra10 = A3[i+4+2];
         ia10 = A3[i+4+3];
         ra00 += rx2 * ry3;
         ia00 += rx2 * iy3;
         ra10 += rx3 * ry3;
         ia10 += rx3 * iy3;
         ra00 -= ix2 * iy3;
         ia00 += ix2 * ry3;
         ra10 -= ix3 * iy3;
         ia10 += ix3 * ry3;
         ra00 += rw2 * rz3;
         ia00 += rw2 * iz3;
         ra10 += rw3 * rz3;
         ia10 += rw3 * iz3;
         ra00 -= iw2 * iz3;
         A3[i+4] = ra00;
         ia00 += iw2 * rz3;
         A3[i+4+1] = ia00;
         ra10 -= iw3 * iz3;
         A3[i+4+2] = ra10;
         ia10 += iw3 * rz3;
         A3[i+4+3] = ia10;

         ra00 = A4[i+0];
         ia00 = A4[i+0+1];
         ra10 = A4[i+0+2];
         ia10 = A4[i+0+3];
         ra00 += rx0 * ry4;
         ia00 += rx0 * iy4;
         ra10 += rx1 * ry4;
         ia10 += rx1 * iy4;
         prefA(A4);
         ra00 -= ix0 * iy4;
         ia00 += ix0 * ry4;
         ra10 -= ix1 * iy4;
         ia10 += ix1 * ry4;
         ra00 += rw0 * rz4;
         ia00 += rw0 * iz4;
         ra10 += rw1 * rz4;
         ia10 += rw1 * iz4;
         ra00 -= iw0 * iz4;
         A4[i+0] = ra00;
         ia00 += iw0 * rz4;
         A4[i+0+1] = ia00;
         ra10 -= iw1 * iz4;
         A4[i+0+2] = ra10;
         ia10 += iw1 * rz4;
         A4[i+0+3] = ia10;
         ra00 = A4[i+4];
         ia00 = A4[i+4+1];
         ra10 = A4[i+4+2];
         ia10 = A4[i+4+3];
         ra00 += rx2 * ry4;
         ia00 += rx2 * iy4;
         ra10 += rx3 * ry4;
         ia10 += rx3 * iy4;
         ra00 -= ix2 * iy4;
         ia00 += ix2 * ry4;
         ra10 -= ix3 * iy4;
         ia10 += ix3 * ry4;
         ra00 += rw2 * rz4;
         ia00 += rw2 * iz4;
         ra10 += rw3 * rz4;
         ia10 += rw3 * iz4;
         ra00 -= iw2 * iz4;
         A4[i+4] = ra00;
         ia00 += iw2 * rz4;
         A4[i+4+1] = ia00;
         ra10 -= iw3 * iz4;
         A4[i+4+2] = ra10;
         ia10 += iw3 * rz4;
         A4[i+4+3] = ia10;

         ra00 = A5[i+0];
         ia00 = A5[i+0+1];
         ra10 = A5[i+0+2];
         ia10 = A5[i+0+3];
         ra00 += rx0 * ry5;
         ia00 += rx0 * iy5;
         ra10 += rx1 * ry5;
         ia10 += rx1 * iy5;
         prefA(A5);
         ra00 -= ix0 * iy5;
         ia00 += ix0 * ry5;
         ra10 -= ix1 * iy5;
         ia10 += ix1 * ry5;
         ra00 += rw0 * rz5;
         ia00 += rw0 * iz5;
         ra10 += rw1 * rz5;
         ia10 += rw1 * iz5;
         ra00 -= iw0 * iz5;
         A5[i+0] = ra00;
         ia00 += iw0 * rz5;
         A5[i+0+1] = ia00;
         ra10 -= iw1 * iz5;
         A5[i+0+2] = ra10;
         ia10 += iw1 * rz5;
         A5[i+0+3] = ia10;
         ra00 = A5[i+4];
         ia00 = A5[i+4+1];
         ra10 = A5[i+4+2];
         ia10 = A5[i+4+3];
         ra00 += rx2 * ry5;
         ia00 += rx2 * iy5;
         ra10 += rx3 * ry5;
         ia10 += rx3 * iy5;
         ra00 -= ix2 * iy5;
         ia00 += ix2 * ry5;
         ra10 -= ix3 * iy5;
         ia10 += ix3 * ry5;
         ra00 += rw2 * rz5;
         ia00 += rw2 * iz5;
         ra10 += rw3 * rz5;
         ia10 += rw3 * iz5;
         ra00 -= iw2 * iz5;
         A5[i+4] = ra00;
         ia00 += iw2 * rz5;
         A5[i+4+1] = ia00;
         ra10 -= iw3 * iz5;
         A5[i+4+2] = ra10;
         ia10 += iw3 * rz5;
         A5[i+4+3] = ia10;

         ra00 = A6[i+0];
         ia00 = A6[i+0+1];
         ra10 = A6[i+0+2];
         ia10 = A6[i+0+3];
         ra00 += rx0 * ry6;
         ia00 += rx0 * iy6;
         ra10 += rx1 * ry6;
         ia10 += rx1 * iy6;
         prefA(A6);
         ra00 -= ix0 * iy6;
         ia00 += ix0 * ry6;
         ra10 -= ix1 * iy6;
         ia10 += ix1 * ry6;
         ra00 += rw0 * rz6;
         ia00 += rw0 * iz6;
         ra10 += rw1 * rz6;
         ia10 += rw1 * iz6;
         ra00 -= iw0 * iz6;
         A6[i+0] = ra00;
         ia00 += iw0 * rz6;
         A6[i+0+1] = ia00;
         ra10 -= iw1 * iz6;
         A6[i+0+2] = ra10;
         ia10 += iw1 * rz6;
         A6[i+0+3] = ia10;
         ra00 = A6[i+4];
         ia00 = A6[i+4+1];
         ra10 = A6[i+4+2];
         ia10 = A6[i+4+3];
         ra00 += rx2 * ry6;
         ia00 += rx2 * iy6;
         ra10 += rx3 * ry6;
         ia10 += rx3 * iy6;
         ra00 -= ix2 * iy6;
         ia00 += ix2 * ry6;
         ra10 -= ix3 * iy6;
         ia10 += ix3 * ry6;
         ra00 += rw2 * rz6;
         ia00 += rw2 * iz6;
         ra10 += rw3 * rz6;
         ia10 += rw3 * iz6;
         ra00 -= iw2 * iz6;
         A6[i+4] = ra00;
         ia00 += iw2 * rz6;
         A6[i+4+1] = ia00;
         ra10 -= iw3 * iz6;
         A6[i+4+2] = ra10;
         ia10 += iw3 * rz6;
         A6[i+4+3] = ia10;

         ra00 = A7[i+0];
         ia00 = A7[i+0+1];
         ra10 = A7[i+0+2];
         ia10 = A7[i+0+3];
         ra00 += rx0 * ry7;
         ia00 += rx0 * iy7;
         ra10 += rx1 * ry7;
         ia10 += rx1 * iy7;
         prefA(A7);
         ra00 -= ix0 * iy7;
         ia00 += ix0 * ry7;
         ra10 -= ix1 * iy7;
         ia10 += ix1 * ry7;
         ra00 += rw0 * rz7;
         ia00 += rw0 * iz7;
         ra10 += rw1 * rz7;
         ia10 += rw1 * iz7;
         ra00 -= iw0 * iz7;
         A7[i+0] = ra00;
         ia00 += iw0 * rz7;
         A7[i+0+1] = ia00;
         ra10 -= iw1 * iz7;
         A7[i+0+2] = ra10;
         ia10 += iw1 * rz7;
         A7[i+0+3] = ia10;
         ra00 = A7[i+4];
         ia00 = A7[i+4+1];
         ra10 = A7[i+4+2];
         ia10 = A7[i+4+3];
         ra00 += rx2 * ry7;
         ia00 += rx2 * iy7;
         ra10 += rx3 * ry7;
         ia10 += rx3 * iy7;
         ra00 -= ix2 * iy7;
         ia00 += ix2 * ry7;
         ra10 -= ix3 * iy7;
         ia10 += ix3 * ry7;
         ra00 += rw2 * rz7;
         ia00 += rw2 * iz7;
         ra10 += rw3 * rz7;
         ia10 += rw3 * iz7;
         ra00 -= iw2 * iz7;
         A7[i+4] = ra00;
         ia00 += iw2 * rz7;
         A7[i+4+1] = ia00;
         ra10 -= iw3 * iz7;
         A7[i+4+2] = ra10;
         ia10 += iw3 * rz7;
         A7[i+4+3] = ia10;

         ra00 = A8[i+0];
         ia00 = A8[i+0+1];
         ra10 = A8[i+0+2];
         ia10 = A8[i+0+3];
         ra00 += rx0 * ry8;
         ia00 += rx0 * iy8;
         ra10 += rx1 * ry8;
         ia10 += rx1 * iy8;
         prefA(A8);
         ra00 -= ix0 * iy8;
         ia00 += ix0 * ry8;
         ra10 -= ix1 * iy8;
         ia10 += ix1 * ry8;
         ra00 += rw0 * rz8;
         ia00 += rw0 * iz8;
         ra10 += rw1 * rz8;
         ia10 += rw1 * iz8;
         ra00 -= iw0 * iz8;
         A8[i+0] = ra00;
         ia00 += iw0 * rz8;
         A8[i+0+1] = ia00;
         ra10 -= iw1 * iz8;
         A8[i+0+2] = ra10;
         ia10 += iw1 * rz8;
         A8[i+0+3] = ia10;
         ra00 = A8[i+4];
         ia00 = A8[i+4+1];
         ra10 = A8[i+4+2];
         ia10 = A8[i+4+3];
         ra00 += rx2 * ry8;
         ia00 += rx2 * iy8;
         ra10 += rx3 * ry8;
         ia10 += rx3 * iy8;
         ra00 -= ix2 * iy8;
         ia00 += ix2 * ry8;
         ra10 -= ix3 * iy8;
         ia10 += ix3 * ry8;
         ra00 += rw2 * rz8;
         ia00 += rw2 * iz8;
         ra10 += rw3 * rz8;
         ia10 += rw3 * iz8;
         ra00 -= iw2 * iz8;
         A8[i+4] = ra00;
         ia00 += iw2 * rz8;
         A8[i+4+1] = ia00;
         ra10 -= iw3 * iz8;
         A8[i+4+2] = ra10;
         ia10 += iw3 * rz8;
         A8[i+4+3] = ia10;

         ra00 = A9[i+0];
         ia00 = A9[i+0+1];
         ra10 = A9[i+0+2];
         ia10 = A9[i+0+3];
         ra00 += rx0 * ry9;
         ia00 += rx0 * iy9;
         ra10 += rx1 * ry9;
         ia10 += rx1 * iy9;
         prefA(A9);
         ra00 -= ix0 * iy9;
         ia00 += ix0 * ry9;
         ra10 -= ix1 * iy9;
         ia10 += ix1 * ry9;
         ra00 += rw0 * rz9;
         ia00 += rw0 * iz9;
         ra10 += rw1 * rz9;
         ia10 += rw1 * iz9;
         ra00 -= iw0 * iz9;
         A9[i+0] = ra00;
         ia00 += iw0 * rz9;
         A9[i+0+1] = ia00;
         ra10 -= iw1 * iz9;
         A9[i+0+2] = ra10;
         ia10 += iw1 * rz9;
         A9[i+0+3] = ia10;
         ra00 = A9[i+4];
         ia00 = A9[i+4+1];
         ra10 = A9[i+4+2];
         ia10 = A9[i+4+3];
         ra00 += rx2 * ry9;
         ia00 += rx2 * iy9;
         ra10 += rx3 * ry9;
         ia10 += rx3 * iy9;
         ra00 -= ix2 * iy9;
         ia00 += ix2 * ry9;
         ra10 -= ix3 * iy9;
         ia10 += ix3 * ry9;
         ra00 += rw2 * rz9;
         ia00 += rw2 * iz9;
         ra10 += rw3 * rz9;
         ia10 += rw3 * iz9;
         ra00 -= iw2 * iz9;
         A9[i+4] = ra00;
         ia00 += iw2 * rz9;
         A9[i+4+1] = ia00;
         ra10 -= iw3 * iz9;
         A9[i+4+2] = ra10;
         ia10 += iw3 * rz9;
         A9[i+4+3] = ia10;

         ra00 = A10[i+0];
         ia00 = A10[i+0+1];
         ra10 = A10[i+0+2];
         ia10 = A10[i+0+3];
         ra00 += rx0 * ry10;
         ia00 += rx0 * iy10;
         ra10 += rx1 * ry10;
         ia10 += rx1 * iy10;
         prefA(A10);
         ra00 -= ix0 * iy10;
         ia00 += ix0 * ry10;
         ra10 -= ix1 * iy10;
         ia10 += ix1 * ry10;
         ra00 += rw0 * rz10;
         ia00 += rw0 * iz10;
         ra10 += rw1 * rz10;
         ia10 += rw1 * iz10;
         ra00 -= iw0 * iz10;
         A10[i+0] = ra00;
         ia00 += iw0 * rz10;
         A10[i+0+1] = ia00;
         ra10 -= iw1 * iz10;
         A10[i+0+2] = ra10;
         ia10 += iw1 * rz10;
         A10[i+0+3] = ia10;
         ra00 = A10[i+4];
         ia00 = A10[i+4+1];
         ra10 = A10[i+4+2];
         ia10 = A10[i+4+3];
         ra00 += rx2 * ry10;
         ia00 += rx2 * iy10;
         ra10 += rx3 * ry10;
         ia10 += rx3 * iy10;
         ra00 -= ix2 * iy10;
         ia00 += ix2 * ry10;
         ra10 -= ix3 * iy10;
         ia10 += ix3 * ry10;
         ra00 += rw2 * rz10;
         ia00 += rw2 * iz10;
         ra10 += rw3 * rz10;
         ia10 += rw3 * iz10;
         ra00 -= iw2 * iz10;
         A10[i+4] = ra00;
         ia00 += iw2 * rz10;
         A10[i+4+1] = ia00;
         ra10 -= iw3 * iz10;
         A10[i+4+2] = ra10;
         ia10 += iw3 * rz10;
         A10[i+4+3] = ia10;

         ra00 = A11[i+0];
         ia00 = A11[i+0+1];
         ra10 = A11[i+0+2];
         ia10 = A11[i+0+3];
         ra00 += rx0 * ry11;
         ia00 += rx0 * iy11;
         ra10 += rx1 * ry11;
         ia10 += rx1 * iy11;
         prefA(A11);
         ra00 -= ix0 * iy11;
         ia00 += ix0 * ry11;
         ra10 -= ix1 * iy11;
         ia10 += ix1 * ry11;
         ra00 += rw0 * rz11;
         ia00 += rw0 * iz11;
         ra10 += rw1 * rz11;
         ia10 += rw1 * iz11;
         ra00 -= iw0 * iz11;
         A11[i+0] = ra00;
         ia00 += iw0 * rz11;
         A11[i+0+1] = ia00;
         ra10 -= iw1 * iz11;
         A11[i+0+2] = ra10;
         ia10 += iw1 * rz11;
         A11[i+0+3] = ia10;
         ra00 = A11[i+4];
         ia00 = A11[i+4+1];
         ra10 = A11[i+4+2];
         ia10 = A11[i+4+3];
         ra00 += rx2 * ry11;
         ia00 += rx2 * iy11;
         ra10 += rx3 * ry11;
         ia10 += rx3 * iy11;
         ra00 -= ix2 * iy11;
         ia00 += ix2 * ry11;
         ra10 -= ix3 * iy11;
         ia10 += ix3 * ry11;
         ra00 += rw2 * rz11;
         ia00 += rw2 * iz11;
         ra10 += rw3 * rz11;
         ia10 += rw3 * iz11;
         ra00 -= iw2 * iz11;
         A11[i+4] = ra00;
         ia00 += iw2 * rz11;
         A11[i+4+1] = ia00;
         ra10 -= iw3 * iz11;
         A11[i+4+2] = ra10;
         ia10 += iw3 * rz11;
         A11[i+4+3] = ia10;

      }
      for (i=M4; i < M; i += 2)
      {
         const double rx0 = X[i], ix0 = X[i+1], rw0 = W[i], iw0 = W[i+1];
         A0[i] += rx0 * ry0 - ix0 * iy0 + rw0 * rz0 - iw0 * iz0 ;
         A0[i+1] += ix0 * ry0 + rx0 * iy0 + iw0 * rz0 + rw0 * iz0;
         A1[i] += rx0 * ry1 - ix0 * iy1 + rw0 * rz1 - iw0 * iz1 ;
         A1[i+1] += ix0 * ry1 + rx0 * iy1 + iw0 * rz1 + rw0 * iz1;
         A2[i] += rx0 * ry2 - ix0 * iy2 + rw0 * rz2 - iw0 * iz2 ;
         A2[i+1] += ix0 * ry2 + rx0 * iy2 + iw0 * rz2 + rw0 * iz2;
         A3[i] += rx0 * ry3 - ix0 * iy3 + rw0 * rz3 - iw0 * iz3 ;
         A3[i+1] += ix0 * ry3 + rx0 * iy3 + iw0 * rz3 + rw0 * iz3;
         A4[i] += rx0 * ry4 - ix0 * iy4 + rw0 * rz4 - iw0 * iz4 ;
         A4[i+1] += ix0 * ry4 + rx0 * iy4 + iw0 * rz4 + rw0 * iz4;
         A5[i] += rx0 * ry5 - ix0 * iy5 + rw0 * rz5 - iw0 * iz5 ;
         A5[i+1] += ix0 * ry5 + rx0 * iy5 + iw0 * rz5 + rw0 * iz5;
         A6[i] += rx0 * ry6 - ix0 * iy6 + rw0 * rz6 - iw0 * iz6 ;
         A6[i+1] += ix0 * ry6 + rx0 * iy6 + iw0 * rz6 + rw0 * iz6;
         A7[i] += rx0 * ry7 - ix0 * iy7 + rw0 * rz7 - iw0 * iz7 ;
         A7[i+1] += ix0 * ry7 + rx0 * iy7 + iw0 * rz7 + rw0 * iz7;
         A8[i] += rx0 * ry8 - ix0 * iy8 + rw0 * rz8 - iw0 * iz8 ;
         A8[i+1] += ix0 * ry8 + rx0 * iy8 + iw0 * rz8 + rw0 * iz8;
         A9[i] += rx0 * ry9 - ix0 * iy9 + rw0 * rz9 - iw0 * iz9 ;
         A9[i+1] += ix0 * ry9 + rx0 * iy9 + iw0 * rz9 + rw0 * iz9;
         A10[i] += rx0 * ry10 - ix0 * iy10 + rw0 * rz10 - iw0 * iz10 ;
         A10[i+1] += ix0 * ry10 + rx0 * iy10 + iw0 * rz10 + rw0 * iz10;
         A11[i] += rx0 * ry11 - ix0 * iy11 + rw0 * rz11 - iw0 * iz11 ;
         A11[i+1] += ix0 * ry11 + rx0 * iy11 + iw0 * rz11 + rw0 * iz11;
      }
      Z += 24;
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N12; j; j--, A += lda, Y += 2)
   {
      double *A0=A;
      const register double ry0=Y[0], rz0=Z[0], iy0=Y[1], iz0=Z[1];
      ATL_INT i;
      prefY(Y+24+24-1);
      for (i=0; i < M4; i += 8)
      {
         register double ra00, ia00, ra10, ia10;
         const double rx0=X[i+0], rw0=W[i+0], ix0=X[i+1], iw0=W[i+1],
                      rx1=X[i+2], rw1=W[i+2], ix1=X[i+3], iw1=W[i+3],
                      rx2=X[i+4], rw2=W[i+4], ix2=X[i+5], iw2=W[i+5],
                      rx3=X[i+6], rw3=W[i+6], ix3=X[i+7], iw3=W[i+7];

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
         ra00 = A0[i+4];
         ia00 = A0[i+4+1];
         ra10 = A0[i+4+2];
         ia10 = A0[i+4+3];
         ra00 += rx2 * ry0;
         ia00 += rx2 * iy0;
         ra10 += rx3 * ry0;
         ia10 += rx3 * iy0;
         ra00 -= ix2 * iy0;
         ia00 += ix2 * ry0;
         ra10 -= ix3 * iy0;
         ia10 += ix3 * ry0;
         ra00 += rw2 * rz0;
         ia00 += rw2 * iz0;
         ra10 += rw3 * rz0;
         ia10 += rw3 * iz0;
         ra00 -= iw2 * iz0;
         A0[i+4] = ra00;
         ia00 += iw2 * rz0;
         A0[i+4+1] = ia00;
         ra10 -= iw3 * iz0;
         A0[i+4+2] = ra10;
         ia10 += iw3 * rz0;
         A0[i+4+3] = ia10;

      }
      for (i=M4; i < M; i += 2)
      {
         const double rx0 = X[i], ix0 = X[i+1], rw0 = W[i], iw0 = W[i+1];
         A0[i] += rx0 * ry0 - ix0 * iy0 + rw0 * rz0 - iw0 * iz0 ;
         A0[i+1] += ix0 * ry0 + rx0 * iy0 + iw0 * rz0 + rw0 * iz0;
      }
      Z += 2;
   }
}
