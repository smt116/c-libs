/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#ifndef SMT__LOCAL_TIME_LIB
#define SMT__LOCAL_TIME_LIB

  #include <time.h>

  typedef struct Time {
    clock_t start;
    clock_t stop;
    unsigned diff_in_milliseconds;
  } Time;

  Time *new_time(void);
  void start_time(Time *);
  void stop_time(Time *);
  unsigned time_diff(Time *);

#endif
