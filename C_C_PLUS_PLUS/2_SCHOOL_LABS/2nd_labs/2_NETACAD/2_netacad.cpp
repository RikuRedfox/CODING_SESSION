#include <iostream>
#include <vector>

struct Str{ // struct for a
    int in;
    char ch;
};
struct S{ // struct for e
    int t;
};
struct SS{ // struct for e
    S t;
};
struct Stru{ // struct for k
    int i1, i2;
    char c1, c2;
};

void a(){
    std::vector<Str> t = {{1, 'a'}, {2, 'b'}};
        for(int i=0; i < 2; i++)
            t[i].in += (t[1 - i].ch - t[i].ch);
        std::cout << t[0].in << t[1].in << std::endl;
}
void b(){
    std::vector<int>a = {2,0,1};
    std::vector<int>b = {1,2,3};
    for(int i=0; i< 3; i++)
        b[a[i]] = b[2 - i];
    std::cout << b[0] << b[2];
}
void c(){
    int i = 0, j = i++, k = --i;
    if(i > 0){
        j++;
    } else{
        k++;
    }if (k == 0){
        i++;
    } else if (k > 0){
        k--;
    } else{
        k++;
    } std::cout << i * j * k;  
}
void d(){
    int a = 1, b = 2;
    int c = a | b;
    int d = c & a;
    int e = d ^ 0;
    std::cout << a << d << c;
}
void e(){
    std::vector<SS>t = {{1},{2}};
    std::cout << t[0].t.t << t[1].t.t;
}
void f(){
    int i = 5, j = 0;
    while(i > 0){
        i--;
        j++;
    }   std::cout << j;
}
void g(){
    for(float val = -10.0; val < 100.0; val = -val * 2){
        if(val < 0 && -val >= 20){
            break;
        } std::cout << "*";
    }
}
void h(){
    int i = 3, j = 0;
    do{
        i--; j++;
    } while(i >= 0);
    std::cout << j;
}
void i(){
    double big = 1e15, small = 1e-15;
    std::cout << std::fixed << big + small;
}
void j(){
    for(float val = -10.0; val < 20.0; val = -val * 2)
        std::cout << "*";
}
void k(){
    Stru a = {1, 2, 'a', 'b'};
    Stru b = {5, 6, 'x', 'y'};
    std::cout << static_cast<char>(b.c1 + a.i1);
    std::cout << static_cast<int>(a.c2 - a.c1);
    std::cout << static_cast<int>(b.c2 - b.c1);
}
void l(){
    int i = 1, j = i++, k = --i;
    if(i > 0){
        j++; k++;
    } else{
        k++; i++;
    } if (k == 0){
        i++; j++;
    } else{
        if (k>0){
            k--;
        } else{
            k++;
        }
        i++;
    } std::cout << i * j * k;
}
void m(){
    std::vector<char> arr = {'a', 'b', 'c'};
    for(int i{1}; i < arr.size(); i++){
        std::cout << "*";
        if((arr[i] - arr[i - 1]) % 2){
            continue;
        }
        std::cout << "*";
    }
}
void n(){
    float val{100.0};
    do{
        val = val / 5;
        std::cout << "*";
    } while(val > 1.0);
}
void o(){
    bool yes = !false, no = !yes;
    if(!no)
        std::cout << "true";
    else
        std::cout << "false";
}
void p(){
    std::vector<std::vector<int>> g = {{2, 4},
                                        {3, 6},
                                        {5, 10}};
    for(int i{1}; i >= 0; i--){
        for(int j{}; j < 2; j++ ){
            g[i][j] += g[j][i];
        }
    } std::cout << g[1][1];
}
void q(){
    std::vector<bool> t(2);
    for(int i{}; i < 2; i++){
        t[1 - i] = !(i % 2);
    } std::cout << t[0] && t[1];
}
void r(){
    int a{1}, b{2};
    int c = a << b;
    int d = 1 << c;
    int e = d >> d;
    std::cout << e;
}
void s(){
    int a{2};
    switch(a << a){
        case 8 : a++;
        case 4 : a++;
        case 2 : break;
        case 1 : a--;
    } std::cout << a;
}
void t(){
    std::vector<int> t = {8, 4, 3, 2, 1};
    int i;
    for(i = t[4]; i < t[3]; i++){
        t[i - 1] = -t[3];
    } std::cout << i;
}

int main(){
    // a(); // 21
    // b(); // 23
    // c(); // 0
    // d(); // 113
    // e(); // 12
    // f(); // 5
    // g(); // **
    // h(); // 4
    // i(); // 1000000000000000.000000
    // j(); // *
    // k(); // y11
    // l(); // 4
    // m(); // **
    // n(); // *** 
    // o(); // true 
    // p(); // 12
    // q(); // 0
    // r(); // 0
    // s(); // 4
    // t(); // 2
}