#ifndef ATL_UCLEANK
   #define ATL_sgpKBmm ATL_spKBmm
#endif

void ATL_sJIK0x0x0TN0x0x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
typedef void (*MMfunc)(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);

void ATL_sgpKBmm(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   ATL_sJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
#ifndef ATL_UCLEANK
void ATL_spKBmm_b0(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   ATL_sgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
void ATL_spKBmm_b1(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   ATL_sgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
void ATL_spKBmm_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   ATL_sgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
#endif
