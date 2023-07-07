class Node {
  int value;
  Node? left;
  Node? right;

  Node(this.value)
      : left = null,
        right = null;
}

class BinarySearchTree {
  Node? root;

  void insert(int value) {
    Node newNode = Node(value);
    if (root == null) {
      root = newNode;
      return;
    }
    Node? currentNode = root;
    while (true) {
      if (value < currentNode!.value) {
        if (currentNode.left == null) {
          currentNode.left = newNode;
          return;
        }
        currentNode = currentNode.left;
      } else {
        if (currentNode.right === null) {
          currentNode.right = newNode;
          return;
        }
        currentNode = currentNode.right;
      }
    }
  }

  bool search(int value) {
    Node? currentNode = root;
    while (currentNode != null) {
      if (value == currentNode.value) {
        return true;
      } else if (value < currentNode.value) {
        currentNode = currentNode.left;
      } else {
        currentNode = currentNode.right;
      }
    }
    return false;
  }
}

void main() {
  BinarySearchTree bst = BinarySearchTree();
  // Inserting values into the BST
  bst.insert(5);
  bst.insert(3);
  bst.insert(7);
  bst.insert(2);
  bst.insert(4);
  bst.insert(6);
  bst.insert(8);
  // Searching for a value in the BST
  print(bst.search(6)); // Output: true
  print(bst.search(9)); // Output: false
}
