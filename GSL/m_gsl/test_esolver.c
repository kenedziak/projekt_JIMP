#include <stdlib.h>
#include <stdio.h>
#include "gsl_esolver.h"
#include "matrix.h"
int
main (void)
{
  FILE *in = fopen("gsl_esover.c","r");
  int i;
  int j;
  matrix_t test;
  test.e=malloc(20 *sizeof(double));
  
  
   
  test.e[0]=0.18;
  test.e[1]=0.60;
  test.e[2]=0.57;
  test.e[3]=0.96;
  test.e[4]=1;
  test.e[5]=0.41;
  test.e[6]=0.24;
  test.e[7]=0.99;
  test.e[8]=0.58;
  test.e[9]=2;
  test.e[10]=0.14;
  test.e[11]=0.30;
  test.e[12]=0.97;
  test.e[13]=0.66;
  test.e[14]=3;
  test.e[15]=0.51;
  test.e[16]=0.13;
  test.e[17]=0.19;
  test.e[18]=0.85;
  test.e[19]=4;
  
free(in);  
  


  test.cn=5;
  test.rn=4;
int r=0;
gsl_eq_solver(&test);
free(test.e);

printf("\n");
  return 0;
}
