import 'dart:io';

// ? Defining a class Birthday with properties for day, month, and year
class Birthday {
  final int month;
  final int day;
  final int year;

  // ? Constructor for the Birthday class
  Birthday({required this.month, required this.day, required this.year});

  // ? Method to calculate a hash value for the Birthday object
  int hash() {
    return (day + month + year) % 12;
  }

  // ? Method to compare two Birthday objects for equality
  bool equal(Birthday other) {
    return day == other.day && month == other.month && year == other.year;
  }
}

void main() {
  List<List<Birthday>> hashTable = List.generate(12, (index) => []);

  while (true) {
    stdout.write("\nEnter the file name: ");
    String? fileName = stdin.readLineSync();

    if (fileName == null || fileName != 'bdaylist.txt') {
      stdout.write("Error: that file does not exist. Try again.");
    } else {
      List<String> lines = File(fileName).readAsLinesSync();
      // ? Looping through each line in the file
      for (int i = 0; i < lines.length; i++) {
        List<String> parts = lines[i].split('/');

        // ? Creating a new Birthday object from the parts
        Birthday birthday = Birthday(
          day: int.parse(parts[1]),
          month: int.parse(parts[0]),
          year: int.parse(parts[2]),
        );
        // ? Adding the Birthday object to the hash table
        hashTable[birthday.hash()].add(birthday);
      }
      // ? Looping through the hash table to print the number of elements at each location
      for (int i = 0; i < hashTable.length; i++) {
        stdout.write(
            "\nHash location $i has ${hashTable[i].length} elements in it");
      }
      break;
    }
  }
}