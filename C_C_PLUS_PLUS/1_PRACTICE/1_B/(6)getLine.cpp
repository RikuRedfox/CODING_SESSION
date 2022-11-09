#include <iostream>
#include <string>
using namespace std;

// more on strings | 6.6.2022

int main(){

    string name;
    cout << "Enter your name: ";
    getline(cin, name); // get the full lenght of the user input. compare to cin >> name, it only takes the first word.

    cout<< "Hello! "<< name;

    return 0;
}