#include <iostream>
#include <limits>
#include <sstream>

int main() {
  double x, y, result;
  char op;
  while (1) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Put the calculation you want to do in here. [ex: 1 + 2]\n>>";
    std::cin >> x >> op >> y;

    switch (op) {
    case '+':
      result = x + y;
      break;
    case '-':
      result = x - y;
      break;
    case '*':
      result = x * y;
      break;
    case '/':
      result = x / y;
      break;
    case '%':
      int Result = result, a = x, b = y;
      Result = a % b;
      std::cout << "= " << Result << std::endl;
      break;
    }
    std::cout << "= " << result << std::endl;
  }

  return 0;
}