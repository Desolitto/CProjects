#include "my_string.h"

char *my_strcpy(char *destination, const char *source) {
  char *start = destination;
  while (*source) {
    *destination = *source;
    destination++;
    source++;
  }
  *destination = '\0';
  return start;
}