#include "s21_sprintf.h"

void s21_parse_flag(const char *format, flag *flags) {
  int length = (int)(s21_strlen(format));
  for (int i = 0;
       i < length && (s21_strchr("cdieEfgGosuxXpn%%", *format) == s21_NULL);
       i++, format++) {
    switch (*format) {
      case '-':
        flags->minus = 1;
        break;
      case '+':
        flags->plus = 1;
        break;
      case ' ':
        flags->space = 1;
        break;
      case '.':
        flags->dot = 1;
        break;
      case '#':
        flags->hash = 1;
        break;
      case '0':
        if (flags->width == 0) flags->null = 1;
        break;
      case '*':
        if (!flags->dot)
          flags->star = 1;
        else
          flags->dot_star = 1;
        break;
      case 'h':
        flags->mod.length_mode = 1;
        break;
      case 'l':
        flags->mod.length_mode = 2;
        break;
      case 'L':
        flags->mod.length_mode = 3;
        break;
      default:
        flags->mod.length_mode = 0;
        break;
    }
    if (flags->dot && s21_isdigit(*format))
      flags->accuracy = flags->accuracy * 10 + (*format - '0');
    if (s21_isdigit(*format) && !flags->dot)
      flags->width = flags->width * 10 + (*format - '0');
    flags->mod.flagsCount++;
  }
}

void s21_add_width(char *str[], flag *flags, int num) {
  if (flags->width - num > 0) (*str) += flags->width - num;
}

void s21_width(char **str, flag *flags, int *count, int charCount) {
  while (flags->width > charCount) {
    if (!flags->null)
      s21_addCharToStr(str, count, ' ');
    else
      s21_addCharToStr(str, count, '0');
    flags->width--;
  }
}

void s21_width_d(char **str, flag *flags, int *count, int charCount, char *in) {
  if (flags->dot && ((flags->accuracy) > (flags->width))) {
    flags->width = flags->accuracy;
    if (in[0] == '-') flags->width++;
    flags->null = 1;
  }
  s21_width(str, flags, count, charCount);
  s21_add_width(str, flags, (int)s21_strlen(in));
}

int s21_add_plus_space_minus(int sign, char s[], flag flags, int i) {
  if (sign == 1) s[i++] = '-';
  if (flags.plus == 1 && sign == 0)
    s[i++] = '+';
  else if (flags.space == 1 && sign == 0)
    s[i++] = ' ';
  return i;
}

int s21_add_plus_minus(int sign, char s[], flag flags, int i) {
  if (sign == 1) s[i++] = '-';
  if (flags.plus == 1 && sign == 0) s[i++] = '+';
  return i;
}

int s21_add_plus_minus_to_str_nenull(flag *flags, char *fl, char **str,
                                     int *count) {
  if ((!flags->null && ((flags->plus && fl[0] == '+') || fl[0] == '-'))) {
    s21_addCharToStr(str, count, fl[0]);
  }
  return *count;
}

int s21_add_plus_minus_to_str_null(flag *flags, char *fl, char **str,
                                   int *count) {
  if ((flags->null && ((flags->plus && fl[0] == '+') || fl[0] == '-'))) {
    s21_addCharToStr(str, count, fl[0]);
  }
  return *count;
}

void s21_flags_pam(va_list tr, flag *flags, const char **format) {
  *format += flags->mod.flagsCount;
  if (flags->star) {
    flags->width = va_arg(tr, int);
    if (flags->width < 0) {
      flags->width *= -1;
      flags->minus = 1;
    }
  }
  if (flags->dot_star) flags->accuracy = va_arg(tr, int);
}