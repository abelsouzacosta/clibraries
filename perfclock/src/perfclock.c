#include "../include/perfclock.h"
#include <stdio.h>
#include <time.h>

clock_t start_time;

void start_counter() { start_time = clock(); }

void stop_counter() {
  clock_t end_time = clock();
  double total_elapsed_time = ((double)(end_time - start_time));
  fprintf(stdout, "The total elapsed time: %f", total_elapsed_time);
}
