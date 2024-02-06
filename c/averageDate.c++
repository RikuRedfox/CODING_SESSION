#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct Date {
    int day;
    int month;
    int year;
};

// Number of days in each month (non-leap year)
const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int daysSinceReference(const Date& date) {
    int days = 0;
    
    // Calculate days for years
    for (int y = 1; y < date.year; ++y) {
        days += (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 366 : 365;
    }

    // Add days for months
    for (int m = 1; m < date.month; ++m) {
        days += daysInMonth[m];
        // Handle February in leap years
        if (m == 2 && (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0))) {
            ++days;
        }
    }

    // Add days of the current month
    days += date.day;

    return days;
}

int main() {
    std::vector<Date> dates;

    char choice;
    std::cout << "Would you like to read dates from a file? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        std::string filename;
        std::cout << "Enter filename: ";
        std::cin >> filename;

        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return 1;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            Date date;
            char slash;
            ss >> date.day >> slash >> date.month >> slash >> date.year;
            dates.push_back(date);
        }
        file.close();
    } else {
        std::cout << "Enter dates in the format dd/mm/yyyy (e.g., 10/11/2023):" << std::endl;
        std::string dateStr;
        while (std::getline(std::cin, dateStr) && !dateStr.empty()) {
            std::stringstream ss(dateStr);
            Date date;
            char slash;
            ss >> date.day >> slash >> date.month >> slash >> date.year;
            dates.push_back(date);
        }
    }

    if (dates.empty()) {
        std::cerr << "No dates provided!" << std::endl;
        return 1;
    }

    int totalDays = 0;
    for (const auto& date : dates) {
        totalDays += daysSinceReference(date);
    }

    int avgDay = totalDays / dates.size();
    std::cout << "The average day (days since reference) is: " << avgDay << std::endl;

    return 0;
}
