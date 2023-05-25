#include "./include/fancy.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FancyArray *array = (FancyArray *)create(8);

  for (int counter = 1; counter < 8; counter += 1) {
    append(array, counter);
  }

  print(array);

  remove_element(&array, 3);

  print(array);

  return EXIT_SUCCESS;
}
