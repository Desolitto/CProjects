#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int count = 0;
  va_list tr;
  va_start(tr, format);
  int lengthStr = (int)s21_strlen(str);
  int lengthFormat = (int)s21_strlen(format);
  count = s21_handleSscanf(str, format, &tr, lengthStr, lengthFormat);
  va_end(tr);
  return count;
}