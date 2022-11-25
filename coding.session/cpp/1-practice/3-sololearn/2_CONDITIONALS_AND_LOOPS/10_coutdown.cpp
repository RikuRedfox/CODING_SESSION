#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    //your code goes here
    // while(n > 0){
    //     std::cout << n << "\n";
    //     if(n%5 == 0){
    //         std::cout << "Beep\n";
    //     }
    //     n--;
    // }
    do{
        std::cout << n << "\n";
        if(n%5 == 0){
            std::cout << "Beep\n";
        }
        n--;
    }while(n > 0);
    
    return 0;
}