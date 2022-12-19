#include <vector>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <string>

std::string respond;

int main()
{
  // cashier credentials
  std::string username = "Xulio";
  // {
  //   std::string password;
  //   while (true)
  //   {
  //     std::cout << "Enter Username: ";
  //     std::cin >> username;
  //     std::cout << "Enter Password: ";
  //     std::cin >> password;

  //     if (username == "Xulio" && password == "admin")
  //       break;
  //     else
  //       std::cout << "\nWrong Credentials.\n";
  //   }
  // }

  // menu system
  while (true)
  {
    std::vector<std::string> orderName;
    std::vector<int> orderPrice;
    std::vector<int> orderQuantity;
    int i = 0;
    // the array will hold the orders;
    while (true)
    {
      int order, qty;
      while (true)
      {
        std::cout << "\n\tSandwiches" << std::setw(50)
                  << "\t\t\tMain Dish w/ Rice\n";
        std::cout << "[1] Ham & Cheese\t - - - - Php 55\t\t\t" << std::setw(20)
                  << "[9] Fried Chicken\t - - - - Php 110\n";
        std::cout << "[2] Burger\t\t - - - - Php 60\t\t\t" << std::setw(20)
                  << "[10] Pork Chop\t\t - - - - Php 115\n";
        std::cout << "[3] Clubhouse\t\t - - - - Php 85\t\t\t" << std::setw(20)
                  << "[11] Steak\t\t - - - - Php 150\n";
        std::cout << "[4] Tuna\t\t - - - - Php 50\t\t\t" << std::setw(20)
                  << "[12] Fish Fillet\t - - - - Php 140\n";

        std::cout << "\n\tPasta" << std::setw(50) << "\t\t\tDrinks\n";
        std::cout << "[5] Spaghetti\t\t - - - - Php 85\t\t\t" << std::setw(20)
                  << "[13] Soda\t\t - - - - Php 20\n";
        std::cout << "[6] Carbonara \t\t - - - - Php 85\t\t\t" << std::setw(20)
                  << "[14] Iced tea\t\t - - - - php 25\n";
        std::cout << "[7] Lasagna\t\t - - - - Php 90\t\t\t" << std::setw(20)
                  << "[15] Orange Juice\t - - - - Php 25\n";
        std::cout << "[8] Baked Mac\t\t - - - - Php 90\t\t\t" << std::setw(20)
                  << "[16] Coffee \t\t - - - - Php 30\n";

        std::cout << "Order: "; //
        std::cin >> order;
        std::cout << "Quantity: "; // qty
        std::cin >> qty;

        while (std::cin.fail())
        {
          std::cin.clear(); // clearning the buffer if there is a string input
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cerr
              << "\n\nERROR : Something wrong with the input, Please try again."
              << std::endl;

          std::cout << "\n\tSandwiches" << std::setw(50)
                    << "\t\t\tMain Dish w/ Rice\n";
          std::cout << "[1] Ham & Cheese\t - - - - Php 55\t\t\t"
                    << std::setw(20) << "[9] Fried Chicken\t - - - - Php 110\n";
          std::cout << "[2] Burger\t\t - - - - Php 60\t\t\t" << std::setw(20)
                    << "[10] Pork Chop\t\t - - - - Php 115\n";
          std::cout << "[3] Clubhouse\t\t - - - - Php 85\t\t\t" << std::setw(20)
                    << "[11] Steak\t\t - - - - Php 150\n";
          std::cout << "[4] Tuna\t\t - - - - Php 50\t\t\t" << std::setw(20)
                    << "[12] Fish Fillet\t - - - - Php 140\n";

          std::cout << "\n\tPasta" << std::setw(50) << "\t\t\tDrinks\n";
          std::cout << "[5] Spaghetti\t\t - - - - Php 85\t\t\t" << std::setw(20)
                    << "[13] Soda\t\t - - - - Php 20\n";
          std::cout << "[6] Carbonara \t\t - - - - Php 85\t\t\t"
                    << std::setw(20) << "[14] Iced tea\t\t - - - - php 25\n";
          std::cout << "[7] Lasagna\t\t - - - - Php 90\t\t\t" << std::setw(20)
                    << "[15] Orange Juice\t - - - - Php 25\n";
          std::cout << "[8] Baked Mac\t\t - - - - Php 90\t\t\t" << std::setw(20)
                    << "[16] Coffee \t\t - - - - Php 30\n";

          std::cout << "Order: "; //
          std::cin >> order;
          std::cout << "Quantity: "; // qty
          std::cin >> qty;
        }

        if (order > 16 || order < 1)
        {
          std::cout << "We're sorry, Ma'am/Sir, but it's not on the menu.";
          continue;
        }
        else
          break;
      }

      switch (order)
      {
      case 1:
        orderName.push_back("Ham & Cheese    ");
        orderPrice.push_back(55);
        orderQuantity.push_back(qty);
        break;
      case 2:
        orderName.push_back("Burger          ");
        orderPrice.push_back(60);
        orderQuantity.push_back(qty);
        break;
      case 3:
        orderName.push_back("Clubhouse       ");
        orderPrice.push_back(85);
        orderQuantity.push_back(qty);
        break;
      case 4:
        orderName.push_back("Tune            ");
        orderPrice.push_back(50);
        orderQuantity.push_back(qty);
        break;
      case 5:
        orderName.push_back("Spaghetti       ");
        orderPrice.push_back(85);
        orderQuantity.push_back(qty);
        break;
      case 6:
        orderName.push_back("Carbonara       ");
        orderPrice.push_back(85);
        orderQuantity.push_back(qty);
        break;
      case 7:
        orderName.push_back("Lasagna         ");
        orderPrice.push_back(90);
        orderQuantity.push_back(qty);
        break;
      case 8:
        orderName.push_back("Baked Mac       ");
        orderPrice.push_back(90);
        orderQuantity.push_back(qty);
        break;
      case 9:
        orderName.push_back("Friend Chiken   ");
        orderPrice.push_back(110);
        orderQuantity.push_back(qty);
        break;
      case 10:
        orderName.push_back("Pork Chop       ");
        orderPrice.push_back(115);
        orderQuantity.push_back(qty);
        break;
      case 11:
        orderName.push_back("Steak           ");
        orderPrice.push_back(150);
        orderQuantity.push_back(qty);
        break;
      case 12:
        orderName.push_back("Fish Fillet     ");
        orderPrice.push_back(140);
        orderQuantity.push_back(qty);
        break;
      case 13:
        orderName.push_back("Soda            ");
        orderPrice.push_back(20);
        orderQuantity.push_back(qty);
        break;
      case 14:
        orderName.push_back("Iced Tea        ");
        orderPrice.push_back(25);
        orderQuantity.push_back(qty);
        break;
      case 15:
        orderName.push_back("Orange Juice    ");
        orderPrice.push_back(25);
        orderQuantity.push_back(qty);
        break;
      case 16:
        orderName.push_back("Coffer          ");
        orderPrice.push_back(30);
        orderQuantity.push_back(qty);
        break;
      }
      std::cout << "\n";
      for (size_t x = 0; x <= i; x++)
      {
        std::cout << "Item " << x << " : " << orderName.at(x)
                  << " | Quantity : " << orderQuantity.at(x)
                  << " | Unit Price : " << orderPrice.at(x)
                  << " | Total Price : "
                  << (orderPrice.at(x) * orderQuantity.at(x)) << std::endl;
      }

      std::cout
          << "\nDo you want to order again?\n('Y' for Yes | 'any' for No) : ";
      std::cin >> respond;

      if (respond == "Y" || respond == "y")
        continue;
      else
        break;

      i++;
    }

    std::cout << "\nReceipt : \n";
    std::cout << "Cashier : " << username << std::endl;
    int total{0}, cash, amount;

    std::cout << std::endl;
    for (size_t x{0}; x <= i; x++)
    {
      amount = (orderPrice.at(x) * orderQuantity.at(x));
      total += amount;
      std::cout << "Item " << x << " : " << orderName.at(x)
                << " | Quantity : " << orderQuantity.at(x)
                << " | Unit Price : " << orderPrice.at(x)
                << " | Total Price : "
                << (orderPrice.at(x) * orderQuantity.at(x)) << std::endl;
    }
    std::cout << "\nTotal: " << total << std::endl;
    while (true)
    {
      std::cout << "Enter Cash : ";
      std::cin >> cash;

      while (std::cin.fail())
      {
        std::cin.clear(); // clearning the buffer if there is a string input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr
            << "\nERROR : Something wrong with the input, Please try again."
            << std::endl;

        std::cout << "Enter Cash : ";
        std::cin >> cash;
      }
      if (cash >= total)
        break;

      std::cout << "Unsufficient funds\n";
    }

    std::cout << "\nChange: " << cash - total << std::endl;

    std::cout << "\nDo you want to make another transaction?\n"
                 "('Y' for yes | 'any' for any) : ";
    std::cin >> respond;

    if (!(respond == "Y" || respond == "y"))
      break;
  }
  std::cout << "\nOkay have a nice day!";
  return 0;
}