#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#include "_class.hpp"

inline void mainMenu();

std::string strRespond1, strRespond2;
unsigned short i;

int main(void) {

#if 0
  mainMenu();
#elif 1
  Data data;
  data._data();
#else
  Area area;
  area._area();
#endif
  return 0;
}

// Acting like a main func
inline void mainMenu() {

  short unsigned int intRespond;
  std::array<std::string, 12> choice{"Simple Calculator",
                                     "Area",
                                     "BMI",
                                     "Data [ONG]",
                                     "Discount [ONG]",
                                     "Length [ONG]",
                                     "Mass [ONG]",
                                     "Numerical System [ONG]",
                                     "Speed [ONG]",
                                     "Temperature [ONG]",
                                     "Time [ONG]",
                                     "Volume [ONG]"};
  do {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
      system("CLS");
      std::cerr << "\nERROR: String input. (Press Enter)";
      std::cin.get();
    }

    system("CLS");
    std::cout << "\tCommands:"
                 "\n'e' to exit program.";
    std::cout << "\n\n\tCALCULATOR / CONVERTOR\n";
    i = 1;
    for (auto a : choice)
      std::cout << "[" << i++ << "] " << a << "\n";

    std::cout << "\nType a number to enter one of the calculator: ";
    std::cin >> strRespond1;
    if (strRespond1 == "e")
      return;
    try {
      intRespond = stoi(strRespond1);
    } catch (...) {
      continue;
    }

    if (intRespond < 1 || intRespond > 12) {
      system("CLS");
      std::cerr << "\nERROR: Out of range. (Press Enter)";
      std::cin.get();
      std::cin.get();
      system("CLS");
      continue;
    } else
      break;
  } while (true);

  Calc::SimpleCalc simplecalc;
  Area area;
  Calc::BMI bmi;
  Data data;

  switch (intRespond) {
  case 1:
    simplecalc._simple_calc();
    break;
  case 2:
    area._area();
    break;
  case 3:
    bmi._bmi();
    break;
  case 4:
    data._data();
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 11:
    break;
  case 12:
    break;
  }
}

inline void Calc::SimpleCalc::_simple_calc() {
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("CLS");
    std::cout << "\tCommands:"
                 "\n'e' Back to main menu"
                 "\n\n\tAvailable Operators:"
                 "\n'+' Addition"
                 "\n'-' Subtraction"
                 "\n'*' Multiplication"
                 "\n'/' Division"
                 "\n'%' Modulo";

    if (op == '+' || op == '-' || op == '*' || op == '/')
      std::cout << "\n\nLast result: " << t_num;
    if (op == '%')
      std::cout << "\n\nLast result: " << m_num;

    std::cout << "\n\n\t[Ex. Format: 1 + 2]\n>> ";
    std::cin >> strRespond1;
    std::transform(strRespond1.begin(), strRespond1.end(), strRespond1.begin(),
                   ::tolower);
    if (strRespond1 == "e")
      return mainMenu();

    std::cin >> op;
    std::tolower(op);
    if (op == 'e')
      return mainMenu();

    std::cin >> strRespond1;
    std::transform(strRespond1.begin(), strRespond1.end(), strRespond1.begin(),
                   ::tolower);
    if (strRespond2 == "e")
      return mainMenu();

    try {
      num1 = stold(strRespond1);
      num2 = stold(strRespond2);
    } catch (...) {
      continue;
    }

    switch (op) {
    case '+':
      t_num = num1 + num2;
      break;
    case '-':
      t_num = num1 - num2;
      break;
    case '*':
      t_num = num1 * num2;
      break;
    case '/':
      t_num = num1 / num2;
      break;
    case '%':
      m_num1 = num1;
      m_num2 = num2;
      m_num = m_num1 % m_num2;
      break;
    default:
      continue;
      break;
    }
  }
}

inline void Calc::BMI::_bmi() {
  weight = {"pounds", "kilograms"};
  height = {"feet", "inches", "centimeters", "meters"};

  std::cout << "Press Enter";
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {
      while (true) {
        i = 1;
        system("CLS");
        std::cout << "\tCommands:"
                     "\n'e' Back to main menu"
                     "\n\n\tWeight\n";

        for (auto a : weight)
          std::cout << "[" << i++ << "] " << a << "\n";

        std::cout << "Weight: ";
        std::cin >> strRespond1;
        std::transform(strRespond1.begin(), strRespond1.end(),
                       strRespond1.begin(), ::tolower);
        if (strRespond1 == "e")
          return mainMenu();
        else {
          try {
            intWeight = std::stoi(strRespond1);
            weight.at(--intWeight);
          } catch (...) {
            continue;
          }
        }
        break;
      } // Weight type
      while (true) {
        system("CLS");
        std::cout << "\tCommands:"
                     "\n'e' Back to main menu"
                     "\n\n\tWeight";
        std::cout << "\nWeight (" << weight.at(intWeight) << ") "
                  << "\n";
        std::cout << "Weight Value: ";
        std::cin >> strRespond1;
        std::transform(strRespond1.begin(), strRespond1.end(),
                       strRespond1.begin(), ::tolower);
        if (strRespond1 == "e")
          return mainMenu();
        else {
          try {
            weightValue = std::stod(strRespond1);
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
        std::cout << "\tCommands:\n'e' Back to main menu"
                     "\n\nWeight: "
                  << weightValue << " " << weight.at(1) << "\n\n\tHeight\n";

        i = 1;
        for (auto a : height)
          std::cout << "[" << i++ << "] " << a << "\n";

        std::cout << "Height: ";
        std::cin >> strRespond1;
        std::transform(strRespond1.begin(), strRespond1.end(),
                       strRespond1.begin(), ::tolower);
        if (strRespond1 == "e")
          return mainMenu();
        else {
          try {
            intHeight = std::stoi(strRespond1);
            height.at(--intHeight);
          } catch (...) {
            continue;
          }
        }
        break;
      } // Height type
      while (true) {
        system("CLS");
        std::cout << "\tCommands:\n'e' Back to main menu"
                     "\n\nWeight: "
                  << weightValue << " " << weight.at(1) << "\n\n\tHeight:";
        std::cout << "\nHeight (" << height.at(intHeight) << ") ";

        if (height.at(intHeight) == height.at(0)) { // ft and in
          while (true) {
            system("CLS");
            std::cout << "\tCommands:\n'e' Back to main menu"
                         "\nWeight: "
                      << weightValue << " " << weight.at(1)
                      << "\n\n\tHeight: " << height.at(intHeight);
            std::cout << "\nHeight Value (ft): ";
            std::cin >> strRespond1;
            std::transform(strRespond1.begin(), strRespond1.end(),
                           strRespond1.begin(), ::tolower);
            if (strRespond1 == "e")
              return mainMenu();
            else {
              try {
                heightValue1 = stod(strRespond1);
                heightValue1 /= 3.2808399;
              } catch (...) {
                continue;
              }
            }
            break;
          } // feet value
          while (true) {
            system("CLS");
            std::cout << "\tCommands:\n'e' Back to main menu"
                         "\nWeight: "
                      << weightValue << " " << weight.at(1)
                      << "\n\n\tHeight: " << height.at(intHeight);
            std::cout << "\nHeight Value (ft) - " << heightValue1 << " "
                      << height.at(3);
            std::cout << "\nHeight Value (in): ";
            std::cin >> strRespond1;
            std::transform(strRespond1.begin(), strRespond1.end(),
                           strRespond1.begin(), ::tolower);
            if (strRespond1 == "e")
              return mainMenu();
            else {
              try {
                heightValue2 = stod(strRespond1);
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
            std::cout << "\tCommands:\n'e' Back to main menu"
                         "\nWeight: "
                      << weightValue << " " << weight.at(1)
                      << "\n\n\tHeight: " << height.at(intHeight);
            std::cout << "\nHeight Value (in): ";
            std::cin >> strRespond1;
            std::transform(strRespond1.begin(), strRespond1.end(),
                           strRespond1.begin(), ::tolower);
            if (strRespond1 == "e")
              return mainMenu();
            else {
              try {
                heightValue1 = stod(strRespond1);
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
            std::cout << "\tCommands:\n'e' Back to main menu"
                         "\nWeight: "
                      << weightValue << " " << weight.at(1)
                      << "\n\n\tHeight: " << height.at(intHeight);
            std::cout << "\nHeight Value (cm): ";
            std::cin >> strRespond1;
            std::transform(strRespond1.begin(), strRespond1.end(),
                           strRespond1.begin(), ::tolower);
            if (strRespond1 == "e")
              return mainMenu();
            else {
              try {
                heightValue1 = stod(strRespond1);
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
            std::cout << "\tCommands:\n'e' Back to main menu"
                         "\nWeight: "
                      << weightValue << " " << weight.at(1)
                      << "\n\n\tHeight: " << height.at(intHeight);
            std::cout << "\nHeight Value (m): ";
            std::cin >> strRespond1;
            std::transform(strRespond1.begin(), strRespond1.end(),
                           strRespond1.begin(), ::tolower);
            if (strRespond1 == "e")
              return mainMenu();
            else {
              try {
                heightValue1 = stod(strRespond1);
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
    // BMI = weight in kg / height ^ 2 in meters
    system("CLS");
    std::cout << "\nWeight: " << weightValue << " " << weight.at(1);
    std::cout << "\nHeight: " << heightValue1 << " " << height.at(3);

    ((weightValue / (heightValue1 * heightValue1)) <= 18.4)
        ? std::cout << "\nBMI: "
                    << (weightValue / (heightValue1 * heightValue1))
                    << " (Underweight)"
    : ((weightValue / (heightValue1 * heightValue1)) >= 18.5 &&
       (weightValue / (heightValue1 * heightValue1)) <= 24.9)
        ? std::cout << "\nBMI: "
                    << (weightValue / (heightValue1 * heightValue1))
                    << " (Normal)"
    : ((weightValue / (heightValue1 * heightValue1)) >= 25.0 &&
       (weightValue / (heightValue1 * heightValue1)) <= 39.9)
        ? std::cout << "\nBMI: "
                    << (weightValue / (heightValue1 * heightValue1))
                    << " (Overweight)"
    : ((weightValue / (heightValue1 * heightValue1)) >= 40.0)
        ? std::cout << "\nBMI: "
                    << (weightValue / (heightValue1 * heightValue1))
                    << " (Obese)"
        : std::cout << "\nBMI: "
                    << (weightValue / (heightValue1 * heightValue1))
                    << " (ERROR!)";

    std::cout << "\n(Press enter to continue.)";
    std::cin.get();
  }
}

inline void Area::_area() {
  unit = {"Square inch (in)",
          "Square foot (ft)",
          "Square yard (yd)",
          "Square mile (mi)",
          "acre (ac)",
          "hectare (ha)",
          "Square millimeter (mm)",
          "Square centimeter (cm)",
          "Square meter (m)",
          "Square kilometer (km)"};
  std::cout << "Press enter.";
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    i = 1;
    system("CLS");
    std::cout << "\tCommands:"
                 "\n'e' Back to main menu\n\n";

    for (auto a : unit)
      std::cout << "[" << i++ << "] " << a << "\n";

    std::cout << "\nFrom: ";
    std::cin >> strRespond1;
    std::transform(strRespond1.begin(), strRespond1.end(), strRespond1.begin(),
                   ::tolower);
    if (strRespond1 == "e")
      return mainMenu();
    else {
      try {
        intRespond1 = stoi(strRespond1);
      } catch (...) {
        continue;
      }
    }
    if (intRespond1 < 1 || intRespond1 > 10)
      continue;

    std::cout << "To: ";
    std::cin >> strRespond1;
    std::transform(strRespond1.begin(), strRespond1.end(), strRespond1.begin(),
                   ::tolower);
    if (strRespond1 == "e")
      return mainMenu();
    else {
      try {
        intRespond2 = stoi(strRespond1);
      } catch (...) {
        continue;
      }
    }

    if (intRespond2 < 1 || intRespond2 > 10)
      continue;

    std::cout << "Value to Convert: ";
    std::cin >> strRespond1;
    std::transform(strRespond1.begin(), strRespond1.end(), strRespond1.begin(),
                   ::tolower);
    if (strRespond1 == "e")
      return mainMenu();
    else {
      try {
        value = stold(strRespond1);
      } catch (...) {
        continue;
      }
    }

    result =                                                              // -in
        (intRespond1 == 1 && intRespond2 == 1)    ? value * 1             // in
        : (intRespond1 == 1 && intRespond2 == 2)  ? value / 144           // ft
        : (intRespond1 == 1 && intRespond2 == 3)  ? value / 1296          // yd
        : (intRespond1 == 1 && intRespond2 == 4)  ? value / 4014000000    // mi
        : (intRespond1 == 1 && intRespond2 == 5)  ? value / 6273000       // ac
        : (intRespond1 == 1 && intRespond2 == 6)  ? value / 15500000      // ha
        : (intRespond1 == 1 && intRespond2 == 7)  ? value * 645.2         // mm
        : (intRespond1 == 1 && intRespond2 == 8)  ? value * 6.452         // cm
        : (intRespond1 == 1 && intRespond2 == 9)  ? value / 1550          // m
        : (intRespond1 == 1 && intRespond2 == 10) ? value / 1550000000    // km
                                                                          // -ft
        : (intRespond1 == 2 && intRespond2 == 1)  ? value * 144           // in
        : (intRespond1 == 2 && intRespond2 == 2)  ? value * 1             // ft
        : (intRespond1 == 2 && intRespond2 == 3)  ? value / 9             // yd
        : (intRespond1 == 2 && intRespond2 == 4)  ? value / 27880000      // mi
        : (intRespond1 == 2 && intRespond2 == 5)  ? value / 43560         // ac
        : (intRespond1 == 2 && intRespond2 == 6)  ? value / 107600        // ha
        : (intRespond1 == 2 && intRespond2 == 7)  ? value * 92900         // mm
        : (intRespond1 == 2 && intRespond2 == 8)  ? value * 929           // cm
        : (intRespond1 == 2 && intRespond2 == 9)  ? value / 10.76         // m
        : (intRespond1 == 2 && intRespond2 == 10) ? value / 10760000      // km
                                                                          // -yd
        : (intRespond1 == 3 && intRespond2 == 1)  ? value * 1296          // in
        : (intRespond1 == 3 && intRespond2 == 2)  ? value * 9             // ft
        : (intRespond1 == 3 && intRespond2 == 3)  ? value * 1             // yd
        : (intRespond1 == 3 && intRespond2 == 4)  ? value / 3098000       // mi
        : (intRespond1 == 3 && intRespond2 == 5)  ? value / 4840          // ac
        : (intRespond1 == 3 && intRespond2 == 6)  ? value / 11960         // ha
        : (intRespond1 == 3 && intRespond2 == 7)  ? value * 836100        // mm
        : (intRespond1 == 3 && intRespond2 == 8)  ? value * 8361          // cn
        : (intRespond1 == 3 && intRespond2 == 9)  ? value * 1.196         // m
        : (intRespond1 == 3 && intRespond2 == 10) ? value / 1196000       // km
                                                                          // -mi
        : (intRespond1 == 4 && intRespond2 == 1)  ? value * 4014000000    // in
        : (intRespond1 == 4 && intRespond2 == 2)  ? value * 27880000      // ft
        : (intRespond1 == 4 && intRespond2 == 3)  ? value * 3098000       // yd
        : (intRespond1 == 4 && intRespond2 == 4)  ? value * 1             // mi
        : (intRespond1 == 4 && intRespond2 == 5)  ? value * 640           // ac
        : (intRespond1 == 4 && intRespond2 == 6)  ? value * 259           // ha
        : (intRespond1 == 4 && intRespond2 == 7)  ? value * 2590000000000 // mm
        : (intRespond1 == 4 && intRespond2 == 8)  ? value * 25900000000   // cm
        : (intRespond1 == 4 && intRespond2 == 9)  ? value * 2590000       // m
        : (intRespond1 == 4 && intRespond2 == 10) ? value * 2.59          // km
                                                                          // -ac
        : (intRespond1 == 5 && intRespond2 == 1)  ? value * 6273000       // in
        : (intRespond1 == 5 && intRespond2 == 2)  ? value * 43560         // ft
        : (intRespond1 == 5 && intRespond2 == 3)  ? value * 4840          // yd
        : (intRespond1 == 5 && intRespond2 == 4)  ? value / 640           // mi
        : (intRespond1 == 5 && intRespond2 == 5)  ? value * 1             // ac
        : (intRespond1 == 5 && intRespond2 == 6)  ? value / 2.471         // ha
        : (intRespond1 == 5 && intRespond2 == 7)  ? value * 4047000000    // mm
        : (intRespond1 == 5 && intRespond2 == 8)  ? value * 40470000      // cm
        : (intRespond1 == 5 && intRespond2 == 9)  ? value * 4047          // m
        : (intRespond1 == 5 && intRespond2 == 10) ? value * 247.1         // km
                                                                          // -ha
        : (intRespond1 == 6 && intRespond2 == 1)  ? value * 15500000      // in
        : (intRespond1 == 6 && intRespond2 == 2)  ? value * 107600        // ft
        : (intRespond1 == 6 && intRespond2 == 3)  ? value * 11960         // yd
        : (intRespond1 == 6 && intRespond2 == 4)  ? value / 259           // mi
        : (intRespond1 == 6 && intRespond2 == 5)  ? value * 2.471         // ac
        : (intRespond1 == 6 && intRespond2 == 6)  ? value * 1             // ha
        : (intRespond1 == 6 && intRespond2 == 7)  ? value * 10000000000   // mm
        : (intRespond1 == 6 && intRespond2 == 8)  ? value * 100000000     // cm
        : (intRespond1 == 6 && intRespond2 == 9)  ? value * 10000         // m
        : (intRespond1 == 6 && intRespond2 == 10) ? value / 100           // km
                                                                          // -mm
        : (intRespond1 == 7 && intRespond2 == 1)  ? value / 645.2         // in
        : (intRespond1 == 7 && intRespond2 == 2)  ? value / 92900         // ft
        : (intRespond1 == 7 && intRespond2 == 3)  ? value / 836100        // yd
        : (intRespond1 == 7 && intRespond2 == 4)  ? value / 2590000000000 // mi
        : (intRespond1 == 7 && intRespond2 == 5)  ? value / 4047000000    // ac
        : (intRespond1 == 7 && intRespond2 == 6)  ? value / 10000000000   // ha
        : (intRespond1 == 7 && intRespond2 == 7)  ? value * 1             // mm
        : (intRespond1 == 7 && intRespond2 == 8)  ? value / 100           // cm
        : (intRespond1 == 7 && intRespond2 == 9)  ? value / 1000000       // m
        : (intRespond1 == 7 && intRespond2 == 10) ? value / 1000000000000 // km
                                                                          // -cm
        : (intRespond1 == 8 && intRespond2 == 1)  ? value / 6.452         // in
        : (intRespond1 == 8 && intRespond2 == 2)  ? value / 929           // ft
        : (intRespond1 == 8 && intRespond2 == 3)  ? value / 8361          // yd
        : (intRespond1 == 8 && intRespond2 == 4)  ? value / 25900000000   // mi
        : (intRespond1 == 8 && intRespond2 == 5)  ? value / 40470000      // ac
        : (intRespond1 == 8 && intRespond2 == 6)  ? value / 100000000     // ha
        : (intRespond1 == 8 && intRespond2 == 7)  ? value * 100           // mm
        : (intRespond1 == 8 && intRespond2 == 8)  ? value * 1             // cm
        : (intRespond1 == 8 && intRespond2 == 9)  ? value / 10000         // m
        : (intRespond1 == 8 && intRespond2 == 10) ? value / 10000000000   // km
                                                                          // -m
        : (intRespond1 == 9 && intRespond2 == 1)  ? value * 1550          // in
        : (intRespond1 == 9 && intRespond2 == 2)  ? value * 10.76         // ft
        : (intRespond1 == 9 && intRespond2 == 3)  ? value * 1.196         // yd
        : (intRespond1 == 9 && intRespond2 == 4)  ? value / 2590000       // mi
        : (intRespond1 == 9 && intRespond2 == 5)  ? value / 4047          // ac
        : (intRespond1 == 9 && intRespond2 == 6)  ? value / 10000         // ha
        : (intRespond1 == 9 && intRespond2 == 7)  ? value * 1000000       // mm
        : (intRespond1 == 9 && intRespond2 == 8)  ? value * 10000         // cm
        : (intRespond1 == 9 && intRespond2 == 9)  ? value * 1             // m
        : (intRespond1 == 9 && intRespond2 == 10) ? value / 1000000       // km
                                                                          // -km
        : (intRespond1 == 10 && intRespond2 == 1)  ? value * 1550000000   // in
        : (intRespond1 == 10 && intRespond2 == 2)  ? value * 10760000     // ft
        : (intRespond1 == 10 && intRespond2 == 3)  ? value * 1196000      // yd
        : (intRespond1 == 10 && intRespond2 == 4)  ? value / 2.59         // mi
        : (intRespond1 == 10 && intRespond2 == 5)  ? value * 247.1        // ac
        : (intRespond1 == 10 && intRespond2 == 6)  ? value * 100          // ha
        : (intRespond1 == 10 && intRespond2 == 7)  ? value * 1000000000000 // mm
        : (intRespond1 == 10 && intRespond2 == 8)  ? value * 10000000000   // cm
        : (intRespond1 == 10 && intRespond2 == 9)  ? value * 1000000       // m
        : (intRespond1 == 10 && intRespond2 == 10) ? value * 1             // km
                                                   : value *= 0;

    std::cout << "\nResult: " << result << " " << unit.at(--intRespond2)
              << "\n\n(Press Enter to continue)";
    std::cin.get();
  }
}

inline void Data::_data() {
  unit = {"Bit (b)",       "Kilobit (kb)",   "Megabit (Mb)",  "Gigabit (Gb)",
          "Terabit (Tb)",  "Petabit (Pb)",   "Exabit (Eb)",   "Zettabit (Zb)",
          "Yottabit (Yb)", "Nibble ()",      "Byte (B)",      "Kilobyte (kB)",
          "Megabyte (MB)", "Gigabyte (GB)",  "Terabyte (TB)", "Petabyte (PB)",
          "Exabyte (EB)",  "Zettabyte (ZB)", "Yottabyte (YB)"};
  std::cout << "Press enter.";
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    i = 1;
    system("CLS");
    std::cout << "\tCommands:"
                 "\n'e' Back to main menu\n\n";
    for (auto a : unit)
      std::cout << "[" << i++ << "] " << a << "\n";

    std::cout << "\nFrom: ";
    std::cin >> strRespond1;
    std::transform(strRespond1.begin(), strRespond1.end(), strRespond1.begin(),
                   ::tolower);
    if (strRespond1 == "e")
      return mainMenu();
    else {
      try {
        intRespond1 = std::stoi(strRespond1);
      } catch (...) {
        continue;
      }
    }
    if (intRespond1 < 1 || intRespond1 > 19)
      continue;

    std::cout << "To: ";
    std::cin >> strRespond1;
    std::transform(strRespond1.begin(), strRespond1.end(), strRespond1.begin(),
                   ::tolower);
    if (strRespond1 == "e")
      return mainMenu();
    else {
      try {
        intRespond2 = std::stoi(strRespond1);
      } catch (...) {
        continue;
      }
    }
    if (intRespond2 < 1 || intRespond2 > 19)
      continue;

    std::cout << "Value to Convert: ";
    std::cin >> strRespond1;
    std::transform(strRespond1.begin(), strRespond1.end(), strRespond1.begin(),
                   ::tolower);
    if (strRespond1 == "e")
      return mainMenu();
    else {
      try {
        value = std::stoi(strRespond1);
      } catch (...) {
        continue;
      }
    }

    // "Bit (b)",         1
    // "Kilobit (kb)",    2
    // "Megabit (Mb)",    3
    // "Gigabit (Gb)",    4
    // "Terabit (Tb)",    5
    // "Petabit (Pb)",    6
    // "Exabit (Eb)",     7
    // "Zettabit (Zb)",   8
    // "Yottabit (Yb)",   9
    // "Nibble ()",       10
    // "Byte (B)",        11
    // "Kilobyte (kB)",   12
    // "Megabyte (MB)",   13
    // "Gigabyte (GB)",   14
    // "Terabyte (TB)",   15
    // "Petabyte (PB)",   16
    // "Exabyte (EB)",    17
    // "Zettabyte (ZB)",  18
    // "Yottabyte (YB)"   19

    result = (intRespond1 == 1 && intRespond2 == 1)    ? value * 1
             : (intRespond1 == 1 && intRespond2 == 2)  ? value / 1000
             : (intRespond1 == 1 && intRespond2 == 3)  ? value / 1000000
             : (intRespond1 == 1 && intRespond2 == 4)  ? value / 1.0000e+9
             : (intRespond1 == 1 && intRespond2 == 5)  ? value / 1.0000e+12
             : (intRespond1 == 1 && intRespond2 == 6)  ? value / 1.0000e+15
             : (intRespond1 == 1 && intRespond2 == 7)  ? value / 1.0000e+18
             : (intRespond1 == 1 && intRespond2 == 8)  ? value / 1.0000e+21
             : (intRespond1 == 1 && intRespond2 == 9)  ? value / 1.0000e+24
             : (intRespond1 == 1 && intRespond2 == 10) ? value / 4
             : (intRespond1 == 1 && intRespond2 == 11) ? value / 8
             : (intRespond1 == 1 && intRespond2 == 12) ? value / 8000
             : (intRespond1 == 1 && intRespond2 == 13) ? value / 8000000
             : (intRespond1 == 1 && intRespond2 == 14) ? value / 8.0000e+9
             : (intRespond1 == 1 && intRespond2 == 15) ? value / 8.0000e+12
             : (intRespond1 == 1 && intRespond2 == 16) ? value / 8.0000e+15
             : (intRespond1 == 1 && intRespond2 == 17) ? value / 8.0000e+18
             : (intRespond1 == 1 && intRespond2 == 18) ? value / 8.0000e+21
             : (intRespond1 == 1 && intRespond2 == 19) ? value / 8.0000e+24
             : (intRespond1 == 2 && intRespond2 == 1)  ? value * 1000
             : (intRespond1 == 2 && intRespond2 == 2)  ? value * 1
             : (intRespond1 == 2 && intRespond2 == 3)  ? value / 1000
             : (intRespond1 == 2 && intRespond2 == 4)  ? value / 1000000
             : (intRespond1 == 2 && intRespond2 == 5)  ? value / 1.0000e+9
             : (intRespond1 == 2 && intRespond2 == 6)  ? value / 1.0000e+12
             : (intRespond1 == 2 && intRespond2 == 7)  ? value / 1.0000e+15
             : (intRespond1 == 2 && intRespond2 == 8)  ? value / 1.0000e+18
             : (intRespond1 == 2 && intRespond2 == 9)  ? value / 1.0000e+21
             : (intRespond1 == 2 && intRespond2 == 10) ? value * 250
             : (intRespond1 == 2 && intRespond2 == 11) ? value * 125
             : (intRespond1 == 2 && intRespond2 == 12) ? value / 8
             : (intRespond1 == 2 && intRespond2 == 13) ? value / 8000
             : (intRespond1 == 2 && intRespond2 == 14) ? value / 8000000
             : (intRespond1 == 2 && intRespond2 == 15) ? value / 8.0000e+9
             : (intRespond1 == 2 && intRespond2 == 16) ? value / 8.0000e+12
             : (intRespond1 == 2 && intRespond2 == 17) ? value / 8.0000e+15
             : (intRespond1 == 2 && intRespond2 == 18) ? value / 8.0000e+18
             : (intRespond1 == 2 && intRespond2 == 19) ? value / 8.0000e+21
             : (intRespond1 == 3 && intRespond2 == 1)  ? value * 1000000
             : (intRespond1 == 3 && intRespond2 == 2)  ? value * 1000
             : (intRespond1 == 3 && intRespond2 == 3)  ? value * 1
             : (intRespond1 == 3 && intRespond2 == 4)  ? value / 1000
             : (intRespond1 == 3 && intRespond2 == 5)  ? value / 1000000
             : (intRespond1 == 3 && intRespond2 == 6)  ? value / 1.0000E+9
             : (intRespond1 == 3 && intRespond2 == 7)  ? value / 1.0000E+12
             : (intRespond1 == 3 && intRespond2 == 8)  ? value / 1.0000E+15
             : (intRespond1 == 3 && intRespond2 == 9)  ? value / 1.0000E+18
             : (intRespond1 == 3 && intRespond2 == 10) ? value * 250000
             : (intRespond1 == 3 && intRespond2 == 11) ? value * 125000
             : (intRespond1 == 3 && intRespond2 == 12) ? value * 125
             : (intRespond1 == 3 && intRespond2 == 13) ? value / 8
             : (intRespond1 == 3 && intRespond2 == 14) ? value / 8000
             : (intRespond1 == 3 && intRespond2 == 15) ? value / 8000000
             : (intRespond1 == 3 && intRespond2 == 16) ? value / 8.0000E+9
             : (intRespond1 == 3 && intRespond2 == 17) ? value / 8.0000E+12
             : (intRespond1 == 3 && intRespond2 == 18) ? value / 8.0000E+15
             : (intRespond1 == 3 && intRespond2 == 19) ? value / 8.0000E+18
             : (intRespond1 == 4 && intRespond2 == 1)  ? value * 1.0000E+9
             : (intRespond1 == 4 && intRespond2 == 2)  ? value * 1000000
             : (intRespond1 == 4 && intRespond2 == 3)  ? value * 1000
             : (intRespond1 == 4 && intRespond2 == 4)  ? value * 1
             : (intRespond1 == 4 && intRespond2 == 5)  ? value / 1000
             : (intRespond1 == 4 && intRespond2 == 6)  ? value / 1000000
             : (intRespond1 == 4 && intRespond2 == 7)  ? value / 1.0000E+9
             : (intRespond1 == 4 && intRespond2 == 8)  ? value / 1.0000E+12
             : (intRespond1 == 4 && intRespond2 == 9)  ? value / 1.0000E+15
             : (intRespond1 == 4 && intRespond2 == 10) ? value * 250000000
             : (intRespond1 == 4 && intRespond2 == 11) ? value * 125000000
             : (intRespond1 == 4 && intRespond2 == 12) ? value * 125000
             : (intRespond1 == 4 && intRespond2 == 13) ? value * 125
             : (intRespond1 == 4 && intRespond2 == 14) ? value / 8
             : (intRespond1 == 4 && intRespond2 == 15) ? value / 8000
             : (intRespond1 == 4 && intRespond2 == 16) ? value / 8000000
             : (intRespond1 == 4 && intRespond2 == 17) ? value / 8.0000E+9
             : (intRespond1 == 4 && intRespond2 == 18) ? value / 8.0000E+12
             : (intRespond1 == 4 && intRespond2 == 19) ? value / 8.0000E+15
             : (intRespond1 == 5 && intRespond2 == 1)  ? value * 1.0000E+12
             : (intRespond1 == 5 && intRespond2 == 2)  ? value * 1.0000E+9
             : (intRespond1 == 5 && intRespond2 == 3)  ? value * 1000000
             : (intRespond1 == 5 && intRespond2 == 4)  ? value * 1000
             : (intRespond1 == 5 && intRespond2 == 5)  ? value * 1
             : (intRespond1 == 5 && intRespond2 == 6)  ? value / 1000
             : (intRespond1 == 5 && intRespond2 == 7)  ? value / 1000000
             : (intRespond1 == 5 && intRespond2 == 8)  ? value / 1.0000E+9
             : (intRespond1 == 5 && intRespond2 == 9)  ? value / 1.0000E+12
             : (intRespond1 == 5 && intRespond2 == 10) ? value * 2.5000E+11
             : (intRespond1 == 5 && intRespond2 == 11) ? value * 1.2500E+11
             : (intRespond1 == 5 && intRespond2 == 12) ? value * 125000000
             : (intRespond1 == 5 && intRespond2 == 13) ? value * 125000
             : (intRespond1 == 5 && intRespond2 == 14) ? value * 125
             : (intRespond1 == 5 && intRespond2 == 15) ? value / 8
             : (intRespond1 == 5 && intRespond2 == 16) ? value / 8000
             : (intRespond1 == 5 && intRespond2 == 17) ? value / 8000000
             : (intRespond1 == 5 && intRespond2 == 18) ? value / 8.0000E+9
             : (intRespond1 == 5 && intRespond2 == 19) ? value / 8.0000E+12
             : (intRespond1 == 6 && intRespond2 == 1)  ? value * 1.0000E+15
             : (intRespond1 == 6 && intRespond2 == 2)  ? value * 1.0000E+12
             : (intRespond1 == 6 && intRespond2 == 3)  ? value * 1.0000E+9
             : (intRespond1 == 6 && intRespond2 == 4)  ? value * 1000000
             : (intRespond1 == 6 && intRespond2 == 5)  ? value * 1000
             : (intRespond1 == 6 && intRespond2 == 6)  ? value * 1
             : (intRespond1 == 6 && intRespond2 == 7)  ? value / 1000
             : (intRespond1 == 6 && intRespond2 == 8)  ? value / 1000000
             : (intRespond1 == 6 && intRespond2 == 9)  ? value / 1.0000E+9
             : (intRespond1 == 6 && intRespond2 == 10) ? value * 2.5000E+14
             : (intRespond1 == 6 && intRespond2 == 11) ? value * 1.2500E+14
             : (intRespond1 == 6 && intRespond2 == 12) ? value * 1.2500E+11
             : (intRespond1 == 6 && intRespond2 == 13) ? value * 125000000
             : (intRespond1 == 6 && intRespond2 == 14) ? value * 125000
             : (intRespond1 == 6 && intRespond2 == 15) ? value * 125
             : (intRespond1 == 6 && intRespond2 == 16) ? value / 8
             : (intRespond1 == 6 && intRespond2 == 17) ? value / 8000
             : (intRespond1 == 6 && intRespond2 == 18) ? value / 8000000
             : (intRespond1 == 6 && intRespond2 == 19) ? value / 8.0000E+9

             : (intRespond1 == 7 && intRespond2 == 1)  ? value * 1.0000E+18
             : (intRespond1 == 7 && intRespond2 == 2)  ? value * 1.0000E+15
             : (intRespond1 == 7 && intRespond2 == 3)  ? value * 1.0000E+12
             : (intRespond1 == 7 && intRespond2 == 4)  ? value * 1.0000E+9
             : (intRespond1 == 7 && intRespond2 == 5)  ? value * 1000000
             : (intRespond1 == 7 && intRespond2 == 6)  ? value * 1000
             : (intRespond1 == 7 && intRespond2 == 7)  ? value * 1
             : (intRespond1 == 7 && intRespond2 == 8)  ? value / 1000
             : (intRespond1 == 7 && intRespond2 == 9)  ? value / 1000000
             : (intRespond1 == 7 && intRespond2 == 10) ? value * 2.5000E+17
             : (intRespond1 == 7 && intRespond2 == 11) ? value * 1.2500E+17
             : (intRespond1 == 7 && intRespond2 == 12) ? value * 1.2500E+14
             : (intRespond1 == 7 && intRespond2 == 13) ? value * 1.2500E+11
             : (intRespond1 == 7 && intRespond2 == 14) ? value * 125000000
             : (intRespond1 == 7 && intRespond2 == 15) ? value * 125000
             : (intRespond1 == 7 && intRespond2 == 16) ? value * 125
             : (intRespond1 == 7 && intRespond2 == 17) ? value * 8
             : (intRespond1 == 7 && intRespond2 == 18) ? value / 8000
             : (intRespond1 == 7 && intRespond2 == 19) ? value / 8000000

             : (intRespond1 == 8 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 8 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 8 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 8 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 8 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 8 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 8 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 8 && intRespond2 == 8)  ? value * 1
             : (intRespond1 == 8 && intRespond2 == 9)  ? value * 0
             : (intRespond1 == 8 && intRespond2 == 10) ? value * 0
             : (intRespond1 == 8 && intRespond2 == 11) ? value * 0
             : (intRespond1 == 8 && intRespond2 == 12) ? value * 0
             : (intRespond1 == 8 && intRespond2 == 13) ? value * 0
             : (intRespond1 == 8 && intRespond2 == 14) ? value * 0
             : (intRespond1 == 8 && intRespond2 == 15) ? value * 0
             : (intRespond1 == 8 && intRespond2 == 16) ? value * 0
             : (intRespond1 == 8 && intRespond2 == 17) ? value * 0
             : (intRespond1 == 8 && intRespond2 == 18) ? value * 0
             : (intRespond1 == 8 && intRespond2 == 19) ? value * 0

             : (intRespond1 == 9 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 9 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 9 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 9 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 9 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 9 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 9 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 9 && intRespond2 == 8)  ? value * 0
             : (intRespond1 == 9 && intRespond2 == 9)  ? value * 1
             : (intRespond1 == 9 && intRespond2 == 10) ? value * 0
             : (intRespond1 == 9 && intRespond2 == 11) ? value * 0
             : (intRespond1 == 9 && intRespond2 == 12) ? value * 0
             : (intRespond1 == 9 && intRespond2 == 13) ? value * 0
             : (intRespond1 == 9 && intRespond2 == 14) ? value * 0
             : (intRespond1 == 9 && intRespond2 == 15) ? value * 0
             : (intRespond1 == 9 && intRespond2 == 16) ? value * 0
             : (intRespond1 == 9 && intRespond2 == 17) ? value * 0
             : (intRespond1 == 9 && intRespond2 == 18) ? value * 0
             : (intRespond1 == 9 && intRespond2 == 19) ? value * 0

             : (intRespond1 == 10 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 10 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 10 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 10 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 10 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 10 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 10 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 10 && intRespond2 == 8)  ? value * 0
             : (intRespond1 == 10 && intRespond2 == 9)  ? value * 0
             : (intRespond1 == 10 && intRespond2 == 10) ? value * 1
             : (intRespond1 == 10 && intRespond2 == 11) ? value * 0
             : (intRespond1 == 10 && intRespond2 == 12) ? value * 0
             : (intRespond1 == 10 && intRespond2 == 13) ? value * 0
             : (intRespond1 == 10 && intRespond2 == 14) ? value * 0
             : (intRespond1 == 10 && intRespond2 == 15) ? value * 0
             : (intRespond1 == 10 && intRespond2 == 16) ? value * 0
             : (intRespond1 == 10 && intRespond2 == 17) ? value * 0
             : (intRespond1 == 10 && intRespond2 == 18) ? value * 0
             : (intRespond1 == 10 && intRespond2 == 19) ? value * 0

             : (intRespond1 == 11 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 11 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 11 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 11 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 11 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 11 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 11 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 11 && intRespond2 == 8)  ? value * 0
             : (intRespond1 == 11 && intRespond2 == 9)  ? value * 0
             : (intRespond1 == 11 && intRespond2 == 10) ? value * 0
             : (intRespond1 == 11 && intRespond2 == 11) ? value * 1
             : (intRespond1 == 11 && intRespond2 == 12) ? value * 0
             : (intRespond1 == 11 && intRespond2 == 13) ? value * 0
             : (intRespond1 == 11 && intRespond2 == 14) ? value * 0
             : (intRespond1 == 11 && intRespond2 == 15) ? value * 0
             : (intRespond1 == 11 && intRespond2 == 16) ? value * 0
             : (intRespond1 == 11 && intRespond2 == 17) ? value * 0
             : (intRespond1 == 11 && intRespond2 == 18) ? value * 0
             : (intRespond1 == 11 && intRespond2 == 19) ? value * 0

             : (intRespond1 == 12 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 12 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 12 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 12 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 12 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 12 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 12 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 12 && intRespond2 == 8)  ? value * 0
             : (intRespond1 == 12 && intRespond2 == 9)  ? value * 0
             : (intRespond1 == 12 && intRespond2 == 10) ? value * 0
             : (intRespond1 == 12 && intRespond2 == 11) ? value * 0
             : (intRespond1 == 12 && intRespond2 == 12) ? value * 1
             : (intRespond1 == 12 && intRespond2 == 13) ? value * 0
             : (intRespond1 == 12 && intRespond2 == 14) ? value * 0
             : (intRespond1 == 12 && intRespond2 == 15) ? value * 0
             : (intRespond1 == 12 && intRespond2 == 16) ? value * 0
             : (intRespond1 == 12 && intRespond2 == 17) ? value * 0
             : (intRespond1 == 12 && intRespond2 == 18) ? value * 0
             : (intRespond1 == 12 && intRespond2 == 19) ? value * 0

             : (intRespond1 == 13 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 13 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 13 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 13 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 13 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 13 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 13 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 13 && intRespond2 == 8)  ? value * 0
             : (intRespond1 == 13 && intRespond2 == 9)  ? value * 0
             : (intRespond1 == 13 && intRespond2 == 10) ? value * 0
             : (intRespond1 == 13 && intRespond2 == 11) ? value * 0
             : (intRespond1 == 13 && intRespond2 == 12) ? value * 0
             : (intRespond1 == 13 && intRespond2 == 13) ? value * 1
             : (intRespond1 == 13 && intRespond2 == 14) ? value * 0
             : (intRespond1 == 13 && intRespond2 == 15) ? value * 0
             : (intRespond1 == 13 && intRespond2 == 16) ? value * 0
             : (intRespond1 == 13 && intRespond2 == 17) ? value * 0
             : (intRespond1 == 13 && intRespond2 == 18) ? value * 0
             : (intRespond1 == 13 && intRespond2 == 19) ? value * 0

             : (intRespond1 == 14 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 14 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 14 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 14 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 14 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 14 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 14 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 14 && intRespond2 == 8)  ? value * 0
             : (intRespond1 == 14 && intRespond2 == 9)  ? value * 0
             : (intRespond1 == 14 && intRespond2 == 10) ? value * 0
             : (intRespond1 == 14 && intRespond2 == 11) ? value * 0
             : (intRespond1 == 14 && intRespond2 == 12) ? value * 0
             : (intRespond1 == 14 && intRespond2 == 13) ? value * 0
             : (intRespond1 == 14 && intRespond2 == 14) ? value * 1
             : (intRespond1 == 14 && intRespond2 == 15) ? value * 0
             : (intRespond1 == 14 && intRespond2 == 16) ? value * 0
             : (intRespond1 == 14 && intRespond2 == 17) ? value * 0
             : (intRespond1 == 14 && intRespond2 == 18) ? value * 0
             : (intRespond1 == 14 && intRespond2 == 19) ? value * 0

             : (intRespond1 == 15 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 15 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 15 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 15 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 15 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 15 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 15 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 15 && intRespond2 == 8)  ? value * 0
             : (intRespond1 == 15 && intRespond2 == 9)  ? value * 0
             : (intRespond1 == 15 && intRespond2 == 10) ? value * 0
             : (intRespond1 == 15 && intRespond2 == 11) ? value * 0
             : (intRespond1 == 15 && intRespond2 == 12) ? value * 0
             : (intRespond1 == 15 && intRespond2 == 13) ? value * 0
             : (intRespond1 == 15 && intRespond2 == 14) ? value * 0
             : (intRespond1 == 15 && intRespond2 == 15) ? value * 1
             : (intRespond1 == 15 && intRespond2 == 16) ? value * 0
             : (intRespond1 == 15 && intRespond2 == 17) ? value * 0
             : (intRespond1 == 15 && intRespond2 == 18) ? value * 0
             : (intRespond1 == 15 && intRespond2 == 19) ? value * 0

             : (intRespond1 == 16 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 16 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 16 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 16 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 16 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 16 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 16 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 16 && intRespond2 == 8)  ? value * 0
             : (intRespond1 == 16 && intRespond2 == 9)  ? value * 0
             : (intRespond1 == 16 && intRespond2 == 10) ? value * 0
             : (intRespond1 == 16 && intRespond2 == 11) ? value * 0
             : (intRespond1 == 16 && intRespond2 == 12) ? value * 0
             : (intRespond1 == 16 && intRespond2 == 13) ? value * 0
             : (intRespond1 == 16 && intRespond2 == 14) ? value * 0
             : (intRespond1 == 16 && intRespond2 == 15) ? value * 0
             : (intRespond1 == 16 && intRespond2 == 16) ? value * 1
             : (intRespond1 == 16 && intRespond2 == 17) ? value * 0
             : (intRespond1 == 16 && intRespond2 == 18) ? value * 0
             : (intRespond1 == 16 && intRespond2 == 19) ? value * 0

             : (intRespond1 == 17 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 17 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 17 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 17 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 17 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 17 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 17 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 17 && intRespond2 == 8)  ? value * 0
             : (intRespond1 == 17 && intRespond2 == 9)  ? value * 0
             : (intRespond1 == 17 && intRespond2 == 10) ? value * 0
             : (intRespond1 == 17 && intRespond2 == 11) ? value * 0
             : (intRespond1 == 17 && intRespond2 == 12) ? value * 0
             : (intRespond1 == 17 && intRespond2 == 13) ? value * 0
             : (intRespond1 == 17 && intRespond2 == 14) ? value * 0
             : (intRespond1 == 17 && intRespond2 == 15) ? value * 0
             : (intRespond1 == 17 && intRespond2 == 16) ? value * 0
             : (intRespond1 == 17 && intRespond2 == 17) ? value * 1
             : (intRespond1 == 17 && intRespond2 == 18) ? value * 0
             : (intRespond1 == 17 && intRespond2 == 19) ? value * 0

             : (intRespond1 == 18 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 18 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 18 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 18 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 18 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 18 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 18 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 18 && intRespond2 == 8)  ? value * 0
             : (intRespond1 == 18 && intRespond2 == 9)  ? value * 0
             : (intRespond1 == 18 && intRespond2 == 10) ? value * 0
             : (intRespond1 == 18 && intRespond2 == 11) ? value * 0
             : (intRespond1 == 18 && intRespond2 == 12) ? value * 0
             : (intRespond1 == 18 && intRespond2 == 13) ? value * 0
             : (intRespond1 == 18 && intRespond2 == 14) ? value * 0
             : (intRespond1 == 18 && intRespond2 == 15) ? value * 0
             : (intRespond1 == 18 && intRespond2 == 16) ? value * 0
             : (intRespond1 == 18 && intRespond2 == 17) ? value * 0
             : (intRespond1 == 18 && intRespond2 == 18) ? value * 1
             : (intRespond1 == 18 && intRespond2 == 19) ? value * 0

             : (intRespond1 == 19 && intRespond2 == 1)  ? value * 0
             : (intRespond1 == 19 && intRespond2 == 2)  ? value * 0
             : (intRespond1 == 19 && intRespond2 == 3)  ? value * 0
             : (intRespond1 == 19 && intRespond2 == 4)  ? value * 0
             : (intRespond1 == 19 && intRespond2 == 5)  ? value * 0
             : (intRespond1 == 19 && intRespond2 == 6)  ? value * 0
             : (intRespond1 == 19 && intRespond2 == 7)  ? value * 0
             : (intRespond1 == 19 && intRespond2 == 8)  ? value * 0
             : (intRespond1 == 19 && intRespond2 == 9)  ? value * 0
             : (intRespond1 == 19 && intRespond2 == 10) ? value * 0
             : (intRespond1 == 19 && intRespond2 == 11) ? value * 0
             : (intRespond1 == 19 && intRespond2 == 12) ? value * 0
             : (intRespond1 == 19 && intRespond2 == 13) ? value * 0
             : (intRespond1 == 19 && intRespond2 == 14) ? value * 0
             : (intRespond1 == 19 && intRespond2 == 15) ? value * 0
             : (intRespond1 == 19 && intRespond2 == 16) ? value * 0
             : (intRespond1 == 19 && intRespond2 == 17) ? value * 0
             : (intRespond1 == 19 && intRespond2 == 18) ? value * 0
             : (intRespond1 == 19 && intRespond2 == 19) ? value * 1
                                                        : value * 0;

    std::cout << "\nResult: " << result << " " << unit.at(--intRespond2)
              << "\n\n(Press enter to continue)";
    std::cin.get();
  }
}