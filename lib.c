/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

double get_double_from_args(char *option, int argc, char **argv) {
  int i = 0;

  while(i < argc) {
    if(!strcmp(argv[i], option)) {
      return atof(argv[++i]);
    }
    i++;
  }

  return 0;
}
