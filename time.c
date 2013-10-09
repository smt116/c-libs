/*
 * Maciej Małecki
 * sm__time_stop16@gmail.com
 */
#include "lib.h"

void start_time(void) {
  clock_gettime(CLOCK_REALTIME, &__time_start);
}

void stop_time(void) {
  clock_gettime(CLOCK_REALTIME, &__time_stop);
}

double time_diff(void) {
  return ((__time_stop.tv_sec + __time_stop.tv_nsec)/MLD) -
          ((__time_start.tv_sec + __time_start.tv_nsec)/MLD);
}
