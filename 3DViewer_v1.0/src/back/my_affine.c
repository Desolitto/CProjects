#include "3D_Viewer.h"

void my_normalize(v_data *data_v) {
  double max_v = 0.0;
  for (int i = 0; i < data_v->count; i++) {
    if (fabs(data_v->values[i]) > max_v) max_v = data_v->values[i];
  }
  if (max_v != 0.) {
    for (int i = 0; i < data_v->count; i++) {
      data_v->values[i] /= max_v;
    }
  }
}

void my_centralize(v_data *obj) {
  float centx = get_center(obj, 0);
  float centy = get_center(obj, 1);
  float centz = get_center(obj, 2);
  set_center(obj, 0, centx);
  set_center(obj, 1, centy);
  set_center(obj, 2, centz);
}

float get_center(v_data *obj, int ax) {
  float xmin = obj->values[0 + ax];
  float xmax = obj->values[0 + ax];

  for (int i = 0; i < obj->count / 3; i++) {
    if (obj->values[i * 3 + ax] > xmax) xmax = obj->values[i * 3 + ax];
    if (obj->values[i * 3 + ax] < xmin) xmin = obj->values[i * 3 + ax];
  }
  float centx = (xmax + xmin) / 2;

  return centx;
}

void set_center(v_data *obj, int ax, float cent) {
  for (int i = 0; i < obj->count / 3; i++) {
    obj->values[i * 3 + ax] -= cent;
  }
}

//не работает
void my_change_scale(v_data *data_v, float ratio) {
  if (fabs(ratio - 1.0) <= 1e-03) return;
  for (int i = 0; i < data_v->count; i++) {
    data_v->values[i] *= ratio;
  }
}

void my_move(v_data *data_v, float a, float b, float c) {
  for (int i = 0; i < data_v->count; i += 3) {
    data_v->values[i] += a;
    data_v->values[i + 1] += b;
    data_v->values[i + 2] += c;
  }
}

void my_rotate_x(v_data *data_v, float a) {
  float cos_a = cos(a);
  float sin_a = sin(a);
  for (int i = 0; i < data_v->count; i += 3) {
    float y = data_v->values[i + 1];
    float z = data_v->values[i + 2];

    data_v->values[i + 1] = y * cos_a - z * sin_a;
    data_v->values[i + 2] = y * sin_a + z * cos_a;
  }
}

void my_rotate_y(v_data *data_v, float a) {
  float cos_a = cos(a);
  float sin_a = sin(a);
  for (int i = 0; i < data_v->count; i += 3) {
    float x = data_v->values[i];
    float z = data_v->values[i + 2];

    data_v->values[i] = x * cos_a + z * sin_a;
    data_v->values[i + 2] = -x * sin_a + z * cos_a;
  }
}

void my_rotate_z(v_data *data_v, float a) {
  float cos_a = cos(a);
  float sin_a = sin(a);
  for (int i = 0; i < data_v->count; i += 3) {
    float x = data_v->values[i];
    float y = data_v->values[i + 1];

    data_v->values[i] = x * cos_a - y * sin_a;
    data_v->values[i + 1] = x * sin_a + y * cos_a;
  }
}