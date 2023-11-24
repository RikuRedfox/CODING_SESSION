#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 12
#define FILE_NAME_SIZE 50
#define LINE_SIZE 100

typedef struct {
  uint16_t month;
  uint16_t day;
  uint16_t year;
} Birthday;

struct Node {
  Birthday birthday;
  struct Node *next;
};

// Constructor
Birthday createBirthday(uint16_t month, uint16_t day, uint16_t year) {
  Birthday b = {month, day, year};
  return b;
}

uint32_t hash(const Birthday *b) {
  return (b->day + b->month + b->year) % HASH_TABLE_SIZE;
}

uint32_t equal(const Birthday *b, const Birthday *b2) {
  return (b->day == b2->day && b->month == b2->month && b->year == b2->year);
}

void freeHashTable(struct Node *hashTable[]) {
  for (uint16_t i = 0; i < HASH_TABLE_SIZE; i++) {
    struct Node *current = hashTable[i];
    while (current != NULL) {
      struct Node *temp = current;
      current = current->next;
      free(temp);
    }
  }
}

void insertIntoHashTable(struct Node *hashTable[], const Birthday *birthday) {
  int h = hash(birthday);

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    perror("Error allocation memory for a new node.\n");
    freeHashTable(hashTable);
    exit(EXIT_FAILURE);
  }

  newNode->birthday = *birthday;
  newNode->next = hashTable[h];
  hashTable[h] = newNode;
}

void displayHashCounts(struct Node *hashTable[]) {
  for (uint16_t i = 0; i < HASH_TABLE_SIZE; i++) {
    uint16_t count = 0;
    const struct Node *temp = hashTable[i];
    while (temp != NULL) {
      count++;
      temp = temp->next;
    }
    printf("\nHash location %d has %hu elements in it.", i, count);
  }
}

int main(void) {
  struct Node *hashTable[HASH_TABLE_SIZE] = {0};

  while (true) {
    printf("\nEnter the file name: ");
    char fileName[FILE_NAME_SIZE];
    scanf("%49s", fileName);

    if (strcmp(fileName, "bdaylist.txt") != 0) {
      printf("\nError: That file does not exist. Try again.");
    } else {
      FILE *file = fopen(fileName, "r");
      if (file == NULL) {
        perror("Error opening file.\n");
        freeHashTable(hashTable);
        exit(EXIT_FAILURE);
      }

      char line[LINE_SIZE];
      while (fgets(line, sizeof(line), file) != NULL) {
        uint16_t month, day, year;
        sscanf(line, "%hu%hu%hu", &month, &day, &year);

        Birthday birthday = createBirthday(month, day, year);
        insertIntoHashTable(hashTable, &birthday);
      }

      displayHashCounts(hashTable);
      freeHashTable(hashTable);
      fclose(file);
      break;
    }
  }

  return 0;
}