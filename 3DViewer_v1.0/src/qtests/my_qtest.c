#include "my_view_test.h"

#define CUBE "obj/cube.obj"
#define BAD_MODEL "obj/bad_model.obj"

START_TEST(test_my_parser_0) {
  v_data data_v;
  f_data data_f;
  memset(&data_v, 0, sizeof(v_data));
  memset(&data_f, 0, sizeof(f_data));
  FILE *fp = fopen(CUBE, "r");

  ck_assert_ptr_nonnull(fp);
  my_parse_obj(&data_v, &data_f, fp);

  fclose(fp);

  ck_assert_int_eq(data_v.count, 24);
  ck_assert_int_eq(data_f.count, 72);
  freeData(&data_f, &data_v);
}

START_TEST(test_my_parser_1) {
  v_data data_v;
  f_data data_f;
  memset(&data_v, 0, sizeof(v_data));
  memset(&data_f, 0, sizeof(f_data));
  FILE *fp = fopen(CUBE, "r");

  ck_assert_ptr_nonnull(fp);
  my_parse_obj(&data_v, &data_f, fp);

  fclose(fp);

  ck_assert_double_eq_tol(data_v.values[0], 0.5, 1e-8);
  ck_assert_double_eq_tol(data_v.values[11], -0.5, 1e-8);
  ck_assert_int_eq(data_f.values[0], 1);
  ck_assert_int_eq(data_f.values[12], 4);
  freeData(&data_f, &data_v);
}

START_TEST(test_my_invalid_0) {
  v_data data_v;
  f_data data_f;
  memset(&data_v, 0, sizeof(v_data));
  memset(&data_f, 0, sizeof(f_data));
  FILE *fp = fopen(CUBE, "r");

  ck_assert_ptr_nonnull(fp);
  my_parse_obj(&data_v, &data_f, fp);
  int error = my_valid_data(&data_f, &data_v);

  ck_assert_int_eq(error, OK);

  fclose(fp);
  freeData(&data_f, &data_v);
}

START_TEST(test_my_invalid_1) {
  v_data data_v;
  f_data data_f;
  memset(&data_v, 0, sizeof(v_data));
  memset(&data_f, 0, sizeof(f_data));
  FILE *fp = fopen(BAD_MODEL, "r");

  ck_assert_ptr_nonnull(fp);
  my_parse_obj(&data_v, &data_f, fp);
  int error = my_valid_data(&data_f, &data_v);

  ck_assert_int_eq(error, INCORRECT_POLIGON);

  fclose(fp);
  freeData(&data_f, &data_v);
}

START_TEST(test_my_rotate_x) {
  v_data data_v;
  data_v.count = 6;
  data_v.values = malloc(data_v.count * sizeof(double));

  data_v.values[0] = 1.0;
  data_v.values[1] = 0.0;
  data_v.values[2] = 0.0;
  data_v.values[3] = 0.0;
  data_v.values[4] = 1.0;
  data_v.values[5] = 0.0;

  float angle = M_PI / 2;  // 90

  my_rotate_x(&data_v, angle);

  double expected_values[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0};

  for (int i = 0; i < data_v.count; i++) {
    ck_assert_double_eq_tol(data_v.values[i], expected_values[i], 1e-6);
  }

  free(data_v.values);
}
END_TEST

START_TEST(test_my_rotate_y) {
  v_data data_v;
  data_v.count = 6;
  data_v.values = malloc(data_v.count * sizeof(double));

  data_v.values[0] = 1.0;
  data_v.values[1] = 0.0;
  data_v.values[2] = 0.0;
  data_v.values[3] = 0.0;
  data_v.values[4] = 1.0;
  data_v.values[5] = 0.0;

  float angle = M_PI / 2;  // 90

  my_rotate_y(&data_v, angle);

  double expected_values[6] = {0.0, 0.0, -1.0, 0.0, 1.0, 0.0};

  for (int i = 0; i < data_v.count; i++) {
    ck_assert_double_eq_tol(data_v.values[i], expected_values[i], 1e-6);
  }

  free(data_v.values);
}
END_TEST

START_TEST(test_my_rotate_z) {
  v_data data_v;
  data_v.count = 6;
  data_v.values = malloc(data_v.count * sizeof(double));

  data_v.values[0] = 1.0;
  data_v.values[1] = 0.0;
  data_v.values[2] = 0.0;
  data_v.values[3] = 0.0;
  data_v.values[4] = 1.0;
  data_v.values[5] = 0.0;

  float angle = M_PI / 2;  // 90
  my_rotate_z(&data_v, angle);

  double expected_values[6] = {0.0, 1.0, 0.0, -1.0, 0.0, 0.0};

  for (int i = 0; i < data_v.count; i++) {
    ck_assert_double_eq_tol(data_v.values[i], expected_values[i], 1e-6);
  }

  free(data_v.values);
}
END_TEST

START_TEST(test_my_move) {
  v_data data_v;
  data_v.count = 6;
  data_v.values = malloc(data_v.count * sizeof(double));

  data_v.values[0] = 1.0;
  data_v.values[1] = 2.0;
  data_v.values[2] = 3.0;
  data_v.values[3] = 4.0;
  data_v.values[4] = 5.0;
  data_v.values[5] = 6.0;

  float a = 1.0;
  float b = -2.0;
  float c = 3.0;

  my_move(&data_v, a, b, c);

  double expected_values[6] = {2.0, 0.0, 6.0, 5.0, 3.0, 9.0};

  for (int i = 0; i < data_v.count; i++) {
    ck_assert_double_eq_tol(data_v.values[i], expected_values[i], 1e-6);
  }

  free(data_v.values);
}
END_TEST

START_TEST(test_my_get_center) {
  v_data data_v;
  data_v.count = 9;
  data_v.values = malloc(data_v.count * sizeof(double));

  data_v.values[0] = 1.0;  // x1
  data_v.values[1] = 2.0;  // y1
  data_v.values[2] = 3.0;  // z1
  data_v.values[3] = 4.0;  // x2
  data_v.values[4] = 5.0;  // y2
  data_v.values[5] = 6.0;  // z2
  data_v.values[6] = 7.0;  // x3
  data_v.values[7] = 8.0;  // y3
  data_v.values[8] = 9.0;  // z3

  float cent_x = get_center(&data_v, 0);
  ck_assert_float_eq_tol(cent_x, 4.0, 1e-6);

  float cent_y = get_center(&data_v, 1);
  ck_assert_float_eq_tol(cent_y, 5.0, 1e-6);

  float cent_z = get_center(&data_v, 2);
  ck_assert_float_eq_tol(cent_z, 6.0, 1e-6);

  free(data_v.values);
}
END_TEST

START_TEST(test_my_change_scale) {
  v_data data_v;
  data_v.count = 6;
  data_v.values = malloc(data_v.count * sizeof(double));

  data_v.values[0] = 1.0;
  data_v.values[1] = 2.0;
  data_v.values[2] = 3.0;
  data_v.values[3] = 4.0;
  data_v.values[4] = 5.0;
  data_v.values[5] = 6.0;

  float ratio = 2.0;

  my_change_scale(&data_v, ratio);

  double expected_values[6] = {2.0, 4.0, 6.0, 8.0, 10.0, 12.0};

  for (int i = 0; i < data_v.count; i++) {
    ck_assert_double_eq_tol(data_v.values[i], expected_values[i], 1e-6);
  }

  free(data_v.values);
}
END_TEST

START_TEST(test_my_normalize) {
  v_data data_v;
  data_v.count = 6;
  data_v.values = malloc(data_v.count * sizeof(double));

  data_v.values[0] = 1.0;
  data_v.values[1] = 2.0;
  data_v.values[2] = 3.0;
  data_v.values[3] = -4.0;
  data_v.values[4] = -5.0;
  data_v.values[5] = -6.0;

  my_normalize(&data_v);

  for (int i = 0; i < data_v.count; i++) {
    ck_assert_double_ge(data_v.values[i], -1.0);
    ck_assert_double_le(data_v.values[i], 1.0);
  }

  free(data_v.values);
}
END_TEST

START_TEST(test_my_centralize) {
  v_data data_v;
  data_v.count = 9;
  data_v.values = malloc(data_v.count * sizeof(double));

  data_v.values[0] = 1.0;
  data_v.values[1] = 2.0;
  data_v.values[2] = 3.0;
  data_v.values[3] = 4.0;
  data_v.values[4] = 5.0;
  data_v.values[5] = 6.0;
  data_v.values[6] = 7.0;
  data_v.values[7] = 8.0;
  data_v.values[8] = 9.0;

  my_centralize(&data_v);

  for (int i = 0; i < 3; i++) {
    ck_assert_double_eq_tol(get_center(&data_v, i), 0.0, 1e-6);
  }

  free(data_v.values);
}
END_TEST

Suite *suite_test_parser(void) {
  Suite *s = suite_create("\033[45m-=suite_all=-\033[0m");
  TCase *tc = tcase_create("case_valid_all");

  tcase_add_test(tc, test_my_parser_0);
  tcase_add_test(tc, test_my_parser_1);
  tcase_add_test(tc, test_my_invalid_0);
  tcase_add_test(tc, test_my_invalid_1);
  tcase_add_test(tc, test_my_rotate_x);
  tcase_add_test(tc, test_my_rotate_y);
  tcase_add_test(tc, test_my_rotate_z);
  tcase_add_test(tc, test_my_move);
  tcase_add_test(tc, test_my_get_center);
  tcase_add_test(tc, test_my_change_scale);
  tcase_add_test(tc, test_my_normalize);
  tcase_add_test(tc, test_my_centralize);

  suite_add_tcase(s, tc);
  return s;
}
