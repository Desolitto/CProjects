#include "test_main.h"

// One parameter unsigned
START_TEST(sprintf_1_unsigned) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %u Test";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three unsigned parameters
START_TEST(sprintf_2_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%lu Test %lu Test %hu GOD %hu";
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 33030030303;
  unsigned short val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%3u Test %5u Test %10u";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Different precision and width
START_TEST(sprintf_6_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5u Test %.23u Test %3.u TEST %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10u Test %-8u Test %-7u TEST %-u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zerues
START_TEST(sprintf_8_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %0u Test %00u TEST %0u GOD %5u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  unsigned int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3u Test %+5u TEST %+010u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Zeru vals
START_TEST(sprintf_10_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%u Test %3.u Test %5.7u TEST %10u %#u %-u %+u %.u % .u";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_11_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3u Test %+05u TEST %+10u GOD %+u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_12_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "% u Test % 3u Test % 0u TEST % -10u GOD % +-0u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Hash
START_TEST(sprintf_13_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%#u Test %#3u Test %#5.7u TEST %#.7u Ouf %#.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %06u Test %05u TEST %07u Ouf %0u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%*u Test %-*u Test %*.*u TEST %.*u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 919;
  unsigned int val4 = 32311;
  unsigned int ast = 2;
  unsigned int ast2 = 5;
  unsigned int ast3 = 4;
  unsigned int ast4 = 10;
  unsigned int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lu";
  unsigned long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%- u Test %- 15u sdasda %- 15u sdsad %- u";
  unsigned int val = -3231;
  unsigned int val2 = -3231;
  unsigned int val3 = 3231;
  unsigned int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%2u %10u %15u %7u %5u %7u %5u %7u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%02u %010u %015u %07u %05u %07u %05u %07u";
  int val = 0;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0+2u %0+10u %0+15u %0+7u %0+5u %0+7u %0+5u %0+7u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0-2u %0-10u %0-15u %0-7u %0-5u %0-7u %0-5u %0-7u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0-+2u %0-+10u %0-+15u %0-+7u %0-+5u %0-+7u %0-+5u %0-+7u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "% 02u % 010u % 015u % 07u % 05u % 07u % 05u % 07u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "% 2u % 10u % 15u % 7u % 5u % 7u % 5u % 7u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "% 0+2u % 0+10u % 0+15u % 0+7u % 0+5u % 0+7u % 0+5u % 0+7u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "% 0-2u % 0-10u % 0-15u % 0-7u % 0-5u % 0-7u % 0-5u % 0-7u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 =
      "% 0-+2u % 0-+10u % 0-+15u % 0-+7u % 0-+5u % 0-+7u % 0-+5u % 0-+7u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%2.u %10.u %15.u %7.u %5.u %7.u %5.u %7.u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%2.10u %10.10u %15.10u %7.10u %5.10u %7.10u %5.10u %7.10u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0.10u %0.0u %10.0u %0.10u %5.10u %7.10u %5.10u %7.10u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%20.10u %20.0u %20.0u %20.10u %20.10u %20.10u %20.10u %20.10u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%20.u %20.0u %20.0u %20.10u %20.10u %20.10u %20.10u %20.10u";
  int val = 0;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%+-04.5u %+-04.5u %+-04.5u %+-04.5u %+-04.5u %+-04.5u %+-04.5u %+-04.5u";
  int val = 0;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%+- 04.5u %+- 04.5u %+- 04.5u % +-04.5u %+-0 4.5u %+- 04.5u %+- 04.5u "
      "%+ -04.5u";
  int val = 0;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "% *u Test % *u Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%+*u Test %+*u Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%-*u Test %-*u Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+0*u Test %-+0*u Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+0*.u Test %-+0*.u Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+0*.5u Test %-+0*.5u Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// HASH
START_TEST(sprintf_41_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%#u Test %#2u Test %#2.7u";
  int val = 32;
  int val2 = 8899;
  int val3 = 2;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// HASH
START_TEST(sprintf_42_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%#0.2u Test %#2.u Test %#7.7u";
  int val = 32;
  int val2 = 8899;
  int val3 = 2;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// HASH
START_TEST(sprintf_43_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%#0.2u Test %#2.u Test %#7.7u";
  int val = 0;
  int val2 = 0;
  int val3 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %lu";
  unsigned long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_unsigned(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_UNSIGNED=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_unsigned);
  tcase_add_test(tc, sprintf_2_unsigned);
  tcase_add_test(tc, sprintf_3_unsigned);
  tcase_add_test(tc, sprintf_4_unsigned);
  tcase_add_test(tc, sprintf_5_unsigned);
  tcase_add_test(tc, sprintf_6_unsigned);
  tcase_add_test(tc, sprintf_7_unsigned);
  tcase_add_test(tc, sprintf_8_unsigned);
  tcase_add_test(tc, sprintf_9_unsigned);
  tcase_add_test(tc, sprintf_10_unsigned);
  tcase_add_test(tc, sprintf_11_unsigned);
  tcase_add_test(tc, sprintf_12_unsigned);
  tcase_add_test(tc, sprintf_13_unsigned);
  tcase_add_test(tc, sprintf_14_unsigned);
  tcase_add_test(tc, sprintf_15_unsigned);
  tcase_add_test(tc, sprintf_16_unsigned);
  tcase_add_test(tc, sprintf_17_unsigned);
  tcase_add_test(tc, sprintf_18_unsigned);
  tcase_add_test(tc, sprintf_19_unsigned);
  tcase_add_test(tc, sprintf_20_unsigned);
  tcase_add_test(tc, sprintf_21_unsigned);
  tcase_add_test(tc, sprintf_22_unsigned);
  tcase_add_test(tc, sprintf_23_unsigned);
  tcase_add_test(tc, sprintf_24_unsigned);
  tcase_add_test(tc, sprintf_25_unsigned);
  tcase_add_test(tc, sprintf_26_unsigned);
  tcase_add_test(tc, sprintf_27_unsigned);
  tcase_add_test(tc, sprintf_28_unsigned);
  tcase_add_test(tc, sprintf_29_unsigned);
  tcase_add_test(tc, sprintf_30_unsigned);
  tcase_add_test(tc, sprintf_31_unsigned);
  tcase_add_test(tc, sprintf_32_unsigned);
  tcase_add_test(tc, sprintf_33_unsigned);
  tcase_add_test(tc, sprintf_34_unsigned);
  tcase_add_test(tc, sprintf_35_unsigned);
  tcase_add_test(tc, sprintf_36_unsigned);
  tcase_add_test(tc, sprintf_37_unsigned);
  tcase_add_test(tc, sprintf_38_unsigned);
  tcase_add_test(tc, sprintf_39_unsigned);
  tcase_add_test(tc, sprintf_40_unsigned);
  tcase_add_test(tc, sprintf_41_unsigned);
  tcase_add_test(tc, sprintf_42_unsigned);
  tcase_add_test(tc, sprintf_43_unsigned);
  tcase_add_test(tc, sprintf_44_unsigned);

  suite_add_tcase(s, tc);
  return s;
}
