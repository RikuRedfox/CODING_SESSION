#include <iostream>
using std::cout, std::cin;

int main()
{
    while (true)
    {
        srand(time(NULL));
        int secretNum = rand() % 100; // range from 1-100;
        int guess, guessCount = 0, guessLimit = 10;
        bool outOfGuesses = false;

        cout << "Guest my number.\n\n"; // You can't guess, every time you guess the number will chance. . . possible but small chance.
        while (secretNum != guess && !outOfGuesses)
        {
            if (guessCount < guessLimit)
            {
                cout << "[" << guessCount << "] "
                     << "Enter number guess: ";
                cin >> guess;
                // test;
                // cout << "\nThe number for this time is. . . ";
                // cout << rand() % 100 << endl;
                guessCount++;
            }
            else
            {
                outOfGuesses = true;
            }
        }
        if (outOfGuesses)
        {
            cout << "Out of guesses token.\n";
            cout << "Good try o(*^＠^*)o \n";
        }
        else
        {
            cout << "You guess it!\n";
        }

        cout << "Do you want to try it again? [1]YES [0]NO\n";
        int dec;
        cin >> dec;
        if (dec != 1)
        {
            break;
        }
    }
    return 0;
}