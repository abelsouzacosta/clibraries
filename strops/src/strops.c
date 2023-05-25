#include "../includes/strops.h"
#include <stddef.h>
#include <string.h>

size_t _getlength(char *str) {
  size_t length = strlen(str);
  return length;
}

void to_lower_case(char *str) {
  for (size_t counter = 0; counter < _getlength(str); counter += 1) {
    if (str[counter] >= 65 && str[counter] <= 90) {
      str[counter] += 32;
    }
  }
}

void to_upper_case(char *str) {
  for (size_t counter = 0; counter < _getlength(str); counter += 1) {
    if (str[counter] >= 97 && str[counter] <= 122) {
      str[counter] -= 32;
    }
  }
}
