#include <iostream>
#include <limits>
#include <sstream>

int main(int argc, char const *argv[]) {

  int time, hr, min, sec;

  std::cout << "\nEnter second : ";
  std::cin >> sec;
  time += sec;

  if (sec >= 60) {
    while (sec < 60) {
      sec /= 60;
      min += sec;
      min *= 60;
      sec += min;
      time += sec;
    }
  }

  std::cout << "\nEnter minute : ";
  std::cin >> min;
  time += (min * 60);

  if (min >= 60) {
    while (min < 60) {
      min /= 60;
      sec += 3600;
      time += sec;
    }
  }

  std::cout << "Enter hour : ";
  std::cin >> hr;
  time += (hr * 3600);

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\nERROR : Must not be a string or a double.\n\n";
    time = 0;

    std::cout << "\nEnter second : ";
    std::cin >> sec;
    time += sec;

    if (sec >= 60) {
      while (sec < 60) {
        sec /= 60;
        min += sec;
        min *= 60;
        sec += min;
        time += sec;
      }
    }

    std::cout << "\nEnter minute : ";
    std::cin >> min;
    time += (min * 60);

    if (min >= 60) {
      while (min < 60) {
        min /= 60;
        sec += 3600;
        time += sec;
      }
    }

    std::cout << "Enter hour : ";
    std::cin >> hr;
    time += (hr * 3600);
  }

  std::cout << "Time : " << time << " seconds\n";
  return 0;
}
