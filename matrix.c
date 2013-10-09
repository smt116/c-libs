/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

Matrix *new_matrix(int n, int m) {
  Matrix *v;

  v = MALLOC(Matrix, 1);

  v->n = n;
  v->m = m;
  v->vector = new_vector(v->n * v->m);

  return v;
}

void delete_matrix(Matrix *p) {
  delete_vector(p->vector);
  free(p);
}

void set_matrix_with_var(Matrix *p, double x) {
  int i;

  for(i=0; i < p->vector->size; i++) {
    p->vector->data[i] = x;
  }
}

void set_matrix_with_vars(Matrix *p, double *data) {
  int i, k;

  for(i=0; i < p->n; i++) {
    for(k=0; k < p->m; k++) {
      p->vector->data[(i*p->m)+k] = data[(i*p->m)+k];
    }
  }
}

void print_matrix(Matrix *p, char *name) {
  int i, k;

  printf("\n%s [%i, %i]\n", name, p->n, p->m);
  for(i=0; i < p->n; i++) {
    printf("| ");
    for(k=0; k < p->m; k++) {
      if((k+1) == p->m) {
        printf("%4.2lf |\n", p->vector->data[(i*p->m)+k]);
      } else {
        printf("%4.2lf, ", p->vector->data[(i*p->m)+k]);
      }
    }
  }
}

Matrix *product_matrix(Matrix *p, Matrix *q) {
  if(p->m != q->n) {
    perror("m != n");
    exit(1);
  }

  Matrix *ptr = new_matrix(q->m, q->n);
  set_matrix_with_var(ptr, 0);
  int i, k, l;

  for(i=0; i < p->n; i++) {
    for(k=0; k < p->m; k++) {
      for(l=0; l < q->n; l++) {
        ptr->vector->data[(i * ptr->n) + l] += 
          p->vector->data[(i * p->n) + k] * q->vector->data[(k * q->n) + l];
      }
    }
  }

  return ptr;
}
