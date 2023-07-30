#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(char *arr[], int size, const char *target) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    int cmp = strcmp(arr[mid], target);

    if (cmp == 0) {
      return mid;
    } else if (cmp > 0) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

void swap(char **a, char **b) {
  char *temp = *a;
  *a = *b;
  *b = temp;
}

int partition(char **names, int left, int right) {
  char *pivot = names[right];
  int i = left - 1;

  for (int j = left; j < right; j++) {
    if (strcmp(names[j], pivot) <= 0) {
      i++;
      swap(&names[i], &names[j]);
    }
  }

  swap(&names[i + 1], &names[right]);
  return i + 1;
}

void quickSort(char **names, int left, int right) {
  if (left < right) {
    int pivotIndex = partition(names, left, right);
    quickSort(names, left, pivotIndex - 1);
    quickSort(names, pivotIndex + 1, right);
  }
}

char *strToUpperR(char *str) {
  for (int i = 0; str[i] != '\0'; i++)
    str[i] = toupper(str[i]);

  return str;
}

int main(void) {
  char **names = NULL;
  int size = 0;

  while (1) {
    printf("Enter a name: ");
    char inputName[50];
    if (fgets(inputName, sizeof(inputName), stdin) == NULL) {
      printf("Input reading failed.\n");
      continue;
    }
    inputName[strcspn(inputName, "\n")] = '\0';

    char **temp = (char **)realloc(names, (size + 1) * sizeof(char *));
    if (temp == NULL) {
      printf("Memory allocation failed.\n");
      exit(1);
    } else {
      names = temp;
    }

    names[size] = strdup(inputName);
    size++;

    printf("Want to add more name? [Y/N] ");
    char userChoose[3];
    if (fgets(userChoose, sizeof(userChoose), stdin) == NULL) {
      printf("Input reading failed.\n");
      continue;
    }

    userChoose[strcspn(userChoose, "\n")] = '\0';
    if (strcmp(strToUpperR(userChoose), "Y") == 0 ||
        strcmp(strToUpperR(userChoose), "YES") == 0) {
      continue;
    } else {
      break;
    }
  }

  // Sorting
  quickSort(names, 0, size - 1);

  printf("Enter the search: ");
  char searchName[50];
  if (fgets(searchName, sizeof(searchName), stdin) == NULL) {
    printf("Input reading failed.\n");
    exit(1);
  }

  searchName[strcspn(searchName, "\n")] = '\0';
  int result = binarySearch(names, size, searchName);

  (result == -1) ? printf("Element is not present in array.\n")
                 : printf("Element is present at index %d.\n", result);

  // Free dynamic memory
  for (int i = 0; i < size; i++) {
    free(names[i]);
  }
  free(names);
}