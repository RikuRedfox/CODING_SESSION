#include <iostream>
using namespace std;

//String and variables | 6.6.2022

int main(){

    string character_gender, character_sex, character_name;
    int character_age;

    cout<<"Pick either He/Man or She/Woman: ";
    cin>>character_gender>>character_sex;
    cout<<"Type the name you want: ";
    cin>>character_name;
    cout<<"Type the age of the character: ";
    cin>>character_age;

    cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    
    cout<<"There once was a "<<character_sex<<" named "<<character_name<<endl;
    cout<<character_gender<<" was "<<character_age<<" years old "<<endl;
    cout<<character_gender<<" liked the name "<< character_name<<endl;
    cout<<"But did not like being "<<character_age<<endl;
    
    return 0;
}