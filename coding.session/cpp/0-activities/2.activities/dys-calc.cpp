#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class Calc {
private:
  double time, distance, speed;

public:
  void setValues(double, double, double);

  void getTime();
  void getDistance();
  void getSpeed();
};

std::string respond;

int main(int argc, char const *argv[]) {
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

void Calc::setValues(double Time, double Distance, double Speed) {
  time = Time;
  distance = Distance;
  speed = Speed;
}

void Calc::getDistance() {
  std::cout << "Enter Speed (m/sec) : ";
  std::cin >> speed;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "ERROR: The input cannot be a string.\n";

    std::cout << "Enter Speed (m/sec) : ";
    std::cin >> speed;
  }

  std::cout << "\n\tEnter TIME\nseconds in 'default' you want to change?"
               "\n(Press 'Y' for yes | 'any' for no) : ";

  std::cin >> respond;
  if (respond == "Y" || respond == "y") {
    while (true) {
      std::cout << "\nAlright Press [H] for hour | [M] for minute : ";
      std::cin >> respond;

      if (respond == "H" || respond == "h") {
        std::cout << "Enter Time (hour) : ";
        std::cin >> time;

        while (std::cin.fail()) {
          std::cin.clear(); // clearning the buffer if there is a string input
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cerr << "ERROR: The input cannot be a string.\n";
          std::cout << "Enter Time (hour) : ";
          std::cin >> time;
        }

        time *= 3600;
        break;
      } else if (respond == "M" || respond == "m") {
        std::cout << "Enter Time (minute) : ";
        std::cin >> time;

        while (std::cin.fail()) {
          std::cin.clear(); // clearning the buffer if there is a string input
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cerr << "ERROR: The input cannot be a string.\n";
          std::cout << "Enter Time (hour) : ";
          std::cin >> time;
        }

        time *= 60;
        break;
      } else {
        std::cout << "Input does not match. Try again.\n\n";
        continue;
      }
    }
  } else {
    std::cout << "Enter Time (second) : ";
    std::cin >> time;

    while (std::cin.fail()) {
      std::cin.clear(); // clearning the buffer if there is a string input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "ERROR: The input cannot be a string.\n";
      std::cout << "Enter Time (hour) : ";
      std::cin >> time;
    }
  }
  std::cout << "Distance : " << speed * time << " meters.";
}

void Calc::getSpeed() {
  std::cout << "Enter Distance (meters) : ";
  std::cin >> distance;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "ERROR: The input cannot be a string.\n";
    std::cout << "Enter Distance (meters) : ";
    std::cin >> distance;
  }

  std::cout << "\n\tEnter TIME\nseconds in 'default' you want to change?"
               "\n(Press 'Y' for yes | 'any' for no) : ";

  std::cin >> respond;
  if (respond == "Y" || respond == "y") {
    while (true) {
      std::cout << "\nAlright Press [H] for hour | [M] for minute : ";
      std::cin >> respond;
      if (respond == "H" || respond == "h") {
        std::cout << "Enter Time (hour) : ";
        std::cin >> time;

        while (std::cin.fail()) {
          std::cin.clear(); // clearning the buffer if there is a string input
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cerr << "ERROR: The input cannot be a string.\n";
          std::cout << "Enter Time (hour) : ";
          std::cin >> time;
        }

        time *= 3600;
        break;
      } else if (respond == "M" || respond == "m") {
        std::cout << "Enter Time (minute) : ";
        std::cin >> time;

        while (std::cin.fail()) {
          std::cin.clear(); // clearning the buffer if there is a string input
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cerr << "ERROR: The input cannot be a string.\n";
          std::cout << "Enter Time (hour) : ";
          std::cin >> time;
        }

        time *= 60;
        break;
      } else {
        std::cout << "Input does not match. Try again.\n\n";
        continue;
      }
    }
  } else {
    std::cout << "Enter Time (second) : ";
    std::cin >> time;

    while (std::cin.fail()) {
      std::cin.clear(); // clearning the buffer if there is a string input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "ERROR: The input cannot be a string.\n";
      std::cout << "Enter Time (hour) : ";
      std::cin >> time;
    }
  }
  std::cout << "Speed : " << std::presic<<  distance / time << " m/sec";
}

void Calc::getTime() {
  std::cout << "Enter Distance (meters) : ";
  std::cin >> distance;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "ERROR: The input cannot be a string.\n";
    std::cout << "Enter Distance (meters) : ";
    std::cin >> distance;
  }

  std::cout << "Enter Speed (m/sec) : ";
  std::cin >> speed;

  while (std::cin.fail()) {
    std::cin.clear(); // clearning the buffer if there is a string input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "ERROR: The input cannot be a string.\n";
    std::cout << "Enter Distance (meters) : ";
    std::cin >> distance;
  }

  std::cout << "Time : " << distance / speed << " secs";
}