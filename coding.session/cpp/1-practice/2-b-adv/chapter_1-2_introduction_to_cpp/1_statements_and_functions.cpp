#include <iostream>

double added_num(double first_num, double second_num){

    double result = first_num + second_num;
    return result;
}

int main(){

    double num1 {.2}, num2 {.3};
    float float_sum = num1 + num2;
    std::cout << "Float Sum : " << float_sum;
    std::cout << std::endl;

    double sum = added_num(14.2, 5.123);
    std::cout << "Sum : " << sum;

    return 0;
}