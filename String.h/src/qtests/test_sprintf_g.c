#include "test_main.h"

START_TEST(sprintf_1_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %g TEST %g TEST %g TEST %g!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   my_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.4g!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   my_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%25.18g TEST\n%.6g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   my_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%.2g TEST\n%.3g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   my_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = 0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   my_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   my_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   my_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.0g TEST %4.2g TEST %4.g TEST %5.10g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   my_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %15.1g\ntest: %16.2g\ntest: %18.3g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %10.4g\ntest: %25.5g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-#15.g\ntest: %-26.1g\ntest: %-18.0g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#-10.g\ntest: %-+25.g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// 13
START_TEST(sprintf_13_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%6g TEST %.2g TEST %4.5g TEST %4.3g TEST %5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   my_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   my_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   my_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// 16
START_TEST(sprintf_16_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10g\n%20.15g\n%-20.5g!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// 17
START_TEST(sprintf_17_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg\n%+-#Lg\n%+#.Lg\n%-#.Lg!";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   my_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g!\ntest: %26.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g!\ntest: %26.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g!\ntest: %-020g!\ntest: %+025g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5g!\ntest: %- 020.4g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_24_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g!\ntest: %-020g!\ntest: %+025g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5g!\ntest: %- 020.4g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %015g!\ntest: %-026g!\ntest: %+018g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 010.2g!\ntest: %- 025.7g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg!\ntest: % -26.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 30.15Lg!\ntest: %+ 50.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +40.15Lg\ntest: % +-25.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg!\ntest: % -26.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 30.13Lg!\ntest: %+ 50.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +40.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num), my_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.6Lg!\ntest: %.Lg!";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.g!\ntest: %.2g!\ntest: %.3g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.10g!\ntest: %.6g!\ntest: %.g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-20.13g!\ntest: %-25.7g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-.15g!\ntest: %-16g!\ntest: %- 13.5g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+20.13g!\ntest: %+25.7g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+.15g!\ntest: %+16g!\ntest: %+ 13.5g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.12Lg!\ntest: %.6Lg!\ntest: %.9Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %g!\n";
  double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), my_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_45_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lg!\ntest: %Lg!\n";
  long double num = NAN;
  long double num1 = 1.;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   my_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_46_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 13.0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_47_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 1.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_48_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 0.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   my_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_49_g) {
  char str1[400];
  char str2[400];
  char *str3 =
      "test: %Lg! test: %.2Lg! test: %.3Lg!\n test: %Lg! test: %.2Lg! test: "
      "%.3Lg!";
  long double num = 0.12;
  long double num1 = 2.12;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num1, num1, num1),
                   my_sprintf(str2, str3, num, num, num, num1, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_50_g) {
  char str1[400];
  char str2[400];
  char *str3 =
      "test: %Lg! test: %.2Lg! test: %.3Lg!\n test: %Lg! test: %.2Lg! test: "
      "%.3Lg!";
  long double num = 1.12;
  long double num1 = 2.1;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num1, num1, num1),
                   my_sprintf(str2, str3, num, num, num, num1, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_51_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%Lg = %.Lg = %+-Lg = %+#.Lg\n";
  long double num = 6.789e5;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   my_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_52_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g = %.g = %+-g = %+#.g\n";
  double num = 6.789e5;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   my_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_53_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%GLol %3.G";
  double a1 = 1.4567;
  ck_assert_int_eq(sprintf(str1, str3, a1, a1),
                   my_sprintf(str2, str3, a1, a1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_54_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%5.g %5.g";
  double a1 = 7.8988765;
  double a = 6.675432134567;
  ck_assert_int_eq(sprintf(str1, str3, a1, a), my_sprintf(str2, str3, a1, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_55_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.2Lg!\ntest: %.Lg!";
  long double num = 0.003563245;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   my_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_56_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.6Lg!test: %.Lg!\n    test: %.6Lg!test: %.Lg!\n";
  long double num = 99999.9;
  long double num2 = 100000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num2, num2),
                   my_sprintf(str2, str3, num, num, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_57_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.13Lg!test: %+-0.Lg!\n    test: %.13Lg!test: %+-0.Lg!\n";
  long double num = 99999.9;
  long double num2 = 100000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num2, num2),
                   my_sprintf(str2, str3, num, num, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_58_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.4Lg!test: %.1Lg!\n    test: %.0Lg!test: %.1Lg!\n";
  long double num = 999.9;
  long double num2 = 100000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num2, num2),
                   my_sprintf(str2, str3, num, num, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_59_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.4Lg!test: %.1Lg!\n    test: %.0Lg!test: %.1Lg!\n";
  long double num = 999.9;
  long double num2 = 100000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num2, num2),
                   my_sprintf(str2, str3, num, num, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_60_g) {
  char str1[400];
  char str2[400];
  char *str3 =
      "test: %+-010.4Lg!test: %#13.1Lg!\n    test: %15.6Lg!test: %#.6Lg!\n";
  long double num = 999.9;
  long double num2 = 100000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num2, num2),
                   my_sprintf(str2, str3, num, num, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_61_g) {
  char str1[400];
  char str2[400];
  char *str3 =
      "test: %+-010.4Lg!test: %#13.1Lg!\n    test: %15.6Lg!test: %#.6Lg!\n";
  long double num = 999.9;
  long double num2 = 100000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num2, num2),
                   my_sprintf(str2, str3, num, num, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_62_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+-10.3G!test: %#G!\n    test: %+30.*Lg!test: %-#*.*g!\n";
  int a = 1;
  int width = 10, precision = 2;
  double num = -22.25600;
  double num1 = 0.0000000000001;
  long double num2 = 1234567.2345678;
  double num3 = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, num, num1, a, num2, width, precision, num3),
      my_sprintf(str2, str3, num, num1, a, num2, width, precision, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_63_g) {
  char str1[400];
  char str2[400];
  char *str3 =
      "test: %+-10.3G!test: %#g!\n    test: %+30.*Lg!test: %-#10.*g!\n";
  int a = 12;
  int precision = 2;
  double num = -22.25600;
  double num1 = 0.0000000000001;
  long double num2 = 1234567.2345678;
  double num3 = 0.0;
  ck_assert_int_eq(
      sprintf(str1, str3, num, num1, a, num2, precision, num3),
      my_sprintf(str2, str3, num, num1, a, num2, precision, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_64_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+-10.3G!test: %#G!\n    test: %+30.*Lg!test: %-#*.*g!\n";
  int a = 1;
  int width = 10, precision = 2;
  double num = -22.25600;
  double num1 = 0.0000000000001;
  long double num2 = 1234567.2345678;
  double num3 = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, num, num1, a, num2, width, precision, num3),
      my_sprintf(str2, str3, num, num1, a, num2, width, precision, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_65_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test:%-.10G g%010%!\n";
  double num = 999.9;
  long double num2 = 100000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num2, num2),
                   my_sprintf(str2, str3, num, num, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_66_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test:%#LG test:%#LG test:%#LG!\n";
  long double num = 0.;  //любое число
  long double num2 = 1;
  long double num3 = 3;
  ck_assert_int_eq(sprintf(str1, str3, num, num2, num3),
                   my_sprintf(str2, str3, num, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_single) {
  struct input_data {
    const char *format;
    const double n;
  };
  struct input_data testcases[] = {{"%g", 1.23},          {"%%%g", -1.23},
                                   {"%4g", 1.23},         {"%4g", 12.3456},
                                   {"%04g", 1.23},        {"%+4G", 1.23},
                                   {"%+09g", 9000.00},    {"% G", 12.3456},
                                   {"%-4g", 1.23},        {"%+5.5G", 1.23},
                                   {"% 5g", -1.23},       {"%.5G", 1.23},
                                   {"%+10.5g", 1.234445}, {"%-10.5G", 12300000},
                                   {"%.3g", 1.23456},     {"%#G", 1},
                                   {"%%%#g", -123},       {"%#G", 1.10000},
                                   {"%+#g", 12.3456},     {"%0#G", 1.23},
                                   {"%#-4g", 123},        {"%+#05G", 1.23},
                                   {"% #g", 123},         {"%-# 7G", 120000}};
  my_size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (my_size_t i = 0; i < n; i++) {
    char result[256];
    char expected_result[256];
    my_sprintf(result, testcases[i].format, testcases[i].n);
    sprintf(expected_result, testcases[i].format, testcases[i].n);
    ck_assert_pstr_eq(result, expected_result);
  }
}

START_TEST(sprintf_LG_single) {
  struct input_data {
    const char *format;
    const long double n;
  };
  struct input_data testcases[] = {
      {"%Lg", 1.23},          {"%%%Lg", -1.23},
      {"%4Lg", 1.23},         {"%4Lg", 12.3456},
      {"% 04Lg", 0},          {"%+4LG", 1.23},
      {"%+09Lg", 9000.00},    {"% LG", 12.3456},
      {"% -4.4Lg", 1.23},     {"%+5.5LG", 1.23},
      {"% 5Lg", -1.23},       {"%.5LG", 1.23},
      {"%+10.5Lg", 1.234445}, {"%-10.5LG", 12300000},
      {"%4.0Lg", 0},          {"%#LG", 0},
      {"%%%#Lg", -123},       {"% #LG", 1.10000},
      {"%+#Lg", 12.3456},     {"%0#LG", 1.23},
      {"%#-4Lg", 123},        {"%+#05LG", 1.23},
      {"% #Lg", 123},         {"%-# 7LG", 120000}};
  my_size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (my_size_t i = 0; i < n; i++) {
    char result[256];
    char expected_result[256];
    my_sprintf(result, testcases[i].format, testcases[i].n);
    sprintf(expected_result, testcases[i].format, testcases[i].n);
    ck_assert_pstr_eq(result, expected_result);
  }
}
END_TEST

START_TEST(sprintf_feg_single_long) {
  struct input_data {
    const char *format;
    const double n;
  };
  struct input_data testcases[] = {
      {"%f", -340282346638528859811704183484516925440.0000000000000000},
      {"%%%f", 340282346638528859811704183484516925440.0000000000000000},
      {"%4e", -340282346638528859811704183484516925440.0000000000000000},
      {"%4e", 340282346638528859811704183484516925440.0000000000000000},
      {"%04g", -340282346638528859811704183484516925440.0000000000000000},
      {"%+4g", 340282346638528859811704183484516925440.0000000000000000},
      {"%+05f", 340282346638528859811704183484516925439.999999999999},
      {"% .2f", -340282346638528859811704183484516925439.899999999999},
      {"%-4e", 340282346638528859811704183484516925439.999999999999},
      {"%+5.5e", -340282346638528859811704183484516925439.999999999999},
      {"% 5g", 340282346638528859811704183484516925439.999999999999},
      {"%.5g", -340282346638528859811704183484516925439.999999999999},
      {"%+50.10f", 340282346638528859811704183484516925440.0000000000000000},
      {"%-10.0f", -340282346638528859811704183484516925439.444999999999},
      {"%.0e", 340282346638528859811704183484516925439.9999999999},
      {"%#e", -340282346638528859811704183484516925439.999999999999},
      {"%%%#g", 340282346638528859811704183484516925440.0000000000000000},
      {"%50.15g", 000000000000000000000000.0000000000000000},
      {"%+#f", 34028234663852885981170418348451692540.0000000000000000},
      {"%0#f", -340282346638528859811704183484516925439.999999999999},
      {"%#-50.10e", 340282346638528859811704183484516925440.0000000000000000},
      {"%+#05.0e", -340282346638528859811704183484516925439.899999999999},
      {"% #g", 340282346638528859811704183484516925440.0000000000000000},
      {"%-# 7g", -340282346638528859811704183484516925439.999999999999}};
  my_size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (my_size_t i = 0; i < n; i++) {
    char result[256];
    char expected_result[256];
    my_sprintf(result, testcases[i].format, testcases[i].n);
    sprintf(expected_result, testcases[i].format, testcases[i].n);
    ck_assert_pstr_eq(result, expected_result);
  }
}
END_TEST

Suite *test_sprintf_g(void) {
  Suite *s = suite_create("\033[45m-=my_SPRINTF_G=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_g);
  tcase_add_test(tc, sprintf_2_g);
  tcase_add_test(tc, sprintf_3_g);
  tcase_add_test(tc, sprintf_4_g);
  tcase_add_test(tc, sprintf_5_g);
  tcase_add_test(tc, sprintf_6_g);
  tcase_add_test(tc, sprintf_7_g);
  tcase_add_test(tc, sprintf_8_g);
  tcase_add_test(tc, sprintf_9_g);
  tcase_add_test(tc, sprintf_10_g);
  tcase_add_test(tc, sprintf_11_g);
  tcase_add_test(tc, sprintf_12_g);
  tcase_add_test(tc, sprintf_13_g);
  tcase_add_test(tc, sprintf_14_g);
  tcase_add_test(tc, sprintf_15_g);
  tcase_add_test(tc, sprintf_16_g);
  tcase_add_test(tc, sprintf_17_g);
  tcase_add_test(tc, sprintf_18_g);
  tcase_add_test(tc, sprintf_19_g);
  tcase_add_test(tc, sprintf_20_g);
  tcase_add_test(tc, sprintf_21_g);
  tcase_add_test(tc, sprintf_22_g);
  tcase_add_test(tc, sprintf_23_g);
  tcase_add_test(tc, sprintf_24_g);
  tcase_add_test(tc, sprintf_25_g);
  tcase_add_test(tc, sprintf_26_g);
  tcase_add_test(tc, sprintf_27_g);
  tcase_add_test(tc, sprintf_28_g);
  tcase_add_test(tc, sprintf_29_g);
  tcase_add_test(tc, sprintf_30_g);
  tcase_add_test(tc, sprintf_31_g);
  tcase_add_test(tc, sprintf_32_g);
  tcase_add_test(tc, sprintf_33_g);
  tcase_add_test(tc, sprintf_34_g);
  tcase_add_test(tc, sprintf_35_g);
  tcase_add_test(tc, sprintf_36_g);
  tcase_add_test(tc, sprintf_37_g);
  tcase_add_test(tc, sprintf_38_g);
  tcase_add_test(tc, sprintf_39_g);
  tcase_add_test(tc, sprintf_40_g);
  tcase_add_test(tc, sprintf_41_g);
  tcase_add_test(tc, sprintf_42_g);
  tcase_add_test(tc, sprintf_43_g);
  tcase_add_test(tc, sprintf_44_g);
  tcase_add_test(tc, sprintf_45_g);
  tcase_add_test(tc, sprintf_46_g);
  tcase_add_test(tc, sprintf_47_g);
  tcase_add_test(tc, sprintf_48_g);
  tcase_add_test(tc, sprintf_49_g);
  tcase_add_test(tc, sprintf_50_g);
  tcase_add_test(tc, sprintf_51_g);
  tcase_add_test(tc, sprintf_52_g);
  tcase_add_test(tc, sprintf_53_g);
  tcase_add_test(tc, sprintf_54_g);
  tcase_add_test(tc, sprintf_55_g);
  tcase_add_test(tc, sprintf_56_g);
  tcase_add_test(tc, sprintf_57_g);
  tcase_add_test(tc, sprintf_58_g);
  tcase_add_test(tc, sprintf_59_g);
  tcase_add_test(tc, sprintf_60_g);
  tcase_add_test(tc, sprintf_61_g);
  tcase_add_test(tc, sprintf_62_g);
  tcase_add_test(tc, sprintf_63_g);
  tcase_add_test(tc, sprintf_64_g);
  tcase_add_test(tc, sprintf_65_g);
  tcase_add_test(tc, sprintf_66_g);
  tcase_add_test(tc, sprintf_g_single);
  tcase_add_test(tc, sprintf_LG_single);
  tcase_add_test(tc, sprintf_feg_single_long);
  suite_add_tcase(s, tc);
  return s;
}
