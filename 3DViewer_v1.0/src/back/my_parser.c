#include "3D_Viewer.h"

void process_vertex_line(char *line, v_data *v_data) {
  float x = 0, y = 0, z = 0;

  if (sscanf(line, "v %f %f %f", &x, &y, &z) == 3) {
    add_coord(x, v_data);
    add_coord(y, v_data);
    add_coord(z, v_data);
  }
}

void process_polygon_line(char *line, f_data *f_data) {
  char *token = strtok(line, " ");
  int first_pol = 0;
  int escape_f = 0;
  int pol = 0;
  int start_pol = 0;

  while (token != NULL) {
    if (escape_f > 0) {
      if (sscanf(token, "%d", &pol) == 1) {
        pol--;
        if (start_pol == 0) {
          add_pol(pol, f_data);
          first_pol = pol;
          start_pol = 1;
        } else {
          add_pol(pol, f_data);
          add_pol(pol, f_data);
        }
      }
    }
    escape_f = 1;
    token = strtok(NULL, " ");
  }
  add_pol(first_pol, f_data);
  f_data->poligons++;
}

void my_parse_obj(v_data *v_data, f_data *f_data, FILE *file) {
  char *line = NULL;
  size_t bufsize = 0;
  int characters = 0;

  while ((characters = getline(&line, &bufsize, file)) != -1) {
    if (strncmp(line, "v ", 2) == 0) {
      process_vertex_line(line, v_data);
    }
    if (!strncmp(line, "f ", 2)) {
      process_polygon_line(line, f_data);
    }
  }

  free(line);
}