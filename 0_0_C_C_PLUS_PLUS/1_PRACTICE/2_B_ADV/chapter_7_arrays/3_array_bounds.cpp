#include <iostream>

int main(){
    int numbers[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    std::cout << numbers[12] << std::endl; // garbage shit

    numbers[12] = 100; // modifying
    std::cout << numbers[12];

    // numbers[1299999] = 1000;
    // std::cout << numbers[12999999]; // crush

    std::cout << "Program ending . . ." << std::endl;
    return 0;
}