#include <iostream>
#include <cstdlib>

int main() {
    srand(0);
    int range;
    std::cin >> range;
    //your code goes here
    int pin[4];
    for(int i = 0; i < 4; i++){
        pin[i] = 1 + rand() % range;
    }
    std::cout << pin[0] << pin[1] << pin[2] << pin[3]; 
    
    return 0;
}
