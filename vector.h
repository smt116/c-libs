/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#ifndef SMT__LOCAL_VECTOR_LIB
#define SMT__LOCAL_VECTOR_LIB

  typedef struct Vector {
    int size;
    int *data;
  } Vector;

  Vector *new_vector(int);

  /*
   * Be sure that p->size >= q->size!
   */
  Vector *add_vectors(Vector *, Vector *);
  void multiply_vector_by(Vector *, int);
  Vector *multiply_vectors(Vector *, Vector *);

#endif
