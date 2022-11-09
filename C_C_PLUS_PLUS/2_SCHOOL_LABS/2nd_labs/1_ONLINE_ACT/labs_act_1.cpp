// getting the average of 5 subjects and iidentify if is passed or failed. above 75 is passed below is failed.

#include <iostream>

int main(){

    float in_num1, in_num2, in_num3, in_num4, in_num5;

    std::cout << "Enter your five subject grade : \n";

    std::cout << "1st input : \n>> ";
    std::cin >> in_num1;

    std::cout << "2nd input : \n>> ";
    std::cin >> in_num2;

    std::cout << "3rd input : \n>> ";
    std::cin >> in_num3;

    std::cout << "4th input : \n>> ";
    std::cin >> in_num4;

    std::cout << "5th input : \n>> ";
    std::cin >> in_num5;

    float result { (in_num1 + in_num2 + in_num3 + in_num4 + in_num5) / 5 };

    result >= 75 ? std::cout << result << " Passed!" : std::cout << result << " Failed!";

    return 0;
}