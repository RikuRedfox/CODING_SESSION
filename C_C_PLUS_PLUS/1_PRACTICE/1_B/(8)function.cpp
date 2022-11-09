#include <iostream>
using namespace std;

// function | 6.7.2022

void sayHi(string name, int age){

    cout << "Hello User " << name << " your age are " << age << endl;

}

int main(){

    sayHi("Andrew", 19);
    sayHi("Hans", 19);
    sayHi("Alloysius", 19);

    return 0;
}