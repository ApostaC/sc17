#define DREAL
#include "atlas_misc.h"
void ATL_dupMBmm0_4_0_b0
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);
void ATL_dgpMBmm_b0
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc);

void ATL_dpMBmm_b0
   (const int M, const int N, const int K, const double alpha,
    const double *A, const int lda, const double *B, const int ldb,
    const double beta, double *C, const int ldc)
{

   if (M == (((((M) >> 2)) << 2)))
   {
      ATL_dupMBmm0_4_0_b0(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
   }
   else ATL_dgpMBmm_b0(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
