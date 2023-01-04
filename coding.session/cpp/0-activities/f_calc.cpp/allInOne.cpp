#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>

#define LOG_CLEAR std::cout << "\033[2J\033[1;1H";
#define RELEASE 1

#include "_class.hpp"

static void mainMenu();
static inline long double listOfResult(unsigned short where,
                                       unsigned short &from, unsigned short &to,
                                       long double &value);

int main() {
#if RELEASE == 1 // RELEASE
  mainMenu();
#else // DEBUGGING
  
#endif
  return 0;
}
// Acting like a main func
static void mainMenu() {
  SimpleCalc *simplecalc = new SimpleCalc;
  BMI *bmi = new BMI;
  Discount *discount = new Discount;
  Conv1 *conv1 = new Conv1;
  Conv2 *conv2 = new Conv2;

  unsigned short iRespond;
  const std::vector<std::string> choice{
      "Simple Calculator",      "Calculator: BMI",
      "Calculator: Discount",   "Converter: Area",
      "Converter: Data",        "Converter: Length [ONG]",
      "Converter: Mass [ONG]",  "Converter: Speed [ONG]",
      "Converter: Temperature", "Converter: Time [ONG]",
      "Converter: Volume [ONG]"};

  do {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    LOG_CLEAR;
    std::cout << "\tCommands:"
                 "\n'e' to exit program.";
    std::cout << "\n\n\tCALCULATOR / CONVERTER\n";
    glb::i = 1;
    for (auto a : choice)
      std::cout << "[" << glb::i++ << "] " << a << "\n";

    std::cout << "\nType a number to enter one of the calculator: ";
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e") {
      delete simplecalc;
      delete bmi;
      delete discount;
      delete conv1;
      delete conv2;
      break;
    }

    try {
      iRespond = stoi(glb::strRespond1);
    } catch (...) {
      continue;
    }

    if (iRespond == 1) {
      // delete simplecalc;
      delete bmi;
      delete discount;
      delete conv1;
      delete conv2;
      simplecalc->simpleCalc();
    } else if (iRespond == 2) {
      delete simplecalc;
      // delete bmi;
      delete discount;
      delete conv1;
      delete conv2;
      bmi->bmi();
    } else if (iRespond == 3) {
      delete simplecalc;
      delete bmi;
      // delete discount;
      delete conv1;
      delete conv2;
      discount->discount();
    } else if (iRespond == 4) {
      delete simplecalc;
      delete bmi;
      delete discount;
      // delete conv1;
      delete conv2;
      conv1->area();
    } else if (iRespond == 5) {
      delete simplecalc;
      delete bmi;
      delete discount;
      delete conv1;
      // delete conv2;
      conv1->data();
    } else if (iRespond == 6) {
      delete simplecalc;
      delete bmi;
      delete discount;
      delete conv1;
      delete conv2;
      continue;
    } else if (iRespond == 7) {
      delete simplecalc;
      delete bmi;
      delete discount;
      delete conv1;
      delete conv2;
      continue;
    } else if (iRespond == 8) {
      delete simplecalc;
      delete bmi;
      delete discount;
      delete conv1;
      delete conv2;
      continue;
    } else if (iRespond == 9) {
      delete simplecalc;
      delete bmi;
      delete discount;
      delete conv1;
      delete conv2;
      continue;
    } else if (iRespond == 10) {
      delete simplecalc;
      delete bmi;
      delete discount;
      delete conv1;
      delete conv2;
      conv2->temperature();
    } else if (iRespond == 11) {
      delete simplecalc;
      delete bmi;
      delete discount;
      delete conv1;
      delete conv2;
      continue;
    } else if (iRespond == 12) {
      delete simplecalc;
      delete bmi;
      delete discount;
      delete conv1;
      delete conv2;
      continue;
    } else {
      delete simplecalc;
      delete bmi;
      delete discount;
      delete conv1;
      delete conv2;
      continue;
    }
    break;
  } while (true);
  return;
}

void SimpleCalc::simpleCalc() {
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    LOG_CLEAR;
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
    else if (op == '%')
      std::cout << "\n\nLast result: " << m_num;
    else if (!(op == '+' || op == '-' || op == '*' || op == '/' || op == '%' ||
               op == ' '))
      std::cout << "\n\nSomething goes wrong.";
    else
      std::cout << "\n\nDefault: " << 0;

    std::cout << "\n\n\t[Ex. Format: 1 + 2]\n>> ";
    // Frist num
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e")
      return mainMenu();

    // Operator
    std::cin >> op;
    op = std::tolower(op);
    if (op == 'e')
      return mainMenu();

    // second num
    std::cin >> glb::strRespond2;
    std::transform(glb::strRespond2.begin(), glb::strRespond2.end(),
                   glb::strRespond2.begin(), ::tolower);
    if (glb::strRespond2 == "e")
      return mainMenu();

    try {
      num1 = stold(glb::strRespond1);
      num2 = stold(glb::strRespond2);
    } catch (...) {
      continue;
    }

    if (op == '+') {
      t_num = num1 + num2;
    } else if (op == '-') {
      t_num = num1 - num2;
    } else if (op == '*') {
      t_num = num1 * num2;
    } else if (op == '/') {
      t_num = num1 / num2;
    } else if (op == '%') {
      m_num1 = num1;
      m_num2 = num2;
      m_num = m_num1 % m_num2;
    } else {
      continue;
    }
  }
}

void BMI::bmi() {
  weight = {"pounds", "kilograms"};
  height = {"feet", "inches", "centimeters", "meters"};

  std::cout << "Press Enter";
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {
      while (true) {
        glb::i = 1;
        LOG_CLEAR;
        std::cout << "\tCommands:"
                     "\n'e' Back to main menu"
                     "\n\n\tWeight\n";

        for (auto a : weight)
          std::cout << "[" << glb::i++ << "] " << a << "\n";

        std::cout << "Weight: ";
        std::cin >> glb::strRespond1;
        std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                       glb::strRespond1.begin(), ::tolower);
        if (glb::strRespond1 == "e")
          return mainMenu();
        else {
          try {
            intWeight = std::stoi(glb::strRespond1);
            weight.at(--intWeight);
          } catch (...) {
            continue;
          }
        }
        break;
      } // Weight type
      while (true) {
        LOG_CLEAR;
        std::cout << "\tCommands:"
                     "\n'e' Back to main menu"
                     "\n\n\tWeight";
        std::cout << "\nWeight (" << weight.at(intWeight) << ") "
                  << "\n";
        std::cout << "Weight Value: ";
        std::cin >> glb::strRespond1;
        std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                       glb::strRespond1.begin(), ::tolower);
        if (glb::strRespond1 == "e")
          return mainMenu();
        else {
          try {
            weightValue = std::stod(glb::strRespond1);
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
        LOG_CLEAR;
        std::cout << "\tCommands:\n'e' Back to main menu"
                     "\n\nWeight: "
                  << weightValue << " " << weight.at(1) << "\n\n\tHeight\n";

        glb::i = 1;
        for (auto a : height)
          std::cout << "[" << glb::i++ << "] " << a << "\n";

        std::cout << "Height: ";
        std::cin >> glb::strRespond1;
        std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                       glb::strRespond1.begin(), ::tolower);
        if (glb::strRespond1 == "e")
          return mainMenu();
        else {
          try {
            intHeight = std::stoi(glb::strRespond1);
            height.at(--intHeight);
          } catch (...) {
            continue;
          }
        }
        break;
      } // Height type
      while (true) {
        LOG_CLEAR;
        std::cout << "\tCommands:\n'e' Back to main menu"
                     "\n\nWeight: "
                  << weightValue << " " << weight.at(1) << "\n\n\tHeight:";
        std::cout << "\nHeight (" << height.at(intHeight) << ") ";

        if (height.at(intHeight) == height.at(0)) { // ft and in
          while (true) {
            LOG_CLEAR;
            std::cout << "\tCommands:\n'e' Back to main menu"
                         "\nWeight: "
                      << weightValue << " " << weight.at(1)
                      << "\n\n\tHeight: " << height.at(intHeight);
            std::cout << "\nHeight Value (ft): ";
            std::cin >> glb::strRespond1;
            std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                           glb::strRespond1.begin(), ::tolower);
            if (glb::strRespond1 == "e")
              return mainMenu();
            else {
              try {
                heightValue1 = stod(glb::strRespond1);
                heightValue1 /= 3.2808399;
              } catch (...) {
                continue;
              }
            }
            break;
          } // feet value
          while (true) {
            LOG_CLEAR;
            std::cout << "\tCommands:\n'e' Back to main menu"
                         "\nWeight: "
                      << weightValue << " " << weight.at(1)
                      << "\n\n\tHeight: " << height.at(intHeight);
            std::cout << "\nHeight Value (ft) - " << heightValue1 << " "
                      << height.at(3);
            std::cout << "\nHeight Value (in): ";
            std::cin >> glb::strRespond1;
            std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                           glb::strRespond1.begin(), ::tolower);
            if (glb::strRespond1 == "e")
              return mainMenu();
            else {
              try {
                heightValue2 = stod(glb::strRespond1);
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
            LOG_CLEAR;
            std::cout << "\tCommands:\n'e' Back to main menu"
                         "\nWeight: "
                      << weightValue << " " << weight.at(1)
                      << "\n\n\tHeight: " << height.at(intHeight);
            std::cout << "\nHeight Value (in): ";
            std::cin >> glb::strRespond1;
            std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                           glb::strRespond1.begin(), ::tolower);
            if (glb::strRespond1 == "e")
              return mainMenu();
            else {
              try {
                heightValue1 = stod(glb::strRespond1);
                heightValue1 /= 39.3700787;
              } catch (...) {
                continue;
              }
            }
            break;
          }                                                // inches
        } else if (height.at(intHeight) == height.at(2)) { // cm
          while (true) {
            LOG_CLEAR;
            std::cout << "\tCommands:\n'e' Back to main menu"
                         "\nWeight: "
                      << weightValue << " " << weight.at(1)
                      << "\n\n\tHeight: " << height.at(intHeight);
            std::cout << "\nHeight Value (cm): ";
            std::cin >> glb::strRespond1;
            std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                           glb::strRespond1.begin(), ::tolower);
            if (glb::strRespond1 == "e")
              return mainMenu();
            else {
              try {
                heightValue1 = stod(glb::strRespond1);
                heightValue1 /= 100;
              } catch (...) {
                continue;
              }
            }
            break;
          }                                                // cm
        } else if (height.at(intHeight) == height.at(3)) { // meters
          while (true) {
            LOG_CLEAR;
            std::cout << "\tCommands:\n'e' Back to main menu"
                         "\nWeight: "
                      << weightValue << " " << weight.at(1)
                      << "\n\n\tHeight: " << height.at(intHeight);
            std::cout << "\nHeight Value (m): ";
            std::cin >> glb::strRespond1;
            std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                           glb::strRespond1.begin(), ::tolower);
            if (glb::strRespond1 == "e")
              return mainMenu();
            else {
              try {
                heightValue1 = stod(glb::strRespond1);
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
    LOG_CLEAR;
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

void Discount::discount() {
  std::cout << "Press enter.";
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    LOG_CLEAR;
    std::cout << "\tCommands:"
                 "\n'e' Back to main menu\n\n";
    // Original Price
    std::cout << "Enter Original Price: ";
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e")
      return mainMenu();
    else {
      try {
        origPrice = stof(glb::strRespond1);
      } catch (...) {
        continue;
      }
    }
    // Percentage
    std::cout << "Enter Percentage: ";
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e")
      return mainMenu();
    else {
      try {
        Percentage = stof(glb::strRespond1);
        Percentage *= .01;
      } catch (...) {
        continue;
      }
    }
    LOG_CLEAR;
    std::cout << "You save: Php" << Percentage * origPrice;
    std::cout << "\nFinal Price: Php" << (origPrice - (Percentage * origPrice))
              << "\n(Press enter to continue)";
    std::cin.get();
  }
}

#define CONV_CLEAR                                                             \
  unit.clear();                                                                \
  return mainMenu();

void Conv1::area() {
  unit = {"Square inch (in)",
          "Square foot (ft)",
          "Square yard (yd)",
          "Square mile (mi)",
          "acr)",
          "hectare (ha)",
          "Square millimeter (mm)",
          "Square centimeter (cm)",
          "Square meter (m)",
          "Square kilometer (km)"};
  std::cout << "Press enter.";
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    glb::i = 1;
    LOG_CLEAR;
    std::cout << "\tCommands:"
                 "\n'e' Back to main menu\n\n";

    for (auto a : unit)
      std::cout << "[" << glb::i++ << "] " << a << "\n";

    std::cout << "\nFrom: ";
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e") {
      CONV_CLEAR
    } else {
      try {
        iConv1 = stoi(glb::strRespond1);
      } catch (...) {
        continue;
      }
    }
    if (iConv1 < 1 || iConv1 > 10)
      continue;

    std::cout << "To: ";
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e") {
      CONV_CLEAR
    } else {
      try {
        iConv2 = stoi(glb::strRespond1);
      } catch (...) {
        continue;
      }
    }

    if (iConv2 < 1 || iConv2 > 10)
      continue;

    std::cout << "Value of " << unit.at(--iConv1) << ": " << ++iConv1;
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e") {
      CONV_CLEAR;
    } else {
      try {
        value = stold(glb::strRespond1);
      } catch (...) {
        continue;
      }
    }

    result = listOfResult(1, iConv1, iConv2, value);

    std::cout << "\nResult: " << result << " " << unit.at(--iConv2)
              << "\n\n(Press Enter to continue)";
    std::cin.get();
  }
}

void Conv1::data() {
  unit = {"Bit (b)",       "Kilobit (kb)",   "Megabit (Mb)",  "Gigabit (Gb)",
          "Terabit (Tb)",  "Petabit (Pb)",   "Exabit (Eb)",   "Zettabit (Zb)",
          "Yottabit (Yb)", "Nibble ()",      "Byte (B)",      "Kilobyte (kB)",
          "Megabyte (MB)", "Gigabyte (GB)",  "Terabyte (TB)", "Petabyte (PB)",
          "Exabyte (EB)",  "Zettabyte (ZB)", "Yottabyte (YB)"};
  std::cout << "Press enter.";
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    glb::i = 1;
    LOG_CLEAR;
    std::cout << "\tCommands:"
                 "\n'e' Back to main menu\n\n";
    for (auto a : unit)
      std::cout << "[" << glb::i++ << "] " << a << "\n";

    std::cout << "\nFrom: ";
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e") {
      CONV_CLEAR;
    } else {
      try {
        iConv1 = std::stoi(glb::strRespond1);
      } catch (...) {
        continue;
      }
    }
    if (iConv1 < 1 || iConv1 > 19)
      continue;

    std::cout << "To: ";
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e") {
      CONV_CLEAR;
    } else {
      try {
        iConv2 = std::stoi(glb::strRespond1);
      } catch (...) {
        continue;
      }
    }
    if (iConv2 < 1 || iConv2 > 19)
      continue;

    std::cout << "Value of " << unit.at(--iConv1) << ": " << ++iConv1;
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e") {
      CONV_CLEAR;
    } else {
      try {
        value = std::stoi(glb::strRespond1);
      } catch (...) {
        continue;
      }
    }
    result = listOfResult(2, iConv1, iConv2, value);
    std::cout << "\nResult: " << result << " " << unit.at(--iConv2)
              << "\n\n(Press enter to continue)";
    std::cin.get();
  }
}

static long double listOfResult(unsigned short where,
                                       unsigned short &from, unsigned short &to,
                                       long double &value) {
  long double result = 0.0L;
  if (where == 1) {
    result = (from == 1)    ? ((to == 2)    ? value / 144
                               : (to == 3)  ? value / 1296
                               : (to == 4)  ? value / 4.0145E+9
                               : (to == 5)  ? value / 6.2726E+6
                               : (to == 6)  ? value / 1.5500E+7
                               : (to == 7)  ? value * 645.16
                               : (to == 8)  ? value * 6.4516
                               : (to == 9)  ? value / 1550.0031
                               : (to == 10) ? value / 1.5500E+9
                                            : value * 1) // if n1 == n2
             : (from == 2)  ? ((to == 1)    ? value * 144
                               : (to == 3)  ? value / 9
                               : (to == 4)  ? value / 2.7878E+7
                               : (to == 5)  ? value / 43560
                               : (to == 6)  ? value / 107639.104
                               : (to == 7)  ? value * 92903.04
                               : (to == 8)  ? value * 929.0304
                               : (to == 9)  ? value / 10.7639104
                               : (to == 10) ? value / 1.0764E+7
                                            : value * 1) // if n1 == n2
             : (from == 3)  ? ((to == 1)    ? value * 1296
                               : (to == 2)  ? value * 9
                               : (to == 4)  ? value / 3.0976E+6
                               : (to == 5)  ? value / 4840
                               : (to == 6)  ? value / 11959.9005
                               : (to == 7)  ? value * 836127.36
                               : (to == 8)  ? value * 8361.2736
                               : (to == 9)  ? value / 1.19599005
                               : (to == 10) ? value / 1.1960E+6
                                            : value * 1) // if n1 == n2
             : (from == 4)  ? ((to == 1)    ? value * 4.0145E+9
                               : (to == 2)  ? value * 2.7878E+7
                               : (to == 3)  ? value * 3097600
                               : (to == 5)  ? value / 3.0976E+6
                               : (to == 6)  ? value / 11959.9005
                               : (to == 7)  ? value * 836127.36
                               : (to == 8)  ? value * 8361.2736
                               : (to == 9)  ? value / 1.19599005
                               : (to == 10) ? value / 1.1960E+6
                                            : value * 1) // if n1 == n2
             : (from == 5)  ? ((to == 1)    ? value * 6272640
                               : (to == 2)  ? value * 43560
                               : (to == 3)  ? value * 4840
                               : (to == 4)  ? value / 640
                               : (to == 6)  ? value / 2.47105381
                               : (to == 7)  ? value * 4.0469E+9
                               : (to == 8)  ? value * 4.0469E+7
                               : (to == 9)  ? value * 4046.85642
                               : (to == 10) ? value / 247.105381
                                            : value * 1) // if n1 == n2
             : (from == 6)  ? ((to == 1)    ? value * 1.5500E+7
                               : (to == 2)  ? value * 107639.104
                               : (to == 3)  ? value * 11959.9005
                               : (to == 4)  ? value / 258.998811
                               : (to == 5)  ? value * 2.47105381
                               : (to == 7)  ? value * 1.0000E+10
                               : (to == 8)  ? value * 100000000
                               : (to == 9)  ? value * 10000
                               : (to == 10) ? value / 100
                                            : value * 1) // if n1 == n2
             : (from == 7)  ? ((to == 1)    ? value / 645.16
                               : (to == 2)  ? value / 92903.04
                               : (to == 3)  ? value / 836127.36
                               : (to == 4)  ? value / 2.5900E+12
                               : (to == 5)  ? value / 4.0469E+9
                               : (to == 6)  ? value / 4.0469E+9
                               : (to == 8)  ? value / 100
                               : (to == 9)  ? value / 1000000
                               : (to == 10) ? value / 1.0000E+12
                                            : value * 1) // if n1 == n2
             : (from == 8)  ? ((to == 1)    ? value / 6.4516
                               : (to == 2)  ? value / 929.0304
                               : (to == 3)  ? value / 8361.2736
                               : (to == 4)  ? value / 2.5900E+10
                               : (to == 5)  ? value / 4.0469E+7
                               : (to == 6)  ? value / 100000000
                               : (to == 7)  ? value * 100
                               : (to == 9)  ? value / 10000
                               : (to == 10) ? value / 1.0000E+10
                                            : value * 1) // if n1 == n2
             : (from == 9)  ? ((to == 1)    ? value * 1550.0031
                               : (to == 2)  ? value * 10.7639104
                               : (to == 3)  ? value * 1.19599005
                               : (to == 4)  ? value / 2.5900E+6
                               : (to == 5)  ? value / 4046.85642
                               : (to == 6)  ? value / 10000
                               : (to == 7)  ? value * 1000000
                               : (to == 8)  ? value * 10000
                               : (to == 10) ? value / 1000000
                                            : value * 1) // if n1 == n2
             : (from == 10) ? ((to == 1)   ? value * 1.5500E+9
                               : (to == 2) ? value * 1.0764E+7
                               : (to == 3) ? value * 1.1960E+6
                               : (to == 4) ? value / 2.58998811
                               : (to == 5) ? value * 247.105381
                               : (to == 6) ? value * 100
                               : (to == 7) ? value * 1.0000E+12
                               : (to == 8) ? value * 1.0000E+10
                               : (to == 9) ? value * 1000000
                                           : value * 1) // if n1 == n2
                            : value * 0;
  }
  if (where == 2) {
    result = (from == 1 && to == 1)    ? value * 1
             : (from == 1 && to == 2)  ? value / 1000
             : (from == 1 && to == 3)  ? value / 1000000
             : (from == 1 && to == 4)  ? value / 1.0000e+9
             : (from == 1 && to == 5)  ? value / 1.0000e+12
             : (from == 1 && to == 6)  ? value / 1.0000e+15
             : (from == 1 && to == 7)  ? value / 1.0000e+18
             : (from == 1 && to == 8)  ? value / 1.0000e+21
             : (from == 1 && to == 9)  ? value / 1.0000e+24
             : (from == 1 && to == 10) ? value / 4
             : (from == 1 && to == 11) ? value / 8
             : (from == 1 && to == 12) ? value / 8000
             : (from == 1 && to == 13) ? value / 8000000
             : (from == 1 && to == 14) ? value / 8.0000e+9
             : (from == 1 && to == 15) ? value / 8.0000e+12
             : (from == 1 && to == 16) ? value / 8.0000e+15
             : (from == 1 && to == 17) ? value / 8.0000e+18
             : (from == 1 && to == 18) ? value / 8.0000e+21
             : (from == 1 && to == 19) ? value / 8.0000e+24

             : (from == 2 && to == 1)  ? value * 1000
             : (from == 2 && to == 2)  ? value * 1
             : (from == 2 && to == 3)  ? value / 1000
             : (from == 2 && to == 4)  ? value / 1000000
             : (from == 2 && to == 5)  ? value / 1.0000e+9
             : (from == 2 && to == 6)  ? value / 1.0000e+12
             : (from == 2 && to == 7)  ? value / 1.0000e+15
             : (from == 2 && to == 8)  ? value / 1.0000e+18
             : (from == 2 && to == 9)  ? value / 1.0000e+21
             : (from == 2 && to == 10) ? value * 250
             : (from == 2 && to == 11) ? value * 125
             : (from == 2 && to == 12) ? value / 8
             : (from == 2 && to == 13) ? value / 8000
             : (from == 2 && to == 14) ? value / 8000000
             : (from == 2 && to == 15) ? value / 8.0000e+9
             : (from == 2 && to == 16) ? value / 8.0000e+12
             : (from == 2 && to == 17) ? value / 8.0000e+15
             : (from == 2 && to == 18) ? value / 8.0000e+18
             : (from == 2 && to == 19) ? value / 8.0000e+21

             : (from == 3 && to == 1)  ? value * 1000000
             : (from == 3 && to == 2)  ? value * 1000
             : (from == 3 && to == 3)  ? value * 1
             : (from == 3 && to == 4)  ? value / 1000
             : (from == 3 && to == 5)  ? value / 1000000
             : (from == 3 && to == 6)  ? value / 1.0000E+9
             : (from == 3 && to == 7)  ? value / 1.0000E+12
             : (from == 3 && to == 8)  ? value / 1.0000E+15
             : (from == 3 && to == 9)  ? value / 1.0000E+18
             : (from == 3 && to == 10) ? value * 250000
             : (from == 3 && to == 11) ? value * 125000
             : (from == 3 && to == 12) ? value * 125
             : (from == 3 && to == 13) ? value / 8
             : (from == 3 && to == 14) ? value / 8000
             : (from == 3 && to == 15) ? value / 8000000
             : (from == 3 && to == 16) ? value / 8.0000E+9
             : (from == 3 && to == 17) ? value / 8.0000E+12
             : (from == 3 && to == 18) ? value / 8.0000E+15
             : (from == 3 && to == 19) ? value / 8.0000E+18

             : (from == 4 && to == 1)  ? value * 1.0000E+9
             : (from == 4 && to == 2)  ? value * 1000000
             : (from == 4 && to == 3)  ? value * 1000
             : (from == 4 && to == 4)  ? value * 1
             : (from == 4 && to == 5)  ? value / 1000
             : (from == 4 && to == 6)  ? value / 1000000
             : (from == 4 && to == 7)  ? value / 1.0000E+9
             : (from == 4 && to == 8)  ? value / 1.0000E+12
             : (from == 4 && to == 9)  ? value / 1.0000E+15
             : (from == 4 && to == 10) ? value * 250000000
             : (from == 4 && to == 11) ? value * 125000000
             : (from == 4 && to == 12) ? value * 125000
             : (from == 4 && to == 13) ? value * 125
             : (from == 4 && to == 14) ? value / 8
             : (from == 4 && to == 15) ? value / 8000
             : (from == 4 && to == 16) ? value / 8000000
             : (from == 4 && to == 17) ? value / 8.0000E+9
             : (from == 4 && to == 18) ? value / 8.0000E+12
             : (from == 4 && to == 19) ? value / 8.0000E+15

             : (from == 5 && to == 1)  ? value * 1.0000E+12
             : (from == 5 && to == 2)  ? value * 1.0000E+9
             : (from == 5 && to == 3)  ? value * 1000000
             : (from == 5 && to == 4)  ? value * 1000
             : (from == 5 && to == 5)  ? value * 1
             : (from == 5 && to == 6)  ? value / 1000
             : (from == 5 && to == 7)  ? value / 1000000
             : (from == 5 && to == 8)  ? value / 1.0000E+9
             : (from == 5 && to == 9)  ? value / 1.0000E+12
             : (from == 5 && to == 10) ? value * 2.5000E+11
             : (from == 5 && to == 11) ? value * 1.2500E+11
             : (from == 5 && to == 12) ? value * 125000000
             : (from == 5 && to == 13) ? value * 125000
             : (from == 5 && to == 14) ? value * 125
             : (from == 5 && to == 15) ? value / 8
             : (from == 5 && to == 16) ? value / 8000
             : (from == 5 && to == 17) ? value / 8000000
             : (from == 5 && to == 18) ? value / 8.0000E+9
             : (from == 5 && to == 19) ? value / 8.0000E+12

             : (from == 6 && to == 1)  ? value * 1.0000E+15
             : (from == 6 && to == 2)  ? value * 1.0000E+12
             : (from == 6 && to == 3)  ? value * 1.0000E+9
             : (from == 6 && to == 4)  ? value * 1000000
             : (from == 6 && to == 5)  ? value * 1000
             : (from == 6 && to == 6)  ? value * 1
             : (from == 6 && to == 7)  ? value / 1000
             : (from == 6 && to == 8)  ? value / 1000000
             : (from == 6 && to == 9)  ? value / 1.0000E+9
             : (from == 6 && to == 10) ? value * 2.5000E+14
             : (from == 6 && to == 11) ? value * 1.2500E+14
             : (from == 6 && to == 12) ? value * 1.2500E+11
             : (from == 6 && to == 13) ? value * 125000000
             : (from == 6 && to == 14) ? value * 125000
             : (from == 6 && to == 15) ? value * 125
             : (from == 6 && to == 16) ? value / 8
             : (from == 6 && to == 17) ? value / 8000
             : (from == 6 && to == 18) ? value / 8000000
             : (from == 6 && to == 19) ? value / 8.0000E+9

             : (from == 7 && to == 1)  ? value * 1.0000E+18
             : (from == 7 && to == 2)  ? value * 1.0000E+15
             : (from == 7 && to == 3)  ? value * 1.0000E+12
             : (from == 7 && to == 4)  ? value * 1.0000E+9
             : (from == 7 && to == 5)  ? value * 1000000
             : (from == 7 && to == 6)  ? value * 1000
             : (from == 7 && to == 7)  ? value * 1
             : (from == 7 && to == 8)  ? value / 1000
             : (from == 7 && to == 9)  ? value / 1000000
             : (from == 7 && to == 10) ? value * 2.5000E+17
             : (from == 7 && to == 11) ? value * 1.2500E+17
             : (from == 7 && to == 12) ? value * 1.2500E+14
             : (from == 7 && to == 13) ? value * 1.2500E+11
             : (from == 7 && to == 14) ? value * 125000000
             : (from == 7 && to == 15) ? value * 125000
             : (from == 7 && to == 16) ? value * 125
             : (from == 7 && to == 17) ? value * 8
             : (from == 7 && to == 18) ? value / 8000
             : (from == 7 && to == 19) ? value / 8000000

             : (from == 8 && to == 1)  ? value * 1.0000E+21
             : (from == 8 && to == 2)  ? value * 1.0000E+18
             : (from == 8 && to == 3)  ? value * 1.0000E+15
             : (from == 8 && to == 4)  ? value * 1.0000E+12
             : (from == 8 && to == 5)  ? value * 1.0000E+9
             : (from == 8 && to == 6)  ? value * 1000000
             : (from == 8 && to == 7)  ? value * 1000
             : (from == 8 && to == 8)  ? value * 1
             : (from == 8 && to == 9)  ? value / 1000
             : (from == 8 && to == 10) ? value * 2.5000E+20
             : (from == 8 && to == 11) ? value * 1.2500E+20
             : (from == 8 && to == 12) ? value * 1.2500E+17
             : (from == 8 && to == 13) ? value * 1.2500E+14
             : (from == 8 && to == 14) ? value * 1.2500E+11
             : (from == 8 && to == 15) ? value * 125000000
             : (from == 8 && to == 16) ? value * 125000
             : (from == 8 && to == 17) ? value * 125
             : (from == 8 && to == 18) ? value * 8
             : (from == 8 && to == 19) ? value / 8000

             : (from == 9 && to == 1)  ? value * 1.0000E+24
             : (from == 9 && to == 2)  ? value * 1.0000E+21
             : (from == 9 && to == 3)  ? value * 1.0000E+18
             : (from == 9 && to == 4)  ? value * 1.0000E+15
             : (from == 9 && to == 5)  ? value * 1.0000E+12
             : (from == 9 && to == 6)  ? value * 1.0000E+9
             : (from == 9 && to == 7)  ? value * 1000000
             : (from == 9 && to == 8)  ? value * 1000
             : (from == 9 && to == 9)  ? value * 1
             : (from == 9 && to == 10) ? value * 2.5000E+23
             : (from == 9 && to == 11) ? value * 1.2500E+23
             : (from == 9 && to == 12) ? value * 1.2500E+20
             : (from == 9 && to == 13) ? value * 1.2500E+17
             : (from == 9 && to == 14) ? value * 1.2500E+14
             : (from == 9 && to == 15) ? value * 1.2500E+11
             : (from == 9 && to == 16) ? value * 125000000
             : (from == 9 && to == 17) ? value * 125000
             : (from == 9 && to == 18) ? value * 125
             : (from == 9 && to == 19) ? value * 8

             : (from == 10 && to == 1)  ? value * 4
             : (from == 10 && to == 2)  ? value / 250
             : (from == 10 && to == 3)  ? value / 250000
             : (from == 10 && to == 4)  ? value / 2.5000E+8
             : (from == 10 && to == 5)  ? value / 2.5000E+11
             : (from == 10 && to == 6)  ? value / 2.5000E+14
             : (from == 10 && to == 7)  ? value / 2.5000E+17
             : (from == 10 && to == 8)  ? value / 2.5000E+20
             : (from == 10 && to == 9)  ? value / 2.5000E+23
             : (from == 10 && to == 10) ? value * 1
             : (from == 10 && to == 11) ? value / 2
             : (from == 10 && to == 12) ? value / 2000
             : (from == 10 && to == 13) ? value / 2000000
             : (from == 10 && to == 14) ? value / 2.0000E+9
             : (from == 10 && to == 15) ? value / 2.0000E+12
             : (from == 10 && to == 16) ? value / 2.0000E+15
             : (from == 10 && to == 17) ? value / 2.0000E+18
             : (from == 10 && to == 18) ? value / 2.0000E+21
             : (from == 10 && to == 19) ? value / 2.0000E+24

             : (from == 11 && to == 1)  ? value * 8
             : (from == 11 && to == 2)  ? value / 125
             : (from == 11 && to == 3)  ? value / 125000
             : (from == 11 && to == 4)  ? value / 1.2500E+8
             : (from == 11 && to == 5)  ? value / 1.2500E+11
             : (from == 11 && to == 6)  ? value / 1.2500E+14
             : (from == 11 && to == 7)  ? value / 1.2500E+17
             : (from == 11 && to == 8)  ? value / 1.2500E+20
             : (from == 11 && to == 9)  ? value / 1.2500E+23
             : (from == 11 && to == 10) ? value * 2
             : (from == 11 && to == 11) ? value * 1
             : (from == 11 && to == 12) ? value / 1000
             : (from == 11 && to == 13) ? value / 1000000
             : (from == 11 && to == 14) ? value / 1.0000E+9
             : (from == 11 && to == 15) ? value / 1.0000E+12
             : (from == 11 && to == 16) ? value / 1.0000E+15
             : (from == 11 && to == 17) ? value / 1.0000E+18
             : (from == 11 && to == 18) ? value / 1.0000E+21
             : (from == 11 && to == 19) ? value / 1.0000E+24

             : (from == 12 && to == 1)  ? value * 8000
             : (from == 12 && to == 2)  ? value * 8
             : (from == 12 && to == 3)  ? value / 125
             : (from == 12 && to == 4)  ? value / 125000
             : (from == 12 && to == 5)  ? value / 1.2500E+8
             : (from == 12 && to == 6)  ? value / 1.2500E+11
             : (from == 12 && to == 7)  ? value / 1.2500E+14
             : (from == 12 && to == 8)  ? value / 1.2500E+17
             : (from == 12 && to == 9)  ? value / 1.2500E+20
             : (from == 12 && to == 10) ? value * 2000
             : (from == 12 && to == 11) ? value * 1000
             : (from == 12 && to == 12) ? value * 1
             : (from == 12 && to == 13) ? value / 1000
             : (from == 12 && to == 14) ? value / 1000000
             : (from == 12 && to == 15) ? value / 1.0000E+9
             : (from == 12 && to == 16) ? value / 1.0000E+12
             : (from == 12 && to == 17) ? value / 1.0000E+15
             : (from == 12 && to == 18) ? value / 1.0000E+18
             : (from == 12 && to == 19) ? value / 1.0000E+21

             : (from == 13 && to == 1)  ? value * 8000000
             : (from == 13 && to == 2)  ? value * 8000
             : (from == 13 && to == 3)  ? value * 8
             : (from == 13 && to == 4)  ? value / 125
             : (from == 13 && to == 5)  ? value / 125000
             : (from == 13 && to == 6)  ? value / 1.2500E+8
             : (from == 13 && to == 7)  ? value / 1.2500E+11
             : (from == 13 && to == 8)  ? value / 1.2500E+14
             : (from == 13 && to == 9)  ? value / 1.2500E+17
             : (from == 13 && to == 10) ? value * 2000000
             : (from == 13 && to == 11) ? value * 1000000
             : (from == 13 && to == 12) ? value * 1000
             : (from == 13 && to == 13) ? value * 1
             : (from == 13 && to == 14) ? value / 1000
             : (from == 13 && to == 15) ? value / 1000000
             : (from == 13 && to == 16) ? value / 1.0000E+9
             : (from == 13 && to == 17) ? value / 1.0000E+12
             : (from == 13 && to == 18) ? value / 1.0000E+15
             : (from == 13 && to == 19) ? value / 1.0000E+18

             : (from == 14 && to == 1)  ? value * 8.0000E+9
             : (from == 14 && to == 2)  ? value * 8000000
             : (from == 14 && to == 3)  ? value * 8000
             : (from == 14 && to == 4)  ? value * 8
             : (from == 14 && to == 5)  ? value / 125
             : (from == 14 && to == 6)  ? value / 125000
             : (from == 14 && to == 7)  ? value / 1.2500E+8
             : (from == 14 && to == 8)  ? value / 1.2500E+11
             : (from == 14 && to == 9)  ? value / 1.2500E+14
             : (from == 14 && to == 10) ? value * 2.0000E+9
             : (from == 14 && to == 11) ? value * 1.0000E+9
             : (from == 14 && to == 12) ? value * 1000000
             : (from == 14 && to == 13) ? value * 1000
             : (from == 14 && to == 14) ? value * 1
             : (from == 14 && to == 15) ? value / 1000
             : (from == 14 && to == 16) ? value / 1000000
             : (from == 14 && to == 17) ? value / 1.0000E+9
             : (from == 14 && to == 18) ? value / 1.0000E+11
             : (from == 14 && to == 19) ? value / 1.0000E+15

             : (from == 15 && to == 1)  ? value * 8.0000E+12
             : (from == 15 && to == 2)  ? value * 8.0000E+9
             : (from == 15 && to == 3)  ? value * 8000000
             : (from == 15 && to == 4)  ? value * 8000
             : (from == 15 && to == 5)  ? value * 8
             : (from == 15 && to == 6)  ? value / 125
             : (from == 15 && to == 7)  ? value / 125000
             : (from == 15 && to == 8)  ? value / 1.2500E+8
             : (from == 15 && to == 9)  ? value / 1.2500E+11
             : (from == 15 && to == 10) ? value * 2.0000E+12
             : (from == 15 && to == 11) ? value * 1.0000E+12
             : (from == 15 && to == 12) ? value * 1.0000E+9
             : (from == 15 && to == 13) ? value * 1000000
             : (from == 15 && to == 14) ? value * 1000
             : (from == 15 && to == 15) ? value * 1
             : (from == 15 && to == 16) ? value / 1000
             : (from == 15 && to == 17) ? value / 1000000
             : (from == 15 && to == 18) ? value / 1.0000E+9
             : (from == 15 && to == 19) ? value / 1.0000E+12

             : (from == 16 && to == 1)  ? value * 8.0000E+15
             : (from == 16 && to == 2)  ? value * 8.0000E+12
             : (from == 16 && to == 3)  ? value * 8.0000E+9
             : (from == 16 && to == 4)  ? value * 8000000
             : (from == 16 && to == 5)  ? value * 8000
             : (from == 16 && to == 6)  ? value * 8
             : (from == 16 && to == 7)  ? value / 125
             : (from == 16 && to == 8)  ? value / 125000
             : (from == 16 && to == 9)  ? value / 1.2500E+8
             : (from == 16 && to == 10) ? value * 2.0000E+15
             : (from == 16 && to == 11) ? value * 1.0000E+15
             : (from == 16 && to == 12) ? value * 1.0000E+12
             : (from == 16 && to == 13) ? value * 1.0000E+9
             : (from == 16 && to == 14) ? value * 1000000
             : (from == 16 && to == 15) ? value * 1000
             : (from == 16 && to == 16) ? value * 1
             : (from == 16 && to == 17) ? value / 1000
             : (from == 16 && to == 18) ? value / 1000000
             : (from == 16 && to == 19) ? value / 1.0000E+9

             : (from == 17 && to == 1)  ? value * 8.0000E+18
             : (from == 17 && to == 2)  ? value * 8.0000E+15
             : (from == 17 && to == 3)  ? value * 8.0000E+12
             : (from == 17 && to == 4)  ? value * 8.0000E+9
             : (from == 17 && to == 5)  ? value * 8000000
             : (from == 17 && to == 6)  ? value * 8000
             : (from == 17 && to == 7)  ? value * 8
             : (from == 17 && to == 8)  ? value / 125
             : (from == 17 && to == 9)  ? value / 125000
             : (from == 17 && to == 10) ? value * 2.0000E+18
             : (from == 17 && to == 11) ? value * 1.0000E+18
             : (from == 17 && to == 12) ? value * 1.0000E+15
             : (from == 17 && to == 13) ? value * 1.0000E+12
             : (from == 17 && to == 14) ? value * 1.0000E+9
             : (from == 17 && to == 15) ? value * 1000000
             : (from == 17 && to == 16) ? value * 1000
             : (from == 17 && to == 17) ? value * 1
             : (from == 17 && to == 18) ? value / 1000
             : (from == 17 && to == 19) ? value / 1000000

             : (from == 18 && to == 1)  ? value * 8.0000E+21
             : (from == 18 && to == 2)  ? value * 8.0000E+18
             : (from == 18 && to == 3)  ? value * 8.0000E+15
             : (from == 18 && to == 4)  ? value * 8.0000E+12
             : (from == 18 && to == 5)  ? value * 8.0000E+9
             : (from == 18 && to == 6)  ? value * 8000000
             : (from == 18 && to == 7)  ? value * 8000
             : (from == 18 && to == 8)  ? value * 8
             : (from == 18 && to == 9)  ? value / 125
             : (from == 18 && to == 10) ? value * 2.0000E+21
             : (from == 18 && to == 11) ? value * 1.0000E+21
             : (from == 18 && to == 12) ? value * 1.0000E+18
             : (from == 18 && to == 13) ? value * 1.0000E+15
             : (from == 18 && to == 14) ? value * 1.0000E+12
             : (from == 18 && to == 15) ? value * 1.0000E+9
             : (from == 18 && to == 16) ? value * 1000000
             : (from == 18 && to == 17) ? value * 1000
             : (from == 18 && to == 18) ? value * 1
             : (from == 18 && to == 19) ? value / 1000

             : (from == 19 && to == 1)  ? value * 8.0000E+24
             : (from == 19 && to == 2)  ? value * 8.0000E+21
             : (from == 19 && to == 3)  ? value * 8.0000E+18
             : (from == 19 && to == 4)  ? value * 8.0000E+15
             : (from == 19 && to == 5)  ? value * 8.0000E+12
             : (from == 19 && to == 6)  ? value * 8.0000E+9
             : (from == 19 && to == 7)  ? value * 8000000
             : (from == 19 && to == 8)  ? value * 8000
             : (from == 19 && to == 9)  ? value * 8
             : (from == 19 && to == 10) ? value * 2.0000E+24
             : (from == 19 && to == 11) ? value * 1.0000E+24
             : (from == 19 && to == 12) ? value * 1.0000E+21
             : (from == 19 && to == 13) ? value * 1.0000E+18
             : (from == 19 && to == 14) ? value * 1.0000E+15
             : (from == 19 && to == 15) ? value * 1.0000E+12
             : (from == 19 && to == 16) ? value * 1.0000E+9
             : (from == 19 && to == 17) ? value * 1000000
             : (from == 19 && to == 18) ? value * 1000
             : (from == 19 && to == 19) ? value * 1
                                              : value * 0;
  }
  return result;
}

void Conv2::temperature() {
  unit = {"Celcius (C)", "Fahrenheit (F)", "Kelvin (K)", "Rankine (R)"};
  std::cout << "Press enter.";
  while (true) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    glb::i = 1;
    LOG_CLEAR;
    std::cout << "\tCommands:"
                 "\n'e' Back to main menu\n\n";

    for (auto a : unit)
      std::cout << "[" << glb::i++ << "] " << a << "\n";

    glb::i = 0;
    for (auto a : unit)
      std::cout << "\n" << a << ": " << results.at(glb::i++);

    std::cout << "\n\nFrom: ";
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e") {
      CONV_CLEAR;
    } else {
      try {
        iConv1 = std::stoi(glb::strRespond1);
      } catch (...) {
        continue;
      }
    }
    if (iConv1 < 1 || iConv1 > 4)
      continue;

    std::cout << "Value of " << unit.at(--iConv1) << ": ";
    std::cin >> glb::strRespond1;
    std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
                   glb::strRespond1.begin(), ::tolower);
    if (glb::strRespond1 == "e") {
      CONV_CLEAR;
    } else {
      try {
        value = std::stoi(glb::strRespond1);
      } catch (...) {
        continue;
      }
    }

    ++iConv1;
    if (iConv1 == 1) {
      results.at(0) = (value * 1);
      results.at(1) = ((value * 1.8) + 32);
      results.at(2) = (value + 273.15);
      results.at(3) = ((value * 1.8) + 491.67);
    } else if (iConv1 == 2) {
      results.at(0) = ((value - 32) * 0.555556);
      results.at(1) = (value * 1);
      results.at(2) = ((value + 459.67) * 0.555556);
      results.at(3) = (value + 459.67);
    } else if (iConv1 == 3) {
      results.at(0) = (value - 273.15);
      results.at(1) = ((value * 1.8) - 459.67);
      results.at(2) = (value * 1);
      results.at(3) = (value * 1.8);
    } else if (iConv1 == 4) {
      results.at(0) = (value * 0.555556) - 273.15;
      results.at(1) = (value - 459.67);
      results.at(2) = (value * 0.555556);
      results.at(3) = (value * 1);
    } else {
      results.at(0) = 0;
      results.at(1) = 0;
      results.at(2) = 0;
      results.at(3) = 0;
    }
  }
}