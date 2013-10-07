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
    Vector **vector;
  } Matrix;

  Matrix *new_matrix(int, int);

#endif
