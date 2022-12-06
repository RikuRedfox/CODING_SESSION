#include <iostream>

// class definition
class Car {

private: // private area
  int horsepowers;

public: // public area
  // complete the setter function
  void setHorsepowers(int a) {
    horsepowers = a;
    if (a > 800)
      std::cout << "Too much." << std::endl;
  }
  // complete the getter function
  int getHorsepowers() { return horsepowers; }
};

int main() {
  // getting input
  int horsepowers;
  std::cin >> horsepowers;
  // creating the object of class Car
  Car car;
  // setting the value for private member
  car.setHorsepowers(horsepowers);
  // printing the value of private member
  std::cout << car.getHorsepowers();

  return 0;
}