#include <iostream>

int main(){

    // Postfix "after";

    int value{5};

    // value++; // value = value + 1
    std::cout << "The value is: " << value++ << std::endl;

    value = 5;

    // value--; // value = value - 1
    std::cout << "The value is: " << value-- << std::endl;

    // Prefix before; increment/decrement right away.

    int number{5};

    // ++number;
    std::cout << "The number is: " << ++number << std::endl;

    number = 5;

    // --number;
    std::cout << "The number is: " << --number << std::endl;


    return 0;
}