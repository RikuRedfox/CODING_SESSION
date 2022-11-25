#include <iostream>

int main(){
    int vision;
    std::cin >> vision;
    
    int height;
    std::cin >> height;
    //your code goes here
    if(vision == 100 && (height > 62 && height < 75 )){
        std::cout << "passed\n";
    } else{
        std::cout << "failed\n";
    }
    return 0;
}