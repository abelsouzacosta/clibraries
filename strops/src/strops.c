#include "../includes/strops.h"
#include <stddef.h>

void to_lower_case(char *str) {
  size_t length = strlen(str);

  for (size_t counter = 0; counter < length; counter += 1) {
    if (str[counter] >= 65 && str[counter] <= 90) {
      str[counter] += 32;
    }
  }
}
