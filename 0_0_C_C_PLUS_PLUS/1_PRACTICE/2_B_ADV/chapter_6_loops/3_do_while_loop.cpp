#include <iostream>

int mina(){
    size_t i {1}, COUNT{1000};
    do{
        std::cout << i << ": I love you Katou Megumi." << std::endl;
        ++i;
    } while ( i <= COUNT );
    return 0;
}