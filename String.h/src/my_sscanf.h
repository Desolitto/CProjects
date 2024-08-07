#ifndef my_SSCANF_H_
#define my_SSCANF_H_

#include "my_string.h"

#define my_isdigit(c) ((c >= '0' && c <= '9') ? 1 : 0)
#define my_isspace(c) ((c == ' ' || c == '\n' || c == '\t') ? 1 : 0)

typedef struct {
  int readAndSkip;
  int width;
  int width_exist;
  int count;
  int length_mode;
  int len_count;
  int signedWidth;
} flagss;

void my_parse_flag_sscanf(const char *format, flagss *flags);
int my_isInfNan(const char *s, int *i, double *n);
long long int my_str_to_num(const char *s, int *n_num, flagss flags,
                             int *isWrongWidth, int base);
void my_xX_to_num(char s, unsigned long long int *n, int base);
double my_f_str_to_num(const char *s, int *n_num, int *isDigitExist,
                        flagss flags, int *isWrongWidth);
unsigned long long int my_xXp_str_to_num(const char *s, int *n_num,
                                          flagss flags, int *isWrongWidth,
                                          int base);
int my_handleSpacesInSpecifiers(const char **format, int *lengthStr);
int my_handleCSpec(const char **str, va_list *tr, flagss *flags,
                    int isSpaceinfromat, int *read_from_str);
int my_handleSSpec(va_list *tr, const char **str, flagss *flags,
                    int *read_from_str);
int my_handleDSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str);
int my_handleUOSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                     int *read_from_str, int base);
int my_handleXSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str);
int my_handlePSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str);
int my_handleFSpec(int *resWidth, const char **str, va_list *tr, flagss flags,
                    int *read_from_str);
void my_handleNSpec(int isSpec, const char **str, va_list *tr,
                     int *read_from_str);
void my_parse_spec(const char **str, const char **format, va_list *tr,
                    int isSpaceinfromat, int *read_from_str, int *resWidth,
                    int *count, flagss flags);
int my_handleSscanf(const char *str, const char *format, va_list *tr,
                     int lengthStr, int lengthFormat);

#endif