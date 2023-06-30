/// Author: Andrew Jules R. Miyajima
/// Ask how many NODE user want to insert
/// Inser at First, Last and Specific position
/// Delete at First, Last and Specific position

import 'dart:io';

import '../../reusableMethod.dart';

/// Node class represent a node in a double-linked list
class Node {
  dynamic data;
  Node? previous;
  Node? next;

  Node(this.data);
}

/// DoubleLinkyList class represents a double-linked list.
class DoubleLinkyList {
  Node? head;
  Node? tail;
  int size;
  int maxSize;

  /// Contructs a DoubleLinkyList with a maximum size.
  DoubleLinkyList(this.maxSize) : size = 0;

  bool get isEmpty => head == null;
  bool get isFull => size == maxSize;

  /// Adds a new node with the given data at the end of the list.
  void addLast(dynamic data) {
    if (isFull) {
      print('The Node is full. Cannot add more.');
      PAUSE();
      return;
    }

    final newNode = Node(data);
    if (isEmpty) {
      head = newNode;
      tail = newNode;
    } else {
      newNode.previous = tail;
      tail!.next = newNode;
      tail = newNode;
    }
    size++;
  }

  /// Adds a  new node with the given data at the beginning of the list.
  void addFirst(dynamic data) {
    if (isFull) {
      print('The Node is full. Cannot add more.');
      PAUSE();
      return;
    }

    final newNode = Node(data);
    if (isEmpty) {
      head = newNode;
      tail = newNode;
    } else {
      newNode.next = head;
      head!.previous = newNode;
      head = newNode;
    }
    size++;
  }

  /// Inserts a new node with the given data at the specified position in the list.
  void insertAtPosition(dynamic data, int position) {
    if (position < 0 || position > size) {
      print('Invalid position.');
      PAUSE();
      return;
    }

    if (isFull) {
      print('The Node is full. Cannot add more.');
      PAUSE();
      return;
    }

    if (position == 0) {
      addFirst(data);
      return;
    }

    if (position == size) {
      addLast(data);
      return;
    }

    Node? current = head;
    int currentPosition = 0;

    while (current != null && currentPosition < position) {
      current = current.next;
      currentPosition++;
    }

    if (currentPosition == position) {
      final newNode = Node(data);
      newNode.previous = current!.previous;
      newNode.next = current;
      current.previous!.next = newNode;
      current.previous = newNode;
      size++;
    } else {
      print('Invalid position.');
      PAUSE();
    }
  }

  /// Removes the first node from the list
  void removeFirst() {
    if (isEmpty) {
      return;
    }

    if (head == tail) {
      head = null;
      tail = null;
    } else {
      head = head!.next;
      head!.previous = null;
    }
    size--;
  }

  /// Removes the last node from the lsit
  void removeLast() {
    if (isEmpty) {
      return;
    }

    if (head == tail) {
      head = null;
      tail = null;
    } else {
      tail = tail!.previous;
      tail!.next = null;
    }
    size--;
  }

  /// Removes the node at the specifed position in the list.
  void removeAtPosition(int position) {
    if (position < 0) {
      print('Invalid position');
      return;
    }

    if (isEmpty) {
      return;
    }

    if (position == 0) {
      removeFirst();
      return;
    }

    Node? current = head;
    Node? previous;
    int currentPosition = 0;

    while (current != null && currentPosition < position) {
      previous = current;
      current = current.next;
      currentPosition++;
    }

    if (current != null) {
      previous!.next = current.next;
      if (current.next != null) {
        current.next!.previous = previous;
      } else {
        tail = previous;
      }
      size--;
    } else {
      print('Invalid position');
    }
  }

  /// Displays the elements of the list
  void display() {
    Node? temp = head;
    while (temp != null) {
      stdout.write('${temp.data} -> ');
      temp = temp.next;
    }
  }
}

void main() {
  stdout.write('Enter the maximum size of the node: ');
  int? maxSize = int.tryParse(stdin.readLineSync()!);

  if (maxSize == null || maxSize <= 0) {
    print('Inavalid maximum size. Program will exit.');
    return;
  }

  final DoubleLinkyList doubleLinkList = DoubleLinkyList(maxSize);

  while (true) {
    CLEAR_CONSOLE();
    doubleLinkList.display();
    print('\nWhat do you want to do?');
    print('[1] Insert Node.');
    print('[2] Delete Node.');
    stdout.write('[3] Exit.\nChoice: ');
    int? userChoice = int.tryParse(stdin.readLineSync()!);

    switch (userChoice) {
      case 1:
        CLEAR_CONSOLE();
        doubleLinkList.display();
        print('\nInserting Node:');
        print('[1] Insert at first position.');
        print('[2] Insert at last position.');
        stdout.write('[3] Insert at specific position.\nChoice: ');
        int? insertChoice = int.tryParse(stdin.readLineSync()!);

        switch (insertChoice) {
          case 1:
            stdout.write('Enter the value: ');
            dynamic value = stdin.readLineSync()!;
            doubleLinkList.addFirst(value);
            break;
          case 2:
            stdout.write('Enter the value: ');
            dynamic value = stdin.readLineSync()!;
            doubleLinkList.addLast(value);
            break;
          case 3:
            stdout.write('Enter the position: ');
            int? position = int.tryParse(stdin.readLineSync()!);
            stdout.write('Enter the value: ');
            dynamic value = stdin.readLineSync()!;
            doubleLinkList.insertAtPosition(value, position!);
            break;
          default:
            print('Invalid choice.');
        }

        break;
      case 2:
        CLEAR_CONSOLE();
        doubleLinkList.display();
        print('\nDeleting Node:');
        print('[1] Delete first node');
        print('[2] Delete last node');
        stdout.write('[3] Delete node at specific position\nChoice: ');
        int? deleteChoice = int.tryParse(stdin.readLineSync()!);

        switch (deleteChoice) {
          case 1:
            doubleLinkList.removeFirst();
            break;
          case 2:
            doubleLinkList.removeLast();
            break;
          case 3:
            stdout.write('Enter the position: ');
            int? position = int.tryParse(stdin.readLineSync()!);
            doubleLinkList.removeAtPosition(position!);
            break;
          default:
            print('Invalid choice.');
        }

        break;
      case 3:
        print('\nExiting . . .');
        return;
      default:
        print('Invalid choice.');
        PAUSE();
    }
  }
}
