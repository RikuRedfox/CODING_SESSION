#pragma once
#include <array>
#include <string>
#include <vector>

#define CREATED                                                                \
  static unsigned short i = 0;                                                 \
  ++i;                                                                         \
  printf("Created: %i Times", i);                                              \
  std::cin.get();

#define DESTROYED                                                              \
  static unsigned short i = 0;                                                 \
  ++i;                                                                         \
  printf("Destroyed: %i Times", i);                                            \
  std::cin.get();

/* In the main cpp file, there are variables called strRespond 1 and 2 (at
 * global scope) that handle the user input. The string can be used to exit the
 * function or program once the user types "e" in the console; otherwise, the
 * string should be an int or float to type cast it. That's why each class has a
 * private variable to access it by function (public in each class). In the
 * private variable, the type casting will be done inside the function,
 * converting the string to an int or float. If an error occurs, the try-catch
 * will handle it. 
 */

// Each Class have a Constructor that will set the member variables to default
// once the Class called in the main file.

// I just realize that the global variable are bad, so I create a namespace for
// that still can be use globally
namespace glb {
std::string strRespond1, strRespond2;
unsigned short i;
} // namespace glb

class SimpleCalc {
public:
  SimpleCalc() {
    op = ' ';
    num1 = 0.;
    num2 = 0.;
    t_num = 0.;
    m_num1 = 0;
    m_num2 = 0;
    m_num = 0;

    // printf("SimpleCalc ");
    // CREATED;
  }
  // ~SimpleCalc() {
  //   printf("SimpleCalc ");
  //   DESTROYED;
  // }

private:
  // Operator
  char op;
  // Add Sub Mul Div
  long double num1, num2;
  long double t_num;
  // Used in Modulo
  int m_num1, m_num2;
  int m_num;

public:
  void simpleCalc();
};

class BMI {
public:
  BMI() {
    intWeight = 0;
    intHeight = 0;
    weightValue = 0.0;
    heightValue1 = 0.0;
    heightValue2 = 0.0;

    // printf("BMI ");
    // CREATED;
  }

  // ~BMI() {
  //   printf("BMI ");
  //   DESTROYED;
  // }

private:
  unsigned int intWeight, intHeight;
  float weightValue, heightValue1, heightValue2;
  std::array<std::string, 2> weight;
  std::array<std::string, 4> height;

public:
  void bmi();
};

class Discount {
public:
  Discount() {
    origPrice = 0.0;
    Percentage = 0.0;

    // printf("Discount ");
    // CREATED;
  }

  // ~Discount() {
  //   printf("Discount ");
  //   DESTROYED;
  // }

private:
  float origPrice, Percentage;

public:
  void discount();
};

class Conv1 {
public:
  // Conv1() {
  //   printf("Conv ");
  //   CREATED;
  // }

  // ~Conv1() {
  //   printf("Conv ");
  //   DESTROYED;
  // }

  inline void reset() {
    iConv1 = 0;
    iConv2 = 0;
    result = 0.0;
    value = 0.0;
    unit.clear();
  }

protected:
  unsigned short iConv1, iConv2;
  long double result, value;
  std::vector<std::string> unit;

public:
  void area();
  void data();
};

class Conv2 : protected Conv1 {
public:
  // Conv2() {
  //   printf("Temperature ");
  //   CREATED;
  // }

  // ~Conv2() {
  //   printf("Temperature ");
  //   DESTROYED;
  // }
  inline void reset() {
    results = {0., 0., 0., 0.};
  }

private:
  std::array<long double, 4> results;

public:
  void temperature();
  // void numSystem();
};