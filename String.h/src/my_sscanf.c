#include "my_sscanf.h"

int my_sscanf(const char *str, const char *format, ...) {
  int count = 0;
  va_list tr;
  va_start(tr, format);
  int lengthStr = (int)my_strlen(str);
  int lengthFormat = (int)my_strlen(format);
  count = my_handleSscanf(str, format, &tr, lengthStr, lengthFormat);
  va_end(tr);
  return count;
}