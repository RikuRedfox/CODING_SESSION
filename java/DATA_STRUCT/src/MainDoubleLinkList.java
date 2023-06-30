import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Node {
    Object data;
    Node previous;
    Node next;

    Node(Object data) {
        this.data = data;
    }
}

class DoubleLinkyList {
    Node head;
    Node tail;
    int size;
    int maxSize;

    DoubleLinkyList(int maxSize) {
        this.maxSize = maxSize;
        size = 0;
    }

    boolean isEmpty() {
        return head == null;
    }

    boolean isFull() {
        return size == maxSize;
    }

    void addLast(Object data) {
        if (isFull()) {
            System.out.println("The Node is full. Cannot add more.");
            Terminal.PAUSE();
            return;
        }

        Node newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode.previous = tail;
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addFirst(Object data) {
        if (isFull()) {
            System.out.println("The Node is full. Cannot add more.");
            Terminal.PAUSE();
            return;
        }

        Node newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode.next = head;
            head.previous = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtPosition(Object data, int position) {
        if (position < 0 || position > size) {
            System.out.println("Invalid position.");
            Terminal.PAUSE();
            return;
        }

        if (isFull()) {
            System.out.println("The Node is full. Cannot add more.");
            Terminal.PAUSE();
            return;
        }

        if (position == 0) {
            addFirst(data);
            return;
        }

        Node current = head;
        int currentPosition = 0;

        while (current != null && currentPosition < position) {
            current = current.next;
            currentPosition++;
        }

        if (currentPosition == position) {
            Node newNode = new Node(data);
            newNode.previous = current.previous;
            newNode.next = current;
            current.previous.next = newNode;
            current.previous = newNode;
            size++;
        } else {
            System.out.println("Invalid position.");
            Terminal.PAUSE();
        }
    }

    void removeFirst() {
        if (isEmpty()) {
            return;
        }

        if (head == tail) {
            head = null;
            tail = null;
        } else {
            head = head.next;
            head.previous = null;
        }
        size--;
    }

    void removeLast() {
        if (isEmpty()) {
            return;
        }

        if (head == tail) {
            head = null;
            tail = null;
        } else {
            tail = tail.previous;
            tail.next = null;
        }
        size--;
    }

    void removeAtPosition(int position) {
        if (position < 0) {
            System.out.println("Invalid position.");
            return;
        }

        if (isEmpty()) {
            return;
        }

        if (position == 0) {
            removeFirst();
            return;
        }

        Node current = head;
        Node previous = null;
        int currentPosition = 0;

        while (current != null && currentPosition < position) {
            previous = current;
            current = current.next;
            currentPosition++;
        }

        if (current != null) {
            previous.next = current.next;
            if (current.next != null) {
                current.next.previous = previous;
            } else {
                tail = previous;
            }
            size--;
        } else {
            System.out.println("Invalid position.");
        }
    }

    void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
    }
}

class MainDoubleLinkList {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter the maximum size of the node: ");
        int maxSize = Integer.parseInt(reader.readLine());

        if (maxSize <= 0) {
            System.out.println("Invalid maximum size. Program will exit.");
            return;
        }

        DoubleLinkyList doubleLinkList = new DoubleLinkyList(maxSize);

        while (true) {
            Terminal.CLEAR_CONSOLE();
            doubleLinkList.display();
            System.out.println("\nWhat do you want to do?");
            System.out.println("[1] Insert Node.");
            System.out.println("[2] Delete Node.");
            System.out.print("[3] Exit.\nChoice: ");
            int userChoice = Integer.parseInt(reader.readLine());

            switch (userChoice) {
                case 1:
                    Terminal.CLEAR_CONSOLE();
                    doubleLinkList.display();
                    System.out.println("\nInserting Node:");
                    System.out.println("[1] Insert at first position.");
                    System.out.println("[2] Insert at last position.");
                    System.out.print("[3] Insert at specific position.\nChoice: ");
                    int insertChoice = Integer.parseInt(reader.readLine());

                    switch (insertChoice) {
                        case 1:
                            System.out.print("Enter the value: ");
                            Object value = reader.readLine();
                            doubleLinkList.addFirst(value);
                            break;
                        case 2:
                            System.out.print("Enter the value: ");
                            value = reader.readLine();
                            doubleLinkList.addLast(value);
                            break;
                        case 3:
                            System.out.print("Enter the position: ");
                            int position = Integer.parseInt(reader.readLine());
                            System.out.print("Enter the value: ");
                            value = reader.readLine();
                            doubleLinkList.insertAtPosition(value, position);
                            break;
                        default:
                            System.out.println("Invalid choice.");
                    }

                    break;
                case 2:
                    Terminal.CLEAR_CONSOLE();
                    doubleLinkList.display();
                    System.out.println("\nDeleting Node:");
                    System.out.println("[1] Delete first node");
                    System.out.println("[2] Delete last node");
                    System.out.print("[3] Delete node at specific position\nChoice: ");
                    int deleteChoice = Integer.parseInt(reader.readLine());

                    switch (deleteChoice) {
                        case 1:
                            doubleLinkList.removeFirst();
                            break;
                        case 2:
                            doubleLinkList.removeLast();
                            break;
                        case 3:
                            System.out.print("Enter the position: ");
                            int position = Integer.parseInt(reader.readLine());
                            doubleLinkList.removeAtPosition(position);
                            break;
                        default:
                            System.out.println("Invalid choice.");
                    }

                    break;
                case 3:
                    System.out.println("\nExiting...");
                    return;
                default:
                    System.out.println("Invalid choice.");
                    Terminal.PAUSE();
            }
        }
    }
}
