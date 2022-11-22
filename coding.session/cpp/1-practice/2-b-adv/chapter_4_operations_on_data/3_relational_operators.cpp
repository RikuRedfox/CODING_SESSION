#include <iostream>

int main(){

    int num1{66}, num2{};

    printf("\tShow num1: %d", num1);
    printf("\t\tShow num2: %d\n\n", num2);
    printf("\t\tComparing vars.\n\n");

    std::cout << std::boolalpha; 
    // the purpose of parenthesis is not to confuse the compiler
    std::cout << "\t\tnum1 < num2: " << (num1 < num2) << std::endl;
    std::cout << "\t\tnum1 <= num2: " << (num1 <= num2) << std::endl;
    std::cout << "\t\tnum1 > num2: " << (num1 > num2) << std::endl;
    std::cout << "\t\tnum1 >= num2: " << (num1 >= num2) << std::endl;
    std::cout << "\t\tnum1 == num2: " << (num1 == num2) << std::endl;
    std::cout << "\t\tnum1 != num2: " << (num1 != num2) << std::endl;

    return 0;
}