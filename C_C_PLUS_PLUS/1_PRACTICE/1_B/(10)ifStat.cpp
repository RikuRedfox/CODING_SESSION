#include <iostream>

using namespace std;

//if statement | 6.7.2022

int main(){

    bool isMale = true;
    bool isTall = false;

    if(isMale && isTall){
        cout << "You are a tall male";
    } else if(isMale && !isTall){
        cout << "You are short male";
    } else if(!isMale && isTall){
        cout << "You are tall but not male";
    }else {
        cout << "You are not a male and tall";
    }

    cout << endl;

    if(isMale || isTall){
        cout << "You are a tall male";
    } else if(isMale || !isTall){
        cout << "You are short male";
    } else if(!isMale || isTall){
        cout << "You are tall but not male";
    }else {
        cout << "You are not a male and tall";
    }

    return 0;
}