import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Stack {
  private List<Object> data;
  private int size;

  Stack(int size) {
    this.data = new ArrayList<>();
    this.size = size;
  }

  boolean isFull() {
    return data.size() == size;
  }

  boolean isEmpty() {
    return data.isEmpty();
  }

  void push(Object value) {
    if (isFull())
      System.out.println("Stack Overflow");
    else
      data.add(value);
  }

  void pop() {
    if (isEmpty()) {
      System.out.println("Stack Underflow");
    } else {
      Object value = data.remove(data.size() - 1);
      System.out.println(value + " has been popped from the Stack");
    }
  }

  void StackDisplay() {
    if (isEmpty()) {
      System.out.println("Stack is empty.");
    } else {
      StringBuilder sb = new StringBuilder();
      for (Object item : data)
        sb.append(item + " <- ");

      System.out.println(sb.toString());
    }
  }

}

public class MainStack {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
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
