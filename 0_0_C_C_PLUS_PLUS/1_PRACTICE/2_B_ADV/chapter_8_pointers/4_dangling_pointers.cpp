#include <iostream>

int main(){
    // uninitialized ptr
    int *pNumber; // Dangling uninitialized pointer
    std::cout << std::endl;
    std::cout << "c1: Uninitialized ptr: " << std::endl;
    std::cout << "pNumber: " << pNumber << std::endl;
    // std::cout << "*pNumber: " << *pNumber << std::endl; // crash

    // deleted ptr
    std::cout << std::endl;
    std::cout << "c2: Deleted ptr: " << std::endl;

    int *pNumber1{new int{67}};
    std::cout << "pNumber1 (beforedelete): " << *pNumber1 << std::endl;

    delete pNumber1;
    std::cout << "*pNumber1(afterdelete): " << *pNumber1 << std::endl;

    // multiple ptr pointing to same address

    std::cout << std::endl;
    std::cout << "c3: Multiple pointers pointing to same address: " << std::endl;

    int *pNumber2{new int{83}};
    int *pNumber3{pNumber2};

    std::cout << "pNumber2: " << pNumber2 << " - " << *pNumber2 << std::endl;
    std::cout << "pNumber3: " << pNumber3 << " - " << *pNumber3 << std::endl;

    // delete
    delete pNumber2;

    std::cout << "pNumber3(after deleting pNumber2): " << pNumber3 << " - " << *pNumber3 << std::endl; // garbage or crash

    // sol1: initialize your ptr immediately upon declaration
    std::cout << "\nSol 1: " << std::endl;
    int *pNumber4{nullptr};
    int *pNumber5{new int{56}};

    // check for nullptr before use
    if (pNumber5 != nullptr)
    {
        std::cout << "*pNumber6: " << *pNumber5 << std::endl;
    }
    else
    {
        std::cout << "Invalid address" << std::endl;
    }

    // sol 2: after call a delete ptr, remeber to reset so it doesn't point anywere.

    std::cout << std::endl;
    std::cout << "Sol 2: " << std::endl;
    int *pNumber6{new int{82}};

    // use the ptr however you want
    std::cout << "pNumber6 : " << pNumber6 << " - " << *pNumber6 << std::endl;

    delete pNumber6;
    pNumber6 = nullptr;

    // check for nullptr before use
    if (pNumber6 != nullptr)
    {
        std::cout << "pNumber6: " << pNumber6 << std::endl;
    }
    else
    {
        std::cout << "Invalid address" << std::endl;
    }

    // sol 3: make sure there is one clear ptr (mstr ptr) that owns the memory (responsible for releasing when necessary)

    std::cout << std::endl;
    std::cout << "Sol 3: " << std::endl;
    int *pNumber7{new int{1234}}; // master ptr
    int *pNumber8{pNumber7};

    std::cout << "pNumber7 : " << pNumber7 << " - " << *pNumber7 << std::endl;

    if (!(pNumber7 == nullptr))
    { // use slave ptr when mstr ptr is valid
        std::cout << "pNumber8 - " << pNumber8 << " - " << *pNumber8 << std::endl;
    }

    delete pNumber7;
    pNumber7 = nullptr;

    if (!(pNumber7 == nullptr))
    { // use slave ptr when mstr ptr is valid
        std::cout << "pNumber7 - " << pNumber8 << " - " << *pNumber8 << std::endl;
    }
    else
    {
        std::cerr << "WARNING: TRYING TO USE AN INVALID PTR" << std::endl;
    }

    // 11:17:03

    return 0;
}