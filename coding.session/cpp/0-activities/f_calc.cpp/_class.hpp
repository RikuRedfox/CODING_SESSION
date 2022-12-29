#include <array>
#include <string>
#include <vector>

class Calc {
public:
  ~Calc() {
    static unsigned short i = 0;
    ++i;
    printf("\nCalc: %i Times have been destoryed.", i);
  }
  class SimpleCalc {
  public:
    ~SimpleCalc() {
      static unsigned short i = 0;
      ++i;
      printf("\nSimCalc: %i Times have been destoryed.", i);
    }
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
    ~BMI() {
      static unsigned short i = 0;
      ++i;
      printf("\nBMI: %i Times have been destoryed.", i);
    }

  private:
    int intWeight, intHeight;
    double weightValue, heightValue1, heightValue2;
    std::array<std::string, 2> weight;
    std::array<std::string, 4> height;
  };

  class Discount {
  public:
    void _discount(void);
    ~Discount() {
      static unsigned short i = 0;
      ++i;
      printf("\nDis: %i Times have been destoryed.", i);
    }

  private:
    long double origPrice, finalPrice;
    float Percentage;
  };
};

class Conv {
protected:
  int intRespond1, intRespond2;
  long double result, value;
  std::vector<std::string> unit;

public:
  Conv() { unit.clear(); }
  ~Conv() {
    static unsigned short i = 0;
    ++i;
    printf("\nConv: %i Times have been destoryed.", i);
  }
};

class Area : protected Conv {
public:
  void _area(void);
};

class Data : protected Conv {
public:
  void _data(void);
};