#include "./include/console.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  clear_screen();
  write_console("Teste");
  callout("Another test");
  throw_error("Teste");
  return EXIT_SUCCESS;
}
