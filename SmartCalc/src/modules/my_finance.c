#include "my_finance.h"

int my_credit_calc_ann(double loan, int loan_term, double interest_rate,
                        double *month_payment, double *total_loan,
                        double *interest_rate_payment) {
  int status = OK;
  double y = interest_rate / (12 * 100);
  // Коэффициент аннуитета
  double k = y * powl(1 + y, loan_term) / (powl(1 + y, loan_term) - 1);
  // Ежемесячный аннуитетный платеж
  *month_payment = (k * loan);
  *interest_rate_payment = (*month_payment * loan_term) - loan;
  *total_loan = *interest_rate_payment + loan;

  return status;
}

int my_credit_calc_dif(double loan, int loan_term, double interest_rate,
                        double *total_loan, double *interest_rate_payment,
                        double *month_payment_min, double *month_payment_max) {
  int status = OK;
  double monthly_interest_rate =
      interest_rate / (12 * 100);  // Преобразование в месячную ставку
  double credit_amount_const = loan / (double)loan_term;
  *month_payment_min = 0;
  *month_payment_max = loan * monthly_interest_rate + credit_amount_const;
  double const_loan = loan;
  for (int i = 0; loan > 0; i++) {
    *interest_rate_payment += loan * monthly_interest_rate;
    if (i == loan_term - 1)
      *month_payment_min = loan * monthly_interest_rate + credit_amount_const;
    loan -= credit_amount_const;
  }
  *total_loan = const_loan + *interest_rate_payment;

  return status;
}

// int main() {
//     double loan = 1000000;
//     int loan_term = 18;
//     int interest_rate = 20;
//     double month_payment = 0;
//     double total_loan = 0;
//     double interest_rate_payment = 0;
//     double month_payment_min = 0;
//     double month_payment_max = 0;
//     // int status = credit_calc_ann(loan, loan_term, interest_rate,
//     &month_payment, &total_loan, &interest_rate_payment); int status =
//     credit_calc_dif(loan, loan_term, interest_rate, &total_loan,
//     &interest_rate_payment, &month_payment_min, &month_payment_max);
//     printf("%lf\n", month_payment_max);
//     printf("%lf\n", month_payment_min);
//     printf("%lf\n", total_loan);
//     printf("%lf\n", interest_rate_payment);

//     return 0;
// }

int my_deposit_calc(deposit_calc_struct *deposit, double *total_amount,
                     double *tax_amount, double *interest_amount) {
  int error = false;
  double origin_deposit = deposit->sum;

  if (!deposit->capitalization) {
    calculateInterestWithoutCapitalization(deposit, interest_amount,
                                           tax_amount);
  } else {
    calculateInterestWithCapitalization(deposit, interest_amount, tax_amount);
  }

  *total_amount = origin_deposit + *interest_amount;

  return error;
}

// Функция для расчета процентов без капитализации
void calculateInterestWithoutCapitalization(deposit_calc_struct *deposit,
                                            double *interest_amount,
                                            double *tax_amount) {
  *interest_amount =
      deposit->sum * deposit->interest_rate * deposit->duration_month / 1200.0;
  if (*interest_amount - 160000 > 0)
    *tax_amount = (*interest_amount - 160000) * deposit->tax_rate / 100;
  else
    *tax_amount = 0.0;
}

void calculateInterestWithCapitalization(deposit_calc_struct *deposit,
                                         double *interest_amount,
                                         double *tax_amount) {
  double num_pay = 1.0;
  if (deposit->frequency_of_payments > deposit->duration_month) {
    deposit->frequency_of_payments = deposit->duration_month;
  } else {
    num_pay = (12.0 / deposit->frequency_of_payments);
  }
  double interest_sum = 0;
  double period =
      ceil(deposit->duration_month / deposit->frequency_of_payments);
  double year_interest = 0.0;
  int count_month = 1;
  int month = deposit->duration_month;

  while (period > 0) {
    double interest =
        deposit->sum * ((deposit->interest_rate / 100.0) /
                        (12.0 / (month < deposit->frequency_of_payments
                                     ? month
                                     : deposit->frequency_of_payments)));
    deposit->sum += interest;
    interest_sum += interest;
    year_interest += interest;
    if (count_month == num_pay - 1 || period <= 1 ||
        (num_pay == 1 && ((int)deposit->duration_month %
                          (int)deposit->frequency_of_payments) == 0)) {
      *tax_amount +=
          fmax(0.0, year_interest - 160000) * deposit->tax_rate / 100;
      count_month = 0;
      year_interest = 0.0;
    } else {
      count_month++;
    }
    period--;
    month = deposit->duration_month - deposit->frequency_of_payments;
  }
  *interest_amount = interest_sum;
}

// old version
// void calculateInterestWithCapitalization(deposit_calc_struct *deposit, double
// *interest_amount, double *tax_amount) {
//     double num_pay = 1.0;
//     if(deposit->frequency_of_payments>deposit->duration_month) {
//         deposit->frequency_of_payments = deposit->duration_month;
//     } else {
//         num_pay = (12.0/deposit->frequency_of_payments);
//     }
//     double interest_sum = 0;
//     double period = ceil(deposit->duration_month /
//     deposit->frequency_of_payments); double year_interst, yaer_tax = 0.0; int
//     month = deposit->duration_month; int count_month = 1; //year = 0,
//     while(period > 0) {
//         double interest = 0;
//         if(month < deposit->frequency_of_payments) {
//             interest = deposit->sum * ((deposit->interest_rate /100.0)
//             /(12.0/month));
//         } else {
//             interest = deposit->sum * ((deposit->interest_rate /100.0)
//             /(12.0/deposit->frequency_of_payments));
//         }
//         deposit->sum += interest;
//         interest_sum += interest;
//         year_interst += interest;
//         if(count_month == num_pay-1||period<=1||(num_pay==1 &&
//         ((int)deposit->duration_month %
//         (int)deposit->frequency_of_payments)==0)) {
//             if(year_interst - 160000 > 0)
//                 yaer_tax = (year_interst - 160000) * deposit->tax_rate/100;
//             else
//                 yaer_tax = 0.0;
//             count_month = 0;
//             year_interst = 0.0;
//             *tax_amount +=yaer_tax;
//         } else{
//             count_month++;
//         }
//         period--;
//         month = deposit->duration_month - deposit->frequency_of_payments;
//     }
//     *interest_amount = interest_sum;
// }

// int main() {

//     deposit_calc_struct deposit = {0};
//     deposit.sum = 100000;
//     deposit.duration_month = 12;
//     deposit.interest_rate = 150;
//     deposit.tax_rate = 13;
//     deposit.capitalization = 1;
//     deposit.frequency_of_payments = 1;
//     // deposit.contribution_amount = 0;
//     // deposit.periodicity_of_contribution = NEVER;
//     // deposit.whithdrawl_amount = 0;
//     // deposit.periodicity_of_whithdrawl = NEVER;

//     double total_amount = 0;
//     double tax_amount = 0;
//     double interest_amount = 0;

//     my_deposit_calc(&deposit, &total_amount, &tax_amount, &interest_amount);
//     // my_ebncalc(&deposit, &total_amount, &tax_amount, &interest_amount);
//     printf("%llf\n", interest_amount);
//     printf("%llf\n", total_amount);
//     printf("%llf\n", tax_amount);

//     return 0;
// }

// 89055029737
