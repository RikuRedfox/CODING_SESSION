/// Author: Andrew Jules R. Miyajima
/// Date CREATED: June 6, 2023
/// - Search for name or usn then return by index with the info
/// (name and usn will be printed)
/// Date UPDATED: June 20, 2023
/// - Search for name with the similar name
/// - The USN must be unique
/// Date UPDATED: June 22, 2023
/// - Delete by USN and Name search by multiple search and delete by index.
/// 
/// @PLANING
/// - Binary search tree. Full name implementation.

import 'dart:convert';
import 'dart:io';

import '../../reusableMethod.dart';

class AMAStudent {
  final int usn;
  final String name;

  AMAStudent(this.usn, this.name);

  @override
  String toString() => '\nUSN: $usn, Name: $name';

  Map<String, dynamic> toJson() => {'USN': usn, 'Name': name};

  factory AMAStudent.fromJson(Map<String, dynamic> json) =>
      AMAStudent(json['USN'], json['Name']);
}

bool isNumeric(String str) => num.tryParse(str) != null;

void main() {
  final List<AMAStudent> studentInfo = [];

  loadStudentFromFile(studentInfo);
  handleUserInput(studentInfo);
}

/*  print('1. Add Student.');
    print('2. Search by Name.');
    print('3. Search by USN.');
    print('4. Print Student List.');
    print('5. Exit and Save Student List to File'); 
  */
/// Handles user input and displays a menu for various operations.
void handleUserInput(List<AMAStudent> studentInfo) {
  while (true) {
    CLEAR_CONSOLE();

    print('1. Add Student.');
    print('2. Search by Name.');
    print('3. Search by USN.');
    print('4. Delete by Name.');
    print('5. Delete by USN.');
    print('6. Print Student List.');
    print('7. Exit and Save Student List to File');

    stdout.write('Enter your choice: ');
    late String choice;
    choice = stdin.readLineSync()!;

    switch (choice) {
      case '1':
        addStudent(studentInfo);
        break;
      case '2':
        searchByName(studentInfo);
        break;
      case '3':
        searchByUSN(studentInfo);
        break;
      case '4':
        deleteByName(studentInfo);
        break;
      case '5':
        deleteByUSN(studentInfo);
        break;
      case '6':
        CLEAR_AND_PAUSE(studentInfo.toString());
        break;
      case '7':
        saveStudentToFile(studentInfo);
        return;
      default:
        CLEAR_AND_PAUSE('What is that? Can you repeat that again?');
    }
  }
}

/// Adds a student to the list
void addStudent(List<AMAStudent> infos) {
  while (true) {
    CLEAR_TO_PROMPT("Enter student name: ");
    final String name = stdin.readLineSync()!.trim().toUpperCase();
    if (name.isEmpty) continue;

    late String temp;
    do {
      stdout.write("Enter the student USN: ");
      temp = stdin.readLineSync()!;
    } while (!isNumeric(temp) || temp.length != 11);
    final int usn = int.parse(temp);

    if (checkDuplicateUSN(infos, usn)) {
      CLEAR_AND_PAUSE('A student with the same USN already exists'
          ' for this name. Please enter a unique USN.');
      continue;
    }

    infos.add(AMAStudent(usn, name));

    stdout.write("Want to add more names? [Y/N] ");
    final String userChoice = stdin.readLineSync()!;
    if (!(userChoice.toUpperCase() == "Y" ||
        userChoice.toUpperCase() == "YES")) {
      break;
    }
  }
}

bool checkDuplicateUSN(List<AMAStudent> infos, int usn) {
  return infos.any((student) => student.usn == usn);
}

/// Searches for students by name (sorted by name)
void searchByName(List<AMAStudent> infos) {
  CLEAR_TO_PROMPT("Search by name: ");
  final String nameValue = stdin.readLineSync()!.trim().toUpperCase();

  List<MapEntry<int, AMAStudent>> result = binarySearchByName(infos, nameValue);
  printSearchResult(result);
  PAUSE();
}

/// Performs a binary search on the list by name, returning a list
/// of matching students.
List<MapEntry<int, AMAStudent>> binarySearchByName(
    List<AMAStudent> infos, String value) {
  // Sort the student list by name
  infos.sort((a, b) => a.name.compareTo(b.name));
  List<MapEntry<int, AMAStudent>> result = [];
  int low = 0;
  int high = infos.length - 1;

  while (low <= high) {
    int mid = ((low + high) ~/ 2);
    AMAStudent student = infos[mid];

    if (student.name.compareTo(value) == 0) {
      // Match found, add to the result list
      result.add(MapEntry(mid, student));

      // Search left for matching students
      int left = mid - 1;
      while (left >= 0 && infos[left].name.compareTo(value) == 0) {
        result.add(MapEntry(left, infos[left]));
        left--;
      }

      // Search right for matching students
      int right = mid + 1;
      while (right < infos.length && infos[right].name.compareTo(value) == 0) {
        result.add(MapEntry(right, infos[right]));
        right++;
      }

      return result;
    } else if (student.name.compareTo(value) > 0) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return result;
}

/// Prints the search result.
void printSearchResult(List<MapEntry<int, AMAStudent>> result) {
  if (result.isEmpty) {
    print('No students found.');
  } else {
    print('\nSearch Results:');
    for (var student in result) {
      stdout.write('Index: ${student.key}, Student: ${student.value}\n');
    }
  }
}

/// Searches for students by USN (sorted by USN)
void searchByUSN(List<AMAStudent> infos) {
  late String usnValue;
  bool isValid = false;

  while (!isValid) {
    CLEAR_TO_PROMPT("Search by USN: ");
    usnValue = stdin.readLineSync()!.trim();

    if (!isNumeric(usnValue)) {
      CLEAR_AND_PAUSE('Error: USN must be a numeric.');
    } else {
      isValid = true;
    }
  }

  final int usn = int.parse(usnValue.trim());

  MapEntry<int, AMAStudent>? searchResult = binarySearchByUSN(infos, usn);
  if (searchResult != null) {
    print('Search Result:\n');
    print('Index: ${searchResult.key}');
    print('Student Info: ${searchResult.value}');
  } else {
    print('\nNo student found with the given USN.');
  }
  PAUSE();
}

/// Performs a binary search on the list by USN,
/// returning the matching student if found.
MapEntry<int, AMAStudent>? binarySearchByUSN(
    List<AMAStudent> infos, int value) {
  // Sort the student list by USN
  infos.sort((a, b) => a.usn.compareTo(b.usn));
  int low = 0;
  int high = infos.length - 1;

  while (low <= high) {
    int mid = ((low + high) ~/ 2);
    AMAStudent student = infos[mid];

    if (student.usn == value) {
      return MapEntry(mid, student);
    } else if (student.usn > value) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return null;
}

/// Delete a student by Name
void deleteByName(List<AMAStudent> infos) {
  CLEAR_TO_PROMPT('Enter a name: ');
  final String nameValue = stdin.readLineSync()!.trim().toUpperCase();

  final List<MapEntry<int, AMAStudent>> searchResults =
      binarySearchByName(infos, nameValue);

  if (searchResults.isEmpty) {
    CLEAR_AND_PAUSE('No students found with the given name.');
    return;
  }

  CLEAR_TO_PROMPT('Indexes is: 0 - '
      '${searchResults.length > 0 ? searchResults.length : null}'
      '\nSearch Results: ');
  for (var entry in searchResults) {
    int index = entry.key;
    AMAStudent student = entry.value;
    print('Index: $index, Student: $student');
  }

  stdout.write('Enter the index of the student to delete: ');
  final int? deleteIndex = int.tryParse(stdin.readLineSync()!);

  if (deleteIndex != null &&
      deleteIndex >= 0 &&
      deleteIndex < searchResults.length) {
    final AMAStudent deletedStudent =
        infos.removeAt(searchResults[deleteIndex].key);
    CLEAR_AND_PAUSE(
        'Student at index $deleteIndex died successfully\n$deletedStudent');
  } else {
    CLEAR_AND_PAUSE('Invalid index. No student had died.');
  }
}

/// Delete a student by USN
void deleteByUSN(List<AMAStudent> infos) {
  late String usnValue;
  bool isValid = false;

  while (!isValid) {
    CLEAR_TO_PROMPT('Enter the USN to delete: ');
    usnValue = stdin.readLineSync()!.trim();

    if (!isNumeric(usnValue) || usnValue.isEmpty || usnValue.contains(' ')) {
      CLEAR_AND_PAUSE(
          'Error: USN must be numeric with a length of 11 and without any spaces.');
    } else {
      isValid = true;
    }
  }

  final usn = int.parse(usnValue);

  final MapEntry<int, AMAStudent>? searchResult = binarySearchByUSN(infos, usn);
  if (searchResult != null) {
    final int index = searchResult.key;
    final AMAStudent deletedStudent = infos.removeAt(index);
    CLEAR_AND_PAUSE('Student with USN $usn died successfully\n$deletedStudent');
  } else {
    CLEAR_AND_PAUSE('Invalid index. No student had died.');
  }
}

/// Loads student data from a file
void loadStudentFromFile(List<AMAStudent> infos) {
  try {
    File file =
        File('D:/CODING_SESSION/dart/DATA_SEARCH/BinarySearch/students.json');

    if (file.existsSync()) {
      String jsonString = file.readAsStringSync();

      List<dynamic> studentData = jsonDecode(jsonString);

      for (dynamic data in studentData) {
        if (data is Map<String, dynamic>) {
          infos.add(AMAStudent.fromJson(data));
        }
      }
      CLEAR_AND_PAUSE('Students loaded from file.');
    }
  } catch (e) {
    CLEAR_AND_PAUSE('ERROR: Failed to load students from file: $e');
  }
}

/// Saves student data to a file then exits
void saveStudentToFile(List<AMAStudent> infos) {
  try {
    File file =
        File('D:/CODING_SESSION/dart/DATA_SEARCH/BinarySearch/students.json');

    List<Map<String, dynamic>> jsonData =
        infos.map((student) => student.toJson()).toList();
    String jsonString = jsonEncode(jsonData);

    file.writeAsStringSync(jsonString);

    CLEAR_AND_PAUSE('Student data saved to file. Exiting...');
  } catch (e) {
    CLEAR_AND_PAUSE('ERROR: Failed to save student data to file: $e');
  }
}
