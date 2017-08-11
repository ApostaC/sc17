#define SREAL
#include "atlas_misc.h"
void ATL_supNBmm0_5_0_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supNBmm0_4_0_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supNBmm0_3_0_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supNBmm0_2_0_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_supNBmm0_1_0_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_sgpNBmm_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);

typedef void (*MMfunc)(const int, const int, const int, const TYPE,
                       const TYPE *, const int, const TYPE *, const int,
                       const TYPE, TYPE *, const int);

void ATL_spNBmm_b1
   (const int M, const int N, const int K, const TYPE alpha,
    const TYPE *A, const int lda, const TYPE *B, const int ldb,
    const TYPE beta, TYPE *C, const int ldc)
{

   static MMfunc mmfunc[64] = 
   {
      NULL,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_2_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_2_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_2_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_2_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_2_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_2_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_2_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_4_0_b1,
      ATL_supNBmm0_3_0_b1,
      ATL_supNBmm0_2_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_5_0_b1,
      ATL_supNBmm0_1_0_b1,
      ATL_supNBmm0_2_0_b1,
      ATL_supNBmm0_3_0_b1
   };

   mmfunc[N](M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
