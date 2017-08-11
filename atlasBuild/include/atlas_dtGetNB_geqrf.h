#ifndef ATL_dtGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,112,168,280,616,1232,2464,4928
 * N : 25,112,168,280,616,1232,2464,4928
 * NB : 7,8,56,56,56,56,56,112
 */
#define ATL_dtGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 68) (nb_) = 7; \
   else if ((n_) < 140) (nb_) = 8; \
   else if ((n_) < 3696) (nb_) = 56; \
   else (nb_) = 112; \
}


#endif    /* end ifndef ATL_dtGetNB_geqrf */
