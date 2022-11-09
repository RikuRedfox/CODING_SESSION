#include <iostream>

int main(){

    int set_of_numbers[]{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    for (auto value : set_of_numbers){
        std::cout << value << std::endl;
    }

    return 0;
}