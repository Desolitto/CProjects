

#include "my_stack.h"

Stack *initStack(char data) {
  Stack *node = (Stack *)calloc(1, sizeof(Stack));
  node->data = data;
  node->prev = NULL;
  return node;
}

int push(Stack **top, char data) {
  int status = OK;  // Статус проверки

  Stack *node = initStack(data);

  if (node != NULL) {
    node->prev = *top;
    *top = node;
  } else {
    status = MEMORY_ERROR;
  }
  return status;
}

char pop(Stack **top) {
  Stack *temp = *top;
  char data = temp->data;
  *top = (*top)->prev;
  free(temp);
  return data;
}

int is_stack_empty(Stack *top) { return top == NULL; }

D_Stack *initStack_d(double data) {
  D_Stack *node = (D_Stack *)calloc(1, sizeof(D_Stack));
  node->data = data;
  node->prev = NULL;
  return node;
}

int push_d(D_Stack **top, double data) {
  int status = OK;  // Статус проверки

  D_Stack *node = initStack_d(data);

  if (node != NULL) {
    node->prev = *top;
    *top = node;
  } else {
    status = MEMORY_ERROR;
  }
  return status;
}

double pop_d(D_Stack **stack) {
  if (*stack == NULL) {
    return MEMORY_ERROR;
  }
  D_Stack *temp = *stack;
  double data = temp->data;
  *stack = temp->prev;
  free(temp);
  return data;
}

int is_stack_empty_d(D_Stack *top) { return top == NULL; }
