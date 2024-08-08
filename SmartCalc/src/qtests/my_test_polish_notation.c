#include "my_calc_test.h"

START_TEST(my_infix_to_postfix_1) {
  char from_str[] = "2*3";
  char to_str[MAX_LEN] = "\0";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "2 3 * ");
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_2) {
  char from_str[] = "25 + 25";
  char to_str[MAX_LEN] = "\0";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "25 25 + ");
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_3) {
  char from_str[] = "cos(4)+sin(15)";
  char to_str[MAX_LEN] = "\0";

  int is_error = my_infix_to_postfix(from_str, to_str);
  ck_assert_str_eq(to_str, "4 c 15 s + ");
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_4) {
  char from_str[] = "3.1415-21/42+12*tan(5)";
  char to_str[MAX_LEN] = "\0";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "3.1415 21 42 / - 12 5 t * + ");
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_5) {
  char from_str[] = "10+5*2-8/4";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "10 5 2 * + 8 4 / - ");
  ck_assert_int_eq(is_error, 0);
}
// 16 sqrt 3 2 ^ +
START_TEST(my_infix_to_postfix_6) {
  char from_str[] = "sqrt(16)+3^2";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "16 q 3 2 ^ + ");
  ck_assert_int_eq(is_error, 0);
}

// 2 30 sin * 4 60 cos * + 45 tan -
START_TEST(my_infix_to_postfix_7) {
  char from_str[] = "2*sin(30)+4*cos(60)-tan(45)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "2 30 s * 4 60 c * + 45 t - ");
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_8) {
  char from_str[] = "log(100)-sqrt(25)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "100 L 25 q - ");
  ck_assert_int_eq(is_error, 0);
}

// 1 2 + 3 4 * 5 2 ^ / - 6 30 sin * +
START_TEST(my_infix_to_postfix_9) {
  char from_str[] = "1+2-3*4/5^2+6*sin(30)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "1 2 + 3 4 * 5 2 ^ / - 6 30 s * + ");
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_10) {
  char from_str[] = "log(10)-sqrt(9)*tan(45)/sin(30)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "10 L 9 q 45 t * 30 s / - ");
  ck_assert_int_eq(is_error, 0);
}

// 3.14 2.71 + 1.618 4 * 2 3 ^ / - 16 sqrt 45 cos * + x 4 / tan +
START_TEST(my_infix_to_postfix_11) {
  char from_str[] = "3.14+2.71-1.618*4/2^3+sqrt(16)*cos(45)+tan(x/4)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str,
                   "3.14 2.71 + 1.618 4 * 2 3 ^ / - 16 q 45 c * + x 4 / t + ");
  //                        3.14 2.71 + 1.618 4 * 2 3 ^ / - 16 q 45 c * + x 4 /
  //                        t + 3.14 2.71 + 1.618 4 * 2 3 ^ / - 16 q 45 c * + 4
  //                        / t +

  ck_assert_int_eq(is_error, 0);
}

// 45 sin 60 cos + 30 tan 100 log * 1 acos / - 25 sqrt 2 ^ +
START_TEST(my_infix_to_postfix_12) {
  char from_str[] = "sin(45)+cos(60)-tan(30)*log(100)/acos(1)+sqrt(25)^2";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "45 s 60 c + 30 t 100 L * 1 C / - 25 q 2 ^ + ");

  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_13) {
  char from_str[] = "sqrt(4)+log(100)*tan(x/4)/sin(30)+cos(x/3)^2";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "4 q 100 L x 4 / t * 30 s / + x 3 / c 2 ^ + ");

  ck_assert_int_eq(is_error, 0);
}

// 1 2 + 3 4 * 5 2 ^ / - 6 x 6 / sin * + 7 x 3 / cos * - 8 x 4 / tan * +
START_TEST(my_infix_to_postfix_14) {
  char from_str[] = "1+2-3*4/5^2+6*sin(x/6)-7*cos(x/3)+8*tan(x/4)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(
      to_str,
      "1 2 + 3 4 * 5 2 ^ / - 6 x 6 / s * + 7 x 3 / c * - 8 x 4 / t * + ");
  ck_assert_int_eq(is_error, 0);
}

// 10 log 9 sqrt x acos 4 / tan * 4 log 6 / sin / - 4 3 3 / % cos 2 ^ + 10 atan
// 2 / sin -
START_TEST(my_infix_to_postfix_15) {
  char from_str[] =
      "log(10)-sqrt(9)*tan(acos(x)/4)/sin(ln(4)/6)+cos(4mod3/3)^2-sin(atan(10)/"
      "2)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(
      to_str,
      "10 L 9 q x C 4 / t * 4 l 6 / s / - 4 3 m 3 / c 2 ^ + 10 T 2 / s - ");
  ck_assert_int_eq(is_error, 0);
}

// 10 log 9 sqrt x acos 4 / tan * 4 log 6 / sin / - 4 3 % 3 / cos 2 ^ + 10 atan
// 2 / sin -
START_TEST(my_infix_to_postfix_16) {
  char from_str[] =
      "log(10)-sqrt(9)*tan(acos(x)/4)/sin(ln(4)/6)+cos((4mod3)/"
      "3)^2-sin(atan(10)/2)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(
      to_str,
      "10 L 9 q x C 4 / t * 4 l 6 / s / - 4 3 m 3 / c 2 ^ + 10 T 2 / s - ");
  ck_assert_int_eq(is_error, 0);
}

// 25 sqrt 2 ^
START_TEST(my_infix_to_postfix_17) {
  char from_str[] = "sqrt(25)^2";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "25 q 2 ^ ");
  ck_assert_int_eq(is_error, 0);
}

// 2 3 ^ 4 ^
START_TEST(my_infix_to_postfix_18) {
  char from_str[] = "2^3^4";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "2 3 ^ 4 ^ ");
  ck_assert_int_eq(is_error, 0);
}

// 1 3 * -
START_TEST(my_infix_to_postfix_19) {
  char from_str[] = "-1*3";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "0 1 3 * - ");
  ck_assert_int_eq(is_error, 0);
}

// 1 3 * -
START_TEST(my_infix_to_postfix_20) {
  char from_str[] = "(-1)*3";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "0 1 - 3 * ");
  ck_assert_int_eq(is_error, 0);
}

// 1 3 * -
START_TEST(my_infix_to_postfix_21) {
  char from_str[] = "3*(-1)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "3 0 1 - * ");
  ck_assert_int_eq(is_error, 0);
}

// 1 22.21 / 2 3 + 9 2 - 2 + 6 7 / - / +
START_TEST(my_infix_to_postfix_22) {
  char from_str[] = "1/22.21+(2+3)/((9-2)+2-6/7)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "1 22.21 / 2 3 + 9 2 - 2 + 6 7 / - / + ");

  ck_assert_int_eq(is_error, 0);
}

// 1 2 / - 0 2 - 3 + 0 9 + 2 - sin 2 ^ - 6 7 / - / +
START_TEST(my_infix_to_postfix_23) {
  char from_str[] = "1/2+(2+3)/(sin(9-2)^2-6/7)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "1 2 / 2 3 + 9 2 - s 2 ^ 6 7 / - / + ");
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_24) {
  char from_str[] = "(-1)/2+(2+3)/(sin(9-2)^2-6/7)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "0 1 - 2 / 2 3 + 9 2 - s 2 ^ 6 7 / - / + ");

  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_25) {
  char from_str[] = "-1/2+(2+3)/(sin(9-2)^2-6/7)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "0 1 2 / - 2 3 + 9 2 - s 2 ^ 6 7 / - / + ");
  //                        0 1 2 /-2 3 +9 2 -s2 ^6 7 /-/+

  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_26) {
  char from_str[] = "+cos(4mod3/3)^2";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "4 3 m 3 / c 2 ^ ");
  //                        4 3 m 3 / c 2 ^

  ck_assert_int_eq(is_error, 0);
}

//(sin(30)*sqrt(625)+cos(60)*ln(34)+tan(50))/(asin(0.5)^(2)+acos(-(0.5))*log(100)+atan(0.5))
START_TEST(my_infix_to_postfix_27) {
  char from_str[] =
      "(sin(30)*sqrt(625)+cos(60)*ln(34)+tan(50))/"
      "(asin(0.5)^(2)+acos(-(0.5))*log(100)+atan(0.5))";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str,
                   "30 s 625 q * 60 c 34 l * + 50 t + 0.5 S 2 ^ 0 0.5 - C 100 "
                   "L * + 0.5 T + / ");
  //                        30 s 625 q * 60 c 34 l * + 50 t + 0.5 S 2 ^ 0 0.5 -
  //                        C 100 L * + 0.5 T + / 30 s 625 q 60 C 34 L * * 50 T
  //                        + 0.5 S 2 0.5 ^ + C 100 L * - 0.5 T + / +

  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_28) {
  char from_str[] = "3mod(2)";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "3 2 m ");
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_infix_to_postfix_29) {
  char from_str[] = "asin(0.5)^(2)+acos(-(0.5))";
  char to_str[MAX_LEN] = "";
  int is_error = my_infix_to_postfix(from_str, to_str);

  ck_assert_str_eq(to_str, "0.5 S 2 ^ 0 0.5 - C + ");
  //                        0.5 S 2 ^ 0 0.5 - C +

  ck_assert_int_eq(is_error, 0);
}

Suite *test_polish_notation(void) {
  Suite *s = suite_create("\033[45m-=my_infix_to_postfix=-\033[0m");
  TCase *tc = tcase_create("case_my_infix_to_postfix");

  tcase_add_test(tc, my_infix_to_postfix_1);
  tcase_add_test(tc, my_infix_to_postfix_2);
  tcase_add_test(tc, my_infix_to_postfix_3);
  tcase_add_test(tc, my_infix_to_postfix_4);
  tcase_add_test(tc, my_infix_to_postfix_5);
  tcase_add_test(tc, my_infix_to_postfix_6);
  tcase_add_test(tc, my_infix_to_postfix_7);
  tcase_add_test(tc, my_infix_to_postfix_8);
  tcase_add_test(tc, my_infix_to_postfix_9);
  tcase_add_test(tc, my_infix_to_postfix_10);
  tcase_add_test(tc, my_infix_to_postfix_11);
  tcase_add_test(tc, my_infix_to_postfix_12);
  tcase_add_test(tc, my_infix_to_postfix_13);
  tcase_add_test(tc, my_infix_to_postfix_14);
  tcase_add_test(tc, my_infix_to_postfix_15);
  tcase_add_test(tc, my_infix_to_postfix_16);
  tcase_add_test(tc, my_infix_to_postfix_17);
  tcase_add_test(tc, my_infix_to_postfix_18);
  tcase_add_test(tc, my_infix_to_postfix_19);
  tcase_add_test(tc, my_infix_to_postfix_20);
  tcase_add_test(tc, my_infix_to_postfix_21);
  tcase_add_test(tc, my_infix_to_postfix_22);
  tcase_add_test(tc, my_infix_to_postfix_23);
  tcase_add_test(tc, my_infix_to_postfix_24);
  tcase_add_test(tc, my_infix_to_postfix_25);
  tcase_add_test(tc, my_infix_to_postfix_26);
  tcase_add_test(tc, my_infix_to_postfix_27);
  tcase_add_test(tc, my_infix_to_postfix_28);
  tcase_add_test(tc, my_infix_to_postfix_29);

  suite_add_tcase(s, tc);
  return s;
}