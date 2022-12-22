#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

class Calc {
public:
  class SimpleCalc {
    std::string str1, str2;
    char op;
    long double num1, num2;
    long double t_num = 0;
    int m_num1, m_num2;
    int m_num = 0;

  public:
    inline void _simple_calc();
  } simpleCalc;

  class BMI {
    std::string respond = "";
    int intWeight, intHeight;
    double weightValue, heightValue1, heightValue2;
    std::array<std::string, 2> weight;
    std::array<std::string, 4> height;

  public:
    inline void _bmi();
  } bmi;
} calc;

class Conv {
public:
  class Area {
    std::string strRespond;
    int intRespond1 = 1, intRespond2 = 1;
    long double result, value;
    std::array<std::string, 10> choice;

  public:
    inline void _area(void);
  } area;
} conv;

inline void mainMenu();

int main(void) {
  mainMenu();
  return 0;
}

// Acting like a main func
inline void mainMenu() {
  std::string str_respond;
  short unsigned int int_respond;
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
    std::cout << "\n\tCHOICE WHAT TO CALCULATE\n";
    size_t i = 1;
    for (auto a : choice)
      std::cout << "[" << i++ << "] " << a << "\n";

    std::cout << "\nType a number to enter one of the calculator: ";
    std::cin >> int_respond;

    while (std::cin.fail()) {
      system("CLS");
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "\nERROR: String input. (Press Enter)";
      std::cin.get();
      system("CLS");
      std::cout << "\n\tCHOICE WHAT TO CALCULATE\n";
      int i = 1;
      for (auto a : choice) {
        std::cout << "[" << i++ << "] " << a << "\n";
      }

      std::cout << "\nType a number to enter one of the calculator : ";
      std::cin >> int_respond;
    }

    if (int_respond < 1 || int_respond > 12) {
      system("CLS");
      std::cerr << "\nERROR: Out of range. (Press Enter)";
      std::cin.get();
      std::cin.get();
      system("CLS");
      continue;
    } else
      break;
  } while (true);

  switch (int_respond) {
  case 1:
    calc.simpleCalc._simple_calc();
    break;
  case 2:
    conv.area._area();
    break;
  case 3:
    calc.bmi._bmi();
    break;
  case 4:
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

void Calc::SimpleCalc::_simple_calc() {
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("CLS");
    std::cout << "\tCommands:"
                 "\n'e x t' Exits the program"
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
    std::cin >> str1 >> op >> str2;

    if (str1 == "e" || str1 == "E") {
      std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
      if (op == 'x' || op == 'X') {
        op = tolower(op);
        if (str2 == "t" || str2 == "T") {
          std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
          if (str1 == "e" && op == 'x' && str2 == "t")
            return mainMenu();
        } // str2
      }   // op
    }     // str1

    switch (op) {
    case '+':
      num1 = stold(str1);
      num2 = stold(str2);
      t_num = num1 + num2;
      break;
    case '-':
      num1 = stold(str1);
      num2 = stold(str2);
      t_num = num1 - num2;
      break;
    case '*':
      num1 = stold(str1);
      num2 = stold(str2);
      t_num = num1 * num2;
      break;
    case '/':
      num1 = stold(str1);
      num2 = stold(str2);
      t_num = num1 / num2;
      break;
    case '%':
      num1 = stold(str1);
      num2 = stold(str2);
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
          return mainMenu();
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
          return mainMenu();
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
          return mainMenu();
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
              return mainMenu();
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
              return mainMenu();
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
              return mainMenu();
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
              return mainMenu();
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
              return mainMenu();
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

void Conv::Area::_area() {
  choice = {"Square inch (in)",
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
    system("CLS");

    size_t i = 1;
    system("CLS");
    std::cout << "\tCommands:"
                 "\n'exit' Exit the conversion\n\n";

    for (auto a : choice)
      std::cout << "[" << i++ << "] " << a << "\n";

    std::cout << "\nFrom: ";
    std::cin >> strRespond;
    std::transform(strRespond.begin(), strRespond.end(), strRespond.begin(),
                   ::tolower);
    if (strRespond == "exit")
      return mainMenu();
    else {
      try {
        intRespond1 = stold(strRespond);
      } catch (...) {
        continue;
      }
    }
    if (intRespond1 < 1 || intRespond1 > 10)
      continue;

    std::cout << "To: ";
    try {
      std::cin >> intRespond2;
    } catch (...) {
      continue;
    }
    if (intRespond2 < 1 || intRespond2 > 10)
      continue;

    try {
      std::cout << "Value to Convert: ";
      std::cin >> value;
    } catch (...) {
      continue;
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

    std::cout << "\nResult: " << result << " " << choice.at(--intRespond2)
              << "\n\n(Press Enter to continue)";
    std::cin.get();
  }
}