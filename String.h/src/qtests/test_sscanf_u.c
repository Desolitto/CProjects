#include "test_main.h"

/*-----UNSIGNED-----*/
START_TEST(test_uint_dec_simple) {
  char *str = "16498 8196516519 0123456777";
  char *format = "%u %u %u";
  unsigned int a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_uint_dec_neg) {
  char *str = "16498 -8196516519 -0123456777";
  char *format = "%u %u %u";
  unsigned int a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_uint_dec_max) {
  char *str = "0 18446744073709551615 459494";
  char *format = "%llu %llu %llu";
  unsigned long long a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_uint_dec_skip_width) {
  char *str = "0 18446744073709551615 184467440737095516157878";
  char *format = "%*u %*9lu %llu %*19llu %1llu %llu";
  unsigned long long a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_uint_dec_short) {
  char *str = "-1215 6896 89849 16181 89651685425989 598";
  char *format = "%*hu %*9lu %hu %*19llu %hu %1hu";
  unsigned short a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int res2 = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(uint2) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                         d2 = 0;
  const char str[] = "-1337 233333331 5008 3000";
  const char fstr[] = "%1llu %2llu %5llu %4llu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint3) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long long d1 = 0, d2 = 0;

  const char str[] =
      "\t\t\t\t\t\n 3      adsfdfa%$$$$`adfasdfasdfaszcvzcxvcv -1337 "
      "anurobich+ 21 -5008 -33000 0.3333";
  const char fstr[] = "%*s %*s %llu %s %llu %llu %lld";

  char s1[100000] = {'\0'};
  char s2[100000] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, &a1, s1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, s2, &b2, &c2, &d2);

  ck_assert_uint_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_parse_uint) {
  unsigned int a = 0, b = 0;
  unsigned long la = 0, lb = 0;
  unsigned long long lla = 0, llb = 0;

  ck_assert_int_eq(s21_sscanf("1234567890", "%u", &a),
                   sscanf("1234567890", "%u", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("12345678901", "%u", &a),
                   sscanf("12345678901", "%u", &b));
  ck_assert_int_eq(a, b);

  // переполнение
  ck_assert_int_eq(s21_sscanf("123456789012345678901", "%llu", &lla),
                   sscanf("123456789012345678901", "%llu", &llb));
  ck_assert_int_eq(la, lb);

  ck_assert_int_eq(s21_sscanf("12345678901234567890123", "%22llu", &lla),
                   sscanf("12345678901234567890123", "%22llu", &llb));
  ck_assert_int_eq(la, lb);

  unsigned short sa = 0, sb = 0;
  ck_assert_int_eq(s21_sscanf("1234567890", "%5hu%lu", &sa, &la),
                   sscanf("1234567890", "%5hu%lu", &sb, &lb));
  ck_assert_int_eq(sa, sb);
  ck_assert_int_eq(la, lb);

  // слишком широкий спецификатор
  ck_assert_int_eq(s21_sscanf("123", "%5u", &a), sscanf("123", "%5u", &b));
  ck_assert_int_eq(a, b);

  // -
  ck_assert_int_eq(s21_sscanf("-123", "%u", &a), sscanf("-123", "%u", &b));
  ck_assert_int_eq(a, b);

  // +
  ck_assert_int_eq(s21_sscanf("+123", "%u", &a), sscanf("+123", "%u", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+123", "%*2u%u", &a),
                   sscanf("+123", "%*2u%u", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

Suite *test_sscanf_u(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_U=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, test_uint_dec_simple);
  tcase_add_test(tc, test_uint_dec_neg);
  tcase_add_test(tc, test_uint_dec_max);
  tcase_add_test(tc, test_uint_dec_skip_width);
  tcase_add_test(tc, test_uint_dec_short);
  tcase_add_test(tc, uint2);
  tcase_add_test(tc, uint3);
  tcase_add_test(tc, test_parse_uint);

  suite_add_tcase(s, tc);
  return s;
}