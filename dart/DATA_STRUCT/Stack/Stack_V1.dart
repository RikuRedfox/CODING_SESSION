class Stack<T> {
  List<T> _items = [];

  /// Check if the stack is empty
  bool get isEmpty => _items.isEmpty;
  /// Returns the number of elements in the stack
  int get length => _items.length;

  // Pushes an item onto the top of the stack.
  void push(T item) {
    _items.add(item);
  }

  /// Removes and returns the top item from the stack
  /// 
  /// otherwise Throws an exception if the stack is empty.
  T pop() {
    if (isEmpty) {
      throw Exception("Stack is empty.");
    }
    return _items.removeLast();
  }

  /// Returns the top item from the stack without removing it
  /// 
  /// otherwise Throws an exception if the stack is empty.
  T peek(){
    if(isEmpty){
      throw Exception("Stack is empty.");
    }
    return _items.last;
  }

  /// Removes all items from the stack.
  void clear(){
    _items.clear();
  }
}

void main() {
  Stack<int> stack = Stack();

  stack.push(10);
  stack.push(20);
  stack.push(30);

  print("Stack length: ${stack.length}");
  print("Top item: ${stack.peek()}\n");

  while(!stack.isEmpty){
    print("Popped item: ${stack.pop()}");
  }

  print("\nStack length: ${stack.length}");

  stack.clear();
}