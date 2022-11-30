#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

void loveScale() {
  std::cout << "\nLOVE SCALE. Goodluck!\n\n";
  double current_scale{}, total{65};
  int user_scale;

  // 'name' user input for person they like to see in per sentence.
  std::string name;
  // 'questions' all question are stored here.
  const std::string questions[13][3]{
      {"If ",
       " were feeling badly, my first duty would be to cheer him(her) up.\n",
       ""}, // 1
      {"I feel that I can confide in ", " about virtually everything.\n",
       ""},                                                              // 2
      {"I find it easy to ignore ", "'s faults.\n", ""},                 // 3
      {"I would do almost anything for ", ".\n", ""},                    // 4
      {"I feel very possessive toward ", ".\n", ""},                     // 5
      {"If I could never be with ", ", I would be to seek ", " out.\n"}, // 6
      {"If I were lonely, my first thought would be to seek ", " out.\n",
       ""},                                                     // 7
      {"One of my primary concern is ", "'s welfare.\n", ""},   // 8
      {"I would forgive ", " for practically anything.\n", ""}, // 9
      {"I feel responsible for ", "'s well-being.\n", ""},      // 10
      {"When I am with ",
       ", I spend a good feal of time just looking at him(her).\n", ""}, // 11
      {"I would greatly enjoy being confided in by ", ".\n", ""},        // 12
      {"it would be hard for me to get along without ", ".\n", ""}       // 13
  };

  std::cin.get();
  std::cout << "Enter the name of your love one: ";
  std::getline(std::cin, name);
  std::cout << std::endl;
  // i for rows
  for (size_t i{0}; i < 13; i++) { // j for column
    for (size_t j{0}; j < 2; j++) {
      while (1) {
        std::cin.clear(); // clearning the buffer if there is a string input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      // code here call the array value each iteration
      // increment j to call next column in same row
      std::cout << questions[i][j] << name;
      j++;
      std::cout << questions[i][j];
      j++;
      // call this array if the iteration met the condition
      if (questions[i][j] == questions[5][2]) {
        std::cout << name << questions[i][j];
      }
        try {
          std::cout << "Your scale: ";
          std::cin >> user_scale;
          // input for scale 1-5
          if (user_scale > 5 || user_scale < 1) {
            j -= 2;
            throw 1;
          } else {
            break;
          }
        } catch (const int &x) {
          std::cerr << "\nERROR: 1 to 5 only! Retry your input. ErrorCode : "
                    << &x << "\n\n";
        }
      }
      // current scale + user scale
      current_scale += user_scale;
      // show the current points
      std::cout << "\nCurrent score: " << current_scale << "/" << total
                << std::endl
                << std::endl;
    }
  }
  // print the total/final point.
  std::cout << "The final score: " << current_scale << "/" << total
            << std::endl;
  double result = (current_scale / total) * 100;
  std::cout << result << "% That is you're inlove with " << name << std::endl;
}

void likeScale() {
  std::cout << "\nLIKE SCALE. Goodluck!\n\n";
  double current_scale{}, total{65};
  int user_scale;

  // 'name' user input for person they like to see in per sentence.
  std::string name;
  // 'questions' all question are stored here.
  const std::string questions[13][3]{
      {"When I am with ", ", we are almost always in the same mood.\n",
       ""},                                                             // 1
      {"I think that ", " is unusually well adjusted.\n", ""},          // 2
      {"I would highly recommend ", " for a responsible job.\n", ""},   // 3
      {"In my opinion, ", " is an exceptionally mature person.\n", ""}, // 4
      {"I have great confidence in ", "'s good judgment.\n", ""},       // 5
      {"Most people would react very favorably to ",
       " after a brief acquiantance.\n", ""},                             // 6
      {"I think that ", " and I are quite similar to each other.\n", ""}, // 7
      {"I would vote for ", " in a class or group election.\n", ""},      // 8
      {"I think that ", " is one of those people who quicly wins respect.\n",
       ""},                                                            // 9
      {"I feel that ", " is an extremenly intelligent person.\n", ""}, // 10
      {"", " is one of the most likable people I know.\n", ""},        // 11
      {"", " is the sort of person whom I myself would like to be.\n",
       ""}, // 12
      {"It seems to me that it is very easy for ", " to gain admiration.\n",
       ""} // 13
  };

  std::cin.get();
  std::cout << "Enter the name of your friend(love): ";
  std::getline(std::cin, name);
  std::cout << std::endl;
  // i for rows
  for (size_t i{0}; i < 13; i++) { // j for column
    for (size_t j{0}; j < 2; j++) {
      // call this array if the iteration met the condition
      if (questions[i][j] == questions[11][1] ||
          questions[i][j] == questions[12][1]) {
        std::cout << name << questions[i][j];
      }
      // increment j to call next column in same row
      std::cout << questions[i][j] << name;
      j++;
      std::cout << questions[i][j];
      j++;
      while (1) {
        std::cin.clear(); // clearning the buffer if there is a string input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        try {
          std::cout << "Your scale: ";
          std::cin >> user_scale;
          // input for scale 1-5
          if (user_scale > 5 || user_scale < 1) {
            throw 1;
          } else {
            break;
          }
        } catch (const int &x) {
          std::cerr << "\nERROR: 1 to 5 only! Retry your input. ErrorCode : "
                    << &x << "\n\n";
        }
      }
      // current scale + user scale
      current_scale += user_scale;
      // show the current points
      std::cout << "\nCurrent score: " << current_scale << "/" << total
                << std::endl
                << std::endl;
    }
  }
  // print the total/final point.
  std::cout << "The final score: " << current_scale << "/" << total
            << std::endl;
  double result = (current_scale / total) * 100;
  std::cout << result << "% That is you like " << name << std::endl;
}

void error() { std::cout << "error?\n"; }

int main() {
  // Introduction
  std::cout << "LOVE AND LIKE SCALE\n\n";
  std::cout << "This quiz are for fun only.\nThis scale are originally a "
               "research paper\nfrom 1970 by Zick Rubin.\n\n";

  std::cout << "Press enter to continue . . .";
  std::cin.get();

  std::string name, gender[2]{"Male", "Female"}, respond;
  size_t age, gender_in;

  std::cout << "\nWhat is your name? ";
  std::getline(std::cin, name);

  std::cout << "How old are you? ";
  std::cin >> age;

  std::cout << "What is your gender?\n(Press '0' for Male | '1' for Female) : ";
  std::cin >> gender_in;
  gender[gender_in];

  std::cout << "\nHere is the direction before take the quiz.\nScale it from "
               "1-5 otherwise the scaling will fail/error.\n\n";
  std::cout << "Are you ready to take the \nLOVE AND LIKE QUIZ? " << name
            << "? \n(Press '1' for yes | 'any' for no) : ";
  std::cin >> respond;

  if (stoi(respond) == 1) {
    while (true) {
      std::cout
          << "\nNice! Before we start I like you to pick between the quiz.\n";
      std::cout
          << "Type 'love' for love scale | 'like' for like scale\nRespond : ";
      std::cin >> respond;
      std::for_each(respond.begin(), respond.end(),
                    [](char &c) { c = ::tolower(c); });
      (respond == "love")   ? loveScale()
      : (respond == "like") ? likeScale()
                            : error();

      int dec;
      std::cout << "Do you want to try it again or try the other one?\n(Press "
                   "'1' for try again(other) | 'any' for no) : ";
      std::cin >> dec;
      if (dec != 1) {
        break;
      }
    }
    std::cout << "\nThank you trying this mini game. ヾ(≧▽≦*)o";
    return 0;
  } else {
    std::cout << "Oh. . . Ok. ＞︿＜" << std::endl;
    return 0;
  }

  return 0;
}