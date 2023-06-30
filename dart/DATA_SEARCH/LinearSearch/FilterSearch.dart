import 'dart:io';

const String CLEAR_LOG = "\x1B[2J\x1B[0;0H";

void main(List<String> args) {
  final List<AMAStudent> studentInfo = [];

  while (true) {
    print(CLEAR_LOG);
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
          print(CLEAR_LOG);

          stdout.write("Enter Student name: ");
          final String name = stdin.readLineSync()!;
          if (name.trim().isEmpty) continue;

          String temp;
          do {
            stdout.write("Enter thhe student USN: ");
            temp = stdin.readLineSync()!;

            // if (!isNumeric(temp) || temp.length != 11) continue;
          } while (!isNumeric(temp) || temp.length != 11);
          final int usn = int.parse(temp);

          studentInfo.add(AMAStudent(usn, name.trim()));

          stdout.write("Want to add more name? [Y/N] ");
          final String userChoose = stdin.readLineSync()!;
          if (!(userChoose.toUpperCase() == "Y" ||
              userChoose.toUpperCase() == "YES")) break;
        }
        break;
      case 2: // Search by Name
        stdout.write("Search by name: ");
        final String nameValue = stdin.readLineSync()!;
        List<AMAStudent> searchResults = studentInfo
            .where((student) => student.name.contains(nameValue))
            .toList();
        if (searchResults.isEmpty) {
          stdout.writeln("Element is not present in the array.");
        } else {
          stdout.writeln("Search results:");
          searchResults
              .forEach((student) => stdout.writeln(student.toString()));
        }
        stdin.readLineSync();
        break;

      case 3: // Search by USN
        stdout.write("Search by USN: ");
        final String usnValue = stdin.readLineSync()!;
        List<AMAStudent> searchResults = studentInfo
            .where((student) => student.usn.toString().contains(usnValue))
            .toList();
        if (searchResults.isEmpty) {
          stdout.writeln("Element is not present in the array.");
        } else {
          stdout.writeln("Search results:");
          searchResults
              .forEach((student) => stdout.writeln(student.toString()));
        }
        stdin.readLineSync();
        break;
      case 4: // Print all the added students
        print(CLEAR_LOG);
        print(studentInfo.toString());
        stdin.readLineSync();
        break;
      case 5:
        return;
      default:
        return;
    }
  }
}

class AMAStudent {
  final int usn;
  final String name;

  AMAStudent(this.usn, this.name);

  @override
  String toString() {
    return '\nUSN: ${usn}, Name: ${name}\n';
  }
}

bool isNumeric(String str) {
  return num.tryParse(str) != null;
}
