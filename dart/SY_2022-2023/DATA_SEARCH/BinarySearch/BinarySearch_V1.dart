import 'dart:io';

const String CLEAR_LOG = "\x1B[2J\x1B[0;0H";
void main(List<String> args) {
  List<String> names = [];

  // Inputs
  while (true) {
    print(CLEAR_LOG);
    stdout.write("Enter a name: ");
    final String inputName = stdin.readLineSync()!;
    names.add(inputName);

    stdout.write("Want to add more name? [Y/N] ");
    final String userChoose = stdin.readLineSync()!;
    if (userChoose.toUpperCase() == "Y" || userChoose.toUpperCase() == "YES") {
      continue;
    }
    break;
  }
  
  // Searching Element
  names.sort();
  print(CLEAR_LOG);
  stdout.write("Enter the search: ");
  final String searchName = stdin.readLineSync()!;

  // Call func
  int result = BinarySearch(names, searchName);

  (result == -1)
      ? stdout.writeln("Element is not present in array.")
      : stdout.writeln("Element is present at index $result");
}

int BinarySearch(List<String> namesContainer, String searchString) {
  int low = 0;
  int high = namesContainer.length - 1;
  while (low <= high) {
    int mid = ((low + high) ~/ 2);
    if (namesContainer[mid] == searchString) {
      return mid;
    } else if (namesContainer[mid].compareTo(searchString) > 0) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}
