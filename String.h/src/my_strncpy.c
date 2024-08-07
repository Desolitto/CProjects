#include "my_string.h"

char *my_strncpy(char *dest, const char *src, my_size_t n) {
  my_memset(dest, '\0', n);
  for (my_size_t i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  return dest;
}