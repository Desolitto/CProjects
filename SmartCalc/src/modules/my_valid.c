#include "my_valid.h"

int my_valid_str(char *str) {
  int status = OK;
  if (str == NULL) {
    status = INCORRECT_INPUT;
  } else if (strlen(str) == 0 || strlen(str) > MAX_LEN) {
    status = INCORRECT_INPUT;  // проверка на длину строки
                               // printf("LEN\n");
  } else if (my_valid_bkt(str)) {  // проверка на скобки
    // printf("BKT\n");
    status = INCORRECT_INPUT;
  } else if (my_valid_point(str)) {
    status = INCORRECT_INPUT;
    // printf("POINT\n");
  } else if (my_valid_op(str)) {
    status = INCORRECT_INPUT;
    // printf("OP\n");
  } else if (my_valid_trig(str)) {
    status = INCORRECT_INPUT;
    // printf("TRIG\n");
  } else if (my_valid_other_func(str)) {
    status = INCORRECT_INPUT;
    // printf("OTHER_FUNC\n");
  } else if (my_valid_num(str)) {
    status = INCORRECT_INPUT;
    // printf("NUM\n");
  } else if (my_valid_x(str)) {
    status = INCORRECT_INPUT;
    // printf("X\n");
  } else if (my_valid_e(str)) {
    status = SORRY_CANT_CALC_WITH_E;
    // printf("E\n");
  }
  return status;
}

int my_valid_bkt(char *str) {
  int left_bkt = 0;   // Счетчик открывающих скобок
  int right_bkt = 0;  // Счетчик закрывающих скобок
  int status = OK;    // Статус проверки
  int len = (int)strlen(str);
  for (int i = 0; i < len && !status; i++) {
    if (str[i] == '(') {
      left_bkt++;
      if (str[i + 1] == ')') {
        status = INCORRECT_INPUT;
      }
    }
    if (str[i] == ')') {
      right_bkt++;
      if (left_bkt < right_bkt) {
        status = INCORRECT_INPUT;
      }
    }
    if ((isdigit(str[i]) || str[i] == ')') && str[i + 1] == '(') {
      status = INCORRECT_INPUT;
    }
  }
  if (left_bkt != right_bkt) {
    status = INCORRECT_INPUT;
  }

  return status;
}

// Функция для проверки символа на точку и её положение
int check_dot_position(char *str, int index, int *point_counter) {
  if (str[index] == '.' && index != 0) {
    (*point_counter)++;
    if (index > 0 && (!isdigit(str[index - 1]) || !isdigit(str[index + 1]))) {
      return INCORRECT_INPUT;
    }
  } else if (str[index] == '.' && index == 0) {
    return INCORRECT_INPUT;
  }
  return OK;
}

int my_valid_point(char *str) {
  int status = OK;        // Статус проверки
  int point_counter = 0;  // счетчик точек
  int in_number = 0;  // Флаг, указывающий, что мы внутри числа
  int len = (int)strlen(str);

  for (int i = 0; i < len && !status; i++) {
    if (isdigit(str[i]) || str[i] == '.') {
      status = check_dot_position(str, i, &point_counter);
      in_number = 1;  // Мы внутри числа
    } else if (in_number && point_counter < 2) {
      // Если мы встретили символ, который не является частью числа,
      // и мы были внутри числа, то сбрасываем счетчик точек.
      point_counter = 0;
      in_number = 0;
    }
    if (in_number && point_counter > 1) {
      status = INCORRECT_INPUT;
    }
  }
  return status;
}
/// Фулл версия
// int my_valid_point(char *str) {
//   int status = OK;        // Статус проверки
//   int point_counter = 0;  // счетчик точек
//   int in_number = 0;  // Флаг, указывающий, что мы внутри числа
//   int len = (int)strlen(str);
//   for (int i = 0; i < len && !status; i++) {
//     if (isdigit(str[i]) || str[i] == '.') {
//       if (str[i] == '.' && i != 0) {
//         point_counter++;
//         if (i > 0 && (!isdigit(str[i - 1]) ||
//                       !isdigit(str[i + 1]))) {
//           status = INCORRECT_INPUT;
//         }

//       } else if (str[i] == '.' && i == 0) {
//         status = INCORRECT_INPUT;
//       }
//       in_number = 1;  // Мы внутри числа
//     } else if (in_number && point_counter < 2) {
//       // Если мы встретили символ, который не является частью числа,
//       // и мы были внутри числа, то сбрасываем счетчик точек.
//       point_counter = 0;
//       in_number = 0;
//     }
//     if (in_number && point_counter > 1) {
//       status = INCORRECT_INPUT;
//     }
//   }
//   return status;
// }

int my_valid_op(char *str) {
  int status = OK;
  int len = (int)strlen(str);
  for (int i = 0; i < len && !status; i++) {
    if (strchr(OPERATORS, str[i]) && i + 1 < len &&
        strchr(OPERATORS, str[i + 1]))
      status = INCORRECT_INPUT;
    if ((i == 0 || i == len - 1) && strchr("/*^", str[i])) {
      status = INCORRECT_INPUT;
    }
    if (i > 0 && (strchr("/*^", str[i]) && str[i - 1] == '(')) {
      status = INCORRECT_INPUT;
    }
    if (i == len - 1 && strchr("+-", str[i])) {
      status = INCORRECT_INPUT;
    }
    if (str[i] == 'm') {
      status = check_m_operator(str, &i);
    }
  }
  return status;
}

int check_m_operator(char *str, int *i) {
  int status = OK;
  int len = (int)strlen(str);
  if (*i == 0 || *i > len - 4) {
    status = INCORRECT_INPUT;
  }
  if (*i != 0 || *i < len - 4) {
    if (*i > 0 && !isdigit(str[*i - 1]) &&
        (strchr(")x", str[*i - 1]) == NULL)) {
      status = INCORRECT_INPUT;
    }
    if (*i > 0 && !isdigit(str[*i + 3]) &&
        (strchr("(x", str[*i + 3]) == NULL) && (*i + 3 < len)) {
      status = INCORRECT_INPUT;
    }
  }
  *i += 2;
  return status;
}

int check_lim_bkt(char *str, int i, int length) {
  int status = OK;
  int len = (int)strlen(str);
  if (i > len - length) {
    status = INCORRECT_INPUT;
  }
  if (i > 0 && i <= len - length) {
    if (i > 0 && (strchr(")x", str[i - 1]) != NULL || isdigit(str[i - 1]))) {
      status = INCORRECT_INPUT;
    }
  }
  return status;
}

int my_valid_trig(char *str) {
  int status = OK;
  int len = (int)strlen(str);
  for (int i = 0; i < len && !status; i++) {
    if (str[i] == 'a') {
      if (str[i + 4] != '(') status = INCORRECT_INPUT;
      if (check_lim_bkt(str, i, 6)) {
        status = INCORRECT_INPUT;
      }
      i += 3;
    }
    if ((str[i] == 'c' || (str[i] == 't' && str[i + 1] == 'a') ||
         (str[i] == 's' && str[i + 1] == 'i'))) {
      if (str[i + 3] != '(') status = INCORRECT_INPUT;
      if (check_lim_bkt(str, i, 5)) {
        status = INCORRECT_INPUT;
      }
      i += 2;
    }
  }
  return status;
}

int my_valid_other_func(char *str) {
  int status = OK;
  int len = (int)strlen(str);
  for (int i = 0; i < len && !status; i++) {
    if (str[i] == 'l' && str[i + 1] == 'n') {
      if (str[i + 2] != '(') status = INCORRECT_INPUT;
      if (check_lim_bkt(str, i, 5)) {
        status = INCORRECT_INPUT;
      }
      i++;
    }
    if (str[i] == 'l' && str[i + 1] == 'o') {
      if (str[i + 3] != '(') status = INCORRECT_INPUT;
      if (check_lim_bkt(str, i, 6)) {
        status = INCORRECT_INPUT;
      }
      i += 2;
    }
    if (str[i] == 's' && str[i + 1] == 'q') {
      if (str[i + 4] != '(') status = INCORRECT_INPUT;
      if (check_lim_bkt(str, i, 7)) {
        status = INCORRECT_INPUT;
      }
      if (str[i + 5] == '-') {
        status = INCORRECT_INPUT;
      }
      i += 3;
    }
  }
  return status;
}

int my_valid_num(char *str) {
  int status = OK;  // Статус проверки
  int len = (int)strlen(str);
  for (int i = 0; i < len && !status; i++) {
    if (i > 0 && str[i - 1] == ')' && (isdigit(str[i]))) {
      status = INCORRECT_INPUT;
    }
    if (i > 0 && str[i] == ')' && strchr(OPERATORS, str[i - 1]) != NULL) {
      status = INCORRECT_INPUT;
    }
    if (i > 0 && str[i] == '(' && strchr("/*^", str[i + 1]) != NULL) {
      status = INCORRECT_INPUT;
    }
    if (i > 0 && isdigit(str[i - 1]) && strchr("cstal", str[i]) != NULL) {
      status = INCORRECT_INPUT;
    }
  }
  return status;
}

int my_valid_x(char *str) {
  int status = OK;  // Статус проверки
  int len = strlen(str);

  for (int i = 0; i < len; i++) {
    if (str[i] == 'x' && len != 1) {
      if (len == 1 ||
          (i == 0 && (strchr(")x", str[i + 1]) || isdigit(str[i + 1])))) {
        status = INCORRECT_INPUT;
      }
      if (i > 0 && (strchr(")x", str[i - 1]) || isdigit(str[i - 1]))) {
        status = INCORRECT_INPUT;
      }
      if (i == len - 1 && (strchr(")x", str[i - 1]) || isdigit(str[i - 1]))) {
        status = INCORRECT_INPUT;
      }
      if (i < len - 1 &&
          (isdigit(str[i + 1]) || str[i + 1] == '(' || str[i + 1] == 'x')) {
        status = INCORRECT_INPUT;
      }
    }
  }
  return status;
}

int my_valid_e(char *str) {
  int status = OK;
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] == 'e') {
      status = SORRY_CANT_CALC_WITH_E;
    }
  }
  return status;
}

// int main() {
//     // char *infix_expr = "3.2*0.20*0.3*2mod7+2+sin(sin(2)+2.2)";
//     // char *infix_expr =
//     // "-3.2*0.20^0.3+atan(asin(acos(tan(cos(sin(2)+2.2)))))";
//     char *infix_expr = "sin-(2)";
//     // 3.2*0.20*0.3*2mod7+sin(sin(2)2)
//     // 3.2*0.20*0.3*2mod7+2+sin(sin(2)+2.2)
//     //   char *infix_expr = "+x-(-21)";
//     //   char *infix_expr = "3.2*0.20*0.3";
//     //   char *infix_expr = "3.14+56*((x)*22)";
//     //   char *infix_expr = "2.123123123+12398172387126387123613412";
//     //   char *infix_expr = "3.14";
//     // char *infix_expr = "cos(4)+sin(15)";
//     // char postfix_expr[255];
//     printf("valid %d", my_valid_str(infix_expr));
//     // if (my_infix_to_postfix(infix_expr, postfix_expr)) {
//     //   printf("Инфиксное выражение: %s\n", infix_expr);
//     //   printf("Постфиксное выражение: %s\n", postfix_expr);
//     // }

//     return 0;
// }
