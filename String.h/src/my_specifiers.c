#include "my_sprintf.h"

int my_parsing_specifier(char **str, int *count, va_list tr, flag *flags,
                          const char **format) {
  char x_or_X;
  int check_e = 0;
  int check_g = 0;
  my_parse_flag(*format, flags);
  my_flags_pam(tr, flags, format);
  switch (**format) {
    case 'c':
      my_func_for_char(str, flags, count, tr);
      break;
    case 'i':
    case 'd':
      my_func_for_int(str, flags, count, tr);
      break;
    case 'f':
      my_func_for_float(str, flags, count, tr);
      break;
    case 'u':
      my_func_for_unsigned(str, flags, count, tr);
      break;
    case 's':
      my_func_for_string(str, flags, count, tr);
      break;
    case 'o':
      my_func_for_octalstr(str, flags, count, tr);
      break;
    case 'X':
      x_or_X = 'X';
      my_func_for_hexstr(str, flags, count, tr, x_or_X);
      break;
    case 'x':
      x_or_X = 'x';
      my_func_for_hexstr(str, flags, count, tr, x_or_X);
      break;
    case 'G':
      ++check_e;
      my_func_for_g(str, flags, count, tr, &check_e, &check_g);
      break;
    case 'g':
      my_func_for_g(str, flags, count, tr, &check_e, &check_g);
      break;
    case 'E':
      ++check_e;
      my_func_for_mantissa(str, flags, count, tr, &check_e, &check_g);
      break;
    case 'e':
      my_func_for_mantissa(str, flags, count, tr, &check_e, &check_g);
      break;
    case 'p':
      my_func_for_pointer(str, flags, count, tr);
      break;
    case '%':
      my_func_for_percent(str, flags, count);
      break;
    case 'n':
      *va_arg(tr, int *) = *count;
      break;
    default:
      return 1;
  }
  return 0;
}

void my_addCharToStr(char **str, int *count, char ch) {
  *(*str)++ = ch;
  (*count)++;
}

void my_setNan(char *fl) { my_strcpy(fl, "nan"); }

void my_setInfinity(char *fl, long double long_double_num, flag flags) {
  if (long_double_num > 0) {
    if (flags.plus) {
      my_strcpy(fl, "+inf");
    } else {
      my_strcpy(fl, "inf");
    }
  } else {
    my_strcpy(fl, "-inf");
  }
}

void my_func_for_char(char **str, flag *flags, int *count, va_list tr) {
  char symbol;
  wchar_t symbol_w;

  if (flags->mod.length_mode == 2) {
    symbol_w = va_arg(tr, wchar_t);
  } else {
    symbol = va_arg(tr, int);
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    my_width(str, flags, count, 1);
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
    my_width(str, flags, count, 1);
    if (flags->width != 0) *str += flags->width - 1;
  }
}

void my_func_for_int(char **str, flag *flags, int *count, va_list tr) {
  char in[250];
  my_memset(in, 0, sizeof(in));
  if (flags->mod.length_mode == 1) {
    flags->mod.short_num = va_arg(tr, int);
    my_int_to_str(flags->mod.short_num, in, *flags);
  } else if (flags->mod.length_mode == 2) {
    flags->mod.long_num = va_arg(tr, long);
    my_int_to_str(flags->mod.long_num, in, *flags);
  } else {
    flags->mod.num = va_arg(tr, int);
    my_int_to_str(flags->mod.num, in, *flags);
  }
  if (flags->dot && flags->null) flags->null = 0;
  if (((in[0] == '+') || (in[0] == ' ') || (in[0] == '-')) &&
      (flags->null ||
       (flags->width == 0 || (flags->accuracy > flags->width)))) {
    my_addCharToStr(str, count, in[0]);
  }
  if (flags->mod.flagsCount != 0 && !flags->minus) {
    my_width_d(str, flags, count, (int)my_strlen(in), in);
  }
  if (((in[0] == '-') || (in[0] == '+') || (in[0] == ' ')) && !flags->null &&
      flags->width != 0 && flags->accuracy <= flags->width) {
    my_addCharToStr(str, count, in[0]);
  }
  for (my_size_t i = 0; i < my_strlen(in); i++) {
    if (((in[0] == '-') || (in[0] == '+') || (in[0] == ' ')) && i == 0)
      continue;
    my_addCharToStr(str, count, in[i]);
  }
  if (flags->minus) {
    flags->null = 0;
    my_width_d(str, flags, count, (int)my_strlen(in), in);
  }
}

void my_handleLongDoubleNumF(flag *flags, char *fl) {
  if (isnan(flags->mod.long_double_num)) {
    my_setNan(fl);
    flags->null = 0;
  } else if (isinf(flags->mod.long_double_num)) {
    my_setInfinity(fl, flags->mod.long_double_num, *flags);
    flags->null = 0;
  } else {
    my_float_to_str(flags->mod.long_double_num, fl, *flags);
  }
}

void my_handleDoubleNumF(flag *flags, char *fl) {
  if (isnan(flags->mod.double_num)) {
    my_setNan(fl);
    flags->null = 0;
  } else if (isinf(flags->mod.double_num)) {
    my_setInfinity(fl, flags->mod.double_num, *flags);
    flags->null = 0;
  } else {
    my_float_to_str(flags->mod.double_num, fl, *flags);
  }
}

void my_func_for_float(char **str, flag *flags, int *count, va_list tr) {
  char fl[65];
  my_memset(fl, 0, sizeof(fl));
  if (flags->minus) flags->null = 0;

  flags->accuracy = (flags->accuracy < 0) ? 6 : flags->accuracy;

  if (flags->mod.length_mode == 3) {
    flags->mod.long_double_num = va_arg(tr, long double);
    my_handleLongDoubleNumF(flags, fl);
  } else {
    flags->mod.double_num = va_arg(tr, double);
    my_handleDoubleNumF(flags, fl);
  }

  if (flags->dot && flags->accuracy == 0 && !flags->hash) {
    flags->width++;
  }

  *count = my_add_plus_minus_to_str_null(flags, fl, str, count);

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    my_width(str, flags, count, (int)my_strlen(fl));
    my_add_width(str, flags, (int)my_strlen(fl));
  }

  *count = my_add_plus_minus_to_str_nenull(flags, fl, str, count);

  for (my_size_t i = 0; i < my_strlen(fl); i++) {
    if (((fl[0] == '-') || (flags->plus == 1)) && i == 0) {
      continue;
    }
    if (fl[i] != '.') {
      my_addCharToStr(str, count, fl[i]);
    }
    if ((fl[i] == '.' && flags->dot && flags->accuracy != 0)) {
      my_addCharToStr(str, count, fl[i++]);
      while (flags->accuracy != 0) {
        my_addCharToStr(str, count, fl[i++]);
        flags->accuracy--;
      }
      break;
    } else if (fl[i] == '.' &&
               (!flags->dot || (flags->hash && !flags->accuracy))) {
      my_addCharToStr(str, count, fl[i]);
    }
  }
  if (flags->mod.flagsCount != 0 && flags->minus) {
    my_width(str, flags, count, (int)my_strlen(fl));
    my_add_width(str, flags, (int)my_strlen(fl));
  }
}

void my_func_for_unsigned(char **str, flag *flags, int *count, va_list tr) {
  char in[250];
  my_memset(in, 0, sizeof(in));
  flags->plus = 0;
  flags->space = 0;
  if (flags->dot && flags->null) flags->null = 0;

  if (flags->mod.length_mode == 1) {
    flags->mod.unsign_short_num = va_arg(tr, unsigned int);
    my_u_int_to_str(flags->mod.unsign_short_num, in, *flags);
  } else if (flags->mod.length_mode == 2) {
    flags->mod.unsign_long_num = va_arg(tr, unsigned long);
    my_u_int_to_str(flags->mod.unsign_long_num, in, *flags);
  } else {
    flags->mod.unsign_num = va_arg(tr, unsigned int);
    my_u_int_to_str(flags->mod.unsign_num, in, *flags);
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    my_width_d(str, flags, count, (int)my_strlen(in), in);
  }

  for (my_size_t i = 0; i < my_strlen(in); i++) {
    my_addCharToStr(str, count, in[i]);
  }
  if (flags->minus) {
    flags->null = 0;
    my_width_d(str, flags, count, (int)my_strlen(in), in);
  }
}

my_size_t my_wcslen(const wchar_t *str) {
  my_size_t len = 0;
  while (*str++) {
    len++;
  }
  return len;
}

void my_func_for_string(char **str, flag *flags, int *count, va_list tr) {
  char *buff;
  buff = va_arg(tr, char *);

  flags->accuracy =
      (flags->accuracy < 0) ? (flags->accuracy * -1) : flags->accuracy;

  if (!(flags->width == 0 && flags->accuracy == 0 && flags->dot &&
        !flags->star)) {
    if (flags->minus) flags->null = 0;
    if (buff == my_NULL) buff = "(null)";
    wchar_t *wide_buff = (wchar_t *)buff;

    int length_to_print_str;
    if (flags->mod.length_mode == 2)
      length_to_print_str = (int)my_wcslen(wide_buff);
    else
      length_to_print_str = (int)my_strlen(buff);
    if (flags->dot) {
      if (flags->accuracy == 0 || flags->accuracy < (int)my_strlen(buff)) {
        length_to_print_str = flags->accuracy;
      }
    }
    // ОБРАБОТКА ШИРИНЫ ДО ТЕКСТА
    if (!flags->minus && flags->mod.flagsCount != 0) {
      my_width(str, flags, count, length_to_print_str);
      my_add_width(str, flags, length_to_print_str);
    }

    // ВЫВОД ТЕКСТА
    for (int i = 0; i < length_to_print_str; i++) {
      if (flags->mod.length_mode == 2)
        my_addCharToStr(str, count, wide_buff[i]);
      else
        my_addCharToStr(str, count, buff[i]);
    }

    // ОБРАБОТКА ШИРИНЫ ПОСЛЕ ТЕКСТ, ЕСЛИ ФЛАГ МИНУС
    if (flags->minus) {
      my_width(str, flags, count, length_to_print_str);
      my_add_width(str, flags, length_to_print_str);
    }
  }
}

void my_func_for_octalstr(char **str, flag *flags, int *count, va_list tr) {
  char octalStr[50];
  my_memset(octalStr, 0, sizeof(octalStr));
  flags->plus = 0;
  flags->space = 0;
  if (flags->dot && flags->null) flags->null = 0;

  if (flags->mod.length_mode == 1) {
    flags->mod.short_num = va_arg(tr, int);
    my_decimalToOctal(flags->mod.short_num, octalStr, *flags);
  } else if (flags->mod.length_mode == 2) {
    flags->mod.long_num = va_arg(tr, long);
    my_decimalToOctal(flags->mod.long_num, octalStr, *flags);
  } else {
    flags->mod.num = va_arg(tr, int);
    my_decimalToOctal(flags->mod.num, octalStr, *flags);
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    my_width_d(str, flags, count, (int)my_strlen(octalStr), octalStr);
  }
  for (my_size_t i = 0; i < my_strlen(octalStr); i++) {
    my_addCharToStr(str, count, octalStr[i]);
  }
  if (flags->minus) {
    flags->null = 0;
    my_width_d(str, flags, count, (int)my_strlen(octalStr), octalStr);
  }
}

void my_func_for_hexstr(char **str, flag *flags, int *count, va_list tr,
                         char x_or_X) {
  char hexStr[50];
  my_memset(hexStr, 0, sizeof(hexStr));
  flags->plus = 0;
  flags->space = 0;

  if (flags->dot && flags->null) flags->null = 0;

  if (flags->mod.length_mode == 1) {
    flags->mod.short_num = va_arg(tr, unsigned int);
    my_decimalToHexdecimalSmallOrBig(flags->mod.short_num, hexStr, *flags,
                                      x_or_X);
  } else if (flags->mod.length_mode == 2) {
    flags->mod.long_num = va_arg(tr, unsigned long);
    my_decimalToHexdecimalSmallOrBig(flags->mod.long_num, hexStr, *flags,
                                      x_or_X);
  } else {
    flags->mod.num = va_arg(tr, unsigned int);
    my_decimalToHexdecimalSmallOrBig(flags->mod.num, hexStr, *flags, x_or_X);
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    my_width_d(str, flags, count, (int)my_strlen(hexStr), hexStr);
  }

  for (my_size_t i = 0; i < my_strlen(hexStr); i++) {
    my_addCharToStr(str, count, hexStr[i]);
  }

  if (flags->minus) {
    flags->null = 0;
    my_width_d(str, flags, count, (int)my_strlen(hexStr), hexStr);
  }
}

void my_func_for_pointer(char **str, flag *flags, int *count, va_list tr) {
  char fl[65];
  void *void_pointer;
  my_memset(fl, 0, sizeof(fl));
  void_pointer = va_arg(tr, void *);
  my_pointer_to_str(void_pointer, fl, *flags);

  if (flags->width != 0) {
    flags->width -= 2;
  }

  if (flags->width && flags->accuracy) {
    if (flags->mod.flagsCount != 0 && !flags->minus && flags->width &&
        !flags->null) {
      my_width(str, flags, count, flags->accuracy);
      if (flags->width - flags->accuracy > 0) {
        *str += flags->width - flags->accuracy;
      }
    }
  } else if (flags->mod.flagsCount != 0 && !flags->minus && flags->width &&
             !flags->null) {
    my_width(str, flags, count, (int)my_strlen(fl));
    my_add_width(str, flags, (int)my_strlen(fl));
  }
  my_addCharToStr(str, count, '0');
  my_addCharToStr(str, count, 'x');

  if ((flags->accuracy > (int)my_strlen(fl)) || (void_pointer == 0)) {
    flags->width = flags->accuracy;
  }
  if (flags->accuracy) {
    flags->null = 1;
  }

  if (flags->mod.flagsCount != 0 && !flags->minus &&
      (flags->width && flags->accuracy)) {
    my_width(str, flags, count, (int)my_strlen(fl));
    my_add_width(str, flags, (int)my_strlen(fl));
  }

  for (my_size_t i = 0; fl[i]; i++) {
    my_addCharToStr(str, count, fl[i]);
  }

  if (flags->mod.flagsCount != 0 && flags->minus) {
    my_width(str, flags, count, (int)my_strlen(fl));
    my_add_width(str, flags, (int)my_strlen(fl));
  }
}

void my_case_logic_mantisa(flag *flags, char *buffor_g_e, char **str,
                            int *count) {
  *count = my_add_plus_minus_to_str_null(flags, buffor_g_e, str, count);

  if ((flags->space) && (!flags->plus) && (buffor_g_e[0] != '-') &&
      (buffor_g_e[0] != 'n')) {
    my_addCharToStr(str, count, ' ');
    --(flags->width);
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    my_width(str, flags, count, (int)my_strlen(buffor_g_e));
    my_add_width(str, flags, (int)my_strlen(buffor_g_e));
  }

  *count = my_add_plus_minus_to_str_nenull(flags, buffor_g_e, str, count);

  for (my_size_t i = 0; buffor_g_e[i]; i++) {
    if ((buffor_g_e[i] == '-') && i == 0) {
      continue;
    }

    if ((flags->plus == 1) && i == 0) continue;

    my_addCharToStr(str, count, buffor_g_e[i]);
  }

  if (flags->mod.flagsCount != 0 && flags->minus) {
    my_width(str, flags, count, (int)my_strlen(buffor_g_e));
    my_add_width(str, flags, (int)my_strlen(buffor_g_e));
  }
}

void my_func_for_mantissa(char **str, flag *flags, int *count, va_list tr,
                           int *check_e, int *check_g) {
  char fl[65];
  char buffor_g_e[200];
  my_memset(fl, 0, sizeof(fl));
  flags->accuracy = (flags->accuracy < 0) ? 6 : flags->accuracy;
  if (flags->mod.length_mode == 3) {
    flags->mod.long_double_num = va_arg(tr, long double);
    if (isnan(flags->mod.long_double_num)) {
      my_setNan(buffor_g_e);
      my_setNan(fl);
      flags->null = 0;
    } else if (isinf(flags->mod.long_double_num)) {
      my_setInfinity(buffor_g_e, flags->mod.long_double_num, *flags);
      my_setInfinity(fl, flags->mod.long_double_num, *flags);
      flags->null = 0;
    } else
      my_e_float_to_str(flags->mod.long_double_num, fl, *flags, *check_e,
                         *check_g);
  } else {
    flags->mod.double_num = va_arg(tr, double);
    if (isnan(flags->mod.double_num)) {
      my_setNan(buffor_g_e);
      my_setNan(fl);
      flags->null = 0;
    } else if (isinf(flags->mod.double_num)) {
      my_setInfinity(buffor_g_e, flags->mod.double_num, *flags);
      my_setInfinity(fl, flags->mod.double_num, *flags);
      flags->null = 0;
    } else
      my_e_float_to_str(flags->mod.double_num, fl, *flags, *check_e, *check_g);
  }
  flags->mod.length_mode = 0;
  if (flags->minus) {
    flags->null = 0;
  }
  my_case_logic_mantisa(flags, fl, str, count);
}

void my_handleDoubleNumG(flag *flags, char *buffor_g_e, char *fl, int *check_e,
                          int *check_g, int *eflag2, int *g) {
  if (isnan(flags->mod.double_num)) {
    my_setNan(buffor_g_e);
    my_setNan(fl);
    flags->null = 0;
  } else if (isinf(flags->mod.double_num)) {
    my_setInfinity(buffor_g_e, flags->mod.double_num, *flags);
    my_setInfinity(fl, flags->mod.double_num, *flags);
    flags->null = 0;
  } else {
    my_e_float_to_str(flags->mod.double_num, buffor_g_e, *flags, *check_e,
                       *check_g);
    my_ftoa_forG(flags->mod.double_num, fl, flags);
    if (flags->mod.double_num < 0) {
      flags->mod.double_num *= -1;
    }
    if ((flags->mod.double_num < 1)) {
      *g = flags->accuracy - flags->mod.precision;
    }
    if (((flags->mod.double_num < 0.0001 && flags->mod.double_num > 0) ||
         flags->mod.double_num >= pow(10, flags->mod.precision)) &&
        my_strlen(buffor_g_e) > my_strlen(fl) - *g) {
      *eflag2 = 1;
    }
  }
}

void my_handleLongDoubleNumG(flag *flags, char *buffor_g_e, char *fl,
                              int *check_e, int *check_g, int *eflag2, int *g) {
  if (isnan(flags->mod.long_double_num)) {
    my_setNan(buffor_g_e);
    my_setNan(fl);
    flags->null = 0;
  } else if (isinf(flags->mod.long_double_num)) {
    my_setInfinity(buffor_g_e, flags->mod.long_double_num, *flags);
    my_setInfinity(fl, flags->mod.long_double_num, *flags);
    flags->null = 0;
  } else {
    my_e_float_to_str(flags->mod.long_double_num, buffor_g_e, *flags, *check_e,
                       *check_g);
    my_ftoa_forG(flags->mod.long_double_num, fl, flags);
    if (flags->mod.long_double_num < 0) {
      flags->mod.long_double_num *= -1;
    }
    if ((flags->mod.long_double_num < 1)) {
      *g = flags->accuracy - flags->mod.precision;
    }
    if (((flags->mod.long_double_num < 0.0001 &&
          flags->mod.long_double_num > 0) ||
         roundl(flags->mod.long_double_num) >= pow(10, flags->mod.precision)) &&
        my_strlen(buffor_g_e) > my_strlen(fl) - *g) {
      *eflag2 = 1;
    }
  }
}

void my_case_logic_g(flag *flags, char *fl, char **str, int *count) {
  if (flags->dot && flags->mod.precision == 0 && !flags->hash) {
    flags->width++;
  }
  *count = my_add_plus_minus_to_str_null(flags, fl, str, count);

  if ((flags->space == 1) && (flags->plus == 0) && (fl[0] != '-') &&
      (fl[0] != 'n'))  //
  {
    my_addCharToStr(str, count, ' ');
    --flags->width;
  }

  if (flags->mod.flagsCount != 0 && !flags->minus) {
    my_width(str, flags, count, (int)my_strlen(fl));
    my_add_width(str, flags, (int)my_strlen(fl));
  }

  *count = my_add_plus_minus_to_str_nenull(flags, fl, str, count);

  for (my_size_t i = 0; i < my_strlen(fl); i++) {
    if (((fl[0] == '-') || (flags->plus == 1)) && i == 0 && (fl[i] != 'n')) {
      continue;
    }

    if (fl[i] != '.') {
      my_addCharToStr(str, count, fl[i]);
    }

    if ((fl[i] == '.' && flags->dot && flags->accuracy != 0) ||
        (fl[i] == '.' && flags->hash)) {
      my_addCharToStr(str, count, fl[i++]);
      while (flags->accuracy != 0 && fl[i] != '\0') {
        my_addCharToStr(str, count, fl[i++]);
        flags->accuracy--;
      }
      break;
    } else if (fl[i] == '.' && !flags->dot) {
      my_addCharToStr(str, count, fl[i]);
    }
  }

  if (flags->mod.flagsCount != 0 && flags->minus) {
    my_width(str, flags, count, (int)my_strlen(fl));
    my_add_width(str, flags, (int)my_strlen(fl));
  }
}

void my_func_for_g(char **str, flag *flags, int *count, va_list tr,
                    int *check_e, int *check_g) {
  char fl[65];
  char buffor_g_e[200];
  my_memset(fl, 0, sizeof(fl));
  my_memset(buffor_g_e, 0, sizeof(buffor_g_e));
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
    my_handleLongDoubleNumG(flags, buffor_g_e, fl, check_e, check_g, &eflag2,
                             &g);
  } else {
    flags->mod.double_num = va_arg(tr, double);
    my_handleDoubleNumG(flags, buffor_g_e, fl, check_e, check_g, &eflag2, &g);
  }

  if ((my_strlen(buffor_g_e) <= my_strlen(fl) - g &&
       !((my_strlen(buffor_g_e) <= my_strlen(fl) - g) &&
         (flags->mod.precision >= (int)my_strlen(fl) - g))) ||
      ((eflag2))) {
    my_case_logic_mantisa(flags, buffor_g_e, str, count);
  } else {
    my_case_logic_g(flags, fl, str, count);
  }
}

void my_func_for_percent(char **str, flag *flags, int *count) {
  if (flags->mod.flagsCount != 0 && !flags->minus) {
    my_width(str, flags, count, 1);
    *str += flags->width - 1;
  }
  *(*str)++ = '%';
  if (flags->minus) {
    flags->null = 0;
    my_width(str, flags, count, 1);
    *str += flags->width - 1;
  }
  (*count)++;
}