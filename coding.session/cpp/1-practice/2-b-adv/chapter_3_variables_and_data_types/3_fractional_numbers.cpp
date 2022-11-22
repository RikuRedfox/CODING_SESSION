#include <iostream>
#include <iomanip>

int main(){

    float num1{1.123456789012345678901234567890f};       // 7
    double num2{1.123456789012345678901234567890};       // 15
    long double num3{1.123456789012345678901234567890L}; // 17?
    // float num4 {123456789}; compiler error
    float num4{192400023.0f};
    // Scientific notation
    double num5{1.1234567e9};
    double num6{1.123e9}; // multi 9
    double num7{0.000000000000003456};
    double num8{1.234e-11}; // multi -11

    std::cout << std::setprecision(20);
    std::cout << "num 1: " << num1 << std::endl;
    std::cout << "num 2: " << num2 << std::endl;
    std::cout << "num 3: " << num3 << std::endl;
    std::cout << "num 4: " << num4 << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "num 5: " << num5 << std::endl;
    std::cout << "num 6: " << num6 << std::endl;
    std::cout << "num 7: " << num7 << std::endl;
    std::cout << "num 8: " << num8 << std::endl;
    std::cout << std::endl;

    // Infinity and NaN

    double num9{2.2}, num10{}, num11{};

    double result{num9 / num10};

    std::cout << num9 << "/" << num10 << " yields " << result << std::endl;
    std::cout << result << " + " << num11 << " yields " << result + num11 << std::endl;

    result = num10 / num11;

    std::cout << result << std::endl;

    return 0;
}