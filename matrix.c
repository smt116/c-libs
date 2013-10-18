/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

Matrix *new_matrix(unsigned long long int n, unsigned long long int m) {
  Matrix *v;

  v = MALLOC(Matrix, 1);

  v->n = n;
  v->m = m;
  v->data = MALLOC(double, v->n * v->m);

  return v;
}

void delete_matrix(Matrix *p) {
  if(p) {
    if(p->data) {
      free(p->data);
    }
    free(p);
  }
}

void set_matrix_with_var(Matrix *p, double x) {
  unsigned long long int i;

  for(i=0; i < (p->m * p->n); i++) {
    p->data[i] = x;
  }
}

void set_matrix_with_vars(Matrix *p, double *data) {
  unsigned long long int i;

  for(i=0; i < (p->m * p->n); i++) {
    p->data[i] = data[i];
  }
}

void print_matrix(Matrix *p, char *name) {
  unsigned long long int i, k;

  printf("\n%s [%llu, %llu]\n", name, p->n, p->m);
  for(i=0; i < p->n; i++) {
    printf("| ");
    for(k=0; k < p->m; k++) {
      if((k+1) == p->m) {
        printf("%4.2lf |\n", p->data[(i*p->m)+k]);
      } else {
        printf("%4.2lf, ", p->data[(i*p->m)+k]);
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
  unsigned long long int i, k, l;

  for(i=0; i < p->n; i++) {
    for(k=0; k < p->m; k++) {
      for(l=0; l < q->n; l++) {
        ptr->data[(i * ptr->n) + l] += 
          p->data[(i * p->n) + k] * q->data[(k * q->n) + l];
      }
    }
  }

  return ptr;
}

void randomize_matrix(Matrix *p, unsigned long long int max) {
  unsigned long long int i;
  srand(time(NULL));

  for(i=0; i < (p->n * p->m); i++) {
    p->data[i] = (rand() % max) + (double) rand() / RAND_MAX;
  }
}
