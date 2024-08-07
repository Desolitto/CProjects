#ifndef my_SPRINTF_H_
#define my_SPRINTF_H_

#include "my_string.h"

#define my_isdigit(c) ((c >= '0' && c <= '9') ? 1 : 0)

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

void my_parse_flag(const char *format, flag *flags);
void my_add_width(char *str[], flag *flags, int num);
void my_width(char **str, flag *flags, int *count, int charCount);
void my_width_d(char **str, flag *flags, int *count, int charCount, char *in);
void my_addCharToStr(char **str, int *count, char ch);
void my_setNan(char *fl);
void my_setInfinity(char *fl, long double long_double_num, flag flags);
void my_what_the_sign(long double *n, int *sign);
void my_reverse(char s[]);
int my_add_plus_space_minus(int sign, char s[], flag flags, int i);
int my_add_plus_minus(int sign, char s[], flag flags, int i);
int my_add_plus_minus_to_str_nenull(flag *flags, char *fl, char **str,
                                     int *count);
int my_add_plus_minus_to_str_null(flag *flags, char *fl, char **str,
                                   int *count);
void my_int_to_str(long int n, char s[], flag flags);
void my_u_int_to_str(unsigned long int n, char s[], flag flags);
int my_f_to_str(long double num, char s[], int num_digits, int i);
void my_float_to_str(long double n, char s[], flag flags);
void my_ftoa_forG_digits_roundn(long double *n, flag *flags);
void my_ftoa_forG_add_all_parts(char s[], flag *flags, long double n, int *i);
void my_ftoa_forG(long double n, char s[], flag *flags);
void my_decimalToOctal(unsigned long int decimalNum, char octalStr[],
                        flag flags);
void my_additional_function_decimal(unsigned long int *decimalNum, flag *flags,
                                     char hexStr[], int *i, char mode);
void my_decimalToHexdecimalSmallOrBig(unsigned long int decimalNum,
                                       char hexStr[], flag flags, char mode);

void my_pointer_to_str(void *num, char s[], flag flags);
void my_func_for_char(char **str, flag *flags, int *count, va_list tr);
void my_e_float_to_str(long double n, char s[], flag flags, int check_e,
                        int check_g);

void my_handleLongDoubleNumF(flag *flags, char *fl);
void my_handleDoubleNumF(flag *flags, char *fl);
void my_handleDoubleNum(flag *flags, char *buffor_g_e, char *fl, int *check_e,
                         int *check_g, int *eflag2, int *g);
void my_handleLongDoubleNum(flag *flags, char *buffor_g_e, char *fl,
                             int *check_e, int *check_g, int *eflag2, int *g);

void my_func_for_int(char **str, flag *flags, int *count, va_list tr);
void my_func_for_float(char **str, flag *flags, int *count, va_list tr);
void my_func_for_unsigned(char **str, flag *flags, int *count, va_list tr);
void my_func_for_string(char **str, flag *flags, int *count, va_list tr);
void my_func_for_octalstr(char **str, flag *flags, int *count, va_list tr);
void my_func_for_hexstr(char **str, flag *flags, int *count, va_list tr,
                         char x_or_X);
void my_func_for_pointer(char **str, flag *flags, int *count, va_list tr);
void my_case_logic_mantisa(flag *flags, char *buffor_g_e, char **str,
                            int *count);
void my_func_for_mantissa(char **str, flag *flags, int *count, va_list tr,
                           int *check_e, int *check_g);

void my_case_logic_g(flag *flags, char *fl, char **str, int *count);
void my_func_for_g(char **str, flag *flags, int *count, va_list tr,
                    int *check_e, int *check_g);

void my_func_for_percent(char **str, flag *flags, int *count);
void my_flags_pam(va_list tr, flag *flags, const char **format);
int my_parsing_specifier(char **str, int *count, va_list tr, flag *flags,
                          const char **format);

int my_sprintf(char *str, const char *format, ...);
int my_sscanf(const char *str, const char *format, ...);

#endif
