#ifndef ATL_zGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,112,280,560,1176,2408
 * N : 25,112,280,560,1176,2408
 * NB : 12,56,56,56,168,168
 */
#define ATL_zGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 68) (nb_) = 12; \
   else if ((n_) < 868) (nb_) = 56; \
   else (nb_) = 168; \
}


#endif    /* end ifndef ATL_zGetNB_geqrf */
