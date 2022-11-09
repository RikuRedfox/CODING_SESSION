#include <iostream>

int main(){
    char hello[]{'H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D', '!', '\0'}; // '\0' is the end of the array w/o it will print a garbage shit.
    char helloStr[]{"Hello World!"};                                                // act like a string func some called it C-string.
    std::cout << "Normal char: " << hello << std::endl;
    std::cout << "C-String: " << helloStr << std::endl;

    int numbers[]{1, 2, 3, 4, 5};
    std::cout << "Numbers: " << *numbers << std::endl;
    return 0;
}