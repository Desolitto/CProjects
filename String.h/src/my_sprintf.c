#include "my_sprintf.h"

int my_sprintf(char *str, const char *format, ...) {
  int count = 0;
  va_list tr;
  va_start(tr, format);
  flag flags = {0};
  int err = 0;

  while (*format != '\0') {
    if (*format != '%') {
      my_addCharToStr(&str, &count, *format);
    } else if (*format++ == '%') {
      if (*format == '\0') {
        va_end(tr);
        (*str) = '\0';
        return 0;
      }
      err = my_parsing_specifier(&str, &count, tr, &flags, &format);
      if (err) {
        my_addCharToStr(&str, &count, *format);
      }
    }
    my_memset(&flags, 0, sizeof(flag));
    flags.mod.length_mode = 0;
    if (!err) {
      format++;
    }
  }

  va_end(tr);
  *str = '\0';
  return count;
}
