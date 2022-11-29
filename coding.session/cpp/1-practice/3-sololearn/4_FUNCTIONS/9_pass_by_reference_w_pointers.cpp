#include <iostream>

// complete the function to multiple the megabytes, don't forget to set the
// parameter
void promotion(int *megabytes) {
  // taking multiplier as input
  int multiplier;
  std::cin >> multiplier;
  *megabytes = multiplier * *megabytes;
}

int main() {
  // getting initial count of megabytes
  int megabytes;
  std::cin >> megabytes;

  // printing the count of megabytes before the promotion
  std::cout << "Before the promotion: " << megabytes << std::endl;

  // complete the function call
  promotion(&megabytes);

  // printing the count of megabytes after the promotion
  std::cout << "After the promotion: " << megabytes << std::endl;

  return 0;
}