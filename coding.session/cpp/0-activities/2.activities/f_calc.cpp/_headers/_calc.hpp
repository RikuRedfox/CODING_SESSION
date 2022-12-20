#include <string>
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <cstdlib>
#include <array>
#include <vector>

class Calc
{
public:
    class SimpleCalc
    {
        std::string str1, str2;
        char op;
        long double num1, num2;
        long double t_num = 0;
        int m_num1, m_num2;
        int m_num = 0;

    public:
        inline void simple_calc()
        {
            while (true)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("CLS");
                std::cout << "\tCommands:"
                             "\n'e x t' Exits the program"
                             "\n\n\tAvailable Operators:"
                             "\n'+' Addition"
                             "\n'-' Subtraction"
                             "\n'*' Multiplication"
                             "\n'/' Division"
                             "\n'%' Modulo";
                if (op == '+' || op == '-' || op == '*' || op == '/')
                    std::cout << "\n\nLast result: " << t_num;
                if (op == '%')
                    std::cout << "\n\nLast result: " << m_num;
                std::cout << "\n\n\t[Ex. Format: 1 + 2]\n>> ";
                std::cin >> str1 >> op >> str2;

                if (str1 == "e" || str1 == "E")
                {
                    std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
                    if (op == 'x' || op == 'X')
                    {
                        op = tolower(op);
                        if (str2 == "t" || str2 == "T")
                        {
                            std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                            if (str1 == "e" && op == 'x' && str2 == "t")
                                break;
                        } // str2
                    }     // op
                }         // str1

                switch (op)
                {
                case '+':
                    num1 = stold(str1);
                    num2 = stold(str2);
                    t_num = num1 + num2;
                    break;
                case '-':
                    num1 = stold(str1);
                    num2 = stold(str2);
                    t_num = num1 - num2;
                    break;
                case '*':
                    num1 = stold(str1);
                    num2 = stold(str2);
                    t_num = num1 * num2;
                    break;
                case '/':
                    num1 = stold(str1);
                    num2 = stold(str2);
                    t_num = num1 / num2;
                    break;
                case '%':
                    num1 = stold(str1);
                    num2 = stold(str2);
                    m_num1 = num1;
                    m_num2 = num2;
                    m_num = m_num1 % m_num2;
                    break;
                default:
                    continue;
                    break;
                }
            }
        }
    } simpleCalc;
} calc;
