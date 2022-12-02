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
  void setValues(int, int, int, int, double, double);

  double s(double);
  double d(double);
  int t(int, int, int, int);

  void getTime();
  void getDistance();
  void getSpeed();
};

std::string respond;

int main() {
  Calc calc;

  while (true) {
    std::cout << "\n\tChoice what to calculate\n"
                 "(Type 'Time', 'Distance', 'Speed') : ";
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

void Calc::setValues(int Time, int Hour, int Min, int Sec, double Distance,
                     double Speed) {
  time = Time;
  hr = Hour;
  min = Min;
  sec = Sec;
  distance = Distance;
  speed = Speed;
}

inline double Calc::s(double speed) { return speed; }
inline int Calc::t(int hr, int min, int sec, int time) {
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
  
  time += (min * 60);
  if (min >= 60) {
    while (min < 60) {
      min /= 60;
      sec += 3600;
      time += sec;
    }
  }

  time += (hr * 3600);
  return time;
}
inline double Calc::d(double distance) { return distance; }
inline void Calc::getDistance() {
  // Speed
  std::cout << "Enter Speed (m/sec) : ";
  std::cin >> speed;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "\n\nERROR: The input cannot be a string.\n\n";

    std::cout << "Enter Speed (m/sec) : ";
    std::cin >> speed;
  }

  // Time
  std::cout << "\n\tEnter Time (hh:mm:ss)\n";
  std::cout << "Enter second : ";
  std::cin >> sec;
  std::cout << "Enter minute : ";
  std::cin >> min;
  std::cout << "Enter hour : ";
  std::cin >> hr;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "\n\nERROR : Must not be a string or a double.\n\n";

    std::cout << "\n\tEnter Time (hh:mm:ss)\n";
    std::cout << "Enter second : ";
    std::cin >> sec;
    std::cout << "Enter minute : ";
    std::cin >> min;
    std::cout << "Enter hour : ";
    std::cin >> hr;
  }

  std::cout << "Distance : " << (s(speed) * t(hr, min, sec, 0)) << " meters.";
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
  std::cout << "Enter second : ";
  std::cin >> sec;
  std::cout << "Enter minute : ";
  std::cin >> min;
  std::cout << "Enter hour : ";
  std::cin >> hr;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "\n\nERROR : Must not be a string or a double.\n\n";

    std::cout << "\n\tEnter Time (hh:mm:ss)\n";
    std::cout << "Enter second : ";
    std::cin >> sec;
    std::cout << "Enter minute : ";
    std::cin >> min;
    std::cout << "Enter hour : ";
    std::cin >> hr;
  }
  std::cout << "Speed : " << (d(distance) / t(hr, min, sec, 0)) << " m/sec";
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

  sec = (d(distance) / s(speed));
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

  std::cout << hr << " [hour] : " << min << " [mins] : " << sec << " [secs]";
}