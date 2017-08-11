#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

static void ATL_cJIK1x52x52TT1x2x4_a1_b1
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=T, MB=1, NB=52, KB=52, 
 * lda=0, ldb=0, ldc=0, mu=1, nu=2, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const float *stM = A + (((lda) << 1));
   const float *stN = B + 104;
   const float *pfA = A + M;
   #define incAk 8
   const int incAm = ((((lda) - 52) << 1)), incAn = -(((lda) << 1));
   const int incBk = (((ldb) << 1)), incBm = -(104*(ldb));
   #define incBn 4
   #define incCm 2
   const int incCn = (((ldc) << 2)) - 2;
   float *pC0=C, *pC1=pC0+(((ldc) << 1));
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0;
   register float rB0, rB1;
   register float rC0_0, rC0_1;
   do /* N-loop */
   {
      ATL_pfl1R(pfA+0);
      ATL_pfl1R(pfA+16);
      ATL_pfl1R(pfA+32);
      pfA += lda;
      rC0_0 = *pC0;
      rC0_1 = *pC1;
      for (k=0; k < 13; k++) /* easy loop to unroll */
      {
         rA0 = *pA0;
         rB0 = *pB0;
         rB1 = pB0[2];
         rC0_0 += rA0 * rB0;
         rC0_1 += rA0 * rB1;
         pB0 += incBk;
         rA0 = pA0[2];
         rB0 = *pB0;
         rB1 = pB0[2];
         rC0_0 += rA0 * rB0;
         rC0_1 += rA0 * rB1;
         pB0 += incBk;
         rA0 = pA0[4];
         rB0 = *pB0;
         rB1 = pB0[2];
         rC0_0 += rA0 * rB0;
         rC0_1 += rA0 * rB1;
         pB0 += incBk;
         rA0 = pA0[6];
         rB0 = *pB0;
         rB1 = pB0[2];
         rC0_0 += rA0 * rB0;
         rC0_1 += rA0 * rB1;
         pB0 += incBk;
         pA0 += incAk;
      }
      pB0 -= 0*incBk;
      *pC0 = rC0_0;
      *pC1 = rC0_1;
      pC0 += incCm;
      pC1 += incCm;
      pA0 += incAm;
      pB0 += incBm;
      pC0 += incCn;
      pC1 += incCn;
      pA0 += incAn;
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
void ATL_cJIK52x52x52TT0x0x0_a1_b1
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=T, MB=52, NB=52, KB=52, 
 * lda=0, ldb=0, ldc=0, mu=3, nu=2, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (102*(lda));
   const float *stN = B + 104;
   const float *pfA = A + M;
   #define incAk 8
   const int incAm = ((((((lda) << 1)+lda) - 52) << 1)), incAn = -(102*(lda));
   const int incBk = (((ldb) << 1)), incBm = -(104*(ldb));
   #define incBn 4
   #define incCm 6
   const int incCn = (((ldc) << 2)) - 102;
   float *pC0=C, *pC1=pC0+(((ldc) << 1));
   const float *pA0=A, *pA1=pA0+(((lda) << 1)), *pA2=pA1+(((lda) << 1));
   const float *pB0=B;
   register int k;
   register float rA0, rA1, rA2;
   register float rB0, rB1;
   register float rC0_0, rC1_0, rC2_0, rC0_1, rC1_1, rC2_1;
   do /* N-loop */
   {
      ATL_pfl1R(pfA+0);
      ATL_pfl1R(pfA+16);
      ATL_pfl1R(pfA+32);
      pfA += lda;
      do /* M-loop */
      {
         rC0_0 = *pC0;
         rC1_0 = pC0[2];
         rC2_0 = pC0[4];
         rC0_1 = *pC1;
         rC1_1 = pC1[2];
         rC2_1 = pC1[4];
         for (k=0; k < 13; k++) /* easy loop to unroll */
         {
            rA0 = *pA0;
            rB0 = *pB0;
            rA1 = *pA1;
            rA2 = *pA2;
            rC0_0 += rA0 * rB0;
            rB1 = pB0[2];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC0_1 += rA0 * rB1;
            rC1_1 += rA1 * rB1;
            rC2_1 += rA2 * rB1;
            pB0 += incBk;
            rA0 = pA0[2];
            rB0 = *pB0;
            rA1 = pA1[2];
            rA2 = pA2[2];
            rC0_0 += rA0 * rB0;
            rB1 = pB0[2];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC0_1 += rA0 * rB1;
            rC1_1 += rA1 * rB1;
            rC2_1 += rA2 * rB1;
            pB0 += incBk;
            rA0 = pA0[4];
            rB0 = *pB0;
            rA1 = pA1[4];
            rA2 = pA2[4];
            rC0_0 += rA0 * rB0;
            rB1 = pB0[2];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC0_1 += rA0 * rB1;
            rC1_1 += rA1 * rB1;
            rC2_1 += rA2 * rB1;
            pB0 += incBk;
            rA0 = pA0[6];
            rB0 = *pB0;
            rA1 = pA1[6];
            rA2 = pA2[6];
            rC0_0 += rA0 * rB0;
            rB1 = pB0[2];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC0_1 += rA0 * rB1;
            rC1_1 += rA1 * rB1;
            rC2_1 += rA2 * rB1;
            pB0 += incBk;
            pA0 += incAk;
            pA1 += incAk;
            pA2 += incAk;
         }
         pB0 -= 0*incBk;
         *pC0 = rC0_0;
         pC0[2] = rC1_0;
         pC0[4] = rC2_0;
         *pC1 = rC0_1;
         pC1[2] = rC1_1;
         pC1[4] = rC2_1;
         pC0 += incCm;
         pC1 += incCm;
         pA0 += incAm;
         pA1 += incAm;
         pA2 += incAm;
         pB0 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pC1 += incCn;
      pA0 += incAn;
      pA1 += incAn;
      pA2 += incAn;
      pB0 += incBn;
   }
   while(pB0 != stN);
   ATL_cJIK1x52x52TT1x2x4_a1_b1(1, 52, 52, alpha, ca + (102*(lda)), lda, cb, ldb, beta, cc + 102, ldc);
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
