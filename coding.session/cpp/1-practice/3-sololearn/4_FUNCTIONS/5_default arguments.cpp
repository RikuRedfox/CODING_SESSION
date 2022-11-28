#include <iostream>
#include <string>

//complete the function with one default argument
void printOrder(std::string order, std::string bt = "Black tea") {
    std::cout << bt << "\n" << order;
}

int main() {
    //getting coffee type
    std::string friendOrder;
    std::cin >> friendOrder;
    
    printOrder(friendOrder);
    
    return 0;
}
