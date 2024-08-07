#include "my_string.h"

int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  while (n > 0 && *str1 == *str2) {
    str1++;
    str2++;
    n--;
  }

  return (n == 0) ? 0 : (*(unsigned char *)str1 - *(unsigned char *)str2);
}