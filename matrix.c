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
  v->data = MALLOC(int, v->n * v->m);

  return v;
}

void delete_matrix(Matrix *p) {
  free(p->data);
  free(p);
}
