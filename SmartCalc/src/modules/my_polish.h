/**
 * @file my_polish.h
 * @brief Файл, содержащий функции для работы с постфиксной записью.
 *
 * В этом файле определены функции для конвертации выражений из инфиксной записи
 * в постфиксную, а также для работы с приоритетами операторов.
 */

#ifndef POLISH_H
#define POLISH_H

#include "../my_smart_calc.h"

/**
 * @brief Определяет приоритет оператора.
 * @param ch Символ оператора.
 * @return Приоритет оператора.
 */
int get_priority(char ch);

/**
 * @brief Сравнивает приоритеты двух операторов.
 * @param op1 Первый оператор.
 * @param op2 Второй оператор.
 * @return 1, если приоритет op1 больше или равен приоритету op2, иначе 0.
 */
int priority_compare(char op1, char op2);

/**
 * @brief Конвертирует строку с инфиксной записью в строку с сокращенной
 * записью.
 * @param str Исходная строка с инфиксной записью.
 * @param res_str Результат конвертации.
 * @return OK, если конвертация прошла успешно, иначе INCORRECT_INPUT.
 */
int convert_to_short(char *str, char *res_str);

/**
 * @brief Обрабатывает числа в строке, добавляя их в строку результата.
 * @param str Исходная строка.
 * @param res_str Строка результата.
 * @param i Указатель на индекс в исходной строке.
 * @param j Указатель на индекс в строке результата.
 */
void process_number(char *str, char *res_str, int *i, int *j);

/**
 * @brief Конвертирует строку с инфиксной записью в постфиксную запись.
 * @param str Исходная строка с инфиксной записью.
 * @param res_str Результат конвертации.
 * @return OK, если конвертация прошла успешно, иначе INCORRECT_INPUT.
 */
int my_polish_notation(char *str, char *res_str);

/**
 * @brief Конвертирует строку с инфиксной записью в постфиксную запись.
 * @param str Исходная строка с инфиксной записью.
 * @param res_str Строка результата, содержащая постфиксную запись.
 * @return OK, если конвертация прошла успешно, иначе INCORRECT_INPUT.
 */
int my_infix_to_postfix(char *str, char *res_str);

// int is_stack_empty(Stack *top);

#endif