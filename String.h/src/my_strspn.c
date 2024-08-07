#include "my_string.h"

my_size_t my_strspn(const char *str, const char *sym) {
  my_size_t count = 0;
  int found = 0, exit = 0;
  while ((*str) && (exit == 0)) {
    const char *s = sym;
    found = 0;
    while ((*s) && (exit == 0)) {
      if (*str == *s) {
        found = 1;
        exit = 1;
      }
      s++;
    }
    exit = 0;
    if (found) {
      count++;
    } else {
      exit = 1;
    }
    str++;
  }
  return count;
}