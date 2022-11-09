#include <iostream>

int main(){

    char hello = 97; // 65 = A 66 = B 67 = C etc... 97 = a 98 = b 99 = c etc...

    std::cout << "Char value : " << hello << std::endl;
    std::cout << "Char value(int) : " << static_cast<int>(hello) << std::endl;

    char char1{'H'};
    char char2{'E'};
    char char3{'L'};
    char char4{'L'};
    char char5{'O'};
    char char6{'W'};

    std::cout << char1 << std::endl;
    std::cout << char2 << std::endl;
    std::cout << char3 << std::endl;
    std::cout << char4 << std::endl;
    std::cout << char5 << std::endl;
    std::cout << char6 << std::endl;
    
    return 0;
}