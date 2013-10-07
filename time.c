/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

Time *new_time(void) {
  Time *v;

  v = MALLOC(Time, 1);

  return v;
}

void start_time(Time *p) {
  p->start = clock();
}

void stop_time(Time *p) {
  p->stop = clock();
}

unsigned time_diff(Time *p) {
  p->diff_in_milliseconds = difftime(p->stop, p->start) / 1000;
  return p->diff_in_milliseconds;
}
