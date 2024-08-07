#include "test_main.h"

int main(void) {
  int failed = 0;
  Suite *my_string_test[] = {test_memchr(),           test_memcmp(),
                              test_memcpy(),           test_memmove(),
                              test_memset(),           test_strcat(),
                              test_strncat(),          test_strchr(),
                              test_strcmp(),           test_strncmp(),
                              test_strcpy(),           test_strncpy(),
                              test_strcspn(),          test_strerror(),
                              test_strlen(),           test_strpbrk(),
                              test_strrchr(),          test_strspn(),
                              test_strstr(),           test_strtok(),
                              test_to_upper(),         test_to_lower(),
                              test_insert(),           test_trim(),
                              test_sprintf_c(),  // Sprint
                              test_sprintf_signed(),   test_sprintf_f(),
                              test_sprintf_unsigned(), test_sprintf_string(),
                              test_sprintf_percent(),  test_sprintf_octal(),
                              test_sprintf_g(),        test_sprintf_e(),
                              test_sprintf_n(),        test_sprintf_HEX(),
                              test_sprintf_hex(),      test_sprintf_asterisk(),
                              test_sprintf_pointer(),  test_sprintf_signed_i(),
                              my_sprintf1_suite(),    my_sprintf2_suite(),
                              test_sscanf_d(),  // SSCANF
                              test_sscanf_s(),         test_sscanf_c(),
                              test_sscanf_i(),         test_sscanf_u(),
                              test_sscanf_o(),         test_sscanf_x(),
                              test_sscanf_n(),         test_sscanf_p(),
                              test_sscanf_real(),      NULL};

  for (int i = 0; my_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(my_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}