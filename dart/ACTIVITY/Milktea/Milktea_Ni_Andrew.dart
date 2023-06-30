import 'dart:io';
import 'dart:math';

const String CLEAR_LOG = "\x1B[2J\x1B[0;0H";

void main() => Order().RunProgram();

class Order {
  static const List<String> flavorNames = [
    "Mango            ",
    "Vanilla          ",
    "Cookies and Cream",
    "Coffee           ",
    "Almond           ",
    "Nutella          ",
    "Choco            ",
    "Mocha            ",
    "Cheesecake       ",
    "Caramel          "
  ];
  static const List<String> sizes = ['S', 'M', 'L'];
  static const List<int> prices = [30, 60, 90];

  final int orderID = Random().nextInt(1000) + 1;
  int totalOrders = 0;
  double totalPrice = 0.0;
  double payment = 0.0;

  List<MilkteaOrder> orders = [];

  void RunProgram() {
    print("Welcome to Andrew's Milktea Shop!");

    totalOrders = getIntInput("How many orders would you like? (Max 10)",
        validation: (value) => value >= 1 && value <= 10);

    printMenu();
    printOrder();

    totalPrice = calculateTotalPrice();
    print("Total: ${totalPrice.toStringAsFixed(2)}");

    payment = getDoubleInput("Enter your payment",
        validation: (value) => value >= totalPrice);

    printReceipt();
  }

  void printMenu() {
    print(CLEAR_LOG);
    print("SIZE\t\t\t\tPRICES");
    print("[1] Small \t\t\t30 Php");
    print("[2] Medium \t\t\t60 Php");
    print("[3] Large \t\t\t90 Php");

    print('\n');

    for (int i = 0; i < flavorNames.length; i++) {
      print("${i + 1}) ${flavorNames[i]}");
    }

    getOrder();
  }

  void getOrder() {
    for (int i = 0; i < totalOrders; i++) {
      print("\nNumber Order > ${i + 1}");

      int flavorID = getIntInput("Enter the Flavor ID (1-10)",
          validation: (value) => value >= 1 && value <= 10);
      int sizeID = getIntInput("Enter the Size ID (1-3)",
          validation: (value) => value >= 1 && value <= 3);

      sizeID--;
      var order = MilkteaOrder(
          flavor: flavorNames[flavorID - 1],
          size: sizes[sizeID],
          price: prices[sizeID]);
      orders.add(order);
    }
  }

  void printReceipt() {
    print(CLEAR_LOG);
    print(DateTime.now());
    print("Order#: $orderID");

    print('\n');
    printOrder();

    print('\n');
    print("TOTAL: ${totalPrice.toStringAsFixed(2)}");
    print("CASH: $payment");
    print("CHANGE: ${(payment - totalPrice).toStringAsFixed(2)}");
  }

  void printOrder() {
    for (int i = 0; i < orders.length; i++) {
      var order = orders[i];
      print(
          "Flavor: ${order.flavor} | Price[Size]: ${order.price} ${order.size}");
    }
  }

  double calculateTotalPrice() {
    return orders.fold(0, (total, order) => total + order.price);
  }

  int getIntInput(String prompt, {bool Function(int)? validation}) {
    while (true) {
      try {
        stdout.write('$prompt > ');
        var input = stdin.readLineSync();
        var value = int.parse(input!);
        if (validation == null || validation(value)) {
          return value;
        }
        print('Invalid input. Try again.');
      } on FormatException {
        print('Invalid input. Try again.');
      }
    }
  }

  double getDoubleInput(String prompt, {bool Function(double)? validation}) {
    while (true) {
      try {
        stdout.write('$prompt > ');
        var input = stdin.readLineSync();
        var value = double.parse(input!);
        if (validation == null || validation(value)) {
          return value;
        }
        print('Invalid input. Try again.');
      } on FormatException {
        print('Invalid input. Try again.');
      }
    }
  }
}

class MilkteaOrder {
  final String flavor;
  final String size;
  final int price;

  MilkteaOrder({required this.flavor, required this.size, required this.price});
}