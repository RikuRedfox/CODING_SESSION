#include <iostream>

//your function
void toMinutes(int hours) {
    //complete the function
    hours *= 60 ;
    std::cout << hours << std::endl;
}

int main() {
    //call the function
    int hours;
    std::cin >> hours;
    toMinutes(hours);
    return 0;
}