#include "test_main.h"

// One parameter asterisk +
START_TEST(sprintf_1_asterisk) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %.*d Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val, 1),
                   s21_sprintf(str2, str3, val, 1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// One parameter asterisk ang * width d,u,o
START_TEST(sprintf_2_asterisk) {
  char str1[200];
  char str2[200];
  char *str3 = "%+*.*d Test";
  int a = 1;
  int b = 2;
  int c = 456;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_3_asterisk) {
  char str1[200];
  char str2[200];
  char *str3 = "%+*.*d Test";
  int a = 1;
  int b = 2;
  int c = 456;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_2_asterisk) {
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
  int res1 = s21_sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                         ast5, val4);
  int res2 =
      sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// One parameter asterisk ang * width x, X
START_TEST(sprintf_3_asterisk) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%*.*x Test  %*.*X Test";
  int val = 0x7a4;  // x
  int val2 = 0;     // X
  int val3 = 3015;
  int val4 = 01234;
  int val5 = 99;
  int arg_width = 10;
  int arg_accur = 10;
  int arg_width1 = 2;
  int arg_accur1 = 9;
  int arg_width2 = 29;
  int arg_accur2 = 10;
  int arg_width3 = 50;
  int arg_accur3 = 0;
  int arg_width4 = 23;
  int arg_accur4 = 1;
  ck_assert_int_eq(
      sprintf(str1, str3, arg_width, arg_accur, val, arg_width1, arg_accur1,
              val2, arg_width2, arg_accur2, val3, arg_width3, arg_accur3, val4,
              arg_width4, arg_accur4, val5),
      s21_sprintf(str2, str3, arg_width, arg_accur, val, arg_width1, arg_accur1,
                  val2, arg_width2, arg_accur2, val3, arg_width3, arg_accur3,
                  val4, arg_width4, arg_accur4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

//Ширина отсутствует

// One parameter asterisk ang * width d,u,o
START_TEST(sprintf_4_asterisk) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %.*d Test %.*u Test  %.*o";
  int val = -12;            // d
  unsigned int val2 = 012;  // u
  int val3 = 012;           // o
  ck_assert_int_eq(sprintf(str1, str3, 10, val, 2, val2, 0, val3),
                   s21_sprintf(str2, str3, 10, val, 2, val2, 0, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// One parameter asterisk ang * width x, X
START_TEST(sprintf_5_asterisk) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%.*x Test  %.*X Test";
  int val = 0x7a4;  // x
  int val2 = 0;     // X
  int val3 = 3015;
  int val4 = 01234;
  int val5 = 99;

  int arg_accur = 10;
  int arg_accur1 = 9;
  int arg_accur2 = 10;
  int arg_accur3 = 0;
  int arg_accur4 = 1;

  ck_assert_int_eq(
      sprintf(str1, str3, arg_accur, val, arg_accur1, val2, arg_accur2, val3,
              arg_accur3, val4, arg_accur4, val5),
      s21_sprintf(str2, str3, arg_accur, val, arg_accur1, val2, arg_accur2,
                  val3, arg_accur3, val4, arg_accur4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_asterisk) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %10.*f Test %2.*e Test  %10.*E Test  %10.*E";
  double val = 76.756513;                   // f
  double val1 = -764231539.;                // e
  double val2 = 1234567890000.0938217586;   // E
  double val3 = -.12345678900000938217586;  // E
  int arg_accur = 10;
  int arg_accur1 = 9;
  int arg_accur2 = 10;
  int arg_accur3 = 10;

  ck_assert_int_eq(sprintf(str1, str3, arg_accur, val, arg_accur1, val1,
                           arg_accur2, val2, arg_accur3, val3),
                   s21_sprintf(str2, str3, arg_accur, val, arg_accur1, val1,
                               arg_accur2, val2, arg_accur3, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_asterisk) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10d Test %-8d Test %-7d TEST %-d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_asterisk) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %0d Test %00d TEST %-0d GOD %5d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_asterisk) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3d Test %+5d TEST %+10d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Zero vals
START_TEST(sprintf_10_asterisk) {
  char str1[200];
  char str2[200];
  char *str3 = "%d Test %3.d Test %5.7d TEST %10d %#d %-d %+d %.d % .d";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Spaces
START_TEST(sprintf_11_asterisk) {
  char str1[200];
  char str2[200];
  char *str3 = "% d Test % 3d Test % +5d TEST % -10d GOD % +-d";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Plus
START_TEST(sprintf_12_asterisk) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d GOD %+.d";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_asterisk(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_asterisk=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_asterisk);
  tcase_add_test(tc, sprintf_2_asterisk);
  tcase_add_test(tc, sprintf_2_2_asterisk);
  tcase_add_test(tc, sprintf_2_3_asterisk);
  tcase_add_test(tc, sprintf_3_asterisk);
  tcase_add_test(tc, sprintf_4_asterisk);
  tcase_add_test(tc, sprintf_5_asterisk);
  tcase_add_test(tc, sprintf_6_asterisk);
  tcase_add_test(tc, sprintf_7_asterisk);
  tcase_add_test(tc, sprintf_8_asterisk);
  tcase_add_test(tc, sprintf_9_asterisk);
  tcase_add_test(tc, sprintf_10_asterisk);
  tcase_add_test(tc, sprintf_11_asterisk);
  tcase_add_test(tc, sprintf_12_asterisk);

  suite_add_tcase(s, tc);
  return s;
}