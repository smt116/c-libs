/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

Vector *new_vector(int size) {
  Vector *v;

  v = MALLOC(Vector, 1);

  v->size = size;
  v->data = MALLOC(int, v->size);

  return v;
}

/*
 * Be sure that p->size >= q->size!
 */
Vector *add_vectors(Vector *p, Vector *q) {
  Vector v, *ptr;
  int i;

  v.size = p->size;
  v.data = MALLOC(int, v.size);

  for(i=0; i < q->size; i++) {
    v.data[i] = p->data[i] + q->data[i];
  }
  if(i < p->size) {
    for(i=i; i < p->size; i++) {
      v.data[i] = p->data[i];
    }
  }

  ptr = &v;
  return ptr;
}

void multiply_vector_by(Vector *p, int a) {
  int i;

  for(i=0; i < p->size; i++) {
    p->data[i] *= a;
  }
}

Vector *multiply_vectors(Vector *p, Vector *q) {
  Vector v, *ptr;
  int i;

  if(p->size < q->size) {
    v.size = q->size;
  } else {
    v.size = p->size;
  }
  v.data = MALLOC(int, v.size);

  for(i=0; i < v.size; i++) {
    if(p->data[i] && q->data[i]) {
      v.data[i] = p->data[i] * q->data[i];
    } else {
      v.data[i] = 0;
    }
  }

  ptr = &v;
  return ptr;
}
