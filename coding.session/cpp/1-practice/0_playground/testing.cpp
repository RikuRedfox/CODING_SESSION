#include <iostream>
#include <limits>
#include <sstream>

int main(int argc, char const *argv[]) {

  double time;
  std::cout << "Time : ";
  std::cin >> time;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Time : ";
    std::cin >> time;
  }

  time *= 60;
  std::cout << "Time : " << time;
  return 0;
}
