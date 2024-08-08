#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>
#include <unistd.h>

#include "../back/3D_Viewer.h"

Suite *suite_test_parser(void);

typedef struct {
  int fails;
} fail;

void run_tests(fail *fails);
void run_testcase(Suite *testcase, fail *fails);

#endif
