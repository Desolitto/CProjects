#include "my_string.h"

char *my_strcat(char *dest, const char *src) {
  int len = 0;
  while (*dest) {
    dest++;
    len++;
  }
  while (*src) {
    *dest = *src;
    dest++;
    src++;
    len++;
  }
  *dest = '\0';
  dest -= len;
  return dest;
}
