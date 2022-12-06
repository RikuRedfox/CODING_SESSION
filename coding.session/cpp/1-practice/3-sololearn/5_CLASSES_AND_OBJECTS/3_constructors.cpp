#include <iostream>
#include <string>

class Painting {
private:
  std::string name;

public:
  Painting(std::string ab) {
    name = ab;
    std::cout << ab;
  }
  std::string paint() { return name; }
};
int main() {
  std::string temp;
  std::string name = "";
  while (std::cin >> temp) {
    name += temp.append(" ");
  }

  Painting painting(name);

  return 0;
}