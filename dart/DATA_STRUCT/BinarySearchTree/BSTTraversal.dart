import 'dart:io';

import '../../reusableMethod.dart';

class Node {
  int? key;
  Node? left, right;

  Node(this.key) {
    left = right = null;
  }
}

class BinaryTree {
  Node? root;

  BinaryTree() {
    root = null;
  }

  void insert(int? key) {
    var node = Node(key);

    if (root == null) {
      root = node;
      return;
    }

    var current = root;

    while (true) {
      if (key == current!.key) return;

      if (key! < current.key!) {
        if (current.left == null) {
          current.left = node;
          return;
        }
        current = current.left;
      } else {
        if (current.right == null) {
          current.right = node;
          return;
        }
        current = current.right;
      }
    }
  }

  void delete(int? key) {
    root = _deleteRec(root, key);
  }

  Node? _deleteRec(Node? root, int? key) {
    if (root == null) return root;

    if (key! < root.key!) {
      root.left = _deleteRec(root.left, key);
    } else if (key > root.key!) {
      root.right = _deleteRec(root.right, key);
    } else {
      if (root.left == null)
        return root.right;
      else if (root.right == null) return root.left;

      root.key = _minValue(root.right);
      root.right = _deleteRec(root.right, root.key);
    }
    return root;
  }

  int? _minValue(Node? root) {
    int? minValue = root?.key;
    while (root?.left != null) {
      minValue = root?.left?.key;
      root = root?.left;
    }
    return minValue;
  }

  Node? search(int? key) {
    return _searchRec(root, key);
  }

  Node? _searchRec(Node? root, int? key) {
    if (root == null || root.key == key) return root;

    if (key! < root.key!) return _searchRec(root.left, key);

    return _searchRec(root.right, key);
  }

  void inorder() {
    CLEAR_TO_PROMPT("Inorder Traversal: ");
    _inorderRec(root);
    PAUSE();
  }

  void _inorderRec(Node? root) {
    if (root != null) {
      _inorderRec(root.left);
      stdout.write("${root.key} ");
      _inorderRec(root.right);
    }
  }

  void preorder() {
    CLEAR_TO_PROMPT("Preorder Traverl: ");
    _preorderRec(root);
    PAUSE();
  }

  void _preorderRec(Node? root) {
    if (root != null) {
      stdout.write("${root.key} ");
      _preorderRec(root.left);
      _preorderRec(root.right);
    }
  }

  void postorder() {
    CLEAR_TO_PROMPT("Postorder Traversal: ");
    _postorderRec(root);
    PAUSE();
  }

  void _postorderRec(Node? root) {
    if (root != null) {
      _postorderRec(root.left);
      _postorderRec(root.right);
      stdout.write("${root.key} ");
    }
  }
}

void main() {
  BinaryTree bst = BinaryTree();
  late int? choice = 0, key;

  while (choice != 7) {
    CLEAR_TO_PROMPT("\nBinary search tree Operations\n");
    print("1) Insert");
    print("2) Delete");
    print("3) Search");
    print("4) Inorder Traversal");
    print("5) Preorder Traversal");
    print("6) Postorder Travel");
    print("7) Exit");
    stdout.write("Enter your choice: ");
    choice = int.tryParse(stdin.readLineSync()!);

    switch (choice) {
      case 1:
        CLEAR_TO_PROMPT("Enter the key to be inserted: ");
        key = int.tryParse(stdin.readLineSync()!);
        bst.insert(key);
        bst.inorder();
        break;
      case 2:
        CLEAR_TO_PROMPT("Enter the key to be delete: ");
        key = int.tryParse(stdin.readLineSync()!);
        bst.delete(key);
        bst.inorder();
        break;
      case 3:
        CLEAR_TO_PROMPT("Enter the key to be searched: ");
        key = int.tryParse(stdin.readLineSync()!);
        Node? result = bst.search(key);
        if (result != null)
          print("Key found!");
        else
          print("Key not found!");
        break;
      case 4:
        bst.inorder();
        break;
      case 5:
        bst.preorder();
        break;
      case 6:
        bst.postorder();
        break;
      case 7:
        CLEAR_TO_PROMPT("Program exiting . . .");
        break;
      default:
        CLEAR_TO_PROMPT("Invalid choice!");
    }
  }
}
