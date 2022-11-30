#include <iostream>

class Bird {
public:
  // complete the class, add makeSound() method
  void makeSound() { std::cout << "chirp-chirp"; }
};

int main() {

  // instantiation
  Bird bird;

  // function call
  bird.makeSound();

  return 0;
}