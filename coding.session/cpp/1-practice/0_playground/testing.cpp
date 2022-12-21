#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

int main(void) {
  std::string respond = "";
  int intFor{0}, intGender{0}, intAgeY{0}, intAgeM{0}, intWeight{0},
      intHeight{0};
  // int ageYear, ageMonths;
  double weightValue{0}, heightValue{0};
  std::array<std::string, 2> age{"2-19 yrs old", "20+ yrs old"};
  std::array<std::string, 2> gender{"Male", "Female"};
  std::array<std::string, 2> weight{"pounds", "kilograms"};
  std::array<std::string, 4> height{"feet", "inches", "centimeters", "meters"};

  std::cout << "Press Enter";
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int i;
    while (true) { // Age Range check
      system("CLS");
      i = 1;
      std::cout << "\tAGE RANGE\n";
      for (auto a : age)
        std::cout << "[" << i++ << "] " << a << "\n";

      std::cout << "\nBMI for: ";
      std::cin >> respond;
      std::transform(respond.begin(), respond.end(), respond.begin(),
                     ::tolower);
      if (respond == "exit")
        return 0;
      else {
        try {
          intFor = std::stoi(respond);
          age.at(--intFor);
        } catch (...) {
          continue;
        }
      }
      break;
    }

    if (age.at(intFor) == age.at(0)) {
      while (true) {
        system("CLS");
        i = 1;
        std::cout << "BMI For " << age.at(intFor);
        std::cout << "\n\n\tGENDER\n";
        for (auto a : gender)
          std::cout << "[" << i++ << "] " << a << "\n";

        std::cout << "Gender: ";
        std::cin >> respond;
        std::transform(respond.begin(), respond.end(), respond.begin(),
                       ::tolower);
        if (respond == "exit")
          return 0;
        else {
          try {
            intGender = std::stoi(respond);
            gender.at(--intGender);
          } catch (...) {
            continue;
          }
        }
        break;
      } // Gender

      while (true) {
        while (true) {
          system("CLS");
          std::cout << "BMI For " << age.at(intFor);
          std::cout << "\nGender: " << gender.at(intGender);
          std::cout << "\n\n\tAge: year + month\n";
          std::cout << "Year old: ";
          std::cin >> respond;
          std::transform(respond.begin(), respond.end(), respond.begin(),
                         ::tolower);
          if (respond == "exit")
            return 0;
          else {
            try {
              intAgeY = std::stoi(respond);
              if (intAgeY >= 2 && intAgeY <= 19)
                break;
              else {
                std::cout << "The age range is 2 - 19, and it can't be greater "
                             "than. \n\t(Press Enter)";
                std::cin.get();
                std::cin.get();
                continue;
              }
            } catch (...) {
              continue;
            }
          }
        } // Year old
        while (true) {
          system("CLS");
          std::cout << "BMI For " << age.at(intFor);
          std::cout << "\nGender: " << gender.at(intGender);
          std::cout << "\n\n\tAge: year + month";
          std::cout << "\nYear old: " << intAgeY;
          std::cout << "\nMonth old: ";
          std::cin >> respond;
          std::transform(respond.begin(), respond.end(), respond.begin(),
                         ::tolower);
          if (respond == "exit")
            return 0;
          else {
            try {
              intAgeM = std::stoi(respond);
              if (intAgeM >= 1 && intAgeM <= 12)
                break;
              if (intAgeM > 12) {
                std::cout << "It can't be greater than 12. "
                             "\n\nWant to re-enter the month? "
                             "otherwise the value wiil be 12.\n"
                             "(Enter 'Y' change | 'any' to set 12)\n>> ";
                std::cin >> respond;
                std::transform(respond.begin(), respond.end(), respond.begin(),
                               ::tolower);
                if (respond == "y") {
                  continue;
                } else {
                  intAgeM = 12;
                  break;
                }
              } else if (intAgeM < 1) {
                std::cout << "It can't be less than 1. "
                             "\n\nWant to re-enter the month? "
                             "otherwise the value wiil be 1.\n"
                             "(Enter 'Y' change | 'any' to set 1)\n>> ";
                std::cin >> respond;
                std::transform(respond.begin(), respond.end(), respond.begin(),
                               ::tolower);
                if (respond == "y") {
                  continue;
                } else {
                  intAgeM = 1;
                  break;
                }
              }
            } catch (...) {
              continue;
            }
          }
        } // Month old
        break;
      } // Yr old + Month old

      while (true) {
        i = 1;
        system("CLS");
        std::cout << "BMI For " << age.at(intFor);
        std::cout << "\nGender: " << gender.at(intGender);
        std::cout << "\nAge: " << intAgeY << " Year old & " << intAgeM
                  << " Month old\n\n";

        for (auto a : weight)
          std::cout << "[" << i++ << "] " << a << "\n";

        std::cout << "Weight: ";
        std::cin >> respond;
        std::transform(respond.begin(), respond.end(), respond.begin(),
                       ::tolower);
        if (respond == "exit")
          return 0;
        else {
          try {
            intWeight = std::stoi(respond);
            weight.at(--intWeight);
          } catch (...) {
            continue;
          }
        }
        std::cout << "Weight Value: ";
        std::cin >> respond;
        std::transform(respond.begin(), respond.end(), respond.begin(),
                       ::tolower);
        if (respond == "exit")
          return 0;
        else {
          try {
            weightValue = std::stod(respond);
          } catch (...) {
            continue;
          }
        }
        break;
      }

      while (true) {
        i = 1;
        for (auto a : height)
          std::cout << "[" << i++ << "] " << a << "\n";

        std::cout << "Height: ";
        std::cin >> respond;
        std::transform(respond.begin(), respond.end(), respond.begin(),
                       ::tolower);
        if (respond == "exit")
          return 0;
        else {
          try {
            intHeight = std::stoi(respond);
            height.at(--intHeight);
          } catch (...) {
            continue;
          }
        }
        break;
      }
    }
    if (age.at(intFor) == age.at(1)) {
      std::cout << "Hello world muna (Press Enter)";
      std::cin.get();
    }
  }
}