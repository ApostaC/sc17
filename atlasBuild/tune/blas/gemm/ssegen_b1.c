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
   __m128 temp0;  
   __m128 temp1;  
   __m128 temp2;  
   __m128 temp3;  
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = 2*ldc;
   
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
         /* Prefetch one element from the next block of A */
         __builtin_prefetch( prefetchABlock,PF_READONLY,PF_DEF );
         prefetchABlock += pfBlockDistance;
         
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
         
         for( k=4; k<44; k+=4 )
         {
            /* k_partialUnrolling: 0 */
            B0 = _mm_load_ps( MMCAST( B0_off + k ) );
            A0 = _mm_load_ps( MMCAST(A0_off + k));
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
            A1 = _mm_load_ps( MMCAST(A0_off + 44 + k));
            temp = _mm_mul_ps( B0, A1 );
            c0_1 = _mm_add_ps( temp, c0_1 );
            A2 = _mm_load_ps( MMCAST(A0_off + 88 + k));
            temp = _mm_mul_ps( B0, A2 );
            c0_2 = _mm_add_ps( temp, c0_2 );
            A3 = _mm_load_ps( MMCAST(A0_off + 132 + k));
            temp = _mm_mul_ps( B0, A3 );
            c0_3 = _mm_add_ps( temp, c0_3 );
            A4 = _mm_load_ps( MMCAST(A0_off + 176 + k));
            temp = _mm_mul_ps( B0, A4 );
            c0_4 = _mm_add_ps( temp, c0_4 );
            A5 = _mm_load_ps( MMCAST(A0_off + 220 + k));
            temp = _mm_mul_ps( B0, A5 );
            c0_5 = _mm_add_ps( temp, c0_5 );
            A6 = _mm_load_ps( MMCAST(A0_off + 264 + k));
            temp = _mm_mul_ps( B0, A6 );
            c0_6 = _mm_add_ps( temp, c0_6 );
            A7 = _mm_load_ps( MMCAST(A0_off + 308 + k));
            temp = _mm_mul_ps( B0, A7 );
            c0_7 = _mm_add_ps( temp, c0_7 );
            A8 = _mm_load_ps( MMCAST(A0_off + 352 + k));
            temp = _mm_mul_ps( B0, A8 );
            c0_8 = _mm_add_ps( temp, c0_8 );
            A9 = _mm_load_ps( MMCAST(A0_off + 396 + k));
            temp = _mm_mul_ps( B0, A9 );
            c0_9 = _mm_add_ps( temp, c0_9 );
            A10 = _mm_load_ps( MMCAST(A0_off + 440 + k));
            temp = _mm_mul_ps( B0, A10 );
            c0_10 = _mm_add_ps( temp, c0_10 );
         }
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
            temp0 = _mm_load_ss( cPtrI0 + 0 );
            temp1 = _mm_load_ss( cPtrI0 + 2 );
            temp2 = _mm_load_ss( cPtrI0 + 4 );
            temp3 = _mm_load_ss( cPtrI0 + 6 );
            temp0 = _mm_unpacklo_ps( temp0, temp1 );
            temp2 = _mm_unpacklo_ps( temp2, temp3 );
            bc0_0 = _mm_movelh_ps( temp0, temp2 );
            temp0 = _mm_load_ss( cPtrI0 + 8 );
            temp1 = _mm_load_ss( cPtrI0 + 10 );
            temp2 = _mm_load_ss( cPtrI0 + 12 );
            temp3 = _mm_load_ss( cPtrI0 + 14 );
            temp0 = _mm_unpacklo_ps( temp0, temp1 );
            temp2 = _mm_unpacklo_ps( temp2, temp3 );
            bc0_4 = _mm_movelh_ps( temp0, temp2 );
            /* 3 remaining */
            bc0_8 = _mm_load_ss( cPtrI0+16 );
            /* 2 remaining */
            bc0_9 = _mm_load_ss( cPtrI0+18 );
            /* 1 remaining */
            bc0_10 = _mm_load_ss( cPtrI0+20 );
            /* C = (beta*C) + (matrix multiply) */
            c0_0 = _mm_add_ps( bc0_0, c0_0 );
            c0_4 = _mm_add_ps( bc0_4, c0_4 );
            c0_8 = _mm_add_ss( bc0_8, c0_8 );
            c0_9 = _mm_add_ss( bc0_9, c0_9 );
            c0_10 = _mm_add_ss( bc0_10, c0_10 );
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         temp = c0_0;
         _mm_store_ss( cPtrI0+0, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(1,1,1,1));
         _mm_store_ss( cPtrI0+2, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(2,2,2,2));
         _mm_store_ss( cPtrI0+4, temp );
         temp = _mm_shuffle_ps( c0_0, c0_0,_MM_SHUFFLE(3,3,3,3));
         _mm_store_ss( cPtrI0+6, temp );
         temp = c0_4;
         _mm_store_ss( cPtrI0+8, temp );
         temp = _mm_shuffle_ps( c0_4, c0_4,_MM_SHUFFLE(1,1,1,1));
         _mm_store_ss( cPtrI0+10, temp );
         temp = _mm_shuffle_ps( c0_4, c0_4,_MM_SHUFFLE(2,2,2,2));
         _mm_store_ss( cPtrI0+12, temp );
         temp = _mm_shuffle_ps( c0_4, c0_4,_MM_SHUFFLE(3,3,3,3));
         _mm_store_ss( cPtrI0+14, temp );
          _mm_store_ss( cPtrI0+16, c0_8 );
          _mm_store_ss( cPtrI0+18, c0_9 );
          _mm_store_ss( cPtrI0+20, c0_10 );
         cPtrI0 += 2*I_UNROLL;
         

      } /* End i/MB loop */

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
