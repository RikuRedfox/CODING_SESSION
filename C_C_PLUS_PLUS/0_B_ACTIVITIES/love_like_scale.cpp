#include <iostream>
#include <iomanip>
#include <string>
using std::cout, 
    std::cin,
    std::endl,
    std::getline,
    std::setprecision,
    std::string;

void loveScale(){
    // 'scales' scale from 1-5 using 'us' | 'us' user scale | 'cs' current scale set to 0 | 'total' total points will get.
    double scales[6]{0, 1, 2, 3, 4, 5}, cs = 0, total = 65;
    int us;
    string name, // 'name' user input for person they like to see in per sentence.
        questions[13][3]{
            // 'questions' all question are stored here.

            {"If ", " were feeling badly, my first duty would be to cheer him(her) up.\n", ""},   // 1
            {"I feel that I can confide in ", " about virtually everything.\n", ""},              // 2
            {"I find it easy to ignore ", "'s faults.\n", ""},                                    // 3
            {"I would do almost anything for ", ".\n", ""},                                       // 4
            {"I feel very possessive toward ", ".\n", ""},                                        // 5
            {"If I could never be with ", ", I would be to seek ", " out.\n"},                    // 6
            {"If I were lonely, my first thought would be to seek ", " out.\n", ""},              // 7
            {"One of my primary concern is ", "'s welfare.\n", ""},                               // 8
            {"I would forgive ", " for practically anything.\n", ""},                             // 9
            {"I feel responsible for ", "'s well-being.\n", ""},                                  // 10
            {"When I am with ", ", I spend a good feal of time just looking at him(her).\n", ""}, // 11
            {"I would greatly enjoy being confided in by ", ".\n", ""},                           // 12
            {"it would be hard for me to get along without ", ".\n", ""}                          // 13

        };
    cin.get();
    cout << "Enter the name of your love one: ";
    getline(cin, name);
    cout << endl;
    // i for rows
    for (size_t i{0}; i < 13; i++){ // j for column
        for (size_t j{0}; j < 2; j++){
            // code here call the array value each iteration
            cout << questions[i][j] << name;
            j++; // increment the column to call next column in same row
            cout << questions[i][j];
            j++;
            if (questions[i][j] == questions[5][2]){ // call this array if the iteration met the requirement
                cout << name << questions[i][j];
            };
            cout << "Your scale: ";
            cin >> us;        // input for scale 1-5
            cs += scales[us]; // current scale + user scale
            // show the current points
            cout << endl
                 << "Current score: " << cs << "/" << total << endl
                 << endl;
        }
    } // print the total/final point.

    cout << "The final score: " << cs << "/" << total << endl;
    cout << setprecision(4);
    double result = (cs / total) * 100;
    cout << result << "% That is you're inlove with " << name << endl;
}

void likeScale(){
    // 'scales' scale from 1-5 using 'us' | 'us' user scale | 'cs' current scale set to 0 | 'total' total points will get.
    double scales[6]{0, 1, 2, 3, 4, 5}, cs{0}, total{65};
    int us;
    string name, // 'name' user input for person they like to see in per sentence.
        questions[13][3]{
            // 'questions' all question are stored here.

            {"When I am with ", ", we are almost always in the same mood.\n", ""},                // 1 5
            {"I think that ", " is unusually well adjusted.\n", ""},                              // 2 10
            {"I would highly recommend ", " for a responsible job.\n", ""},                       // 3 15
            {"In my opinion, ", " is an exceptionally mature person.\n", ""},                     // 4 20
            {"I have great confidence in ", "'s good judgment.\n", ""},                           // 5 25
            {"Most people would react very favorably to ", " after a brief acquiantance.\n", ""}, // 6 30
            {"I think that ", " and I are quite similar to each other.\n", ""},                   // 7 35
            {"I would vote for ", " in a class or group election.\n", ""},                        // 8 40
            {"I think that ", " is one of those people who quicly wins respect.\n", ""},          // 9 45
            {"I feel that ", " is an extremenly intelligent person.\n", ""},                      // 10 50
            {"", " is one of the most likable people I know.\n", ""},                             // 11 name then sentence 55
            {"", " is the sort of person whom I myself would like to be.\n", ""},                 // 12 name then sentence 60
            {"It seems to me that it is very easy for ", " to gain admiration.\n", ""}            // 13 65

        };

    cin.get();
    cout << "Enter the name of your friend: ";
    getline(cin, name);
    cout << endl;
    // i for rows
    for (size_t i{0}; i < 13; i++){ // j for column
        for (size_t j{0}; j < 2; j++){
            if (questions[i][j] == questions[11][1] || questions[i][j] == questions[12][1]){ // call this array if the iteration met the requirement
                cout << name << questions[i][j];
            }
            cout << questions[i][j] << name;
            j++; // increment the column to call next column in same row
            cout << questions[i][j];
            j++;

            cout << "Your scale: ";
            cin >> us;        // input for scale 1-5
            cs += scales[us]; // current scale + user scale
            // show the current points
            cout << endl
                 << "Current score: " << cs << "/" << total << endl
                 << endl;
        }
    }
    // print the total/final point.
    cout << "The final score: " << cs << "/" << total << endl;
    double result = (cs / total) * 100;
    cout << setprecision(4);
    cout << result << "%"
         << " You like this person.";
}

int main(){
    // Introduction
    cout << "\n\nLOVE AND LIKE SCALE\n\n";
    cout << "This quiz are for fun only. \nThis scale are originally a research paper \nfrom 1970 by Zick Rubin.\n\n";

    cout << "Press Enter to start the quiz . . .\n";

    cin.get(); // input

    string Name, Gender[2]{"Male", "Female"}, Respond;
    int Age, gIn;

    cout << "What is your name? ";
    getline(cin, Name);
    cout << endl;

    cout << "How old are you? ";
    cin >> Age;
    cout << endl;

    cout << "What is yout gender? [0]Male, [1]Female ";
    cin >> gIn;
    Gender[gIn];

    cout << endl
         << endl;

    cout << "Here is the direction before take the quiz.\n Scale it from 1-5 otherwise the scaling will fail/error.\nGoodluck out there.\n\n";
    cout << "Are you ready to take the \nLOVE AND LIKE QUIZ? " << Name << "? yes/no\n";
    cin >> Respond;

    // Convert the string to lower case;
    for (int i = 0; i < Respond.length(); i++){
        if (Respond[i] >= 'A' && Respond[i] <= 'Z')
        {
            Respond[i] = Respond[i] + 32;
        }
    }

    if (Respond == "yes"){
        cout << "\nGood. Before we start I like you to pick between the quiz.\n\n";

        while (true){
            cout << "Type 'love' for love scale,\nand 'like' for like scale: \n\n";
            cin >> Respond;
            for (int i = 0; i < Respond.length(); i++){
                if (Respond[i] >= 'A' && Respond[i] <= 'Z'){
                    Respond[i] = Respond[i] + 32;
                }
            }
            if (Respond == "love"){
                cout << "\n\nLOVE SCALE. Goodluck!\n\n";
                loveScale();
            }
            else if (Respond == "like"){
                cout << "\n\nLIKE SCALE. Goodluck!\n\n";
                likeScale();
            }
            
            cout << "Do you want to try it again or try the other one? [1]YES [0]NO\n";
            int dec;
            cin >> dec;
            if(dec != 1){
                break;
            }
        }
        cout << "\nThank you trying this mini game. ヾ(≧▽≦*)o";
    }
    else if (Respond == "no"){
        cout << "Oh. . . Ok. ＞︿＜" << endl;
        return 0;
    }

    return 0;
}