#include <iostream>

int max(int num1, int num2) {
    int result;
    if(num1 > num2){
        result = num1;
    } else{
        result = num2;
    }
    return result;
}

int main() {
    //getting inputs
    int first;
    std::cin >> first;
    int second;
    std::cin >> second;
    
    //call the function and print result
    std::cout << max(first, second) << std::endl;
    
    
    return 0;
}