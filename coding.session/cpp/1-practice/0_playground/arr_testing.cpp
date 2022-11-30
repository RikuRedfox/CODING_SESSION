#include <array>
#include <iostream>
#include <string>
#include <vector>

int main() {

  std::array<std::array<std::string, 3>, 13> arr = {{
      {"If ", " were feeling badly, my first duty would be to cheer him(her) up.\n", ""},
      {"I feel that I can confide in ", " about virtually everything.\n", ""},
      {"I find it easy to ignore ", "'s faults.\n", ""},
      {"I would do almost anything for ", ".\n", ""},
      {"I feel very possessive toward ", ".\n", ""},
      {"If I could never be with ", ", I would be to seek ", " out.\n"},
      {"If I were lonely, my first thought would be to seek ", " out.\n", ""},
      {"One of my primary concern is ", "'s welfare.\n", ""},
      {"I would forgive ", " for practically anything.\n", ""},
      {"I feel responsible for ", "'s well-being.\n", ""},
      {"When I am with ", ", I spend a good feal of time just looking at him(her).\n", ""},
      {"I would greatly enjoy being confided in by ", ".\n", ""},
      {"it would be hard for me to get along without ", ".\n", ""}
  }};

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
      {"If ", " were feeling badly, my first duty would be to cheer him(her) up.\n", ""},
      {"I feel that I can confide in ", " about virtually everything.\n", ""},
      {"I find it easy to ignore ", "'s faults.\n", ""},
      {"I would do almost anything for ", ".\n", ""},
      {"I feel very possessive toward ", ".\n", ""},
      {"If I could never be with ", ", I would be to seek ", " out.\n"},
      {"If I were lonely, my first thought would be to seek ", " out.\n", ""},
      {"One of my primary concern is ", "'s welfare.\n", ""},
      {"I would forgive ", " for practically anything.\n", ""},
      {"I feel responsible for ", "'s well-being.\n", ""},
      {"When I am with ", ", I spend a good feal of time just looking at him(her).\n", ""},
      {"I would greatly enjoy being confided in by ", ".\n", ""},
      {"it would be hard for me to get along without ", ".\n", ""}
  };

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