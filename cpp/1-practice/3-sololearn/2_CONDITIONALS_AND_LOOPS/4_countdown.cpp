#include <iostream>

int main() {
  int seconds;
  std::cin >> seconds;

  // your code goes here
  while(seconds >= 0 ){
    std::cout << seconds << std::endl;
    seconds--;
  }

  return 0;
}