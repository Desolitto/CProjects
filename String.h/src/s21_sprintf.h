#ifndef S21_SPRINTF_H_
#define S21_SPRINTF_H_

#include "s21_string.h"

#define s21_isdigit(c) ((c >= '0' && c <= '9') ? 1 : 0)

typedef struct modes {
  int flagsCount;
  int length_mode;
  int precision;
  int num;
  short int short_num;
  long int long_num;
  double double_num;
  long double long_double_num;
  unsigned int unsign_num;
  unsigned short int unsign_short_num;
  unsigned long int unsign_long_num;
} modes;

typedef struct flag {
  int minus;
  int plus;
  int space;
  int hash;
  int null;
  int dot;
  int star;
  int dot_star;
  int width;
  int accuracy;
  struct modes mod;
} flag;

void s21_parse_flag(const char *format, flag *flags);
void s21_add_width(char *str[], flag *flags, int num);
void s21_width(char **str, flag *flags, int *count, int charCount);
void s21_width_d(char **str, flag *flags, int *count, int charCount, char *in);
void s21_addCharToStr(char **str, int *count, char ch);
void s21_setNan(char *fl);
void s21_setInfinity(char *fl, long double long_double_num, flag flags);
void s21_what_the_sign(long double *n, int *sign);
void s21_reverse(char s[]);
int s21_add_plus_space_minus(int sign, char s[], flag flags, int i);
int s21_add_plus_minus(int sign, char s[], flag flags, int i);
int s21_add_plus_minus_to_str_nenull(flag *flags, char *fl, char **str,
                                     int *count);
int s21_add_plus_minus_to_str_null(flag *flags, char *fl, char **str,
                                   int *count);
void s21_int_to_str(long int n, char s[], flag flags);
void s21_u_int_to_str(unsigned long int n, char s[], flag flags);
int s21_f_to_str(long double num, char s[], int num_digits, int i);
void s21_float_to_str(long double n, char s[], flag flags);
void s21_ftoa_forG_digits_roundn(long double *n, flag *flags);
void s21_ftoa_forG_add_all_parts(char s[], flag *flags, long double n, int *i);
void s21_ftoa_forG(long double n, char s[], flag *flags);
void s21_decimalToOctal(unsigned long int decimalNum, char octalStr[],
                        flag flags);
void s21_additional_function_decimal(unsigned long int *decimalNum, flag *flags,
                                     char hexStr[], int *i, char mode);
void s21_decimalToHexdecimalSmallOrBig(unsigned long int decimalNum,
                                       char hexStr[], flag flags, char mode);

void s21_pointer_to_str(void *num, char s[], flag flags);
void s21_func_for_char(char **str, flag *flags, int *count, va_list tr);
void s21_e_float_to_str(long double n, char s[], flag flags, int check_e,
                        int check_g);

void s21_handleLongDoubleNumF(flag *flags, char *fl);
void s21_handleDoubleNumF(flag *flags, char *fl);
void s21_handleDoubleNum(flag *flags, char *buffor_g_e, char *fl, int *check_e,
                         int *check_g, int *eflag2, int *g);
void s21_handleLongDoubleNum(flag *flags, char *buffor_g_e, char *fl,
                             int *check_e, int *check_g, int *eflag2, int *g);

void s21_func_for_int(char **str, flag *flags, int *count, va_list tr);
void s21_func_for_float(char **str, flag *flags, int *count, va_list tr);
void s21_func_for_unsigned(char **str, flag *flags, int *count, va_list tr);
void s21_func_for_string(char **str, flag *flags, int *count, va_list tr);
void s21_func_for_octalstr(char **str, flag *flags, int *count, va_list tr);
void s21_func_for_hexstr(char **str, flag *flags, int *count, va_list tr,
                         char x_or_X);
void s21_func_for_pointer(char **str, flag *flags, int *count, va_list tr);
void s21_case_logic_mantisa(flag *flags, char *buffor_g_e, char **str,
                            int *count);
void s21_func_for_mantissa(char **str, flag *flags, int *count, va_list tr,
                           int *check_e, int *check_g);

void s21_case_logic_g(flag *flags, char *fl, char **str, int *count);
void s21_func_for_g(char **str, flag *flags, int *count, va_list tr,
                    int *check_e, int *check_g);

void s21_func_for_percent(char **str, flag *flags, int *count);
void s21_flags_pam(va_list tr, flag *flags, const char **format);
int s21_parsing_specifier(char **str, int *count, va_list tr, flag *flags,
                          const char **format);

int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);

#endif
