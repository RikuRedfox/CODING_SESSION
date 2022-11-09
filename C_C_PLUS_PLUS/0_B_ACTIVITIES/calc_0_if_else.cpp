#include <iostream>

int main(){
    double x, y, result;
    char op;
    while (true){
        std::cout << "Put the calculation you want to do in here. [ex: 1 + 2]\n>>";
        std::cin >> x >> op >> y;

        if (!std::cin){
            std::cerr << "incorrect input format The program has ended.\n";
            return -1;
        }

        if (op == '+'){
            result = x + y;
        }
        else if (op == '-'){
            result = x - y;
        }
        else if (op == '*'){
            result = x * y;
        }
        else if (op == '/'){
            result = x / y;
        }
        else if (op == '%'){
            int Result = result, a = x, b = y; Result = a % b;
            std::cout << "= " << Result << std::endl;
        }
        std::cout << "= " << result << std::endl;
        
    }       
    return 0;
}