import 'dart:io';

class Stack {
  List<dynamic> _data;
  int _size; // Maximum size of the stack

  Stack(int size)
      : _data = [],
        _size = size; // Cnstructor to initize the stack

  bool get isFull => _data.length == _size; // check if the stack is full
  bool get isEmpty => _data.isEmpty; // Check if the stack is empty

  /// If stack is empty, print empty message
  /// otherwise print stack elements seprated by '<<'
  void printStack() {
    if (isEmpty) {
      print("Stack is empty.");
    } else {
      print(_data.map((item) => '$item << ').join());
    }
  }

  /// If stack is full, print the Stack is empty
  /// otherwise add element to the top of the stack
  void push(dynamic value) {
    if (isFull) {
      print("Stack Overflow");
    } else {
      _data.add(value);
    }
  }

  /// if stack is empty, print underflow message
  /// otherwise remove and retrive the top element
  void pop() {
    if (isEmpty) {
      print("Stack Underflow");
    } else {
      var value = _data.removeLast();
      print('$value has been popped from the Stack');
    }
  }
}

void clearScreen() {
  print('\x1B[2J\x1B[0;0H');
}

void pause() {
  print('Press Enter to continue...');
  stdin.readLineSync();
}

void main() {
  var size = 5;
  var stack = Stack(size);
  var userChoice = 0;

  while (userChoice != 3) {
    clearScreen();
    print("==== Number Stack Menu ====");
    stack.printStack();
    print("[1] Push Element\n[2] Pop Element\n[3] Exit");
    print("===========================");
    userChoice = int.parse(stdin.readLineSync()!);

    switch (userChoice) {
      case 1: // Add element to top
        clearScreen();
        print("Enter a Number:");
        var element = int.parse(stdin.readLineSync()!);
        stack.push(element);
        pause();
        break;
      case 2: // Remove last element
        stack.pop();
        pause();
        break;
      case 3: // Exit
        break;
      default:
        print("I don't understand that...");
        pause();
    }
  }
}