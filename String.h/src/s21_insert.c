#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_src = s21_NULL;
  const char *str1 = s21_NULL;
  int error_index = 0;
  s21_size_t len_src = 0, len_str = 0;

  if ((src != s21_NULL) && (str != s21_NULL)) {
    str1 = str;
    len_src = s21_strlen(src);
    len_str = s21_strlen(str1);
    len_src += len_str;

    if ((len_src - len_str) < start_index) {
      error_index = 1;
    }
  }

  if ((src == s21_NULL) || (str == s21_NULL) || (error_index == 1)) {
    new_src = s21_NULL;
  } else {
    new_src = (char *)calloc(len_src + 1, sizeof(char));

    if (new_src) {
      for (s21_size_t i = 0; (i < start_index); i++) {
        new_src[i] = src[i];
      }

      for (s21_size_t i = start_index; (*str1); i++) {
        new_src[i] = *str1;
        ++str1;
      }

      for (s21_size_t i = start_index + len_str; (i <= len_src); i++) {
        new_src[i] = src[i - len_str];
      }
    }
  }

  return new_src;
}