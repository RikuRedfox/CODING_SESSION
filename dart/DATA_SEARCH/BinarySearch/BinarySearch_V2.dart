import 'dart:io';

import '../../reusableMethod.dart';

/// Represent a student in the AMA
class AMAStudent {
  final int _usn;
  final String _name;

  AMAStudent(this._usn, this._name);

  @override
  String toString() {
    return '\nUSN: ${_usn}, Name: ${_name}\n';
  }
}

void main() {
  final List<AMAStudent> studentInfo = [];

  while (true) {
    CLEAR_CONSOLE();
    print("[1] Add Student.");
    print("[2] Search by name.");
    print("[3] Search by USN.");
    print("[4] Print the current list.");
    print("[5] Exit.");

    stdout.write("My good user please enter thy entry: ");
    final int userChoose = int.parse(stdin.readLineSync()!);

    switch (userChoose) {
      case 1: // Add student
        while (true) {
          CLEAR_CONSOLE();

          stdout.write("Enter Student name: ");
          final String name = stdin.readLineSync()!;
          if (name.trim().isEmpty) continue;

          String temp;
          do {
            stdout.write("Enter thhe student USN: ");
            temp = stdin.readLineSync()!;
          } while (!isNumeric(temp) || temp.length != 11);
          final int usn = int.parse(temp);

          studentInfo.add(AMAStudent(usn, name.trim().toUpperCase()));

          stdout.write("Want to add more name? [Y/N] ");
          final String userChoice = stdin.readLineSync()!;
          if (!(userChoice.toUpperCase() == "Y" ||
              userChoice.toUpperCase() == "YES")) break;
        }
        break;
      case 2: // Search by Name and auto sort by name
        stdout.write("Search by name: ");
        final String nameValue = stdin.readLineSync()!;
        studentInfo.sort((a, b) => a._name.compareTo(b._name));
        int result = binarySearch(studentInfo, nameValue.toUpperCase());
        printSearchResult(result);
        stdin.readLineSync();
        break;
      case 3: // Search by USN and auto sort by USN
        stdout.write("Search by USN: ");
        final String usnValue = stdin.readLineSync()!;
        studentInfo.sort((a, b) => a._usn.compareTo(b._usn));
        int result = binarySearch(studentInfo, int.tryParse(usnValue));
        printSearchResult(result);
        stdin.readLineSync();
        break;
      case 4: // Print all the added student
        CLEAR_CONSOLE();
        print(studentInfo.toString());
        stdin.readLineSync();
        break;
      case 5: // Exit
        return;
      default:
        return;
    }
  }
}

/// Check if a string can be parse as a numeric value
bool isNumeric(String str) {
  return num.tryParse(str) != null;
}

/// Clear the console
void get CLEAR_LOG => print("\x1B[2J\x1B[0;0H");

/// Perform a binary search on the given list of student base on the provided value
/// Returns the index of the found student or -1 if not found.
int binarySearch(List<AMAStudent> studentList, dynamic value) {
  int low = 0;
  int high = studentList.length - 1;

  while (low <= high) {
    int mid = ((low + high) / 2).floor();
    AMAStudent student = studentList[mid];

    if (value is int) {
      // For searching a USN
      if (student._usn == value) {
        return mid;
      } else if (student._usn > value) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else if (value is String) {
      // For searching a name
      int nameCamparison = student._name.compareTo(value); // 0 1 -1
      if (nameCamparison == 0) {
        return mid;
      } else if (nameCamparison > 0) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else {
      // The value is not a integer or string
      throw ArgumentError('Unsupported value type.');
    }
  }
  return -1;
}

/// Prints the search result based on the provided index.
void printSearchResult(int result) {
  (result == -1)
      ? stdout.writeln("Element is not present in the array.")
      : stdout.writeln("Element is present at index $result.");
}
