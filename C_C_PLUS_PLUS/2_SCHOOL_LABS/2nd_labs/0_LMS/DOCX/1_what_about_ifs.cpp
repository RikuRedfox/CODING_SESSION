#include <iostream>

int gl_a {1};

void if_else(){
    int lc_a {2}, lc_b {3};

    if(1){
        lc_a = 20;
    } else{
        lc_b = lc_b++;
    }
    std::cout << "gl_a : " << gl_a << std::endl;
    std::cout << "lc_a : " << lc_a << std::endl;
    std::cout << "lc_b : " << lc_b << std::endl;
    std::cout << "IF ELSE END." << std::endl;
}
void if_else_if(){
    int a{123}, b{1};
    if(b == 1){
        a = a * 1;
    } else if(b == 2){
        a = a * 2;
    } else {
        a = a * 3;
    }
    std::cout << "a : " << a << std::endl;
    std::cout << "IF ELSE IF END." << std::endl;
}
void switch_stmt(){
    int a {123}, b{1};
    switch(b){
        case 1: a = a * 1; break;
        case 2: a = a * 2; break;
        case 3: a = a * 3; break;
        default: a = a * 10; break;
    }
    std::cout << "a : " << a << std::endl;
    std::cout << "SWTICH STMT END." << std::endl;
}
void if_swtich_else(){
    int a {123}, b{1};
    if(b < 3 && b > 0){
        a = 321;
        switch(b){
            case 1: a = a * 2; break;
            case 2: a = a * 3; break;
        } 
    } else {
        a = a * 4;
    }
    std::cout << "a : " << a << std::endl;
    std::cout << "IF SWITCH ELSE END." << std::endl;
}

int main(){
    if_else();
    if_else_if();
    switch_stmt();
    if_swtich_else();

    system("PAUSE");
    return 0;
}