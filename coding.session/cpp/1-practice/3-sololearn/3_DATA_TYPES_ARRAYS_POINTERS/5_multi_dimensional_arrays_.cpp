#include <iostream>
#include <string>

int main() {
    
    std::string arr[3][3] = {
        {"Python", "JS", "C++"},
        {"PHP", "SQL", "Java"},
        {"C#", "Swift", "Kotlin"},
    };
    // your code goes here
    std::cout << arr[0][2];
    
    return 0;
}