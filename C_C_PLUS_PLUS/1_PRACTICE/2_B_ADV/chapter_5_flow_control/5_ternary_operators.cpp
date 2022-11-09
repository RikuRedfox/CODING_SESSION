#include <iostream>

int main(){

    int max {}, a{59}, b{30};

    /*
    if(a > b){
        max = a;
    } else{
        max = b;
    }
    */

    max = (a > b)? a : b;

    std::cout << "Max: " << max << std::endl;

    return 0;
}