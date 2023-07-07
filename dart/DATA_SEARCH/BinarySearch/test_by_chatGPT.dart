import 'dart:io';

class Node {
  int data;
  Node? left;
  Node? right;

  Node(this.data) {
    this.left = null;
    this.right = null;
  }
}

class BinarySearchTree {
  Node? root;

  BinarySearchTree() {
    this.root = null;
  }

  void insert(int data) {
    Node newNode = Node(data);

    if (root == null) {
      root = newNode;
      return;
    }

    Node current = root!;
    Node? parent;

    while (true) {
      parent = current;

      if (data < current.data) {
        if (current.left == null) {
          parent.left = newNode;
          return;
        }
        current = current.left!;
      } else {
        if (current.right == null) {
          parent.right = newNode;
          return;
        }
        current = current.right!;
      }
    }
  }

  Node? search(int data) {
    Node? current = root;

    while (current != null) {
      if (current.data == data) {
        return current;
      } else if (data < current.data) {
        current = current.left;
      } else {
        current = current.right;
      }
    }

    return null;
  }

  bool delete(int data) {
    if (root == null) {
      return false;
    }

    Node? current = root;
    Node? parent = null;
    bool isLeftChild = false;

    while (current != null) {
      if (current.data == data) {
        break;
      }

      parent = current;

      if (data < current.data) {
        isLeftChild = true;
        current = current.left;
      } else {
        isLeftChild = false;
        current = current.right;
      }
    }

    if (current == null) {
      return false;
    }

    if (current.left == null && current.right == null) {
      if (current == root) {
        root = null;
      } else if (isLeftChild) {
        parent!.left = null;
      } else {
        parent!.right = null;
      }
    } else if (current.right == null) {
      if (current == root) {
        root = current.left;
      } else if (isLeftChild) {
        parent!.left = current.left;
      } else {
        parent!.right = current.left;
      }
    } else if (current.left == null) {
      if (current == root) {
        root = current.right;
      } else if (isLeftChild) {
        parent!.left = current.right;
      } else {
        parent!.right = current.right;
      }
    } else {
      Node? successor = getSuccessor(current);

      if (current == root) {
        root = successor;
      } else if (isLeftChild) {
        parent!.left = successor;
      } else {
        parent!.right = successor;
      }

      successor!.left = current.left;
    }

    return true;
  }

  Node? getSuccessor(Node node) {
    Node? successorParent = node;
    Node? successor = node;
    Node? current = node.right;

    while (current != null) {
      successorParent = successor;
      successor = current;
      current = current.left;
    }

    if (successor != node.right) {
      successorParent!.left = successor!.right;
      successor.right = node.right;
    }

    return successor;
  }

  List<int> inorderTraversal(Node? node) {
    List<int> result = [];
    if (node != null) {
      result.addAll(inorderTraversal(node.left));
      result.add(node.data);
      result.addAll(inorderTraversal(node.right));
    }
    return result;
  }

  List<int> preorderTraversal(Node? node) {
    List<int> result = [];
    if (node != null) {
      result.add(node.data);
      result.addAll(preorderTraversal(node.left));
      result.addAll(preorderTraversal(node.right));
    }
    return result;
  }

  List<int> postorderTraversal(Node? node) {
    List<int> result = [];
    if (node != null) {
      result.addAll(postorderTraversal(node.left));
      result.addAll(postorderTraversal(node.right));
      result.add(node.data);
    }
    return result;
  }
}

void main() {
  BinarySearchTree tree = BinarySearchTree();

  while (true) {
    stdout.write(
        '\nEnter command (i[nsert], s[earch], d[elete], t[raversal], e[xit]): ');
    String? input = stdin.readLineSync()?.trim().toLowerCase();

    if (input == null || input.isEmpty) {
      stdout.write('Invalid command\n');
      continue;
    }

    switch (input[0]) {
      case 'i':
        stdout.write('Enter value to insert: ');
        String? valueInput = stdin.readLineSync()?.trim();
        int? value = int.tryParse(valueInput ?? '');

        if (value == null) {
          stdout.write('Invalid value\n');
          continue;
        }

        tree.insert(value);
        stdout.write('Value $value inserted successfully\n');
        break;
      case 's':
        stdout.write('Enter value to search: ');
        String? valueInput = stdin.readLineSync()?.trim();
        int? value = int.tryParse(valueInput ?? '');

        if (value == null) {
          stdout.write('Invalid value\n');
          continue;
        }

        Node? foundNode = tree.search(value);
        if (foundNode != null) {
          stdout.write('Value $value found in tree\n');
        } else {
          stdout.write('Value $value not found in tree\n');
        }
        break;
      case 'd':
        stdout.write('Enter value to delete: ');
        String? valueInput = stdin.readLineSync()?.trim();
        int? value = int.tryParse(valueInput ?? '');

        if (value == null) {
          stdout.write('Invalid value\n');
          continue;
        }

        if (tree.delete(value)) {
          stdout.write('Value $value deleted successfully\n');
        } else {
          stdout.write('Value $value not found in tree\n');
        }
        break;
      case 't':
        stdout.write(
            'Enter traversal type (i[norder], p[reorder], o[ostorder]): ');
        String? type = stdin.readLineSync()?.trim();

        if (type == null || type.isEmpty) {
          stdout.write('Invalid traversal type\n');
          continue;
        }

        switch (type[0]) {
          case 'i':
            stdout.write('Inorder traversal: ');
            List<int> inorder = tree.inorderTraversal(tree.root);
            stdout.write(inorder.join(' '));
            stdout.write('\n');
            break;
          case 'p':
            stdout.write('Preorder traversal: ');
            List<int> preorder = tree.preorderTraversal(tree.root);
            stdout.write(preorder.join(' '));
            stdout.write('\n');
            break;
          case 'o':
            stdout.write('Postorder traversal: ');
            List<int> postorder = tree.postorderTraversal(tree.root);
            stdout.write(postorder.join(' '));
            stdout.write('\n');
            break;
          default:
            stdout.write('Invalid traversal type\n');
            break;
        }
        break;
      case 'e':
        stdout.write('Exiting program...\n');
        return;
      default:
        stdout.write('Invalid command\n');
        break;
    }
  }
}

