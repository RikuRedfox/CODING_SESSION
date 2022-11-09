#include <iostream>

float a, b;

void inp()
{
    std::cout << "This is a basic calculator." << std::endl;
    std::cout << "Enter a first number: ";
    std::cin >> a;
    std::cout << "Enter a second number: ";
    std::cin >> b;
}

void sum()
{
    std::cout << "The sum of the two numbers is: " << (a + b) << std::endl;
}

void sub()
{
    std::cout << "The difference of the two numbers is: " << (a - b) << std::endl;
}

void mul()
{
    std::cout << "The product of the two numbers is: " << (a * b) << std::endl;
}
void div()
{
    std::cout << "The quotient of the two numbers is: " << (a / b) << std::endl;
}
int main()
{

        inp();

        std::cout << std::endl;
        sum();
        sub();
        mul();
        div();

        char dec;
        std::cout << "Do you want to retry again? | [Y] YES [N] NO\n>> ";
        std::cin >> dec;
        if (dec == 'Y' || dec == 'y')
        {
            return main();
        }
        else if (dec == 'N' || dec == 'n')
        {
            return 0;
        }
        else
        {
            std::cout << "Wrong inputs, program terminated." << std::endl;
            return -1;
        }

    return 0;
}