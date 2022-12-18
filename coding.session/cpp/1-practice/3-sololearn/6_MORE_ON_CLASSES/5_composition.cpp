#include <iostream>

class Engine
{
    int power;

public:
    Engine(int p) : power(p){};
    void start()
    {
        std::cout << "Engine ON (" << power << " horsepower)";
    }
};
class Car
{
    Engine e;
    std::string color;
    int year;

public:
    Car(Engine x, std::string c, int y) : e(x), color(c), year(y){};
    void start()
    {
        std::cout << "Starting" << std::endl;
        // your code goes here
        e.start();
    }
};

int main()
{
    int power;
    std::string color;
    int year;
    std::cin >> power >> color >> year;

    Engine e(power);
    // your code goes here
    Car a(e, color, year);
    a.start();
    return 0;
}
