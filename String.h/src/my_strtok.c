#include "my_string.h"

char *my_strtok(char *str1, const char *str2) {
  static char *str_offset;
  char *return_token = (char *)str2;

  if ((str1 == my_NULL) && ((str1 = str_offset) == my_NULL)) {
    return_token = my_NULL;
  }

  char *str = str1;
  int find_token = 1;
  for (; (str) && (*str) && (find_token == 1); str++) {
    find_token = 0;
    for (char *delim = (char *)str2; (*delim) && (find_token == 0); delim++) {
      if (*str == *delim) find_token = 1;
    }
  }

  if ((str) && (*str == '\0') && (find_token == 1)) {
    str_offset = my_NULL;
    return_token = my_NULL;
  } else if (str) {
    return_token = str - 1;
    str -= 1;
  }

  for (int find_delim = 0; (str) && (*str) && (find_delim == 0); str++) {
    for (char *delim = (char *)str2; (*delim) && (find_delim == 0); delim++) {
      if (*str == *delim) {
        *str = '\0';
        find_delim = 1;
      }
    }
    str_offset = str + 1;
  }

  return return_token;
}
