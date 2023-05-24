#include "../include/console.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void write_console(char *str, ...) {
  va_list args;
  va_start(args, str);
  printf("\033[0;32m");
  vprintf(str, args);
  printf("\033[0m");
}

void throw_error(char *str, ...) {
  va_list args;
  va_start(args, str);
  fprintf(stderr, "\033[0;31m");
  vfprintf(stderr, str, args);
  fprintf(stderr, "\033[0m");
  va_end(args);
}

void callout(char *str, ...) {
  va_list args;
  va_start(args, str);
  printf("\033[0;33m");
  vprintf(str, args);
  printf("\033[0m");
}

void clear_screen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
