// Andrew Jules Miyajima - 10.22.2022
// OOP (5) and Inheritance (6)
#include <iostream>
#include "6.math.hpp"

int main(){

    Subject comp("Computer Programming 1", "IT6200A", 3);
    Math math;

    std::cout << "Subject Details : " << comp.get_subject() << std::endl;
    std::cout << "Subject Details : " << math.get_subject() << std::endl;

    return 0;
}