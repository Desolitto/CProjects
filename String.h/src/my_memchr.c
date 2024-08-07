#include "my_string.h"

void *my_memchr(const void *str, int c, my_size_t n) {
  const unsigned char *s = str;
  unsigned char uc = c;
  void *result = my_NULL;

  while (n-- > 0 && result == my_NULL) {
    if (*s == uc) {
      result = (void *)s;
    }
    s++;
  }
  return result;
}
