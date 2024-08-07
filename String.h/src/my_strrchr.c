//  fix return

#include "my_string.h"

char *my_strrchr(const char *str, int c) {
  const char *last_occurrence = my_NULL;
  char *result = my_NULL;

  while (*str != '\0') {
    if (*str == c) {
      last_occurrence = str;
    }
    str++;
  }

  if (c == '\0') {
    result = (char *)str;
  } else {
    result = (char *)last_occurrence;
  }

  return result;
}
