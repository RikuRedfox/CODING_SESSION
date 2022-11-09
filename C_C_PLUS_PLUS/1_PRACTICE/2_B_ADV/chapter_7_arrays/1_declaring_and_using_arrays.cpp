#include <iostream>

int main(){
    int scores[10]; // storing 10 int

    for (size_t i{0}; i < 10; i++) // write
    {
        scores[i] = i * 6;
    }

    for (size_t i{0}; i < 10; i++) // read
    {
        std::cout << "scores[" << i << "] " << scores[i] << std::endl;
    }

    std::cout << std::endl
         << "- - - Salary - - -" << std::endl;

    double salaries[5]{12.7, 7.6, 13.2, 8.1, 9.3};

    for (size_t i{0}; i < 5; i++)
    {
        std::cout << "salary[" << i << "] " << salaries[i] << std::endl;
    }

    std::cout << std::endl
         << "- - - Bottles - - -" << std::endl;

    int bottllesG[5]{350, 500, 150};
    for (size_t i{0}; i < 5; i++)
    {
        std::cout << "bottles[" << i << "] " << bottllesG[i] << std::endl;
    }

    std::cout << std::endl
         << "- - - w/o values - - -" << std::endl;

    int class_sizes[]{10, 12, 15, 11, 19, 17, 23, 56, 19};

    for (auto value : class_sizes)
    {
        std::cout << "Value : " << value << std::endl;
    }

    std::cout << std::endl
         << "- - - w/o values - - -" << std::endl;

    int scoresTwo[]{5, 10, 15, 20, 25, 30, 35},
        sum{0};

    for (int value : scoresTwo)
    {
        sum += value;
    }

    std::cout << "Score sum: " << sum << std::endl;
    return 0;
}