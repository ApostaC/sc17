#ifdef BETA0
#define ATL_INT int
#include <stdio.h>
#include <stdint.h>
#include <pmmintrin.h>

#define I_UNROLL 11
#define J_UNROLL 1
/* Is prefetched data written or just read? */
#define PF_READONLY 0
#define PF_READWRITE 1
#define PF_NO_REUSE 0

/* Default temporality of cache prefetch (1-3) */
#define PF_DEF 1
#define CACHE_LINE_SIZE 64
#define MMCAST( a ) (a)
#define MMCASTStore( a ) (a)
#define MMCASTStoreintrin( a ) (a)
#define TYPE float
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128 c0_0, c0_1, c0_2, c0_3, c0_4, c0_5, c0_6, c0_7, c0_8, c0_9, c0_10;
   /* Temporary vector registers for use in inner loop */
   __m128 temp; 
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchABlock =  (void*)(A + 44*KB); 
   
   /* Unroll A */
   __m128 A0, a0, A1, a1, A2, a2, A3, a3, A4, a4, A5, a5, A6, a6, A7, a7, A8, a8, A9, a9, A10, a10;
   /* Unroll B */
   __m128 B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   const ATL_INT pfBlockDistance = (11 * 1 * KB * 4) / 44;
   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-44; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-44; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_ps( MMCAST(A0_off) );
         A1 = _mm_load_ps( MMCAST(A0_off + 44) );
         A2 = _mm_load_ps( MMCAST(A0_off + 88) );
         A3 = _mm_load_ps( MMCAST(A0_off + 132) );
         A4 = _mm_load_ps( MMCAST(A0_off + 176) );
         A5 = _mm_load_ps( MMCAST(A0_off + 220) );
         A6 = _mm_load_ps( MMCAST(A0_off + 264) );
         A7 = _mm_load_ps( MMCAST(A0_off + 308) );
         A8 = _mm_load_ps( MMCAST(A0_off + 352) );
         A9 = _mm_load_ps( MMCAST(A0_off + 396) );
         A10 = _mm_load_ps( MMCAST(A0_off + 440) );
         B0 = _mm_load_ps( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_ps( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_ps( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_ps( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_ps( A3, c0_3 );
         c0_4 = B0;
         c0_4 = _mm_mul_ps( A4, c0_4 );
         c0_5 = B0;
         c0_5 = _mm_mul_ps( A5, c0_5 );
         c0_6 = B0;
         c0_6 = _mm_mul_ps( A6, c0_6 );
         c0_7 = B0;
         c0_7 = _mm_mul_ps( A7, c0_7 );
         c0_8 = B0;
         c0_8 = _mm_mul_ps( A8, c0_8 );
         c0_9 = B0;
         c0_9 = _mm_mul_ps( A9, c0_9 );
         c0_10 = B0;
         c0_10 = _mm_mul_ps( A10, c0_10 );
         
         /* Prefetch one element from the next block of A */
         __builtin_prefetch( prefetchABlock + 0*pfBlockDistance,PF_READONLY, PF_DEF );
         /* K_Unrolling: 4 */
         A0 = _mm_load_ps( MMCAST(A0_off + 4) );
         A1 = _mm_load_ps( MMCAST(A0_off + 48) );
         A2 = _mm_load_ps( MMCAST(A0_off + 92) );
         A3 = _mm_load_ps( MMCAST(A0_off + 136) );
         A4 = _mm_load_ps( MMCAST(A0_off + 180) );
         A5 = _mm_load_ps( MMCAST(A0_off + 224) );
         A6 = _mm_load_ps( MMCAST(A0_off + 268) );
         A7 = _mm_load_ps( MMCAST(A0_off + 312) );
         A8 = _mm_load_ps( MMCAST(A0_off + 356) );
         A9 = _mm_load_ps( MMCAST(A0_off + 400) );
         A10 = _mm_load_ps( MMCAST(A0_off + 444) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 4) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 8 */
         A0 = _mm_load_ps( MMCAST(A0_off + 8) );
         A1 = _mm_load_ps( MMCAST(A0_off + 52) );
         A2 = _mm_load_ps( MMCAST(A0_off + 96) );
         A3 = _mm_load_ps( MMCAST(A0_off + 140) );
         A4 = _mm_load_ps( MMCAST(A0_off + 184) );
         A5 = _mm_load_ps( MMCAST(A0_off + 228) );
         A6 = _mm_load_ps( MMCAST(A0_off + 272) );
         A7 = _mm_load_ps( MMCAST(A0_off + 316) );
         A8 = _mm_load_ps( MMCAST(A0_off + 360) );
         A9 = _mm_load_ps( MMCAST(A0_off + 404) );
         A10 = _mm_load_ps( MMCAST(A0_off + 448) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 8) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 12 */
         A0 = _mm_load_ps( MMCAST(A0_off + 12) );
         A1 = _mm_load_ps( MMCAST(A0_off + 56) );
         A2 = _mm_load_ps( MMCAST(A0_off + 100) );
         A3 = _mm_load_ps( MMCAST(A0_off + 144) );
         A4 = _mm_load_ps( MMCAST(A0_off + 188) );
         A5 = _mm_load_ps( MMCAST(A0_off + 232) );
         A6 = _mm_load_ps( MMCAST(A0_off + 276) );
         A7 = _mm_load_ps( MMCAST(A0_off + 320) );
         A8 = _mm_load_ps( MMCAST(A0_off + 364) );
         A9 = _mm_load_ps( MMCAST(A0_off + 408) );
         A10 = _mm_load_ps( MMCAST(A0_off + 452) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 12) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 16 */
         A0 = _mm_load_ps( MMCAST(A0_off + 16) );
         A1 = _mm_load_ps( MMCAST(A0_off + 60) );
         A2 = _mm_load_ps( MMCAST(A0_off + 104) );
         A3 = _mm_load_ps( MMCAST(A0_off + 148) );
         A4 = _mm_load_ps( MMCAST(A0_off + 192) );
         A5 = _mm_load_ps( MMCAST(A0_off + 236) );
         A6 = _mm_load_ps( MMCAST(A0_off + 280) );
         A7 = _mm_load_ps( MMCAST(A0_off + 324) );
         A8 = _mm_load_ps( MMCAST(A0_off + 368) );
         A9 = _mm_load_ps( MMCAST(A0_off + 412) );
         A10 = _mm_load_ps( MMCAST(A0_off + 456) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 16) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 20 */
         A0 = _mm_load_ps( MMCAST(A0_off + 20) );
         A1 = _mm_load_ps( MMCAST(A0_off + 64) );
         A2 = _mm_load_ps( MMCAST(A0_off + 108) );
         A3 = _mm_load_ps( MMCAST(A0_off + 152) );
         A4 = _mm_load_ps( MMCAST(A0_off + 196) );
         A5 = _mm_load_ps( MMCAST(A0_off + 240) );
         A6 = _mm_load_ps( MMCAST(A0_off + 284) );
         A7 = _mm_load_ps( MMCAST(A0_off + 328) );
         A8 = _mm_load_ps( MMCAST(A0_off + 372) );
         A9 = _mm_load_ps( MMCAST(A0_off + 416) );
         A10 = _mm_load_ps( MMCAST(A0_off + 460) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 20) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 24 */
         A0 = _mm_load_ps( MMCAST(A0_off + 24) );
         A1 = _mm_load_ps( MMCAST(A0_off + 68) );
         A2 = _mm_load_ps( MMCAST(A0_off + 112) );
         A3 = _mm_load_ps( MMCAST(A0_off + 156) );
         A4 = _mm_load_ps( MMCAST(A0_off + 200) );
         A5 = _mm_load_ps( MMCAST(A0_off + 244) );
         A6 = _mm_load_ps( MMCAST(A0_off + 288) );
         A7 = _mm_load_ps( MMCAST(A0_off + 332) );
         A8 = _mm_load_ps( MMCAST(A0_off + 376) );
         A9 = _mm_load_ps( MMCAST(A0_off + 420) );
         A10 = _mm_load_ps( MMCAST(A0_off + 464) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 24) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 28 */
         A0 = _mm_load_ps( MMCAST(A0_off + 28) );
         A1 = _mm_load_ps( MMCAST(A0_off + 72) );
         A2 = _mm_load_ps( MMCAST(A0_off + 116) );
         A3 = _mm_load_ps( MMCAST(A0_off + 160) );
         A4 = _mm_load_ps( MMCAST(A0_off + 204) );
         A5 = _mm_load_ps( MMCAST(A0_off + 248) );
         A6 = _mm_load_ps( MMCAST(A0_off + 292) );
         A7 = _mm_load_ps( MMCAST(A0_off + 336) );
         A8 = _mm_load_ps( MMCAST(A0_off + 380) );
         A9 = _mm_load_ps( MMCAST(A0_off + 424) );
         A10 = _mm_load_ps( MMCAST(A0_off + 468) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 28) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 32 */
         A0 = _mm_load_ps( MMCAST(A0_off + 32) );
         A1 = _mm_load_ps( MMCAST(A0_off + 76) );
         A2 = _mm_load_ps( MMCAST(A0_off + 120) );
         A3 = _mm_load_ps( MMCAST(A0_off + 164) );
         A4 = _mm_load_ps( MMCAST(A0_off + 208) );
         A5 = _mm_load_ps( MMCAST(A0_off + 252) );
         A6 = _mm_load_ps( MMCAST(A0_off + 296) );
         A7 = _mm_load_ps( MMCAST(A0_off + 340) );
         A8 = _mm_load_ps( MMCAST(A0_off + 384) );
         A9 = _mm_load_ps( MMCAST(A0_off + 428) );
         A10 = _mm_load_ps( MMCAST(A0_off + 472) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 32) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 36 */
         A0 = _mm_load_ps( MMCAST(A0_off + 36) );
         A1 = _mm_load_ps( MMCAST(A0_off + 80) );
         A2 = _mm_load_ps( MMCAST(A0_off + 124) );
         A3 = _mm_load_ps( MMCAST(A0_off + 168) );
         A4 = _mm_load_ps( MMCAST(A0_off + 212) );
         A5 = _mm_load_ps( MMCAST(A0_off + 256) );
         A6 = _mm_load_ps( MMCAST(A0_off + 300) );
         A7 = _mm_load_ps( MMCAST(A0_off + 344) );
         A8 = _mm_load_ps( MMCAST(A0_off + 388) );
         A9 = _mm_load_ps( MMCAST(A0_off + 432) );
         A10 = _mm_load_ps( MMCAST(A0_off + 476) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 36) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 40 */
         A0 = _mm_load_ps( MMCAST(A0_off + 40) );
         A1 = _mm_load_ps( MMCAST(A0_off + 84) );
         A2 = _mm_load_ps( MMCAST(A0_off + 128) );
         A3 = _mm_load_ps( MMCAST(A0_off + 172) );
         A4 = _mm_load_ps( MMCAST(A0_off + 216) );
         A5 = _mm_load_ps( MMCAST(A0_off + 260) );
         A6 = _mm_load_ps( MMCAST(A0_off + 304) );
         A7 = _mm_load_ps( MMCAST(A0_off + 348) );
         A8 = _mm_load_ps( MMCAST(A0_off + 392) );
         A9 = _mm_load_ps( MMCAST(A0_off + 436) );
         A10 = _mm_load_ps( MMCAST(A0_off + 480) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 40) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         prefetchABlock += 1*pfBlockDistance;
         /* Single Scalar Compression */
         c0_0 = _mm_hadd_ps( c0_0, c0_1 );
         c0_2 = _mm_hadd_ps( c0_2, c0_3 );
         c0_0 = _mm_hadd_ps( c0_0, c0_2 );
         
         c0_4 = _mm_hadd_ps( c0_4, c0_5 );
         c0_6 = _mm_hadd_ps( c0_6, c0_7 );
         c0_4 = _mm_hadd_ps( c0_4, c0_6 );
         
         /* additional remaining step */
         c0_8 = _mm_hadd_ps( c0_8, c0_8 );
         c0_8 = _mm_hadd_ps( c0_8, c0_8 );
         /* additional remaining step */
         c0_9 = _mm_hadd_ps( c0_9, c0_9 );
         c0_9 = _mm_hadd_ps( c0_9, c0_9 );
         /* additional remaining step */
         c0_10 = _mm_hadd_ps( c0_10, c0_10 );
         c0_10 = _mm_hadd_ps( c0_10, c0_10 );
         /* Applying Beta */
         /* No beta will be appied */
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_storeu_ps( MMCAST( cPtrI0 ),  MMCASTStoreintrin( c0_0 ) );
         _mm_storeu_ps( MMCAST( cPtrI0+4 ),  MMCASTStoreintrin( c0_4 ) );
         _mm_store_ss( cPtrI0+8,  c0_8 );
         _mm_store_ss( cPtrI0+9,  c0_9 );
         _mm_store_ss( cPtrI0+10,  c0_10 );
         cPtrI0 += I_UNROLL;
         

      } /* End i/MB loop */

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
#elif defined(BETAX)
#define ATL_INT int
#include <stdio.h>
#include <stdint.h>
#include <pmmintrin.h>

#define I_UNROLL 11
#define J_UNROLL 1
/* Is prefetched data written or just read? */
#define PF_READONLY 0
#define PF_READWRITE 1
#define PF_NO_REUSE 0

/* Default temporality of cache prefetch (1-3) */
#define PF_DEF 1
#define CACHE_LINE_SIZE 64
#define MMCAST( a ) (a)
#define MMCASTStore( a ) (a)
#define MMCASTStoreintrin( a ) (a)
#define TYPE float
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128 c0_0, c0_1, c0_2, c0_3, c0_4, c0_5, c0_6, c0_7, c0_8, c0_9, c0_10;
   /* Vector register to hold C*beta */
   __m128 bc0_0, bc0_4, bc0_8, bc0_9, bc0_10;
   /* Temporary vector registers for use in inner loop */
   __m128 temp; 
   const __m128 betaV = _mm_set1_ps( beta ); 
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchABlock =  (void*)(A + 44*KB); 
   
   /* Unroll A */
   __m128 A0, a0, A1, a1, A2, a2, A3, a3, A4, a4, A5, a5, A6, a6, A7, a7, A8, a8, A9, a9, A10, a10;
   /* Unroll B */
   __m128 B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   const ATL_INT pfBlockDistance = (11 * 1 * KB * 4) / 44;
   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-44; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-44; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_ps( MMCAST(A0_off) );
         A1 = _mm_load_ps( MMCAST(A0_off + 44) );
         A2 = _mm_load_ps( MMCAST(A0_off + 88) );
         A3 = _mm_load_ps( MMCAST(A0_off + 132) );
         A4 = _mm_load_ps( MMCAST(A0_off + 176) );
         A5 = _mm_load_ps( MMCAST(A0_off + 220) );
         A6 = _mm_load_ps( MMCAST(A0_off + 264) );
         A7 = _mm_load_ps( MMCAST(A0_off + 308) );
         A8 = _mm_load_ps( MMCAST(A0_off + 352) );
         A9 = _mm_load_ps( MMCAST(A0_off + 396) );
         A10 = _mm_load_ps( MMCAST(A0_off + 440) );
         B0 = _mm_load_ps( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_ps( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_ps( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_ps( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_ps( A3, c0_3 );
         c0_4 = B0;
         c0_4 = _mm_mul_ps( A4, c0_4 );
         c0_5 = B0;
         c0_5 = _mm_mul_ps( A5, c0_5 );
         c0_6 = B0;
         c0_6 = _mm_mul_ps( A6, c0_6 );
         c0_7 = B0;
         c0_7 = _mm_mul_ps( A7, c0_7 );
         c0_8 = B0;
         c0_8 = _mm_mul_ps( A8, c0_8 );
         c0_9 = B0;
         c0_9 = _mm_mul_ps( A9, c0_9 );
         c0_10 = B0;
         c0_10 = _mm_mul_ps( A10, c0_10 );
         
         /* Prefetch one element from the next block of A */
         __builtin_prefetch( prefetchABlock + 0*pfBlockDistance,PF_READONLY, PF_DEF );
         /* K_Unrolling: 4 */
         A0 = _mm_load_ps( MMCAST(A0_off + 4) );
         A1 = _mm_load_ps( MMCAST(A0_off + 48) );
         A2 = _mm_load_ps( MMCAST(A0_off + 92) );
         A3 = _mm_load_ps( MMCAST(A0_off + 136) );
         A4 = _mm_load_ps( MMCAST(A0_off + 180) );
         A5 = _mm_load_ps( MMCAST(A0_off + 224) );
         A6 = _mm_load_ps( MMCAST(A0_off + 268) );
         A7 = _mm_load_ps( MMCAST(A0_off + 312) );
         A8 = _mm_load_ps( MMCAST(A0_off + 356) );
         A9 = _mm_load_ps( MMCAST(A0_off + 400) );
         A10 = _mm_load_ps( MMCAST(A0_off + 444) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 4) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 8 */
         A0 = _mm_load_ps( MMCAST(A0_off + 8) );
         A1 = _mm_load_ps( MMCAST(A0_off + 52) );
         A2 = _mm_load_ps( MMCAST(A0_off + 96) );
         A3 = _mm_load_ps( MMCAST(A0_off + 140) );
         A4 = _mm_load_ps( MMCAST(A0_off + 184) );
         A5 = _mm_load_ps( MMCAST(A0_off + 228) );
         A6 = _mm_load_ps( MMCAST(A0_off + 272) );
         A7 = _mm_load_ps( MMCAST(A0_off + 316) );
         A8 = _mm_load_ps( MMCAST(A0_off + 360) );
         A9 = _mm_load_ps( MMCAST(A0_off + 404) );
         A10 = _mm_load_ps( MMCAST(A0_off + 448) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 8) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 12 */
         A0 = _mm_load_ps( MMCAST(A0_off + 12) );
         A1 = _mm_load_ps( MMCAST(A0_off + 56) );
         A2 = _mm_load_ps( MMCAST(A0_off + 100) );
         A3 = _mm_load_ps( MMCAST(A0_off + 144) );
         A4 = _mm_load_ps( MMCAST(A0_off + 188) );
         A5 = _mm_load_ps( MMCAST(A0_off + 232) );
         A6 = _mm_load_ps( MMCAST(A0_off + 276) );
         A7 = _mm_load_ps( MMCAST(A0_off + 320) );
         A8 = _mm_load_ps( MMCAST(A0_off + 364) );
         A9 = _mm_load_ps( MMCAST(A0_off + 408) );
         A10 = _mm_load_ps( MMCAST(A0_off + 452) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 12) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 16 */
         A0 = _mm_load_ps( MMCAST(A0_off + 16) );
         A1 = _mm_load_ps( MMCAST(A0_off + 60) );
         A2 = _mm_load_ps( MMCAST(A0_off + 104) );
         A3 = _mm_load_ps( MMCAST(A0_off + 148) );
         A4 = _mm_load_ps( MMCAST(A0_off + 192) );
         A5 = _mm_load_ps( MMCAST(A0_off + 236) );
         A6 = _mm_load_ps( MMCAST(A0_off + 280) );
         A7 = _mm_load_ps( MMCAST(A0_off + 324) );
         A8 = _mm_load_ps( MMCAST(A0_off + 368) );
         A9 = _mm_load_ps( MMCAST(A0_off + 412) );
         A10 = _mm_load_ps( MMCAST(A0_off + 456) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 16) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 20 */
         A0 = _mm_load_ps( MMCAST(A0_off + 20) );
         A1 = _mm_load_ps( MMCAST(A0_off + 64) );
         A2 = _mm_load_ps( MMCAST(A0_off + 108) );
         A3 = _mm_load_ps( MMCAST(A0_off + 152) );
         A4 = _mm_load_ps( MMCAST(A0_off + 196) );
         A5 = _mm_load_ps( MMCAST(A0_off + 240) );
         A6 = _mm_load_ps( MMCAST(A0_off + 284) );
         A7 = _mm_load_ps( MMCAST(A0_off + 328) );
         A8 = _mm_load_ps( MMCAST(A0_off + 372) );
         A9 = _mm_load_ps( MMCAST(A0_off + 416) );
         A10 = _mm_load_ps( MMCAST(A0_off + 460) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 20) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 24 */
         A0 = _mm_load_ps( MMCAST(A0_off + 24) );
         A1 = _mm_load_ps( MMCAST(A0_off + 68) );
         A2 = _mm_load_ps( MMCAST(A0_off + 112) );
         A3 = _mm_load_ps( MMCAST(A0_off + 156) );
         A4 = _mm_load_ps( MMCAST(A0_off + 200) );
         A5 = _mm_load_ps( MMCAST(A0_off + 244) );
         A6 = _mm_load_ps( MMCAST(A0_off + 288) );
         A7 = _mm_load_ps( MMCAST(A0_off + 332) );
         A8 = _mm_load_ps( MMCAST(A0_off + 376) );
         A9 = _mm_load_ps( MMCAST(A0_off + 420) );
         A10 = _mm_load_ps( MMCAST(A0_off + 464) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 24) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 28 */
         A0 = _mm_load_ps( MMCAST(A0_off + 28) );
         A1 = _mm_load_ps( MMCAST(A0_off + 72) );
         A2 = _mm_load_ps( MMCAST(A0_off + 116) );
         A3 = _mm_load_ps( MMCAST(A0_off + 160) );
         A4 = _mm_load_ps( MMCAST(A0_off + 204) );
         A5 = _mm_load_ps( MMCAST(A0_off + 248) );
         A6 = _mm_load_ps( MMCAST(A0_off + 292) );
         A7 = _mm_load_ps( MMCAST(A0_off + 336) );
         A8 = _mm_load_ps( MMCAST(A0_off + 380) );
         A9 = _mm_load_ps( MMCAST(A0_off + 424) );
         A10 = _mm_load_ps( MMCAST(A0_off + 468) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 28) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 32 */
         A0 = _mm_load_ps( MMCAST(A0_off + 32) );
         A1 = _mm_load_ps( MMCAST(A0_off + 76) );
         A2 = _mm_load_ps( MMCAST(A0_off + 120) );
         A3 = _mm_load_ps( MMCAST(A0_off + 164) );
         A4 = _mm_load_ps( MMCAST(A0_off + 208) );
         A5 = _mm_load_ps( MMCAST(A0_off + 252) );
         A6 = _mm_load_ps( MMCAST(A0_off + 296) );
         A7 = _mm_load_ps( MMCAST(A0_off + 340) );
         A8 = _mm_load_ps( MMCAST(A0_off + 384) );
         A9 = _mm_load_ps( MMCAST(A0_off + 428) );
         A10 = _mm_load_ps( MMCAST(A0_off + 472) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 32) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 36 */
         A0 = _mm_load_ps( MMCAST(A0_off + 36) );
         A1 = _mm_load_ps( MMCAST(A0_off + 80) );
         A2 = _mm_load_ps( MMCAST(A0_off + 124) );
         A3 = _mm_load_ps( MMCAST(A0_off + 168) );
         A4 = _mm_load_ps( MMCAST(A0_off + 212) );
         A5 = _mm_load_ps( MMCAST(A0_off + 256) );
         A6 = _mm_load_ps( MMCAST(A0_off + 300) );
         A7 = _mm_load_ps( MMCAST(A0_off + 344) );
         A8 = _mm_load_ps( MMCAST(A0_off + 388) );
         A9 = _mm_load_ps( MMCAST(A0_off + 432) );
         A10 = _mm_load_ps( MMCAST(A0_off + 476) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 36) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 40 */
         A0 = _mm_load_ps( MMCAST(A0_off + 40) );
         A1 = _mm_load_ps( MMCAST(A0_off + 84) );
         A2 = _mm_load_ps( MMCAST(A0_off + 128) );
         A3 = _mm_load_ps( MMCAST(A0_off + 172) );
         A4 = _mm_load_ps( MMCAST(A0_off + 216) );
         A5 = _mm_load_ps( MMCAST(A0_off + 260) );
         A6 = _mm_load_ps( MMCAST(A0_off + 304) );
         A7 = _mm_load_ps( MMCAST(A0_off + 348) );
         A8 = _mm_load_ps( MMCAST(A0_off + 392) );
         A9 = _mm_load_ps( MMCAST(A0_off + 436) );
         A10 = _mm_load_ps( MMCAST(A0_off + 480) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 40) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         prefetchABlock += 1*pfBlockDistance;
         /* Single Scalar Compression */
         c0_0 = _mm_hadd_ps( c0_0, c0_1 );
         c0_2 = _mm_hadd_ps( c0_2, c0_3 );
         c0_0 = _mm_hadd_ps( c0_0, c0_2 );
         
         c0_4 = _mm_hadd_ps( c0_4, c0_5 );
         c0_6 = _mm_hadd_ps( c0_6, c0_7 );
         c0_4 = _mm_hadd_ps( c0_4, c0_6 );
         
         /* additional remaining step */
         c0_8 = _mm_hadd_ps( c0_8, c0_8 );
         c0_8 = _mm_hadd_ps( c0_8, c0_8 );
         /* additional remaining step */
         c0_9 = _mm_hadd_ps( c0_9, c0_9 );
         c0_9 = _mm_hadd_ps( c0_9, c0_9 );
         /* additional remaining step */
         c0_10 = _mm_hadd_ps( c0_10, c0_10 );
         c0_10 = _mm_hadd_ps( c0_10, c0_10 );
         /* Applying Beta */
            /* Apply Beta Factor */
            /* Load C from memory */
            bc0_0 = _mm_loadu_ps( cPtrI0+0 );
            bc0_0 = _mm_mul_ps( betaV, bc0_0 );
            bc0_4 = _mm_loadu_ps( cPtrI0+4 );
            bc0_4 = _mm_mul_ps( betaV, bc0_4 );
            /* 3 remaining */
            bc0_8 = _mm_load_ss( cPtrI0+8 );
            bc0_8 = _mm_mul_ss( betaV, bc0_8 );
            /* 2 remaining */
            bc0_9 = _mm_load_ss( cPtrI0+9 );
            bc0_9 = _mm_mul_ss( betaV, bc0_9 );
            /* 1 remaining */
            bc0_10 = _mm_load_ss( cPtrI0+10 );
            bc0_10 = _mm_mul_ss( betaV, bc0_10 );
            /* C = (beta*C) + (matrix multiply) */
            c0_0 = _mm_add_ps( bc0_0, c0_0 );
            c0_4 = _mm_add_ps( bc0_4, c0_4 );
            c0_8 = _mm_add_ss( bc0_8, c0_8 );
            c0_9 = _mm_add_ss( bc0_9, c0_9 );
            c0_10 = _mm_add_ss( bc0_10, c0_10 );
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_storeu_ps( MMCAST( cPtrI0 ),  MMCASTStoreintrin( c0_0 ) );
         _mm_storeu_ps( MMCAST( cPtrI0+4 ),  MMCASTStoreintrin( c0_4 ) );
         _mm_store_ss( cPtrI0+8,  c0_8 );
         _mm_store_ss( cPtrI0+9,  c0_9 );
         _mm_store_ss( cPtrI0+10,  c0_10 );
         cPtrI0 += I_UNROLL;
         

      } /* End i/MB loop */

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
#else
#define ATL_INT int
#include <stdio.h>
#include <stdint.h>
#include <pmmintrin.h>

#define I_UNROLL 11
#define J_UNROLL 1
/* Is prefetched data written or just read? */
#define PF_READONLY 0
#define PF_READWRITE 1
#define PF_NO_REUSE 0

/* Default temporality of cache prefetch (1-3) */
#define PF_DEF 1
#define CACHE_LINE_SIZE 64
#define MMCAST( a ) (a)
#define MMCASTStore( a ) (a)
#define MMCASTStoreintrin( a ) (a)
#define TYPE float
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128 c0_0, c0_1, c0_2, c0_3, c0_4, c0_5, c0_6, c0_7, c0_8, c0_9, c0_10;
   /* Vector register to hold C*beta */
   __m128 bc0_0, bc0_4, bc0_8, bc0_9, bc0_10;
   /* Temporary vector registers for use in inner loop */
   __m128 temp; 
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchABlock =  (void*)(A + 44*KB); 
   
   /* Unroll A */
   __m128 A0, a0, A1, a1, A2, a2, A3, a3, A4, a4, A5, a5, A6, a6, A7, a7, A8, a8, A9, a9, A10, a10;
   /* Unroll B */
   __m128 B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   const ATL_INT pfBlockDistance = (11 * 1 * KB * 4) / 44;
   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-44; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-44; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_ps( MMCAST(A0_off) );
         A1 = _mm_load_ps( MMCAST(A0_off + 44) );
         A2 = _mm_load_ps( MMCAST(A0_off + 88) );
         A3 = _mm_load_ps( MMCAST(A0_off + 132) );
         A4 = _mm_load_ps( MMCAST(A0_off + 176) );
         A5 = _mm_load_ps( MMCAST(A0_off + 220) );
         A6 = _mm_load_ps( MMCAST(A0_off + 264) );
         A7 = _mm_load_ps( MMCAST(A0_off + 308) );
         A8 = _mm_load_ps( MMCAST(A0_off + 352) );
         A9 = _mm_load_ps( MMCAST(A0_off + 396) );
         A10 = _mm_load_ps( MMCAST(A0_off + 440) );
         B0 = _mm_load_ps( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_ps( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_ps( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_ps( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_ps( A3, c0_3 );
         c0_4 = B0;
         c0_4 = _mm_mul_ps( A4, c0_4 );
         c0_5 = B0;
         c0_5 = _mm_mul_ps( A5, c0_5 );
         c0_6 = B0;
         c0_6 = _mm_mul_ps( A6, c0_6 );
         c0_7 = B0;
         c0_7 = _mm_mul_ps( A7, c0_7 );
         c0_8 = B0;
         c0_8 = _mm_mul_ps( A8, c0_8 );
         c0_9 = B0;
         c0_9 = _mm_mul_ps( A9, c0_9 );
         c0_10 = B0;
         c0_10 = _mm_mul_ps( A10, c0_10 );
         
         /* Prefetch one element from the next block of A */
         __builtin_prefetch( prefetchABlock + 0*pfBlockDistance,PF_READONLY, PF_DEF );
         /* K_Unrolling: 4 */
         A0 = _mm_load_ps( MMCAST(A0_off + 4) );
         A1 = _mm_load_ps( MMCAST(A0_off + 48) );
         A2 = _mm_load_ps( MMCAST(A0_off + 92) );
         A3 = _mm_load_ps( MMCAST(A0_off + 136) );
         A4 = _mm_load_ps( MMCAST(A0_off + 180) );
         A5 = _mm_load_ps( MMCAST(A0_off + 224) );
         A6 = _mm_load_ps( MMCAST(A0_off + 268) );
         A7 = _mm_load_ps( MMCAST(A0_off + 312) );
         A8 = _mm_load_ps( MMCAST(A0_off + 356) );
         A9 = _mm_load_ps( MMCAST(A0_off + 400) );
         A10 = _mm_load_ps( MMCAST(A0_off + 444) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 4) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 8 */
         A0 = _mm_load_ps( MMCAST(A0_off + 8) );
         A1 = _mm_load_ps( MMCAST(A0_off + 52) );
         A2 = _mm_load_ps( MMCAST(A0_off + 96) );
         A3 = _mm_load_ps( MMCAST(A0_off + 140) );
         A4 = _mm_load_ps( MMCAST(A0_off + 184) );
         A5 = _mm_load_ps( MMCAST(A0_off + 228) );
         A6 = _mm_load_ps( MMCAST(A0_off + 272) );
         A7 = _mm_load_ps( MMCAST(A0_off + 316) );
         A8 = _mm_load_ps( MMCAST(A0_off + 360) );
         A9 = _mm_load_ps( MMCAST(A0_off + 404) );
         A10 = _mm_load_ps( MMCAST(A0_off + 448) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 8) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 12 */
         A0 = _mm_load_ps( MMCAST(A0_off + 12) );
         A1 = _mm_load_ps( MMCAST(A0_off + 56) );
         A2 = _mm_load_ps( MMCAST(A0_off + 100) );
         A3 = _mm_load_ps( MMCAST(A0_off + 144) );
         A4 = _mm_load_ps( MMCAST(A0_off + 188) );
         A5 = _mm_load_ps( MMCAST(A0_off + 232) );
         A6 = _mm_load_ps( MMCAST(A0_off + 276) );
         A7 = _mm_load_ps( MMCAST(A0_off + 320) );
         A8 = _mm_load_ps( MMCAST(A0_off + 364) );
         A9 = _mm_load_ps( MMCAST(A0_off + 408) );
         A10 = _mm_load_ps( MMCAST(A0_off + 452) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 12) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 16 */
         A0 = _mm_load_ps( MMCAST(A0_off + 16) );
         A1 = _mm_load_ps( MMCAST(A0_off + 60) );
         A2 = _mm_load_ps( MMCAST(A0_off + 104) );
         A3 = _mm_load_ps( MMCAST(A0_off + 148) );
         A4 = _mm_load_ps( MMCAST(A0_off + 192) );
         A5 = _mm_load_ps( MMCAST(A0_off + 236) );
         A6 = _mm_load_ps( MMCAST(A0_off + 280) );
         A7 = _mm_load_ps( MMCAST(A0_off + 324) );
         A8 = _mm_load_ps( MMCAST(A0_off + 368) );
         A9 = _mm_load_ps( MMCAST(A0_off + 412) );
         A10 = _mm_load_ps( MMCAST(A0_off + 456) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 16) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 20 */
         A0 = _mm_load_ps( MMCAST(A0_off + 20) );
         A1 = _mm_load_ps( MMCAST(A0_off + 64) );
         A2 = _mm_load_ps( MMCAST(A0_off + 108) );
         A3 = _mm_load_ps( MMCAST(A0_off + 152) );
         A4 = _mm_load_ps( MMCAST(A0_off + 196) );
         A5 = _mm_load_ps( MMCAST(A0_off + 240) );
         A6 = _mm_load_ps( MMCAST(A0_off + 284) );
         A7 = _mm_load_ps( MMCAST(A0_off + 328) );
         A8 = _mm_load_ps( MMCAST(A0_off + 372) );
         A9 = _mm_load_ps( MMCAST(A0_off + 416) );
         A10 = _mm_load_ps( MMCAST(A0_off + 460) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 20) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 24 */
         A0 = _mm_load_ps( MMCAST(A0_off + 24) );
         A1 = _mm_load_ps( MMCAST(A0_off + 68) );
         A2 = _mm_load_ps( MMCAST(A0_off + 112) );
         A3 = _mm_load_ps( MMCAST(A0_off + 156) );
         A4 = _mm_load_ps( MMCAST(A0_off + 200) );
         A5 = _mm_load_ps( MMCAST(A0_off + 244) );
         A6 = _mm_load_ps( MMCAST(A0_off + 288) );
         A7 = _mm_load_ps( MMCAST(A0_off + 332) );
         A8 = _mm_load_ps( MMCAST(A0_off + 376) );
         A9 = _mm_load_ps( MMCAST(A0_off + 420) );
         A10 = _mm_load_ps( MMCAST(A0_off + 464) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 24) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 28 */
         A0 = _mm_load_ps( MMCAST(A0_off + 28) );
         A1 = _mm_load_ps( MMCAST(A0_off + 72) );
         A2 = _mm_load_ps( MMCAST(A0_off + 116) );
         A3 = _mm_load_ps( MMCAST(A0_off + 160) );
         A4 = _mm_load_ps( MMCAST(A0_off + 204) );
         A5 = _mm_load_ps( MMCAST(A0_off + 248) );
         A6 = _mm_load_ps( MMCAST(A0_off + 292) );
         A7 = _mm_load_ps( MMCAST(A0_off + 336) );
         A8 = _mm_load_ps( MMCAST(A0_off + 380) );
         A9 = _mm_load_ps( MMCAST(A0_off + 424) );
         A10 = _mm_load_ps( MMCAST(A0_off + 468) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 28) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 32 */
         A0 = _mm_load_ps( MMCAST(A0_off + 32) );
         A1 = _mm_load_ps( MMCAST(A0_off + 76) );
         A2 = _mm_load_ps( MMCAST(A0_off + 120) );
         A3 = _mm_load_ps( MMCAST(A0_off + 164) );
         A4 = _mm_load_ps( MMCAST(A0_off + 208) );
         A5 = _mm_load_ps( MMCAST(A0_off + 252) );
         A6 = _mm_load_ps( MMCAST(A0_off + 296) );
         A7 = _mm_load_ps( MMCAST(A0_off + 340) );
         A8 = _mm_load_ps( MMCAST(A0_off + 384) );
         A9 = _mm_load_ps( MMCAST(A0_off + 428) );
         A10 = _mm_load_ps( MMCAST(A0_off + 472) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 32) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 36 */
         A0 = _mm_load_ps( MMCAST(A0_off + 36) );
         A1 = _mm_load_ps( MMCAST(A0_off + 80) );
         A2 = _mm_load_ps( MMCAST(A0_off + 124) );
         A3 = _mm_load_ps( MMCAST(A0_off + 168) );
         A4 = _mm_load_ps( MMCAST(A0_off + 212) );
         A5 = _mm_load_ps( MMCAST(A0_off + 256) );
         A6 = _mm_load_ps( MMCAST(A0_off + 300) );
         A7 = _mm_load_ps( MMCAST(A0_off + 344) );
         A8 = _mm_load_ps( MMCAST(A0_off + 388) );
         A9 = _mm_load_ps( MMCAST(A0_off + 432) );
         A10 = _mm_load_ps( MMCAST(A0_off + 476) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 36) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         /* K_Unrolling: 40 */
         A0 = _mm_load_ps( MMCAST(A0_off + 40) );
         A1 = _mm_load_ps( MMCAST(A0_off + 84) );
         A2 = _mm_load_ps( MMCAST(A0_off + 128) );
         A3 = _mm_load_ps( MMCAST(A0_off + 172) );
         A4 = _mm_load_ps( MMCAST(A0_off + 216) );
         A5 = _mm_load_ps( MMCAST(A0_off + 260) );
         A6 = _mm_load_ps( MMCAST(A0_off + 304) );
         A7 = _mm_load_ps( MMCAST(A0_off + 348) );
         A8 = _mm_load_ps( MMCAST(A0_off + 392) );
         A9 = _mm_load_ps( MMCAST(A0_off + 436) );
         A10 = _mm_load_ps( MMCAST(A0_off + 480) );
         
         B0 = _mm_load_ps( MMCAST(B0_off + 40) );
         A0 = _mm_mul_ps( B0, A0 );
         c0_0 = _mm_add_ps( A0, c0_0 );
         A1 = _mm_mul_ps( B0, A1 );
         c0_1 = _mm_add_ps( A1, c0_1 );
         A2 = _mm_mul_ps( B0, A2 );
         c0_2 = _mm_add_ps( A2, c0_2 );
         A3 = _mm_mul_ps( B0, A3 );
         c0_3 = _mm_add_ps( A3, c0_3 );
         A4 = _mm_mul_ps( B0, A4 );
         c0_4 = _mm_add_ps( A4, c0_4 );
         A5 = _mm_mul_ps( B0, A5 );
         c0_5 = _mm_add_ps( A5, c0_5 );
         A6 = _mm_mul_ps( B0, A6 );
         c0_6 = _mm_add_ps( A6, c0_6 );
         A7 = _mm_mul_ps( B0, A7 );
         c0_7 = _mm_add_ps( A7, c0_7 );
         A8 = _mm_mul_ps( B0, A8 );
         c0_8 = _mm_add_ps( A8, c0_8 );
         A9 = _mm_mul_ps( B0, A9 );
         c0_9 = _mm_add_ps( A9, c0_9 );
         A10 = _mm_mul_ps( B0, A10 );
         c0_10 = _mm_add_ps( A10, c0_10 );
         prefetchABlock += 1*pfBlockDistance;
         /* Single Scalar Compression */
         c0_0 = _mm_hadd_ps( c0_0, c0_1 );
         c0_2 = _mm_hadd_ps( c0_2, c0_3 );
         c0_0 = _mm_hadd_ps( c0_0, c0_2 );
         
         c0_4 = _mm_hadd_ps( c0_4, c0_5 );
         c0_6 = _mm_hadd_ps( c0_6, c0_7 );
         c0_4 = _mm_hadd_ps( c0_4, c0_6 );
         
         /* additional remaining step */
         c0_8 = _mm_hadd_ps( c0_8, c0_8 );
         c0_8 = _mm_hadd_ps( c0_8, c0_8 );
         /* additional remaining step */
         c0_9 = _mm_hadd_ps( c0_9, c0_9 );
         c0_9 = _mm_hadd_ps( c0_9, c0_9 );
         /* additional remaining step */
         c0_10 = _mm_hadd_ps( c0_10, c0_10 );
         c0_10 = _mm_hadd_ps( c0_10, c0_10 );
         /* Applying Beta */
            /* Apply Beta Factor */
            /* Load C from memory */
            bc0_0 = _mm_loadu_ps( cPtrI0+0 );
            bc0_4 = _mm_loadu_ps( cPtrI0+4 );
            /* 3 remaining */
            bc0_8 = _mm_load_ss( cPtrI0+8 );
            /* 2 remaining */
            bc0_9 = _mm_load_ss( cPtrI0+9 );
            /* 1 remaining */
            bc0_10 = _mm_load_ss( cPtrI0+10 );
            /* C = (beta*C) + (matrix multiply) */
            c0_0 = _mm_add_ps( bc0_0, c0_0 );
            c0_4 = _mm_add_ps( bc0_4, c0_4 );
            c0_8 = _mm_add_ss( bc0_8, c0_8 );
            c0_9 = _mm_add_ss( bc0_9, c0_9 );
            c0_10 = _mm_add_ss( bc0_10, c0_10 );
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_storeu_ps( MMCAST( cPtrI0 ),  MMCASTStoreintrin( c0_0 ) );
         _mm_storeu_ps( MMCAST( cPtrI0+4 ),  MMCASTStoreintrin( c0_4 ) );
         _mm_store_ss( cPtrI0+8,  c0_8 );
         _mm_store_ss( cPtrI0+9,  c0_9 );
         _mm_store_ss( cPtrI0+10,  c0_10 );
         cPtrI0 += I_UNROLL;
         

      } /* End i/MB loop */

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
#endif
