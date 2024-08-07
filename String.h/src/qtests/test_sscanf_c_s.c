#include "test_main.h"

START_TEST(sscanf_spec_c_2) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_4) {
  char format[] = "%c";
  char str[] = "\t\n\n   \n  \ta";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_5) {
  char format[] = "%c%c%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_6) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  1    2 3 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_7) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_8) {
  char format[] = "%c %*c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c21, c22;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
}
END_TEST

START_TEST(test_parse_string) {
  char buf1[100] = {0}, buf2[100] = {0};
  // %c
  ck_assert_int_eq(s21_sscanf("123", "%c", buf1), sscanf("123", "%c", buf2));
  ck_assert_int_eq(buf1[0], buf2[0]);

  // %s
  ck_assert_int_eq(s21_sscanf("1234567890", "%s", buf1),
                   sscanf("1234567890", "%s", buf2));
  ck_assert_str_eq(buf1, buf2);

  // %s with len
  ck_assert_int_eq(s21_sscanf("abcdefghk", "%5s", buf1),
                   sscanf("abcdefghk", "%5s", buf2));
  ck_assert_str_eq(buf1, buf2);

  // empty string
  ck_assert_int_eq(s21_sscanf("", "%s", buf1), sscanf("", "%s", buf2));
  ck_assert_str_eq(buf1, buf2);

  // two strings with space
  char buf3[100] = {0}, buf4[100] = {0};
  ck_assert_int_eq(s21_sscanf("123 456", "%s %s", buf1, buf3),
                   sscanf("123 456", "%s %s", buf2, buf4));
  ck_assert_str_eq(buf1, buf2);
  ck_assert_str_eq(buf3, buf4);
}
END_TEST

Suite *test_sscanf_c(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_C_S=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_c_2);
  tcase_add_test(tc, sscanf_spec_c_4);
  tcase_add_test(tc, sscanf_spec_c_5);
  tcase_add_test(tc, sscanf_spec_c_6);
  tcase_add_test(tc, sscanf_spec_c_7);
  tcase_add_test(tc, sscanf_spec_c_8);
  tcase_add_test(tc, test_parse_string);

  suite_add_tcase(s, tc);
  return s;
}