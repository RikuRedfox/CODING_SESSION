#include <iostream>

int main(){
    // try to allocate a insanely huge array in one go
    // unhandled new failure : crash
    // int *lots_of_ints1{new int[100000000000000000000000]}; // may give you an error for exceeding array size

    // use a huge loop to try and exhaust the memory capabilities of your system. when new fails, your program is going to forcefuly terminate.

    /*
    for (size_t i{}; i < 100; ++i)
    {
        int *lots_of_ints2{new int [10000000000000000]};
    }
    */

    // Handling the exception

    // handle the problem in a way that makes sense for your applciation.
    for (size_t i{}; i < 10; ++i)
    {
        try
        {
            int *lots_of_ints3{new int[10000000000000000]};
        }
        catch (std::exception &ex)
        {
            std::cout << "Caught exception outselve: " << ex.what() << std::endl;
        }
    }

    // std::nothrow: ideal if you dont want exception thrown when new fails

    for (size_t i{}; i < 10; ++i)
    {
        int *lots_of_ints4{new (std::nothrow) int[10000000000000000]};

        if (lots_of_ints4 != nullptr)
        {
            std::cout << "Memory alloc failed" << std::endl;
        }
        else
        {
            std::cout << "Memory alloc succeeded" << std::endl;
        }
    }

    return 0;
}