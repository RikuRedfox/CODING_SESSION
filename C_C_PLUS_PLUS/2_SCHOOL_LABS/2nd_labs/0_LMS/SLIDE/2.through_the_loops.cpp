// Andrew Jules Miyajima - 10.22.2022
#include <iostream>

int main(){

    int n;
    std::cout << "Enter the number of rows : ";
    std::cin >> n;
    std::cout << std::endl;
    
    size_t i{0}, t;
    for(; i < n; i++){
        for(t = 0; t < n - i - 1; t++){
            std::cout << " ";
        }
        for(t = 0; t < ( i * 2 ) + 1; t++){
            std::cout << "*";
        } 
        std::cout << std::endl;
    }
    system("PAUSE");
    return 0;
}