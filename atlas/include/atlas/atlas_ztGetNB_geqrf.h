#ifndef ATL_ztGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,168,336,728,1512,2240,3024
 * N : 25,168,336,728,1512,2240,3024
 * NB : 5,56,56,56,56,56,112
 */
#define ATL_ztGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 96) (nb_) = 5; \
   else if ((n_) < 2632) (nb_) = 56; \
   else (nb_) = 112; \
}


#endif    /* end ifndef ATL_ztGetNB_geqrf */
