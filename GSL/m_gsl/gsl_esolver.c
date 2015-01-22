#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include "matrix.h"





 int gsl_matrix_data(double *a,double *b,matrix_t *m){
	int i;
	int j=0; 
	int r=0;
	int c=0;
  for (i = 0; i < m->rn; i++) {
    for (j = 0; j < m->cn-1 ; j++){
      a[r]=m->e[i * m->cn + j];
      r++;
      
    }
    b[c] = m->e[(i+1) * m->rn +(c)];
    c++;
  }

   return 0;
}



int gsl_eq_solver(matrix_t * m){


  int i;
  int j;
  double a_data[m->rn * m->rn];
  double b_data[1*m->cn];
  gsl_matrix_data(a_data,b_data,m);
 
  
  gsl_matrix_view k 
    = gsl_matrix_view_array (a_data, m->rn, m->rn);

  gsl_vector_view b
    = gsl_vector_view_array (b_data, m->rn);

  gsl_vector *x = gsl_vector_alloc (m->rn);
 
  int s;

  gsl_permutation * p = gsl_permutation_alloc (m->rn);
  gsl_linalg_LU_decomp (&k.matrix, p, &s);
  gsl_linalg_LU_solve (&k.matrix, p, &b.vector, x);


  
  

  for(j=1;j < m->cn+1 ;j++){
    i=m->cn*j-(1); 
    m->e[i]=x->data[j-1];
    
    
    
  }
    gsl_permutation_free (p);
    gsl_vector_free (x);
     
  return 0;
}


