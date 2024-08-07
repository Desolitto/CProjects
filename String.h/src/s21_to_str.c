#include "s21_sprintf.h"

void s21_reverse(char s[]) {
  for (int i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    int c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void s21_what_the_sign(long double *n, int *sign) {
  if (*n < 0) {
    *sign = 1;
    *n = -*n;
  }
}

void s21_int_to_str(long int n, char s[], flag flags) {
  int i = 0, sign = 0;

  if (n < 0) {
    sign = 1;
    n = -n;
  }

  if (n == -9223372036854775807 - 1) {
    s[i++] = '8';
    n = 922337203685477580;
  }
  do {
    if (n == 0 && flags.dot && flags.accuracy < 1 && flags.width != 0 &&
        !flags.hash) {
      s[i++] = ' ';
    } else if ((flags.width != 0 && n == 0) ||
               (flags.width == 0 && n == 0 && !flags.dot) || (n != 0))
      s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  int rast = flags.accuracy - (int)s21_strlen(s);
  while (rast > 0) {
    s[i++] = '0';
    rast--;
  }

  i = s21_add_plus_space_minus(sign, s, flags, i);

  s21_reverse(s);
  s[i] = '\0';
}

void s21_u_int_to_str(unsigned long int n, char s[], flag flags) {
  int i = 0;

  do {
    if (n == 0 && flags.dot && flags.accuracy < 1 && flags.width != 0) {
      s[i++] = ' ';
    } else if ((flags.width != 0 && n == 0) ||
               (flags.width == 0 && n == 0 && !flags.dot) || (n != 0))
      s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  int rast = flags.accuracy - (int)s21_strlen(s);
  while (rast > 0) {
    s[i++] = '0';
    rast--;
  }

  s[i] = '\0';
  s21_reverse(s);
}

int s21_f_to_str(long double num, char s[], int num_digits, int i) {
  long double divider = 10.;
  while (num_digits > 0) {
    int digit = (int)(fmodl(num, divider) / (divider / 10.));
    s[i++] = digit + '0';
    divider *= 10.;
    num_digits--;
  }
  return i;
}

void s21_float_to_str(long double n, char s[], flag flags) {
  int i = 0, sign = 0, num_digits = 0, decimal_places = 0;
  long double whole_part = 0, digit_part = 0;
  s21_what_the_sign(&n, &sign);
  if (!flags.dot) flags.accuracy = 6;

  n = roundl(n * powl(10, flags.accuracy)) / powl(10, flags.accuracy);
  digit_part = modfl(n, &whole_part);
  digit_part = roundl(digit_part * powl(10, flags.accuracy));

  if (whole_part == 0) {
    num_digits = 1;
  } else
    num_digits = log10l(whole_part) + 1;

  decimal_places = flags.accuracy;

  i = s21_f_to_str(digit_part, s, decimal_places, i);

  s[i++] = '.';

  i = s21_f_to_str(whole_part, s, num_digits, i);

  i = s21_add_plus_space_minus(sign, s, flags, i);

  s21_reverse(s);

  s[i] = '\0';
}

void s21_ftoa_forG_digits_roundn(long double *n, flag *flags) {
  int num_digits = 0;
  int num_digits_0 = 0;
  int num_digits2 = 0;
  if (*n == 0) {
    *n = 0;
    ++num_digits;
    if (!flags->hash) flags->accuracy--;
  } else if (*n >= 1) {
    long double d = *n;
    while (d >= 1) {
      d /= (long double)10;
      ++num_digits;
    }
  } else {
    long double num = *n;
    while (num < 1) {
      num *= (long double)10;
      ++num_digits_0;
    }
    num_digits_0--;
  }
  if (*n > 1) {
    long double d = roundl(*n);
    while (d >= 1) {
      d /= (long double)10;
      ++num_digits2;
    }
  }
  if (*n >= 0 && *n < 10 && flags->dot && flags->accuracy < 2)
    flags->accuracy = 1;
  if (flags->accuracy == num_digits) {
    flags->accuracy = 0;
  }
  if (flags->dot && !flags->accuracy) {
    *n = roundl(*n);
  } else if (flags->dot) {
    flags->accuracy += num_digits_0 - num_digits;
    if (num_digits2 > num_digits) {
      *n = roundl(*n * powl(10, flags->accuracy)) / powl(10, flags->accuracy);
    }
  } else {
    flags->accuracy = 6 - num_digits;
  }
  if (!flags->dot && !flags->accuracy) {
    *n = roundl(*n * powl(10, flags->accuracy)) / powl(10, flags->accuracy);
  }
}

void s21_ftoa_forG_add_all_parts(char s[], flag *flags, long double n, int *i) {
  unsigned long long int whole_part = (unsigned long long int)n;
  long double decimal_part = n - whole_part;
  decimal_part = roundl(decimal_part * powl(10, flags->accuracy));
  unsigned long int digit_part = (unsigned long)decimal_part;
  int decimal_places = flags->accuracy;
  int null_check = 1;
  while (decimal_places > 0) {
    if ((digit_part % 10 == 0) && (null_check == 1) && (!flags->hash)) {
      digit_part /= 10;
      --decimal_places;
    } else {
      null_check = 0;
      int digit = digit_part % 10;
      s[(*i)++] = digit + '0';
      digit_part -= digit;
      digit_part /= 10;
      decimal_places--;
    }
  }
  if (((digit_part > 0 || (flags->dot && !flags->mod.precision) ||
        (!null_check)) &&
       flags->accuracy > 0) ||
      flags->hash) {
    s[(*i)++] = '.';
  }
  if (whole_part == 0) {
    s[(*i)++] = '0';
  }
  while (whole_part > 0) {
    s[(*i)++] = whole_part % 10 + '0';
    whole_part /= 10;
  }
}

void s21_ftoa_forG(long double n, char s[], flag *flags) {
  int i = 0;
  int sign = 0;
  s21_what_the_sign(&n, &sign);
  s21_ftoa_forG_digits_roundn(&n, flags);
  s21_ftoa_forG_add_all_parts(s, flags, n, &i);
  i = s21_add_plus_minus(sign, s, *flags, i);
  s21_reverse(s);
  s[i] = '\0';
}

void s21_decimalToOctal(unsigned long int decimalNum, char octalStr[],
                        flag flags) {
  int origin_number = decimalNum;
  int i = 0;
  if (flags.mod.length_mode == 0) {
    decimalNum = (unsigned int)decimalNum;
  } else if (flags.mod.length_mode == 1) {
    decimalNum = (unsigned short int)decimalNum;
  }
  // Дополнительные условия для обработки decimalNum = 0;
  do {
    if (decimalNum == 0 && flags.dot && flags.accuracy < 1 &&
        flags.width != 0 && !flags.hash) {
      octalStr[i++] = ' ';
    } else if ((flags.width != 0 && decimalNum == 0) ||
               (flags.width == 0 && decimalNum == 0 && !flags.dot) ||
               (decimalNum != 0))
      octalStr[i++] = decimalNum % 8 + '0';
  } while ((decimalNum /= 8) > 0);

  if (flags.hash && origin_number != 0) octalStr[i++] = '0';

  int rast = flags.accuracy - (int)s21_strlen(octalStr);
  while (rast > 0) {
    octalStr[i++] = '0';
    rast--;
  }
  octalStr[i] = '\0';
  int len = i;
  for (int j = 0; j < len / 2; j++) {
    char temp = octalStr[j];
    octalStr[j] = octalStr[len - j - 1];
    octalStr[len - j - 1] = temp;
  }
}

void s21_additional_function_decimal(unsigned long int *decimalNum, flag *flags,
                                     char hexStr[], int *i, char mode) {
  do {
    if (*decimalNum == 0 && flags->dot && flags->accuracy < 1 &&
        flags->width != 0) {
      hexStr[*i] = ' ';
      *i += 1;
    } else if ((flags->width != 0 && *decimalNum == 0) ||
               (flags->width == 0 && *decimalNum == 0 && !flags->dot) ||
               (*decimalNum != 0)) {
      int newNum = *decimalNum % 16;
      if (newNum < 10) {
        hexStr[*i] = newNum + '0';
        *i += 1;
      } else {
        if (mode == 'x') {
          hexStr[*i] = newNum - 10 + 'a';
          *i += 1;
        } else {
          hexStr[*i] = newNum - 10 + 'A';
          *i += 1;
        }
      }
    }
  } while ((*decimalNum /= 16) > 0);
}

void s21_decimalToHexdecimalSmallOrBig(unsigned long int decimalNum,
                                       char hexStr[], flag flags, char mode) {
  int i = 0;
  int origin_number = decimalNum;  // for hash and value = 0;
  if (flags.mod.length_mode == 0) {
    decimalNum = (unsigned int)decimalNum;
  } else if (flags.mod.length_mode == 1) {
    decimalNum = (unsigned short int)decimalNum;
  }
  // Дополнительные условия для обработки decimalNum = 0;
  s21_additional_function_decimal(&decimalNum, &flags, hexStr, &i, mode);
  int rast = flags.accuracy - (int)s21_strlen(hexStr);
  while (rast > 0) {
    hexStr[i++] = '0';
    rast--;
  }
  if (flags.hash && origin_number != 0) {
    if (mode == 'x')
      hexStr[i++] = 'x';
    else
      hexStr[i++] = 'X';
    hexStr[i++] = '0';
  }
  hexStr[i] = '\0';
  int len = i;
  for (int j = 0; j < len / 2; j++) {
    char temp = hexStr[j];
    hexStr[j] = hexStr[len - j - 1];
    hexStr[len - j - 1] = temp;
  }
}

void s21_pointer_to_str(void *num, char s[], flag flags) {
  int i = 0;
  long long int addres = (long long int)num;

  if ((num == 0) && !(!flags.accuracy && flags.dot)) {
    s[i++] = '0';
  } else {
    while (addres > 0) {
      int digit = addres % 16;

      if (digit < 10) {
        s[i++] = digit + '0';
      } else {
        s[i++] = digit - 10 + 'a';
      }
      addres -= digit;
      addres /= 16;
    }

    s21_reverse(s);
  }

  s[i] = '\0';
}

void s21_amount_of_acc_to_print_e(int *decimal_places, flag flags,
                                  int check_g) {
  if (flags.dot) {
    if (check_g) {
      if (flags.accuracy) {
        *decimal_places = flags.accuracy;
      } else
        *decimal_places = flags.accuracy + 1;
    } else
      *decimal_places = flags.accuracy + 1;
  } else {
    if (check_g) {
      *decimal_places = 6;
    } else
      *decimal_places = 6 + 1;
  }
}

void s21_count_digits(long double *n, flag flags, int check_g,
                      int *num_of_digits, int *mantissa_sign) {
  if (*n == 0) {
    *num_of_digits = 0;
  } else if (*n > 1) {
    while (*n > 1) {
      *n /= (long double)10;
      ++*num_of_digits;
    }

    if (!check_g || (!flags.accuracy && flags.dot)) *n *= (long double)10;

    *num_of_digits -= 1;
  } else {
    while (*n < 1) {
      *n *= (long double)10;
      ++*num_of_digits;
    }
    *mantissa_sign = 1;
    if (check_g && !(!flags.accuracy && flags.dot)) *n /= (long double)10;
  }
}

int s21_mantissa_to_str_e(char s[], int check_e, int num_of_digits,
                          int mantissa_sign, int i) {
  if (num_of_digits < 10) {
    s[i++] = num_of_digits + '0';
    s[i++] = '0';
  } else {
    while (num_of_digits > 0) {
      int digit = num_of_digits % 10;
      s[i++] = digit + '0';
      num_of_digits -= digit;
      num_of_digits /= 10;
    }
  }

  if (mantissa_sign == 0) {
    s[i++] = '+';
  } else
    s[i++] = '-';

  if (check_e == 1) {
    s[i++] = 'E';
  } else if (check_e == 0)
    s[i++] = 'e';

  return i;
}

int s21_digits_to_str_e(unsigned long int digit_part, flag flags,
                        int decimal_places, int check_g, char s[], int i,
                        long double n) {
  int null_check = 1;
  while (decimal_places > 0) {
    if ((decimal_places == 1) &&
        (!(flags.dot && (flags.accuracy == 0)) || (flags.hash == 1)) &&
        ((!(check_g &&
            ((flags.accuracy == 1) || (n == powl(10, flags.accuracy - 1))))) ||
         (flags.hash == 1)))
      s[i++] = '.';

    if ((check_g == 1) && (digit_part % 10 == 0) && (null_check == 1) &&
        (flags.hash == 0)) {
      digit_part /= 10;
      --decimal_places;
    } else {
      null_check = 0;
      int digit = digit_part % 10;
      s[i++] = digit + '0';
      digit_part -= digit;
      digit_part /= 10;
      decimal_places--;
    }
  }
  return i;
}

void s21_e_float_to_str(long double n, char s[], flag flags, int check_e,
                        int check_g) {
  int i = 0, sign = 0, decimal_places = 0, num_of_digits = 0, mantissa_sign = 0;
  unsigned long int digit_part = 0;

  s21_what_the_sign(&n, &sign);
  s21_count_digits(&n, flags, check_g, &num_of_digits, &mantissa_sign);
  if (!flags.dot) flags.accuracy = 6;

  n = roundl(n * powl(10, flags.accuracy));
  if ((flags.accuracy && (n >= powl(10, flags.accuracy)) &&
       (n >= powl(10, flags.accuracy + 1))) ||
      (check_g && flags.accuracy && (n >= powl(10, flags.accuracy)))) {
    n /= (long double)10;
    ++num_of_digits;
  }
  if ((n > 9) && !flags.accuracy) {
    n /= (long double)10;
    ++num_of_digits;
  }

  digit_part = (unsigned long)n;
  s21_amount_of_acc_to_print_e(&decimal_places, flags, check_g);
  i = s21_mantissa_to_str_e(s, check_e, num_of_digits, mantissa_sign, i);
  i = s21_digits_to_str_e(digit_part, flags, decimal_places, check_g, s, i, n);

  i = s21_add_plus_minus(sign, s, flags, i);
  s21_reverse(s);
  s[i] = '\0';
}