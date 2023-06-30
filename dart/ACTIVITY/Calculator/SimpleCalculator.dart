import 'dart:io';

void main() {
  /// Simple calculator that add, sub, mul, div.

  void performOperation(
      double a, double b, Function(double, double) operation) {
    var result = operation(a, b);
    print("Result: $result");
    stdin.readLineSync();
  }

  stdout.write("Enter first number: ");
  double num1 = double.parse(stdin.readLineSync()!);
  stdout.write("Enter second number: ");
  double num2 = double.parse(stdin.readLineSync()!);

  stdout.write("Enter operation: ");
  String op = stdin.readLineSync()!;

  switch (op) {
    case '+':
      performOperation(num1, num2, (p0, p1) => p0 + p1);
      break;
    case '-':
      performOperation(num1, num2, (p0, p1) => p0 - p1);
      break;
    case '*':
      performOperation(num1, num2, (p0, p1) => p0 * p1);
      break;
    case '/':
      performOperation(num1, num2, (p0, p1) => p0 / p1);
      break;
    case '%':
      performOperation(num1, num2, (p0, p1) => p0 % p1);
      break;
    default:
      print("Syntax ERROR!");
      stdin.readLineSync();
      break;
  }
}