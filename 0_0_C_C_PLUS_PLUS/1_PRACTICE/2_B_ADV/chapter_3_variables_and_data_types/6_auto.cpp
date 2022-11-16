#include <iostream>

int main(){

    auto var1{12};      // int
    auto var2{13.0};    // double
    auto var3{14.0f};   // float
    auto var4{15.0l};   // long double
    auto var5{'Y'};     // char
    auto var6{123u};    // unsigned int
    auto var7{123ul};   // unsigned long
    auto var8{123ll};   // long long
    auto var9{"Hello"}; // string

    std::cout << var1 << std::endl;
    std::cout << var2 << std::endl;
    std::cout << var3 << std::endl;
    std::cout << var4 << std::endl;
    std::cout << var5 << std::endl;
    std::cout << var6 << std::endl;
    std::cout << var7 << std::endl;
    std::cout << var8 << std::endl;
    std::cout << var9 << std::endl;

    std::cout << "\n---- BYTES ----\n";
    std::cout << std::endl;

    std::cout << sizeof(var1) << std::endl;
    std::cout << sizeof(var2) << std::endl;
    std::cout << sizeof(var3) << std::endl;
    std::cout << sizeof(var4) << std::endl;
    std::cout << sizeof(var5) << std::endl;
    std::cout << sizeof(var6) << std::endl;
    std::cout << sizeof(var7) << std::endl;
    std::cout << sizeof(var8) << std::endl;
    std::cout << sizeof(var9) << std::endl;

    return 0;
}