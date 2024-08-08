// #include <stdio.h>

#include "3D_Viewer.h"

// int main() {
//     int a = 0;
//     int b = 0;
//     int c = 0;

//     char main[256] = "f 5/5/5 5/5/5 5/5/5";
//     int g = sscanf(main, "f %1d %1d %1d", &a, &b, &c);

//     printf("%d %d %d %d\n", a, b, c, g);

//     return 0;
// }

int main() {
  v_data data_v;
  f_data data_f;
  memset(&data_v, 0, sizeof(v_data));
  memset(&data_f, 0, sizeof(f_data));

  // FILE *fp = fopen(
  //     "/Users/jenisepl/Desktop/myProjects/C8_3DViewer_v1.0-1/src/obj/cube.obj",
  //     "r");

  FILE *fp = fopen(
      "/Users/calamarp/Projects/C8_3DViewer_v1.0-1/src/obj/cube.obj", "r");

  if (fp == NULL) {
    perror("Ошибка открытия файла");
    exit(EXIT_FAILURE);
  }

  my_parse_obj(&data_v, &data_f, fp);

  fclose(fp);
  // Выводим значения для проверки
  for (int i = 0; i < data_v.count; i++) {
    // printf("%f %f %f\n", data_v.values[i], data_v.values[i+1],
    // data_v.values[i+2]); i+=1; sleep(1);
    printf("%f\t", data_v.values[i]);
  }
  printf("\n\n\n\n\n\n");

  printf("%d\n", data_v.count);
  printf("%d\n", data_f.count);

  printf("\n\n\n\n\n\n");

  for (int i = 0; i < data_f.count; ++i) {
    printf("%d\t", data_f.values[i]);
  }
  printf("\n");
  printf("data_f.count =%d\n", data_f.count);
  // Освобождаем память
  freeData(&data_f, &data_v);
}