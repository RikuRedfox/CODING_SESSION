#include <iostream>

int main() {
    int ages[5];

    for (int i = 0; i < 5; ++i) {
        std::cin >> ages[i];
    }
    //your code goes here
    int min = ages[0];
    for(int i = 1; i < 5; ++i) {
        if(ages[i] < min)
            min = ages[i];
    }
    std::cout << 50 - (min/100. * 50);
    
    return 0;
}