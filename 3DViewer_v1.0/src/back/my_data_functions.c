#include "3D_Viewer.h"

void add_coord(float cord, v_data *data) {
  if (data->values == NULL) {
    data->memory = 64;
    data->count = 0;
    data->values = calloc(64, sizeof(float));
  }
  if (data->count >= data->memory) {
    data->memory *= 2;
    data->values = realloc(data->values, sizeof(float) * data->memory);
  }
  data->values[data->count] = cord;
  data->count++;
}

void add_pol(int cord, f_data *data) {
  if (data->values == NULL) {
    data->memory_total = 64;
    data->count = 0;
    data->values = calloc(data->memory_total, sizeof(float));
  }
  if (data->count >= data->memory_total) {
    data->memory_total *= 2;
    data->values = realloc(data->values, sizeof(float) * data->memory_total);
  }
  data->values[data->count] = cord;
  data->count++;
}

void freeData(f_data *f, v_data *v) {
  if (f->values != NULL) {
    free(f->values);
    f->count = 0;
    f->poligons = 0;
    f->memory_total = 0;
    f->values = NULL;
  }
  if (v->values != NULL) {
    free(v->values);
    v->count = 0;
    v->memory = 0;
    v->values = NULL;
  }
}

int my_valid_data(f_data *f_data, v_data *v_data) {
  int status = OK;
  for (int i = 0; !status && i < f_data->count; i++) {
    if (f_data->values[i] < 0 || f_data->values[i] > v_data->count - 1) {
      status = INCORRECT_POLIGON;
    }
  }
  if (f_data->count % 2 != 0) status = INCORRECT_POLIGON;

  return status;
}
