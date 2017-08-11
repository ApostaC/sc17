#define SCPLX
#include "atlas_misc.h"
void ATL_cupNBmm0_5_0_b0
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupNBmm0_3_0_b0
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupNBmm0_2_0_b0
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupNBmm0_1_0_b0
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cgpNBmm_b0
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupNBmm0_5_0_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupNBmm0_3_0_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupNBmm0_2_0_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupNBmm0_1_0_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cgpNBmm_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupNBmm0_5_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupNBmm0_3_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupNBmm0_2_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupNBmm0_1_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cgpNBmm_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);

static void ATL_CupNBmm0_5_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc)
{
   const float *rA = A + lda*M, *rB = B + ldb*N;
   ATL_cupNBmm0_5_0_bX(M, N, K, alpha, A, lda, B, ldb, -beta, C, ldc); 
   ATL_cupNBmm0_5_0_bX(M, N, K, alpha, A, lda, rB, ldb, beta, C+1, ldc); 
   ATL_cupNBmm0_5_0_bX(M, N, K, alpha, rA, lda, rB, ldb, ATL_rnone, C, ldc); 
   ATL_cupNBmm0_5_0_b1(M, N, K, alpha, rA, lda, B, ldb, ATL_rone, C+1, ldc); 
}
static void ATL_CupNBmm0_3_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc)
{
   const float *rA = A + lda*M, *rB = B + ldb*N;
   ATL_cupNBmm0_3_0_bX(M, N, K, alpha, A, lda, B, ldb, -beta, C, ldc); 
   ATL_cupNBmm0_3_0_bX(M, N, K, alpha, A, lda, rB, ldb, beta, C+1, ldc); 
   ATL_cupNBmm0_3_0_bX(M, N, K, alpha, rA, lda, rB, ldb, ATL_rnone, C, ldc); 
   ATL_cupNBmm0_3_0_b1(M, N, K, alpha, rA, lda, B, ldb, ATL_rone, C+1, ldc); 
}
static void ATL_CupNBmm0_2_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc)
{
   const float *rA = A + lda*M, *rB = B + ldb*N;
   ATL_cupNBmm0_2_0_bX(M, N, K, alpha, A, lda, B, ldb, -beta, C, ldc); 
   ATL_cupNBmm0_2_0_bX(M, N, K, alpha, A, lda, rB, ldb, beta, C+1, ldc); 
   ATL_cupNBmm0_2_0_bX(M, N, K, alpha, rA, lda, rB, ldb, ATL_rnone, C, ldc); 
   ATL_cupNBmm0_2_0_b1(M, N, K, alpha, rA, lda, B, ldb, ATL_rone, C+1, ldc); 
}
static void ATL_CupNBmm0_1_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc)
{
   const float *rA = A + lda*M, *rB = B + ldb*N;
   ATL_cupNBmm0_1_0_bX(M, N, K, alpha, A, lda, B, ldb, -beta, C, ldc); 
   ATL_cupNBmm0_1_0_bX(M, N, K, alpha, A, lda, rB, ldb, beta, C+1, ldc); 
   ATL_cupNBmm0_1_0_bX(M, N, K, alpha, rA, lda, rB, ldb, ATL_rnone, C, ldc); 
   ATL_cupNBmm0_1_0_b1(M, N, K, alpha, rA, lda, B, ldb, ATL_rone, C+1, ldc); 
}

typedef void (*MMfunc)(const int, const int, const int, const TYPE,
                       const TYPE *, const int, const TYPE *, const int,
                       const TYPE, TYPE *, const int);

void ATL_cpNBmm_bX
   (const int M, const int N, const int K, const TYPE alpha,
    const TYPE *A, const int lda, const TYPE *B, const int ldb,
    const TYPE beta, TYPE *C, const int ldc)
{

   static MMfunc mmfunc[80] = 
   {
      NULL,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_5_0_bX,
      ATL_CupNBmm0_2_0_bX,
      ATL_CupNBmm0_1_0_bX,
      ATL_CupNBmm0_3_0_bX,
      ATL_CupNBmm0_1_0_bX
   };

   mmfunc[N](M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
