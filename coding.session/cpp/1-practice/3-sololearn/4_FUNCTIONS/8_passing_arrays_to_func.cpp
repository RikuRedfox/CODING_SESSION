#include <iostream>
#include <string>

// complete the function
void winners(std::string customers[], int a, int b, int c) {
  b--;
  for (int i{0}; i < a; i++) {
    if (b > (a - 1)) {
      break;
    }
    std::cout << customers[b] << std::endl;
    b = b + c;
  }
}

int main() {

  std::string customers[] = {"Alice", "Bob",     "Rayan",  "Emma",    "Ann",
                             "Bruce", "Synthia", "Daniel", "Richard", "Sam",
                             "Nick",  "Mary",    "Paul"};

  // getting the lucky number as input
  int b;
  std::cin >> b;
  int c = b;
  // call function
  winners(customers, 13, b, c);

  return 0;
}