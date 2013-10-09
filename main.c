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

  multiply_vector_by(p, 3);
  printf("3 * p [%i, %i, %i]\n", p->data[0], p->data[1], p->data[2]);

  printf("p[%i, %i, %i]\n", p->data[0], p->data[1], p->data[2]);
  printf("q[%i, %i]\n", q->data[0], q->data[1]);

  ptr = multiply_vectors(p, q);
  printf("p * q [%i, %i, %i]\n", ptr->data[0], ptr->data[1], ptr->data[2]);

  Matrix *a,
         *b;
  a = new_matrix(2,3);
  b = new_matrix(3,2);
  a->vector[0]->data[0] = 1;
  a->vector[0]->data[1] = 2;
  a->vector[0]->data[2] = 3;
  a->vector[1]->data[0] = 11;
  a->vector[1]->data[1] = 22;
  a->vector[1]->data[2] = 33;
  b->vector[0]->data[0] = 111;
  b->vector[0]->data[1] = 222;
  b->vector[1]->data[0] = 333;
  b->vector[1]->data[1] = 1111;
  b->vector[2]->data[0] = 2222;
  b->vector[2]->data[1] = 3333;

  start_time();
  printf("strin");
  stop_time();
  printf("%0.16lf\n", time_diff());


  return 0;
}
