#include <iostream>

int main(){

    // can't put sign in "unsigned" example -5, that will be a compiler error. but it can be positive sign.

    // 2 bytes
    short short_var{-32768};
    short int short_int{455};
    signed short sign_short{+122};
    signed short int sign_short_int{-456};
    unsigned short int unsign_short_int{+456};

    std::cout << short_var << std::endl;
    std::cout << short_int << std::endl;
    std::cout << sign_short << std::endl;
    std::cout << sign_short_int << std::endl;
    std::cout << unsign_short_int << std::endl;

    // 4 bytes
    int int_var{55};
    signed sign_var{66};
    signed int sign_int{77};
    unsigned int unsign_int{777};

    std::cout << int_var << std::endl;
    std::cout << sign_var << std::endl;
    std::cout << sign_int << std::endl;
    std::cout << unsign_int << std::endl;

    // 4 bytes or 8 bytes
    long long_var{88};
    long int long_int{33};
    signed long signed_long{44};
    signed long int sign_long_int{44};
    unsigned long int unsigned_long_int{44};

    std::cout << long_var << std::endl;
    std::cout << long_int << std::endl;
    std::cout << signed_long << std::endl;
    std::cout << sign_long_int << std::endl;
    std::cout << unsigned_long_int << std::endl;

    // 8 bytes
    long long longa_dog{888};
    long long int longa_dog_int{999};
    signed long long singed_longa_dog{444};
    signed long long int signed_longa_dog_int{1234};
    unsigned long long int unsigned_longa_dog_int{1234};

    std::cout << longa_dog << std::endl;
    std::cout << longa_dog_int << std::endl;
    std::cout << singed_longa_dog << std::endl;
    std::cout << signed_longa_dog_int << std::endl;
    std::cout << unsigned_longa_dog_int << std::endl;
    
    return 0;
}