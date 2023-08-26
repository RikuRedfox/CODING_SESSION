#include <iostream>
#include <iomanip>

int main() {
  long double pi = 3.141592653589793238L;
  //               3.1415926535897932381

    std::cout << std::setprecision(20);
    std::cout << "Value of pi with long double: " << pi << std::endl;

    return 0;
}
