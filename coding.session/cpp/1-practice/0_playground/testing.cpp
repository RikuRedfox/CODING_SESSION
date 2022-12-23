#include <algorithm>
#include <array>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

int main(void) {
  std::cout << std::left << std::setw(20) << "CALCULATOR:"   << std::left << "|\t\tCONVERTER:\n";
  std::cout << std::left << std::setw(20) << "BMI"          << std::right <<"|\t\tArea\n";
  std::cout << std::left << std::setw(20) << "Discount"     << std::right <<"|\t\tData\n";
  std::cout << std::left << std::setw(20) << "-"            << std::right <<"|\t\tLength\n";
  std::cout << std::left << std::setw(20) << "-"            << std::right <<"|\t\tMass\n";
  std::cout << std::left << std::setw(20) << "-"            << std::right <<"|\t\tNumerial System\n";
  std::cout << std::left << std::setw(20) << "-"            << std::right <<"|\t\tSpeed\n";
  std::cout << std::left << std::setw(20) << "-"            << std::right <<"|\t\tTemperature\n";
  std::cout << std::left << std::setw(20) << "-"            << std::right <<"|\t\tTime\n";
}