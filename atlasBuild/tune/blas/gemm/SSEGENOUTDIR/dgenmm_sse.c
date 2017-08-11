#ifdef BETA0
#define ATL_INT int
#include <stdio.h>
#include <stdint.h>
#include <pmmintrin.h>

#define I_UNROLL 13
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
#define TYPE double
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128d c0_0, c0_1, c0_2, c0_3, c0_4, c0_5, c0_6, c0_7, c0_8, c0_9, c0_10, c0_11, c0_12;
   /* Temporary vector registers for use in inner loop */
   __m128d temp; 
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchABlock =  (void*)(A + 26*KB); 
   
   /* Unroll A */
   __m128d A0, a0, A1, a1, A2, a2, A3, a3, A4, a4, A5, a5, A6, a6, A7, a7, A8, a8, A9, a9, A10, a10, A11, a11, A12, a12;
   /* Unroll B */
   __m128d B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   const ATL_INT pfBlockDistance = (13 * 1 * KB * 8) / 26;
   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-26; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-26; i != 0; i+= I_UNROLL )
      {
         /* Prefetch one element from the next block of A */
         __builtin_prefetch( prefetchABlock,PF_READONLY,PF_DEF );
         prefetchABlock += pfBlockDistance;
         
         /* K_Unrolling0 */
         A0 = _mm_load_pd( MMCAST(A0_off) );
         A1 = _mm_load_pd( MMCAST(A0_off + 26) );
         A2 = _mm_load_pd( MMCAST(A0_off + 52) );
         A3 = _mm_load_pd( MMCAST(A0_off + 78) );
         A4 = _mm_load_pd( MMCAST(A0_off + 104) );
         A5 = _mm_load_pd( MMCAST(A0_off + 130) );
         A6 = _mm_load_pd( MMCAST(A0_off + 156) );
         A7 = _mm_load_pd( MMCAST(A0_off + 182) );
         A8 = _mm_load_pd( MMCAST(A0_off + 208) );
         A9 = _mm_load_pd( MMCAST(A0_off + 234) );
         A10 = _mm_load_pd( MMCAST(A0_off + 260) );
         A11 = _mm_load_pd( MMCAST(A0_off + 286) );
         A12 = _mm_load_pd( MMCAST(A0_off + 312) );
         B0 = _mm_load_pd( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_pd( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_pd( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_pd( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_pd( A3, c0_3 );
         c0_4 = B0;
         c0_4 = _mm_mul_pd( A4, c0_4 );
         c0_5 = B0;
         c0_5 = _mm_mul_pd( A5, c0_5 );
         c0_6 = B0;
         c0_6 = _mm_mul_pd( A6, c0_6 );
         c0_7 = B0;
         c0_7 = _mm_mul_pd( A7, c0_7 );
         c0_8 = B0;
         c0_8 = _mm_mul_pd( A8, c0_8 );
         c0_9 = B0;
         c0_9 = _mm_mul_pd( A9, c0_9 );
         c0_10 = B0;
         c0_10 = _mm_mul_pd( A10, c0_10 );
         c0_11 = B0;
         c0_11 = _mm_mul_pd( A11, c0_11 );
         c0_12 = B0;
         c0_12 = _mm_mul_pd( A12, c0_12 );
         
         for( k=2; k<26; k+=2 )
         {
            /* k_partialUnrolling: 0 */
            B0 = _mm_load_pd( MMCAST( B0_off + k ) );
            A0 = _mm_load_pd( MMCAST(A0_off + k));
            temp = _mm_mul_pd( B0, A0 );
            c0_0 = _mm_add_pd( temp, c0_0 );
            A1 = _mm_load_pd( MMCAST(A0_off + 26 + k));
            temp = _mm_mul_pd( B0, A1 );
            c0_1 = _mm_add_pd( temp, c0_1 );
            A2 = _mm_load_pd( MMCAST(A0_off + 52 + k));
            temp = _mm_mul_pd( B0, A2 );
            c0_2 = _mm_add_pd( temp, c0_2 );
            A3 = _mm_load_pd( MMCAST(A0_off + 78 + k));
            temp = _mm_mul_pd( B0, A3 );
            c0_3 = _mm_add_pd( temp, c0_3 );
            A4 = _mm_load_pd( MMCAST(A0_off + 104 + k));
            temp = _mm_mul_pd( B0, A4 );
            c0_4 = _mm_add_pd( temp, c0_4 );
            A5 = _mm_load_pd( MMCAST(A0_off + 130 + k));
            temp = _mm_mul_pd( B0, A5 );
            c0_5 = _mm_add_pd( temp, c0_5 );
            A6 = _mm_load_pd( MMCAST(A0_off + 156 + k));
            temp = _mm_mul_pd( B0, A6 );
            c0_6 = _mm_add_pd( temp, c0_6 );
            A7 = _mm_load_pd( MMCAST(A0_off + 182 + k));
            temp = _mm_mul_pd( B0, A7 );
            c0_7 = _mm_add_pd( temp, c0_7 );
            A8 = _mm_load_pd( MMCAST(A0_off + 208 + k));
            temp = _mm_mul_pd( B0, A8 );
            c0_8 = _mm_add_pd( temp, c0_8 );
            A9 = _mm_load_pd( MMCAST(A0_off + 234 + k));
            temp = _mm_mul_pd( B0, A9 );
            c0_9 = _mm_add_pd( temp, c0_9 );
            A10 = _mm_load_pd( MMCAST(A0_off + 260 + k));
            temp = _mm_mul_pd( B0, A10 );
            c0_10 = _mm_add_pd( temp, c0_10 );
            A11 = _mm_load_pd( MMCAST(A0_off + 286 + k));
            temp = _mm_mul_pd( B0, A11 );
            c0_11 = _mm_add_pd( temp, c0_11 );
            A12 = _mm_load_pd( MMCAST(A0_off + 312 + k));
            temp = _mm_mul_pd( B0, A12 );
            c0_12 = _mm_add_pd( temp, c0_12 );
         }
         prefetchABlock += 2*pfBlockDistance;
         /* Combine scalar expansion back to scalar */
         /* handling uneven case */
         /* double */
         c0_0 = _mm_hadd_pd( c0_0, c0_1 );
         /* double */
         c0_2 = _mm_hadd_pd( c0_2, c0_3 );
         /* double */
         c0_4 = _mm_hadd_pd( c0_4, c0_5 );
         /* double */
         c0_6 = _mm_hadd_pd( c0_6, c0_7 );
         /* double */
         c0_8 = _mm_hadd_pd( c0_8, c0_9 );
         /* double */
         c0_10 = _mm_hadd_pd( c0_10, c0_11 );
         c0_12 = _mm_hadd_pd( c0_12, c0_12 );
         /* Applying Beta */
         /* No beta will be appied */
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_storeu_pd( MMCAST( cPtrI0 ),  MMCASTStoreintrin( c0_0 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+2 ),  MMCASTStoreintrin( c0_2 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+4 ),  MMCASTStoreintrin( c0_4 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+6 ),  MMCASTStoreintrin( c0_6 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+8 ),  MMCASTStoreintrin( c0_8 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+10 ),  MMCASTStoreintrin( c0_10 ) );
         _mm_store_sd( cPtrI0+12,  c0_12 );
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

#define I_UNROLL 13
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
#define TYPE double
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128d c0_0, c0_1, c0_2, c0_3, c0_4, c0_5, c0_6, c0_7, c0_8, c0_9, c0_10, c0_11, c0_12;
   /* Vector register to hold C*beta */
   __m128d bc0_0, bc0_2, bc0_4, bc0_6, bc0_8, bc0_10, bc0_12;
   /* Temporary vector registers for use in inner loop */
   __m128d temp; 
   const __m128d betaV = _mm_set1_pd( beta ); 
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchABlock =  (void*)(A + 26*KB); 
   
   /* Unroll A */
   __m128d A0, a0, A1, a1, A2, a2, A3, a3, A4, a4, A5, a5, A6, a6, A7, a7, A8, a8, A9, a9, A10, a10, A11, a11, A12, a12;
   /* Unroll B */
   __m128d B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   const ATL_INT pfBlockDistance = (13 * 1 * KB * 8) / 26;
   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-26; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-26; i != 0; i+= I_UNROLL )
      {
         /* Prefetch one element from the next block of A */
         __builtin_prefetch( prefetchABlock,PF_READONLY,PF_DEF );
         prefetchABlock += pfBlockDistance;
         
         /* K_Unrolling0 */
         A0 = _mm_load_pd( MMCAST(A0_off) );
         A1 = _mm_load_pd( MMCAST(A0_off + 26) );
         A2 = _mm_load_pd( MMCAST(A0_off + 52) );
         A3 = _mm_load_pd( MMCAST(A0_off + 78) );
         A4 = _mm_load_pd( MMCAST(A0_off + 104) );
         A5 = _mm_load_pd( MMCAST(A0_off + 130) );
         A6 = _mm_load_pd( MMCAST(A0_off + 156) );
         A7 = _mm_load_pd( MMCAST(A0_off + 182) );
         A8 = _mm_load_pd( MMCAST(A0_off + 208) );
         A9 = _mm_load_pd( MMCAST(A0_off + 234) );
         A10 = _mm_load_pd( MMCAST(A0_off + 260) );
         A11 = _mm_load_pd( MMCAST(A0_off + 286) );
         A12 = _mm_load_pd( MMCAST(A0_off + 312) );
         B0 = _mm_load_pd( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_pd( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_pd( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_pd( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_pd( A3, c0_3 );
         c0_4 = B0;
         c0_4 = _mm_mul_pd( A4, c0_4 );
         c0_5 = B0;
         c0_5 = _mm_mul_pd( A5, c0_5 );
         c0_6 = B0;
         c0_6 = _mm_mul_pd( A6, c0_6 );
         c0_7 = B0;
         c0_7 = _mm_mul_pd( A7, c0_7 );
         c0_8 = B0;
         c0_8 = _mm_mul_pd( A8, c0_8 );
         c0_9 = B0;
         c0_9 = _mm_mul_pd( A9, c0_9 );
         c0_10 = B0;
         c0_10 = _mm_mul_pd( A10, c0_10 );
         c0_11 = B0;
         c0_11 = _mm_mul_pd( A11, c0_11 );
         c0_12 = B0;
         c0_12 = _mm_mul_pd( A12, c0_12 );
         
         for( k=2; k<26; k+=2 )
         {
            /* k_partialUnrolling: 0 */
            B0 = _mm_load_pd( MMCAST( B0_off + k ) );
            A0 = _mm_load_pd( MMCAST(A0_off + k));
            temp = _mm_mul_pd( B0, A0 );
            c0_0 = _mm_add_pd( temp, c0_0 );
            A1 = _mm_load_pd( MMCAST(A0_off + 26 + k));
            temp = _mm_mul_pd( B0, A1 );
            c0_1 = _mm_add_pd( temp, c0_1 );
            A2 = _mm_load_pd( MMCAST(A0_off + 52 + k));
            temp = _mm_mul_pd( B0, A2 );
            c0_2 = _mm_add_pd( temp, c0_2 );
            A3 = _mm_load_pd( MMCAST(A0_off + 78 + k));
            temp = _mm_mul_pd( B0, A3 );
            c0_3 = _mm_add_pd( temp, c0_3 );
            A4 = _mm_load_pd( MMCAST(A0_off + 104 + k));
            temp = _mm_mul_pd( B0, A4 );
            c0_4 = _mm_add_pd( temp, c0_4 );
            A5 = _mm_load_pd( MMCAST(A0_off + 130 + k));
            temp = _mm_mul_pd( B0, A5 );
            c0_5 = _mm_add_pd( temp, c0_5 );
            A6 = _mm_load_pd( MMCAST(A0_off + 156 + k));
            temp = _mm_mul_pd( B0, A6 );
            c0_6 = _mm_add_pd( temp, c0_6 );
            A7 = _mm_load_pd( MMCAST(A0_off + 182 + k));
            temp = _mm_mul_pd( B0, A7 );
            c0_7 = _mm_add_pd( temp, c0_7 );
            A8 = _mm_load_pd( MMCAST(A0_off + 208 + k));
            temp = _mm_mul_pd( B0, A8 );
            c0_8 = _mm_add_pd( temp, c0_8 );
            A9 = _mm_load_pd( MMCAST(A0_off + 234 + k));
            temp = _mm_mul_pd( B0, A9 );
            c0_9 = _mm_add_pd( temp, c0_9 );
            A10 = _mm_load_pd( MMCAST(A0_off + 260 + k));
            temp = _mm_mul_pd( B0, A10 );
            c0_10 = _mm_add_pd( temp, c0_10 );
            A11 = _mm_load_pd( MMCAST(A0_off + 286 + k));
            temp = _mm_mul_pd( B0, A11 );
            c0_11 = _mm_add_pd( temp, c0_11 );
            A12 = _mm_load_pd( MMCAST(A0_off + 312 + k));
            temp = _mm_mul_pd( B0, A12 );
            c0_12 = _mm_add_pd( temp, c0_12 );
         }
         prefetchABlock += 2*pfBlockDistance;
         /* Combine scalar expansion back to scalar */
         /* handling uneven case */
         /* double */
         c0_0 = _mm_hadd_pd( c0_0, c0_1 );
         /* double */
         c0_2 = _mm_hadd_pd( c0_2, c0_3 );
         /* double */
         c0_4 = _mm_hadd_pd( c0_4, c0_5 );
         /* double */
         c0_6 = _mm_hadd_pd( c0_6, c0_7 );
         /* double */
         c0_8 = _mm_hadd_pd( c0_8, c0_9 );
         /* double */
         c0_10 = _mm_hadd_pd( c0_10, c0_11 );
         c0_12 = _mm_hadd_pd( c0_12, c0_12 );
         /* Applying Beta */
            /* Apply Beta Factor */
            /* Load C from memory */
            bc0_0 = _mm_loadu_pd( cPtrI0+0 );
            bc0_0 = _mm_mul_pd( betaV, bc0_0 );
            bc0_2 = _mm_loadu_pd( cPtrI0+2 );
            bc0_2 = _mm_mul_pd( betaV, bc0_2 );
            bc0_4 = _mm_loadu_pd( cPtrI0+4 );
            bc0_4 = _mm_mul_pd( betaV, bc0_4 );
            bc0_6 = _mm_loadu_pd( cPtrI0+6 );
            bc0_6 = _mm_mul_pd( betaV, bc0_6 );
            bc0_8 = _mm_loadu_pd( cPtrI0+8 );
            bc0_8 = _mm_mul_pd( betaV, bc0_8 );
            bc0_10 = _mm_loadu_pd( cPtrI0+10 );
            bc0_10 = _mm_mul_pd( betaV, bc0_10 );
            /* 1 remaining */
            bc0_12 = _mm_load_sd( cPtrI0+12 );
            bc0_12 = _mm_mul_sd( betaV, bc0_12 );
            /* C = (beta*C) + (matrix multiply) */
            c0_0 = _mm_add_pd( bc0_0, c0_0 );
            c0_2 = _mm_add_pd( bc0_2, c0_2 );
            c0_4 = _mm_add_pd( bc0_4, c0_4 );
            c0_6 = _mm_add_pd( bc0_6, c0_6 );
            c0_8 = _mm_add_pd( bc0_8, c0_8 );
            c0_10 = _mm_add_pd( bc0_10, c0_10 );
            c0_12 = _mm_add_sd( bc0_12, c0_12 );
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_storeu_pd( MMCAST( cPtrI0 ),  MMCASTStoreintrin( c0_0 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+2 ),  MMCASTStoreintrin( c0_2 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+4 ),  MMCASTStoreintrin( c0_4 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+6 ),  MMCASTStoreintrin( c0_6 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+8 ),  MMCASTStoreintrin( c0_8 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+10 ),  MMCASTStoreintrin( c0_10 ) );
         _mm_store_sd( cPtrI0+12,  c0_12 );
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

#define I_UNROLL 13
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
#define TYPE double
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128d c0_0, c0_1, c0_2, c0_3, c0_4, c0_5, c0_6, c0_7, c0_8, c0_9, c0_10, c0_11, c0_12;
   /* Vector register to hold C*beta */
   __m128d bc0_0, bc0_2, bc0_4, bc0_6, bc0_8, bc0_10, bc0_12;
   /* Temporary vector registers for use in inner loop */
   __m128d temp; 
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = ldc;
   
   register TYPE const *B0_off = B;
      
   register void const * prefetchABlock =  (void*)(A + 26*KB); 
   
   /* Unroll A */
   __m128d A0, a0, A1, a1, A2, a2, A3, a3, A4, a4, A5, a5, A6, a6, A7, a7, A8, a8, A9, a9, A10, a10, A11, a11, A12, a12;
   /* Unroll B */
   __m128d B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   const ATL_INT pfBlockDistance = (13 * 1 * KB * 8) / 26;
   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-26; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-26; i != 0; i+= I_UNROLL )
      {
         /* Prefetch one element from the next block of A */
         __builtin_prefetch( prefetchABlock,PF_READONLY,PF_DEF );
         prefetchABlock += pfBlockDistance;
         
         /* K_Unrolling0 */
         A0 = _mm_load_pd( MMCAST(A0_off) );
         A1 = _mm_load_pd( MMCAST(A0_off + 26) );
         A2 = _mm_load_pd( MMCAST(A0_off + 52) );
         A3 = _mm_load_pd( MMCAST(A0_off + 78) );
         A4 = _mm_load_pd( MMCAST(A0_off + 104) );
         A5 = _mm_load_pd( MMCAST(A0_off + 130) );
         A6 = _mm_load_pd( MMCAST(A0_off + 156) );
         A7 = _mm_load_pd( MMCAST(A0_off + 182) );
         A8 = _mm_load_pd( MMCAST(A0_off + 208) );
         A9 = _mm_load_pd( MMCAST(A0_off + 234) );
         A10 = _mm_load_pd( MMCAST(A0_off + 260) );
         A11 = _mm_load_pd( MMCAST(A0_off + 286) );
         A12 = _mm_load_pd( MMCAST(A0_off + 312) );
         B0 = _mm_load_pd( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_pd( A0, c0_0 );
         c0_1 = B0;
         c0_1 = _mm_mul_pd( A1, c0_1 );
         c0_2 = B0;
         c0_2 = _mm_mul_pd( A2, c0_2 );
         c0_3 = B0;
         c0_3 = _mm_mul_pd( A3, c0_3 );
         c0_4 = B0;
         c0_4 = _mm_mul_pd( A4, c0_4 );
         c0_5 = B0;
         c0_5 = _mm_mul_pd( A5, c0_5 );
         c0_6 = B0;
         c0_6 = _mm_mul_pd( A6, c0_6 );
         c0_7 = B0;
         c0_7 = _mm_mul_pd( A7, c0_7 );
         c0_8 = B0;
         c0_8 = _mm_mul_pd( A8, c0_8 );
         c0_9 = B0;
         c0_9 = _mm_mul_pd( A9, c0_9 );
         c0_10 = B0;
         c0_10 = _mm_mul_pd( A10, c0_10 );
         c0_11 = B0;
         c0_11 = _mm_mul_pd( A11, c0_11 );
         c0_12 = B0;
         c0_12 = _mm_mul_pd( A12, c0_12 );
         
         for( k=2; k<26; k+=2 )
         {
            /* k_partialUnrolling: 0 */
            B0 = _mm_load_pd( MMCAST( B0_off + k ) );
            A0 = _mm_load_pd( MMCAST(A0_off + k));
            temp = _mm_mul_pd( B0, A0 );
            c0_0 = _mm_add_pd( temp, c0_0 );
            A1 = _mm_load_pd( MMCAST(A0_off + 26 + k));
            temp = _mm_mul_pd( B0, A1 );
            c0_1 = _mm_add_pd( temp, c0_1 );
            A2 = _mm_load_pd( MMCAST(A0_off + 52 + k));
            temp = _mm_mul_pd( B0, A2 );
            c0_2 = _mm_add_pd( temp, c0_2 );
            A3 = _mm_load_pd( MMCAST(A0_off + 78 + k));
            temp = _mm_mul_pd( B0, A3 );
            c0_3 = _mm_add_pd( temp, c0_3 );
            A4 = _mm_load_pd( MMCAST(A0_off + 104 + k));
            temp = _mm_mul_pd( B0, A4 );
            c0_4 = _mm_add_pd( temp, c0_4 );
            A5 = _mm_load_pd( MMCAST(A0_off + 130 + k));
            temp = _mm_mul_pd( B0, A5 );
            c0_5 = _mm_add_pd( temp, c0_5 );
            A6 = _mm_load_pd( MMCAST(A0_off + 156 + k));
            temp = _mm_mul_pd( B0, A6 );
            c0_6 = _mm_add_pd( temp, c0_6 );
            A7 = _mm_load_pd( MMCAST(A0_off + 182 + k));
            temp = _mm_mul_pd( B0, A7 );
            c0_7 = _mm_add_pd( temp, c0_7 );
            A8 = _mm_load_pd( MMCAST(A0_off + 208 + k));
            temp = _mm_mul_pd( B0, A8 );
            c0_8 = _mm_add_pd( temp, c0_8 );
            A9 = _mm_load_pd( MMCAST(A0_off + 234 + k));
            temp = _mm_mul_pd( B0, A9 );
            c0_9 = _mm_add_pd( temp, c0_9 );
            A10 = _mm_load_pd( MMCAST(A0_off + 260 + k));
            temp = _mm_mul_pd( B0, A10 );
            c0_10 = _mm_add_pd( temp, c0_10 );
            A11 = _mm_load_pd( MMCAST(A0_off + 286 + k));
            temp = _mm_mul_pd( B0, A11 );
            c0_11 = _mm_add_pd( temp, c0_11 );
            A12 = _mm_load_pd( MMCAST(A0_off + 312 + k));
            temp = _mm_mul_pd( B0, A12 );
            c0_12 = _mm_add_pd( temp, c0_12 );
         }
         prefetchABlock += 2*pfBlockDistance;
         /* Combine scalar expansion back to scalar */
         /* handling uneven case */
         /* double */
         c0_0 = _mm_hadd_pd( c0_0, c0_1 );
         /* double */
         c0_2 = _mm_hadd_pd( c0_2, c0_3 );
         /* double */
         c0_4 = _mm_hadd_pd( c0_4, c0_5 );
         /* double */
         c0_6 = _mm_hadd_pd( c0_6, c0_7 );
         /* double */
         c0_8 = _mm_hadd_pd( c0_8, c0_9 );
         /* double */
         c0_10 = _mm_hadd_pd( c0_10, c0_11 );
         c0_12 = _mm_hadd_pd( c0_12, c0_12 );
         /* Applying Beta */
            /* Apply Beta Factor */
            /* Load C from memory */
            bc0_0 = _mm_loadu_pd( cPtrI0+0 );
            bc0_2 = _mm_loadu_pd( cPtrI0+2 );
            bc0_4 = _mm_loadu_pd( cPtrI0+4 );
            bc0_6 = _mm_loadu_pd( cPtrI0+6 );
            bc0_8 = _mm_loadu_pd( cPtrI0+8 );
            bc0_10 = _mm_loadu_pd( cPtrI0+10 );
            /* 1 remaining */
            bc0_12 = _mm_load_sd( cPtrI0+12 );
            /* C = (beta*C) + (matrix multiply) */
            c0_0 = _mm_add_pd( bc0_0, c0_0 );
            c0_2 = _mm_add_pd( bc0_2, c0_2 );
            c0_4 = _mm_add_pd( bc0_4, c0_4 );
            c0_6 = _mm_add_pd( bc0_6, c0_6 );
            c0_8 = _mm_add_pd( bc0_8, c0_8 );
            c0_10 = _mm_add_pd( bc0_10, c0_10 );
            c0_12 = _mm_add_sd( bc0_12, c0_12 );
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_storeu_pd( MMCAST( cPtrI0 ),  MMCASTStoreintrin( c0_0 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+2 ),  MMCASTStoreintrin( c0_2 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+4 ),  MMCASTStoreintrin( c0_4 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+6 ),  MMCASTStoreintrin( c0_6 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+8 ),  MMCASTStoreintrin( c0_8 ) );
         _mm_storeu_pd( MMCAST( cPtrI0+10 ),  MMCASTStoreintrin( c0_10 ) );
         _mm_store_sd( cPtrI0+12,  c0_12 );
         cPtrI0 += I_UNROLL;
         

      } /* End i/MB loop */

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
#endif
