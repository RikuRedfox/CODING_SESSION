#include <iostream>

int main() {
    double items[] = {500, 12.4, 94, 45, 3, 81, 1000.9, 85, 90, 1, 35};
    int p;
    std::cin >> p;
    
    //your code goes here
    for(int i {}; i < 11; i++){
        std::cout << (items[i]-items[i]*p/100) << " ";
    }
    
    return 0;
}
