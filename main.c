/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main() {

  Vector *p = new_vector(3),
         *q = new_vector(2),
         *ptr;
  {
    double a[2] = {3,4};
    set_vector_with_var(p, 1);
    set_vector_with_vars(q, a);
  }

  print_vector(p, "p");
  print_vector(q, "q");

  ptr = add_vectors(p, q);
  print_vector(ptr, "p + q");
  delete_vector(ptr);

  multiply_vector_by(p, 3);
  print_vector(p, "3 * p");

  print_vector(p, "p");
  print_vector(q, "q");

  ptr = multiply_vectors(p, q);
  print_vector(ptr, "p * q");
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
