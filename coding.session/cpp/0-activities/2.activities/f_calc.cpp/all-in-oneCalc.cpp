#include "_headers/_calc.hpp"
#include "_headers/_conv.hpp"

std::string str_respond;
short unsigned int int_respond;

int main(void)
{
    std::array<std::string, 12> choice{"Simple Calculator", "Area", "BMI", "Data", "Discount", "Length", "Mass", "Numerical System", "Speed", "Temperature", "Time", "Volume"};
    do
    {
        std::cout << "\n\tCHOICE WHAT TO CALCULATE\n";
        size_t i = 1;
        for (auto a : choice)
            std::cout << "[" << i++ << "] " << a << "\n";

        std::cout << "\nType a number to enter one of the calculator: ";
        std::cin >> int_respond;

        while (std::cin.fail())
        {
            system("CLS");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "\nERROR: String input. (Press Enter)";
            std::cin.get();
            system("CLS");
            std::cout << "\n\tCHOICE WHAT TO CALCULATE\n";
            int i = 1;
            for (auto a : choice)
            {
                std::cout << "[" << i++ << "] " << a << "\n";
            }

            std::cout << "\nType a number to enter one of the calculator : ";
            std::cin >> int_respond;
        }

        if (int_respond < 1 || int_respond > 12)
        {
            system("CLS");
            std::cerr << "\nERROR: Out of range. (Press Enter)";
            std::cin.get();
            std::cin.get();
            system("CLS");
            continue;
        }
        else
            break;
    } while (true);

    switch (int_respond)
    {
    case 1:
        calc.simpleCalc.simple_calc();
        break;
    case 2:
        conv.area.area();
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        break;
    }

    return 0;
}
