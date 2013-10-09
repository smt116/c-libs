/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#ifndef SMT__LOCAL_MATRIX_LIB
#define SMT__LOCAL_MATRIX_LIB

  #include "vector.h"

  typedef struct Matrix {
    int n;
    int m;
    int *data;
  } Matrix;

  Matrix *new_matrix(int, int);
  void delete_matrix(Matrix *);

#endif
