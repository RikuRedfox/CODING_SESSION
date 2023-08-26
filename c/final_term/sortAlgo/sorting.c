#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH_OF_ARRAY 10

int count = 0;

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Advantages of Bubble Sort:
// > Bubble sort is easy to understand and implement.
// > It does not require any additional memory space.
// > It is a stable sorting algorithm, meaning that elements with the same
//  key value maintain their relative order in the sorted output.
//
// Disadvantages of Bubble Sort:
// > Bubble sort has a time complexity of O(N2) which makes it very
//  slow for large data sets.
// > Bubble sort is a comparison-based sorting algorithm, which
//  means that it requires a comparison operator to determine the
//  relative order of elements in the input data set. It can limit
//  the efficiency of the algorithm in certain cases.
void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    bool swapFlag = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        swapFlag = true;
      }
    }
    if (!swapFlag) {
      break;
    }
    printf("Step %d. -> ", i + 1);
    printArray(arr, size);
  }
}

// Advantages of Selection Sort Algorithm
// > Simple and easy to understand.
// > Works well with small datasets.
//
// Disadvantages of the Selection Sort Algorithm
// > Selection sort has a time complexity of O(n^2) in the worst and average
// case.
// > Does not work well on large datasets. > Does not preserve the
//  relative order of items with equal keys which means it is not stable.
void selectionSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(&arr[i], &arr[minIndex]);
    printf("Step %d. -> ", i + 1);
    printArray(arr, size);
  }
}

// Characteristics of Insertion Sort
// > This algorithm is one of the simplest algorithms with a simple
// implementation
// > Basically, Insertion sort is efficient for small data values
// > Insertion sort is adaptive in nature, i.e. it is appropriate
//  for data sets that are already partially sorted.
void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
    printf("Step %d. -> ", i);
    printArray(arr, size);
  }
}

// Advantages of Quick Sort:
// > It is a divide-and-conquer algorithm that makes it easier to solve
// problems.
// > It is efficient on large data sets.
// > It has a low overhead, as
// it only requires a small amount of memory to function.
//
// Disadvantages of Quick Sort:
// > It has a worst-case time complexity of O(N2), which occurs
//  when the pivot is chosen poorly.
// > It is not a good choice for small data sets.
// > It is not a stable sort, meaning that if two elements have
//  the same key, their relative order will not be preserved in the
//  sorted output in case of quick sort, because here we are
//  swapping elements according to the pivot’s position
//  (without considering their original positions).
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  printf("Step %d. -> ", count++);
  printArray(arr, high + 1);
  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

// Advantages of Heap Sort:
// > Efficient Time Complexity: Heap Sort has a time complexity of O(n log n) in
// all cases. This makes it efficient for sorting large datasets. The log n
// factor comes from the height of the binary heap, and it ensures that the
// algorithm maintains good performance even with a large number of elements.
// > Memory Usage – Memory usage can be minimal because apart from what is
// necessary to hold the initial list of items to be sorted, it needs no
// additional memory space to work
// > Simplicity –  It is simpler to understand
// than other equally efficient sorting algorithms because it does not use
// advanced computer science concepts such as recursion.
//
// Disadvantages of Heap Sort:
// > Costly: Heap sort is costly.
// > Unstable: Heap sort is unstable. It might rearrange the relative order.
// > Efficient: Heap Sort is not very efficient when working with highly complex
//  data.
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
  printf("Step %d. -> ", count++);
  printArray(arr, right + 1);
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

// Advantages of Merge Sort:
// > Stability: Merge sort is a stable sorting algorithm, which means it
// maintains the relative order of equal elements in the input array.
// > Guaranteed worst-case performance: Merge sort has a worst-case time
// complexity of O(N logN), which means it performs well even on large datasets.
// > Parallelizable: Merge sort is a naturally parallelizable algorithm, which
// means it can be easily parallelized to take advantage of multiple processors
// or threads.
//
// Drawbacks of Merge Sort:
// > Space complexity: Merge sort requires additional memory to store the merged
// sub-arrays during the sorting process.
// > Not in-place: Merge sort is not an
// in-place sorting algorithm, which means it requires additional memory to
// store the sorted data. This can be a disadvantage in applications where
// memory usage is a concern.
// > Not always optimal for small datasets: For small
// datasets, Merge sort has a higher time complexity than some other sorting
// algorithms, such as insertion sort. This can result in slower performance for
// very small datasets.
void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(arr, size, i);
  }
  for (int i = size - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
    printf("Step %d. -> ", count++);
    printArray(arr, size);
  }
}

// Generate random numbers in arrays.
void getRandom(int arr[], int size) {
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 500 + 1;
  }
}

int main(void) {
  int numbers[LENGTH_OF_ARRAY];
  getRandom(numbers, LENGTH_OF_ARRAY);

  int originalNumbers[LENGTH_OF_ARRAY];
  for (int i = 0; i < LENGTH_OF_ARRAY; i++) {
    originalNumbers[i] = numbers[i];
  }

  while (true) {
    printf("Choose an operation:\n");
    printf("1.) Bubble Sort\n");
    printf("2.) Selection Sort\n");
    printf("3.) Insertion Sort\n");
    printf("4.) Quick Sort\n");
    printf("5.) Merge Sort\n");
    printf("6.) Heap Sort\n");
    printf("7.) Generate New Random Numbers.\n");
    printf("0.) Exit Program\n");

    int choose;
    printf("\nEnter Operation: ");
    scanf("%d", &choose);

    for (int i = 0; i < LENGTH_OF_ARRAY; i++) {
      numbers[i] = originalNumbers[i];
    }

    printf("Original Array: ");
    printArray(numbers, LENGTH_OF_ARRAY);

    switch (choose) {
    case 1:
      printf("Bubble Sort:\n");
      bubbleSort(numbers, LENGTH_OF_ARRAY);
      break;
    case 2:
      printf("Selection Sort:\n");
      selectionSort(numbers, LENGTH_OF_ARRAY);
      break;
    case 3:
      printf("Insertion Sort:\n");
      insertionSort(numbers, LENGTH_OF_ARRAY);
      break;
    case 4:
      count = 1;
      printf("Quick Sort:\n");
      quickSort(numbers, 0, LENGTH_OF_ARRAY - 1);
      break;
    case 5:
      count = 1;
      printf("Merge Sort:\n");
      mergeSort(numbers, 0, LENGTH_OF_ARRAY - 1);
      break;
    case 6:
      count = 1;
      printf("Heap Sort:\n");
      heapSort(numbers, LENGTH_OF_ARRAY);
      break;
    case 7:
      getRandom(numbers, LENGTH_OF_ARRAY);
      for (int i = 0; i < LENGTH_OF_ARRAY; i++) {
        originalNumbers[i] = numbers[i];
      }

      printf("New Array: ");
      printArray(numbers, LENGTH_OF_ARRAY);
      break;
    case 0:
      exit(0);
    default:
      printf("Invalid Input. Try again.\n");
    }
  }

  return 0;
}