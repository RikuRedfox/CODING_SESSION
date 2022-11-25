// Quiz 1 netacad
#include <iostream>
#include <cmath> // use in f

void a(){
    int var;

    var = 10; 
    var = var + var;
    std::cout << var; // 20
}

void b(){
    float var = .1;

    var = var + 1.;
    var = var + 1e1;
    var = var + 1e-2;
    std::cout << var; // 11.11
}

void c(){
    int i = 10, j = 1;
    int k = (i % j + i / 3) / (j % i - j / i);
    std::cout << k; // 1
}

void d(){
    int i, j;
    std::cin >> i; // if user in 10
    j = i;

    if(i >= 9)
        i += 9 - i;

    j /= i;
    std::cout << j; // out 1
}

void e(){
    float a, b;

    std::cin >> a; // if user in 3.0
    b = a / 2;

    if(b >= 1)
        a += b;
    else if (a > b)
        b += a;

    std::cout << a + b; // out 10.5
}

void f(){
    float a;

    std::cin >> a; // if user in 2.0
    a += a; 
    a += a;
    a = sqrtf(a) * sqrtf(a);
    std::cout << a; // out 8 | but quiz says 16 :p
}

int main(){

    // cannot be used as a variable name
    // exactly one function named 'main'
    // is an integer coded as an octal number
    // a(); // out 20
    // b(); // out 11.11
    // c(); // out 1
    // if X = 88 the Z = 90
    // d(); // out 1
    // e(); // out 10.5
    // f(); // out 8 | but quiz says 16 :p

    return 0;
}