#include <iostream>
using namespace std;

int main(){

    int age = 19;
    int *pAge = &age;
    double gpa = 1.25;
    double *pGPA = &gpa;
    string name = "Andrew";
    string *pName = &name;

    // Memory Address
    cout << pAge << endl
        << pGPA << endl 
        << pName << endl;

    // dereference
    cout << *pAge << endl
        << *pGPA << endl 
        << *pName << endl;

    // Original value
    cout << age << endl
        << gpa << endl 
        << name << endl;

    // Memory Adress
    cout << &age << endl
        << &gpa << endl 
        << &name << endl;

    // dereference 
    cout << *&age << endl
        << *&gpa << endl 
        << *&name << endl;

    return 0;
}