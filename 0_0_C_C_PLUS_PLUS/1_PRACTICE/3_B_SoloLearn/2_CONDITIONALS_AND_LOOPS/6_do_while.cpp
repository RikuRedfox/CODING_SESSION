#include <iostream>

int main()
{
    int purchaseAmount = 0;
    double totalPrice;
    
    //your code goes here
    do{
        std::cin >> totalPrice;
        totalPrice = totalPrice *.15;
        std::cout << totalPrice << std::endl;
        purchaseAmount++;
    }while(purchaseAmount < 3);
    
    return 0;
}