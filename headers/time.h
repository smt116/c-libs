/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#ifndef SMT__LOCAL_TIME_LIB
#define SMT__LOCAL_TIME_LIB

  #include <time.h>

  #define MLD 1000000000.0

  struct timespec __time_start,
                  __time_stop;

  void start_time(void);
  void stop_time(void);
  double time_diff(void);

#endif
