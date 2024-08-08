/**
 * \mainpage
 * \authors calamarp jenisepl
 * \version 1.0
 *
 * @file 3D_VIEWER.h
 * @brief Заголовочный файл с объявлениями функций и структур для работы с 3D
 * моделями.
 *
 * Этот файл содержит объявления функций и структур, используемых для обработки
 * и отображения трехмерных моделей.
 */

#ifndef _3D_VIEWER_H
#define _3D_VIEWER_H

/**
 * @brief Коды ошибок.
 */

#define ERROR 1
#define OK 0
#define INCORRECT_VERTEX 1
#define MEMORY_ERROR 2
#define INCORRECT_FILE 3
#define INCORRECT_POLIGON 4

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct f_data
 * @brief Структура для хранения данных о полигонах модели.
 */

typedef struct f_data {  // ПОлигоны
  int count;
  int poligons;
  int memory_total;
  int *values;
} f_data;

/**
 * @struct v_data
 * @brief Структура для хранения данных о вершинах модели.
 */

typedef struct v_data {  // Вершины
  int count;
  int memory;
  float *values;
} v_data;

/**
 * @struct my_color
 * @brief Структура для представления цвета.
 */

typedef struct my_color {  //Цвет
  float red;
  float green;
  float blue;
} my_color;

/**
 * @brief Функция для парсинга файла .obj и заполнения данных о вершинах и
 * полигонах модели.
 *
 * @param v_data Структура для хранения данных о вершинах модели.
 * @param f_data Структура для хранения данных о полигонах модели.
 * @param file Указатель на открытый файл .obj.
 */
void my_parse_obj(v_data *v_data, f_data *f_data, FILE *file);

/**
 * @brief Функция для обработки строки, содержащей информацию о вершине.
 *
 * @param line Строка, содержащая информацию о вершине.
 * @param v_data Структура для хранения данных о вершинах модели.
 */
void process_vertex_line(char *line, v_data *v_data);

/**
 * @brief Функция для обработки строки, содержащей информацию о полигоне.
 *
 * @param line Строка, содержащая информацию о полигоне.
 * @param f_data Структура для хранения данных о полигонах модели.
 */
void process_polygon_line(char *line, f_data *f_data);

/**
 * @brief Функция для добавления координаты к массиву вершин.
 *
 * @param cord Координата для добавления.
 * @param data Структура для хранения данных о вершинах модели.
 */
void add_coord(float cord, v_data *data);

/**
 * @brief Функция для добавления полигона к массиву полигонов.
 *
 * @param cord Значение полигона для добавления.
 * @param data Структура для хранения данных о полигонах модели.
 */
void add_pol(int cord, f_data *data);

/**
 * @brief Функция для освобождения памяти, занятой структурами данных модели.
 *
 * @param f Указатель на структуру данных о полигонах модели.
 * @param v Указатель на структуру данных о вершинах модели.
 */
void freeData(f_data *f, v_data *v);

/**
 * @brief Функция для проверки корректности данных о вершинах и полигонах
 * модели.
 *
 * @param f_data Структура данных о полигонах модели.
 * @param v_data Структура данных о вершинах модели.
 * @return Код ошибки или OK, если данные корректны.
 */
int my_valid_data(f_data *f_data, v_data *v_data);

/**
 * @brief Функция для нормализации координат вершин модели.
 *
 * @param data_v Структура для хранения данных о вершинах модели.
 */
void my_normalize(v_data *data_v);

/**
 * @brief Функция для вычисления центра по указанной оси.
 *
 * @param obj Структура для хранения данных о вершинах модели.
 * @param ax Ось (входные данные: 0 - X, 1 - Y, 2 - Z).
 * @return Координата центра по указанной оси.
 */
float get_center(v_data *obj, int ax);

/**
 * @brief Функция для установки центра по указанной оси.
 *
 * @param obj Структура для хранения данных о вершинах модели.
 * @param ax Ось (входные данные: 0 - X, 1 - Y, 2 - Z).
 * @param cent Координата центра по указанной оси.
 */
void set_center(v_data *obj, int ax, float cent);

/**
 * @brief Функция для централизации модели относительно центра координат.
 *
 * @param obj Структура для хранения данных о вершинах модели.
 */
void my_centralize(v_data *obj);

/**
 * @brief Функция для изменения масштаба модели.
 *
 * @param data_v Структура для хранения данных о вершинах модели.
 * @param ratio Коэффициент масштабирования.
 */
void my_change_scale(v_data *data_v, float ratio);

/**
 * @brief Функция для перемещения модели на указанные координаты.
 *
 * @param data_v Структура для хранения данных о вершинах модели.
 * @param a Смещение по оси X.
 * @param b Смещение по оси Y.
 * @param c Смещение по оси Z.
 */
void my_move(v_data *data_v, float a, float b, float c);

/**
 * @brief Функция для поворота модели вокруг оси X.
 *
 * @param data_v Структура для хранения данных о вершинах модели.
 * @param a Угол поворота
 */
void my_rotate_x(v_data *data_v, float a);

/**
 * @brief Функция для поворота модели вокруг оси Y.
 *
 * @param data_v Структура для хранения данных о вершинах модели.
 * @param a Угол поворота
 */
void my_rotate_y(v_data *data_v, float a);

/**
 * @brief Функция для поворота модели вокруг оси Z.
 *
 * @param data_v Структура для хранения данных о вершинах модели.
 * @param a Угол поворота
 */
void my_rotate_z(v_data *data_v, float a);

#endif  // _3D_VIEWER_H
