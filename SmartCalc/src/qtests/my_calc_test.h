#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>
#include <unistd.h>

#include "../my_smart_calc.h"

Suite *suite_valid_str(void);
Suite *test_str_validation(void);
Suite *test_polish_notation(void);
Suite *suite_calc_str(void);
Suite *suite_finance_test(void);

typedef struct {
  int fails;
} fail;

void run_tests(fail *fails);
void run_testcase(Suite *testcase, fail *fails);

#endif
