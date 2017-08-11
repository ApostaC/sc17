#ifndef ATL_stGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,192,384,768,1152,1344,1408,1472,1536,3072,6208
 * N : 25,192,384,768,1152,1344,1408,1472,1536,3072,6208
 * NB : 4,64,64,64,64,64,64,64,128,128,128
 */
#define ATL_stGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 108) (nb_) = 4; \
   else if ((n_) < 1504) (nb_) = 64; \
   else (nb_) = 128; \
}


#endif    /* end ifndef ATL_stGetNB_geqrf */
