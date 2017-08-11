#ifndef ATL_sGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,128,256,576,1216,1792,2112,2240,2432,4928
 * N : 25,128,256,576,1216,1792,2112,2240,2432,4928
 * NB : 12,64,68,64,64,64,64,64,192,192
 */
#define ATL_sGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 76) (nb_) = 12; \
   else if ((n_) < 192) (nb_) = 64; \
   else if ((n_) < 416) (nb_) = 68; \
   else if ((n_) < 2336) (nb_) = 64; \
   else (nb_) = 192; \
}


#endif    /* end ifndef ATL_sGetNB_geqrf */
