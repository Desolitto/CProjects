

#ifndef my_STRING_H_
#define my_STRING_H_
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_sprintf.h"
#include "my_sscanf.h"

#define my_NULL (void *)0
#define my_size_t unsigned long long

my_size_t my_strlen(const char *str);
void *my_memchr(const void *str, int c, my_size_t n);
int my_memcmp(const void *str1, const void *str2, my_size_t n);
void *my_memcpy(void *dest, const void *src, my_size_t n);
void *my_memset(void *str, int c, my_size_t n);
void *my_memmove(void *dest, const void *src, my_size_t n);
char *my_strpbrk(const char *str1, const char *str2);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *str1, const char *str2);       // 1
char *my_strcpy(char *destination, const char *source);  // 2
my_size_t my_strspn(const char *str, const char *sym);  // 3
//!!
char *my_strchr(const char *str, int c);
char *my_strrchr(const char *str, int c);
char *my_strstr(const char *str1, const char *str2);
//!!
char *my_strpbrk(const char *str1, const char *str2);
char *my_strncpy(char *dest, const char *src, my_size_t n);
char *my_strncat(char *dest, const char *src, my_size_t n);
int my_strncmp(const char *str1, const char *str2, my_size_t n);
char *my_strerror(int errnum);
void my_errnum_tostring(char str[], int num);
int my_strncmp(const char *str1, const char *str2, my_size_t n);
my_size_t my_strcspn(const char *str1, const char *str2);
//!!
char *my_strtok(char *str, const char *sep);
void *my_to_lower(const char *str);
void *my_to_upper(const char *str);
void *my_insert(const char *src, const char *str, my_size_t start_index);
void *my_trim(const char *src, const char *trim_chars);
#endif