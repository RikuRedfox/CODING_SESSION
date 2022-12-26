#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class Calc {
private:
  int time, hr, min, sec;
  double distance, speed;

public:
  inline int t(int, int, int);
  void getTime();
  void getDistance();
  void getSpeed();
};

std::string respond;

int main() {
  Calc calc;

  while (true) {
    std::cout << "\n\tChoice what to calculate\n"
                 "(Type : 'Time', 'Distance', 'Speed') : ";
    std::cin >> respond;

    std::for_each(respond.begin(), respond.end(),
                  [](char &c) { c = ::tolower(c); });
    if (respond == "time") {
      calc.getTime();
    } else if (respond == "speed") {
      calc.getSpeed();
    } else if (respond == "distance") {
      calc.getDistance();
    } else {
      std::cout << "\nNope we don't have that. Try again.\n" << std::endl;
      continue;
    }

    std::cout << "\n\nWant to try again or try other?\n"
                 "(Press 'Y' to yes | 'any' to exit) : ";
    // std::string respond1;
    std::cin >> respond;
    if (respond == "Y" || respond == "y") {
      continue;
    } else {
      break;
    }
  }
  return 0;
}

// void Calc::setValues(int Time, int Hour, int Min, int Sec, double Distance,
//                      double Speed) {
//   time = Time;
//   hr = Hour;
//   min = Min;
//   sec = Sec;
//   distance = Distance;
//   speed = Speed;
// }

inline int Calc::t(int hr, int min, int sec) {
  time = 0;
  time += sec;
  time += (min * 60);
  time += (hr * 3600);
  return time;
}

inline void Calc::getDistance() {
  // Speed
  std::cout << "Enter Speed (m/sec) : ";
  std::cin >> speed;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "\n\nERROR: The input cannot be a string.\n\n";

    std::cout << "Enter Speed (meter/sec) : ";
    std::cin >> speed;
  }

  // Time
  std::cout << "\n\tEnter Time (hh:mm:ss)\n";
  std::cout << "Enter second [0 - 59]: ";
  std::cin >> sec;
  std::cout << "Enter minute [0 - 59]: ";
  std::cin >> min;
  std::cout << "Enter hour : ";
  std::cin >> hr;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "\n\nERROR : Must not be a string or a double.\n\n";

    std::cout << "\n\tEnter Time (hh:mm:ss)\n";
    std::cout << "Enter second [0 - 59]: ";
    std::cin >> sec;
    std::cout << "Enter minute [0 - 59]: ";
    std::cin >> min;
    std::cout << "Enter hour : ";
    std::cin >> hr;
  }
  if (sec >= 60)
    sec = 59;
  if (min >= 60)
    min = 59;

  std::cout << "Distance : " << (speed * t(hr, min, sec)) << " meters.";
}

inline void Calc::getSpeed() {
  // Distance
  std::cout << "Enter Distance (meters) : ";
  std::cin >> distance;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "ERROR: The input cannot be a string.\n";
    std::cout << "Enter Distance (meters) : ";
    std::cin >> distance;
  }
  // Time
  std::cout << "\n\tEnter Time (hh:mm:ss)\n";
  std::cout << "Enter second [0 - 59]: ";
  std::cin >> sec;
  std::cout << "Enter minute [0 - 59]: ";
  std::cin >> min;
  std::cout << "Enter hour : ";
  std::cin >> hr;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "\n\nERROR : Must not be a string or a double.\n\n";

    std::cout << "\n\tEnter Time (hh:mm:ss)\n";
    std::cout << "Enter second [0 - 59]: ";
    std::cin >> sec;
    std::cout << "Enter minute [0 - 59]: ";
    std::cin >> min;
    std::cout << "Enter hour : ";
    std::cin >> hr;
  }
  if (sec >= 60)
    sec = 59;
  if (min >= 60)
    min = 59;
  std::cout << "Speed : " << (distance / t(hr, min, sec)) << " m/sec";
}

inline void Calc::getTime() {
  // Distance
  std::cout << "Enter Distance (meters) : ";
  std::cin >> distance;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "ERROR: The input cannot be a string.\n";
    std::cout << "Enter Distance (meters) : ";
    std::cin >> distance;
  }

  // Speed
  std::cout << "Enter Speed (m/sec) : ";
  std::cin >> speed;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "\n\nERROR : Must not be a string or a double.\n\n";

    std::cout << "Enter Speed (m/sec) : ";
    std::cin >> speed;
  }

  sec = (distance / speed);
  min = 0;
  hr = 0;
  while (true) {
    if (sec < 60 && min < 60)
      break;
    if (sec >= 60) {
      min++;
      sec -= 60;
    }
    if (min >= 60) {
      hr++;
      min -= 60;
    }
  }

  std::cout << "Time : " << hr << " [hrs] : " << min << " [mins] : " << sec
            << " [secs]";
}