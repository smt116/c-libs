/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main(int argc, char **argv) {

  double arg1;
  get_double_from_args("-size", &arg1, argc, argv);
  if(arg1)
    printf("size: %lf\n", arg1);

  Vector *p = new_vector(3),
         *q = new_vector(2),
         *ptr;
  {
    double a[2] = {3,4};
    set_vector_with_var(p, 1);
    set_vector_with_vars(q, a);
  }

  printf("%lf\n", reduce_vector(q, 0, 2));

  print_vector(p, "p");
  print_vector(q, "q");

  ptr = add_vectors(p, q);
  print_vector(ptr, "p + q");
  delete_vector(ptr);

  multiply_vector_by(p, 3.15);
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
  a = new_matrix(4,5);
  set_matrix_with_var(a, 22);
  print_matrix(a, "a");
  delete_matrix(a);

  a = new_matrix(3,3);
  b = new_matrix(3,1);
  {
    double vars1[3] = { 1, 2, 3 },
           vars2[9] = { 3, 2, 1, 1, 2, 3, 2, 3, 1 };
    set_matrix_with_vars(a, vars2);
    set_matrix_with_vars(b, vars1);
  }
  print_matrix(a, "a");
  print_matrix(b, "b");

/*
  Matrix *c = product_matrix(a, b);
  print_matrix(c, "c");
  delete_matrix(c);
*/

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
