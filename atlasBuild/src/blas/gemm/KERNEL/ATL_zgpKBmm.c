#ifndef ATL_UCLEANK
   #define ATL_zgpKBmm ATL_zpKBmm
#endif

void ATL_zJIK0x0x0TN0x0x0_a1_bX(const int M, const int N, const int K, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc);
typedef void (*MMfunc)(const int M, const int N, const int K, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc);

void ATL_zgpKBmm(const int M, const int N, const int K, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc)
{
   ATL_zJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A, lda, B, ldb, -beta, C, ldc);
   ATL_zJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A, lda, B+N*ldb, ldb, beta, C+1, ldc);
   ATL_zJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A+M*lda, lda, B+N*ldb, ldb, -1.0, C, ldc);
   ATL_zJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A+M*lda, lda, B, ldb, 1.0, C+1, ldc);
}
#ifndef ATL_UCLEANK
void ATL_zpKBmm_b0(const int M, const int N, const int K, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc)
{
   ATL_zgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
void ATL_zpKBmm_b1(const int M, const int N, const int K, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc)
{
   ATL_zgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
void ATL_zpKBmm_bX(const int M, const int N, const int K, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc)
{
   ATL_zgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
#endif
