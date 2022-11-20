#include <iostream>

int main() {
        double points;
        std::cin >> points;

        //your code goes here
        if(points >= 90){
            std::cout << "pass\n";
        }else{
            std::cout << "fail\n";
        }
	return 0;
}