#include <stdlib.h>  // ПЕРЕНЕСТИ В БИБЛИОТЕКУ STRING.H

#include "my_string.h"

void *my_to_upper(const char *str) {
  char *str_copy = my_NULL;
  if (str != my_NULL) {
    int length_str = my_strlen(str);
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