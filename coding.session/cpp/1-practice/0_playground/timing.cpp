#include <string>
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <cstdlib>
#include <array>
#include <vector>

std::string strRespond1, str_respond2;
int intRespond1 = 1, intRespond2 = 1;

int main(void)
{
  long double result, value, in, ft, yd, mi, ac, ha, mm, cm, m, km;
  std::array<std::string, 10> choice{"Square inch (in)", "Square foot (ft)", "Square yard (yd)", "Square mile (mi)", "acre (ac)", "hectare (ha)", "Square millimeter (mm)", "Square centimeter (cm)", "Square meter (m)", "Square kilometer (km)"};
  std::cout << "Press enter.";
  while (true)
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("CLS");
    if (intRespond1 < 1 || intRespond1 > 10 || intRespond2 < 1 || intRespond2 > 10)
    {
      std::cerr << "ERROR: Did not match. Only 1 - 10, please try again. (Press Enter to continue)";
      std::cin.get();
    }

    size_t i = 1;
    system("CLS");
    std::cout << "\tCommands:"
                 "\n'exit' Exit the conversion\n\n";

    for (auto a : choice)
      std::cout << "[" << i++ << "] " << a << "\n";

    std::cout << "\nFrom: ";
    std::cin >> strRespond1;
    std::transform(strRespond1.begin(), strRespond1.end(), strRespond1.begin(), ::tolower);
    if (strRespond1 == "exit")
      return EXIT_SUCCESS;
    else
    {
      try
      {
        intRespond1 = stold(strRespond1);
      }
      catch (...)
      {
        continue;
      }
    }
    if (intRespond1 < 1 || intRespond1 > 10)
      continue;

    std::cout << "To: ";
    try
    {
      std::cin >> intRespond2;
    }
    catch (...)
    {
      continue;
    }
    if (intRespond2 < 1 || intRespond2 > 10)
      continue;

    std::cout << "Value to Convert: ";
    std::cin >> value;

    result = (intRespond1 == 1 && intRespond2 == 1) ? value * 1 
    : (intRespond1 == 1 && intRespond2 == 2) ? value / 144
                                                              : (intRespond1 == 1 && intRespond2 == 3)   ? value / 1296
                                                                                                         : result = 0;

    std::cout << "\nResult: " << result << " " << choice.at(--intRespond2) << "\n\n(Press Enter to continue)";
    std::cin.get();
  }
}