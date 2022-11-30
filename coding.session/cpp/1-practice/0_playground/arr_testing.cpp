#include <array>
#include <iostream>
#include <string>
#include <vector>

int main() {

  std::array<std::array<std::string, 3>, 13> arr = {
      {{"0, 0", "0, 1", "0, 2"},
       {"1, 0", "1, 1", "1, 2"},
       {"2, 0", "2, 1", "2, 2"},
       {"3, 0", "3, 1", "3, 2"},
       {"4, 0", "4, 1", "4, 2"},
       {"5, 0", "5, 1", "5, 2"},
       {"6, 0", "6, 1", "6, 2"},
       {"7, 0", "7, 1", "7, 2"},
       {"8, 0", "8, 1", "8, 2"},
       {"9, 0", "9, 1", "9, 2"},
       {"10, 0", "10, 1", "10, 2"},
       {"11, 0", "11, 1", "11, 2"},
       {"12, 0", "12, 1", "12, 2"}}};

  for (size_t i = 0; i < arr.size(); i++) {
    for (size_t j = 0; j < arr[i].size(); j++)
      std::cout << arr.at(i).at(j) << " ";
    std::cout << std::endl;
  }

  std::cout << "\n\n\nEnd of first arr\n\n\n";

  for (auto arr1d : arr) {
    for (auto arr2d : arr1d)
      std::cout << arr2d << " ";
    std::cout << std::endl;
  }

  std::cout << "\n\n\nStart of vect\n\n\n";

  std::vector<std::vector<std::string>> vect = {
      {"0, 0", "0, 1", "0, 2"},    {"1, 0", "1, 1", "1, 2"},
      {"2, 0", "2, 1", "2, 2"},    {"3, 0", "3, 1", "3, 2"},
      {"4, 0", "4, 1", "4, 2"},    {"5, 0", "5, 1", "5, 2"},
      {"6, 0", "6, 1", "6, 2"},    {"7, 0", "7, 1", "7, 2"},
      {"8, 0", "8, 1", "8, 2"},    {"9, 0", "9, 1", "9, 2"},
      {"10, 0", "10, 1", "10, 2"}, {"11, 0", "11, 1", "11, 2"},
      {"12, 0", "12, 1", "12, 2"}};

  for (size_t i = 0; i < vect.size(); i++) {
    for (size_t j = 0; j < vect[i].size(); j++)
      std::cout << vect[i][j] << " ";
    std::cout << std::endl;
  }

  std::cout << "\n\n\nEnd of first vect\n\n\n";

  for (auto arr1d : vect) {
    for (auto arr2d : arr1d)
      std::cout << arr2d << " ";
    std::cout << std::endl;
  }

  return 0;
}