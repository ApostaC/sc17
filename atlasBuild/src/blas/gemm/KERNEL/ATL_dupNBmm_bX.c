#define DREAL
#include "atlas_misc.h"
void ATL_dupNBmm0_5_0_bX
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_dupNBmm0_3_0_bX
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_dupNBmm0_2_0_bX
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_dupNBmm0_1_0_bX
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_dgpNBmm_bX
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);

typedef void (*MMfunc)(const int, const int, const int, const TYPE,
                       const TYPE *, const int, const TYPE *, const int,
                       const TYPE, TYPE *, const int);

void ATL_dpNBmm_bX
   (const int M, const int N, const int K, const TYPE alpha,
    const TYPE *A, const int lda, const TYPE *B, const int ldb,
    const TYPE beta, TYPE *C, const int ldc)
{

   static MMfunc mmfunc[56] = 
   {
      NULL,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_5_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_5_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_5_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_5_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_5_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_5_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_5_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_5_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_5_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_5_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_2_0_bX,
      ATL_dupNBmm0_1_0_bX,
      ATL_dupNBmm0_3_0_bX,
      ATL_dupNBmm0_5_0_bX
   };

   mmfunc[N](M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
