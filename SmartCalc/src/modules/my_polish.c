#include "my_polish.h"

int get_priority(char ch) {
  int priority = -1;

  if (ch == '(' || ch == ')')
    priority = 0;
  else if (ch == '+' || ch == '-')
    priority = 1;
  else if (ch == '*' || ch == '/' || ch == 'm')
    priority = 2;
  else if (ch == '^')
    priority = 3;
  else if (strchr(FUNCS, ch))
    priority = 4;
  return priority;
}

int priority_compare(char op1, char op2) {
  return get_priority(op1) >= get_priority(op2);
}

//выделить в отдельную функцию
int convert_to_short(char *str, char *res_str) {
  int status = OK;  // Статус проверки
  if (str == NULL || res_str == NULL) return INCORRECT_INPUT;
  memset(res_str, '\0', 256);
  int len = strlen(str);
  for (int i = 0; i < len && !status; i++) {
    if (str[i] == ' ') {
      continue;
    } else if (strncmp(&str[i], "sin", 3) == 0) {
      strcat(res_str, "s");
      i += 2;
    } else if (strncmp(&str[i], "cos", 3) == 0) {
      strcat(res_str, "c");
      i += 2;
    } else if (strncmp(&str[i], "tan", 3) == 0) {
      strcat(res_str, "t");
      i += 2;
    } else if (strncmp(&str[i], "acos", 4) == 0) {
      strcat(res_str, "C");
      i += 3;
    } else if (strncmp(&str[i], "asin", 4) == 0) {
      strcat(res_str, "S");
      i += 3;
    } else if (strncmp(&str[i], "atan", 4) == 0) {
      strcat(res_str, "T");
      i += 3;
    } else if (strncmp(&str[i], "sqrt", 4) == 0) {
      strcat(res_str, "q");
      i += 3;
    } else if (strncmp(&str[i], "ln", 2) == 0) {
      strcat(res_str, "l");
      i++;
    } else if (strncmp(&str[i], "log", 3) == 0) {
      strcat(res_str, "L");
      i += 2;
    } else if (strncmp(&str[i], "mod", 3) == 0) {
      strcat(res_str, "m");
      i += 2;
    } else if ((str[i] == '+') && (i == 0 || (i > 0 && str[i - 1] == '('))) {
      continue;
    } else {
      strncat(res_str, &str[i], 1);
    }
  }
  return status;
}

int my_infix_to_postfix(char *str, char *res_str) {
  char postfix_expr[256];
  int status = OK;  // Статус проверки
  status = my_valid_str(str);
  if (res_str == NULL && !status) return INCORRECT_INPUT;
  if (!status && convert_to_short(str, postfix_expr)) {
    status = INCORRECT_INPUT;
  }
  if (!status && my_polish_notation(postfix_expr, res_str)) {
    status = INCORRECT_INPUT;
  }
  return status;
}

void pop_plus_space(Stack **stack, char *res_str, int *j) {
  res_str[(*j)++] = pop(stack);
  res_str[(*j)++] = ' ';
}

// Функция для обработки операторов

void process_operator(Stack **stack, char *res_str, int *j, char op) {
  while (!is_stack_empty(*stack) && priority_compare((*stack)->data, op)) {
    res_str[(*j)++] = pop(stack);
    res_str[(*j)++] = ' ';
  }
  push(stack, op);
}

// Функция для обработки чисел

void process_number(char *str, char *res_str, int *i, int *j) {
  while (isdigit(str[*i]) || str[*i] == '.') {
    res_str[(*j)++] = str[(*i)++];
  }
  res_str[(*j)++] = ' ';
  (*i)--;
}

int my_polish_notation(char *str, char *res_str) {
  Stack *stack = NULL;
  int status = OK;  // Статус проверки

  if (str == NULL || res_str == NULL) return INCORRECT_INPUT;
  memset(res_str, '\0', 256);
  int len = strlen(str);
  int i = 0, j = 0;

  for (; i < len && !status; i++) {
    if (str[i] == '(') {
      push(&stack, str[i]);
    } else if (str[i] == ')') {
      while (!is_stack_empty(stack) && stack->data != '(') {
        pop_plus_space(&stack, res_str, &j);
      }
      if (!is_stack_empty(stack) && stack->data == '(') {
        pop(&stack);  // Удаляем открывающую скобку из стека
      }
    } else if (isdigit(str[i]) || str[i] == '.') {
      process_number(str, res_str, &i, &j);
    } else if (str[i] == '-') {
      if (i == 0 || str[i - 1] == '(') {
        res_str[j++] = '0';
        res_str[j++] = ' ';
      }
      process_operator(&stack, res_str, &j, str[i]);
    } else if (strchr("m+*/^", str[i])) {
      process_operator(&stack, res_str, &j, str[i]);
    } else if (strchr(FUNCS, str[i])) {
      push(&stack, str[i]);
    } else if (str[i] == 'x') {
      res_str[j++] = str[i++];
      res_str[j++] = ' ';
      i--;
    }
  }
  while (!is_stack_empty(stack)) {
    pop_plus_space(&stack, res_str, &j);
  }
  return OK;
}

// int main() {
//      char *infix_expr = "asin(0.5)^(2)+acos(-(0.5))";
//     //  char *infix_expr = "1/22.21+(2+3)/((9-2)+2-6/7)";
//     //  char *infix_expr = "cos(4)+sin(15)";
//     //  char *infix_expr = "sin(ln(4)/6)+cos(4mod3/3)^2-sin(atan(10)/2)";

//     //  char *infix_expr = "-1/2+(2+3)/(sin(9-2)^2-6/7)";
//     //  char *infix_expr = "-1/2+(-2+3)/(-sin(+9-2)^2-6/7)";
//     //  char *infix_expr = NULL;
//     char postfix_expr[256];
//     char ppostfix_expr[256];
//     int status = OK;
//     status = my_infix_to_postfix(infix_expr, postfix_expr);
//     if (!status) {
//         printf("Инфиксное выражение: %s\n", infix_expr);
//         printf("Постфиксное выражение: %s\n", postfix_expr);
//     }else{
//         printf("code error = %d\n", status);
//     }
//     //     if (!convert_to_short(infix_expr, postfix_expr)) {
//     //     printf("Инфиксное выражение: %s\n", infix_expr);
//     //     printf("Постфиксное выражение: %s\n", postfix_expr);
//     // }
//     // // if (my_infix_to_postfix(postfix_expr, ppostfix_expr)) {
//     // //     printf("Инфиксное выражение: %s\n", postfix_expr);
//     // //     printf("Постфиксное выражение: %s\n", ppostfix_expr);
//     // // }
//     // if (!my_polish_notation(postfix_expr, ppostfix_expr)) {
//     //     printf("Инфиксное выражение: %s\n", postfix_expr);
//     //     printf("Постфиксное выражение: %s\n", ppostfix_expr);
//     // }
//     return 0;
// }
