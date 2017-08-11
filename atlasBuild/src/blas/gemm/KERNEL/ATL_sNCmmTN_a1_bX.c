#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
void ATL_sJIK72x72x72TN0x0x0_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=72, NB=72, KB=72, 
 * lda=0, ldb=0, ldc=0, mu=3, nu=2, ku=72, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const float *stM = A + (((lda) << 6)+((lda) << 3));
   const float *stN = B + (((ldb) << 6)+((ldb) << 3));
   #define incAk 72
   const int incAm = ((((lda) << 1)+lda) - 72), incAn = -(((lda) << 6)+((lda) << 3));
   #define incBk 72
   const int incBm = -72, incBn = (((ldb) << 1));
   const int incAk0 = ((incAk) / 72), incBk0 = ((incBk) / 72);
   #define incCm 3
   const int incCn = (((ldc) << 1)) - 72;
   float *pC0=C, *pC1=pC0+(ldc);
   const float *pA0=A, *pA1=pA0+(lda), *pA2=pA1+(lda);
   const float *pB0=B, *pB1=pB0+(ldb);
   register int k;
   register float rA0, rA1, rA2;
   register float rB0, rB1;
   register float m0, m1;
   register float rC0_0, rC1_0, rC2_0, rC0_1, rC1_1, rC2_1;
   do /* N-loop */
   {
      do /* M-loop */
      {
         rA0 = beta;
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
/*
 *       Start pipeline
 */
         rA0 = *pA0;
         rB0 = *pB0;
         rA1 = *pA1;
         rA2 = *pA2;
         m0 = rA0 * rB0;
         rB1 = *pB1;
         m1 = rA1 * rB0;

/*
 *       Completely unrolled K-loop
 */
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[1];
         rB0 = pB0[1];
         rA1 = pA1[1];
         rA2 = pA2[1];
         rB1 = pB1[1];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[2];
         rB0 = pB0[2];
         rA1 = pA1[2];
         rA2 = pA2[2];
         rB1 = pB1[2];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[3];
         rB0 = pB0[3];
         rA1 = pA1[3];
         rA2 = pA2[3];
         rB1 = pB1[3];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[4];
         rB0 = pB0[4];
         rA1 = pA1[4];
         rA2 = pA2[4];
         rB1 = pB1[4];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[5];
         rB0 = pB0[5];
         rA1 = pA1[5];
         rA2 = pA2[5];
         rB1 = pB1[5];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[6];
         rB0 = pB0[6];
         rA1 = pA1[6];
         rA2 = pA2[6];
         rB1 = pB1[6];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[7];
         rB0 = pB0[7];
         rA1 = pA1[7];
         rA2 = pA2[7];
         rB1 = pB1[7];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[8];
         rB0 = pB0[8];
         rA1 = pA1[8];
         rA2 = pA2[8];
         rB1 = pB1[8];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[9];
         rB0 = pB0[9];
         rA1 = pA1[9];
         rA2 = pA2[9];
         rB1 = pB1[9];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[10];
         rB0 = pB0[10];
         rA1 = pA1[10];
         rA2 = pA2[10];
         rB1 = pB1[10];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[11];
         rB0 = pB0[11];
         rA1 = pA1[11];
         rA2 = pA2[11];
         rB1 = pB1[11];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[12];
         rB0 = pB0[12];
         rA1 = pA1[12];
         rA2 = pA2[12];
         rB1 = pB1[12];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[13];
         rB0 = pB0[13];
         rA1 = pA1[13];
         rA2 = pA2[13];
         rB1 = pB1[13];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[14];
         rB0 = pB0[14];
         rA1 = pA1[14];
         rA2 = pA2[14];
         rB1 = pB1[14];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[15];
         rB0 = pB0[15];
         rA1 = pA1[15];
         rA2 = pA2[15];
         rB1 = pB1[15];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[16];
         rB0 = pB0[16];
         rA1 = pA1[16];
         rA2 = pA2[16];
         rB1 = pB1[16];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[17];
         rB0 = pB0[17];
         rA1 = pA1[17];
         rA2 = pA2[17];
         rB1 = pB1[17];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[18];
         rB0 = pB0[18];
         rA1 = pA1[18];
         rA2 = pA2[18];
         rB1 = pB1[18];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[19];
         rB0 = pB0[19];
         rA1 = pA1[19];
         rA2 = pA2[19];
         rB1 = pB1[19];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[20];
         rB0 = pB0[20];
         rA1 = pA1[20];
         rA2 = pA2[20];
         rB1 = pB1[20];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[21];
         rB0 = pB0[21];
         rA1 = pA1[21];
         rA2 = pA2[21];
         rB1 = pB1[21];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[22];
         rB0 = pB0[22];
         rA1 = pA1[22];
         rA2 = pA2[22];
         rB1 = pB1[22];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[23];
         rB0 = pB0[23];
         rA1 = pA1[23];
         rA2 = pA2[23];
         rB1 = pB1[23];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[24];
         rB0 = pB0[24];
         rA1 = pA1[24];
         rA2 = pA2[24];
         rB1 = pB1[24];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[25];
         rB0 = pB0[25];
         rA1 = pA1[25];
         rA2 = pA2[25];
         rB1 = pB1[25];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[26];
         rB0 = pB0[26];
         rA1 = pA1[26];
         rA2 = pA2[26];
         rB1 = pB1[26];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[27];
         rB0 = pB0[27];
         rA1 = pA1[27];
         rA2 = pA2[27];
         rB1 = pB1[27];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[28];
         rB0 = pB0[28];
         rA1 = pA1[28];
         rA2 = pA2[28];
         rB1 = pB1[28];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[29];
         rB0 = pB0[29];
         rA1 = pA1[29];
         rA2 = pA2[29];
         rB1 = pB1[29];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[30];
         rB0 = pB0[30];
         rA1 = pA1[30];
         rA2 = pA2[30];
         rB1 = pB1[30];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[31];
         rB0 = pB0[31];
         rA1 = pA1[31];
         rA2 = pA2[31];
         rB1 = pB1[31];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[32];
         rB0 = pB0[32];
         rA1 = pA1[32];
         rA2 = pA2[32];
         rB1 = pB1[32];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[33];
         rB0 = pB0[33];
         rA1 = pA1[33];
         rA2 = pA2[33];
         rB1 = pB1[33];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[34];
         rB0 = pB0[34];
         rA1 = pA1[34];
         rA2 = pA2[34];
         rB1 = pB1[34];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[35];
         rB0 = pB0[35];
         rA1 = pA1[35];
         rA2 = pA2[35];
         rB1 = pB1[35];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[36];
         rB0 = pB0[36];
         rA1 = pA1[36];
         rA2 = pA2[36];
         rB1 = pB1[36];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[37];
         rB0 = pB0[37];
         rA1 = pA1[37];
         rA2 = pA2[37];
         rB1 = pB1[37];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[38];
         rB0 = pB0[38];
         rA1 = pA1[38];
         rA2 = pA2[38];
         rB1 = pB1[38];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[39];
         rB0 = pB0[39];
         rA1 = pA1[39];
         rA2 = pA2[39];
         rB1 = pB1[39];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[40];
         rB0 = pB0[40];
         rA1 = pA1[40];
         rA2 = pA2[40];
         rB1 = pB1[40];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[41];
         rB0 = pB0[41];
         rA1 = pA1[41];
         rA2 = pA2[41];
         rB1 = pB1[41];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[42];
         rB0 = pB0[42];
         rA1 = pA1[42];
         rA2 = pA2[42];
         rB1 = pB1[42];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[43];
         rB0 = pB0[43];
         rA1 = pA1[43];
         rA2 = pA2[43];
         rB1 = pB1[43];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[44];
         rB0 = pB0[44];
         rA1 = pA1[44];
         rA2 = pA2[44];
         rB1 = pB1[44];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[45];
         rB0 = pB0[45];
         rA1 = pA1[45];
         rA2 = pA2[45];
         rB1 = pB1[45];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[46];
         rB0 = pB0[46];
         rA1 = pA1[46];
         rA2 = pA2[46];
         rB1 = pB1[46];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[47];
         rB0 = pB0[47];
         rA1 = pA1[47];
         rA2 = pA2[47];
         rB1 = pB1[47];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[48];
         rB0 = pB0[48];
         rA1 = pA1[48];
         rA2 = pA2[48];
         rB1 = pB1[48];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[49];
         rB0 = pB0[49];
         rA1 = pA1[49];
         rA2 = pA2[49];
         rB1 = pB1[49];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[50];
         rB0 = pB0[50];
         rA1 = pA1[50];
         rA2 = pA2[50];
         rB1 = pB1[50];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[51];
         rB0 = pB0[51];
         rA1 = pA1[51];
         rA2 = pA2[51];
         rB1 = pB1[51];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[52];
         rB0 = pB0[52];
         rA1 = pA1[52];
         rA2 = pA2[52];
         rB1 = pB1[52];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[53];
         rB0 = pB0[53];
         rA1 = pA1[53];
         rA2 = pA2[53];
         rB1 = pB1[53];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[54];
         rB0 = pB0[54];
         rA1 = pA1[54];
         rA2 = pA2[54];
         rB1 = pB1[54];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[55];
         rB0 = pB0[55];
         rA1 = pA1[55];
         rA2 = pA2[55];
         rB1 = pB1[55];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[56];
         rB0 = pB0[56];
         rA1 = pA1[56];
         rA2 = pA2[56];
         rB1 = pB1[56];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[57];
         rB0 = pB0[57];
         rA1 = pA1[57];
         rA2 = pA2[57];
         rB1 = pB1[57];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[58];
         rB0 = pB0[58];
         rA1 = pA1[58];
         rA2 = pA2[58];
         rB1 = pB1[58];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[59];
         rB0 = pB0[59];
         rA1 = pA1[59];
         rA2 = pA2[59];
         rB1 = pB1[59];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[60];
         rB0 = pB0[60];
         rA1 = pA1[60];
         rA2 = pA2[60];
         rB1 = pB1[60];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[61];
         rB0 = pB0[61];
         rA1 = pA1[61];
         rA2 = pA2[61];
         rB1 = pB1[61];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[62];
         rB0 = pB0[62];
         rA1 = pA1[62];
         rA2 = pA2[62];
         rB1 = pB1[62];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[63];
         rB0 = pB0[63];
         rA1 = pA1[63];
         rA2 = pA2[63];
         rB1 = pB1[63];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[64];
         rB0 = pB0[64];
         rA1 = pA1[64];
         rA2 = pA2[64];
         rB1 = pB1[64];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[65];
         rB0 = pB0[65];
         rA1 = pA1[65];
         rA2 = pA2[65];
         rB1 = pB1[65];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[66];
         rB0 = pB0[66];
         rA1 = pA1[66];
         rA2 = pA2[66];
         rB1 = pB1[66];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[67];
         rB0 = pB0[67];
         rA1 = pA1[67];
         rA2 = pA2[67];
         rB1 = pB1[67];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[68];
         rB0 = pB0[68];
         rA1 = pA1[68];
         rA2 = pA2[68];
         rB1 = pB1[68];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[69];
         rB0 = pB0[69];
         rA1 = pA1[69];
         rA2 = pA2[69];
         rB1 = pB1[69];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[70];
         rB0 = pB0[70];
         rA1 = pA1[70];
         rA2 = pA2[70];
         rB1 = pB1[70];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rA0 = pA0[71];
         rB0 = pB0[71];
         rA1 = pA1[71];
         rA2 = pA2[71];
         rB1 = pB1[71];
         rC1_1 += m0;
         m0 = rA0 * rB0;
         rC2_1 += m1;
         m1 = rA1 * rB0;
/*
 *       Drain pipe on last iteration of K-loop
 */
         rC0_0 += m0;
         m0 = rA2 * rB0;
         rC1_0 += m1;
         m1 = rA0 * rB1;
         rC2_0 += m0;
         m0 = rA1 * rB1;
         rC0_1 += m1;
         m1 = rA2 * rB1;
         rC1_1 += m0;
         rC2_1 += m1;
         pA0 += incAk;
         pA1 += incAk;
         pA2 += incAk;
         pB0 += incBk;
         pB1 += incBk;
         *pC0 = rC0_0;
         pC0[1] = rC1_0;
         pC0[2] = rC2_0;
         *pC1 = rC0_1;
         pC1[1] = rC1_1;
         pC1[2] = rC2_1;
         pC0 += incCm;
         pC1 += incCm;
         pA0 += incAm;
         pA1 += incAm;
         pA2 += incAm;
         pB0 += incBm;
         pB1 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pC1 += incCn;
      pA0 += incAn;
      pA1 += incAn;
      pA2 += incAn;
      pB0 += incBn;
      pB1 += incBn;
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
