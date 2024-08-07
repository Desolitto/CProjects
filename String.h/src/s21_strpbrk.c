#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  int flag = 0;
  while (*str1 != '\0') {
    const char *ptr = str2;
    while (*ptr != '\0') {
      if ((*ptr == *str1) && !flag) {
        result = (char *)str1;
        flag = 1;
      }
      ptr++;
    }
    str1++;
  }
  return result;
}