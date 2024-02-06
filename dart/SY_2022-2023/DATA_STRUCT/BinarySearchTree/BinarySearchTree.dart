import 'dart:io';
import 'dart:convert';
import '../../reusableMethod.dart';

class TreeNode {
  AMAStudent student;
  TreeNode? left;
  TreeNode? right;

  TreeNode(this.student);
}

class BinarySearchTree {
  TreeNode? root;

  void insert(AMAStudent student) {
    if (root == null)
      root = TreeNode(student);
    else
      _inserNode(root!, student);
  }

  void _inserNode(TreeNode node, AMAStudent student) {
    if (student.usn < node.student.usn) {
      if (node.left == null) {
        node.left = TreeNode(student);
      } else {
        if (_hasDuplicateUSN(node.left!, student.usn)) {
          print(
              "Duplicate USN. Cannot insert student with USN ${student.usn}.");
          return;
        }
        _inserNode(node.left!, student);
      }
    } else {
      if (node.right == null) {
        node.right = TreeNode(student);
      } else {
        if (_hasDuplicateUSN(node.right!, student.usn)) ;
        print("Duplicate USN. Cannot insert student with USN ${student.usn}.");
        return;
      }
    }
  }

  bool _hasDuplicateUSN(TreeNode node, int usn) {
    if (node.student == usn) return true;

    if (usn < node.student.usn) {
      if (node.left == null)
        return false;
      else
        return _hasDuplicateUSN(node.left!, usn);
    } else {
      if (node.right == null)
        return false;
      else
        return _hasDuplicateUSN(node.right!, usn);
    }
  }

  void deleteByUSN(int usn) => root = _deleteNode(root, usn);

  TreeNode? _deleteNode(TreeNode? node, int usn) {
    if (node == null) return null;

    if (usn < node.student.usn) {
      node.left = _deleteNode(node.left, usn);
    } else if (usn > node.student.usn) {
      node.right = _deleteNode(node.right, usn);
    } else {
      if (node.left == null && node.right == null) {
        return null;
      } else if (node.left == null) {
        return node.right;
      } else if (node.right == null) {
        return node.left;
      } else {
        var minRight = _findMinNode(node.right!);
        node.student = minRight!.student;
        node.right = _deleteNode(node.right, minRight.student.usn);
      }
    }

    return node;
  }

  TreeNode? _findMinNode(TreeNode node) {
    while (node.left != null) node = node.left!;

    return node;
  }

  void deleteByName(String keyword) {
    List<TreeNode> searchResults = searchByName(keyword);
    if (searchResults.isEmpty) {
      CLEAR_AND_PAUSE('No student found with the given name.');
      return;
    }

    CLEAR_TO_PROMPT('\nSearch Result: ');
    for (int i = 0; i < searchResults.length; i++)
      print('Index: $i, Student Info: ${searchResults[i].student}');

    stdout.write('\nEnter the index of the student to delete: ');
    int? index = int.tryParse(stdin.readLineSync()!);

    if (index! >= 0 && index < searchResults.length) {
      AMAStudent studentToDelete = searchResults[index].student;
      deleteByUSN(studentToDelete.usn);
      CLEAR_AND_PAUSE("Student with Name '$keyword' and USN "
          "${studentToDelete.usn} has been deleted.");
    } else {
      CLEAR_AND_PAUSE('Invalid index.');
    }
  }

  List<TreeNode> searchByUSN(int usn) {
    List<TreeNode> results = [];
    _searchByUSNNode(root, usn, results);
    return results;
  }

  void _searchByUSNNode(TreeNode? node, int usn, List<TreeNode> results) {
    if (node == null) return;

    if (node.student.usn == usn) results.add(node);

    if (usn < node.student.usn)
      _searchByUSNNode(node.left, usn, results);
    else
      _searchByUSNNode(node.right, usn, results);
  }

  List<TreeNode> searchByName(String keyword) {
    List<TreeNode> results = [];
    _searchByNameNode(root, keyword.toUpperCase(), results);
    return results;
  }

  void _searchByNameNode(
      TreeNode? node, String keyword, List<TreeNode> results) {
    if (node == null) return;

    if (node.student.name.toUpperCase().contains(keyword)) results.add(node);

    if (keyword.compareTo(node.student.name.toUpperCase()) < 0)
      _searchByNameNode(node.left, keyword, results);
    else
      _searchByNameNode(node.right, keyword, results);
  }

  List<AMAStudent> inOrderTraversal() {
    List<AMAStudent> result = [];
    _inOrderTraversal(root, result);
    return result;
  }

  void _inOrderTraversal(TreeNode? node, List<AMAStudent> result) {
    if (node != null) {
      _inOrderTraversal(node.left, result);
      result.add(node.student);
      _inOrderTraversal(node.right, result);
    }
  }
}

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

/// Loads student data from a file
void loadStudentFromFile(List<AMAStudent> infos) {
  try {
    File file = File(
        'D:/CODING_SESSION/dart/DATA_SEARCH/BinarySearch/studentsTree.json');

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
void saveStudentToFile(BinarySearchTree bst) {
  try {
    File file = File(
        'D:/CODING_SESSION/dart/DATA_SEARCH/BinarySearch/studentsTree.json');

    List<Map<String, dynamic>> jsonData =
        bst.inOrderTraversal().map((student) => student.toJson()).toList();
    String jsonString = jsonEncode(jsonData);

    file.writeAsStringSync(jsonString);

    CLEAR_AND_PAUSE('Student data saved to file. Exiting...');
  } catch (e) {
    CLEAR_AND_PAUSE('ERROR: Failed to save student data to file: $e');
  }
}

void printStudentList(BinarySearchTree bst) {
  if (bst.root == null) {
    CLEAR_TO_PROMPT("No students found.");
    return;
  }

  CLEAR_TO_PROMPT("Student List:");
  inOrderTraversal(bst.root);
}

void inOrderTraversal(TreeNode? node) {
  if (node != null) {
    inOrderTraversal(node.left);
    print(node.student);
    inOrderTraversal(node.right);
  }
}

void main() {
  List<AMAStudent> students = [];

  loadStudentFromFile(students);

  BinarySearchTree bst = BinarySearchTree();
  for (AMAStudent student in students) {
    bst.insert(student);
  }

  bool exit = false;

  while (!exit) {
    CLEAR_TO_PROMPT("Options:\n");
    print("1. Add Student");
    print("2. Search by Name");
    print("3. Search by USN");
    print("4. Delete by Name");
    print("5. Delete by USN");
    print("6. Print Student List");
    print("7. Exit and Save Student List to File");
    stdout.write("Enter your choice: ");
    String choice = stdin.readLineSync()!;
    print("");

    switch (choice) {
      case "1":
        CLEAR_TO_PROMPT("Enter USN: ");
        int usn = int.parse(stdin.readLineSync()!);
        stdout.write("Enter Name: ");
        String name = stdin.readLineSync()!;
        bst.insert(AMAStudent(usn, name));
        CLEAR_AND_PAUSE("Student added successfully.");
        break;

      case "2":
        CLEAR_TO_PROMPT("Enter Name to search: ");
        String name = stdin.readLineSync()!;

        List<TreeNode> nameResults = bst.searchByName(name);
        if (nameResults.isNotEmpty) {
          print("Search Results:");
          for (TreeNode node in nameResults) {
            print(node.student);
          }
        } else {
          CLEAR_AND_PAUSE("No student found with the given name.");
        }
        break;

      case "3":
        CLEAR_TO_PROMPT("Enter USN to search: ");
        int usn = int.parse(stdin.readLineSync()!);

        List<TreeNode> usnResults = bst.searchByUSN(usn);
        if (usnResults.isNotEmpty) {
          print("Search Results:");
          for (TreeNode node in usnResults) {
            print(node.student);
          }
        } else {
          CLEAR_AND_PAUSE("No student found with the given USN.");
        }
        break;

      case "4":
        CLEAR_TO_PROMPT('Enter Name to delete: ');
        String name = stdin.readLineSync()!;
        bst.deleteByName(name);
        break;

      case "5":
        CLEAR_TO_PROMPT("Enter USN to delete: ");
        int usn = int.parse(stdin.readLineSync()!);
        bst.deleteByUSN(usn);
        CLEAR_AND_PAUSE("Student with USN $usn has been deleted.");
        break;

      case "6":
        printStudentList(bst);
        PAUSE();
        break;

      case "7":
        saveStudentToFile(bst);
        exit = true;
        break;

      default:
        print("Invalid choice. Please try again.");
    }
  }

  print("Program exited.");
}
