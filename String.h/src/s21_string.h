

#ifndef S21_STRING_H_
#define S21_STRING_H_
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_sprintf.h"
#include "s21_sscanf.h"

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

s21_size_t s21_strlen(const char *str);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strcat(char *dest, const char *src);
int s21_strcmp(const char *str1, const char *str2);       // 1
char *s21_strcpy(char *destination, const char *source);  // 2
s21_size_t s21_strspn(const char *str, const char *sym);  // 3
//!!
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *str1, const char *str2);
//!!
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strerror(int errnum);
void s21_errnum_tostring(char str[], int num);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
//!!
char *s21_strtok(char *str, const char *sep);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
#endif