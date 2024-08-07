#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *d = dest;
  const char *s = src;

  if (s < d) {
    s += n;
    d += n;
    while (n--) {
      *(--d) = *(--s);
    }
  } else {
    while (n--) {
      *d++ = *s++;
    }
  }

  return dest;
}