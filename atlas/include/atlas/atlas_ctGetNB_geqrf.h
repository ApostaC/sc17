#ifndef ATL_ctGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,160,400,880,1840,3680
 * N : 25,160,400,880,1840,3680
 * NB : 2,80,80,80,80,160
 */
#define ATL_ctGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 92) (nb_) = 2; \
   else if ((n_) < 2760) (nb_) = 80; \
   else (nb_) = 160; \
}


#endif    /* end ifndef ATL_ctGetNB_geqrf */
