// The C library function
// void *memcpy(void *dest, const void *src, size_t n)
// copies n characters from memory area src to memory area dest.

#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *d = dest;
  const char *s = src;

  while (n--) {
    *d++ = *s++;
  }
  return dest;
}
