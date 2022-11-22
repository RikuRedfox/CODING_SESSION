#include <iostream>

int main(){
      // used ptr
#if 0
    int number{2};

    int *pNumber = &number;

    std::cout << "\nDeclating ptr and assigning address: \n";
    std::cout << "number: " << number << std::endl;
    std::cout << "pNumber: " << pNumber << std::endl;
    std::cout << "&number: " << &number << std::endl;
    std::cout << "*pNumber: " << *pNumber << std::endl;

    int *pNumber1; // uninitialize ptr, junk address
    int number1{12};
    pNumber1 = &number1; // Make it point to a valid address
    std::cout << "Uninitialized ponter: " << *pNumber1 << std::endl;
    std::cout << "*pNumber: " << *pNumber1 << std::endl;

    // krazy bad things shet

    // writing into uninitialized ptr through dereference
    int *pNumber2; // junk address
    // *pNumber2 = 555; // wrting into junk address : bad
    std::cout << "Writing into uninitialized ptr through dereference" << std::endl;
    std::cout << "pNumber2: " << pNumber2 << std::endl;
    // std::cout << "*pNumber2: " << *pNumber2 << std::endl; // crashg


    // Initializing ptr to null
    int *pNumber3{}; // initialized ptr equivalent of zerp : nullptr, a ptr pointin nowhere

    // *pNumber3 = 33; // writting into a ptr pointer nowhere : bad shit crashh.

    std::cout << "\nReading and wrting through nullptr: " << std::endl;
    std::cout << "pNumber3: " << pNumber3 << std::endl;
    // std::cout << "*pNumber3: " << *pNumber3 << std::endl; // Reading from nullptr // crash

    std::cout << "\n\nDynamic Heap Memory\n";
    int *pNumber4{nullptr};
    pNumber4 = new int; // Dynamically allocate space int on the heap. This memory belongs to this program. the system can't use it for anything else, until we return it. after this line executes, well have a valid memory lovation, allocated the size of the the allocated memory will be such that it can store the type pointed too be the ptr.

    *pNumber4 = 888; // wrting into dynamicall ycallocated memory
    std::cout << "\nDynamically allocation memory: " << std::endl;
    std::cout << "*pNumber4: " << *pNumber4 << std::endl;

    delete pNumber4;
    pNumber4 = nullptr;
    // std::cout << "Wtriting to bad memory\n";
    // *pNumber4 = 45;
    // std::cout << "Done!" << std::endl; // crash
#endif
#if 1
    // possible to initialize the ptr with valid address on declatration. not with a nullptr
    int *pNumber5{new int};     // junk value
    int *pNumber6{new int(22)}; // use direct initialization
    int *pNumber7{new int{23}}; // use uniform initialization

    std::cout << std::endl;
    std::cout << "Initialize with valid memory address at declaration: " << std::endl;
    std::cout << "pNumber5: " << pNumber5 << std::endl;
    std::cout << "*pNumber5: " << *pNumber5 << std::endl;

    std::cout << "pNumber6: " << pNumber6 << std::endl;
    std::cout << "*pNumber6: " << *pNumber6 << std::endl;

    std::cout << "pNumber7: " << pNumber7 << std::endl;
    std::cout << "*pnumber7: " << *pNumber7 << std::endl;

    // release the memory

    delete pNumber5;
    pNumber5 = nullptr;

    delete pNumber6;
    pNumber6 = nullptr;

    delete pNumber7;
    pNumber7 = nullptr;

    // reuse ptr
    pNumber5 = new int(81);
    std::cout << "pNumber5: " << *pNumber5 << std::endl;

    delete pNumber5;
    pNumber5 = nullptr;

    pNumber5 = new int(99);
    std::cout << "*pNumber5: " << *pNumber5 << std::endl;

    delete pNumber5;
    // delete pNumber5 // dont do this.
#endif
    return 0;
}