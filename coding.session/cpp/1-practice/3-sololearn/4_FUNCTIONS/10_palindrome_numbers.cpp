#include <iostream>

bool isPalindrome(int x) {
  // complete the function
  int digit, temp = x, rev = 0;
  while (x != 0) {
    digit = x % 10;
    rev = (rev * 10 + digit);
    x = x / 10;
  }

  if (temp == rev)
    return true;
  else
    return false;
}

int main() {
  int n;
  while (std::cin) {
    std::cin >> n;

    if (isPalindrome(n)) {
      std::cout << n << " is a palindrome\n\n";
    } else {
      std::cout << n << " is NOT a palindrome\n\n";
    }
  }
  return 0;
}