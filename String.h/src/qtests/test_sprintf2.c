#include "test_main.h"

START_TEST(sprintf_without_specifiers) {
  // Default test
  {
    char buff1[100] = {0};
    char buff2[100] = {0};
    int res1 = 0, res2 = 0;
    res1 = my_sprintf(buff1, "Default message");
    res2 = sprintf(buff2, "Default message");
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(buff1, buff2);
  }

  // Test with specifiers
  {
    char buff1[100] = {0};
    char buff2[100] = {0};
    my_sprintf(buff1, "Default\nmessage2");
    sprintf(buff2, "Default\nmessage2");
    ck_assert_str_eq(buff1, buff2);
  }

  // Test with specifiers
  {
    char buff1[100] = {0};
    char buff2[100] = {0};
    my_sprintf(buff1, "123Default\nmes\tsage2");
    sprintf(buff2, "123Default\nmes\tsage2");
    ck_assert_str_eq(buff1, buff2);
  }
}
END_TEST

START_TEST(sprintf_flag_c) {
  {
    char *flags[5] = {"", "-", "+", " ", "0"};
    char *widths[3] = {"", "0", "3"};
    char *accuracies[5] = {"", ".", ".0", ".3", ".5"};
    char my_buffer[20] = {0};
    char buffer2[20] = {0};
    char format[20] = {0};
    char ch = 'A';
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 3; width++) {
        for (int accuracy = 0; accuracy < 5; accuracy++) {
          strcat(format, "Char: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "c");

          res1 = my_sprintf(my_buffer, format, ch);
          res2 = sprintf(buffer2, format, ch);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          memset(format, 0, strlen(format));
        }
      }
    }
  }

  {
    char *flags[5] = {"", "-", "+", " ", "0"};
    char *widths[3] = {"", "0", "3"};
    char *accuracies[5] = {"", ".", ".0", ".3", ".5"};
    char my_buffer[20] = {0};
    char buffer2[20] = {0};
    char format[20] = {0};
    wchar_t ch = L'q';
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 3; width++) {
        for (int accuracy = 0; accuracy < 5; accuracy++) {
          strcat(format, "Char: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "lc");

          res1 = my_sprintf(my_buffer, format, ch);
          res2 = sprintf(buffer2, format, ch);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          ck_assert_str_eq(my_buffer, buffer2);
          memset(format, 0, strlen(format));
        }
      }
    }
  }
}
END_TEST

START_TEST(sprintf_flag_d) {
  char *flags[5] = {"", "-", "+", " ", "0"};
  char *widths[5] = {"0", "1", "4", "5", "8"};
  char *accuracies[6] = {"", ".", ".0", ".3", ".5", ".7"};
  char my_buffer[50] = {0};
  char buffer2[50] = {0};
  char format[50] = {0};
  // Test -9541 negative int without length argument
  {
    int num = -9541;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 5; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "d");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          memset(format, 0, strlen(format));
        }
      }
    }
  }

  // Test -32767 negative short int with h
  {
    short int num = -32767;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 5; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "hd");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          memset(format, 0, strlen(format));
        }
      }
    }
  }

  // Test long negative int with l
  {
    long int num = -12345678905;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 5; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "ld");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          ck_assert_str_eq(my_buffer, buffer2);
          memset(format, 0, strlen(format));
        }
      }
    }
  }

  // Test 9541 positive int without length argument
  {
    int num = 9541;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 5; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "d");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          ck_assert_str_eq(my_buffer, buffer2);
          memset(format, 0, strlen(format));
        }
      }
    }
  }

  // Test 32767 positive short int with h
  {
    short int num = 32767;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 5; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "hd");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          ck_assert_str_eq(my_buffer, buffer2);
          memset(format, 0, strlen(format));
        }
      }
    }
  }

  // Test long positive int with l
  {
    long int num = 12345678905;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 5; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "ld");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          ck_assert_str_eq(my_buffer, buffer2);
          memset(format, 0, strlen(format));
        }
      }
    }
  }
}
END_TEST

START_TEST(sprintf_flag_f) {
  char *flags[5] = {"", "-", "+", " ", "0"};
  char *widths[6] = {"", "0", "1", "7", "12", "18"};
  char *accuracies[6] = {"", ".", ".0", ".3", ".5", ".7"};
  char my_buffer[50] = {0};
  char buffer2[50] = {0};
  char format[50] = {0};
  {
    float num = 1234567.1234567;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 6; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "f");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          memset(format, 0, strlen(format));
        }
      }
    }
  }

  {
    float num = -1204567.1234567;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 5; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "f");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          memset(format, 0, strlen(format));
        }
      }
    }
  }

  {
    double num = 0.12345;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 5; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "f");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          memset(format, 0, strlen(format));
        }
      }
    }
  }
}
END_TEST

START_TEST(sprintf_flag_s) {
  char *flags[5] = {"", "-", "+", " ", "0"};
  char *widths[5] = {"0", "4", "19", "20", "28"};
  char *accuracies[6] = {"", ".", ".0", ".7", ".15", ".27"};
  char my_buffer[70] = {0};
  char buffer2[70] = {0};
  char format[70] = {0};
  // Test *char
  {
    char *string = "Default string 123";
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 5; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Qwe: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "s");

          res1 = sprintf(buffer2, format, string);
          res2 = my_sprintf(my_buffer, format, string);

          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          memset(format, 0, strlen(format));
        }
      }
    }
  }

  // Test empty *char
  {
    char *string = "";
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 5; flag++) {
      for (int width = 0; width < 5; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "%");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "s");

          res1 = sprintf(buffer2, format, string);
          res2 = my_sprintf(my_buffer, format, string);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          memset(format, 0, strlen(format));
        }
      }
    }
  }
}
END_TEST

START_TEST(sprintf_flag_u) {
  // Test 1234 positive int without length argument
  {
    char *flags[4] = {"", "-", "+", " "};
    char *widths[10] = {"", "-7", "-5", "-4", "-1", "0", "1", "4", "5", "8"};
    char *accuracies[6] = {"", ".", ".0", ".3", ".5", ".7"};
    char my_buffer[50] = {0};
    char buffer2[50] = {0};
    char format[50] = {0};
    unsigned num = 1234;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 4; flag++) {
      for (int width = 0; width < 10; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "u");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          memset(format, 0, strlen(format));
        }
      }
    }
  }

  // Test 32767 positive short int with h
  {
    char *flags[4] = {"", "-", "+", " "};
    char *widths[10] = {"", "-7", "-5", "-4", "-1", "0", "1", "4", "5", "8"};
    char *accuracies[6] = {"", ".", ".0", ".3", ".5", ".7"};
    char my_buffer[50] = {0};
    char buffer2[50] = {0};
    char format[50] = {0};
    short unsigned num = 32767;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 4; flag++) {
      for (int width = 0; width < 10; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "hu");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          memset(format, 0, strlen(format));
        }
      }
    }
  }
  //
  // Test long positive int with l
  {
    char *flags[4] = {"", "-", "+", " "};
    char *widths[10] = {"", "-7", "-5", "-4", "-1", "0", "1", "4", "5", "8"};
    char *accuracies[6] = {"", ".", ".0", ".3", ".5", ".7"};
    char my_buffer[50] = {0};
    char buffer2[50] = {0};
    char format[50] = {0};
    unsigned long int num = 1423143252345435345;
    int res1 = 0, res2 = 0;

    for (int flag = 0; flag < 4; flag++) {
      for (int width = 0; width < 10; width++) {
        for (int accuracy = 0; accuracy < 6; accuracy++) {
          strcat(format, "Num1: %");
          strcat(format, flags[flag]);
          strcat(format, widths[width]);
          strcat(format, accuracies[accuracy]);
          strcat(format, "lu");

          res1 = my_sprintf(my_buffer, format, num);
          res2 = sprintf(buffer2, format, num);
          ck_assert_str_eq(my_buffer, buffer2);
          ck_assert_int_eq(res1, res2);

          memset(format, 0, strlen(format));
        }
      }
    }
  }
}
END_TEST

START_TEST(sprintf_flag_percent) {
  char my_buffer[50] = {0};
  char buffer2[50] = {0};

  my_sprintf(my_buffer, "Print percent: %%");
  sprintf(buffer2, "Print percent: %%");
  ck_assert_str_eq(my_buffer, buffer2);
}
END_TEST

START_TEST(sprintf_flag_xX) {
  char *flags[6] = {"", "-", "+", " ", "#", "0"};
  char *widths[5] = {"0", "1", "4", "5", "8"};
  char *accuracies[6] = {"", ".", ".0", ".3", ".5", ".7"};
  char my_buffer[50] = {0};
  char buffer2[50] = {0};
  char format[50] = {0};

  // Test x
  {
    int numbers[15] = {0x0, 0x1, 0x12345,    0xabcdef, 00, 01,   054321, 017,
                       0b0, 0b1, 0b10101001, 0,        1,  4321, 18754};
    int res1 = 0, res2 = 0;
    for (int num = 0; num < 15; num++) {
      for (int flag = 0; flag < 6; flag++) {
        for (int width = 0; width < 5; width++) {
          for (int accuracy = 0; accuracy < 6; accuracy++) {
            strcat(format, "Hex: %");
            strcat(format, flags[flag]);
            strcat(format, widths[width]);
            strcat(format, accuracies[accuracy]);
            strcat(format, "x");

            res1 = my_sprintf(my_buffer, format, numbers[num]);
            res2 = sprintf(buffer2, format, numbers[num]);
            ck_assert_str_eq(my_buffer, buffer2);
            ck_assert_int_eq(res1, res2);

            memset(format, 0, strlen(format));
          }
        }
      }
    }
  }

  // Test X
  {
    int numbers[15] = {0x0, 0x1, 0x12345,    0xabcdef, 00, 01,   054321, 017,
                       0b0, 0b1, 0b10101001, 0,        1,  4321, 18754};
    int res1 = 0, res2 = 0;
    for (int num = 0; num < 15; num++) {
      for (int flag = 0; flag < 5; flag++) {
        for (int width = 0; width < 5; width++) {
          for (int accuracy = 0; accuracy < 6; accuracy++) {
            strcat(format, "Hex: %");
            strcat(format, flags[flag]);
            strcat(format, widths[width]);
            strcat(format, accuracies[accuracy]);
            strcat(format, "X");

            res1 = my_sprintf(my_buffer, format, numbers[num]);
            res2 = sprintf(buffer2, format, numbers[num]);
            ck_assert_str_eq(my_buffer, buffer2);
            ck_assert_int_eq(res1, res2);

            memset(format, 0, strlen(format));
          }
        }
      }
    }
  }
}
END_TEST

START_TEST(sprintf_flag_o) {
  char *flags[5] = {"", "-", "+", " ", "#"};
  char *widths[5] = {"0", "1", "4", "5", "8"};
  char *accuracies[6] = {"", ".", ".0", ".3", ".5", ".7"};
  char my_buffer[50] = {0};
  char buffer2[50] = {0};
  char format[50] = {0};

  // Test o
  {
    int numbers[11] = {01,  0x1,        0x12345, 0xabcdef, 054321, 017,
                       0b1, 0b10101001, 1,       4321,     18754};

    int res1 = 0, res2 = 0;
    for (int num = 0; num < 11; num++) {
      for (int flag = 0; flag < 5; flag++) {
        for (int width = 0; width < 5; width++) {
          for (int accuracy = 0; accuracy < 6; accuracy++) {
            strcat(format, "Oct: %");
            strcat(format, flags[flag]);
            strcat(format, widths[width]);
            strcat(format, accuracies[accuracy]);
            strcat(format, "o");

            res1 = my_sprintf(my_buffer, format, numbers[num]);
            res2 = sprintf(buffer2, format, numbers[num]);
            ck_assert_str_eq(my_buffer, buffer2);
            ck_assert_int_eq(res1, res2);

            memset(format, 0, strlen(format));
          }
        }
      }
    }
  }
}
END_TEST

START_TEST(sprintf_flag_p) {
  char my_buffer[50] = {0};
  char buffer2[50] = {0};
  int var = 5;

  my_sprintf(my_buffer, "Test1: %p", &var);
  sprintf(buffer2, "Test1: %p", &var);
  ck_assert_str_eq(my_buffer, buffer2);
}
END_TEST

START_TEST(sprintf_flag_star) {
  {
    char my_buffer[50] = {0};
    char buffer2[50] = {0};

    my_sprintf(my_buffer, "%.*s", 10, "Qwertyui");
    sprintf(buffer2, "%.*s", 10, "Qwertyui");
    ck_assert_str_eq(my_buffer, buffer2);
  }

  {
    char my_buffer[50] = {0};
    char buffer2[50] = {0};

    my_sprintf(my_buffer, "%*s", 10, "Qwertyui");
    sprintf(buffer2, "%*s", 10, "Qwertyui");
    ck_assert_str_eq(my_buffer, buffer2);
  }
}
END_TEST

Suite *my_sprintf2_suite() {
  Suite *s1 = suite_create("\033[45m-=my_sprintf2=-\033[0m");
  TCase *tc1 = tcase_create("Core");

  tcase_add_test(tc1, sprintf_without_specifiers);
  tcase_add_test(tc1, sprintf_flag_c);
  tcase_add_test(tc1, sprintf_flag_d);
  tcase_add_test(tc1, sprintf_flag_f);
  tcase_add_test(tc1, sprintf_flag_s);
  tcase_add_test(tc1, sprintf_flag_u);
  tcase_add_test(tc1, sprintf_flag_percent);
  tcase_add_test(tc1, sprintf_flag_xX);
  tcase_add_test(tc1, sprintf_flag_o);
  tcase_add_test(tc1, sprintf_flag_p);
  tcase_add_test(tc1, sprintf_flag_star);

  suite_add_tcase(s1, tc1);

  return s1;
}