#include <array>
#include <string>
#include <vector>


class Calc {
public:
  class SimpleCalc {
  public:
    inline void _simple_calc();

  private:
    char op;
    long double num1, num2;
    long double t_num = 0;
    int m_num1, m_num2;
    int m_num = 0;
  };

  class BMI {
  public:
    inline void _bmi();

  private:
    int intWeight, intHeight;
    double weightValue, heightValue1, heightValue2;
    std::array<std::string, 2> weight;
    std::array<std::string, 4> height;
  };
};

class Conv {
public:
  int intRespond1, intRespond2;
  long double result, value;
  std::vector<std::string> unit;
};

class Area : public Conv {
public:
  inline void _area(void);
};

class Data : public Conv {
public:
  inline void _data();
};