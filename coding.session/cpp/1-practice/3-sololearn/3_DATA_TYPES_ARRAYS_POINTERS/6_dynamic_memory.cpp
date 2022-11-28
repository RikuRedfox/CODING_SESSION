#include <iostream>

int main() {
    int* n = new int;
    std::cin >> *n;

    int* nums = new int;
    std::cin >> *nums;

    int* max = new int;
    *max = *nums;
    for(int i = 1; i < *n; i++){
        std::cin >> *nums;
        if( *nums > *max ){
            *max = *nums;
        }
    }
    std::cout << *max << std::endl;

    delete n;
    delete nums;
    delete max;

    return 0;
}