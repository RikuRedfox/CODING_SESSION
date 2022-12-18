#include <iostream>

class Player
{
    int points;
  public:
    Player(int x)
    {
        points = x;
        points %= 5;
    }
    //define the destructor
    ~Player(){
      std::cout << points;
    }
};

int main() {
  int points;
  std::cin >> points;
  Player obj(points);
}