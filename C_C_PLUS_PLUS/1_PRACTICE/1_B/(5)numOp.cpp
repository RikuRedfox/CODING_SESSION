#include <iostream>
#include <cmath>
using namespace std;

//numbers/operations | 6.6.2022
//cmath is advance math function in c++.

int main(){

    int myNum = 22;

    myNum++;

    cout << myNum <<endl;
    cout << 10%3 << endl;
    cout << 10.0/3.0 << endl
    << 10/3 << endl
    << (4+2)*10;
    cout << sqrt(89) << endl //square root function
    << pow(3,8) << endl    //raise to the power.
    << round(4.912341) << endl //round the number.
    << ceil(4.212341) << endl //round the number increment.
    << floor(4.912341) << endl //round the number but decrement.
    << fmax(4, 22) << endl //find the biggest number between the two number.
    << fmin(4, 22); //find the smallest number between the two num.

    return 0;

}