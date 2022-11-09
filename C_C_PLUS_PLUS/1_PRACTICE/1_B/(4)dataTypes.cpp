#include <iostream>
using namespace std;

//Data types and strings | 6.6.2022

int main(){

    char grade = 'A';
    string para = "I have grade mark ", remark;
    int age = 19;
    double gpa1 = 1.25;
    float gpa2 = 1.25f;
    bool isMale = true;

    if(80>75){
        remark = "Passed";
    } else {
        remark = "Failed";
    }

    cout<<remark<<endl;
    cout<<para.length()<<endl;
    cout<<para[0]<<para[3]<<endl;
    cout<<para.find("have", 0)<<endl;
    cout<<para.substr(9,5);
}