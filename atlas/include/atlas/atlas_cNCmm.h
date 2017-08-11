#ifndef CMM_H
   #define CMM_H

   #define ATL_mmNOMULADD
   #define ATL_mmLAT 8
   #define ATL_mmMU  3
   #define ATL_mmNU  2
   #define ATL_mmKU  24
   #define MB 52
   #define NB 52
   #define KB 52
   #define NBNB 2704
   #define MBNB 2704
   #define MBKB 2704
   #define NBKB 2704
   #define NB2 104
   #define NBNB2 5408

   #define ATL_MulByNB(N_) ((N_) * 52)
   #define ATL_DivByNB(N_) ((N_) / 52)
   #define ATL_MulByNBNB(N_) ((N_) * 2704)

#endif
