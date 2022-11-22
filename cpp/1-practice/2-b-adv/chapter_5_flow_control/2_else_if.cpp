#include <iostream>

int main(){

    bool red (0), green (1), yellow (0), policeStop (1);

    if(green && !policeStop){
        std::cout << "GO." << std::endl;
    } 
    else if(yellow) {
        std::cout << "SLOW DOWN." << std::endl;
    } 
    else if (red){
        std::cout << "STOP." << std::endl;
    } 
    else{
        std::cout << "FUCK THE POLICE! RUN!!" << std::endl;
    }

    return 0;
}