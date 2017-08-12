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

#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

static void ATL_cJIK0x0x52NN1x1x4_aX_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=N, TB=N, MB=0, NB=0, KB=52, 
 * lda=0, ldb=0, ldc=0, mu=1, nu=1, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Mb M
   #define Nb N
   const float *stM = A + (((Mb) << 1));
   const float *stN = B + (((ldb*Nb) << 1));
   const float *pfA = A + lda*M;
   const float BetaAlpha = beta / alpha;
   const int incAk = (((lda) << 1));
   const int incAm = 2 - (104*(lda)), incAn = -(((Mb) << 1));
   #define incBk 8
   const int incBm = -104, incBn = (((ldb) << 1));
   #define incCm 2
   const int incCn = (((ldc) << 1)) - (((Mb) << 1));
   float *pC0=C;
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0;
   register float rB0;
   register float rC0_0;
   do /* N-loop */
   {
      ATL_pfl1R(pfA+0);
      ATL_pfl1R(pfA+16);
      ATL_pfl1R(pfA+32);
      pfA += lda;
      do /* M-loop */
      {
         rA0 = BetaAlpha;
         rC0_0 = *pC0;
         rC0_0 *= rA0;
         for (k=0; k < 13; k++) /* easy loop to unroll */
         {
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            rA0 = *pA0;
            rB0 = pB0[2];
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            rA0 = *pA0;
            rB0 = pB0[4];
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            rA0 = *pA0;
            rB0 = pB0[6];
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
         }
         pA0 -= 0*incAk;
         rB0 = alpha;
         rC0_0 *= rB0;
         *pC0 = rC0_0;
         pC0 += incCm;
         pA0 += incAm;
         pB0 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
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
static void ATL_cJIK0x0x52NN3x1x4_aX_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=N, TB=N, MB=0, NB=0, KB=52, 
 * lda=0, ldb=0, ldc=0, mu=3, nu=1, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const int Mb = (M/3)*3;
   #define Nb N
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (((Mb) << 1));
   const float *stN = B + (((ldb*Nb) << 1));
   const float *pfA = A + lda*M;
   const float BetaAlpha = beta / alpha;
   const int incAk = (((lda) << 1));
   const int incAm = 6 - (104*(lda)), incAn = -(((Mb) << 1));
   #define incBk 8
   const int incBm = -104, incBn = (((ldb) << 1));
   #define incCm 6
   const int incCn = (((ldc) << 1)) - (((Mb) << 1));
   float *pC0=C;
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0, rA1, rA2;
   register float rB0;
   register float rC0_0, rC1_0, rC2_0;
   if (pA0 != stM)
   {
      do /* N-loop */
      {
         ATL_pfl1R(pfA+0);
         ATL_pfl1R(pfA+16);
         ATL_pfl1R(pfA+32);
         pfA += lda;
         do /* M-loop */
         {
            rA0 = BetaAlpha;
            rC0_0 = *pC0;
            rC0_0 *= rA0;
            rC1_0 = pC0[2];
            rC1_0 *= rA0;
            rC2_0 = pC0[4];
            rC2_0 *= rA0;
            for (k=0; k < 13; k++) /* easy loop to unroll */
            {
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[2];
               rA2 = pA0[4];
               rC0_0 += rA0 * rB0;
               rC1_0 += rA1 * rB0;
               rC2_0 += rA2 * rB0;
               pA0 += incAk;
               rA0 = *pA0;
               rB0 = pB0[2];
               rA1 = pA0[2];
               rA2 = pA0[4];
               rC0_0 += rA0 * rB0;
               rC1_0 += rA1 * rB0;
               rC2_0 += rA2 * rB0;
               pA0 += incAk;
               rA0 = *pA0;
               rB0 = pB0[4];
               rA1 = pA0[2];
               rA2 = pA0[4];
               rC0_0 += rA0 * rB0;
               rC1_0 += rA1 * rB0;
               rC2_0 += rA2 * rB0;
               pA0 += incAk;
               rA0 = *pA0;
               rB0 = pB0[6];
               rA1 = pA0[2];
               rA2 = pA0[4];
               rC0_0 += rA0 * rB0;
               rC1_0 += rA1 * rB0;
               rC2_0 += rA2 * rB0;
               pA0 += incAk;
               pB0 += incBk;
            }
            pA0 -= 0*incAk;
            rB0 = alpha;
            rC0_0 *= rB0;
            rC1_0 *= rB0;
            rC2_0 *= rB0;
            *pC0 = rC0_0;
            pC0[2] = rC1_0;
            pC0[4] = rC2_0;
            pC0 += incCm;
            pA0 += incAm;
            pB0 += incBm;
         }
         while(pA0 != stM);
         pC0 += incCn;
         pA0 += incAn;
         pB0 += incBn;
      }
      while(pB0 != stN);
   }
   if (k=M-Mb)
      ATL_cJIK0x0x52NN1x1x4_aX_bX(k, N, 52, alpha, ca + (((Mb) << 1)), lda, cb, ldb, beta, cc + (((Mb) << 1)), ldc);
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
#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

static void ATL_cJIK0x0x52NN1x2x4_aX_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=N, TB=N, MB=0, NB=0, KB=52, 
 * lda=0, ldb=0, ldc=0, mu=1, nu=2, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Mb M
   const int Nb = (N>>1)<<1;
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (((Mb) << 1));
   const float *stN = B + (((ldb*Nb) << 1));
   const float *pfA = A + lda*M;
   const float BetaAlpha = beta / alpha;
   const int incAk = (((lda) << 1));
   const int incAm = 2 - (104*(lda)), incAn = -(((Mb) << 1));
   #define incBk 8
   const int incBm = -104, incBn = (((ldb) << 2));
   #define incCm 2
   const int incCn = (((ldc) << 2)) - (((Mb) << 1));
   float *pC0=C, *pC1=pC0+(((ldc) << 1));
   const float *pA0=A;
   const float *pB0=B, *pB1=pB0+(((ldb) << 1));
   register int k;
   register float rA0;
   register float rB0, rB1;
   register float rC0_0, rC0_1;
   if (pB0 != stN)
   {
      do /* N-loop */
      {
         ATL_pfl1R(pfA+0);
         ATL_pfl1R(pfA+16);
         ATL_pfl1R(pfA+32);
         pfA += lda;
         do /* M-loop */
         {
            rA0 = BetaAlpha;
            rC0_0 = *pC0;
            rC0_0 *= rA0;
            rC0_1 = *pC1;
            rC0_1 *= rA0;
            for (k=0; k < 13; k++) /* easy loop to unroll */
            {
               rA0 = *pA0;
               rB0 = *pB0;
               rB1 = *pB1;
               rC0_0 += rA0 * rB0;
               rC0_1 += rA0 * rB1;
               pA0 += incAk;
               rA0 = *pA0;
               rB0 = pB0[2];
               rB1 = pB1[2];
               rC0_0 += rA0 * rB0;
               rC0_1 += rA0 * rB1;
               pA0 += incAk;
               rA0 = *pA0;
               rB0 = pB0[4];
               rB1 = pB1[4];
               rC0_0 += rA0 * rB0;
               rC0_1 += rA0 * rB1;
               pA0 += incAk;
               rA0 = *pA0;
               rB0 = pB0[6];
               rB1 = pB1[6];
               rC0_0 += rA0 * rB0;
               rC0_1 += rA0 * rB1;
               pA0 += incAk;
               pB0 += incBk;
               pB1 += incBk;
            }
            pA0 -= 0*incAk;
            rB0 = alpha;
            rC0_0 *= rB0;
            rC0_1 *= rB0;
            *pC0 = rC0_0;
            *pC1 = rC0_1;
            pC0 += incCm;
            pC1 += incCm;
            pA0 += incAm;
            pB0 += incBm;
            pB1 += incBm;
         }
         while(pA0 != stM);
         pC0 += incCn;
         pC1 += incCn;
         pA0 += incAn;
         pB0 += incBn;
         pB1 += incBn;
      }
      while(pB0 != stN);
   }
   if (k=N-Nb)
      ATL_cJIK0x0x52NN1x1x4_aX_bX(M, k, 52, alpha, ca, lda, cb + (((Nb*ldb) << 1)), ldb, beta, cc + (((Nb*ldc) << 1)), ldc);
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
void ATL_cJIK0x0x52NN0x0x0_aX_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=N, TB=N, MB=0, NB=0, KB=52, 
 * lda=0, ldb=0, ldc=0, mu=3, nu=2, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const int Mb = (M/3)*3;
   const int Nb = (N>>1)<<1;
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (((Mb) << 1));
   const float *stN = B + (((ldb*Nb) << 1));
   const float *pfA = A + lda*M;
   const float BetaAlpha = beta / alpha;
   const int incAk = (((lda) << 1));
   const int incAm = 6 - (104*(lda)), incAn = -(((Mb) << 1));
   #define incBk 8
   const int incBm = -104, incBn = (((ldb) << 2));
   #define incCm 6
   const int incCn = (((ldc) << 2)) - (((Mb) << 1));
   float *pC0=C, *pC1=pC0+(((ldc) << 1));
   const float *pA0=A;
   const float *pB0=B, *pB1=pB0+(((ldb) << 1));
   register int k;
   register float rA0, rA1, rA2;
   register float rB0, rB1;
   register float rC0_0, rC1_0, rC2_0, rC0_1, rC1_1, rC2_1;
   if (pA0 != stM)
   {
      if (pB0 != stN)
      {
         do /* N-loop */
         {
            ATL_pfl1R(pfA+0);
            ATL_pfl1R(pfA+16);
            ATL_pfl1R(pfA+32);
            pfA += lda;
            do /* M-loop */
            {
               rA0 = BetaAlpha;
               rC0_0 = *pC0;
               rC0_0 *= rA0;
               rC1_0 = pC0[2];
               rC1_0 *= rA0;
               rC2_0 = pC0[4];
               rC2_0 *= rA0;
               rC0_1 = *pC1;
               rC0_1 *= rA0;
               rC1_1 = pC1[2];
               rC1_1 *= rA0;
               rC2_1 = pC1[4];
               rC2_1 *= rA0;
               for (k=0; k < 13; k++) /* easy loop to unroll */
               {
                  rA0 = *pA0;
                  rB0 = *pB0;
                  rA1 = pA0[2];
                  rA2 = pA0[4];
                  rC0_0 += rA0 * rB0;
                  rB1 = *pB1;
                  rC1_0 += rA1 * rB0;
                  rC2_0 += rA2 * rB0;
                  rC0_1 += rA0 * rB1;
                  rC1_1 += rA1 * rB1;
                  rC2_1 += rA2 * rB1;
                  pA0 += incAk;
                  rA0 = *pA0;
                  rB0 = pB0[2];
                  rA1 = pA0[2];
                  rA2 = pA0[4];
                  rC0_0 += rA0 * rB0;
                  rB1 = pB1[2];
                  rC1_0 += rA1 * rB0;
                  rC2_0 += rA2 * rB0;
                  rC0_1 += rA0 * rB1;
                  rC1_1 += rA1 * rB1;
                  rC2_1 += rA2 * rB1;
                  pA0 += incAk;
                  rA0 = *pA0;
                  rB0 = pB0[4];
                  rA1 = pA0[2];
                  rA2 = pA0[4];
                  rC0_0 += rA0 * rB0;
                  rB1 = pB1[4];
                  rC1_0 += rA1 * rB0;
                  rC2_0 += rA2 * rB0;
                  rC0_1 += rA0 * rB1;
                  rC1_1 += rA1 * rB1;
                  rC2_1 += rA2 * rB1;
                  pA0 += incAk;
                  rA0 = *pA0;
                  rB0 = pB0[6];
                  rA1 = pA0[2];
                  rA2 = pA0[4];
                  rC0_0 += rA0 * rB0;
                  rB1 = pB1[6];
                  rC1_0 += rA1 * rB0;
                  rC2_0 += rA2 * rB0;
                  rC0_1 += rA0 * rB1;
                  rC1_1 += rA1 * rB1;
                  rC2_1 += rA2 * rB1;
                  pA0 += incAk;
                  pB0 += incBk;
                  pB1 += incBk;
               }
               pA0 -= 0*incAk;
               rB0 = alpha;
               rC0_0 *= rB0;
               rC0_1 *= rB0;
               rC1_0 *= rB0;
               rC1_1 *= rB0;
               rC2_0 *= rB0;
               rC2_1 *= rB0;
               *pC0 = rC0_0;
               pC0[2] = rC1_0;
               pC0[4] = rC2_0;
               *pC1 = rC0_1;
               pC1[2] = rC1_1;
               pC1[4] = rC2_1;
               pC0 += incCm;
               pC1 += incCm;
               pA0 += incAm;
               pB0 += incBm;
               pB1 += incBm;
            }
            while(pA0 != stM);
            pC0 += incCn;
            pC1 += incCn;
            pA0 += incAn;
            pB0 += incBn;
            pB1 += incBn;
         }
         while(pB0 != stN);
      }
   }
   if (k=N-Nb)
      ATL_cJIK0x0x52NN3x1x4_aX_bX(M, k, 52, alpha, ca, lda, cb + (((Nb*ldb) << 1)), ldb, beta, cc + (((Nb*ldc) << 1)), ldc);
   if (Nb && (k=M-Mb))
      ATL_cJIK0x0x52NN1x2x4_aX_bX(k, Nb, 52, alpha, ca + (((Mb) << 1)), lda, cb, ldb, beta, cc + (((Mb) << 1)), ldc);
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