#include <iostream>

int main() {
  while (true) {
    srand(time(NULL));
    int secretNum = rand() % 100; // range from 1-100;
    int guess, guessCount = 0, guessLimit = 10;
    bool outOfGuesses = false;

    std::cout << "Guest my number.\n\n";
    // You can't guess, every time you guess the
    // number will chance. . . possible but
    // small chance.
    while (secretNum != guess && !outOfGuesses) {
      if (guessCount < guessLimit) {
        std::cout << "[" << guessCount << "] "
                  << "Enter number guess: ";
        // test;
        // std::cout << "\nThe number for this time is. . . ";
        // std::cout << rand() % 100 << endl;
        guessCount++;
      } else {
        outOfGuesses = true;
      }
    }
    if (outOfGuesses) {
      std::cout << "Out of guesses token.\n";
      std::cout << "Good try o(*^＠^*)o \n";
    } else {
      std::cout << "You guess it!\n";
    }

    std::cout << "Do you want to try it again? [1]YES [0]NO\n";
    int dec;
    if (dec != 1) {
      break;
    }
  }
  return 0;
}