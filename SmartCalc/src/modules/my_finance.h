/**
 * @file my_finance.h
 * @brief Файл, содержащий реализацию функций для расчетов в финансовой сфере.
 *
 * В этом файле определены структуры и функции, используемые для расчетов
 * депозитов, аннуитетных и дифференцированных кредитов.
 */

#ifndef FINANCE_H
#define FINANCE_H

#include "../my_smart_calc.h"

/**
 * @brief Структура для хранения данных о депозите.
 * @var sum Сумма депозита.
 * @var duration_month Продолжительность депозита в месяцах.
 * @var interest_rate Ставка по депозиту.
 * @var tax_rate Налоговая ставка.
 * @var capitalization Частота капитализации процентов.
 * @var frequency_of_payments Частота платежей процентов.
 */
typedef struct struct_deposit {
  double sum;  ///< Сумма депозита.
  double duration_month;  ///< Продолжительность депозита в месяцах.
  double interest_rate;  ///< Ставка по депозиту.
  double tax_rate;       ///< Налоговая ставка.
  double capitalization;  ///< Частота капитализации процентов.
  double frequency_of_payments;  ///< Частота платежей процентов.
} deposit_calc_struct;

/**
 * @brief Вычисляет ежемесячный платеж по аннуитетному кредиту.
 * @param loan Сумма кредита.
 * @param loan_term Срок кредита в месяцах.
 * @param interest_rate Годовая процентная ставка.
 * @param month_payment Указатель на переменную для хранения ежемесячного
 * платежа.
 * @param total_loan Указатель на переменную для хранения общей суммы кредита.
 * @param interest_rate_payment Указатель на переменную для хранения суммы
 * процентов.
 * @return OK, если вычисления прошли успешно.
 */
int my_credit_calc_ann(double loan, int loan_term, double interest_rate,
                        double *month_payment, double *total_loan,
                        double *interest_rate_payment);

/**
 * @brief Вычисляет ежемесячный платеж по дифференцированному кредиту.
 * @param loan Сумма кредита.
 * @param loan_term Срок кредита в месяцах.
 * @param interest_rate Годовая процентная ставка.
 * @param total_loan Указатель на переменную для хранения общей суммы кредита.
 * @param interest_rate_payment Указатель на переменную для хранения суммы
 * процентов.
 * @param month_payment_min Указатель на переменную для хранения минимального
 * ежемесячного платежа.
 * @param month_payment_max Указатель на переменную для хранения максимального
 * ежемесячного платежа.
 * @return OK, если вычисления прошли успешно.
 */
int my_credit_calc_dif(double loan, int loan_term, double interest_rate,
                        double *total_loan, double *interest_rate_payment,
                        double *month_payment_min, double *month_payment_max);

/**
 * @brief Вычисляет общую сумму депозита, сумму налога и сумму процентов.
 * @param deposit Указатель на структуру с данными о депозите.
 * @param total_amount Указатель на переменную для хранения общей суммы
 * депозита.
 * @param tax_amount Указатель на переменную для хранения суммы налога.
 * @param interest_amount Указатель на переменную для хранения суммы процентов.
 * @return false, если вычисления прошли успешно.
 */
int my_deposit_calc(deposit_calc_struct *deposit, double *total_amount,
                     double *tax_amount, double *interest_amount);

/**
 * @brief Вычисляет сумму процентов без капитализации.
 * @param deposit Указатель на структуру с данными о депозите.
 * @param interest_amount Указатель на переменную для хранения суммы процентов.
 * @param tax_amount Указатель на переменную для хранения суммы налога.
 */
void calculateInterestWithoutCapitalization(deposit_calc_struct *deposit,
                                            double *interest_amount,
                                            double *tax_amount);

/**
 * @brief Вычисляет сумму процентов с капитализацией.
 * @param deposit Указатель на структуру с данными о депозите.
 * @param interest_amount Указатель на переменную для хранения суммы процентов.
 * @param tax_amount Указатель на переменную для хранения суммы налога.
 */
void calculateInterestWithCapitalization(deposit_calc_struct *deposit,
                                         double *interest_amount,
                                         double *tax_amount);

#endif
