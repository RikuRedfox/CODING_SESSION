#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  int top;
  int size;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack, int size) {
  stack->array = (int *)malloc(size * sizeof(int));
  stack->top = -1;
  stack->size = size;
}

// Function to check if the stack is full
int isFull(Stack *stack) { return stack->top == stack->size - 1; }

// Function to check if the stack is empty
int isEmpty(Stack *stack) { return stack->top == -1; }

void push(Stack *stack, int value) {
  if (isFull(stack)) {
    printf("Stack Overflow: Cannot push element onto to stack.\n");
    return;
  }
  stack->array[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack Underflow: Cannot pop element from an empty stack.\n");
    return -1;
  }
  return stack->array[stack->top--];
}

// Function to peek the top element of the stack
int peek(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty.\n");
    return -1;
  }
  return stack->array[stack->top];
}

// Function to deallocate memory and clean up the stack
void cleanup(Stack *stack) {
  free(stack->array);
  stack->top = -1;
  stack->size = 0;
}

int main(void) {
  int stackSize;
  printf("Enter the size of the stack: ");
  scanf("%d", &stackSize);

  Stack stack;
  initialize(&stack, stackSize);

  int choice, value;

  while (1) {
    printf("\nChoose an operation:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the value to push: ");
      scanf("%d", &value);
      push(&stack, value);
      break;
    case 2:
      value = pop(&stack);
      if (value != -1)
        printf("Popped element: %d\n", value);
      break;
    case 3:
      value = peek(&stack);
      if (value != -1)
        printf("Top element: %d\n", value);
      break;
    case 4:
      cleanup(&stack);
      printf("Exiting . . .\n");
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
