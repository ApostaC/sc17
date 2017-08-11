#define DCPLX
#include "atlas_misc.h"
void ATL_zupNBmm0_5_0_b0
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zupNBmm0_3_0_b0
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zupNBmm0_2_0_b0
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zupNBmm0_1_0_b0
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zgpNBmm_b0
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zupNBmm0_5_0_b1
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zupNBmm0_3_0_b1
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zupNBmm0_2_0_b1
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zupNBmm0_1_0_b1
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zgpNBmm_b1
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zupNBmm0_5_0_bX
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zupNBmm0_3_0_bX
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zupNBmm0_2_0_bX
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zupNBmm0_1_0_bX
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_zgpNBmm_bX
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);

static void ATL_ZupNBmm0_5_0_b1
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc)
{
   const double *rA = A + lda*M, *rB = B + ldb*N;
   ATL_zupNBmm0_5_0_bX(M, N, K, alpha, A, lda, B, ldb, ATL_rnone, C, ldc); 
   ATL_zupNBmm0_5_0_b1(M, N, K, alpha, A, lda, rB, ldb, beta, C+1, ldc); 
   ATL_zupNBmm0_5_0_bX(M, N, K, alpha, rA, lda, rB, ldb, ATL_rnone, C, ldc); 
   ATL_zupNBmm0_5_0_b1(M, N, K, alpha, rA, lda, B, ldb, ATL_rone, C+1, ldc); 
}
static void ATL_ZupNBmm0_3_0_b1
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc)
{
   const double *rA = A + lda*M, *rB = B + ldb*N;
   ATL_zupNBmm0_3_0_bX(M, N, K, alpha, A, lda, B, ldb, ATL_rnone, C, ldc); 
   ATL_zupNBmm0_3_0_b1(M, N, K, alpha, A, lda, rB, ldb, beta, C+1, ldc); 
   ATL_zupNBmm0_3_0_bX(M, N, K, alpha, rA, lda, rB, ldb, ATL_rnone, C, ldc); 
   ATL_zupNBmm0_3_0_b1(M, N, K, alpha, rA, lda, B, ldb, ATL_rone, C+1, ldc); 
}
static void ATL_ZupNBmm0_2_0_b1
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc)
{
   const double *rA = A + lda*M, *rB = B + ldb*N;
   ATL_zupNBmm0_2_0_bX(M, N, K, alpha, A, lda, B, ldb, ATL_rnone, C, ldc); 
   ATL_zupNBmm0_2_0_b1(M, N, K, alpha, A, lda, rB, ldb, beta, C+1, ldc); 
   ATL_zupNBmm0_2_0_bX(M, N, K, alpha, rA, lda, rB, ldb, ATL_rnone, C, ldc); 
   ATL_zupNBmm0_2_0_b1(M, N, K, alpha, rA, lda, B, ldb, ATL_rone, C+1, ldc); 
}
static void ATL_ZupNBmm0_1_0_b1
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc)
{
   const double *rA = A + lda*M, *rB = B + ldb*N;
   ATL_zupNBmm0_1_0_bX(M, N, K, alpha, A, lda, B, ldb, ATL_rnone, C, ldc); 
   ATL_zupNBmm0_1_0_b1(M, N, K, alpha, A, lda, rB, ldb, beta, C+1, ldc); 
   ATL_zupNBmm0_1_0_bX(M, N, K, alpha, rA, lda, rB, ldb, ATL_rnone, C, ldc); 
   ATL_zupNBmm0_1_0_b1(M, N, K, alpha, rA, lda, B, ldb, ATL_rone, C+1, ldc); 
}

typedef void (*MMfunc)(const int, const int, const int, const TYPE,
                       const TYPE *, const int, const TYPE *, const int,
                       const TYPE, TYPE *, const int);

void ATL_zpNBmm_b1
   (const int M, const int N, const int K, const TYPE alpha,
    const TYPE *A, const int lda, const TYPE *B, const int ldb,
    const TYPE beta, TYPE *C, const int ldc)
{

   static MMfunc mmfunc[56] = 
   {
      NULL,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_5_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_5_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_5_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_5_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_5_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_5_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_5_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_5_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_5_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_5_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_2_0_b1,
      ATL_ZupNBmm0_1_0_b1,
      ATL_ZupNBmm0_3_0_b1,
      ATL_ZupNBmm0_5_0_b1
   };

   mmfunc[N](M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
