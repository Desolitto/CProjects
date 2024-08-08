/**
 * @file my_valid.h
 * @brief Файл, содержащий функции для проверки валидности строк и выражений.
 *
 * В этом файле определены функции для проверки различных аспектов строк и
 * выражений, используемых в математических вычислениях, включая корректность
 * использования скобок, точек, операторов, числовых значений и переменных.
 */

#ifndef VALID_H
#define VALID_H

#include "../my_smart_calc.h"

/**
 * @brief Проверяет валидность строки на основе различных критериев.
 * @param str Строка для проверки.
 * @return OK, если строка проходит все проверки, иначе INCORRECT_INPUT или
 * SORRY_CANT_CALC_WITH_E.
 */
int my_valid_str(char *str);

/**
 * @brief Проверяет корректность использования скобок в строке.
 * @param str Строка для проверки.
 * @return OK, если скобки используются корректно, иначе INCORRECT_INPUT.
 */
int my_valid_bkt(char *str);

/**
 * @brief Вспомогательная функция для проверки положение точки в строке.
 * @param str Строка для проверки.
 * @param index Индекс символа в строке.
 * @param point_counter Счетчик точек.
 * @return OK, если точка находится в правильном месте, иначе INCORRECT_INPUT.
 */
int check_dot_position(char *str, int index, int *point_counter);

/**
 * @brief Проверяет валидность использования точек в строке.
 * @param str Строка для проверки.
 * @return OK, если точки используются корректно, иначе INCORRECT_INPUT.
 */
int my_valid_point(char *str);

/**
 * @brief Проверяет валидность операторов в строке.
 * @param str Строка для проверки.
 * @return OK, если операторы используются корректно, иначе INCORRECT_INPUT.
 */
int my_valid_op(char *str);

/**
 * @brief Проверяет валидность оператора 'm' в строке.
 * @param str Строка для проверки.
 * @param i Указатель на индекс в строке.
 * @return OK, если оператор 'm' используется корректно, иначе INCORRECT_INPUT.
 */
int check_m_operator(char *str, int *i);

/**
 * @brief Проверяет валидность ограничивающих скобок для операторов.
 * @param str Строка для проверки.
 * @param i Индекс в строке.
 * @param length Длина проверяемой подстроки.
 * @return OK, если ограничивающие скобки используются корректно, иначе
 * INCORRECT_INPUT.
 */
int check_lim_bkt(char *str, int i, int length);

/**
 * @brief Проверяет валидность тригонометрических функций в строке.
 * @param str Строка для проверки.
 * @return OK, если тригонометрические функции используются корректно, иначе
 * INCORRECT_INPUT.
 */
int my_valid_trig(char *str);

/**
 * @brief Проверяет валидность других функций в строке.
 * @param str Строка для проверки.
 * @return OK, если другие функции используются корректно, иначе
 * INCORRECT_INPUT.
 */
int my_valid_other_func(char *str);

/**
 * @brief Проверяет валидность числовых значений в строке.
 * @param str Строка для проверки.
 * @return OK, если числовые значения используются корректно, иначе
 * INCORRECT_INPUT.
 */
int my_valid_num(char *str);

/**
 * @brief Проверяет валидность использования переменной 'x' в строке.
 * @param str Строка для проверки.
 * @return OK, если переменная 'x' используется корректно, иначе
 * INCORRECT_INPUT.
 */
int my_valid_x(char *str);

/**
 * @brief Проверяет валидность использования 'e' в строке.
 * @param str Строка для проверки.
 * @return OK, если 'e' используется корректно, иначе SORRY_CANT_CALC_WITH_E.
 */
int my_valid_e(char *str);

#endif