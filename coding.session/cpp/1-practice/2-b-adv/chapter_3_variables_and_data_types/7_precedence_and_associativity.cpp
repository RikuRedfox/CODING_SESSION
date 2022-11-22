#include <iostream>

int main(){

    int num1, num2;

    std::cout << "Enter your first number : ";
    std::cin >> num1;
    std::cout << "Enter your second number : ";
    std::cin >> num2;

    int result = num1 + num2;
    int oResult = num1 + num2 + num1;
    std::cout << "Sum of num1 and num2: " << result << std::endl;
    std::cout << "Other sum of num1 and sum2: " << oResult << std::endl;
    std::cout << std::endl;

    result = num1 - num2; 
    oResult = num1 - num2 - num1;
    std::cout << "Sub of num1 and num2: " << result << std::endl;
    std::cout << "Other sub of num1 and sum2: " << oResult << std::endl;
    std::cout << std::endl;

    result = num1 * num2;
    oResult = num1 * num2 * num1;
    std::cout << "Mul of num1 and num2: " << result << std::endl;
    std::cout << "Other mul of num1 and sum2: " << oResult << std::endl;
    std::cout << std::endl;

    result = num1 / num2;
    oResult = num1 / num2 / num1;
    std::cout << "Div of num1 and num2: " << result << std::endl;
    std::cout << "Other div of num1 and sum2: " << oResult << std::endl;
    std::cout << std::endl;

    result = num1 % num2;
    oResult = num1 % num2 % num1;
    std::cout << "Mod of num1 and num2: " << result << std::endl;
    std::cout << "Other mod of num1 and sum2: " << oResult << std::endl;
    std::cout << std::endl;

    std::cout << "\n\t --- Precedence and Associativity --- \n\n";

    // Precedence and Associativity

    int a{2}, b{7}, c{7}, d{5}, e{3}, f{4}, g{5};

    result = a + b * c - d / e + f + g;    // a + (b * c) - (d / e) + f + g
    std::cout << result << std::endl;      // 59 >> multiply and division first before add then sub

    return 0;
}