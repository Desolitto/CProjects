#include "my_string.h"

void *my_insert(const char *src, const char *str, my_size_t start_index) {
  char *new_src = my_NULL;
  const char *str1 = my_NULL;
  int error_index = 0;
  my_size_t len_src = 0, len_str = 0;

  if ((src != my_NULL) && (str != my_NULL)) {
    str1 = str;
    len_src = my_strlen(src);
    len_str = my_strlen(str1);
    len_src += len_str;

    if ((len_src - len_str) < start_index) {
      error_index = 1;
    }
  }

  if ((src == my_NULL) || (str == my_NULL) || (error_index == 1)) {
    new_src = my_NULL;
  } else {
    new_src = (char *)calloc(len_src + 1, sizeof(char));

    if (new_src) {
      for (my_size_t i = 0; (i < start_index); i++) {
        new_src[i] = src[i];
      }

      for (my_size_t i = start_index; (*str1); i++) {
        new_src[i] = *str1;
        ++str1;
      }

      for (my_size_t i = start_index + len_str; (i <= len_src); i++) {
        new_src[i] = src[i - len_str];
      }
    }
  }

  return new_src;
}