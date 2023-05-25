#include "./includes/strops.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char str[100];

  printf("Digite qualquer coisa: ");
  fgets(str, 100, stdin);

  printf("%s", str);

  return EXIT_SUCCESS;
}
