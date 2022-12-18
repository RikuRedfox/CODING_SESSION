#include <iostream>

class TV {
    public:
        TV(int h, int w): height(h), width(w) {};
        void area() {
            std::cout << height*width;
        }
    private:
        int height;
        int width;
};

int main() {
   //your code goes here
   int x, y;
   std::cin >> x >> y;
   TV television(x, y);
   television.area();
   return 0;
}
