#include "test_main.h"

// One parameter octal
START_TEST(sprintf_1_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), my_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three octal parameters
START_TEST(sprintf_2_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho GOD %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Test %5o Test %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Test %.23o Test %3.o TEST %.o";
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
START_TEST(sprintf_7_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
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
START_TEST(sprintf_8_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %0.o Test %0.0o TEST %0o GOD %.o";
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
START_TEST(sprintf_9_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Zero vals
START_TEST(sprintf_10_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o %#o %-o %+o %.o % .o";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      my_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Test % 3.o Test % 5.7o TEST % 10o GOD %.o";
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
START_TEST(sprintf_12_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o GOD %+.o";
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

// Hash
START_TEST(sprintf_13_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o Test %#3o Test %#5.7o TEST %#.7o Oof %#.o";
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
START_TEST(sprintf_14_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %06o Test %05.7o TEST %0.7o Oof %0.o";
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
START_TEST(sprintf_15_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%*o Test %-*o Test %*.*o TEST %.*o";
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

// Simple extra test
START_TEST(sprintf_16_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%o";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), my_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%- o Test %- 15o sdasda %- 15o sdsad %- o";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lo";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), my_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%- o Test %- 15o sdasda %- 15o sdsad %- o";
  unsigned int val = -3231;
  unsigned int val2 = -3231;
  unsigned int val3 = 3231;
  unsigned int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%2o %10o %15o %7o %5o %7o %5o %7o";
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

START_TEST(sprintf_21_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%02o %010o %015o %07o %05o %07o %05o %07o";
  int val = 0;
  int val2 = 10;
  int val3 = 0100;
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

START_TEST(sprintf_22_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0+2o %0+10o %0+15o %0+7o %0+5o %0+7o %0+5o %0+7o";
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

START_TEST(sprintf_23_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0-2o %0-10o %0-15o %0-7o %0-5o %0-7o %0-5o %0-7o";
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

START_TEST(sprintf_24_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0-+2o %0-+10o %0-+15o %0-+7o %0-+5o %0-+7o %0-+5o %0-+7o";
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

START_TEST(sprintf_25_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% 02o % 010o % 015o % 07o % 05o % 07o % 05o % 07o";
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

START_TEST(sprintf_26_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% 2o % 10o % 15o % 7o % 5o % 7o % 5o % 7o";
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

START_TEST(sprintf_27_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% 0+2o % 0+10o % 0+15o % 0+7o % 0+5o % 0+7o % 0+5o % 0+7o";
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

START_TEST(sprintf_28_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% 0-2o % 0-10o % 0-15o % 0-7o % 0-5o % 0-7o % 0-5o % 0-7o";
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

START_TEST(sprintf_29_octal) {
  char str1[200];
  char str2[200];
  char *str3 =
      "% 0-+2o % 0-+10o % 0-+15o % 0-+7o % 0-+5o % 0-+7o % 0-+5o % 0-+7o";
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

START_TEST(sprintf_30_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%2.o %10.o %15.o %7.o %5.o %7.o %5.o %7.o";
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

START_TEST(sprintf_31_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%2.10o %10.10o %15.10o %7.10o %5.10o %7.10o %5.10o %7.10o";
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

START_TEST(sprintf_32_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0.10o %0.0o %10.0o %0.10o %5.10o %7.10o %5.10o %7.10o";
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

START_TEST(sprintf_33_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%20.10o %20.0o %20.0o %20.10o %20.10o %20.10o %20.10o %20.10o";
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

START_TEST(sprintf_34_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%20.o %20.0o %20.0o %20.10o %20.10o %20.10o %20.10o %20.10o";
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

START_TEST(sprintf_35_octal) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%+-04.5o %+-04.5o %+-04.5o %+-04.5o %+-04.5o %+-04.5o %+-04.5o %+-04.5o";
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

START_TEST(sprintf_36_octal) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%+- 04.5o %+- 04.5o %+- 04.5o % +-04.5o %+-0 4.5o %+- 04.5o %+- 04.5o "
      "%+ -04.5o";
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

START_TEST(sprintf_37_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% *o Test % *o Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+*o Test %+*o Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-*o Test %-*o Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+0*o Test %-+0*o Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+0*.o Test %-+0*.o Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-+0*.ou Test %-+0*.5o Test";
  int val = 32;
  int val2 = 8899;
  int ast = 2;
  int ast2 = 5;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  int val = 0x32;
  ck_assert_int_eq(sprintf(str1, str3, val), my_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three hex parameters
START_TEST(sprintf_44_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_45_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_46_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho GOD %ho";
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
START_TEST(sprintf_47_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Test %5o Test %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Different precision and width
START_TEST(sprintf_48_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Test %.23o Test %3.o TEST %.o";
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
START_TEST(sprintf_49_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
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
START_TEST(sprintf_50_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %0.o Test %0.0o TEST %0o GOD %.o";
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
START_TEST(sprintf_51_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o";
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
START_TEST(sprintf_52_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o %#o %-o %+o %.o % .o";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      my_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_53_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Test % 3.o Test % 5.7o TEST % 10o GOD %.o";
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
START_TEST(sprintf_54_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o GOD %+.o";
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

// ZERO flag
START_TEST(sprintf_55_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %06o Test %05.7o TEST %0.7o Oof %0.o";
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

// HASH
START_TEST(sprintf_57_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%#o Test %#2o Test %#2.7o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// HASH
START_TEST(sprintf_58_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%#0.2o Test %#2.o Test %#7.7o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// HASH
START_TEST(sprintf_59_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%#0.2o Test %#2.o Test %#7.7o";
  int val = 0;
  int val2 = 0;
  int val3 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_octal(void) {
  Suite *s = suite_create("\033[45m-=my_SPRINTF_OCTAL=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_octal);
  tcase_add_test(tc, sprintf_2_octal);
  tcase_add_test(tc, sprintf_3_octal);
  tcase_add_test(tc, sprintf_4_octal);
  tcase_add_test(tc, sprintf_5_octal);
  tcase_add_test(tc, sprintf_6_octal);
  tcase_add_test(tc, sprintf_7_octal);
  tcase_add_test(tc, sprintf_8_octal);
  tcase_add_test(tc, sprintf_9_octal);
  tcase_add_test(tc, sprintf_10_octal);
  tcase_add_test(tc, sprintf_11_octal);
  tcase_add_test(tc, sprintf_12_octal);
  tcase_add_test(tc, sprintf_13_octal);
  tcase_add_test(tc, sprintf_14_octal);
  tcase_add_test(tc, sprintf_15_octal);
  tcase_add_test(tc, sprintf_16_octal);
  tcase_add_test(tc, sprintf_17_octal);
  tcase_add_test(tc, sprintf_18_octal);
  tcase_add_test(tc, sprintf_19_octal);
  tcase_add_test(tc, sprintf_20_octal);
  tcase_add_test(tc, sprintf_21_octal);
  tcase_add_test(tc, sprintf_22_octal);
  tcase_add_test(tc, sprintf_23_octal);
  tcase_add_test(tc, sprintf_24_octal);
  tcase_add_test(tc, sprintf_25_octal);
  tcase_add_test(tc, sprintf_26_octal);
  tcase_add_test(tc, sprintf_27_octal);
  tcase_add_test(tc, sprintf_28_octal);
  tcase_add_test(tc, sprintf_29_octal);
  tcase_add_test(tc, sprintf_30_octal);
  tcase_add_test(tc, sprintf_31_octal);
  tcase_add_test(tc, sprintf_32_octal);
  tcase_add_test(tc, sprintf_33_octal);
  tcase_add_test(tc, sprintf_34_octal);
  tcase_add_test(tc, sprintf_35_octal);
  tcase_add_test(tc, sprintf_36_octal);
  tcase_add_test(tc, sprintf_37_octal);
  tcase_add_test(tc, sprintf_38_octal);
  tcase_add_test(tc, sprintf_39_octal);
  tcase_add_test(tc, sprintf_40_octal);
  tcase_add_test(tc, sprintf_41_octal);
  tcase_add_test(tc, sprintf_42_octal);
  tcase_add_test(tc, sprintf_43_octal);
  tcase_add_test(tc, sprintf_44_octal);
  tcase_add_test(tc, sprintf_45_octal);
  tcase_add_test(tc, sprintf_46_octal);
  tcase_add_test(tc, sprintf_47_octal);
  tcase_add_test(tc, sprintf_48_octal);
  tcase_add_test(tc, sprintf_49_octal);
  tcase_add_test(tc, sprintf_50_octal);
  tcase_add_test(tc, sprintf_51_octal);
  tcase_add_test(tc, sprintf_52_octal);
  tcase_add_test(tc, sprintf_53_octal);
  tcase_add_test(tc, sprintf_54_octal);
  tcase_add_test(tc, sprintf_55_octal);
  tcase_add_test(tc, sprintf_57_octal);
  tcase_add_test(tc, sprintf_58_octal);
  tcase_add_test(tc, sprintf_59_octal);

  suite_add_tcase(s, tc);
  return s;
}
