#include "test_main.h"

// One parameter string
START_TEST(sprintf_1_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %s Test";
  char *val = "Here is a copy of the drawing!";
  ck_assert_int_eq(sprintf(str1, str3, val), my_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three string parameters
START_TEST(sprintf_2_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "In the book it said:";
  char *val2 = "Boa constrictors swallow their prey whole";
  char *val3 = ", without chewing it.";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "called True Stories from Nature";
  char *val2 = "about the primeval forest";
  char *val3 = "KEK";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Different sizes WCHAR FOR LATER
START_TEST(sprintf_4_string) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %ls Test2";
  wchar_t *val = L"3wtf80";
  ck_assert_int_eq(sprintf(str1, str3, val), my_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%3s Test %5s Test %10s";
  char *val = "After that they";
  char *val2 = "swallowing an animal";
  char *val3 = "KEK";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   my_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5s Test %.23s Test %3.s TEST %.s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%-010s Test %-8s Test %-7s TEST %-s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %0s Test %00s TEST %-0s GOD %s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   my_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3s Test %+5s TEST %10s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   my_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%s Test %3.s Test %5.7s TEST %10s %#s %-s %+s %.s % .s";
  char *val = NULL;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      my_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_11_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3s Test %+05s TEST %+10s GOD %+s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   my_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_12_string) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test % 3s Test % -5s TEST % +10s GOD % +-0s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   my_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Hash
START_TEST(sprintf_13_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%#s Test %#3s Test %#5.7s TEST %#.7s Oof %#.s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   my_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // ZERO flag
START_TEST(sprintf_14_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %06s Test %05.7s TEST %0.7s Oof %0.s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   my_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%*s Test %-*s Test %*.*s TEST %.*s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
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

START_TEST(sprintf_16_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s %s %s %% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "string";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val4, val3),
                   my_sprintf(str2, str3, val, val2, val4, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_string) {
  char str1[1024];
  char str2[1024];
  char *str3 =
      "%0.0s %1.0s %2.0s %3.0s %5.0s %6.0s %7.0s %0.3s %0.7s %3.2s %3.7s %7.3s";
  char *val = NULL;
  my_sprintf(str2, str3, val, val, val, val, val, val, val, val, val, val, val,
              val);
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val, val, val,
          val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_string) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %ls Test2";
  wchar_t *val = L"3wtf80";
  ck_assert_int_eq(sprintf(str1, str3, val), my_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_string) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test %s Test %s Test %s";
  char *c = "";
  char *c1 = "\n";
  char *c2 = "\t";
  char *c3 = "\0";
  ck_assert_int_eq(sprintf(str1, str3, c, c1, c2, c3),
                   my_sprintf(str2, str3, c, c1, c2, c3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_string) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test % 3.s Test % 5.7s TEST % 10s GOD %.s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   my_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%.*s Test %*.s Test";
  char *val = "97";
  char *val2 = "97";
  int ast = -10;
  int ast2 = -10;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%.*s Test %*.s Test";
  char *val = "97";
  char *val2 = "97";
  int ast = -10;
  int ast2 = -10;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
                   my_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_string(void) {
  Suite *s = suite_create("\033[45m-=my_SPRINTF_STRING=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_string);
  tcase_add_test(tc, sprintf_2_string);
  tcase_add_test(tc, sprintf_3_string);
  tcase_add_test(tc, sprintf_4_string);  // WCHAR
  tcase_add_test(tc, sprintf_5_string);
  tcase_add_test(tc, sprintf_6_string);
  tcase_add_test(tc, sprintf_7_string);
  tcase_add_test(tc, sprintf_8_string);
  tcase_add_test(tc, sprintf_9_string);
  tcase_add_test(tc, sprintf_10_string);
  tcase_add_test(tc, sprintf_11_string);
  tcase_add_test(tc, sprintf_12_string);
  tcase_add_test(tc, sprintf_13_string);
  tcase_add_test(tc, sprintf_14_string);
  tcase_add_test(tc, sprintf_15_string);
  tcase_add_test(tc, sprintf_16_string);
  tcase_add_test(tc, sprintf_17_string);
  tcase_add_test(tc, sprintf_23_string);
  tcase_add_test(tc, sprintf_24_string);
  tcase_add_test(tc, sprintf_25_string);
  tcase_add_test(tc, sprintf_26_string);
  tcase_add_test(tc, sprintf_27_string);
  suite_add_tcase(s, tc);
  return s;
}
