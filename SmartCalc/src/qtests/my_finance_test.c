#include "my_calc_test.h"

START_TEST(test_my_credit_calc_ann_1) {
  double loan = 100000.0;
  int loan_term = 12;
  double interest_rate = 5.0;
  double month_payment, total_loan, interest_rate_payment;

  int status =
      my_credit_calc_ann(loan, loan_term, interest_rate, &month_payment,
                          &total_loan, &interest_rate_payment);

  ck_assert_int_eq(status, OK);
  ck_assert_double_le(month_payment, 8561);
  ck_assert_double_le(total_loan, 102729);
  ck_assert_double_le(interest_rate_payment, 2729);
}

START_TEST(test_my_credit_calc_ann_2) {
  double loan = 10000.0;
  int loan_term = 12;
  double interest_rate = 10.0;
  double month_payment, total_loan, interest_rate_payment;

  int status =
      my_credit_calc_ann(loan, loan_term, interest_rate, &month_payment,
                          &total_loan, &interest_rate_payment);

  ck_assert_int_eq(status, OK);
  ck_assert_double_le(month_payment, 8792);
  ck_assert_double_le(total_loan, 105499);
  ck_assert_double_le(interest_rate_payment, 5499);
}
END_TEST

START_TEST(test_my_credit_calc_dif_1) {
  double loan = 10000.0;
  int loan_term = 12;
  double interest_rate = 5.0;
  double total_loan, interest_rate_payment, month_payment_min,
      month_payment_max;

  int status = my_credit_calc_dif(loan, loan_term, interest_rate, &total_loan,
                                   &interest_rate_payment, &month_payment_min,
                                   &month_payment_max);

  ck_assert_int_eq(status, OK);
  ck_assert_double_le(month_payment_max, 8750);
  ck_assert_double_le(month_payment_min, 8368);
  ck_assert_double_le(total_loan, 102708);
  ck_assert_double_le(interest_rate_payment, 2708);
}
END_TEST

START_TEST(test_my_credit_calc_dif_2) {
  double loan = 10000.0;
  int loan_term = 12;
  double interest_rate = 10.0;
  double total_loan, interest_rate_payment, month_payment_min,
      month_payment_max;

  int status = my_credit_calc_dif(loan, loan_term, interest_rate, &total_loan,
                                   &interest_rate_payment, &month_payment_min,
                                   &month_payment_max);

  ck_assert_int_eq(status, OK);
  ck_assert_double_le(month_payment_max, 9167);
  ck_assert_double_le(month_payment_min, 8403);
  ck_assert_double_le(total_loan, 105417);
  ck_assert_double_le(interest_rate_payment, 5417);
}
END_TEST

START_TEST(deposit_1) {
  deposit_calc_struct deposit = {0};
  deposit.sum = 350000;
  deposit.duration_month = 14;
  deposit.interest_rate = 5;
  deposit.tax_rate = 13;
  deposit.capitalization = 0;
  deposit.frequency_of_payments = 1;

  double total_amount = 0.0;
  double tax_amount = 0.0;
  double interest_amount = 0.0;
  my_deposit_calc(&deposit, &total_amount, &tax_amount, &interest_amount);
  ck_assert_double_eq_tol(total_amount, 370416.666667, 1e-6);
  ck_assert_double_eq_tol(tax_amount, 0.000000, 1e-6);
  ck_assert_double_eq_tol(interest_amount, 20416.666667, 1e-6);
}

START_TEST(deposit_2) {
  deposit_calc_struct deposit = {0};
  deposit.sum = 100000;
  deposit.duration_month = 12;
  deposit.interest_rate = 150;
  deposit.tax_rate = 13;
  deposit.capitalization = 1;
  deposit.frequency_of_payments = 1;

  double total_amount = 0.0;
  double tax_amount = 0.0;
  double interest_amount = 0.0;
  my_deposit_calc(&deposit, &total_amount, &tax_amount, &interest_amount);
  ck_assert_double_eq_tol(total_amount, 410979.52, 1e-6);
  ck_assert_double_eq_tol(tax_amount, 13604.15, 1e-6);
  ck_assert_double_eq_tol(interest_amount, 310979.52, 1e-6);
}

START_TEST(deposit_3) {
  deposit_calc_struct deposit = {0};
  deposit.sum = 68500;
  deposit.duration_month = 8;
  deposit.interest_rate = 5;
  deposit.tax_rate = 13;
  deposit.capitalization = 1;
  deposit.frequency_of_payments = 3;

  double total_amount = 0.0;
  double tax_amount = 0.0;
  double interest_amount = 0.0;
  my_deposit_calc(&deposit, &total_amount, &tax_amount, &interest_amount);
  ck_assert_double_eq_tol(total_amount, 71100.993164, 1e-6);
  ck_assert_double_eq_tol(tax_amount, 0.000000, 1e-6);
  ck_assert_double_eq_tol(interest_amount, 2600.993164, 1e-6);
}

Suite *suite_finance_test(void) {
  Suite *s = suite_create("\033[45m-=finance_test=-\033[0m");
  TCase *tc = tcase_create("case_finance_test");

  tcase_add_test(tc, test_my_credit_calc_ann_1);
  tcase_add_test(tc, test_my_credit_calc_ann_2);
  tcase_add_test(tc, test_my_credit_calc_dif_1);
  tcase_add_test(tc, test_my_credit_calc_dif_2);
  tcase_add_test(tc, deposit_1);
  tcase_add_test(tc, deposit_2);
  tcase_add_test(tc, deposit_3);

  suite_add_tcase(s, tc);
  return s;
}