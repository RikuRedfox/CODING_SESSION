import java.util.Scanner;
import java.util.InputMismatchException;
import java.util.Optional;

 // ! Bug in swap?
class QueueElement {
  private Object data;

  QueueElement(Object data) {
    this.data = data;
  }

  Object getData() {
    return data;
  }
}

public class Queue {
  private static Scanner scanner = new Scanner(System.in);
  private QueueElement[] queue;
  private int front;
  private int rear;
  private int size;
  private int capacity;

  boolean isEmpty() {
    return size == 0;
  }

  boolean isFull() {
    return size == capacity;
  }

  int size() {
    return size;
  }

  Queue(int capacity) {
    this.capacity = capacity;
    queue = new QueueElement[capacity];
    front = 0;
    rear = -1;
    size = 0;
  }

  void push(Object data) {
    if (isFull()) {
      System.out.println("Queue is full.");
      return;
    }

    rear = (rear + 1) % capacity;
    queue[rear] = new QueueElement(data);
    if (front == -1) {
      front = rear;
    }
    size++;
  }

  Object pop() {
    if (isEmpty()) {
      System.out.println("Queue is empty.");
      return null;
    }

    QueueElement frontElement = queue[front];
    front = (front + 1) & capacity;
    size--;
    return frontElement.getData();
  }

  Object peekFirst() {
    if (isEmpty()) {
      System.out.println("Queue is empty.");
      return null;
    }

    return queue[front].getData();
  }

  Object peekLast() {
    if (isEmpty()) {
      System.out.println("Queue is empty.");
      return null;
    }

    return queue[rear].getData();
  }

  void swapElements(int index1, int index2) {
    if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= 0) {
      System.out.println("Invalid index.");
      return;
    }

    QueueElement temp = queue[(front + index1) % capacity];
    queue[(front + index1) % capacity] = queue[(front + index2) % capacity];
    queue[(front + index2) % capacity] = temp;
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder("[");
    for (int i = 0; i < size; i++) {
      sb.append(queue[(front + i) % capacity].getData().toString()).append(", ");
    }
    if (size > 0) {
      sb.delete(sb.length() - 2, sb.length());
    }
    sb.append("]");
    return sb.toString();
  }

  
  public static void main(String[] args) {

    System.out.print("Enter the capacity of the queue: ");
    int capacity = scanner.nextInt();
    Queue queue = new Queue(capacity);

    while (true) {
      System.out.print("""
          \nQueue Operation:
          1.) Push Element.
          2.) Pop Element.
          3.) Peek First Element.
          4.) Peek Last Element.
          5.) Swap Elements [bugged].
          6.) Check Queue size.
          0.) Exit.
          """);
      System.out.print("Input: ");

      Optional<Integer> choose = Optional.empty();

      try {
        choose = Optional.of(scanner.nextInt());
      } catch (InputMismatchException e) {
        System.out.println("Invalid input. Please enter a valid integer.");
        scanner.nextLine();
      }
     
      choose.ifPresent(value -> {
        switch (value) {
          case 1:
            System.out.print("Enter the element to push: ");
            scanner.nextLine(); // Consume the newline character
            Object data = scanner.nextLine();
            queue.push(data);
            System.out.println("Element " + data + " pushed to the queue.");
            break;
          case 2:
            Object popObject = queue.pop();
            if (popObject != null) {
            System.out.println("Popped element: " + popObject);
            }
            break;
          case 3:
            Object firstElement = queue.peekFirst();
            if (firstElement != null) {
              System.out.println("First element: " + firstElement);
            }
            break;
          case 4:
            Object lastElement = queue.peekLast();
            if (lastElement != null) {
              System.out.println("Last element: " + lastElement);
            }
            break;
          case 5:
            System.out.print("Enter the indices of the elements to swap(separated by space): ");
            int index1 = scanner.nextInt();
            int index2 = scanner.nextInt();
            queue.swapElements(index1, index2);
            System.out.println("Elements swapped at indices " + index1 + " and " + index2 + ".");
            break;
          case 6:
            System.out.println("Queue size: " + queue.size());
            break;
          case 0:
            System.out.println("Exiting the program.");
            System.exit(0);
            break;
          default:
            System.out.println("Invalid Option.");
        }
      });
    }
  }
}