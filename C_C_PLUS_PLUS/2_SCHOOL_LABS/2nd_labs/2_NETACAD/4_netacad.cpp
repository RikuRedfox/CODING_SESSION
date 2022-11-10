#include <iostream>
#include <string>
#include <vector>

namespace SpaceA { // q6
    int A;
}
namespace SpaceB { // q6
    int A;
}   // using namespace SpaceA, SpaceB; // unessesary
namespace S{ // q8
    int A = 1;
}
namespace S{ // q8 
    int B = A + 2;
}
namespace S1{ // q18
    int A = 1;
}
namespace S2{ // q18
    int A = 2;
}

void q1(){
    short s = 1;
    int i = 2;
    float f = 4.4;
    double d = 8.8;
    std::cout << s / i + f / i + d / s;
}
void q2(){
    std::string s1 = "1", s2 ="12";
    std::cout << s1.compare("s2");
}
void q3(){
    std::string s = "AB";
    s.append(s).push_back(s[s.length() - 1]);
    std::cout << s;
}
void q4(){
    int i = 2; float f = 4.4;
    // std::cout << f % static_cast<float>(i);
}
void q5(){
    std::string s = "0123";
    std::cout << s.substr(1,3).substr(2).substr();
}
void q6(){
    SpaceA::A = SpaceB::A = 1;
    // std::cout << A + 1;
}
void q7(){
    std::string s1 = "ab", s2 = "Abc";
    if(s1 > s2)
        std::cout << "yes";
    else
        std::cout << "No";
}
void q8(){
    S::A = S::A + 1;
    {
        using namespace S;
        ++B;
    }
    std::cout << S::B << S::A;
}
void q9(){
    std::string s = "a";
    std::cout << s + "b" + "c";
}
void q10(){
    int *it[3];
    for(int i{}; i < 3; i++){
        it[i] = new int[i + 1];
        for(int j{}; j < i + 1; j++)
            it[i][j] = 10 * i + j;
    } std::cout << it[2][2];
    for(int i{}; i < 3; i++)
        delete [] it[i];
}
void q11(){
    int i{2}; std::string s {"2"}; 
    // std::cout << s + i;
}
void q12(){
    std::string s{"a"};
    // std::cout << s << "b" + "c";
}
void q13(){
    std::vector<std::string> t = {"alpha", "beta", "gamma"};
    int *cnt = new int[3], *p = &cnt[0];
    for(int i{}; i < t.size(); i++)
        *p++ = t[i].length();
    std::cout << cnt[0] << cnt[1] << cnt[2];
    delete [] cnt;
}
void q14(){
    int i{2}; float f{5.8};
    f = static_cast<int>(f);
    i = static_cast<float>(i);
    std::cout << f/i;
}
void q15(){
    std::string s1 = "Ab", s2 = "Abc";
    std::cout << s1.compare(s1);
}
void q16(){
    short s = 1; int i = 2; float f = 4.4; double d = 6.6;
    std::cout << i/static_cast<float>(s) + int(f)/i + (long)d/s;
}
void q17(){
    std::vector<float*> ft = {new float[3], new float[3], new float[3]};
    float *p = nullptr;

    for(int i{}; i < 3; i++){
        p = ft[i];
        *p = p[1] = *(p + 2) = 10 * i;
    } std::cout << ft[1][1];
    delete [] ft[0]; delete ft[1]; delete ft[2];
}
void q18(){
    { using namespace S1;
        S2::A = A + 1;
    }
    { using namespace S2;
        S1::A = A + 1; 
    } std::cout << S1::A << S2::A;
}
void q19(){
    std::string s1{"aleph"}, s2 {"alpha"}, s;
    s1.swap(s2); s2.swap(s); s.swap(s2);
    std::cout << s2;
}
void q20(){
    std::string s = "ABC";
    // for(int i = 1; i < s.length(); i += 2){
    //     s[i - 1] = s[i] + 'a' = 'A';
    // } std::cout << s;
}

int main(){
    // q1(); // 11
    // q2(); // -1
    // q3(); // ABABB
    // q4(); // Compiler Error
    // q5(); // 3
    // q6(); // Compiler Error
    // q7(); // yes
    // q8(); // 42
    // q9(); // abc
    // q10(); // 22
    // q11(); // Compiler Error
    // q12(); // Compiler Error
    // q13(); // 545
    // q14(); // 2.5
    // q15(); // 0
    // q16(); // 10
    // q17(); // 10
    // q18(); // 32
    // q19(); // aleph
    // q20(); // Compiler Error
    return 0;
}