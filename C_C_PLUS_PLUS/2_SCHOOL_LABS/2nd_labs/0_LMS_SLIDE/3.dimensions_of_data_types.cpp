// Andrew Jules Miyajima - 10.22.2022
#include <iostream>

int main(){

    int n;
    std::cout << "Enter the number of elements : ";
    std::cin >> n;

    int x[n], i{0};
    for(; i < n; i++){
        std::cout << "Number[" << i << "] : ";
        std::cin >> x[i];
    }
    std::cout << std::endl;

    int sum{0};
    for(i = 0 ; i < n; i++){
        sum = sum + x[i];
    }

    std::cout << "The sum of this " << n << " number(s) is : " << sum << std::endl;

    return 0;
}