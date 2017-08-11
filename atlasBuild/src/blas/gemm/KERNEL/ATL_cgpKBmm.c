#ifndef ATL_UCLEANK
   #define ATL_cgpKBmm ATL_cpKBmm
#endif

void ATL_cJIK0x0x76TN76x76x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x77TN77x77x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x78TN78x78x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x79TN79x79x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x80TN80x80x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x0x0TN0x0x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
typedef void (*MMfunc)(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);

void ATL_cgpKBmm(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   static MMfunc mmfunc[  5] = {
                         ATL_cJIK0x0x76TN76x76x0_a1_bX,
                         ATL_cJIK0x0x77TN77x77x0_a1_bX,
                         ATL_cJIK0x0x78TN78x78x0_a1_bX,
                         ATL_cJIK0x0x79TN79x79x0_a1_bX,
                         ATL_cJIK0x0x80TN80x80x0_a1_bX,
                        };
   MMfunc mm;

   if (K <= 75)
   {
      ATL_cJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A, lda, B, ldb, -beta, C, ldc);
      ATL_cJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A, lda, B+N*ldb, ldb, beta, C+1, ldc);
      ATL_cJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A+M*lda, lda, B+N*ldb, ldb, -1.0, C, ldc);
      ATL_cJIK0x0x0TN0x0x0_a1_bX(M, N, K, alpha, A+M*lda, lda, B, ldb, 1.0, C+1, ldc);
   }
   else
   {
      mm = mmfunc[K-76];
      mm(M, N, K, alpha, A, lda, B, ldb, -beta, C, ldc);
      mm(M, N, K, alpha, A, lda, B+N*ldb, ldb, beta, C+1, ldc);
      mm(M, N, K, alpha, A+M*lda, lda, B+N*ldb, ldb, -1.0, C, ldc);
      mm(M, N, K, alpha, A+M*lda, lda, B, ldb, 1.0, C+1, ldc);
   }
}
#ifndef ATL_UCLEANK
void ATL_cpKBmm_b0(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   ATL_cgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
void ATL_cpKBmm_b1(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   ATL_cgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
void ATL_cpKBmm_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   ATL_cgpKBmm(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
#endif
