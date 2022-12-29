#include <array>
#include <string>
#include <vector>

class SimpleCalc {
private:
  // Operator
  char op;
  // Add Sub Mul Div
  long double num1, num2;
  long double t_num = 0;
  // Used in Modulo
  int m_num1, m_num2;
  int m_num = 0;

public:
  void simpleCalc();
};

class BMI {
private:
  int intWeight, intHeight;
  float weightValue, heightValue1, heightValue2;
  std::array<std::string, 2> weight;
  std::array<std::string, 4> height;

public:
  void bmi();
};

class Discount {
private:
  float origPrice, Percentage;

public:
  void discount();
};

class Conv {
private:
  int iConv1, iConv2;
  long double result, value;
  std::vector<std::string> unit;

public:
  void area();
  void data();
};