#include <iostream>
#include <limits>
#include <sstream>
#include "../header/sub_q.cpp" // Questions

int Guess, Total;
// class function | question.class.hpp
// Objects of Question Class | included by sub_q.cpp
int main(){
    std::cout << "Press Enter to start the quiz...\n";
    std::cin.get();

    std::string Name;
    int Age, Respond;

    // Input the details
    std::cout << "What is your name? ";
    std::getline(std::cin, Name);
    std::cout << "How old are you? ";
    std::cin >> Age;

    std::cout << "\nAre you ready to take the quiz " << Name << "?\nPress '1' for YES or 'any' for NO : ";
    std::cin >> Respond;

    if (Respond != 1){
        std::cout << "Goodbye! ＞︿＜\n";
        return 0;
    }
    std::cout << "\nGood Luck! *^____^*\n";
    
    Total = 0; int dec;
    while (1){
        while(1){
            std::cin.clear(); // clearning the buffer if there is a string input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            // Display all subject available
            std::string subjects[]{"Language", "Mathematics", "Science", "History", "Computers [ONG]"};

            int i {1};
            for (std::string str : subjects){
                std::cout << "[" << i++ << "] " << str << std::endl;
            }

            try{
                std::cout << "\nPick your subject (in number) :  ";
                std::cin >> dec;

                switch (dec){
                    case 1: language(); break;
                    case 2: mathematics(); break;
                    case 3: science(); break;
                    case 4: history(); break;
                    case 5: computers(); break;
                }
                    if(dec > 5 || dec < 1){throw 0;}else{break;} 
            } catch(const int &x){
                std::cerr << "\nERROR: Input error! Please try again. ErrorCode: " << &x << "\n\n";
            }
        }
        q1.askQuestion();
        q2.askQuestion();
        q3.askQuestion();
        q4.askQuestion();
        q5.askQuestion();
        q6.askQuestion();
        q7.askQuestion();
        q8.askQuestion();
        q9.askQuestion();
        q10.askQuestion();

        // Display the total score
        std::cout << "\nTotal Score = " << Total << " out of 100\n";

        // Display the results
        // If the player pass the quiz
        if (Total >= 70){
            std::cout << "Congrats you passed the quiz! ヾ(≧▽≦*)o\n";
        } else { // If failed
            std::cout << "\nYou failed the quiz.\nBetter luck next time. ( •̀ ω •́ )✧\n";
        }

        std::cout << "\n\nDo you want to retry or try other subject?\nPress '1' for YES or 'any' for NO : ";
        std::cin >> dec;
        std::cout << std::endl;
            
        if (dec != 1){
            break;
        }
    }
    return 0;
}

// Function to set the values of the questions
void Question::setValues(std::string q, std::string a1, std::string a2, std::string a3, std::string a4, int ca, int pa){
    Question_Text = q;
    Answer_1 = a1;
    Answer_2 = a2;
    Answer_3 = a3;
    Answer_4 = a4;
    Correct_Answer = ca;
    Question_Score = pa;
}

// Function to ask questions
void Question::askQuestion(){
    while(1){
        std::cin.clear(); // clearning the buffer if there is a string input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        // Print the questions
        std::cout << Question_Text << std::endl;
        std::cout << "1. " << Answer_1 << std::endl;
        std::cout << "2. " << Answer_2 << std::endl;
        std::cout << "3. " << Answer_3 << std::endl;
        std::cout << "4. " << Answer_4 << std::endl;
        std::cout << std::endl;

        try{
            // User input for answer in number from 1-4;
            std::cout << "What is your answer?(in number [1-4]) : ";
            std::cin >> Guess;
            // Handling between the choices will repeat the question again if the number input is excedding
            if(Guess > 4 || Guess < 1){
                throw 1;
            }else{
                break;
            }

        }catch(const int &y){
            std::cerr << "\nERROR: Input error! Please try again. ErrorCode: " << &y << "\n\n";
        }
    }

    // If the answer is correct
    if (Guess == Correct_Answer){
        std::cout << "\nCORRECT!!" << std::endl;  // Update the correct score
        Total += Question_Score;
    } else{
        std::cout << "\nTHE CORRECT ANSWER: " << Correct_Answer << std::endl; // Otherwise
        Question_Score;
    }
}