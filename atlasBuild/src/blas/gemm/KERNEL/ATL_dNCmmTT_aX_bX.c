#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

void ATL_dJIK72x72x72TT0x0x0_aX_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=T, MB=72, NB=72, KB=72, 
 * lda=0, ldb=0, ldc=0, mu=3, nu=4, ku=1, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const double *stM = A + (((lda) << 6)+((lda) << 3));
   const double *stN = B + 72;
   const double *pfA = A + M;
   const double BetaAlpha = beta / alpha;
   #define incAk 1
   const int incAm = ((((lda) << 1)+lda) - 72), incAn = -(((lda) << 6)+((lda) << 3));
   const int incBk = (ldb), incBm = -(((ldb) << 6)+((ldb) << 3));
   #define incBn 4
   #define incCm 3
   const int incCn = (((ldc) << 2)) - 72;
   double *pC0=C, *pC1=pC0+(ldc), *pC2=pC1+(ldc), *pC3=pC2+(ldc);
   const double *pA0=A, *pA1=pA0+(lda), *pA2=pA1+(lda);
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
      ATL_pfl1R(pfA+48);
      ATL_pfl1R(pfA+56);
      ATL_pfl1R(pfA+64);
      pfA += lda;
      do /* M-loop */
      {
         rA0 = BetaAlpha;
         rC0_0 = *pC0;
         rC0_0 *= rA0;
         rC1_0 = pC0[1];
         rC1_0 *= rA0;
         rC2_0 = pC0[2];
         rC2_0 *= rA0;
         rC0_1 = *pC1;
         rC0_1 *= rA0;
         rC1_1 = pC1[1];
         rC1_1 *= rA0;
         rC2_1 = pC1[2];
         rC2_1 *= rA0;
         rC0_2 = *pC2;
         rC0_2 *= rA0;
         rC1_2 = pC2[1];
         rC1_2 *= rA0;
         rC2_2 = pC2[2];
         rC2_2 *= rA0;
         rC0_3 = *pC3;
         rC0_3 *= rA0;
         rC1_3 = pC3[1];
         rC1_3 *= rA0;
         rC2_3 = pC3[2];
         rC2_3 *= rA0;
         for (k=0; k < 72; k++) /* easy loop to unroll */
         {
            rA0 = *pA0;
            rB0 = *pB0;
            rA1 = *pA1;
            rA2 = *pA2;
            rB1 = pB0[1];
            rC0_0 += rA0 * rB0;
            rB2 = pB0[2];
            rB3 = pB0[3];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC0_1 += rA0 * rB1;
            rC1_1 += rA1 * rB1;
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
         }
         rB0 = alpha;
         rC0_0 *= rB0;
         rC0_1 *= rB0;
         rC0_2 *= rB0;
         rC0_3 *= rB0;
         rC1_0 *= rB0;
         rC1_1 *= rB0;
         rC1_2 *= rB0;
         rC1_3 *= rB0;
         rC2_0 *= rB0;
         rC2_1 *= rB0;
         rC2_2 *= rB0;
         rC2_3 *= rB0;
         *pC0 = rC0_0;
         pC0[1] = rC1_0;
         pC0[2] = rC2_0;
         *pC1 = rC0_1;
         pC1[1] = rC1_1;
         pC1[2] = rC2_1;
         *pC2 = rC0_2;
         pC2[1] = rC1_2;
         pC2[2] = rC2_2;
         *pC3 = rC0_3;
         pC3[1] = rC1_3;
         pC3[2] = rC2_3;
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
