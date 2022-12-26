#include <chrono>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <thread>

int main()
{
  unsigned short int sec, min, hr;

  std::cout << "\tTIMER \n";
  std::cout << "Enter sec : ";
  std::cin >> sec;
  std::cout << "Enter min : ";
  std::cin >> min;
  std::cout << "Enter hr : ";
  std::cin >> hr;

  while (std::cin.fail())
  {
    // clearning the buffer if there is a string input
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n\n\tTIMER \n";
    std::cout << "Enter sec : ";
    std::cin >> sec;
    std::cout << "Enter min : ";
    std::cin >> min;
    std::cout << "Enter hr : ";
    std::cin >> hr;
  }

  if (sec >= 60)
    sec = 59;
  if (min >= 60)
    min = 59;

  if (sec == 0 && min == 0 && hr == 0)
  {
    system("CLS");
    std::cout << hr << " : " << min << " : " << sec;
    return 0;
  }

  while (true)
  {
    system("CLS");
    std::cout << hr << " : " << min << " : " << sec;
    sec--;
    if (sec == 0 && min == 0 && hr == 0)
    {
      system("CLS");
      std::cout << hr << " : " << min << " : " << sec;
      break;
    }
    if (sec <= 0)
    {
      sec += 59;
      if (min >= 1)
        min--;
      if (min <= 1)
      {
        if (hr >= 1)
        {
          min += 59;
          hr--;
        }
      }
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
  return 0;
}