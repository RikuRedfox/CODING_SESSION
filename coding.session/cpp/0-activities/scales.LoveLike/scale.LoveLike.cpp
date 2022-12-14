#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class Scales {
private:
  double m_current_scale{0};
  const double m_total{65.};
  int m_user_scale;
  std::string m_lName;
  std::array<std::array<std::string, 3>, 13> questions;

public:
  void Love();
  void Like();
} scale;

int main() {
  system("CLS");
  std::cout << "\tLOVE AND LIKE SCALE\n\nThis quiz are for fun only.\n";
  std::cout << "This scale are originally a research paper\nf";
  std::cout << "rom 1970 by Zick Rubin.\n\n";

  std::cout << "Press enter to continue . . . ";
  std::cin.get();

  std::string respond;
  {
    system("CLS");
    std::string name, gender;
    size_t age;

    std::cout << "What is your name? : ";
    std::getline(std::cin, name);

    std::cout << "How old are you? : ";
    std::cin >> age;
    while (std::cin.fail()) {
      std::cin.clear(); // clearning the buffer if there is a string input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cout << "How old are you? : ";
      std::cin >> age;
    }

    std::cout << "What is your sex? \n";
    std::cout << "(Press 'M' for Male | 'F' for Female) : ";
    std::cin >> respond;

    gender = (respond == "M" || respond == "m")   ? "Male."
             : (respond == "F" || respond == "f") ? "Female."
                                                  : "Unknown?";
    std::cout << "Your sex is . . . " << gender << std::endl;

    std::cout << "\nDIRECTION: Scale it from 1-5 otherwise the scaling will "
                 "fail/error.\n\n";
    std::cout << "Are you ready to take the survey? " << name
              << ". \n(type 'Y' for yes | 'any' for exit) : ";
    std::cin >> respond;
  }

  if (respond == "Y" || respond == "y") {
    system("CLS");
    std::cout << "\n\tI'm glad!";
    while (true) {
      while (true) {
        std::cout << "\nNow pick between the survey.\n"
                  << "(Type 'LOVE' for love survey | 'LIKE' for like survey.)\n"
                     "Respond : ";
        std::cin >> respond;
        std::for_each(respond.begin(), respond.end(),
                      [](char &c) { c = ::tolower(c); });
        if (respond == "love") {
          system("CLS");
          scale.Love();
          break;
        } else if (respond == "like") {
          system("CLS");
          scale.Like();
          break;
        } else {
          system("CLS");
          std::cerr << "\nERROR: The inputs are incompatible. Try again.\n";
          continue;
        }
      }
      std::cout << "\n\nDo you want to try it again or try the other one?\n"
                   "(Press 'Y for try again(other) | 'any' for exit) : ";
      std::cin >> respond;
      if (respond == "Y" || respond == "y")
        continue;
      else {
        break;
      }
    }
    system("CLS");
    std::cout << "\nThank you trying this survey.";
    return 0;
  }
  system("CLS");
  std::cout << "\n\nOh. . . Okay." << std::endl;
  return 0;
}

void Scales::Love() {
  std::cout << "\n\tLOVE SCALE!\n\n";
  m_current_scale = 0;
  std::cin.get();
  questions = {{
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
  }};

  std::cout << "Enter the name of your love one : ";
  std::getline(std::cin, m_lName);
  std::cout << std::endl;
  // i for rows
  for (size_t i{0}; i < questions.size(); i++) { // j for column
    for (size_t j{0}; j < questions.at(i).size(); j++) {
      system("CLS");
      while (1) {
        std::cin.clear(); // clearning the buffer if there is a string input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // code here call the array value each iteration
        // increment j to call next column in same row
        std::cout << questions.at(i).at(j) << m_lName;
        j++;
        std::cout << questions.at(i).at(j);
        j++;
        // call this array if the iteration met the condition
        if (questions.at(i).at(j) == questions.at(5).at(2)) {
          std::cout << m_lName << questions.at(i).at(j);
        }
        try {
          std::cout << "Your scale: ";
          std::cin >> m_user_scale;
          // input for scale 1-5
          if (m_user_scale > 5 || m_user_scale < 1) {
            j -= 2;
            throw 1;
          } else
            break;
        } catch (const int &e) {
          system("CLS");
          std::cerr << "\nERROR: 1 to 5 only! Retry your input. ErrorCode : "
                    << &e << "\n\n";
        }
      }
      // current scale + user scale
      m_current_scale += m_user_scale;
    }
  }
  system("CLS");
  // print the total/final point.
  std::cout << "The final score: " << m_current_scale << "/" << m_total
            << std::endl;
  double result = (m_current_scale / m_total) * 100;
  std::cout << result << "% That is you're inlove with " << m_lName
            << std::endl;
}

void Scales::Like() {
  {
    std::cout << "\n\tLIKE SCALE. Goodluck!\n\n";
    m_current_scale = 0;
    std::cin.get();
    questions = {{
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
    }};

    std::cout << "Enter the name of your friend(love) : ";
    std::getline(std::cin, m_lName);
    std::cout << std::endl;
    // i for rows
    for (size_t i{0}; i < questions.size(); i++) { // j for column
      for (size_t j{0}; j < questions.at(i).size(); j++) {
        system("CLS");
        while (1) {
          std::cin.clear(); // clearning the buffer if there is a string input
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          // call this array if the iteration met the condition
          if (questions.at(i).at(j) == questions.at(11).at(1) ||
              questions.at(i).at(j) == questions.at(12).at(1)) {
            std::cout << m_lName << questions.at(i).at(j);
          }
          // increment j to call next column in same row
          std::cout << questions.at(i).at(j) << m_lName;
          j++;
          std::cout << questions.at(i).at(j);
          j++;
          try {
            std::cout << "Your scale: ";
            std::cin >> m_user_scale;
            // input for scale 1-5
            if (m_user_scale > 5 || m_user_scale < 1) {
              j -= 2;
              throw 1;
            } else
              break;
          } catch (const int &x) {
            system("CLS");
            std::cerr << "\nERROR: 1 to 5 only! Retry your input. ErrorCode : "
                      << &x << "\n\n";
          }
        }
        // current scale + user scale
        m_current_scale += m_user_scale;
      }
    }
    system("CLS");
    // print the m_total/final point.
    std::cout << "The final score: " << m_current_scale << "/" << m_total
              << std::endl;
    double result = (m_current_scale / m_total) * 100;
    std::cout << result << "% That is you like " << m_lName << std::endl;
  }
}