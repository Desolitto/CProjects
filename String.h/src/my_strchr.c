#include "my_string.h"

char *my_strchr(const char *str, int c) {
  char *result = my_NULL;
  while (*str != '\0') {
    if (*str == c) {
      result = (char *)str;
    }
    str++;
  }
  if (c == '\0') {
    result = (char *)str;
  }

  return result;
}
