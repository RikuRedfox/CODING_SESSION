#include <iostream>

int main() {
  // your code goes here
  float celsius;
  std::cin >> celsius;

  if (celsius > 36.1 && celsius < 36.9)
    std::cout << "OK";
  else
    std::cout << "Not OK";

  return 0;
}