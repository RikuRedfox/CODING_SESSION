#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  int front;
  int rear;
  int size;
  int capacity;
} Queue;

// Function to initialize the queue
void initialize(Queue *queue, int capacity) {
  queue->array = (int *)malloc(capacity * sizeof(int));
  queue->front = 0;
  queue->rear = -1;
  queue->size = 0;
  queue->capacity = capacity;
}

// Check if the queue is full
int isFull(Queue *queue) { return queue->size == queue->capacity; }

// Check if the queue is empty
int isEmpty(Queue *queue) { return queue->size == 0; }

// Function to enqueue an element into the queue (push)
void enqueue(Queue *queue, int value) {
  if (isFull(queue)) {
    printf("Queue Overflow: Cannot enqueue element.\n");
    return;
  }
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = value;
  queue->size++;
}

// Function to dequeue an element from the queue (pop)
int dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue Underflow: Cannot dequeue element from an empty queue.\n");
    return -1;
  }
  int frontValue = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size--;
  return frontValue;
}

// Function to view the front element of the queue
int front(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
    return -1;
  }
  return queue->array[queue->front];
}

// Function to deallocate memory and clean up the queue
void cleanup(Queue *queue) {
  free(queue->array);
  queue->front = 0;
  queue->rear = -1;
  queue->size = 0;
  queue->capacity = 0;
}

int main(void) {
  int queueSize;
  printf("Enter the size of the queue: ");
  scanf("%d", &queueSize);

  Queue queue;
  initialize(&queue, queueSize);

  int choice, value;
  while (1) {
    printf("\nChoose an operation:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. View Front\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the value to enqueue: ");
      scanf("%d", &value);
      enqueue(&queue, value);
      break;
    case 2:
      value = dequeue(&queue);
      if (value != -1)
        printf("Dequeued element: %d\n", value);
      break;
    case 3:
      value = front(&queue);
      if (value != -1)
        printf("Front element: %d\n", value);
      break;
    case 4:
      cleanup(&queue);
      printf("Exiting . . . \n");
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return -1;
}
