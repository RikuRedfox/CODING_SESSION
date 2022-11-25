#include <iostream>

class Aa { // a();
public:
  Aa() { v = 2.5; }
  Aa(float v) { Aa::v = v + 1.0; }
  float v;
  float set(float v) {
    Aa::v += 1.0;
    return v;
  }
  float get(float v) {
    v += Aa::v;
    return v;
  }
};
class Ab { // b();
public:
  float v;
  float set(float v) {
    Ab::v += 1.0;
    return v;
  }
  float set(void) {
    Ab::v = v + 1.0;
    return 0.0;
  }
  float get(float v) {
    v += Ab::v;
    return v;
  }
};
class Ac { // b();
public:
  float v;
  float set(float v) {
    v += 1.0;
    this->v = v;
    return v;
  }
  float get(float d) {
    v += 1.0;
    return v;
  }
};
class Ad {
public:
  Ad() { v = 2.5; }
  float v;
  float set(float v) {
    Ad::v += 1.0;
    return v;
  }
  float get(float v) {
    v += Ad::v;
    return v;
  }
};

void a() {
  Aa a, b(1.0);
  std::cout << a.get(b.set(1.5));
}
void b() {
  Ab a;
  std::cout << a.get(a.set(a.set(a.set())));
}
void c() {
  Ac a;
  std::cout << a.get(a.set(a.set(0.5)));
}
void d() {
  Ad a;
  // a.Ad();
  std::cout << a.get(a.set(1.5));
}

int main() {
  // a(); // 4
  // b(); // 3
  // c(); // 3.5
  // d(); // Compiler fails
}