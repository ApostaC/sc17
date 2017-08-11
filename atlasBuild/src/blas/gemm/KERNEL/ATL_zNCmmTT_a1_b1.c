#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

void ATL_zJIK48x48x48TT0x0x0_a1_b1
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=T, MB=48, NB=48, KB=48, 
 * lda=0, ldb=0, ldc=0, mu=3, nu=4, ku=48, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const double *stM = A + (((lda) << 6)+((lda) << 5));
   const double *stN = B + 96;
   const double *pfA = A + M;
   #define incAk 96
   const int incAm = ((((((lda) << 1)+lda) - 48) << 1)), incAn = -(((lda) << 6)+((lda) << 5));
   const int incBk = (((ldb) << 1)), incBm = -(((ldb) << 6)+((ldb) << 5));
   #define incBn 8
   #define incCm 6
   const int incCn = (((ldc) << 3)) - 96;
   double *pC0=C, *pC1=pC0+(((ldc) << 1)), *pC2=pC1+(((ldc) << 1)), *pC3=pC2+(((ldc) << 1));
   const double *pA0=A, *pA1=pA0+(((lda) << 1)), *pA2=pA1+(((lda) << 1));
   const double *pB0=B;
   register int k;
   register double rA0, rA1, rA2;
   register double rB0, rB1, rB2, rB3;
   register double rC0_0, rC1_0, rC2_0, rC0_1, rC1_1, rC2_1, rC0_2, rC1_2, rC2_2, rC0_3, rC1_3, rC2_3;
   do /* N-loop */
   {
      ATL_pfl1R(pfA+0);
      ATL_pfl1R(pfA+8);
      ATL_pfl1R(pfA+16);
      ATL_pfl1R(pfA+24);
      ATL_pfl1R(pfA+32);
      ATL_pfl1R(pfA+40);
      pfA += lda;
      do /* M-loop */
      {
         rC0_0 = *pC0;
         rC1_0 = pC0[2];
         rC2_0 = pC0[4];
         rC0_1 = *pC1;
         rC1_1 = pC1[2];
         rC2_1 = pC1[4];
         rC0_2 = *pC2;
         rC1_2 = pC2[2];
         rC2_2 = pC2[4];
         rC0_3 = *pC3;
         rC1_3 = pC3[2];
         rC2_3 = pC3[4];
         rA0 = *pA0;
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = *pA1;
         rC1_0 += rA1 * rB0;
         rA2 = *pA2;
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[2];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[2];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[2];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[4];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[4];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[4];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[6];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[6];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[6];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[8];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[8];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[8];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[10];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[10];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[10];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[12];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[12];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[12];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[14];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[14];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[14];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[16];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[16];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[16];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[18];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[18];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[18];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[20];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[20];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[20];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[22];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[22];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[22];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[24];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[24];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[24];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[26];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[26];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[26];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[28];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[28];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[28];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[30];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[30];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[30];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[32];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[32];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[32];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[34];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[34];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[34];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[36];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[36];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[36];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[38];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[38];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[38];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[40];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[40];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[40];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[42];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[42];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[42];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[44];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[44];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[44];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[46];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[46];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[46];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[48];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[48];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[48];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[50];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[50];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[50];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[52];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[52];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[52];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[54];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[54];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[54];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[56];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[56];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[56];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[58];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[58];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[58];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[60];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[60];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[60];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[62];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[62];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[62];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[64];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[64];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[64];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[66];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[66];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[66];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[68];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[68];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[68];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[70];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[70];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[70];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[72];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[72];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[72];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[74];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[74];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[74];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[76];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[76];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[76];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[78];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[78];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[78];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[80];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[80];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[80];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[82];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[82];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[82];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[84];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[84];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[84];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[86];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[86];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[86];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[88];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[88];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[88];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[90];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[90];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[90];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[92];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[92];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[92];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         rA0 = pA0[94];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[94];
         rC1_0 += rA1 * rB0;
         rA2 = pA2[94];
         rC2_0 += rA2 * rB0;
         rB1 = pB0[2];
         rC0_1 += rA0 * rB1;
         rB2 = pB0[4];
         rC1_1 += rA1 * rB1;
         rB3 = pB0[6];
         rC2_1 += rA2 * rB1;
         rC0_2 += rA0 * rB2;
         rC1_2 += rA1 * rB2;
         rC2_2 += rA2 * rB2;
         rC0_3 += rA0 * rB3;
         rC1_3 += rA1 * rB3;
         rC2_3 += rA2 * rB3;
         pB0 += incBk;
         pA0 += incAk;
         pA1 += incAk;
         pA2 += incAk;
         *pC0 = rC0_0;
         pC0[2] = rC1_0;
         pC0[4] = rC2_0;
         *pC1 = rC0_1;
         pC1[2] = rC1_1;
         pC1[4] = rC2_1;
         *pC2 = rC0_2;
         pC2[2] = rC1_2;
         pC2[4] = rC2_2;
         *pC3 = rC0_3;
         pC3[2] = rC1_3;
         pC3[4] = rC2_3;
         pC0 += incCm;
         pC1 += incCm;
         pC2 += incCm;
         pC3 += incCm;
         pA0 += incAm;
         pA1 += incAm;
         pA2 += incAm;
         pB0 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pC1 += incCn;
      pC2 += incCn;
      pC3 += incCn;
      pA0 += incAn;
      pA1 += incAn;
      pA2 += incAn;
      pB0 += incBn;
   }
   while(pB0 != stN);
}
#ifdef incAm
   #undef incAm
#endif
#ifdef incAn
   #undef incAn
#endif
#ifdef incAk
   #undef incAk
#endif
#ifdef incBm
   #undef incBm
#endif
#ifdef incBn
   #undef incBn
#endif
#ifdef incBk
   #undef incBk
#endif
#ifdef incCm
   #undef incCm
#endif
#ifdef incCn
   #undef incCn
#endif
#ifdef incCk
   #undef incCk
#endif
#ifdef Mb
   #undef Mb
#endif
#ifdef Nb
   #undef Nb
#endif
#ifdef Kb
   #undef Kb
#endif
