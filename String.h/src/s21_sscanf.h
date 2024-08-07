#ifndef S21_SSCANF_H_
#define S21_SSCANF_H_

#include "s21_string.h"

#define s21_isdigit(c) ((c >= '0' && c <= '9') ? 1 : 0)
#define s21_isspace(c) ((c == ' ' || c == '\n' || c == '\t') ? 1 : 0)

typedef struct {
  int readAndSkip;
  int width;
  int width_exist;
  int count;
  int length_mode;
  int len_count;
  int signedWidth;
} flagss;

void s21_parse_flag_sscanf(const char *format, flagss *flags);
int s21_isInfNan(const char *s, int *i, double *n);
long long int s21_str_to_num(const char *s, int *n_num, flagss flags,
                             int *isWrongWidth, int base);
void s21_xX_to_num(char s, unsigned long long int *n, int base);
double s21_f_str_to_num(const char *s, int *n_num, int *isDigitExist,
                        flagss flags, int *isWrongWidth);
unsigned long long int s21_xXp_str_to_num(const char *s, int *n_num,
                                          flagss flags, int *isWrongWidth,
                                          int base);
int s21_handleSpacesInSpecifiers(const char **format, int *lengthStr);
int s21_handleCSpec(const char **str, va_list *tr, flagss *flags,
                    int isSpaceinfromat, int *read_from_str);
int s21_handleSSpec(va_list *tr, const char **str, flagss *flags,
                    int *read_from_str);
int s21_handleDSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str);
int s21_handleUOSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                     int *read_from_str, int base);
int s21_handleXSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str);
int s21_handlePSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str);
int s21_handleFSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str);
void s21_handleNSpec(int isSpec, const char **str, va_list *tr,
                     int *read_from_str);
void s21_parse_spec(const char **str, const char **format, va_list *tr,
                    int isSpaceinfromat, int *read_from_str, int *resWidth,
                    int *count, flagss flags);
int s21_handleSscanf(const char *str, const char *format, va_list *tr,
                     int lengthStr, int lengthFormat);

#endif