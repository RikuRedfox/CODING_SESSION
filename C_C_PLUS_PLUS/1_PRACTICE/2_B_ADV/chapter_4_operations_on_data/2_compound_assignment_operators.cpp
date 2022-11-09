#include <iostream>

int main(){

    int number{6};

    std::cout << "The original number is : " << number << std::endl;

    number += 9;
    std::cout << "\nThe value after +=9 : " << number << std::endl;

    number -= 9;
    std::cout << "\nThe value after -=9 : " << number << std::endl;

    number *= 9;
    std::cout << "\nThe value after *=9 : " << number << std::endl;

    number /= 9;
    std::cout << "\nThe value after /=9 : " << number << std::endl;

    number %= 9;
    std::cout << "\nThe value after %=9 : " << number << std::endl;

    return 0;
}