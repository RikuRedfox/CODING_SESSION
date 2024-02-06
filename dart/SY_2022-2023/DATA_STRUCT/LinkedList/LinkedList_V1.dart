/// Author: Andrew Jules R. Miyajima
/// Date: June 8, 2023
///
/// example of Linked List in dart.
class Node {
  dynamic data;
  Node? next;

  Node(this.data);
}

class LinkedList {
  Node? head;

  bool get isEmpty => head == null;

  void add(dynamic data) {
    final newNode = Node(data);
    if (isEmpty) {
      head = newNode;
    } else {
      Node? temp = head;
      while (temp?.next != null) {
        temp = temp!.next;
      }
      temp!.next = newNode;
    }
  }

  void remove(dynamic data) {
    if (isEmpty) {
      return;
    }

    if (head?.data == data) {
      head == head?.next;
      return;
    }

    Node? temp = head;
    Node? prev;

    while (temp != null && temp.data != data) {
      prev = temp;
      temp = temp.next;
    }

    if (temp == null) {
      return;
    }

    prev?.next = temp.next;
  }

  void display() {
    Node? temp = head;
    while (temp != null) {
      print(temp.data);
      temp = temp.next;
    }
  }
}

void main() {
  final LinkedList linkedList = LinkedList();

  linkedList.add(10);
  linkedList.add(20);
  linkedList.add(30);
  linkedList.add(40);
  linkedList.add('50');
  linkedList.add(60.60);
  linkedList.add(true);
  linkedList.display();

  print('\n');

  linkedList.remove('50');
  linkedList.remove(20);
  linkedList.remove(60.6);
  linkedList.display();
}