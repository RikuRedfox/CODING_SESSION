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

void mainMenu();

int main() {
#if RELEASE == 1 // RELEASE
  mainMenu();
#else // DEBUGGING
  // NumSystem numSystem;
  // numSystem.numSystem();
#endif
  return 0;
}
// Acting like a main func
void mainMenu() {
  SimpleCalc *simplecalc = new SimpleCalc;
  BMI *bmi = new BMI;
  Discount *discount = new Discount;
  Conv *conv = new Conv;
  Temperature *temperature = new Temperature;
  // NumSystem *numSystem = new NumSystem;

  // std::unique_ptr<SimpleCalc> simplecalc = std::make_unique<SimpleCalc>();
  // std::unique_ptr<BMI> bmi = std::make_unique<BMI>();
  // std::unique_ptr<Discount> discount = std::make_unique<Discount>();
  // std::unique_ptr<Conv> conv = std::make_unique<Conv>();
  // std::unique_ptr<Temperature> temperature = std::make_unique<Temperature>();
  // // std::unique_ptr<NumSystem> numSystem = std::make_unique<NumSystem>();

  std::cout << "\n" << sizeof(*simplecalc);
  std::cout << "\n" << sizeof(*bmi);
  std::cout << "\n" << sizeof(*discount);
  std::cout << "\n" << sizeof(*conv);
  std::cout << "\n" << sizeof(*temperature);

  std::cin.get();

  unsigned short iRespond;
  std::array<std::string, 12> choice{
      "Simple Calculator",      "Calculator: BMI",
      "Calculator: Discount",   "Converter: Area",
      "Converter: Data",        "Converter: Length [ONG]",
      "Converter: Mass [ONG]",  "Converter: Numerical System [ERR]",
      "Converter: Speed [ONG]", "Converter: Temperature",
      "Converter: Time [ONG]",  "Converter: Volume [ONG]"};

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
      // delete simplecalc;
      // delete bmi;
      // delete discount;
      // delete conv;
      // delete temperature;
      // delete numSystem;
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
      delete conv;
      delete temperature;
      // delete numSystem;
      simplecalc->simpleCalc();
    } else if (iRespond == 2) {
      delete simplecalc;
      //   delete bmi;
      delete discount;
      delete conv;
      delete temperature;
      // delete numSystem;
      bmi->bmi();
    } else if (iRespond == 3) {
      delete simplecalc;
      delete bmi;
      // delete discount;
      delete conv;
      delete temperature;
      // delete numSystem;
      discount->discount();
    } else if (iRespond == 4) {
      delete simplecalc;
      delete bmi;
      delete discount;
      // delete conv;
      delete temperature;
      // delete numSystem;
      conv->area();
    } else if (iRespond == 5) {
      delete simplecalc;
      delete bmi;
      delete discount;
      //   delete conv;
      delete temperature;
      // delete numSystem;
      conv->data();
    } else if (iRespond == 6) {
      continue;
    } else if (iRespond == 7) {
      continue;
    } else if (iRespond == 8) {
      // delete simplecalc;
      // delete bmi;
      // delete discount;
      // delete conv;
      // delete temperature;
      // delete numSystem;
      // numSystem->numSystem();
      continue;
    } else if (iRespond == 9) {
      continue;
    } else if (iRespond == 10) {
      delete simplecalc;
      delete bmi;
      delete discount;
      delete conv;
      // delete temperature;
      // delete numSystem;
      temperature->temperature();
    } else if (iRespond == 11) {
      continue;
    } else if (iRespond == 12) {
      continue;
    } else {
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

void Conv::area() {
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

    std::cout << "Value of " << unit.at(--iConv1) << ": ";
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

    ++iConv1; // at line 554 there is an decrement happening

    /* this area of code base is:
    if(n1 == n2){
      if(n1 == n2)
      else if(n1 == n2)
      else
    } else */

    result = (iConv1 == 1)    ? ((iConv2 == 2)    ? value / 144
                                 : (iConv2 == 3)  ? value / 1296
                                 : (iConv2 == 4)  ? value / 4.0145E+9
                                 : (iConv2 == 5)  ? value / 6.2726E+6
                                 : (iConv2 == 6)  ? value / 1.5500E+7
                                 : (iConv2 == 7)  ? value * 645.16
                                 : (iConv2 == 8)  ? value * 6.4516
                                 : (iConv2 == 9)  ? value / 1550.0031
                                 : (iConv2 == 10) ? value / 1.5500E+9
                                                  : value * 1) // if n1 == n2
             : (iConv1 == 2)  ? ((iConv2 == 1)    ? value * 144
                                 : (iConv2 == 3)  ? value / 9
                                 : (iConv2 == 4)  ? value / 2.7878E+7
                                 : (iConv2 == 5)  ? value / 43560
                                 : (iConv2 == 6)  ? value / 107639.104
                                 : (iConv2 == 7)  ? value * 92903.04
                                 : (iConv2 == 8)  ? value * 929.0304
                                 : (iConv2 == 9)  ? value / 10.7639104
                                 : (iConv2 == 10) ? value / 1.0764E+7
                                                  : value * 1) // if n1 == n2
             : (iConv1 == 3)  ? ((iConv2 == 1)    ? value * 1296
                                 : (iConv2 == 2)  ? value * 9
                                 : (iConv2 == 4)  ? value / 3.0976E+6
                                 : (iConv2 == 5)  ? value / 4840
                                 : (iConv2 == 6)  ? value / 11959.9005
                                 : (iConv2 == 7)  ? value * 836127.36
                                 : (iConv2 == 8)  ? value * 8361.2736
                                 : (iConv2 == 9)  ? value / 1.19599005
                                 : (iConv2 == 10) ? value / 1.1960E+6
                                                  : value * 1) // if n1 == n2
             : (iConv1 == 4)  ? ((iConv2 == 1)    ? value * 4.0145E+9
                                 : (iConv2 == 2)  ? value * 2.7878E+7
                                 : (iConv2 == 3)  ? value * 3097600
                                 : (iConv2 == 5)  ? value / 3.0976E+6
                                 : (iConv2 == 6)  ? value / 11959.9005
                                 : (iConv2 == 7)  ? value * 836127.36
                                 : (iConv2 == 8)  ? value * 8361.2736
                                 : (iConv2 == 9)  ? value / 1.19599005
                                 : (iConv2 == 10) ? value / 1.1960E+6
                                                  : value * 1) // if n1 == n2
             : (iConv1 == 5)  ? ((iConv2 == 1)    ? value * 6272640
                                 : (iConv2 == 2)  ? value * 43560
                                 : (iConv2 == 3)  ? value * 4840
                                 : (iConv2 == 4)  ? value / 640
                                 : (iConv2 == 6)  ? value / 2.47105381
                                 : (iConv2 == 7)  ? value * 4.0469E+9
                                 : (iConv2 == 8)  ? value * 4.0469E+7
                                 : (iConv2 == 9)  ? value * 4046.85642
                                 : (iConv2 == 10) ? value / 247.105381
                                                  : value * 1) // if n1 == n2
             : (iConv1 == 6)  ? ((iConv2 == 1)    ? value * 1.5500E+7
                                 : (iConv2 == 2)  ? value * 107639.104
                                 : (iConv2 == 3)  ? value * 11959.9005
                                 : (iConv2 == 4)  ? value / 258.998811
                                 : (iConv2 == 5)  ? value * 2.47105381
                                 : (iConv2 == 7)  ? value * 1.0000E+10
                                 : (iConv2 == 8)  ? value * 100000000
                                 : (iConv2 == 9)  ? value * 10000
                                 : (iConv2 == 10) ? value / 100
                                                  : value * 1) // if n1 == n2
             : (iConv1 == 7)  ? ((iConv2 == 1)    ? value / 645.16
                                 : (iConv2 == 2)  ? value / 92903.04
                                 : (iConv2 == 3)  ? value / 836127.36
                                 : (iConv2 == 4)  ? value / 2.5900E+12
                                 : (iConv2 == 5)  ? value / 4.0469E+9
                                 : (iConv2 == 6)  ? value / 4.0469E+9
                                 : (iConv2 == 8)  ? value / 100
                                 : (iConv2 == 9)  ? value / 1000000
                                 : (iConv2 == 10) ? value / 1.0000E+12
                                                  : value * 1) // if n1 == n2
             : (iConv1 == 8)  ? ((iConv2 == 1)    ? value / 6.4516
                                 : (iConv2 == 2)  ? value / 929.0304
                                 : (iConv2 == 3)  ? value / 8361.2736
                                 : (iConv2 == 4)  ? value / 2.5900E+10
                                 : (iConv2 == 5)  ? value / 4.0469E+7
                                 : (iConv2 == 6)  ? value / 100000000
                                 : (iConv2 == 7)  ? value * 100
                                 : (iConv2 == 9)  ? value / 10000
                                 : (iConv2 == 10) ? value / 1.0000E+10
                                                  : value * 1) // if n1 == n2
             : (iConv1 == 9)  ? ((iConv2 == 1)    ? value * 1550.0031
                                 : (iConv2 == 2)  ? value * 10.7639104
                                 : (iConv2 == 3)  ? value * 1.19599005
                                 : (iConv2 == 4)  ? value / 2.5900E+6
                                 : (iConv2 == 5)  ? value / 4046.85642
                                 : (iConv2 == 6)  ? value / 10000
                                 : (iConv2 == 7)  ? value * 1000000
                                 : (iConv2 == 8)  ? value * 10000
                                 : (iConv2 == 10) ? value / 1000000
                                                  : value * 1) // if n1 == n2
             : (iConv1 == 10) ? ((iConv2 == 1)   ? value * 1.5500E+9
                                 : (iConv2 == 2) ? value * 1.0764E+7
                                 : (iConv2 == 3) ? value * 1.1960E+6
                                 : (iConv2 == 4) ? value / 2.58998811
                                 : (iConv2 == 5) ? value * 247.105381
                                 : (iConv2 == 6) ? value * 100
                                 : (iConv2 == 7) ? value * 1.0000E+12
                                 : (iConv2 == 8) ? value * 1.0000E+10
                                 : (iConv2 == 9) ? value * 1000000
                                                 : value * 1) // if n1 == n2
                              : value * 0;

    std::cout << "\nResult: " << result << " " << unit.at(--iConv2)
              << "\n\n(Press Enter to continue)";
    std::cin.get();
  }
}

void Conv::data() {
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

    ++iConv1; // decrement at line 735
    /* this area of code base is:
    if (n1 == n2)
    else if (n1 == n2)
    else
    */

    result = (iConv1 == 1 && iConv2 == 1)    ? value * 1
             : (iConv1 == 1 && iConv2 == 2)  ? value / 1000
             : (iConv1 == 1 && iConv2 == 3)  ? value / 1000000
             : (iConv1 == 1 && iConv2 == 4)  ? value / 1.0000e+9
             : (iConv1 == 1 && iConv2 == 5)  ? value / 1.0000e+12
             : (iConv1 == 1 && iConv2 == 6)  ? value / 1.0000e+15
             : (iConv1 == 1 && iConv2 == 7)  ? value / 1.0000e+18
             : (iConv1 == 1 && iConv2 == 8)  ? value / 1.0000e+21
             : (iConv1 == 1 && iConv2 == 9)  ? value / 1.0000e+24
             : (iConv1 == 1 && iConv2 == 10) ? value / 4
             : (iConv1 == 1 && iConv2 == 11) ? value / 8
             : (iConv1 == 1 && iConv2 == 12) ? value / 8000
             : (iConv1 == 1 && iConv2 == 13) ? value / 8000000
             : (iConv1 == 1 && iConv2 == 14) ? value / 8.0000e+9
             : (iConv1 == 1 && iConv2 == 15) ? value / 8.0000e+12
             : (iConv1 == 1 && iConv2 == 16) ? value / 8.0000e+15
             : (iConv1 == 1 && iConv2 == 17) ? value / 8.0000e+18
             : (iConv1 == 1 && iConv2 == 18) ? value / 8.0000e+21
             : (iConv1 == 1 && iConv2 == 19) ? value / 8.0000e+24

             : (iConv1 == 2 && iConv2 == 1)  ? value * 1000
             : (iConv1 == 2 && iConv2 == 2)  ? value * 1
             : (iConv1 == 2 && iConv2 == 3)  ? value / 1000
             : (iConv1 == 2 && iConv2 == 4)  ? value / 1000000
             : (iConv1 == 2 && iConv2 == 5)  ? value / 1.0000e+9
             : (iConv1 == 2 && iConv2 == 6)  ? value / 1.0000e+12
             : (iConv1 == 2 && iConv2 == 7)  ? value / 1.0000e+15
             : (iConv1 == 2 && iConv2 == 8)  ? value / 1.0000e+18
             : (iConv1 == 2 && iConv2 == 9)  ? value / 1.0000e+21
             : (iConv1 == 2 && iConv2 == 10) ? value * 250
             : (iConv1 == 2 && iConv2 == 11) ? value * 125
             : (iConv1 == 2 && iConv2 == 12) ? value / 8
             : (iConv1 == 2 && iConv2 == 13) ? value / 8000
             : (iConv1 == 2 && iConv2 == 14) ? value / 8000000
             : (iConv1 == 2 && iConv2 == 15) ? value / 8.0000e+9
             : (iConv1 == 2 && iConv2 == 16) ? value / 8.0000e+12
             : (iConv1 == 2 && iConv2 == 17) ? value / 8.0000e+15
             : (iConv1 == 2 && iConv2 == 18) ? value / 8.0000e+18
             : (iConv1 == 2 && iConv2 == 19) ? value / 8.0000e+21

             : (iConv1 == 3 && iConv2 == 1)  ? value * 1000000
             : (iConv1 == 3 && iConv2 == 2)  ? value * 1000
             : (iConv1 == 3 && iConv2 == 3)  ? value * 1
             : (iConv1 == 3 && iConv2 == 4)  ? value / 1000
             : (iConv1 == 3 && iConv2 == 5)  ? value / 1000000
             : (iConv1 == 3 && iConv2 == 6)  ? value / 1.0000E+9
             : (iConv1 == 3 && iConv2 == 7)  ? value / 1.0000E+12
             : (iConv1 == 3 && iConv2 == 8)  ? value / 1.0000E+15
             : (iConv1 == 3 && iConv2 == 9)  ? value / 1.0000E+18
             : (iConv1 == 3 && iConv2 == 10) ? value * 250000
             : (iConv1 == 3 && iConv2 == 11) ? value * 125000
             : (iConv1 == 3 && iConv2 == 12) ? value * 125
             : (iConv1 == 3 && iConv2 == 13) ? value / 8
             : (iConv1 == 3 && iConv2 == 14) ? value / 8000
             : (iConv1 == 3 && iConv2 == 15) ? value / 8000000
             : (iConv1 == 3 && iConv2 == 16) ? value / 8.0000E+9
             : (iConv1 == 3 && iConv2 == 17) ? value / 8.0000E+12
             : (iConv1 == 3 && iConv2 == 18) ? value / 8.0000E+15
             : (iConv1 == 3 && iConv2 == 19) ? value / 8.0000E+18

             : (iConv1 == 4 && iConv2 == 1)  ? value * 1.0000E+9
             : (iConv1 == 4 && iConv2 == 2)  ? value * 1000000
             : (iConv1 == 4 && iConv2 == 3)  ? value * 1000
             : (iConv1 == 4 && iConv2 == 4)  ? value * 1
             : (iConv1 == 4 && iConv2 == 5)  ? value / 1000
             : (iConv1 == 4 && iConv2 == 6)  ? value / 1000000
             : (iConv1 == 4 && iConv2 == 7)  ? value / 1.0000E+9
             : (iConv1 == 4 && iConv2 == 8)  ? value / 1.0000E+12
             : (iConv1 == 4 && iConv2 == 9)  ? value / 1.0000E+15
             : (iConv1 == 4 && iConv2 == 10) ? value * 250000000
             : (iConv1 == 4 && iConv2 == 11) ? value * 125000000
             : (iConv1 == 4 && iConv2 == 12) ? value * 125000
             : (iConv1 == 4 && iConv2 == 13) ? value * 125
             : (iConv1 == 4 && iConv2 == 14) ? value / 8
             : (iConv1 == 4 && iConv2 == 15) ? value / 8000
             : (iConv1 == 4 && iConv2 == 16) ? value / 8000000
             : (iConv1 == 4 && iConv2 == 17) ? value / 8.0000E+9
             : (iConv1 == 4 && iConv2 == 18) ? value / 8.0000E+12
             : (iConv1 == 4 && iConv2 == 19) ? value / 8.0000E+15

             : (iConv1 == 5 && iConv2 == 1)  ? value * 1.0000E+12
             : (iConv1 == 5 && iConv2 == 2)  ? value * 1.0000E+9
             : (iConv1 == 5 && iConv2 == 3)  ? value * 1000000
             : (iConv1 == 5 && iConv2 == 4)  ? value * 1000
             : (iConv1 == 5 && iConv2 == 5)  ? value * 1
             : (iConv1 == 5 && iConv2 == 6)  ? value / 1000
             : (iConv1 == 5 && iConv2 == 7)  ? value / 1000000
             : (iConv1 == 5 && iConv2 == 8)  ? value / 1.0000E+9
             : (iConv1 == 5 && iConv2 == 9)  ? value / 1.0000E+12
             : (iConv1 == 5 && iConv2 == 10) ? value * 2.5000E+11
             : (iConv1 == 5 && iConv2 == 11) ? value * 1.2500E+11
             : (iConv1 == 5 && iConv2 == 12) ? value * 125000000
             : (iConv1 == 5 && iConv2 == 13) ? value * 125000
             : (iConv1 == 5 && iConv2 == 14) ? value * 125
             : (iConv1 == 5 && iConv2 == 15) ? value / 8
             : (iConv1 == 5 && iConv2 == 16) ? value / 8000
             : (iConv1 == 5 && iConv2 == 17) ? value / 8000000
             : (iConv1 == 5 && iConv2 == 18) ? value / 8.0000E+9
             : (iConv1 == 5 && iConv2 == 19) ? value / 8.0000E+12

             : (iConv1 == 6 && iConv2 == 1)  ? value * 1.0000E+15
             : (iConv1 == 6 && iConv2 == 2)  ? value * 1.0000E+12
             : (iConv1 == 6 && iConv2 == 3)  ? value * 1.0000E+9
             : (iConv1 == 6 && iConv2 == 4)  ? value * 1000000
             : (iConv1 == 6 && iConv2 == 5)  ? value * 1000
             : (iConv1 == 6 && iConv2 == 6)  ? value * 1
             : (iConv1 == 6 && iConv2 == 7)  ? value / 1000
             : (iConv1 == 6 && iConv2 == 8)  ? value / 1000000
             : (iConv1 == 6 && iConv2 == 9)  ? value / 1.0000E+9
             : (iConv1 == 6 && iConv2 == 10) ? value * 2.5000E+14
             : (iConv1 == 6 && iConv2 == 11) ? value * 1.2500E+14
             : (iConv1 == 6 && iConv2 == 12) ? value * 1.2500E+11
             : (iConv1 == 6 && iConv2 == 13) ? value * 125000000
             : (iConv1 == 6 && iConv2 == 14) ? value * 125000
             : (iConv1 == 6 && iConv2 == 15) ? value * 125
             : (iConv1 == 6 && iConv2 == 16) ? value / 8
             : (iConv1 == 6 && iConv2 == 17) ? value / 8000
             : (iConv1 == 6 && iConv2 == 18) ? value / 8000000
             : (iConv1 == 6 && iConv2 == 19) ? value / 8.0000E+9

             : (iConv1 == 7 && iConv2 == 1)  ? value * 1.0000E+18
             : (iConv1 == 7 && iConv2 == 2)  ? value * 1.0000E+15
             : (iConv1 == 7 && iConv2 == 3)  ? value * 1.0000E+12
             : (iConv1 == 7 && iConv2 == 4)  ? value * 1.0000E+9
             : (iConv1 == 7 && iConv2 == 5)  ? value * 1000000
             : (iConv1 == 7 && iConv2 == 6)  ? value * 1000
             : (iConv1 == 7 && iConv2 == 7)  ? value * 1
             : (iConv1 == 7 && iConv2 == 8)  ? value / 1000
             : (iConv1 == 7 && iConv2 == 9)  ? value / 1000000
             : (iConv1 == 7 && iConv2 == 10) ? value * 2.5000E+17
             : (iConv1 == 7 && iConv2 == 11) ? value * 1.2500E+17
             : (iConv1 == 7 && iConv2 == 12) ? value * 1.2500E+14
             : (iConv1 == 7 && iConv2 == 13) ? value * 1.2500E+11
             : (iConv1 == 7 && iConv2 == 14) ? value * 125000000
             : (iConv1 == 7 && iConv2 == 15) ? value * 125000
             : (iConv1 == 7 && iConv2 == 16) ? value * 125
             : (iConv1 == 7 && iConv2 == 17) ? value * 8
             : (iConv1 == 7 && iConv2 == 18) ? value / 8000
             : (iConv1 == 7 && iConv2 == 19) ? value / 8000000

             : (iConv1 == 8 && iConv2 == 1)  ? value * 1.0000E+21
             : (iConv1 == 8 && iConv2 == 2)  ? value * 1.0000E+18
             : (iConv1 == 8 && iConv2 == 3)  ? value * 1.0000E+15
             : (iConv1 == 8 && iConv2 == 4)  ? value * 1.0000E+12
             : (iConv1 == 8 && iConv2 == 5)  ? value * 1.0000E+9
             : (iConv1 == 8 && iConv2 == 6)  ? value * 1000000
             : (iConv1 == 8 && iConv2 == 7)  ? value * 1000
             : (iConv1 == 8 && iConv2 == 8)  ? value * 1
             : (iConv1 == 8 && iConv2 == 9)  ? value / 1000
             : (iConv1 == 8 && iConv2 == 10) ? value * 2.5000E+20
             : (iConv1 == 8 && iConv2 == 11) ? value * 1.2500E+20
             : (iConv1 == 8 && iConv2 == 12) ? value * 1.2500E+17
             : (iConv1 == 8 && iConv2 == 13) ? value * 1.2500E+14
             : (iConv1 == 8 && iConv2 == 14) ? value * 1.2500E+11
             : (iConv1 == 8 && iConv2 == 15) ? value * 125000000
             : (iConv1 == 8 && iConv2 == 16) ? value * 125000
             : (iConv1 == 8 && iConv2 == 17) ? value * 125
             : (iConv1 == 8 && iConv2 == 18) ? value * 8
             : (iConv1 == 8 && iConv2 == 19) ? value / 8000

             : (iConv1 == 9 && iConv2 == 1)  ? value * 1.0000E+24
             : (iConv1 == 9 && iConv2 == 2)  ? value * 1.0000E+21
             : (iConv1 == 9 && iConv2 == 3)  ? value * 1.0000E+18
             : (iConv1 == 9 && iConv2 == 4)  ? value * 1.0000E+15
             : (iConv1 == 9 && iConv2 == 5)  ? value * 1.0000E+12
             : (iConv1 == 9 && iConv2 == 6)  ? value * 1.0000E+9
             : (iConv1 == 9 && iConv2 == 7)  ? value * 1000000
             : (iConv1 == 9 && iConv2 == 8)  ? value * 1000
             : (iConv1 == 9 && iConv2 == 9)  ? value * 1
             : (iConv1 == 9 && iConv2 == 10) ? value * 2.5000E+23
             : (iConv1 == 9 && iConv2 == 11) ? value * 1.2500E+23
             : (iConv1 == 9 && iConv2 == 12) ? value * 1.2500E+20
             : (iConv1 == 9 && iConv2 == 13) ? value * 1.2500E+17
             : (iConv1 == 9 && iConv2 == 14) ? value * 1.2500E+14
             : (iConv1 == 9 && iConv2 == 15) ? value * 1.2500E+11
             : (iConv1 == 9 && iConv2 == 16) ? value * 125000000
             : (iConv1 == 9 && iConv2 == 17) ? value * 125000
             : (iConv1 == 9 && iConv2 == 18) ? value * 125
             : (iConv1 == 9 && iConv2 == 19) ? value * 8

             : (iConv1 == 10 && iConv2 == 1)  ? value * 4
             : (iConv1 == 10 && iConv2 == 2)  ? value / 250
             : (iConv1 == 10 && iConv2 == 3)  ? value / 250000
             : (iConv1 == 10 && iConv2 == 4)  ? value / 2.5000E+8
             : (iConv1 == 10 && iConv2 == 5)  ? value / 2.5000E+11
             : (iConv1 == 10 && iConv2 == 6)  ? value / 2.5000E+14
             : (iConv1 == 10 && iConv2 == 7)  ? value / 2.5000E+17
             : (iConv1 == 10 && iConv2 == 8)  ? value / 2.5000E+20
             : (iConv1 == 10 && iConv2 == 9)  ? value / 2.5000E+23
             : (iConv1 == 10 && iConv2 == 10) ? value * 1
             : (iConv1 == 10 && iConv2 == 11) ? value / 2
             : (iConv1 == 10 && iConv2 == 12) ? value / 2000
             : (iConv1 == 10 && iConv2 == 13) ? value / 2000000
             : (iConv1 == 10 && iConv2 == 14) ? value / 2.0000E+9
             : (iConv1 == 10 && iConv2 == 15) ? value / 2.0000E+12
             : (iConv1 == 10 && iConv2 == 16) ? value / 2.0000E+15
             : (iConv1 == 10 && iConv2 == 17) ? value / 2.0000E+18
             : (iConv1 == 10 && iConv2 == 18) ? value / 2.0000E+21
             : (iConv1 == 10 && iConv2 == 19) ? value / 2.0000E+24

             : (iConv1 == 11 && iConv2 == 1)  ? value * 8
             : (iConv1 == 11 && iConv2 == 2)  ? value / 125
             : (iConv1 == 11 && iConv2 == 3)  ? value / 125000
             : (iConv1 == 11 && iConv2 == 4)  ? value / 1.2500E+8
             : (iConv1 == 11 && iConv2 == 5)  ? value / 1.2500E+11
             : (iConv1 == 11 && iConv2 == 6)  ? value / 1.2500E+14
             : (iConv1 == 11 && iConv2 == 7)  ? value / 1.2500E+17
             : (iConv1 == 11 && iConv2 == 8)  ? value / 1.2500E+20
             : (iConv1 == 11 && iConv2 == 9)  ? value / 1.2500E+23
             : (iConv1 == 11 && iConv2 == 10) ? value * 2
             : (iConv1 == 11 && iConv2 == 11) ? value * 1
             : (iConv1 == 11 && iConv2 == 12) ? value / 1000
             : (iConv1 == 11 && iConv2 == 13) ? value / 1000000
             : (iConv1 == 11 && iConv2 == 14) ? value / 1.0000E+9
             : (iConv1 == 11 && iConv2 == 15) ? value / 1.0000E+12
             : (iConv1 == 11 && iConv2 == 16) ? value / 1.0000E+15
             : (iConv1 == 11 && iConv2 == 17) ? value / 1.0000E+18
             : (iConv1 == 11 && iConv2 == 18) ? value / 1.0000E+21
             : (iConv1 == 11 && iConv2 == 19) ? value / 1.0000E+24

             : (iConv1 == 12 && iConv2 == 1)  ? value * 8000
             : (iConv1 == 12 && iConv2 == 2)  ? value * 8
             : (iConv1 == 12 && iConv2 == 3)  ? value / 125
             : (iConv1 == 12 && iConv2 == 4)  ? value / 125000
             : (iConv1 == 12 && iConv2 == 5)  ? value / 1.2500E+8
             : (iConv1 == 12 && iConv2 == 6)  ? value / 1.2500E+11
             : (iConv1 == 12 && iConv2 == 7)  ? value / 1.2500E+14
             : (iConv1 == 12 && iConv2 == 8)  ? value / 1.2500E+17
             : (iConv1 == 12 && iConv2 == 9)  ? value / 1.2500E+20
             : (iConv1 == 12 && iConv2 == 10) ? value * 2000
             : (iConv1 == 12 && iConv2 == 11) ? value * 1000
             : (iConv1 == 12 && iConv2 == 12) ? value * 1
             : (iConv1 == 12 && iConv2 == 13) ? value / 1000
             : (iConv1 == 12 && iConv2 == 14) ? value / 1000000
             : (iConv1 == 12 && iConv2 == 15) ? value / 1.0000E+9
             : (iConv1 == 12 && iConv2 == 16) ? value / 1.0000E+12
             : (iConv1 == 12 && iConv2 == 17) ? value / 1.0000E+15
             : (iConv1 == 12 && iConv2 == 18) ? value / 1.0000E+18
             : (iConv1 == 12 && iConv2 == 19) ? value / 1.0000E+21

             : (iConv1 == 13 && iConv2 == 1)  ? value * 8000000
             : (iConv1 == 13 && iConv2 == 2)  ? value * 8000
             : (iConv1 == 13 && iConv2 == 3)  ? value * 8
             : (iConv1 == 13 && iConv2 == 4)  ? value / 125
             : (iConv1 == 13 && iConv2 == 5)  ? value / 125000
             : (iConv1 == 13 && iConv2 == 6)  ? value / 1.2500E+8
             : (iConv1 == 13 && iConv2 == 7)  ? value / 1.2500E+11
             : (iConv1 == 13 && iConv2 == 8)  ? value / 1.2500E+14
             : (iConv1 == 13 && iConv2 == 9)  ? value / 1.2500E+17
             : (iConv1 == 13 && iConv2 == 10) ? value * 2000000
             : (iConv1 == 13 && iConv2 == 11) ? value * 1000000
             : (iConv1 == 13 && iConv2 == 12) ? value * 1000
             : (iConv1 == 13 && iConv2 == 13) ? value * 1
             : (iConv1 == 13 && iConv2 == 14) ? value / 1000
             : (iConv1 == 13 && iConv2 == 15) ? value / 1000000
             : (iConv1 == 13 && iConv2 == 16) ? value / 1.0000E+9
             : (iConv1 == 13 && iConv2 == 17) ? value / 1.0000E+12
             : (iConv1 == 13 && iConv2 == 18) ? value / 1.0000E+15
             : (iConv1 == 13 && iConv2 == 19) ? value / 1.0000E+18

             : (iConv1 == 14 && iConv2 == 1)  ? value * 8.0000E+9
             : (iConv1 == 14 && iConv2 == 2)  ? value * 8000000
             : (iConv1 == 14 && iConv2 == 3)  ? value * 8000
             : (iConv1 == 14 && iConv2 == 4)  ? value * 8
             : (iConv1 == 14 && iConv2 == 5)  ? value / 125
             : (iConv1 == 14 && iConv2 == 6)  ? value / 125000
             : (iConv1 == 14 && iConv2 == 7)  ? value / 1.2500E+8
             : (iConv1 == 14 && iConv2 == 8)  ? value / 1.2500E+11
             : (iConv1 == 14 && iConv2 == 9)  ? value / 1.2500E+14
             : (iConv1 == 14 && iConv2 == 10) ? value * 2.0000E+9
             : (iConv1 == 14 && iConv2 == 11) ? value * 1.0000E+9
             : (iConv1 == 14 && iConv2 == 12) ? value * 1000000
             : (iConv1 == 14 && iConv2 == 13) ? value * 1000
             : (iConv1 == 14 && iConv2 == 14) ? value * 1
             : (iConv1 == 14 && iConv2 == 15) ? value / 1000
             : (iConv1 == 14 && iConv2 == 16) ? value / 1000000
             : (iConv1 == 14 && iConv2 == 17) ? value / 1.0000E+9
             : (iConv1 == 14 && iConv2 == 18) ? value / 1.0000E+11
             : (iConv1 == 14 && iConv2 == 19) ? value / 1.0000E+15

             : (iConv1 == 15 && iConv2 == 1)  ? value * 8.0000E+12
             : (iConv1 == 15 && iConv2 == 2)  ? value * 8.0000E+9
             : (iConv1 == 15 && iConv2 == 3)  ? value * 8000000
             : (iConv1 == 15 && iConv2 == 4)  ? value * 8000
             : (iConv1 == 15 && iConv2 == 5)  ? value * 8
             : (iConv1 == 15 && iConv2 == 6)  ? value / 125
             : (iConv1 == 15 && iConv2 == 7)  ? value / 125000
             : (iConv1 == 15 && iConv2 == 8)  ? value / 1.2500E+8
             : (iConv1 == 15 && iConv2 == 9)  ? value / 1.2500E+11
             : (iConv1 == 15 && iConv2 == 10) ? value * 2.0000E+12
             : (iConv1 == 15 && iConv2 == 11) ? value * 1.0000E+12
             : (iConv1 == 15 && iConv2 == 12) ? value * 1.0000E+9
             : (iConv1 == 15 && iConv2 == 13) ? value * 1000000
             : (iConv1 == 15 && iConv2 == 14) ? value * 1000
             : (iConv1 == 15 && iConv2 == 15) ? value * 1
             : (iConv1 == 15 && iConv2 == 16) ? value / 1000
             : (iConv1 == 15 && iConv2 == 17) ? value / 1000000
             : (iConv1 == 15 && iConv2 == 18) ? value / 1.0000E+9
             : (iConv1 == 15 && iConv2 == 19) ? value / 1.0000E+12

             : (iConv1 == 16 && iConv2 == 1)  ? value * 8.0000E+15
             : (iConv1 == 16 && iConv2 == 2)  ? value * 8.0000E+12
             : (iConv1 == 16 && iConv2 == 3)  ? value * 8.0000E+9
             : (iConv1 == 16 && iConv2 == 4)  ? value * 8000000
             : (iConv1 == 16 && iConv2 == 5)  ? value * 8000
             : (iConv1 == 16 && iConv2 == 6)  ? value * 8
             : (iConv1 == 16 && iConv2 == 7)  ? value / 125
             : (iConv1 == 16 && iConv2 == 8)  ? value / 125000
             : (iConv1 == 16 && iConv2 == 9)  ? value / 1.2500E+8
             : (iConv1 == 16 && iConv2 == 10) ? value * 2.0000E+15
             : (iConv1 == 16 && iConv2 == 11) ? value * 1.0000E+15
             : (iConv1 == 16 && iConv2 == 12) ? value * 1.0000E+12
             : (iConv1 == 16 && iConv2 == 13) ? value * 1.0000E+9
             : (iConv1 == 16 && iConv2 == 14) ? value * 1000000
             : (iConv1 == 16 && iConv2 == 15) ? value * 1000
             : (iConv1 == 16 && iConv2 == 16) ? value * 1
             : (iConv1 == 16 && iConv2 == 17) ? value / 1000
             : (iConv1 == 16 && iConv2 == 18) ? value / 1000000
             : (iConv1 == 16 && iConv2 == 19) ? value / 1.0000E+9

             : (iConv1 == 17 && iConv2 == 1)  ? value * 8.0000E+18
             : (iConv1 == 17 && iConv2 == 2)  ? value * 8.0000E+15
             : (iConv1 == 17 && iConv2 == 3)  ? value * 8.0000E+12
             : (iConv1 == 17 && iConv2 == 4)  ? value * 8.0000E+9
             : (iConv1 == 17 && iConv2 == 5)  ? value * 8000000
             : (iConv1 == 17 && iConv2 == 6)  ? value * 8000
             : (iConv1 == 17 && iConv2 == 7)  ? value * 8
             : (iConv1 == 17 && iConv2 == 8)  ? value / 125
             : (iConv1 == 17 && iConv2 == 9)  ? value / 125000
             : (iConv1 == 17 && iConv2 == 10) ? value * 2.0000E+18
             : (iConv1 == 17 && iConv2 == 11) ? value * 1.0000E+18
             : (iConv1 == 17 && iConv2 == 12) ? value * 1.0000E+15
             : (iConv1 == 17 && iConv2 == 13) ? value * 1.0000E+12
             : (iConv1 == 17 && iConv2 == 14) ? value * 1.0000E+9
             : (iConv1 == 17 && iConv2 == 15) ? value * 1000000
             : (iConv1 == 17 && iConv2 == 16) ? value * 1000
             : (iConv1 == 17 && iConv2 == 17) ? value * 1
             : (iConv1 == 17 && iConv2 == 18) ? value / 1000
             : (iConv1 == 17 && iConv2 == 19) ? value / 1000000

             : (iConv1 == 18 && iConv2 == 1)  ? value * 8.0000E+21
             : (iConv1 == 18 && iConv2 == 2)  ? value * 8.0000E+18
             : (iConv1 == 18 && iConv2 == 3)  ? value * 8.0000E+15
             : (iConv1 == 18 && iConv2 == 4)  ? value * 8.0000E+12
             : (iConv1 == 18 && iConv2 == 5)  ? value * 8.0000E+9
             : (iConv1 == 18 && iConv2 == 6)  ? value * 8000000
             : (iConv1 == 18 && iConv2 == 7)  ? value * 8000
             : (iConv1 == 18 && iConv2 == 8)  ? value * 8
             : (iConv1 == 18 && iConv2 == 9)  ? value / 125
             : (iConv1 == 18 && iConv2 == 10) ? value * 2.0000E+21
             : (iConv1 == 18 && iConv2 == 11) ? value * 1.0000E+21
             : (iConv1 == 18 && iConv2 == 12) ? value * 1.0000E+18
             : (iConv1 == 18 && iConv2 == 13) ? value * 1.0000E+15
             : (iConv1 == 18 && iConv2 == 14) ? value * 1.0000E+12
             : (iConv1 == 18 && iConv2 == 15) ? value * 1.0000E+9
             : (iConv1 == 18 && iConv2 == 16) ? value * 1000000
             : (iConv1 == 18 && iConv2 == 17) ? value * 1000
             : (iConv1 == 18 && iConv2 == 18) ? value * 1
             : (iConv1 == 18 && iConv2 == 19) ? value / 1000

             : (iConv1 == 19 && iConv2 == 1)  ? value * 8.0000E+24
             : (iConv1 == 19 && iConv2 == 2)  ? value * 8.0000E+21
             : (iConv1 == 19 && iConv2 == 3)  ? value * 8.0000E+18
             : (iConv1 == 19 && iConv2 == 4)  ? value * 8.0000E+15
             : (iConv1 == 19 && iConv2 == 5)  ? value * 8.0000E+12
             : (iConv1 == 19 && iConv2 == 6)  ? value * 8.0000E+9
             : (iConv1 == 19 && iConv2 == 7)  ? value * 8000000
             : (iConv1 == 19 && iConv2 == 8)  ? value * 8000
             : (iConv1 == 19 && iConv2 == 9)  ? value * 8
             : (iConv1 == 19 && iConv2 == 10) ? value * 2.0000E+24
             : (iConv1 == 19 && iConv2 == 11) ? value * 1.0000E+24
             : (iConv1 == 19 && iConv2 == 12) ? value * 1.0000E+21
             : (iConv1 == 19 && iConv2 == 13) ? value * 1.0000E+18
             : (iConv1 == 19 && iConv2 == 14) ? value * 1.0000E+15
             : (iConv1 == 19 && iConv2 == 15) ? value * 1.0000E+12
             : (iConv1 == 19 && iConv2 == 16) ? value * 1.0000E+9
             : (iConv1 == 19 && iConv2 == 17) ? value * 1000000
             : (iConv1 == 19 && iConv2 == 18) ? value * 1000
             : (iConv1 == 19 && iConv2 == 19) ? value * 1
                                              : value * 0;

    std::cout << "\nResult: " << result << " " << unit.at(--iConv2)
              << "\n\n(Press enter to continue)";
    std::cin.get();
  }
}

void Temperature::temperature() {
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
      std::cout << "\n" << a << ": " << result.at(glb::i++);

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
      result.at(0) = (value * 1);
      result.at(1) = ((value * 1.8) + 32);
      result.at(2) = (value + 273.15);
      result.at(3) = ((value * 1.8) + 491.67);
    } else if (iConv1 == 2) {
      result.at(0) = ((value - 32) * 0.555556);
      result.at(1) = (value * 1);
      result.at(2) = ((value + 459.67) * 0.555556);
      result.at(3) = (value + 459.67);
    } else if (iConv1 == 3) {
      result.at(0) = (value - 273.15);
      result.at(1) = ((value * 1.8) - 459.67);
      result.at(2) = (value * 1);
      result.at(3) = (value * 1.8);
    } else if (iConv1 == 4) {
      result.at(0) = (value * 0.555556) - 273.15;
      result.at(1) = (value - 459.67);
      result.at(2) = (value * 0.555556);
      result.at(3) = (value * 1);
    } else {
      result.at(0) = 0;
      result.at(1) = 0;
      result.at(2) = 0;
      result.at(3) = 0;
    }
  }
}

// void NumSystem::numSystem() {
//   unit = {"Binary BIN (Working on it.)", "Octal OCT", "Decimal DEC",
//           "Hexadecimal HEX"};
//   std::cout << "Press enter.";
//   while (true) {
//     std::cin.clear();
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//     glb::i = 1;
//     LOG_CLEAR;
//     std::cout << "\tCommands:"
//                  "\n'e' Back to main menu\n\n";

//     for (auto a : unit)
//       std::cout << "[" << glb::i++ << "] " << a << "\n";

//     printf("\n");
//     if (iConv1 == 1) { // bin
//       std::cout << "Binary BIN: " << value << "\n";
//       std::cout << "Octal OCT: " << std::oct << value << "\n";
//       std::cout << "Decimal Dec: " << std::dec << value << "\n";
//       std::cout << "Hexadecimal Hex: " << std::hex << value << "\n";
//     } else if (iConv1 == 2) { // oct
//       std::cout << "Binary BIN: " << value << "\n";
//       std::cout << "Octal OCT: " << std::oct << value << "\n";
//       std::cout << "Decimal Dec: " << std::dec << value << "\n";
//       std::cout << "Hexadecimal Hex: " << std::hex << value << "\n";
//     } else if (iConv1 == 3) { // dec
//       std::cout << "Binary BIN: " << value << "\n";
//       std::cout << "Octal OCT: " << std::oct << value << "\n";
//       std::cout << "Decimal Dec: " << std::dec << value << "\n";
//       std::cout << "Hexadecimal Hex: " << std::hex << value << "\n";
//     } else if (iConv1 == 4) { // hex
//       std::cout << "Binary BIN: " << value << "\n";
//       std::cout << "Octal OCT: " << std::oct << value << "\n";
//       std::cout << "Decimal Dec: " << std::dec << value << "\n";
//       std::cout << "Hexadecimal Hex: " << std::hex << value << "\n";
//     } else {
//       result.at(0) = 0;
//       result.at(1) = 0;
//       result.at(2) = 0;
//       result.at(3) = 0;
//     }

//     std::cout << "\nFrom: ";
//     std::cin >> glb::strRespond1;
//     std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
//                    glb::strRespond1.begin(), ::tolower);
//     if (glb::strRespond1 == "e") {
//       CONV_CLEAR;
//     } else {
//       try {
//         iConv1 = std::stoi(glb::strRespond1);
//       } catch (...) {
//         continue;
//       }
//     }
//     if (iConv1 < 1 || iConv1 > 4)
//       continue;

//     std::cout << "Value of " << unit.at(--iConv1) << ": ";
//     std::cin >> glb::strRespond1;
//     std::transform(glb::strRespond1.begin(), glb::strRespond1.end(),
//                    glb::strRespond1.begin(), ::tolower);
//     if (glb::strRespond1 == "e") {
//       CONV_CLEAR;
//     } else {
//       try {
//         value = std::stoi(glb::strRespond1);
//       } catch (...) {
//         continue;
//       }
//     }
//   }
// }