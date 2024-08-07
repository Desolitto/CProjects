#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *s = str;
  unsigned char uc = c;
  void *result = s21_NULL;

  while (n-- > 0 && result == s21_NULL) {
    if (*s == uc) {
      result = (void *)s;
    }
    s++;
  }
  return result;
}
