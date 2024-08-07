#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  int count = 0;
  va_list tr;
  va_start(tr, format);
  flag flags = {0};
  int err = 0;

  while (*format != '\0') {
    if (*format != '%') {
      s21_addCharToStr(&str, &count, *format);
    } else if (*format++ == '%') {
      if (*format == '\0') {
        va_end(tr);
        (*str) = '\0';
        return 0;
      }
      err = s21_parsing_specifier(&str, &count, tr, &flags, &format);
      if (err) {
        s21_addCharToStr(&str, &count, *format);
      }
    }
    s21_memset(&flags, 0, sizeof(flag));
    flags.mod.length_mode = 0;
    if (!err) {
      format++;
    }
  }

  va_end(tr);
  *str = '\0';
  return count;
}
