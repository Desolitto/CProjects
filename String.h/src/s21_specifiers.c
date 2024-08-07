#include "s21_sprintf.h"

int s21_parsing_specifier(char **str, int *count, va_list tr, flag *flags,
                          const char **format) {
  char x_or_X;
  int check_e = 0;
  int check_g = 0;
  s21_parse_flag(*format, flags);
  s21_flags_pam(tr, flags, format);
  switch (**format) {
    case 'c':
      s21_func_for_char(str, flags, count, tr);
      break;
    case 'i':
    case 'd':
      s21_func_for_int(str, flags, count, tr);
      break;
    case 'f':
      s21_func_for_float(str, flags, count, tr);
      break;
    case 'u':
      s21_func_for_unsigned(str, flags, count, tr);
      break;
    case 's':
      s21_func_for_string(str, flags, count, tr);
      break;
    case 'o':
      s21_func_for_octalstr(str, flags, count, tr);
      break;
    case 'X':
      x_or_X = 'X';
      s21_func_for_hexstr(str, flags, count, tr, x_or_X);
      break;
    case 'x':
      x_or_X = 'x';
      s21_func_for_hexstr(str, flags, count, tr, x_or_X);
      break;
    case 'G':
      ++check_e;
      s21_func_for_g(str, flags, count, tr, &check_e, &check_g);
      break;
    case 'g':
      s21_func_for_g(str, flags, count, tr, &check_e, &check_g);
      break;
    case 'E':
      ++check_e;
      s21_func_for_mantissa(str, flags, count, tr, &check_e, &check_g);
      break;
    case 'e':
      s21_func_for_mantissa(str, flags, count, tr, &check_e, &check_g);
      break;
    case 'p':
      s21_func_for_pointer(str, flags, count, tr);
      break;
    case '%':
      s21_func_for_percent(str, flags, count);
      break;
    case 'n':
      *va_arg(tr, int *) = *count;
      break;
    default:
      return 1;
  }
  return 0;
}

void s21_addCharToStr(char **str, int *count, char ch) {
  *(*str)++ = ch;
  (*count)++;
}

void s21_setNan(char *fl) { s21_strcpy(fl, "nan"); }

void s21_setInfinity(char *fl, long double long_double_num, flag flags) {
  if (long_double_num > 0) {
    if (flags.plus) {
      s21_strcpy(fl, "+inf");
    } else {
      s21_strcpy(fl, "inf");
    }
  } else {
    s21_strcpy(fl, "-inf");
  }
}

void s21_func_for_char(char **str, flag *flags, int *count, va_list tr) {
  char symbol;
  wchar_t symbol_w;

  if (flags->mod.length_mode == 2) {
    symbol_w = va_arg(tr, wchar_t);
  } else {
    symbol = va_arg(tr, int);
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    s21_width(str, flags, count, 1);
    if (flags->width != 0) *str += flags->width - 1;
  }

  (*count)++;

  if (flags->mod.length_mode == 2) {
    *(*str)++ = symbol_w;
  } else {
    *(*str)++ = symbol;
  }

  if (flags->minus) {
    flags->null = 0;
    s21_width(str, flags, count, 1);
    if (flags->width != 0) *str += flags->width - 1;
  }
}

void s21_func_for_int(char **str, flag *flags, int *count, va_list tr) {
  char in[250];
  s21_memset(in, 0, sizeof(in));
  if (flags->mod.length_mode == 1) {
    flags->mod.short_num = va_arg(tr, int);
    s21_int_to_str(flags->mod.short_num, in, *flags);
  } else if (flags->mod.length_mode == 2) {
    flags->mod.long_num = va_arg(tr, long);
    s21_int_to_str(flags->mod.long_num, in, *flags);
  } else {
    flags->mod.num = va_arg(tr, int);
    s21_int_to_str(flags->mod.num, in, *flags);
  }
  if (flags->dot && flags->null) flags->null = 0;
  if (((in[0] == '+') || (in[0] == ' ') || (in[0] == '-')) &&
      (flags->null ||
       (flags->width == 0 || (flags->accuracy > flags->width)))) {
    s21_addCharToStr(str, count, in[0]);
  }
  if (flags->mod.flagsCount != 0 && !flags->minus) {
    s21_width_d(str, flags, count, (int)s21_strlen(in), in);
  }
  if (((in[0] == '-') || (in[0] == '+') || (in[0] == ' ')) && !flags->null &&
      flags->width != 0 && flags->accuracy <= flags->width) {
    s21_addCharToStr(str, count, in[0]);
  }
  for (s21_size_t i = 0; i < s21_strlen(in); i++) {
    if (((in[0] == '-') || (in[0] == '+') || (in[0] == ' ')) && i == 0)
      continue;
    s21_addCharToStr(str, count, in[i]);
  }
  if (flags->minus) {
    flags->null = 0;
    s21_width_d(str, flags, count, (int)s21_strlen(in), in);
  }
}

void s21_handleLongDoubleNumF(flag *flags, char *fl) {
  if (isnan(flags->mod.long_double_num)) {
    s21_setNan(fl);
    flags->null = 0;
  } else if (isinf(flags->mod.long_double_num)) {
    s21_setInfinity(fl, flags->mod.long_double_num, *flags);
    flags->null = 0;
  } else {
    s21_float_to_str(flags->mod.long_double_num, fl, *flags);
  }
}

void s21_handleDoubleNumF(flag *flags, char *fl) {
  if (isnan(flags->mod.double_num)) {
    s21_setNan(fl);
    flags->null = 0;
  } else if (isinf(flags->mod.double_num)) {
    s21_setInfinity(fl, flags->mod.double_num, *flags);
    flags->null = 0;
  } else {
    s21_float_to_str(flags->mod.double_num, fl, *flags);
  }
}

void s21_func_for_float(char **str, flag *flags, int *count, va_list tr) {
  char fl[65];
  s21_memset(fl, 0, sizeof(fl));
  if (flags->minus) flags->null = 0;

  flags->accuracy = (flags->accuracy < 0) ? 6 : flags->accuracy;

  if (flags->mod.length_mode == 3) {
    flags->mod.long_double_num = va_arg(tr, long double);
    s21_handleLongDoubleNumF(flags, fl);
  } else {
    flags->mod.double_num = va_arg(tr, double);
    s21_handleDoubleNumF(flags, fl);
  }

  if (flags->dot && flags->accuracy == 0 && !flags->hash) {
    flags->width++;
  }

  *count = s21_add_plus_minus_to_str_null(flags, fl, str, count);

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    s21_width(str, flags, count, (int)s21_strlen(fl));
    s21_add_width(str, flags, (int)s21_strlen(fl));
  }

  *count = s21_add_plus_minus_to_str_nenull(flags, fl, str, count);

  for (s21_size_t i = 0; i < s21_strlen(fl); i++) {
    if (((fl[0] == '-') || (flags->plus == 1)) && i == 0) {
      continue;
    }
    if (fl[i] != '.') {
      s21_addCharToStr(str, count, fl[i]);
    }
    if ((fl[i] == '.' && flags->dot && flags->accuracy != 0)) {
      s21_addCharToStr(str, count, fl[i++]);
      while (flags->accuracy != 0) {
        s21_addCharToStr(str, count, fl[i++]);
        flags->accuracy--;
      }
      break;
    } else if (fl[i] == '.' &&
               (!flags->dot || (flags->hash && !flags->accuracy))) {
      s21_addCharToStr(str, count, fl[i]);
    }
  }
  if (flags->mod.flagsCount != 0 && flags->minus) {
    s21_width(str, flags, count, (int)s21_strlen(fl));
    s21_add_width(str, flags, (int)s21_strlen(fl));
  }
}

void s21_func_for_unsigned(char **str, flag *flags, int *count, va_list tr) {
  char in[250];
  s21_memset(in, 0, sizeof(in));
  flags->plus = 0;
  flags->space = 0;
  if (flags->dot && flags->null) flags->null = 0;

  if (flags->mod.length_mode == 1) {
    flags->mod.unsign_short_num = va_arg(tr, unsigned int);
    s21_u_int_to_str(flags->mod.unsign_short_num, in, *flags);
  } else if (flags->mod.length_mode == 2) {
    flags->mod.unsign_long_num = va_arg(tr, unsigned long);
    s21_u_int_to_str(flags->mod.unsign_long_num, in, *flags);
  } else {
    flags->mod.unsign_num = va_arg(tr, unsigned int);
    s21_u_int_to_str(flags->mod.unsign_num, in, *flags);
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    s21_width_d(str, flags, count, (int)s21_strlen(in), in);
  }

  for (s21_size_t i = 0; i < s21_strlen(in); i++) {
    s21_addCharToStr(str, count, in[i]);
  }
  if (flags->minus) {
    flags->null = 0;
    s21_width_d(str, flags, count, (int)s21_strlen(in), in);
  }
}

s21_size_t s21_wcslen(const wchar_t *str) {
  s21_size_t len = 0;
  while (*str++) {
    len++;
  }
  return len;
}

void s21_func_for_string(char **str, flag *flags, int *count, va_list tr) {
  char *buff;
  buff = va_arg(tr, char *);

  flags->accuracy =
      (flags->accuracy < 0) ? (flags->accuracy * -1) : flags->accuracy;

  if (!(flags->width == 0 && flags->accuracy == 0 && flags->dot &&
        !flags->star)) {
    if (flags->minus) flags->null = 0;
    if (buff == s21_NULL) buff = "(null)";
    wchar_t *wide_buff = (wchar_t *)buff;

    int length_to_print_str;
    if (flags->mod.length_mode == 2)
      length_to_print_str = (int)s21_wcslen(wide_buff);
    else
      length_to_print_str = (int)s21_strlen(buff);
    if (flags->dot) {
      if (flags->accuracy == 0 || flags->accuracy < (int)s21_strlen(buff)) {
        length_to_print_str = flags->accuracy;
      }
    }
    // ОБРАБОТКА ШИРИНЫ ДО ТЕКСТА
    if (!flags->minus && flags->mod.flagsCount != 0) {
      s21_width(str, flags, count, length_to_print_str);
      s21_add_width(str, flags, length_to_print_str);
    }

    // ВЫВОД ТЕКСТА
    for (int i = 0; i < length_to_print_str; i++) {
      if (flags->mod.length_mode == 2)
        s21_addCharToStr(str, count, wide_buff[i]);
      else
        s21_addCharToStr(str, count, buff[i]);
    }

    // ОБРАБОТКА ШИРИНЫ ПОСЛЕ ТЕКСТ, ЕСЛИ ФЛАГ МИНУС
    if (flags->minus) {
      s21_width(str, flags, count, length_to_print_str);
      s21_add_width(str, flags, length_to_print_str);
    }
  }
}

void s21_func_for_octalstr(char **str, flag *flags, int *count, va_list tr) {
  char octalStr[50];
  s21_memset(octalStr, 0, sizeof(octalStr));
  flags->plus = 0;
  flags->space = 0;
  if (flags->dot && flags->null) flags->null = 0;

  if (flags->mod.length_mode == 1) {
    flags->mod.short_num = va_arg(tr, int);
    s21_decimalToOctal(flags->mod.short_num, octalStr, *flags);
  } else if (flags->mod.length_mode == 2) {
    flags->mod.long_num = va_arg(tr, long);
    s21_decimalToOctal(flags->mod.long_num, octalStr, *flags);
  } else {
    flags->mod.num = va_arg(tr, int);
    s21_decimalToOctal(flags->mod.num, octalStr, *flags);
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    s21_width_d(str, flags, count, (int)s21_strlen(octalStr), octalStr);
  }
  for (s21_size_t i = 0; i < s21_strlen(octalStr); i++) {
    s21_addCharToStr(str, count, octalStr[i]);
  }
  if (flags->minus) {
    flags->null = 0;
    s21_width_d(str, flags, count, (int)s21_strlen(octalStr), octalStr);
  }
}

void s21_func_for_hexstr(char **str, flag *flags, int *count, va_list tr,
                         char x_or_X) {
  char hexStr[50];
  s21_memset(hexStr, 0, sizeof(hexStr));
  flags->plus = 0;
  flags->space = 0;

  if (flags->dot && flags->null) flags->null = 0;

  if (flags->mod.length_mode == 1) {
    flags->mod.short_num = va_arg(tr, unsigned int);
    s21_decimalToHexdecimalSmallOrBig(flags->mod.short_num, hexStr, *flags,
                                      x_or_X);
  } else if (flags->mod.length_mode == 2) {
    flags->mod.long_num = va_arg(tr, unsigned long);
    s21_decimalToHexdecimalSmallOrBig(flags->mod.long_num, hexStr, *flags,
                                      x_or_X);
  } else {
    flags->mod.num = va_arg(tr, unsigned int);
    s21_decimalToHexdecimalSmallOrBig(flags->mod.num, hexStr, *flags, x_or_X);
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    s21_width_d(str, flags, count, (int)s21_strlen(hexStr), hexStr);
  }

  for (s21_size_t i = 0; i < s21_strlen(hexStr); i++) {
    s21_addCharToStr(str, count, hexStr[i]);
  }

  if (flags->minus) {
    flags->null = 0;
    s21_width_d(str, flags, count, (int)s21_strlen(hexStr), hexStr);
  }
}

void s21_func_for_pointer(char **str, flag *flags, int *count, va_list tr) {
  char fl[65];
  void *void_pointer;
  s21_memset(fl, 0, sizeof(fl));
  void_pointer = va_arg(tr, void *);
  s21_pointer_to_str(void_pointer, fl, *flags);

  if (flags->width != 0) {
    flags->width -= 2;
  }

  if (flags->width && flags->accuracy) {
    if (flags->mod.flagsCount != 0 && !flags->minus && flags->width &&
        !flags->null) {
      s21_width(str, flags, count, flags->accuracy);
      if (flags->width - flags->accuracy > 0) {
        *str += flags->width - flags->accuracy;
      }
    }
  } else if (flags->mod.flagsCount != 0 && !flags->minus && flags->width &&
             !flags->null) {
    s21_width(str, flags, count, (int)s21_strlen(fl));
    s21_add_width(str, flags, (int)s21_strlen(fl));
  }
  s21_addCharToStr(str, count, '0');
  s21_addCharToStr(str, count, 'x');

  if ((flags->accuracy > (int)s21_strlen(fl)) || (void_pointer == 0)) {
    flags->width = flags->accuracy;
  }
  if (flags->accuracy) {
    flags->null = 1;
  }

  if (flags->mod.flagsCount != 0 && !flags->minus &&
      (flags->width && flags->accuracy)) {
    s21_width(str, flags, count, (int)s21_strlen(fl));
    s21_add_width(str, flags, (int)s21_strlen(fl));
  }

  for (s21_size_t i = 0; fl[i]; i++) {
    s21_addCharToStr(str, count, fl[i]);
  }

  if (flags->mod.flagsCount != 0 && flags->minus) {
    s21_width(str, flags, count, (int)s21_strlen(fl));
    s21_add_width(str, flags, (int)s21_strlen(fl));
  }
}

void s21_case_logic_mantisa(flag *flags, char *buffor_g_e, char **str,
                            int *count) {
  *count = s21_add_plus_minus_to_str_null(flags, buffor_g_e, str, count);

  if ((flags->space) && (!flags->plus) && (buffor_g_e[0] != '-') &&
      (buffor_g_e[0] != 'n')) {
    s21_addCharToStr(str, count, ' ');
    --(flags->width);
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    s21_width(str, flags, count, (int)s21_strlen(buffor_g_e));
    s21_add_width(str, flags, (int)s21_strlen(buffor_g_e));
  }

  *count = s21_add_plus_minus_to_str_nenull(flags, buffor_g_e, str, count);

  for (s21_size_t i = 0; buffor_g_e[i]; i++) {
    if ((buffor_g_e[i] == '-') && i == 0) {
      continue;
    }

    if ((flags->plus == 1) && i == 0) continue;

    s21_addCharToStr(str, count, buffor_g_e[i]);
  }

  if (flags->mod.flagsCount != 0 && flags->minus) {
    s21_width(str, flags, count, (int)s21_strlen(buffor_g_e));
    s21_add_width(str, flags, (int)s21_strlen(buffor_g_e));
  }
}

void s21_func_for_mantissa(char **str, flag *flags, int *count, va_list tr,
                           int *check_e, int *check_g) {
  char fl[65];
  char buffor_g_e[200];
  s21_memset(fl, 0, sizeof(fl));
  flags->accuracy = (flags->accuracy < 0) ? 6 : flags->accuracy;
  if (flags->mod.length_mode == 3) {
    flags->mod.long_double_num = va_arg(tr, long double);
    if (isnan(flags->mod.long_double_num)) {
      s21_setNan(buffor_g_e);
      s21_setNan(fl);
      flags->null = 0;
    } else if (isinf(flags->mod.long_double_num)) {
      s21_setInfinity(buffor_g_e, flags->mod.long_double_num, *flags);
      s21_setInfinity(fl, flags->mod.long_double_num, *flags);
      flags->null = 0;
    } else
      s21_e_float_to_str(flags->mod.long_double_num, fl, *flags, *check_e,
                         *check_g);
  } else {
    flags->mod.double_num = va_arg(tr, double);
    if (isnan(flags->mod.double_num)) {
      s21_setNan(buffor_g_e);
      s21_setNan(fl);
      flags->null = 0;
    } else if (isinf(flags->mod.double_num)) {
      s21_setInfinity(buffor_g_e, flags->mod.double_num, *flags);
      s21_setInfinity(fl, flags->mod.double_num, *flags);
      flags->null = 0;
    } else
      s21_e_float_to_str(flags->mod.double_num, fl, *flags, *check_e, *check_g);
  }
  flags->mod.length_mode = 0;
  if (flags->minus) {
    flags->null = 0;
  }
  s21_case_logic_mantisa(flags, fl, str, count);
}

void s21_handleDoubleNumG(flag *flags, char *buffor_g_e, char *fl, int *check_e,
                          int *check_g, int *eflag2, int *g) {
  if (isnan(flags->mod.double_num)) {
    s21_setNan(buffor_g_e);
    s21_setNan(fl);
    flags->null = 0;
  } else if (isinf(flags->mod.double_num)) {
    s21_setInfinity(buffor_g_e, flags->mod.double_num, *flags);
    s21_setInfinity(fl, flags->mod.double_num, *flags);
    flags->null = 0;
  } else {
    s21_e_float_to_str(flags->mod.double_num, buffor_g_e, *flags, *check_e,
                       *check_g);
    s21_ftoa_forG(flags->mod.double_num, fl, flags);
    if (flags->mod.double_num < 0) {
      flags->mod.double_num *= -1;
    }
    if ((flags->mod.double_num < 1)) {
      *g = flags->accuracy - flags->mod.precision;
    }
    if (((flags->mod.double_num < 0.0001 && flags->mod.double_num > 0) ||
         flags->mod.double_num >= pow(10, flags->mod.precision)) &&
        s21_strlen(buffor_g_e) > s21_strlen(fl) - *g) {
      *eflag2 = 1;
    }
  }
}

void s21_handleLongDoubleNumG(flag *flags, char *buffor_g_e, char *fl,
                              int *check_e, int *check_g, int *eflag2, int *g) {
  if (isnan(flags->mod.long_double_num)) {
    s21_setNan(buffor_g_e);
    s21_setNan(fl);
    flags->null = 0;
  } else if (isinf(flags->mod.long_double_num)) {
    s21_setInfinity(buffor_g_e, flags->mod.long_double_num, *flags);
    s21_setInfinity(fl, flags->mod.long_double_num, *flags);
    flags->null = 0;
  } else {
    s21_e_float_to_str(flags->mod.long_double_num, buffor_g_e, *flags, *check_e,
                       *check_g);
    s21_ftoa_forG(flags->mod.long_double_num, fl, flags);
    if (flags->mod.long_double_num < 0) {
      flags->mod.long_double_num *= -1;
    }
    if ((flags->mod.long_double_num < 1)) {
      *g = flags->accuracy - flags->mod.precision;
    }
    if (((flags->mod.long_double_num < 0.0001 &&
          flags->mod.long_double_num > 0) ||
         roundl(flags->mod.long_double_num) >= pow(10, flags->mod.precision)) &&
        s21_strlen(buffor_g_e) > s21_strlen(fl) - *g) {
      *eflag2 = 1;
    }
  }
}

void s21_case_logic_g(flag *flags, char *fl, char **str, int *count) {
  if (flags->dot && flags->mod.precision == 0 && !flags->hash) {
    flags->width++;
  }
  *count = s21_add_plus_minus_to_str_null(flags, fl, str, count);

  if ((flags->space == 1) && (flags->plus == 0) && (fl[0] != '-') &&
      (fl[0] != 'n'))  //
  {
    s21_addCharToStr(str, count, ' ');
    --flags->width;
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    s21_width(str, flags, count, (int)s21_strlen(fl));
    s21_add_width(str, flags, (int)s21_strlen(fl));
  }

  *count = s21_add_plus_minus_to_str_nenull(flags, fl, str, count);

  for (s21_size_t i = 0; i < s21_strlen(fl); i++) {
    if (((fl[0] == '-') || (flags->plus == 1)) && i == 0 && (fl[i] != 'n')) {
      continue;
    }

    if (fl[i] != '.') {
      s21_addCharToStr(str, count, fl[i]);
    }

    if ((fl[i] == '.' && flags->dot && flags->accuracy != 0) ||
        (fl[i] == '.' && flags->hash)) {
      s21_addCharToStr(str, count, fl[i++]);
      while (flags->accuracy != 0 && fl[i] != '\0') {
        s21_addCharToStr(str, count, fl[i++]);
        flags->accuracy--;
      }
      break;
    } else if (fl[i] == '.' && !flags->dot) {
      s21_addCharToStr(str, count, fl[i]);
    }
  }

  if (flags->mod.flagsCount != 0 && flags->minus) {
    s21_width(str, flags, count, (int)s21_strlen(fl));
    s21_add_width(str, flags, (int)s21_strlen(fl));
  }
}

void s21_func_for_g(char **str, flag *flags, int *count, va_list tr,
                    int *check_e, int *check_g) {
  char fl[65];
  char buffor_g_e[200];
  s21_memset(fl, 0, sizeof(fl));
  s21_memset(buffor_g_e, 0, sizeof(buffor_g_e));
  int eflag2 = 0;
  int g = 0;
  *check_g = 1;

  if (flags->minus) flags->null = 0;
  flags->accuracy = (flags->accuracy < 0) ? 6 : flags->accuracy;
  flags->mod.precision = flags->accuracy;
  if (flags->mod.precision == 0) {
    flags->mod.precision = 6;
  }
  if (flags->dot && !flags->accuracy) {
    flags->mod.precision = 1;
  }

  if (flags->mod.length_mode == 3) {
    flags->mod.long_double_num = va_arg(tr, long double);
    s21_handleLongDoubleNumG(flags, buffor_g_e, fl, check_e, check_g, &eflag2,
                             &g);
  } else {
    flags->mod.double_num = va_arg(tr, double);
    s21_handleDoubleNumG(flags, buffor_g_e, fl, check_e, check_g, &eflag2, &g);
  }

  if ((s21_strlen(buffor_g_e) <= s21_strlen(fl) - g &&
       !((s21_strlen(buffor_g_e) <= s21_strlen(fl) - g) &&
         (flags->mod.precision >= (int)s21_strlen(fl) - g))) ||
      ((eflag2))) {
    s21_case_logic_mantisa(flags, buffor_g_e, str, count);
  } else {
    s21_case_logic_g(flags, fl, str, count);
  }
}

void s21_func_for_percent(char **str, flag *flags, int *count) {
  if (flags->mod.flagsCount != 0 && !flags->minus) {
    s21_width(str, flags, count, 1);
    *str += flags->width - 1;
  }
  *(*str)++ = '%';
  if (flags->minus) {
    flags->null = 0;
    s21_width(str, flags, count, 1);
    *str += flags->width - 1;
  }
  (*count)++;
}