/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

Vector *new_vector(int size) {
  Vector *v;

  v = MALLOC(Vector, 1);

  v->size = size;
  v->data = MALLOC(double, v->size);

  return v;
}

void set_vector_with_var(Vector *p, double x) {
  int i;

  for(i=0; i < p->size; i++) {
    p->data[i] = x;
  }
}

void set_vector_with_vars(Vector *p, double *data) {
  int i;

  for(i=0; i < p->size; i++) {
    p->data[i] = data[i];
  }
}

void print_vector(Vector *p, char *name) {
  int i;

  printf("%s(%i):[ ", name, p->size);
  for(i=0; i < p->size; i++) {
    if((i+1) == p->size) {
      printf("%4.2lf ]\n", p->data[i]);
    } else {
      printf("%4.2lf, ", p->data[i]);
    }
  }
}

/*
 * Be sure that p->size >= q->size!
 */
Vector *add_vectors(Vector *p, Vector *q) {
  Vector *v;
  int i;

  v = new_vector(p->size);

  for(i=0; i < q->size; i++) {
    v->data[i] = p->data[i] + q->data[i];
  }
  if(i < p->size) {
    for(i=i; i < p->size; i++) {
      v->data[i] = p->data[i];
    }
  }

  return v;
}

void multiply_vector_by(Vector *p, double a) {
  int i;

  for(i=0; i < p->size; i++) {
    p->data[i] *= a;
  }
}

Vector *multiply_vectors(Vector *p, Vector *q) {
  Vector *v;
  int i, size;

  if(p->size < q->size) {
    size = q->size;
  } else {
    size = p->size;
  }

  v = new_vector(size);

  for(i=0; i < size; i++) {
    if(i <= p->size && i <= q->size) {
      v->data[i] = p->data[i] * q->data[i];
    } else {
      v->data[i] = 0;
    }
  }

  return v;
}

void delete_vector(Vector *p) {
  free(p->data);
  free(p);
}

double reduce_vector(Vector *p, int start, int end) {
  int i;
  double sum = 0.0;

  for(i=start; i < end; i++) {
    sum += *(p->data + i);
  }

  return sum;
}
