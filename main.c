/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main() {

  Vector *p = new_vector(3),
         *q = new_vector(2),
         *ptr;

  p->data[0] = 1;
  p->data[1] = 2;
  p->data[2] = 3;
  q->data[0] = 10;
  q->data[1] = 11;

  printf("p[%i, %i, %i]\n", p->data[0], p->data[1], p->data[2]);
  printf("q[%i, %i]\n", q->data[0], q->data[1]);

  ptr = add_vectors(p, q);
  printf("p + q [%i, %i, %i]\n", ptr->data[0], ptr->data[1], ptr->data[2]);
  delete_vector(ptr);

  multiply_vector_by(p, 3);
  printf("3 * p [%i, %i, %i]\n", p->data[0], p->data[1], p->data[2]);

  printf("p[%i, %i, %i]\n", p->data[0], p->data[1], p->data[2]);
  printf("q[%i, %i]\n", q->data[0], q->data[1]);

  ptr = multiply_vectors(p, q);
  printf("p * q [%i, %i, %i]\n", ptr->data[0], ptr->data[1], ptr->data[2]);
  delete_vector(ptr);

  delete_vector(p);
  delete_vector(q);

  Matrix *a,
         *b;
  a = new_matrix(3,2);
  b = new_matrix(1,3);
  a->data[0] = 1;
  a->data[1] = 1;
  a->data[2] = 2;
  a->data[3] = 2;
  a->data[4] = 3;
  a->data[5] = 3;
  b->data[0] = 1;
  b->data[1] = 2;
  b->data[2] = 3;

  delete_matrix(a);
  delete_matrix(b);

  Time *t = new_time();
  start_time(t);
  printf("strin");
  stop_time(t);
  print_time(t);
  delete_time(t);


  return 0;
}
