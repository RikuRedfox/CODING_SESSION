#include <iostream>
// 6 - 8 - 2022
int power(int baseNum, int powNum) {

  int result = 1;
  for (int i = 0; i < powNum; i++) {
    result = result * baseNum;
  }

  return result;
}

int main() {

  int num1, num2;

  std::cout << "Enter two numbers : \n";
  for (size_t i = 0; i < 2; i++) {
    if (i == 0) {
      std::cout << "[1] : ";
      std::cin >> num1;
    } else {
      std::cout << "[2] : ";
      std::cin >> num2;
    }
  }
  std::cout << power(num1, num2);

  return 0;
}