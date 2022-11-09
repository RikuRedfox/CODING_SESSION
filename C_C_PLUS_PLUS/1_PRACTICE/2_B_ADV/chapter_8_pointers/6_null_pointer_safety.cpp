#include <iostream>

int main(){
    // nullptr check

    int *pnumber{}; // nullptr
    // pnumber= new int (9);

    if (!(pnumber == nullptr))
    {
        std::cout << "pnumber points to a VALID addres: " << pnumber << std::endl;
        std::cout << "*pnumber: " << *pnumber << std::endl;
    }
    else
    {
        std::cout << "pnumber points to an INVALID address." << std::endl;
    }

    // compact
    if (pnumber)
    {
        std::cout << "pnumber points to a VALID address: " << pnumber << std::endl;
        std::cout << "*pnumber: " << *pnumber << std::endl;
    }
    else
    {
        std::cout << "pnumber points to an INVALID address" << std::endl;
    }

    delete pnumber;
    nullptr;

    // calling delete on a nulltr is ok
    int *pnumber1{};

    delete pnumber1; // this wont cause a problem if contains nullptr

    // so no need to overdo something like this
    // if (pnumber1)
    // {
    //     delete pnumber1;
    //     pnumber1 = nullptr;
    // }

    return 0;
}