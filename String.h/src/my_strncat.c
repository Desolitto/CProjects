#include "my_string.h"

char *my_strncat(char *dest, const char *src, my_size_t n) {
  char *original = dest;

  while (*dest != '\0') {
    dest++;
  }

  while (*src != '\0' && n > 0) {
    *dest = *src;
    dest++;
    src++;
    n--;
  }

  *dest = '\0';
  return original;
}