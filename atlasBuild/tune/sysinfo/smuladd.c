double macase(int nrep, volatile float *dum)
/*
 *  Performs nrep loop its and returns mflops performed
 */
{
   register float m0, a0=0.0, m1, a1=0.0, m2, a2=0.0, m3, a3=0.0, m4, a4=0.0, m5, a5=0.0, m6, a6=0.0, m7, a7=0.0, m8, a8=0.0;
   register int i;
    m0=dum[0];
    m1=dum[1];
    m2=dum[2];
    m3=dum[3];
    m4=dum[4];
    m5=dum[5];
    m6=dum[6];
    m7=dum[7];
    m8=dum[8];
   for (i=0; i < nrep; i++)
   {
/*
 * Basic block 0
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 1
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 2
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 3
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 4
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 5
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 6
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 7
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 8
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 9
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 10
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 11
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 12
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 13
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
/*
 * Basic block 14
 */
      a0 += m0*m0;  m0=m1;
      a1 += m1*m1;  m1=m2;
      a2 += m2*m2;  m2=m3;
      a3 += m3*m3;  m3=m4;
      a4 += m4*m4;  m4=m5;
      a5 += m5*m5;  m5=m6;
      a6 += m6*m6;  m6=m7;
      a7 += m7*m7;  m7=m8;
      a8 += m8*m8;  m8=m0;
   }

   dum[0] = a0;
   dum[1] = a1;
   dum[2] = a2;
   dum[3] = a3;
   dum[4] = a4;
   dum[5] = a5;
   dum[6] = a6;
   dum[7] = a7;
   dum[8] = a8;
   return(nrep*270.0);
}
