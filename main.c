#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int line_number, char *argument) {
  if (top == STACK_SIZE - 1) {
    printf("Stack overflow. Unable to push element.\n");
    exit(EXIT_FAILURE);
  }

  int value = atoi(argument);
  if (value == 0 && strcmp(argument, "0") != 0) {
    printf("L%d: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
  }

  stack[++top] = value;
}

void pall() {
  int i;
  for (i = top; i >= 0; i--) {
    printf("%d\n", stack[i]);
  }
}

int main() {
  // Example usage
  push(1, "10");
  push(2, "20");
  push(3, "30");
  pall();

  return 0;
}
