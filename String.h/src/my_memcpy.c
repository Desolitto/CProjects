// The C library function
// void *memcpy(void *dest, const void *src, size_t n)
// copies n characters from memory area src to memory area dest.

#include "my_string.h"

void *my_memcpy(void *dest, const void *src, my_size_t n) {
  char *d = dest;
  const char *s = src;

  while (n--) {
    *d++ = *s++;
  }
  return dest;
}
