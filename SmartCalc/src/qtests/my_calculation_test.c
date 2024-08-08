#include "my_calc_test.h"

START_TEST(calculateRPN_1) {
  char from_str[] = "2*3";
  char to_str[MAX_LEN] = "\0";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);
  ck_assert_ldouble_eq(num, 6);
  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_2) {
  char from_str[] = "2+2*2/2-2";
  char to_str[MAX_LEN] = "\0";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);
  ck_assert_ldouble_eq(num, 2);
  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_3) {
  char from_str[] = "3.1415-21/42+12*tan(5)";
  char to_str[MAX_LEN] = "\0";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);
  ck_assert_ldouble_eq_tol(num, -37.924680074959, 1e-8);
  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_4) {
  char from_str[] = "log(10)-sqrt(9)*tan(45)/sin(30)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;

  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 5.9181882979634349, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_5) {
  char from_str[] = "-1/2+(2+3)/(sin(9-2)^2-6/7)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, -12.2505646653956, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_6) {
  char from_str[] = "sin(45)+cos(60)-tan(30)*log(100)/cos(180)+sqrt(25)^2";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 3.49244684021724, 1e-8);
  ck_assert_int_eq(is_error_calc, OK);
}

// 16 sqrt 3 2 ^ +
START_TEST(calculateRPN_7) {
  char from_str[] = "sqrt(16)+3^2";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 13, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_8) {
  char from_str[] = "2*sin(30)+4*cos(60)-tan(45)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, -7.40549036039, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_9) {
  char from_str[] = "log(100)-sqrt(25)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, -3, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_10) {
  char from_str[] = "1+2-3*4/5^2+6*sin(30)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, -3.408189744558, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_11) {
  char from_str[] = "log(10)-sqrt(9)*tan(45)/sin(30)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;

  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 5.9181882979637, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_12) {
  char from_str[] = "3.14+2.71-1.618*4/2^3+sqrt(16)*cos(45)+tan(10/4)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 6.395265658033, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_13) {
  char from_str[] = "sqrt(4)+log(100)*tan(10/4)/sin(30)+cos(10/3)^2";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 4.4758263356786238, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_14) {
  char from_str[] = "1+2-3*4/5^2+6*sin(10/6)-7*cos(10/3)+8*tan(10/4)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 9.38798740157886, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_15) {
  char from_str[] = "sqrt(25)^2";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 25, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_16) {
  char from_str[] = "2^3^4";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 4096, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_17) {
  char from_str[] = "-1*3";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, -3, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_18) {
  char from_str[] = "1/22.21+(2+3)/((9-2)+2-6/7)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 0.6590598513392892, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_19) {
  char from_str[] = "1/2+(2+3)/(sin(9-2)^2-6/7)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, -11.2505646654032192, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_20) {
  char from_str[] = "(-1)/2+(2+3)/(sin(9-2)^2-6/7)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, -12.2505646654032192, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_21) {
  char from_str[] = "asin(0.5)^(2)+acos(-(0.5))";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);
  ck_assert_double_eq_tol(num, 2.3685507802007248, 1e-8);
  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_22) {
  char from_str[] = "atan(30)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 1.537475330917, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_23) {
  char from_str[] = "asin(1)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 1.570796326795, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_24) {
  char from_str[] = "(6/2)mod(3*2)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 3, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_25) {
  char from_str[] = "ln(234567)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 12.3654965403456317, 1e-8);

  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_26) {
  char from_str[] = "(sin(30)*sqrt(625)+cos(60)*ln(34)+tan(50))";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);
  ck_assert_double_eq_tol(num, -28.3312427515904812, 1e-8);
  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_27) {
  char from_str[] = "((asin(0.5)^(2)+acos(-(0.5))))";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, 2.3685507802007248, 1e-8);
  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_28) {
  char from_str[] =
      "(sin(30)*sqrt(625)+cos(60)*ln(34)+tan(50))/"
      "(asin(0.5)^(2)+acos(-(0.5))*log(100)+atan(0.5))";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);

  ck_assert_double_eq_tol(num, -5.7506759589413, 1e-8);
  //                              -28.3312427515904812 / 4.9265934915947248
  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_29) {
  char from_str[] = "((asin(x)^(2)+acos(-(x))))";
  double x = 0.5;
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, x);

  ck_assert_double_eq_tol(num, 2.3685507802007248, 1e-8);
  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(calculateRPN_30) {
  char from_str[] =
      "log(10)-sqrt(9)*tan(acos(x)/4)/sin(ln(4)/6)+cos((4mod3)/"
      "3)^2-sin(atan(10)/2)";
  double x = 0.0;
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, x);

  ck_assert_double_eq_tol(num, -4.2044679007516385, 1e-8);
  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(err_calculateRPN_1) {
  char from_str[] = "1/acos(1)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);
  ck_assert_int_eq(is_error_calc, DIV_BY_ZERO);
}

START_TEST(err_calculateRPN_2) {
  char from_str[] = "acos(-2)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);
  ck_assert_int_eq(is_error_calc, CALCULATION_ERROR);
}

START_TEST(err_calculateRPN_3) {
  char from_str[] = "asin(2)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);
  ck_assert_int_eq(is_error_calc, CALCULATION_ERROR);
}

START_TEST(err_calculateRPN_4) {
  char from_str[] = "ln(-2)-log(-10)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);
  ck_assert_int_eq(is_error_calc, CALCULATION_ERROR);
}
START_TEST(err_calculateRPN_5) {
  char from_str[] = "log(-10)";
  char to_str[MAX_LEN] = "";
  my_infix_to_postfix(from_str, to_str);
  double num = 0.0;
  int is_error_calc = calculateRPN(to_str, &num, 0);
  ck_assert_int_eq(is_error_calc, CALCULATION_ERROR);
}

START_TEST(full_calcuation_0) {
  char from_str[] = "asin(1)";
  double num = 0.0;
  int is_error_calc = full_calcuation(from_str, &num, 0);
  ck_assert_double_eq_tol(num, 1.570796326795, 1e-8);
  ck_assert_int_eq(is_error_calc, OK);
}

START_TEST(full_calcuation_1) {
  char from_str[] = "2+2*2/2-2";
  double num = 0.0;
  int is_error_calc = full_calcuation(from_str, &num, 0);
  ck_assert_double_eq_tol(num, 2, 1e-8);
  ck_assert_int_eq(is_error_calc, OK);
}

Suite *suite_calc_str(void) {
  Suite *s = suite_create("\033[45m-=suite_calc_str=-\033[0m");
  TCase *tc = tcase_create("case_calc_str");

  tcase_add_test(tc, calculateRPN_1);
  tcase_add_test(tc, calculateRPN_2);
  tcase_add_test(tc, calculateRPN_3);
  tcase_add_test(tc, calculateRPN_4);
  tcase_add_test(tc, calculateRPN_5);
  tcase_add_test(tc, calculateRPN_6);
  tcase_add_test(tc, calculateRPN_7);
  tcase_add_test(tc, calculateRPN_8);
  tcase_add_test(tc, calculateRPN_9);
  tcase_add_test(tc, calculateRPN_10);
  tcase_add_test(tc, calculateRPN_11);
  tcase_add_test(tc, calculateRPN_12);
  tcase_add_test(tc, calculateRPN_13);
  tcase_add_test(tc, calculateRPN_14);
  tcase_add_test(tc, calculateRPN_15);
  tcase_add_test(tc, calculateRPN_16);
  tcase_add_test(tc, calculateRPN_17);
  tcase_add_test(tc, calculateRPN_18);
  tcase_add_test(tc, calculateRPN_19);
  tcase_add_test(tc, calculateRPN_20);
  tcase_add_test(tc, calculateRPN_21);
  tcase_add_test(tc, calculateRPN_22);
  tcase_add_test(tc, calculateRPN_23);
  tcase_add_test(tc, calculateRPN_24);
  tcase_add_test(tc, calculateRPN_25);
  tcase_add_test(tc, calculateRPN_26);
  tcase_add_test(tc, calculateRPN_27);
  tcase_add_test(tc, calculateRPN_28);
  tcase_add_test(tc, calculateRPN_29);
  tcase_add_test(tc, calculateRPN_30);

  ///
  tcase_add_test(tc, err_calculateRPN_1);
  tcase_add_test(tc, err_calculateRPN_2);
  tcase_add_test(tc, err_calculateRPN_3);
  tcase_add_test(tc, err_calculateRPN_4);
  tcase_add_test(tc, err_calculateRPN_5);
  ///
  tcase_add_test(tc, full_calcuation_0);
  tcase_add_test(tc, full_calcuation_1);

  suite_add_tcase(s, tc);
  return s;
}