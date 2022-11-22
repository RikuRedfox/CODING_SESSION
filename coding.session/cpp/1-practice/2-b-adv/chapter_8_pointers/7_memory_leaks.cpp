#include <iostream>

int main(){
    int *pnumber{new int{68}}; // points to some address, lets call that address 1

    delete pnumber;
    pnumber = nullptr;
    // should be deleted and reset here.

    int number{55}; // lives at address2

    pnumber = &number;
    // pnumber points to address2, but address 1 is still in use by a program. but this program has lost access to that memory location... memory has benn leaked.

    // double alloc

    int *pnumber1{new int{55}};

    delete pnumber1;
    pnumber1 = nullptr;
    // use the ptr

    // s hould delete and rest here.

    pnumber1 = new int{22}; // memory with int 55 leaked;

    // nested scopes with dynamically alloc memory
    {
        int *pnumber2{new int{57}};
        // use the dynamic memory
    }
    // memory with int{57} leaked

    return 0;
}