#include "s21_string.h"

char *s21_strcpy(char *destination, const char *source) {
  char *start = destination;
  while (*source) {
    *destination = *source;
    destination++;
    source++;
  }
  *destination = '\0';
  return start;
}