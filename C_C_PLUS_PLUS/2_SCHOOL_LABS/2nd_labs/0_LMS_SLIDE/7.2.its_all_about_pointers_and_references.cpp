// Andrew Jules Miyajima - 10.22.2022
#include <iostream>

void pause(){
    std::cout << std::endl;
    std::cout << "Press any key to continue...";
    std::cin.get();
}

int main(){

    int a{100};
    int* b{&a};
    
    std::cout << "The value of 'a' is " << a << std::endl;
    std::cout << "The value of 'b' is " << b << std::endl;
    std::cout << "The value of 'b' is " << *b << std::endl;

    std::cout << std::endl;

    a = 200;
    std::cout << "The value of a is " << a << std::endl;
    std::cout << "The value of b is " << *b << std::endl;

    pause();
    return 0;
}