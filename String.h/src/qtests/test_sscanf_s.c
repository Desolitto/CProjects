#include "test_main.h"

// Один спецификатор
START_TEST(sscanf_spec_s_1) {
  char format[] = "%s";
  char str[] = "Hello, world!";
  char c1[100], c2[100];

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c1, c2);
}
END_TEST

// Несколько спецификаторов
START_TEST(sscanf_spec_s_2) {
  char format[] = "%s %s";
  char str[] = "Hello, world!";
  char c1[100], c2[100];
  char c3[100], c4[100];

  int16_t res1 = s21_sscanf(str, format, &c1, &c3);
  int16_t res2 = sscanf(str, format, &c2, &c4);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(c3, c4);
}
END_TEST

// спец символы и цифры
START_TEST(sscanf_spec_s_3) {
  char format[] = "%s %s";
  char str[] = "0101\n 333";
  char c1[100], c2[100];
  char c3[100], c4[100];

  int16_t res1 = s21_sscanf(str, format, &c1, &c3);
  int16_t res2 = sscanf(str, format, &c2, &c4);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(c3, c4);
}
END_TEST

//пустая строка
START_TEST(sscanf_spec_s_4) {
  char format[] = "%s %s";
  char str[] = "";
  char c1[100], c2[100];
  char c3[100], c4[100];

  int16_t res1 = s21_sscanf(str, format, &c1, &c3);
  int16_t res2 = sscanf(str, format, &c2, &c4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

//большая строка
START_TEST(sscanf_spec_s_5) {
  char format[] = "%s";
  char str[] =
      "kdjfhofklajfsfdhiuhfojpk[ackpahdiuhiusdhviocjaocskpcsjdovhoija["
      "skxopasjcoviudshcijapo`kciuhg";
  char c1[200], c2[200];

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c1, c2);
}
END_TEST

// Один спецификатор + ширина
START_TEST(sscanf_spec_s_6) {
  char format[] = "%5s";
  char str[] = "Hello, world!";
  char c1[100], c2[100];

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c1, c2);
}
END_TEST

// Несколько спецификаторов + ширина
START_TEST(sscanf_spec_s_7) {
  char format[] = "%5s %5s";
  char str[] = "Hello, world!";
  char c1[100], c2[100];
  char c3[100], c4[100];

  int16_t res1 = s21_sscanf(str, format, &c1, &c3);
  int16_t res2 = sscanf(str, format, &c2, &c4);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(c3, c4);
}
END_TEST

// Несколько спецификаторов + ширина 0
START_TEST(sscanf_spec_s_8) {
  char format[] = "%0s %5s";
  char str[] = "Hello, world!";
  char c1[100], c2[100];
  char c3[100], c4[100];

  int16_t res1 = s21_sscanf(str, format, &c1, &c3);
  int16_t res2 = sscanf(str, format, &c2, &c4);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(c3, c4);
}
END_TEST

// Несколько спецификаторов + ширина 0
START_TEST(sscanf_spec_s_9) {
  char format[] = "%0s %0s";
  char str[] = "Hello, world!";
  char c1[100], c2[100];
  char c3[100], c4[100];

  int16_t res1 = s21_sscanf(str, format, &c1, &c3);
  int16_t res2 = sscanf(str, format, &c2, &c4);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(c3, c4);
}
END_TEST

// Несколько спецификаторов + отрицательная ширина
START_TEST(sscanf_spec_s_10) {
  char format[] = "%-5s %-5s";
  char str[] = "Hello, world!";
  char c1[100], c2[100];
  char c3[100], c4[100];

  int16_t res1 = s21_sscanf(str, format, &c1, &c3);
  int16_t res2 = sscanf(str, format, &c2, &c4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Несколько спецификаторов + положительная ширина
START_TEST(sscanf_spec_s_11) {
  char format[] = "%+5s %+5s";
  char str[] = "Hello, world!";
  char c1[100], c2[100];
  char c3[100], c4[100];

  int16_t res1 = s21_sscanf(str, format, &c1, &c3);
  int16_t res2 = sscanf(str, format, &c2, &c4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sscanf_s(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_S=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_s_1);
  tcase_add_test(tc, sscanf_spec_s_2);
  tcase_add_test(tc, sscanf_spec_s_3);
  tcase_add_test(tc, sscanf_spec_s_4);
  tcase_add_test(tc, sscanf_spec_s_5);
  tcase_add_test(tc, sscanf_spec_s_6);
  tcase_add_test(tc, sscanf_spec_s_7);
  tcase_add_test(tc, sscanf_spec_s_8);
  tcase_add_test(tc, sscanf_spec_s_9);
  tcase_add_test(tc, sscanf_spec_s_10);
  tcase_add_test(tc, sscanf_spec_s_11);

  suite_add_tcase(s, tc);
  return s;
}