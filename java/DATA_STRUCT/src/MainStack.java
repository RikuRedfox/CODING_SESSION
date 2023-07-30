class Stack {
  private Object[] data;
  private int size;
  private int top;

  Stack(int size) {
    this.data = new Object[size];
    this.size = size;
    this.top = -1;
  }

  boolean isFull() {
    return top == size - 1;
  }

  boolean isEmpty() {
    return top == -1;
  }

  void push(Object value) {
    if (isFull())
      System.out.println("Stack Overflow");
    else
      data[++top] = value;
  }

  void pop() {
    if (isEmpty()) {
      System.out.println("Stack Underflow");
    } else {
      Object value = data[top--];
      System.out.println(value + " has been popped from the Stack");
    }
  }

  void StackDisplay() {
    if (isEmpty()) {
      System.out.println("Stack is empty.");
    } else {
      System.out.println("Stack: ");
      for (Object item : data)
        System.out.println(item + " <- ");

      System.out.println();
    }
  }

}

public class MainStack {
  public static void main(String[] args) {
    java.util.Scanner sc = new java.util.Scanner(System.in);
    int size;
    Stack stack;

    System.out.print("Enter the size of the stack: ");
    size = sc.nextInt();
    stack = new Stack(size);

    int userChoice = 0;

    while (userChoice != 3) {
      Terminal.CLEAR_CONSOLE();
      System.out.println("Size of Stack: " + size);
      stack.StackDisplay();
      System.out.print("""
          [1] Push Element
          [2] Pop Element
          [3] Exit
          """);

      System.out.print("Choose your poison: ");
      userChoice = sc.nextInt();
      sc.nextLine();

      switch (userChoice) {
        case 1:
          Terminal.CLEAR_CONSOLE();
          System.out.print("Enter value: ");
          Object value = sc.nextLine();
          stack.push(value);
          break;
        case 2:
          stack.pop();
          Terminal.PAUSE();
          break;
        case 3:
          return;
        default:
          System.out.println("Invalid Choice");
          Terminal.PAUSE();
      }
    }
    sc.close();
  }
}
