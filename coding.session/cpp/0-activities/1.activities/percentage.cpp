#include <iostream>

float percentage_value(float initial_value, float percentage) {
  float breakdown{initial_value * percentage};
  return initial_value + breakdown;
}

int main() {
  while (1) {
    float initial_value, percentage;

    std::cout << "Enter a value : ";
    std::cin >> initial_value;
    std::cout << "Enter a percentage[ex. .01 or .10] : ";
    std::cin >> percentage;

    float result = percentage_value(initial_value, percentage);
    std::cout << "= " << result << std::endl;
    std::cout << std::endl;
  }

  return 0;
}