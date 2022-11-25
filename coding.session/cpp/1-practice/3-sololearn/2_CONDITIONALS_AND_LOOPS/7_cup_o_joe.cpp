#include <iostream>

int main(){

   int choice = 0;
    cin >> choice;
    /*1 - Latte
    2 - Americano
    3 - Espresso
    4 - Cappuccino
    5 - Macchiato */
    
    //your code goes here
    switch(choice){
        case 1:
            std::cout << "Latte" << std::endl;
            break;
        case 2:
            std::cout << "Americano" << std::endl;
            break;
        case 3:
            std::cout << "Espresso" << std::endl;
            break;
        case 4:
            std::cout << "Cappuccino" << std::endl;
            break;
        case 5:
            std::cout << "Macchiato" << std::endl;
            break;
    }

    return 0;
}