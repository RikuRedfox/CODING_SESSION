#include <iostream>

int main(){
    size_t size{10};

    double *psalaries{new double[size]}; // salaries arry will
    // contain garbage values
    int *pstudents{new (std::nothrow) int[size]{}}; // all values initialized to 0

    double *pscore{new (std::nothrow) double[size]{1, 2, 3, 4, 5}}; // alloc memory space for an array of size double vars. First 5 will be initialized with 1,2,3,4,5. and the rest will be 0's

    if (pscore)
    {
        for (size_t i{}; i < size; ++i)
        {
            std::cout << "Value: " << pscore[i] << " : " << *(pscore + i) << std::endl;
        }
    }

    // releasing memory array

    delete[] pscore;
    pscore = nullptr;

    delete[] pstudents;
    pstudents = nullptr;

    delete[] psalaries;
    psalaries = nullptr;

    // ptrs initialized with dynamic array are different from arrays:
    // std::size doesn't work on them, and they don't support range based for loops

    double *temperatures = new double[size]{10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0};

    // std::cout << "std::size(temperatures) : " << std::size(temperatures) << std::endl; // ERROR

    // temperatures doesn't have array properties that are needed for the range based for loop to work.
    /*
    for (double temp : temperatures){
        std::cout << "temperature : " << temp << std::endl;
    }
    */

    // dynamically allocated array has decayed into a pointer

    std::cout << "=========================" << std::endl
         << std::endl;

    int score[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto s : score)
    {
        std::cout << "Value : " << s << std::endl;
    }

    return 0;
}