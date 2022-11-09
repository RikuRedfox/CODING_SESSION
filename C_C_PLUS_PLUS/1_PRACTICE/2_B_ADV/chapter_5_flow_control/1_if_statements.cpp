#include <iostream>

int main(){

    int num1, num2;

    std::cout << "Enter 1st num: ";
    std::cin >> num1;
    std::cout << "Then your 2nd num: ";
    std::cin >> num2;

    if(num1 < num2){
        std::cout << num1 << " is LESS than " << num2 << std::endl;
    } 
    if(num1 == num2) {
        std::cout << num1 << " is EQUAL to " << num2 << std::endl;
    } 
    if(num1 > num2){
        std::cout << num1 << " is GREATER than " << num2 << std::endl;
    }

    return 0;
}