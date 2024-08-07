#include "test_main.h"

START_TEST(sprintf_1_HEX) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %X Test";
  int val = 0X32;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three HEX parameters
START_TEST(sprintf_2_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X7a4;
  int val2 = 0X9112312f;
  int val3 = 0X3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X3015;
  int val2 = 0X712;
  int val3 = 0X99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%lX Test %lX Test %hX GOD %hX";
  unsigned long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%3X Test %5X Test %10X";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5X Test %.23X Test %3.X TEST %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5X Test %-.8X Test %-7X TEST %-.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %0.X Test %0.0X TEST %0X GOD %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+3.X Test %+5.7X TEST %+10X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%X Test %3.X Test %5.7X TEST %10X %#X %-X %+X %.X % .X";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "% X Test % 3.X Test % 5.7X TEST % 10X GOD %.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+3.X Test %+5.7X TEST %+10X GOD %+.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Hash
START_TEST(sprintf_13_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%#X Test %#3X Test %#5.7X TEST %#.7X Oof %#.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %06X Test %05.7X TEST %0.7X Oof %0.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%*X Test %-*X Test %*.*X TEST %.*X";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%- X Test %- 15X sdasda %- 15X sdsad %- X";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%2X %10X %15X %7X %5X %7X %5X %7X";
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

START_TEST(sprintf_18_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%02X %010X %015X %07X %05X %07X %05X %07X";
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

START_TEST(sprintf_19_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0+2X %0+10X %0+15X %0+7X %0+5X %0+7X %0+5X %0+7X";
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

START_TEST(sprintf_20_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0-2X %0-10X %0-15X %0-7X %0-5X %0-7X %0-5X %0-7X";
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

START_TEST(sprintf_21_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0-+2X %0-+10X %0-+15X %0-+7X %0-+5X %0-+7X %0-+5X %0-+7X";
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

START_TEST(sprintf_22_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "% 02X % 010X % 015X % 07X % 05X % 07X % 05X % 07X";
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

START_TEST(sprintf_23_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "% 2X % 10X % 15X % 7X % 5X % 7X % 5X % 7X";
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

START_TEST(sprintf_24_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "% 0+2X % 0+10X % 0+15X % 0+7X % 0+5X % 0+7X % 0+5X % 0+7X";
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

START_TEST(sprintf_25_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "% 0-2X % 0-10X % 0-15X % 0-7X % 0-5X % 0-7X % 0-5X % 0-7X";
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

START_TEST(sprintf_26_HEX) {
  char str1[200];
  char str2[200];
  char *str3 =
      "% 0-+2X % 0-+10X % 0-+15X % 0-+7X % 0-+5X % 0-+7X % 0-+5X % 0-+7X";
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

START_TEST(sprintf_27_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%2.X %10.X %15.X %7.X %5.X %7.X %5.X %7.X";
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

START_TEST(sprintf_28_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%2.10X %10.10X %15.10X %7.10X %5.10X %7.10X %5.10X %7.10X";
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

START_TEST(sprintf_29_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0.10X %0.0X %10.0X %0.10X %5.10X %7.10X %5.10X %7.10X";
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

START_TEST(sprintf_30_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%20.10X %20.0X %20.0X %20.10X %20.10X %20.10X %20.10X %20.10X";
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

START_TEST(sprintf_31_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%20.X %20.0X %20.0X %20.10X %20.10X %20.10X %20.10X %20.10X";
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

START_TEST(sprintf_32_HEX) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%+-04.5X %+-04.5X %+-04.5X %+-04.5X %+-04.5X %+-04.5X %+-04.5X %+-04.5X";
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

START_TEST(sprintf_33_HEX) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%+- 04.5X %+- 04.5X %+- 04.5X % +-04.5X %+-0 4.5X %+- 04.5X %+- 04.5X "
      "%+ -04.5X";
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

START_TEST(sprintf_34_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "% *X Test % *X Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%+*X Test %+*X Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%-*X Test %-*X Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+0*X Test %-+0*X Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+0*.X Test %-+0*.X Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+#0*.5X Test %-+0#*.5X Test";
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
START_TEST(sprintf_40_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%#X Test %#2X Test %#2.7X";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// HASH
START_TEST(sprintf_41_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%#0.2X Test %#2.X Test %#7.7X";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// HASH
START_TEST(sprintf_42_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%#0.2X Test %#2.X Test %#7.7X";
  int val = 0;
  int val2 = 0;
  int val3 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_HEX(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_HEX2=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_HEX);
  tcase_add_test(tc, sprintf_2_HEX);
  tcase_add_test(tc, sprintf_3_HEX);
  tcase_add_test(tc, sprintf_4_HEX);
  tcase_add_test(tc, sprintf_5_HEX);
  tcase_add_test(tc, sprintf_6_HEX);
  tcase_add_test(tc, sprintf_7_HEX);
  tcase_add_test(tc, sprintf_8_HEX);
  tcase_add_test(tc, sprintf_9_HEX);
  tcase_add_test(tc, sprintf_10_HEX);
  tcase_add_test(tc, sprintf_11_HEX);
  tcase_add_test(tc, sprintf_12_HEX);
  tcase_add_test(tc, sprintf_13_HEX);
  tcase_add_test(tc, sprintf_14_HEX);
  tcase_add_test(tc, sprintf_15_HEX);
  tcase_add_test(tc, sprintf_16_HEX);
  tcase_add_test(tc, sprintf_17_HEX);
  tcase_add_test(tc, sprintf_18_HEX);
  tcase_add_test(tc, sprintf_19_HEX);
  tcase_add_test(tc, sprintf_20_HEX);
  tcase_add_test(tc, sprintf_21_HEX);
  tcase_add_test(tc, sprintf_22_HEX);
  tcase_add_test(tc, sprintf_23_HEX);
  tcase_add_test(tc, sprintf_24_HEX);
  tcase_add_test(tc, sprintf_25_HEX);
  tcase_add_test(tc, sprintf_26_HEX);
  tcase_add_test(tc, sprintf_27_HEX);
  tcase_add_test(tc, sprintf_28_HEX);
  tcase_add_test(tc, sprintf_29_HEX);
  tcase_add_test(tc, sprintf_30_HEX);
  tcase_add_test(tc, sprintf_31_HEX);
  tcase_add_test(tc, sprintf_32_HEX);
  tcase_add_test(tc, sprintf_33_HEX);
  tcase_add_test(tc, sprintf_34_HEX);
  tcase_add_test(tc, sprintf_35_HEX);
  tcase_add_test(tc, sprintf_36_HEX);
  tcase_add_test(tc, sprintf_37_HEX);
  tcase_add_test(tc, sprintf_38_HEX);
  tcase_add_test(tc, sprintf_39_HEX);
  tcase_add_test(tc, sprintf_40_HEX);
  tcase_add_test(tc, sprintf_41_HEX);
  tcase_add_test(tc, sprintf_42_HEX);

  suite_add_tcase(s, tc);
  return s;
}
