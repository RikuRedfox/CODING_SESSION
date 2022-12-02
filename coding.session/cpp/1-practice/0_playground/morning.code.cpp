#include <iostream>

int main(){

    // Morning code.
    try{
        wakeUpAndGoToWork();
    }catch( IFeelLazy e ){
        sleep();
    }

    return 0;
}