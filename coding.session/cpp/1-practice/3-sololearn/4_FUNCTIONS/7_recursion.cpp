#include <iostream>

int recSum(int n) {
    //complete the function
    if(n == 1){
        return 1;
    } else {
        return n + recSum(n-1);
    }
}

int main() {
    //getting input
    int n;
    std::cin >> n;
    
    //call the recursive function and print returned value
    std::cout << recSum(n);
    
    return 0;
}