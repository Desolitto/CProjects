#include "test_main.h"

// One parameter hex
START_TEST(sprintf_1_hex) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %x Test";
  int val = 0x32;
  ck_assert_int_eq(sprintf(str1, str3, val), my_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three hex parameters
START_TEST(sprintf_2_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%lx Test %lx Test %hx GOD %hx";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%3x Test %5x Test %10x";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Different precision and width
START_TEST(sprintf_6_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5x Test %.23x Test %3.x TEST %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5x Test %-.8x Test %-7x TEST %-.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %0.x Test %0.0x TEST %0x GOD %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   my_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%x Test %3.x Test %5.7x TEST %10x %#x %-x %+x %.x % .x";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      my_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "% x Test % 3.x Test % 5.7x TEST % 10x GOD %.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   my_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x GOD %+.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   my_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Hash
START_TEST(sprintf_13_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%#x Test %#3x Test %#5.7x TEST %#.7x Oof %#.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   my_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %06x Test %05.7x TEST %0.7x Oof %0.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   my_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%*x Test %-*x Test %*.*x TEST %.*x";
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
      my_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%- x Test %- 15x sdasda %- 15x sdsad %- x";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lx";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), my_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%2x %10x %15x %7x %5x %7x %5x %7x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%02x %010x %015x %07x %05x %07x %05x %07x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0+2x %0+10x %0+15x %0+7x %0+5x %0+7x %0+5x %0+7x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0-2x %0-10x %0-15x %0-7x %0-5x %0-7x %0-5x %0-7x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0-+2x %0-+10x %0-+15x %0-+7x %0-+5x %0-+7x %0-+5x %0-+7x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "% 02x % 010x % 015x % 07x % 05x % 07x % 05x % 07x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "% 2x % 10x % 15x % 7x % 5x % 7x % 5x % 7x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "% 0+2x % 0+10x % 0+15x % 0+7x % 0+5x % 0+7x % 0+5x % 0+7x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "% 0-2x % 0-10x % 0-15x % 0-7x % 0-5x % 0-7x % 0-5x % 0-7x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_hex) {
  char str1[200];
  char str2[200];
  char *str3 =
      "% 0-+2x % 0-+10x % 0-+15x % 0-+7x % 0-+5x % 0-+7x % 0-+5x % 0-+7x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%2.x %10.x %15.x %7.x %5.x %7.x %5.x %7.x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%2.10x %10.10x %15.10x %7.10x %5.10x %7.10x %5.10x %7.10x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0.10x %0.0x %10.0x %0.10x %5.10x %7.10x %5.10x %7.10x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%20.10x %20.0x %20.0x %20.10x %20.10x %20.10x %20.10x %20.10x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%20.x %20.0x %20.0x %20.10x %20.10x %20.10x %20.10x %20.10x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_hex) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%+-04.5x %+-04.5x %+-04.5x %+-04.5x %+-04.5x %+-04.5x %+-04.5x %+-04.5x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_hex) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%+- 04.5x %+- 04.5x %+- 04.5x % +-04.5x %+-0 4.5x %+- 04.5x %+- 04.5x "
      "%+ -04.5x";
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
      my_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "% *x Test % *x Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+*x Test %+*x Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-*x Test %-*x Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+0*x Test %-+0*x Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+0*.x Test %-+0*.x Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+0*.5x Test %-+0*.5x Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+#0*.5x Test %-+0#*.5x Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// HASH
START_TEST(sprintf_42_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%#x Test %#2x Test %#2.7x";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// HASH
START_TEST(sprintf_43_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%#0.2x Test %#2.x Test %#7.7x";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// HASH
START_TEST(sprintf_44_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%#0.2x Test %#2.x Test %#7.7x";
  int val = 0;
  int val2 = 0;
  int val3 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_hex(void) {
  Suite *s = suite_create("\033[45m-=my_SPRINTF_HEX1=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_hex);
  tcase_add_test(tc, sprintf_2_hex);
  tcase_add_test(tc, sprintf_3_hex);
  tcase_add_test(tc, sprintf_4_hex);
  tcase_add_test(tc, sprintf_5_hex);
  tcase_add_test(tc, sprintf_6_hex);
  tcase_add_test(tc, sprintf_7_hex);
  tcase_add_test(tc, sprintf_8_hex);
  tcase_add_test(tc, sprintf_9_hex);
  tcase_add_test(tc, sprintf_10_hex);
  tcase_add_test(tc, sprintf_11_hex);
  tcase_add_test(tc, sprintf_12_hex);
  tcase_add_test(tc, sprintf_13_hex);
  tcase_add_test(tc, sprintf_14_hex);
  tcase_add_test(tc, sprintf_15_hex);
  tcase_add_test(tc, sprintf_16_hex);
  tcase_add_test(tc, sprintf_17_hex);
  tcase_add_test(tc, sprintf_18_hex);
  tcase_add_test(tc, sprintf_19_hex);
  tcase_add_test(tc, sprintf_20_hex);
  tcase_add_test(tc, sprintf_21_hex);
  tcase_add_test(tc, sprintf_22_hex);
  tcase_add_test(tc, sprintf_23_hex);
  tcase_add_test(tc, sprintf_24_hex);
  tcase_add_test(tc, sprintf_25_hex);
  tcase_add_test(tc, sprintf_26_hex);
  tcase_add_test(tc, sprintf_27_hex);
  tcase_add_test(tc, sprintf_28_hex);
  tcase_add_test(tc, sprintf_29_hex);
  tcase_add_test(tc, sprintf_30_hex);
  tcase_add_test(tc, sprintf_31_hex);
  tcase_add_test(tc, sprintf_32_hex);
  tcase_add_test(tc, sprintf_33_hex);
  tcase_add_test(tc, sprintf_34_hex);
  tcase_add_test(tc, sprintf_35_hex);
  tcase_add_test(tc, sprintf_36_hex);
  tcase_add_test(tc, sprintf_37_hex);
  tcase_add_test(tc, sprintf_38_hex);
  tcase_add_test(tc, sprintf_39_hex);
  tcase_add_test(tc, sprintf_40_hex);
  tcase_add_test(tc, sprintf_41_hex);
  tcase_add_test(tc, sprintf_42_hex);
  tcase_add_test(tc, sprintf_43_hex);
  tcase_add_test(tc, sprintf_44_hex);

  suite_add_tcase(s, tc);
  return s;
}
