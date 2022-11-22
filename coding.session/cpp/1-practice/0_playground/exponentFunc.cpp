#include <iostream>
using namespace std;
// 6 - 8 - 2022
int power (int baseNum, int powNum){

    int result = 1;

    for(int i = 0; i < powNum; i++){
        result = result * baseNum;
    }

    return result;
}

int main(){

    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << power(num1, num2);

    return 0;
}