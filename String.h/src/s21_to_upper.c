#include <stdlib.h>  // ПЕРЕНЕСТИ В БИБЛИОТЕКУ STRING.H

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *str_copy = s21_NULL;
  if (str != s21_NULL) {
    int length_str = s21_strlen(str);
    str_copy = malloc(sizeof(char *) * (length_str + 1));
    if (str_copy) {
      for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
          str_copy[i] = (str[i] - 'a') + 'A';
        else
          str_copy[i] = str[i];
      }
    }
    str_copy[length_str] = '\0';
  }
  return str_copy;
}