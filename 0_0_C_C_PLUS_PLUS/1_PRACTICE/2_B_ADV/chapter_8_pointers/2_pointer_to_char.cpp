#include <iostream>

int main(){
    char *pCharVar{nullptr};
    char charVar{'A'};

    pCharVar = &charVar;

    std::cout << "Stored value in pCharVar is: " << *pCharVar << std::endl;

    char charVar1{'C'};
    pCharVar = &charVar1;

    std::cout << "Stored value in pCharVar is: " << *pCharVar << std::endl;

    std::cout << "\n\n";

    const char *pMessage{"Hello World!"}; // compiler is not happy to this

    std::cout << "The message is: " << pMessage << std::endl;
    std::cout << "The value stored at pMessage is : " << *pMessage << std::endl;

    /*
    *pMessage = 'B'; // CRRUSH
    cout << "The message is: " << pMessage << std::endl;
    cout << "The value stored at pMessage is : " << *pMessage << std::endl;
    */

    char message2[]{"HELLOW THERE!"};
    message2[0] = 'T';
    std::cout << "message2: " << message2 << std::endl;

    return 0;
}