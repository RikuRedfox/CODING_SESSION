#include <iostream>
#include <cmath>

int main(){

    double weight(7.7);

    std::cout << "Weight rounded to floor is: " << floor(weight) << std::endl;
    std::cout << "Weight rounded to ceil is: " << ceil(weight) << std::endl;

    double savings(-3000);

    std::cout << "Abs of weight is: " << abs(weight) << std::endl;
    std::cout << "Abs of savings is: " << abs(savings) << std::endl;

    // exp: f(x) = e^x, where e = 2.71828.
    double exponential = exp(10);
    std::cout << "The exponential of 10 is: " << exponential << std::endl;

    std::cout << "3^4 is: " << pow(3, 4) << std::endl;
    std::cout << "9^3 is: " << pow(9, 3) << std::endl;

    // log: reverse function of pow. e^x. e = 2.71828.
    std::cout << "Log; to get 59.59, you would elevate e to the of: " << log(100) << std::endl;

    // log10, 10^4 = 10000
    std::cout << "To get 1000, you'd need to elevate 10 to the power of : " << log10(10000) << std::endl;

    // sqrt
    std::cout << "The square root of 81 is: " << sqrt(81) << std::endl;

    // round
    std::cout << "3.654 rounded to: " << round(3.654) << std::endl;
    std::cout << "2.5 is rounded to: " << round(2.5) << std::endl;
    std::cout << "2.4 is rounded to: " << round(2.4) << std::endl;

    return 0;
}