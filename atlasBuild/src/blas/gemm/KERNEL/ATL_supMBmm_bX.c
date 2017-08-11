#define SREAL
#include "atlas_misc.h"
void ATL_supMBmm0_4_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm2_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm6_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm10_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm14_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm18_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm22_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm26_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm30_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm34_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm38_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm42_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm46_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm50_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm54_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm58_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm62_2_1_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supMBmm0_1_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_sgpMBmm_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);

typedef void (*MMfunc)(const int, const int, const int, const TYPE,
                       const TYPE *, const int, const TYPE *, const int,
                       const TYPE, TYPE *, const int);

void ATL_spMBmm_bX
   (const int M, const int N, const int K, const TYPE alpha,
    const TYPE *A, const int lda, const TYPE *B, const int ldb,
    const TYPE beta, TYPE *C, const int ldc)
{

   static MMfunc mmfunc[64] = 
   {
      NULL,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm2_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm6_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm10_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm14_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm18_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm22_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm26_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm30_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm34_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm38_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm42_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm46_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm50_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm54_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm58_2_1_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm0_4_0_bX,
      ATL_supMBmm0_1_0_bX,
      ATL_supMBmm62_2_1_bX,
      ATL_supMBmm0_1_0_bX
   };

   mmfunc[M](M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
