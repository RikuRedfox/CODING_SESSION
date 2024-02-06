#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *head = NULL;
int listSize = 0;
int currentSize = 0;

bool isFull() { return currentSize >= listSize; }

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void pushFront(int data) {
  if (isFull()) {
    printf("List is Full.\n");
    return;
  }
  struct Node *newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
    return;
  }
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
  currentSize++;
}

void pushBack(int data) {
  if (isFull()) {
    printf("List is Full.\n");
    return;
  }
  struct Node *newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
    return;
  }
  struct Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
  currentSize++;
}

void pushAtIndex(int index, int data) {
  if (isFull()) {
    printf("List is Full.\n");
    return;
  }

  if (index < 0) {
    printf("Invalid index.\n");
    return;
  }

  if (index == 0) {
    pushFront(data);
    return;
  }

  struct Node *newNode = createNode(data);
  struct Node *temp = head;
  for (int i = 0; i < index - 1; i++) {
    if (temp == NULL) {
      printf("Index out of bounds\n");
      free(newNode);
      return;
    }
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Index out of bounds\n");
    free(newNode);
    return;
  }

  newNode->prev = temp;
  newNode->next = temp->next;
  if (temp->next != NULL) {
    temp->next->prev = newNode;
  }
  temp->next = newNode;
  currentSize++;
}

void popFront() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  struct Node *temp = head;
  head = head->next;
  if (head != NULL) {
    head->prev = NULL;
  }
  free(temp);
  currentSize--;
}

void popBack() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  struct Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  if (temp->prev != NULL) {
    temp->prev->next = NULL;
  } else {
    head = NULL;
  }
  free(temp);
  currentSize--;
}

void popAyIndex(int index) {
  if (index < 0) {
    printf("Invalid index.\n");
    return;
  }

  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  if (index == 0) {
    popFront();
    return;
  }

  struct Node *temp = head;
  for (int i = 0; i < index; i++) {
    if (temp == NULL) {
      printf("Index out of bounds.\n");
      return;
    }
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Index out of bounds.\n");
    return;
  }

  if (temp->prev != NULL) {
    temp->prev->next = temp->next;
  } else {
    head = temp->next;
  }

  if (temp->next != NULL) {
    temp->next->prev = temp->prev;
  }
  free(temp);
  currentSize--;
}

void displayList() {
  struct Node *temp = head;
  printf("List: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void clearList() {
  while (head != NULL) {
    struct Node *temp = head;
    head = head->next;
    free(temp);
  }
}

void initializeList(int size) {
  clearList();
  listSize = size;
  currentSize = 0;
}

int main(void) {
  int choice, data, index;

  printf("Enter the initial size of the list: ");
  scanf("%d", &listSize);
  initializeList(listSize);

  do {
    printf("\nDoubly Linked List Operations:\n");
    printf("1. Push.\n");
    printf("2. Pop.\n");
    printf("3. Display List.\n");
    printf("4. Clear List.\n");
    printf("5. Change List Size. [List wil be cleared.]\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data to push: ");
      scanf("%d", &data);

      printf("1. Push Front.\n");
      printf("2. Push Back.\n");
      printf("3. Push by Index\n");
      printf("Enter sub-choice: ");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
        pushFront(data);
        break;
      case 2:
        pushBack(data);
        break;
      case 3:
        printf("Enter index: ");
        scanf("%d", &index);
        pushAtIndex(index, data);
        break;
      default:
        printf("Invalid sub-choice.\n");
      }
      break;
    case 2:
      printf("1. Pop Front.\n");
      printf("2. Pop Back.\n");
      printf("3. Pop by Index\n");
      printf("Enter sub-choice: ");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
        popFront();
        break;
      case 2:
        popBack();
        break;
      case 3:
        printf("Enter index: ");
        scanf("%d", &index);
        popAyIndex(index);
        break;
      default:
        printf("Invalid sub-choice.\n");
      }
      break;
    case 3:
      displayList();
      break;
    case 4:
      clearList();
      printf("List cleared.\n");
      break;
    case 5:
      printf("Enter the new size of the list: ");
      scanf("%d", &listSize);
      initializeList(listSize);
      printf("List size changed and initialized.\n");
      break;
    case 0:
      clearList();
      printf("Exiting . . .\n");
      break;
    default:
      printf("Invalid choice.\n");
    }

  } while (choice != 0);

  return 0;
}