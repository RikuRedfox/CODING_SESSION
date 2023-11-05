import java.util.Scanner;
import java.util.Random;
import java.util.HashSet;

public class BinarySearchTree {
  static final Scanner scanner = new Scanner(System.in);
  static final BinarySearchTree bst = new BinarySearchTree();

  static class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
      this.data = data;
      right = null;
      left = null;
    }
  }

  private Node root;

  public BinarySearchTree() {
    this.root = null;
  }

  void insert(int newData) {
    this.root = insertElement(root, newData);
  }

  Node insertElement(Node root, int newData) {
    if (root == null) {
      root = new Node(newData);
      return root;
    } else if (root.data >= newData) {
      root.left = insertElement(root.left, newData);
    } else {
      root.right = insertElement(root.right, newData);
    }
    return root;
  }

  void inOrder() {
    inOrder(root);
  }

  void inOrder(Node root) {
    if (root != null) {
      inOrder(root.left);
      System.out.print(root.data + " ");
      inOrder(root.right);
    }
  }

  void preOrder() {
    preOrder(root);
  }

  void preOrder(Node root) {
    if (root != null) {
      System.out.print(root.data + " ");
      preOrder(root.left);
      preOrder(root.right);
    }
  }

  void postOrder() {
    postOrder(root);
  }

  void postOrder(Node root) {
    if (root != null) {
      postOrder(root.left);
      postOrder(root.right);
      System.out.print(root.data + " ");
    }
  }

  void randomSetNumber(int setSize, int minValue, int maxValue) {
    Random rand = new Random();

    HashSet<Integer> uniqueNumbers = new HashSet<>();

    while (uniqueNumbers.size() < setSize) {
      int randomValue = rand.nextInt(maxValue - minValue + 1) + minValue;
      uniqueNumbers.add(randomValue);
    }

    for (int value : uniqueNumbers) {
      insert(value);
    }
  }

  void nodeStart() {
    System.out.print("Enter the size of the array: ");
    int setSize = scanner.nextInt();
    System.out.print("Do you want to manual insert or random generated?" +
        "\n[Press: \"0\" Manual | \"1\" Generated \"ANY KEY\"Exit.]\nInput: ");
    byte userChoice = scanner.nextByte();

    if (userChoice == 0) {
      System.out.println("Enter the elements of the array: ");
      for (int i = 0; i < setSize; i++) {
        System.out.printf("[%d] Input: ", i + 1);
        int value = scanner.nextInt();
        bst.insert(value);
      }
    } else if (userChoice == 1) {
      System.out.print("Enter the minimum value: ");
      int minValue = scanner.nextInt();
      System.out.print("Enter the maximum value: ");
      int maxValue = scanner.nextInt();
      bst.randomSetNumber(setSize, minValue, maxValue);
    } else {
      System.out.println("Invalid! Program End.");
      System.exit(0);
    }
  }

  public static void main(String[] args) {
    bst.nodeStart();

    while (true) {
      System.out.print("""
          1. Change the size and elements of array.
          2. InOrder Traversal.
          3. PreOrder Traversal.
          4. PostOrder Traversal.
          0. Exit.
          """);
      System.out.print("Input: ");
      byte choice = scanner.nextByte();
      switch (choice) {
        case 1:
          bst.root = null;

          bst.nodeStart();
          break;
        case 2:
          bst.inOrder();
          System.out.println();
          break;
        case 3:
          bst.preOrder();
          System.out.println();
          break;
        case 4:
          bst.postOrder();
          System.out.println();
          break;
        case 0:
          System.exit(0);
        default:
          System.out.println("Invalid or Out of range.");
      } // Switch case
    } // While loop
  }
}
