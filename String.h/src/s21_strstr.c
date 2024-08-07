#include "s21_string.h"

char *s21_strstr(const char *str1, const char *str2) {
  char *result = s21_NULL;
  int flag = 0;
  if (*str2 == '\0') {
    result = (char *)str1;
  }

  while (*str1 != '\0' && !flag) {
    const char *s1 = str1;
    const char *s2 = str2;

    while (*s2 != '\0' && *s1 == *s2) {
      s1++;
      s2++;
    }

    if (*s2 == '\0') {
      result = (char *)str1;
      flag = 1;
    }

    str1++;
  }

  return result;
}