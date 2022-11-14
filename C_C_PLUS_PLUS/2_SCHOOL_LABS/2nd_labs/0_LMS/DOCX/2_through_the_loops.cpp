#include <iostream>

int main(){
    int i {0};

    while( i < 9 ){
        std::cout << i << ". Mellow World!" << std::endl;
        i++;
    } 
    std::cout << "\n\tWHILE LOOP END.\n\n"; 
    i = 0;

    do{
        std::cout << i << ". Mellow World!" << std::endl;
        i++;
    }while( i < 9 );
    std::cout << "\n\tDO_WHILE LOOP END.\n\n"; 
    i = 0;

    for( i; i < 9; i++ ){
        std::cout << i << ". Mellow World!" << std::endl;
    } 
    std::cout << "\n\tFOR LOOP END.\n\n"; 
    i = 0;

    return 0;
}