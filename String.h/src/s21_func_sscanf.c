#include "s21_sscanf.h"

void s21_parse_flag_sscanf(const char *format, flagss *flags) {
  int length = (int)(s21_strlen(format));
  int i = 0;
  for (i = 0;
       i < length && (s21_strchr("cdieEfgGosuxXpn%%", *format) == s21_NULL);
       i++) {
    switch (*format) {
      case '*':
        flags->readAndSkip = 1;
        break;
      case '-':
      case '+':
        flags->signedWidth = 1;
        break;
      case 'h':
        flags->length_mode = 1;
        break;
      case 'l':
        flags->length_mode = 2;
        break;
      case 'L':
        flags->length_mode = 3;
        break;
      default:
        flags->length_mode = 0;
        break;
    }
    if (s21_isdigit(*format)) {
      flags->width_exist = 1;
    }
    if (s21_isdigit(*format)) {
      flags->width = flags->width * 10 + (*format - '0');
    }
    if (flags->width == 0) {
      flags->width_exist = 0;
    }
    format++;
    flags->count++;
  }
}

int s21_isInfNan(const char *s, int *i, double *n) {
  int res = 0;
  if ((s[*i] == '-' && s[*i + 1] == 'I' && s[*i + 2] == 'N' &&
       s[*i + 3] == 'F') ||
      (s[*i] == '-' && s[*i + 1] == 'i' && s[*i + 2] == 'n' &&
       s[*i + 3] == 'f')) {
    *n = -INFINITY;
    (*i) += 4;
    res = 1;
  } else if ((s[*i] == '+' && s[*i + 1] == 'I' && s[*i + 2] == 'N' &&
              s[*i + 3] == 'F') ||
             (s[*i] == '+' && s[*i + 1] == 'i' && s[*i + 2] == 'n' &&
              s[*i + 3] == 'f')) {
    *n = INFINITY;
    (*i) += 4;
    res = 1;
  } else if ((s[*i]) == 'N' && s[*i + 1] == 'A' && s[*i + 2] == 'N') {
    *n = NAN;
    (*i) += 3;
    res = 1;
  } else if (s[*i] == 'n' && s[*i + 1] == 'a' && s[*i + 2] == 'n') {
    *n = NAN;
    (*i) += 3;
    res = 1;
  }
  return res;
}

long long int s21_str_to_num(const char *s, int *n_num, flagss flags,
                             int *isWrongWidth, int base) {
  int i, sign;
  long long int n = 0;

  for (i = 0; s21_isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    i++;
    if (flags.width == 1 || flags.signedWidth) *isWrongWidth = 1;
    if (flags.width > 1) {
      flags.width--;
    }
  }

  if (flags.width > 0 && !*isWrongWidth) {
    for (n = 0; s21_isdigit(s[i]) && (flags.width > 0); i++, flags.width--) {
      n = base * n + (s[i] - '0');
    }
  } else {
    for (n = 0; s21_isdigit(s[i]); i++) {
      n = base * n + (s[i] - '0');
    }
  }

  *n_num = i;
  return sign * n;
}

void s21_xX_to_num(char s, unsigned long long int *n, int base) {
  if ((s == 'a') || (s == 'A')) {
    *n = base * (*n) + 10;
  } else if ((s == 'b') || (s == 'B')) {
    *n = base * (*n) + 11;
  } else if ((s == 'c') || (s == 'C')) {
    *n = base * (*n) + 12;
  } else if ((s == 'd') || (s == 'D')) {
    *n = base * (*n) + 13;
  } else if ((s == 'e') || (s == 'E')) {
    *n = base * (*n) + 14;
  } else if ((s == 'f') || (s == 'F')) {
    *n = base * (*n) + 15;
  } else {
    *n = base * (*n) + (s - '0');
  }
}

double s21_f_str_to_num(const char *s, int *n_num, int *isDigitExist,
                        flagss flags, int *isWrongWidth) {
  double n = 0.0;
  int i = 0, sign = 1;
  for (i = 0; s21_isspace(s[i]); i++)
    ;
  if (s21_isInfNan(s, &i, &n))
    ;
  else {
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
      i++;
      if (flags.width == 1 || flags.signedWidth) *isWrongWidth = 1;
      if (flags.width > 1) flags.width--;
    }
    double decimal = 10.0;
    if (flags.width > 0 && !*isWrongWidth) {
      while ((s21_isdigit(s[i]) || s[i] == '.') && (flags.width > 0)) {
        *isDigitExist = 1;
        if (s[i] == '.') {
          i++;
          break;
        }
        n = n * 10.0 + (s[i++] - '0');
        flags.width--;
      }
      while (s21_isdigit(s[i]) && (flags.width > 0)) {
        n = n + (s[i++] - '0') / decimal;
        decimal *= 10;
        flags.width--;
      }
    } else {
      while (s21_isdigit(s[i]) || s[i] == '.') {
        *isDigitExist = 1;
        if (s[i] == '.') {
          i++;
          break;
        }
        n = n * 10.0 + (s[i++] - '0');
      }
      while (s21_isdigit(s[i])) {
        n = n + (s[i++] - '0') / decimal;
        decimal *= 10;
      }
    }
  }
  *n_num = i;
  return sign * n;
}

unsigned long long int s21_xXp_str_to_num(const char *s, int *n_num,
                                          flagss flags, int *isWrongWidth,
                                          int base) {
  int i, sign;
  unsigned long long int n = 0;
  int flag = 0;
  for (i = 0; s21_isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    i++;
    if (flags.width == 1 || flags.signedWidth) *isWrongWidth = 1;
    if (flags.width > 1) flags.width--;
  }
  if ((s[i] == '0' && s[i + 1] == 'X') || (s[i] == '0' && s[i + 1] == 'x')) {
    i += 2;
    if (flags.width <= 2 && flags.width_exist) {
      flag = 1;
      n = 0;
    }
    if (flags.width > 2 && flags.width_exist) flags.width -= 2;
  }
  if (flag != 1) {
    if (flags.width > 0 && !*isWrongWidth) {
      for (n = 0; s[i] != '\0' &&
                  (s21_isdigit(s[i]) ||
                   (s21_strchr("abcdefABCDEF", s[i]) != s21_NULL)) &&
                  (flags.width > 0);
           i++, flags.width--) {
        s21_xX_to_num(s[i], &n, base);
      }
    } else {
      int count = 0;
      for (n = 0;
           s[i] != '\0' && (s21_isdigit(s[i]) ||
                            (s21_strchr("abcdefABCDEF", s[i]) != s21_NULL));
           i++) {
        s21_xX_to_num(s[i], &n, base);
        count++;
        if (count > 16) n = 18446744073709551615ULL;
      }
    }
  }
  *n_num = i;
  return sign * n;
}

int s21_handleSpacesInSpecifiers(const char **format, int *lengthStr) {
  int isSpaceinfromat = 0;
  while (*lengthStr > 0 && s21_isspace(**format)) {
    isSpaceinfromat = 1;
    (*format)++;
    (*lengthStr)--;
  }
  return isSpaceinfromat;
}

int s21_handleCSpec(const char **str, va_list *tr, flagss *flags,
                    int isSpaceinfromat, int *read_from_str) {
  int count = 0;
  if (isSpaceinfromat == 1) {
    while (s21_isspace(**str)) {
      (*str)++;
      (*read_from_str)++;
    }
  }

  if (!flags->readAndSkip) {
    s21_strncpy(va_arg(*tr, char *), *str, 1);
    count++;
    (*read_from_str)++;
  }

  (*str)++;

  return count;
}

int s21_handleSSpec(va_list *tr, const char **str, flagss *flags,
                    int *read_from_str) {
  int count = 0;
  while (s21_isspace(**str)) {
    (*str)++;
    (*read_from_str)++;
  }

  if (flags->readAndSkip) {
    if (flags->width_exist) {
      while ((**str) && (**str) != ' ' && (**str) != '\t' && (**str) != '\n' &&
             flags->width != 0) {
        (*str)++;
        flags->width--;
        (*read_from_str)++;
      }
    } else {
      while ((**str) && (**str) != ' ' && (**str) != '\t' && (**str) != '\n') {
        (*str)++;
        (*read_from_str)++;
      }
    }
  } else {
    char *buff = va_arg(*tr, char *);
    if (flags->width_exist) {
      while ((**str) && (**str) != ' ' && (**str) != '\t' && (**str) != '\n' &&
             flags->width != 0) {
        *buff++ = (**str);
        (*str)++;
        flags->width--;
        (*read_from_str)++;
      }
    } else {
      while ((**str) && (**str) != ' ' && (**str) != '\t' && (**str) != '\n') {
        *buff++ = (**str);
        (*str)++;
        (*read_from_str)++;
      }
    }
    *buff = '\0';
    count = 1;
  }
  return count;
}

int s21_handleDSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str) {
  int isWrongWidth = 0;
  int shift = 0;
  int num = 0;
  long int long_num = 0;
  short int short_num = 0;
  int count = 0;

  if (flags.length_mode == 1) {
    short_num = s21_str_to_num(*str, &shift, flags, &isWrongWidth, 10);
  } else if (flags.length_mode == 2) {
    long_num = s21_str_to_num(*str, &shift, flags, &isWrongWidth, 10);
  } else {
    num = s21_str_to_num(*str, &shift, flags, &isWrongWidth, 10);
  }

  if (flags.width && flags.width < shift) {
    (*str) += flags.width + 1;
    (*read_from_str) += flags.width + 1;
  } else {
    (*str) += shift;
    (*read_from_str) += shift;
  }

  if (!flags.readAndSkip) {
    if (isWrongWidth) {
      if (flags.length_mode == 1) {
        *va_arg(*tr, short *) = 0;
      } else if (flags.length_mode == 2) {
        *va_arg(*tr, long *) = 0;
      } else {
        *va_arg(*tr, int *) = 0;
      }
    } else {
      if (flags.length_mode == 1) {
        *va_arg(*tr, short *) = (short)short_num;
      } else if (flags.length_mode == 2) {
        *va_arg(*tr, long *) = (long)long_num;
      } else {
        *va_arg(*tr, int *) = (int)num;
      }
      count = 1;
    }
  }
  *resWidth = isWrongWidth;
  return count;
}

int s21_handleUOSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                     int *read_from_str, int base) {
  int isWrongWidth = 0;
  int shift = 0;
  unsigned int num = 0;
  unsigned long int long_num = 0;
  unsigned short int short_num = 0;
  int count = 0;

  if (flags.length_mode == 1) {
    short_num = s21_str_to_num(*str, &shift, flags, &isWrongWidth, base);
  } else if (flags.length_mode == 2) {
    long_num = s21_str_to_num(*str, &shift, flags, &isWrongWidth, base);
  } else {
    num = s21_str_to_num(*str, &shift, flags, &isWrongWidth, base);
  }

  if (flags.width && flags.width < shift) {
    (*str) += flags.width + 1;
    (*read_from_str) += flags.width + 1;
  } else {
    (*str) += shift;
    (*read_from_str) += shift;
  }

  if (!flags.readAndSkip) {
    if (isWrongWidth) {
      if (flags.length_mode == 1) {
        *va_arg(*tr, unsigned short *) = 0;
      } else if (flags.length_mode == 2) {
        *va_arg(*tr, unsigned long *) = 0;
      } else {
        *va_arg(*tr, unsigned int *) = 0;
      }
    } else {
      if (flags.length_mode == 1) {
        *va_arg(*tr, unsigned short *) = (unsigned short)short_num;
      } else if (flags.length_mode == 2) {
        *va_arg(*tr, unsigned long *) = (unsigned long)long_num;
      } else {
        *va_arg(*tr, unsigned int *) = (unsigned int)num;
      }
      count++;
    }
  }
  *resWidth = isWrongWidth;

  return count;
}

int s21_handleXSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str) {
  int isWrongWidth = 0;
  int shift = 0;
  int num = 0;
  long int long_num = 0;
  short int short_num = 0;
  int count = 0;

  if (flags.length_mode == 1) {
    short_num = s21_xXp_str_to_num(*str, &shift, flags, &isWrongWidth, 16);
  } else if (flags.length_mode == 2) {
    long_num = s21_xXp_str_to_num(*str, &shift, flags, &isWrongWidth, 16);
  } else {
    num = s21_xXp_str_to_num(*str, &shift, flags, &isWrongWidth, 16);
  }

  if (flags.width && flags.width < shift) {
    (*str) += flags.width + 1;
    (*read_from_str) += flags.width + 1;
  } else {
    (*str) += shift;
    (*read_from_str) += shift;
  }

  if (!flags.readAndSkip) {
    if (isWrongWidth) {
      if (flags.length_mode == 1) {
        *va_arg(*tr, short *) = 0;
      } else if (flags.length_mode == 2) {
        *va_arg(*tr, long *) = 0;
      } else {
        *va_arg(*tr, int *) = 0;
      }
    } else {
      if (flags.length_mode == 1) {
        *va_arg(*tr, short *) = (short)short_num;
      } else if (flags.length_mode == 2) {
        *va_arg(*tr, long *) = (long)long_num;
      } else {
        *va_arg(*tr, int *) = (int)num;
      }
      count++;
    }
  }
  *resWidth = isWrongWidth;

  return count;
}

int s21_handlePSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str) {
  int isWrongWidth = 0;
  int shift = 0;
  unsigned long long num_p;
  int count = 0;

  num_p = s21_xXp_str_to_num(*str, &shift, flags, &isWrongWidth, 16);

  if (flags.width && flags.width < shift) {
    (*str) += flags.width + 1;
    (*read_from_str) += flags.width + 1;
  } else {
    (*str) += shift;
    (*read_from_str) += shift;
  }

  if (!flags.readAndSkip) {
    if (isWrongWidth)
      *va_arg(*tr, unsigned long long *) = 0;

    else {
      *va_arg(*tr, unsigned long long *) = (unsigned long long)num_p;
      count++;
    }
  }
  *resWidth = isWrongWidth;

  return count;
}

int s21_handleFSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str) {
  int isWrongWidth = 0;
  int shift = 0;
  int isDigitExist = 0;
  double double_num = 0.0;
  long double long_double_num = 0.0;
  int count = 0;

  if (flags.length_mode == 3) {
    long_double_num =
        s21_f_str_to_num(*str, &shift, &isDigitExist, flags, &isWrongWidth);
  } else
    double_num =
        s21_f_str_to_num(*str, &shift, &isDigitExist, flags, &isWrongWidth);

  if (flags.width && flags.width < shift) {
    (*str) += flags.width + 1;
    (*read_from_str) += flags.width + 1;
  } else {
    (*str) += shift;
    (*read_from_str) += shift;
  }

  if (isinf(double_num) && double_num < 0) {
    *va_arg(*tr, float *) = -INFINITY;
    count++;
  } else if (isinf(double_num) && double_num > 0) {
    count++;
  } else if (isnan(double_num)) {
    *va_arg(*tr, float *) = NAN;
    count++;
  } else if ((!flags.readAndSkip || !isDigitExist) && isWrongWidth) {
    if (flags.length_mode == 3)
      *va_arg(*tr, long double *) = 0;
    else {
      *va_arg(*tr, float *) = 0;
    }
  } else if ((!flags.readAndSkip && isDigitExist)) {
    if (flags.length_mode == 3)
      *va_arg(*tr, long double *) = (long double)long_double_num;
    else {
      *va_arg(*tr, float *) = (float)double_num;
    }
    count++;
  }
  *resWidth = isWrongWidth;

  return count;
}

void s21_handleNSpec(int isSpec, const char **str, va_list *tr,
                     int *read_from_str) {
  while (s21_isspace(**str)) {
    (*str)++;
    (*read_from_str)++;
  }
  if (isSpec) {
    *va_arg(*tr, int *) = (*read_from_str);
  } else {
    *va_arg(*tr, int *) = 0;
  }
}

void s21_parse_spec(const char **str, const char **format, va_list *tr,
                    int isSpaceinfromat, int *read_from_str, int *resWidth,
                    int *count, flagss flags) {
  int isSpec = (s21_strchr("cs%%iduoxXpfn", **format) != s21_NULL);
  switch (*(*format)++) {
    case 'c':
      *count +=
          s21_handleCSpec(str, tr, &flags, isSpaceinfromat, read_from_str);
      break;
    case 's':
      *count += s21_handleSSpec(tr, str, &flags, read_from_str);
      break;
    case '%':
      (*str)++;
      break;
    case 'i':
    case 'd':
      *count += s21_handleDSpec(resWidth, str, tr, flags, read_from_str);
      break;
    case 'u':
      *count += s21_handleUOSpec(resWidth, str, tr, flags, read_from_str, 10);
      break;
    case 'o':
      *count += s21_handleUOSpec(resWidth, str, tr, flags, read_from_str, 8);
      break;
    case 'x':
    case 'X':
      *count += s21_handleXSpec(resWidth, str, tr, flags, read_from_str);
      break;
    case 'p':
      *count += s21_handlePSpec(resWidth, str, tr, flags, read_from_str);
      break;
    case 'f':
      *count += s21_handleFSpec(resWidth, str, tr, flags, read_from_str);
      break;
    case 'n':
      s21_handleNSpec(isSpec, str, tr, read_from_str);
      break;
    default:
      break;
  }
}

int s21_handleSscanf(const char *str, const char *format, va_list *tr,
                     int lengthStr, int lengthFormat) {
  int count = 0, read_from_str = 0;
  int isSpaceinfromat = 0, resWidth = 0, isWrongWidth = 0;
  flagss flags = {0};

  while (*format != 0) {
    if (s21_isspace(*format))
      isSpaceinfromat = s21_handleSpacesInSpecifiers(&format, &lengthStr);
    if (isWrongWidth) break;

    if (*format != '%') str++;

    if (*format++ == '%') {
      if (lengthStr <= 0) {
        count = -1;
        break;
      }
      if (*format == '\0' && lengthFormat == 1) {
        count = -1;
        break;
      }

      s21_parse_flag_sscanf(format, &flags);
      if (flags.count != 0) format += flags.count;

      if (flags.signedWidth) {
        isWrongWidth = 1;
        continue;
      }

      s21_parse_spec(&str, &format, tr, isSpaceinfromat, &read_from_str,
                     &resWidth, &count, flags);

      isWrongWidth = resWidth;
    }
    s21_memset(&flags, 0, sizeof(flagss));
    flags.length_mode = 0;
  }
  return count;
}