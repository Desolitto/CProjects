#include "my_calc_test.h"

// START_TEST(valid_0) {
//     char *str="";
// ck_assert_int_eq(my_valid_str(str), OK);
// }
// END_TEST

START_TEST(my_valid_str_correct_1) {
  char from_str[287] = "2*3";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_valid_str_correct_2) {
  char from_str[287] = "2";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_valid_str_correct_3) {
  char from_str[287] = "+5";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_valid_str_correct_4) {
  char from_str[287] = "+5+(+2)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, 0);
}

//здесь + между скобками - унарный
START_TEST(my_valid_str_correct_5) {
  char from_str[287] = "+5+(+(sin(2))+2)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_valid_str_correct_6) {
  char from_str[287] = "(2)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_valid_str_correct_7) {
  char from_str[287] = "(sin(2+2))";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_valid_str_correct_8) {
  char from_str[287] = "(asin(2))";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_valid_str_correct_9) {
  char from_str[287] = "(+sin(2))";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, 0);
}

START_TEST(my_valid_str_correct_10) {
  char from_str[287] = "2*3/(+2.2)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, 0);
}

//=================
//=================
//=== INCORRECT STR

START_TEST(my_valid_str_incorrect_1) {
  char from_str[287] = "2*-3";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_2) {
  int is_error = my_valid_str(NULL);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_3) {
  char from_str[287] = "2//2";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_4) {
  char from_str[287] = "2/2*";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_5) {
  char from_str[287] = "+5++2";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_6) {
  char from_str[287] = "+5+(*2)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

// СКОБОЧКИ

START_TEST(my_valid_str_incorrect_7) {
  char from_str[287] = "()";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_8) {
  char from_str[287] = "(.)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_9) {
  char from_str[287] = "(2+2))";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_10) {
  char from_str[287] = "((2+2)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_11) {
  char from_str[287] = "(sin(2+2)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_12) {
  char from_str[287] = "(sin(cos(2))";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_13) {
  char from_str[287] = "3sin";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_14) {
  char from_str[287] = "3sin2";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_15) {
  char from_str[287] = "sin2";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_16) {
  char from_str[287] = "(*asin(2))";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_17) {
  char from_str[287] = "asin*(2)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_18) {
  char from_str[287] = "2*3/(2.2+)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(valid_1) {
  char *str = "2+2*2/2-2";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_2) {
  char *str = "5+(5-2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_3) {
  char *str = "3.2*0";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_4) {
  char *str = "2mod2";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_5) {
  char *str = "cos(4)+sin(15)+tan(10)-acos(30)*asin(45)/atan(60)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_6) {
  char *str = "sqrt(4)+log(15)*ln(2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_7) {
  char *str = "x+x/x-x";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_8) {
  char *str = "x";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_9) {
  char *str = "1";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_10) {
  char *str = "+x-(-21)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_11) {
  char *str = "3.2*0.20*0.3";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_12) {
  char *str = "3.14+56*(x)*22";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_13) {
  char *str = "2.123123123+12398172387126387123613412";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_14) {
  char *str = "3.2*0.20*0.3*2mod7+2+sin(sin(2)+2.2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_15) {
  char *str = "(3.2*0.20^0.3*2)mod(7+2+sin(sin(2)+2.2))";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_16) {
  char *str = "(-3.2*0.20^0.3*2)mod(-7+2+sin(sin(2)+2.2))";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_17) {
  char *str = "-3.2*0.20^0.3+atan(asin(acos(tan(cos(sin(2)+2.2)))))";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_18) {
  char *str = "sqrt(sqrt(sqrt(sqrt(sqrt(4)+log(15)*ln(2)))))";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_19) {
  char *str = "ln(2.2)/log(2.2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(valid_20) {
  char *str =
      "1566mod(cos(log(2*sin(2mod(cos(log(2*sin(3*tan(4*cos(5*log(6*sin(7*tan("
      "8*cos(9*log(10*sin(11*tan(12*cos(13*log(14*sin(15*tan(16*cos(17*log(18*"
      "sin(19*tan(20*cos(21*log(22*sin(23*tan(24*cos(25*log(26*sin(27*tan(28*"
      "cos(29))))))))))))))))))))))))))))))))))";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(invalid_0) {
  char *str = NULL;
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_1) {
  char *str = "3.14+mod(x)+(-2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_2) {
  char *str =
      "4*cos(5*log(6*sin(7*tan(8*cos(1566mod(cos(log(2*sin(2mod(cos(log(2*sin("
      "3*tan(4*cos(5*log(6*sin(7*tan(8*cos(9*log(10*sin(11*tan(12*cos(13*log("
      "14*sin(15*tan(16*cos(17*log(18*sin(19*tan(20*cos(21*log(22*sin(23*tan("
      "24*cos(25*log(26*sin(27*tan(28*cos(29)))))))))))))))))))))))))))))))))))"
      "))))";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}

END_TEST

START_TEST(invalid_3) {
  char *str = "3.14+mod(x)+(-2))";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_4) {
  char *str = "((3.14+mod(x)+(-2))";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_5) {
  char *str = "3.14.2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_6) {
  char *str = ".3.14";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_7) {
  char *str = ".x";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_8) {
  char *str = "x.2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_9) {
  char *str = "++2-2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_10) {
  char *str = "^25.213-1";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_11) {
  char *str = "25.213--1";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_12) {
  char *str = "25.213mod-1";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_13) {
  char *str = "25.213-mod1";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_14) {
  char *str = "25.213*mod1";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_15) {
  char *str = "(-3.2*0.20^0.3*2)mod(-7+2+sin(sin(2)+2.2))/";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_16) {
  char *str = "(-3.2*0.20^0.3*2)modx(-7+2+sin(sin(2)+2.2))";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_17) {
  char *str = "sin(sin(2)2.2))";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_18) {
  char *str = "sin(sin(2)2.2))";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_19) {
  char *str = "sin()";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_20) {
  char *str = "xsin()";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_21) {
  char *str = "(2)sin(2222)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_22) {
  char *str = "sin(";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_23) {
  char *str = "asin()";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_24) {
  char *str = "(2)asin(30222)";
  // printf("str %s %d\n",str,my_valid_str(str) );
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_25) {
  char *str = "log()";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_26) {
  char *str = "ln()";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_27) {
  char *str = "8ln()";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_28) {
  char *str = "xlog()";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_29) {
  char *str = "xln()";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_31) {
  char *str = "xsqrt(2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_32) {
  char *str = "(10-2)(2/2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_33) {
  char *str = "(10-2)(2/2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_34) {
  char *str = "(10-2)*(2/2+)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_35) {
  char *str = "xx";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_36) {
  char *str = "(2+x)x";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_37) {
  char *str = "(2)log(30)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_38) {
  char *str = "(2)ln(30)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(invalid_39) {
  char *str = "mod4";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(input_validation_opt_1) {
  char *sample = "2+2*2";
  int res = my_valid_str(sample);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(input_validation_opt_2) {
  char *sample = "2^2^3";
  int res = my_valid_str(sample);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(input_validation_opt_3) {
  char *sample = "cos(4)*sin(3)";
  int res = my_valid_str(sample);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(input_validation_opt_4) {
  char *sample = "3.1415-21/42+12*tan(5)";
  int res = my_valid_str(sample);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(input_validation_opt_5) {
  char *sample = "19+6-659.129+x*(tan(cos(x)))";
  int res = my_valid_str(sample);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(input_validation_opt_6) {
  char *sample = "kakayatonesurazica";
  int res = my_valid_str(sample);
  ck_assert_int_eq(res, INCORRECT_INPUT);
}
END_TEST

START_TEST(input_validation_opt_7) {
  char *sample = "3..15";
  int res = my_valid_str(sample);
  ck_assert_int_eq(res, INCORRECT_INPUT);
}
END_TEST

START_TEST(input_validation_opt_8) {
  char *sample = "1e--16";
  int res = my_valid_str(sample);
  ck_assert_int_eq(res, INCORRECT_INPUT);
}
END_TEST

START_TEST(input_validation_opt_9) {
  char *sample = "29+cos(4)";
  int res = my_valid_str(sample);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(input_validation_opt_10) {
  char *sample = "atan(5)+ln(3)+mod(4)+sqrt()";
  int res = my_valid_str(sample);
  ck_assert_int_eq(res, INCORRECT_INPUT);
}
END_TEST

START_TEST(tokens_devider_opt_1) {
  char *input_data = "+x-(-21)";
  int res = my_valid_str(input_data);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(tokens_devider_opt_2) {
  char *input_data = "3.14+56((x)22)";
  int res = my_valid_str(input_data);
  ck_assert_int_eq(res, INCORRECT_INPUT);
}
END_TEST

START_TEST(my_valid_str_incorrect_19) {
  char from_str[287] = "123+(3\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_20) {
  char from_str[287] = "123x-3\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_21) {
  char from_str[287] = "()\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_22) {
  char from_str[287] = "(123+2)+3)(3+2\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_23) {
  char from_str[287] = "(123+2)+3)3+2\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_24) {
  char from_str[287] = "123()\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_25) {
  char from_str[287] = "123+(-)(+)(*)(3)\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_26) {
  char from_str[287] = "123*(3mod5)-()\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_27) {
  char from_str[287] = "(\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_28) {
  char from_str[287] = "(123+2)+3cos(3)\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_29) {
  char from_str[287] = "(123+2)+3cos(3)\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_30) {
  char from_str[287] = "cos(tan(atan(sin(3+))))\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_31) {
  char from_str[287] = "cos(tan(atan(sin(3+mod5))))\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_32) {
  char from_str[287] = "cos(tan(atan(sin(3+3mod5--3))))\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_33) {
  char from_str[287] = "cos+3\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_34) {
  char from_str[287] = "cos+(3)\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_35) {
  char from_str[287] = "cos(-)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_36) {
  char from_str[287] = "cos(*/+-)";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_37) {
  char from_str[287] = "cos(cos(1.1.2))";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_38) {
  char from_str[287] = "cos(cos(2x))";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_39) {
  char from_str[287] = "123..3-2\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_40) {
  char from_str[287] = "123.3.2\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_41) {
  char from_str[287] = "123.3*.2\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_42) {
  char from_str[287] = "123.3*(.)2\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_43) {
  char from_str[287] = "123.3*(.)2\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_44) {
  char from_str[287] = "123.3+.2\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_45) {
  char from_str[287] = "123.3+32.(3+2)\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_46) {
  char from_str[287] = "123.3+32.cos(3)\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_47) {
  char from_str[287] = "123.3+32.tan(3)\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_48) {
  char from_str[287] = "123.3+32.^3\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_49) {
  char from_str[287] = "3456+^3\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_50) {
  char from_str[287] = "3456+cos(3)-3+-^*/3mod5\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_51) {
  char from_str[287] = "cos(3+2-)\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_52) {
  char from_str[287] = "cos(3+2-3^3mod3.4--3)\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_53) {
  char from_str[287] = "45*(*28+31)\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_54) {
  char input_str[] = {
      "123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+"
      "123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+"
      "123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+123+"
      "123+123+123123+123+123+123+123+123+123+123+123+123+123\0"};
  int is_error = my_valid_str(input_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_55) {
  char from_str[287] = "+\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(my_valid_str_incorrect_56) {
  char from_str[287] = ")\0";
  int is_error = my_valid_str(from_str);
  ck_assert_int_eq(is_error, INCORRECT_INPUT);
}

START_TEST(simple_func_check_valid_0) {
  char *str = "sqrt(2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_1) {
  char *str = "sqrt2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_2) {
  char *str = "log(2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_3) {
  char *str = "log2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_4) {
  char *str = "ln(2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_5) {
  char *str = "ln2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_6) {
  char *str = "2mod2";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_7) {
  char *str = "2mod(2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_8) {
  char *str = "sin(2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_9) {
  char *str = "sin2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_10) {
  char *str = "cos(2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_11) {
  char *str = "cos2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_12) {
  char *str = "tan(2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_13) {
  char *str = "tan2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_14) {
  char *str = "asin(2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_15) {
  char *str = "asin2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_16) {
  char *str = "acos(2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_17) {
  char *str = "acos2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_18) {
  char *str = "atan(2)";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_19) {
  char *str = "atan2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_20) {
  char *str = "sin-(2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_21) {
  char *str = "sin-2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_22) {
  char *str = "sqrt-(2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_23) {
  char *str = "sqrt-2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_24) {
  char *str = "tan-(2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_25) {
  char *str = "tan-2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_26) {
  char *str = "atan-(2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_27) {
  char *str = "atan-2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_28) {
  char *str = "asin-(2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_29) {
  char *str = "asin-2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_30) {
  char *str = "acos-(2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_31) {
  char *str = "acos-2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_32) {
  char *str = "ln-(2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_33) {
  char *str = "ln-2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_34) {
  char *str = "log-(2)";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_35) {
  char *str = "log-2";
  ck_assert_int_eq(my_valid_str(str), INCORRECT_INPUT);
}
END_TEST

START_TEST(simple_func_check_valid_36) {
  char *str = "sin(-cos(2))";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_37) {
  char *str = "sin(cos(2))";
  ck_assert_int_eq(my_valid_str(str), OK);
}
END_TEST

START_TEST(simple_func_check_valid_38) {
  char *str = "78e+10";
  ck_assert_int_eq(my_valid_str(str), SORRY_CANT_CALC_WITH_E);
}
END_TEST

START_TEST(simple_func_check_valid_39) {
  char *str = "2e-1";
  ck_assert_int_eq(my_valid_str(str), SORRY_CANT_CALC_WITH_E);
}
END_TEST

// START_TEST(invalid_41) {
//     char *str= "asin(2)";
// ck_assert_int_eq(my_valid_str(str), OK);
// }
// END_TEST

Suite *suite_valid_str(void) {
  Suite *s = suite_create("\033[45m-=suite_valid_str=-\033[0m");
  TCase *tc = tcase_create("case_valid_str");

  //===== CORRECT STR

  tcase_add_test(tc, my_valid_str_correct_1);
  tcase_add_test(tc, my_valid_str_correct_2);
  tcase_add_test(tc, my_valid_str_correct_3);
  tcase_add_test(tc, my_valid_str_correct_4);
  tcase_add_test(tc, my_valid_str_correct_5);
  tcase_add_test(tc, my_valid_str_correct_6);
  tcase_add_test(tc, my_valid_str_correct_7);
  tcase_add_test(tc, my_valid_str_correct_8);
  tcase_add_test(tc, my_valid_str_correct_9);
  tcase_add_test(tc, my_valid_str_correct_10);

  //=== INCORRECT STR

  tcase_add_test(tc, my_valid_str_incorrect_1);
  tcase_add_test(tc, my_valid_str_incorrect_2);
  tcase_add_test(tc, my_valid_str_incorrect_3);
  tcase_add_test(tc, my_valid_str_incorrect_4);
  tcase_add_test(tc, my_valid_str_incorrect_5);
  tcase_add_test(tc, my_valid_str_incorrect_6);
  tcase_add_test(tc, my_valid_str_incorrect_7);
  tcase_add_test(tc, my_valid_str_incorrect_8);
  tcase_add_test(tc, my_valid_str_incorrect_9);
  tcase_add_test(tc, my_valid_str_incorrect_10);
  tcase_add_test(tc, my_valid_str_incorrect_11);
  tcase_add_test(tc, my_valid_str_incorrect_12);
  tcase_add_test(tc, my_valid_str_incorrect_13);
  tcase_add_test(tc, my_valid_str_incorrect_14);
  tcase_add_test(tc, my_valid_str_incorrect_15);
  tcase_add_test(tc, my_valid_str_incorrect_16);
  tcase_add_test(tc, my_valid_str_incorrect_17);
  tcase_add_test(tc, my_valid_str_incorrect_18);
  tcase_add_test(tc, my_valid_str_incorrect_19);
  tcase_add_test(tc, my_valid_str_incorrect_20);
  tcase_add_test(tc, my_valid_str_incorrect_21);
  tcase_add_test(tc, my_valid_str_incorrect_22);
  tcase_add_test(tc, my_valid_str_incorrect_23);
  tcase_add_test(tc, my_valid_str_incorrect_24);
  tcase_add_test(tc, my_valid_str_incorrect_25);
  tcase_add_test(tc, my_valid_str_incorrect_26);
  tcase_add_test(tc, my_valid_str_incorrect_27);
  tcase_add_test(tc, my_valid_str_incorrect_28);
  tcase_add_test(tc, my_valid_str_incorrect_29);
  tcase_add_test(tc, my_valid_str_incorrect_30);
  tcase_add_test(tc, my_valid_str_incorrect_31);
  tcase_add_test(tc, my_valid_str_incorrect_32);
  tcase_add_test(tc, my_valid_str_incorrect_33);
  tcase_add_test(tc, my_valid_str_incorrect_34);
  tcase_add_test(tc, my_valid_str_incorrect_35);
  tcase_add_test(tc, my_valid_str_incorrect_36);
  tcase_add_test(tc, my_valid_str_incorrect_37);
  tcase_add_test(tc, my_valid_str_incorrect_38);
  tcase_add_test(tc, my_valid_str_incorrect_39);
  tcase_add_test(tc, my_valid_str_incorrect_40);
  tcase_add_test(tc, my_valid_str_incorrect_41);
  tcase_add_test(tc, my_valid_str_incorrect_42);
  tcase_add_test(tc, my_valid_str_incorrect_43);
  tcase_add_test(tc, my_valid_str_incorrect_44);
  tcase_add_test(tc, my_valid_str_incorrect_45);
  tcase_add_test(tc, my_valid_str_incorrect_46);
  tcase_add_test(tc, my_valid_str_incorrect_47);
  tcase_add_test(tc, my_valid_str_incorrect_48);
  tcase_add_test(tc, my_valid_str_incorrect_49);
  tcase_add_test(tc, my_valid_str_incorrect_50);
  tcase_add_test(tc, my_valid_str_incorrect_51);
  tcase_add_test(tc, my_valid_str_incorrect_52);
  tcase_add_test(tc, my_valid_str_incorrect_53);
  tcase_add_test(tc, my_valid_str_incorrect_54);
  tcase_add_test(tc, my_valid_str_incorrect_55);
  tcase_add_test(tc, my_valid_str_incorrect_56);

  tcase_add_test(tc, valid_1);
  tcase_add_test(tc, valid_2);
  tcase_add_test(tc, valid_3);
  tcase_add_test(tc, valid_4);
  tcase_add_test(tc, valid_5);
  tcase_add_test(tc, valid_6);
  tcase_add_test(tc, valid_7);
  tcase_add_test(tc, valid_8);
  tcase_add_test(tc, valid_9);
  tcase_add_test(tc, valid_10);
  tcase_add_test(tc, valid_11);
  tcase_add_test(tc, valid_12);
  tcase_add_test(tc, valid_13);
  tcase_add_test(tc, valid_14);
  tcase_add_test(tc, valid_15);
  tcase_add_test(tc, valid_16);
  tcase_add_test(tc, valid_17);
  tcase_add_test(tc, valid_18);
  tcase_add_test(tc, valid_19);
  tcase_add_test(tc, valid_20);
  ///
  tcase_add_test(tc, invalid_0);
  tcase_add_test(tc, invalid_1);
  tcase_add_test(tc, invalid_2);
  tcase_add_test(tc, invalid_3);
  tcase_add_test(tc, invalid_4);
  tcase_add_test(tc, invalid_5);
  tcase_add_test(tc, invalid_6);
  tcase_add_test(tc, invalid_7);
  tcase_add_test(tc, invalid_8);
  tcase_add_test(tc, invalid_9);
  tcase_add_test(tc, invalid_10);
  tcase_add_test(tc, invalid_11);
  tcase_add_test(tc, invalid_12);
  tcase_add_test(tc, invalid_13);
  tcase_add_test(tc, invalid_14);
  tcase_add_test(tc, invalid_15);
  tcase_add_test(tc, invalid_16);
  tcase_add_test(tc, invalid_17);
  tcase_add_test(tc, invalid_18);
  tcase_add_test(tc, invalid_19);
  tcase_add_test(tc, invalid_20);
  tcase_add_test(tc, invalid_21);
  tcase_add_test(tc, invalid_22);
  tcase_add_test(tc, invalid_23);
  tcase_add_test(tc, invalid_24);
  tcase_add_test(tc, invalid_25);
  tcase_add_test(tc, invalid_26);
  tcase_add_test(tc, invalid_27);
  tcase_add_test(tc, invalid_28);
  tcase_add_test(tc, invalid_29);
  tcase_add_test(tc, invalid_31);  //
  tcase_add_test(tc, invalid_32);
  tcase_add_test(tc, invalid_33);
  tcase_add_test(tc, invalid_34);
  tcase_add_test(tc, invalid_35);
  tcase_add_test(tc, invalid_36);
  tcase_add_test(tc, invalid_37);
  tcase_add_test(tc, invalid_38);
  tcase_add_test(tc, invalid_39);
  // tcase_add_test(tc, invalid_40);
  // tcase_add_test(tc, invalid_41);
  // tcase_add_test(tc, invalid_42);
  // tcase_add_test(tc, invalid_43);

  tcase_add_test(tc, input_validation_opt_1);
  tcase_add_test(tc, input_validation_opt_2);
  tcase_add_test(tc, input_validation_opt_3);
  tcase_add_test(tc, input_validation_opt_4);
  tcase_add_test(tc, input_validation_opt_5);
  tcase_add_test(tc, input_validation_opt_6);
  tcase_add_test(tc, input_validation_opt_7);
  tcase_add_test(tc, input_validation_opt_8);
  tcase_add_test(tc, input_validation_opt_9);
  tcase_add_test(tc, input_validation_opt_10);
  tcase_add_test(tc, tokens_devider_opt_1);
  tcase_add_test(tc, tokens_devider_opt_2);

  ///
  tcase_add_test(tc, simple_func_check_valid_0);  ////sqrt
  tcase_add_test(tc, simple_func_check_valid_1);
  tcase_add_test(tc, simple_func_check_valid_2);
  tcase_add_test(tc, simple_func_check_valid_3);
  tcase_add_test(tc, simple_func_check_valid_4);
  tcase_add_test(tc, simple_func_check_valid_5);
  tcase_add_test(tc, simple_func_check_valid_6);
  tcase_add_test(tc, simple_func_check_valid_7);
  tcase_add_test(tc, simple_func_check_valid_8);
  tcase_add_test(tc, simple_func_check_valid_9);
  tcase_add_test(tc, simple_func_check_valid_10);
  tcase_add_test(tc, simple_func_check_valid_11);
  tcase_add_test(tc, simple_func_check_valid_12);
  tcase_add_test(tc, simple_func_check_valid_13);
  tcase_add_test(tc, simple_func_check_valid_14);
  tcase_add_test(tc, simple_func_check_valid_15);
  tcase_add_test(tc, simple_func_check_valid_16);
  tcase_add_test(tc, simple_func_check_valid_17);
  tcase_add_test(tc, simple_func_check_valid_18);
  tcase_add_test(tc, simple_func_check_valid_19);
  tcase_add_test(tc, simple_func_check_valid_20);  ////sin
  tcase_add_test(tc, simple_func_check_valid_21);  ////sin
  tcase_add_test(tc, simple_func_check_valid_22);  // sqrt
  tcase_add_test(tc, simple_func_check_valid_23);  // sqrt
  tcase_add_test(tc, simple_func_check_valid_24);  ////tan
  tcase_add_test(tc, simple_func_check_valid_25);  ////tan
  tcase_add_test(tc, simple_func_check_valid_26);  ////atan
  tcase_add_test(tc, simple_func_check_valid_27);  ////atan
  tcase_add_test(tc, simple_func_check_valid_28);  ////asin
  tcase_add_test(tc, simple_func_check_valid_29);  ////asin
  tcase_add_test(tc, simple_func_check_valid_30);  ////acos
  tcase_add_test(tc, simple_func_check_valid_31);  ////acos
  tcase_add_test(tc, simple_func_check_valid_32);  // ln
  tcase_add_test(tc, simple_func_check_valid_33);  // ln
  tcase_add_test(tc, simple_func_check_valid_34);  // log
  tcase_add_test(tc, simple_func_check_valid_35);  // log
  tcase_add_test(tc, simple_func_check_valid_36);
  tcase_add_test(tc, simple_func_check_valid_37);
  tcase_add_test(tc, simple_func_check_valid_38);
  tcase_add_test(tc, simple_func_check_valid_39);
  // tcase_add_test(tc, simple_func_check_valid_23);

  // tcase_add_test(tc, my_valid_str_incorrect_16);//(*asin(2))"
  // tcase_add_test(tc, my_valid_str_incorrect_17);//asin*(2)"
  // tcase_add_test(tc, my_valid_str_incorrect_33);//cos
  // tcase_add_test(tc, my_valid_str_incorrect_34);//cos

  suite_add_tcase(s, tc);
  return s;
}
