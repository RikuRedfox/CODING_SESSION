// Andrew Jules Miyajima - 10.20.2022
#include <iostream>
#include <string>

int main()
{

        std::string month_name;
        short month, day, year;

        std::cout << "Enter month : ";
        std::cin >> month; // 1 - 12

        std::cout << "Enter day : ";
        std::cin >> day;

        std::cout << "Enter year : ";
        std::cin >> year;
        std::cout << std::endl;

        switch (month){
        case 1:
            month_name = "January";
            break;
        case 2:
            month_name = "February";
            break;
        case 3:
            month_name = "March";
            break;
        case 4:
            month_name = "April";
            break;
        case 5:
            month_name = "May";
            break;
        case 6:
            month_name = "June";
            break;
        case 7:
            month_name = "July";
            break;
        case 8:
            month_name = "August";
            break;
        case 9:
            month_name = "September";
            break;
        case 10:
            month_name = "October";
            break;
        case 11:
            month_name = "November";
            break;
        case 12:
            month_name = "December";
            break;
        default:
            std::cout << "Invalid Month!" << std::endl;
            break;
        }

        std::cout << month_name << " " << day << ", " << year << std::endl;

    return 0;
}