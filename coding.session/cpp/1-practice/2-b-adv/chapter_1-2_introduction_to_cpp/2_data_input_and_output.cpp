#include <iostream>
#include <string> // calling string lib

int main(){

    std::string name;
    int age;
    bool is_male = 1;

    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your age : ";
    std::cin >> age;

    std::cout << "Hello " << name << " your age are " << age << " years old." << std::endl;
    std::cout << "Is he a male? : " <<is_male;

    return 0;
}