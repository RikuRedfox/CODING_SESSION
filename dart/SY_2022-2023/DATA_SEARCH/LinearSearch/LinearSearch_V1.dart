void main() {
  List<int> numbers = [5, 3, 8, 2, 1, 9, 4, 7, 6];
  int target = 9;

  int result = linearSearch(numbers, target);
  if (result != -1) {
    print("Target $target found at index $result");
  } else {
    print("Target $target not found in the list");
  }
}

int linearSearch(List<int> list, int target) {
  for (int i = 0; i < list.length; i++) {
    if (list[i] == target) {
      return i; // Return the index if the target is found
    }
  }
  return -1; // Return -1 if the target is not found
}
