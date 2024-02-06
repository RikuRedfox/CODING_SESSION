import 'dart:io';
import '../../reusableMethod.dart';

class Order {
  final String name;
  final int price;
  final int quantity;

  Order(this.name, this.price, this.quantity);
}

void main() {
  String repond;

  while (true) {
    CLEAR_CONSOLE();
    final List<Order> orders = [];
    double total = 0;

    final LOAD_USER_ORDER = () {
      orders.asMap().forEach((index, order) {
        stdout.writeln(
            'Item ${index + 1} : ${order.name} | Quantity: ${order.quantity} | Unit Price: ${order.price} | Total Price: ${order.price * order.quantity}');
      });
    };

    do {
      CLEAR_CONSOLE();
      printMenu();

      final String order;
      final int qty;

      try {
        stdout.write('Order: ');
        order = stdin.readLineSync()!;
        if (num.parse(order) < 1 || num.parse(order) > 16) continue;
        stdout.write('Quantity: ');
        qty = int.parse(stdin.readLineSync()!);
      } on FormatException catch (_) {
        continue;
      }

      final String name;
      final int price;
      switch (order) {
        case '1':
          name = 'Hame & Cheese';
          price = 55;
          break;
        case '2':
          name = 'Burger';
          price = 60;
          break;
        case '3':
          name = 'Clubhouse';
          price = 85;
          break;
        case '4':
          name = 'Tuna';
          price = 50;
          break;
        case '5':
          name = 'Spaghetti';
          price = 85;
          break;
        case '6':
          name = 'Carbonara';
          price = 85;
          break;
        case '7':
          name = 'Lasagna';
          price = 90;
          break;
        case '8':
          name = 'Baked Mac';
          price = 90;
          break;
        case '9':
          name = 'Friend Chicken';
          price = 110;
          break;
        case '10':
          name = 'Pork Chop';
          price = 115;
          break;
        case '11':
          name = 'Steak';
          price = 150;
          break;
        case '12':
          name = 'Fish Fillet';
          price = 140;
          break;
        case '13':
          name = 'Soda';
          price = 20;
          break;
        case '14':
          name = 'Iced Tea';
          price = 25;
          break;
        case '15':
          name = 'Orange Juice';
          price = 25;
          break;
        case '16':
          name = 'Coffee';
          price = 30;
          break;
        default:
          print('Syntax Error. Try again.');
          PAUSE();
          continue;
      }

      orders.add(Order(name, price, qty));
      stdout.writeln();

      LOAD_USER_ORDER();

      stdout.writeln(
          "Do you want to order again?\n ['Y' for yes | any key for no] >>> ");
      repond = stdin.readLineSync()!.toLowerCase();
      if (repond != 'y') break;
    } while (true);

    total = orders.fold(
        0, (subtotal, order) => subtotal + order.price * order.quantity);

    CLEAR_CONSOLE();
    double cash;
    do {
      try {
        stdout.writeln('Total: $total');
        stdout.writeln('Enter Cash: ');
        cash = double.parse(stdin.readLineSync()!);
      } on FormatException catch (_) {
        continue;
      }
      if (cash >= total) break;
      stdout.writeln('Insufficient funds.');
    } while (true);

    CLEAR_CONSOLE();
    stdout.writeln('Receipt: ');
    stdout.writeln(DateTime.now());
    stdout.writeln();
    LOAD_USER_ORDER();
    stdout.writeln();
    stdout.writeln('TOTAL: $total');
    stdout.writeln('CASH: $cash');
    stdout.writeln('CHANGE: ${cash - total}');
    PAUSE();
  }
}

void printMenu() {
  stdout.writeln('\n\tSandwiches' '${' ' * 35}Main Dish w/ Rice');
  stdout.writeln('[1] Ham & Cheese\t - - - - PHP 55'
      '${' ' * 5}[9]  Fried Chicken\t - - - - PHP 110');
  stdout.writeln('[2] Burger\t\t - - - - PHP 50'
      '${' ' * 4} [10] Pork Chop\t - - - - PHP 115');
  stdout.writeln('[3] Clubhouse\t\t - - - - PHP 85'
      '${' ' * 5}[11] Steak\t\t - - - - PHP 150');
  stdout.writeln('[4] Tuna\t\t - - - - PHP 50'
      '${' ' * 5}[12] Fish Fillet\t - - - - PHP 140');

  stdout.writeln('\n\tPaste' '${' ' * 39} Drinks');
  stdout.writeln('[5] Spaghetti\t\t - - - - PHP 85'
      '${' ' * 5}[13] Soda\t\t - - - - PHP 20');
  stdout.writeln('[6] Carbonara\t\t - - - - PHP 85'
      '${' ' * 5}[14] Iced Tea\t - - - - PHP 25');
  stdout.writeln('[7] Lasagna\t\t - - - - PHP 90'
      '${' ' * 5}[15] Orange Juice\t - - - - PHP 25');
  stdout.writeln('[8] Baked Mac\t\t - - - - PHP 90'
      '${' ' * 5}[16] Coffee\t\t - - - - PHP 30');
}