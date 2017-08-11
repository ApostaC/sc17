#ifndef ZMM_H
   #define ZMM_H

   #define ATL_mmMULADD
   #define ATL_mmLAT 8
   #define ATL_mmMU  3
   #define ATL_mmNU  4
   #define ATL_mmKU  56
   #define MB 48
   #define NB 48
   #define KB 48
   #define NBNB 2304
   #define MBNB 2304
   #define MBKB 2304
   #define NBKB 2304
   #define NB2 96
   #define NBNB2 4608

   #define ATL_MulByNB(N_) ((N_) * 48)
   #define ATL_DivByNB(N_) ((N_) / 48)
   #define ATL_MulByNBNB(N_) ((N_) * 2304)

#endif
