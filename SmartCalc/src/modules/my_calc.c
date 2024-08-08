
#include "my_calc.h"

double arithmetic_func(char func, double num, int *status) {
  double result = 0.0;

  if (func == 'c') {
    result = cos(num);
  } else if (func == 's') {
    result = sin(num);
  } else if (func == 't') {
    result = tan(num);
  } else if (func == 'C') {
    if (num < -1 || num > 1)
      *status = CALCULATION_ERROR;
    else
      result = acos(num);
  } else if (func == 'S') {
    if (num < -1 || num > 1)
      *status = CALCULATION_ERROR;
    else
      result = asin(num);
  } else if (func == 'T') {
    result = atan(num);
  } else if (func == 'q') {
    result = sqrt(num);
  } else if (func == 'l') {
    if (num <= 0)
      *status = CALCULATION_ERROR;
    else
      result = log(num);
  } else if (func == 'L') {
    if (num <= 0)
      *status = CALCULATION_ERROR;
    else
      result = log10(num);
  } else {
    *status = CALCULATION_ERROR;
  }

  return result;
}

double calculateRPN(char *expression, double *result, double x) {
  int status = OK;  // Статус проверки
  D_Stack *stack = NULL;
  char expression_copy[MAX_LEN];
  strncpy(expression_copy, expression, MAX_LEN - 1);
  char *token = strtok(expression_copy, " ");

  while (token != NULL && !status) {
    if (isdigit(token[0])) {
      push_d(&stack, atof(token));
    } else if (token[0] == 'x') {
      push_d(&stack, x);
    } else {
      double result = 0.0;
      if (strchr(FUNCS, token[0])) {
        result = arithmetic_func(token[0], pop_d(&stack), &status);
      } else {
        double operand2 = pop_d(&stack);
        double operand1 = pop_d(&stack);
        if (token[0] == '+') {
          result = operand1 + operand2;
        } else if (token[0] == '-') {
          result = operand1 - operand2;
        } else if (token[0] == '*') {
          result = operand1 * operand2;
        } else if (token[0] == '/') {
          if (operand2 != 0) {
            result = operand1 / operand2;
          } else {
            status = DIV_BY_ZERO;
          }
        } else if (token[0] == '^') {
          result = pow(operand1, operand2);
        } else if (token[0] == 'm') {
          result = fmodl(operand1, operand2);

        } else {
          status = CALCULATION_ERROR;
        }
      }
      push_d(&stack, result);
    }
    token = strtok(NULL, " ");
  }
  if (!is_stack_empty_d(stack)) {
    *result = pop_d(&stack);
    if (isnan(*result) || isinf(*result)) status = NAN_OR_INF;
  } else {
    status = true;
  }

  return status;
}

int full_calcuation(char *infix_expr, double *num, char *x) {
  char postfix_expr[256];
  char ppostfix_expr[256];
  int status = OK;
  status = my_infix_to_postfix(infix_expr, postfix_expr);
  if (strchr(postfix_expr, 'x') != NULL) {
    status = my_infix_to_postfix(x, ppostfix_expr);
  }
  if (!status) {
    if (strchr(postfix_expr, 'x') != NULL) {
      double x_res = 0.0;
      status = calculateRPN(ppostfix_expr, &x_res, 0);
      if (!status) status = calculateRPN(postfix_expr, num, x_res);
    } else
      status = calculateRPN(postfix_expr, num, 0);
  }
  return status;
}

// int main() {
//     //  char *infix_expr = "29+(-4)";
//      char *infix_expr =
//      "(sin(30)*sqrt(625)+cos(60)*ln(34)+tan(50))/(asin(0.5)^(2)+acos(-(0.5))*log(100)+atan(0.5))";
//     //  char *infix_expr = "1/22.21+(2+3)/((9-2)+2-6/7)";
//     // char *infix_expr = "cos(0)+sin(90)";
//     //  char *infix_expr = "sin(ln(4)/6)+cos(3mod6/3)^2-sin(atan(10)/2)";
// // printf("%f\n", sin(90));
//     //  char *infix_expr = "-1/2+(2+3)/(sin(9-2)^2-6/7)";
//     //  char *infix_expr = "-1/2+(-2+3)/(-sin(+9-2)^2-6/7)";
//     //  char *infix_expr = NULL;
//     char postfix_expr[256];
//     char ppostfix_expr[256];
//     double num = 0.0;
//     int status = OK;
//     status = my_infix_to_postfix(infix_expr, postfix_expr);
//     if (!status) {
//         printf("Инфиксное выражение: %s\n", infix_expr);
//         printf("Постфиксное выражение: %s\n", postfix_expr);
//         status = calculateRPN(postfix_expr,&num);
//         printf("Результат вычисления выражения: %.15f\n",num);

//     } else {
//         printf("Инфиксное выражение: %s\n", infix_expr);
//         printf("Постфиксное выражение: %s\n", postfix_expr);
//         printf("code error = %d\n", status);
//     }
//     return 0;
// }