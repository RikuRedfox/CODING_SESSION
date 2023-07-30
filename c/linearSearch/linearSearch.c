#include <stdio.h>
#include <stdlib.h>

// Linear Search function
int linearSearch(int arr[], int size, int key) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int main(void) {
  int arrSize;
  printf("Enter the size of the array: ");
  scanf("%d", &arrSize);

  // Dynamically allocate memory for the array
  int *arr = (int *)malloc(arrSize * sizeof(int));

  printf("Enter %d element for the array: \n", arrSize);
  for (int i = 0; i < arrSize; i++) {
    printf("[%d] -> ", (i + 1));
    scanf("%d", &arr[i]);
  }

  int key;
  printf("Enter the element to search: ");
  scanf("%d", &key);

  int result = linearSearch(arr, arrSize, key);
  (result != -1) ? printf("Element %d found at index %d\n", key, result)
                 : printf("Element %d not found in the array\n", key);

  // Free dynamically allocated memory for the array;
  free(arr);
  return 0;
}
