#ifndef ATL_dGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,224,336,448,952,1456,1960,3920
 * N : 25,224,336,448,952,1456,1960,3920
 * NB : 12,12,56,56,56,56,112,168
 */
#define ATL_dGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 280) (nb_) = 12; \
   else if ((n_) < 1708) (nb_) = 56; \
   else if ((n_) < 2940) (nb_) = 112; \
   else (nb_) = 168; \
}


#endif    /* end ifndef ATL_dGetNB_geqrf */
