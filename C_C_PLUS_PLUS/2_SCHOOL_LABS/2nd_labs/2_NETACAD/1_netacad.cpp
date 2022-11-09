// CPPE_1 Module 1 test
#include <iostream>

void a(){
    float x = 1. / 2. + 2. / 4.;
    std::cout << x;
}

void b(){
   int k = 1 % 2 + 4 % 2;
   std::cout << k; 
}

void c(){
    int i = 3, j, k;

    if(i > 0) {
        j = 2 + i * i;
    }
    if(i <= 0) {
        j = 2 * i - 1;
    }
    if(j >= 0) {
        k = j % i + 2;
    }
    if(j < 0) {
        k = i % j + 2;
    }
    if(k < 0) {
        k = k % i % j;
    }
    if(k >= 0) {
        k = j % i % k;
    }

    std:: cout << i << "\t" << j << "\t" << k;
}

void d(){
    float x;

    std::cin >> x;
    std::cout << std::scientific << "x";
}

void e(){
    int i;

    std::cin >> i;
    std::cout << i << std::hex << i+i << std::oct << i; 
}

void f(){
    int i = 3, j = ++i, k = ++i;
    std::cout << k << j << i;
}

void g(){
    int i = 3, j = ++i, k = ++i;

    std::cin >> i;
    std::cout << k + i << j - i << i * i;
}

void h(){
    float x = 1.0 / 4.0;
    int i = x;
    std::cout << i;
}

void i(){
    int i = 3, j = 2, k = -1;

    if(i > 0){
        if(j <= 0){
            if(k < 0)
                k++;
            if(k <= 0)
                k--;
        }
        if(j > 0)
            i++;
    }
    if(i <= 0)
        j++;
    k = i + j + k;
    std::cout << k;
}

void j(){
    int i = 1;
    int j = ++i;
    int k = j++;
    std::cout << k;
}

int main(){

    // a(); // outp 1
    // b(); // outp 1
    // c(); // outp 2
    // d(); // inp 2.5 outp x
    // e(); // inp 8 outp 81010
    // invalid var name 'auto'
    // f(); // outp 545
    // g(); // inp 5 outp 10-125
    // 0e1 = 0
    // 010 = invalid
    // h(); // outp 0
    // i(); // outp 5
    // 3.14
    // first_literal_is_invalid
    // X10 = invalid
    // -1e-1 = -0.1
    // j(); // outp 2
    // 0x1A = 26
    // 010 = 8
    // 3'14

    return 0;
}