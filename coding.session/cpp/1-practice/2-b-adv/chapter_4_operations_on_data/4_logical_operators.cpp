#include <iostream>

int main(){
    
    bool log1, log2;
    std::cout << std::boolalpha;
    
    std::cout << "Logical '&&'\n\n"; // 'AND' Logical one false all false

    log1 = false;
    log2 = false;
    std::cout << "log1 && log2: " << (log1 && log2) << std::endl;

    log1 = true; 
    log2 = true;
    std::cout << "log1 && log2: " << (log1 && log2) << std::endl;

    log1 = false; 
    log2 = true;
    std::cout << "log1 && log2: " << (log1 && log2) << std::endl;

    log1 = true; 
    log2 = false;
    std::cout << "log1 && log2: " << (log1 && log2) << std::endl;

    std::cout << "\n\nLogical '||'\n\n"; // 'OR' Logical; one true all true

    log1 = false; 
    log2 = false;
    std::cout << "log1 && log2: " << (log1 || log2) << std::endl;

    log1 = true; 
    log2 = true;
    std::cout << "log1 && log2: " << (log1 || log2) << std::endl;

    log1 = false; 
    log2 = true;
    std::cout << "log1 && log2: " << (log1 || log2) << std::endl;
    
    log1 = true; 
    log2 = false;
    std::cout << "log1 && log2: " << (log1 || log2) << std::endl;

    std::cout << "\n\nLogical '!'\n\n"; // 'NOT' logical; reverse card.

    log1 = false; 
    log2 = false;
    std::cout << "log1 || log2: " << (!log1 || log2) << std::endl;
    std::cout << "!(log1 && !log2) || !log1: " << (!(log1 && !log2) || !log1) << std::endl;

    return 0;
}