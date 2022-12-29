#include <array>
#include <string>
#include <vector>

class Calc {
public:
  class SimpleCalc {
  public:
    void _simple_calc(void);

  private:
    char op;
    long double num1, num2;
    long double t_num = 0;
    int m_num1, m_num2;
    int m_num = 0;
  };

  class BMI {
  public:
    void _bmi(void);

  private:
    int intWeight, intHeight;
    double weightValue, heightValue1, heightValue2;
    std::array<std::string, 2> weight;
    std::array<std::string, 4> height;
  };

  class Discount {
  public:
    void _discount(void);

  private:
    long double origPrice, finalPrice;
    float Percentage;
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
  ~Area() {
    std::cout << "Deconstractor made";
    std::cin.get();
    unit.clear();
  }
  void _area();
};

class Data : public Conv {
public:
  ~Data() {
    std::cout << "Deconstractor made";
    std::cin.get();
    unit.clear();
  }
  void _data();
};