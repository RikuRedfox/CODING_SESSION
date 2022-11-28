// Andrew Jules Miyajima - 10.22.2022
#include <iostream>

void pause(){
    std::cout << std::endl;
    std::cout << "Press any key to continue...";
    std::cin.get();
}

int main(){

    char a[] {"Hellow World"};
    std::cout << "The value of 'a' is " << a << std::endl;
    std::cout << "The address of 'a' is " << &a << std::endl;
    std::cout << "The address of 'a[1]' is " << (void*)&a[1] << std::endl;

    pause();
    return 0;
}