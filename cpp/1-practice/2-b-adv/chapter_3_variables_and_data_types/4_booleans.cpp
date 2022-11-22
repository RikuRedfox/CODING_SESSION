#include <iostream>
#include <iomanip>

int main(){

    bool truth {1}, falsee {0};

    std::cout << std::boolalpha; // to see the 'true' and 'false' instead of 0s and 1s.
    std::cout << "Truth value : " << truth << std::endl;
    std::cout << "False value : " << falsee << std::endl;

    return 0;
}