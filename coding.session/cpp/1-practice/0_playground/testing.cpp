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
  int intWeight{0}, intHeight{0};
  // int ageYear, ageMonths;
  double weightValue{0}, heightValue1{0}, heightValue2{0};
  std::array<std::string, 2> age{"2-19 yrs old", "20+ yrs old"};
  std::array<std::string, 2> gender{"Male", "Female"};
  std::array<std::string, 2> weight{"pounds", "kilograms"};
  std::array<std::string, 4> height{"feet", "inches", "centimeters", "meters"};

  std::cout << "Press Enter";
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int i;

    while (true) {
      while (true) {
        i = 1;
        system("CLS");
        std::cout << "\tWeight\n";

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
        break;
      } // Weight type
      while (true) {
        system("CLS");
        std::cout << "\tWeight";
        std::cout << "\nWeight (" << weight.at(intWeight) << ") "
                  << "\n";
        std::cout << "Weight Value: ";
        std::cin >> respond;
        std::transform(respond.begin(), respond.end(), respond.begin(),
                       ::tolower);
        if (respond == "exit")
          return 0;
        else {
          try {
            weightValue = std::stod(respond);
            if (weight.at(intWeight) == weight.at(0))
              weightValue /= 2.20462262;
          } catch (...) {
            continue;
          }
        }
        break;
      } // Weight Value
      break;
    } // Weight
    while (true) {
      while (true) {
        system("CLS");
        std::cout << "Weight: " << weightValue << " " << weight.at(1);
        std::cout << "\n\n\tHeight\n";

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
      } // Height type
      while (true) {
        system("CLS");
        std::cout << "\nWeight: " << weightValue << " " << weight.at(1);
        std::cout << "\n\n\tHeight\n";
        std::cout << "Height (" << height.at(intHeight) << ") ";

        if (height.at(intHeight) == height.at(0)) { // ft and in
          while (true) {
            system("CLS");
            std::cout << "\nWeight: " << weightValue << " " << weight.at(1);
            std::cout << "\nHeight (" << height.at(intHeight) << ")";
            std::cout << "\nHeight Value (ft): ";
            std::cin >> respond;
            std::transform(respond.begin(), respond.end(), respond.begin(),
                           ::tolower);
            if (respond == "exit")
              return 0;
            else {
              try {
                heightValue1 = stod(respond);
                heightValue1 /= 3.2808399;
              } catch (...) {
                continue;
              }
            }
            break;
          } // feet value
          while (true) {
            system("CLS");
            std::cout << "\nWeight: " << weightValue << " " << weight.at(1);
            std::cout << "\nHeight (" << height.at(intHeight) << ") ";
            std::cout << "\nHeight Value (ft): " << heightValue1;
            std::cout << "\nHeight Value (in): ";
            std::cin >> respond;
            std::transform(respond.begin(), respond.end(), respond.begin(),
                           ::tolower);
            if (respond == "exit")
              return 0;
            else {
              try {
                heightValue2 = stod(respond);
                if (heightValue2 < 1 || heightValue2 > 12) {
                  std::cerr << "Must be between 1 and 12 (Press Enter)";
                  std::cin.get();
                  std::cin.get();
                  continue;
                }
                heightValue1 += heightValue2 /= 39.3700787;
              } catch (...) {
                continue;
              }
            }
            break;
          } // inches value | foot and inches
        } else if (height.at(intHeight) == height.at(1)) { // in
          while (true) {
            system("CLS");
            std::cout << "\nWeight: " << weightValue << " " << weight.at(1);
            std::cout << "\nHeight (" << height.at(intHeight) << ")";
            std::cout << "\nHeight Value (in): ";
            std::cin >> respond;
            std::transform(respond.begin(), respond.end(), respond.begin(),
                           ::tolower);
            if (respond == "exit")
              return 0;
            else {
              try {
                heightValue1 = stod(respond);
                heightValue1 /= 39.3700787;
              } catch (...) {
                continue;
              }
            }
            break;
          }                                                // inches
        } else if (height.at(intHeight) == height.at(2)) { // cm
          while (true) {
            system("CLS");
            std::cout << "\nWeight: " << weightValue << " " << weight.at(1);
            std::cout << "\nHeight (" << height.at(intHeight) << ")";
            std::cout << "\nHeight Value (cm): ";
            std::cin >> respond;
            std::transform(respond.begin(), respond.end(), respond.begin(),
                           ::tolower);
            if (respond == "exit")
              return 0;
            else {
              try {
                heightValue1 = stod(respond);
                heightValue1 /= 100;
              } catch (...) {
                continue;
              }
            }
            break;
          }                                                // cm
        } else if (height.at(intHeight) == height.at(3)) { // meters
          while (true) {
            system("CLS");
            std::cout << "\nWeight: " << weightValue << " " << weight.at(1);
            std::cout << "\nHeight (" << height.at(intHeight) << ")";
            std::cout << "\nHeight Value (cm): ";
            std::cin >> respond;
            std::transform(respond.begin(), respond.end(), respond.begin(),
                           ::tolower);
            if (respond == "exit")
              return 0;
            else {
              try {
                heightValue1 = stod(respond);
              } catch (...) {
                continue;
              }
            }
            break;
          } // m
        }
        break;
      } // height value
      break;
    } // Height
    // BMI = weight in kg / height in meters
    system("CLS");
    std::cout << "\nWeight: " << weightValue << " " << weight.at(1);
    std::cout << "\nHeight: " << heightValue1 << " " << height.at(3);
    std::cout << "\nBMI: " << (weightValue / ((heightValue1)*2));
    std::cin.get();
  }
}