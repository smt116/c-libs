/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

Matrix *new_matrix(int n, int m) {
  Matrix *v;
  int i;

  v = MALLOC(Matrix, 1);

  v->n = n;
  v->m = m;
  v->vector = MALLOC(Vector *, n);

  for(i=0; i < v->n; i++) {
    v->vector[i] = new_vector(m);
  }

  return v;
}
