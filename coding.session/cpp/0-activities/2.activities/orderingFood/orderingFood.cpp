#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

std::string respond;

int main() {

// cashier credentials
  std::string username, password;
  while (true) {
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;

    if (username == "Xulio" && password == "admin") {
      break;
    } else {
      std::cout << "\nWrong Credentials.\n";
    }
  }

  // menu system
  while (true) {
    std::array<std::string, 99> orderName;
    std::array<int, 99> orderPrice;
    std::array<int, 99> orderQuantity;
    int i = 0;
    // the array will hold the orders;
    do {
      int order, qty;
      while (true) {
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

        while (std::cin.fail()) {
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

        if (order > 16 || order < 1) {
          std::cout << "We're sorry, Ma'am/Sir, but it's not on the menu.";
          continue;
        } else {
          break;
        }
      }

      switch (order) {
      case 1:
        orderName.at(i) = "Ham & Cheese    ";
        orderPrice.at(i) = 55;
        orderQuantity.at(i) = qty;
        break;
      case 2:
        orderName.at(i) = "Burger          ";
        orderPrice.at(i) = 60;
        orderQuantity.at(i) = qty;
        break;
      case 3:
        orderName.at(i) = "Clubhouse       ";
        orderPrice.at(i) = 85;
        orderQuantity.at(i) = qty;
        break;
      case 4:
        orderName.at(i) = "Tune            ";
        orderPrice.at(i) = 50;
        orderQuantity.at(i) = qty;
        break;
      case 5:
        orderName.at(i) = "Spaghetti       ";
        orderPrice.at(i) = 85;
        orderQuantity.at(i) = qty;
        break;
      case 6:
        orderName.at(i) = "Carbonara       ";
        orderPrice.at(i) = 85;
        orderQuantity.at(i) = qty;
        break;
      case 7:
        orderName.at(i) = "Lasagna         ";
        orderPrice.at(i) = 90;
        orderQuantity.at(i) = qty;
        break;
      case 8:
        orderName.at(i) = "Baked Mac       ";
        orderPrice.at(i) = 90;
        orderQuantity.at(i) = qty;
        break;
      case 9:
        orderName.at(i) = "Friend Chiken   ";
        orderPrice.at(i) = 110;
        orderQuantity.at(i) = qty;
        break;
      case 10:
        orderName.at(i) = "Pork Chop       ";
        orderPrice.at(i) = 115;
        orderQuantity.at(i) = qty;
        break;
      case 11:
        orderName.at(i) = "Steak           ";
        orderPrice.at(i) = 150;
        orderQuantity.at(i) = qty;
        break;
      case 12:
        orderName.at(i) = "Fish Fillet     ";
        orderPrice.at(i) = 140;
        orderQuantity.at(i) = qty;
        break;
      case 13:
        orderName.at(i) = "Soda            ";
        orderPrice.at(i) = 20;
        orderQuantity.at(i) = qty;
        break;
      case 14:
        orderName.at(i) = "Iced Tea        ";
        orderPrice.at(i) = 25;
        orderQuantity.at(i) = qty;
        break;
      case 15:
        orderName.at(i) = "Orange Juice    ";
        orderPrice.at(i) = 25;
        orderQuantity.at(i) = qty;
        break;
      case 16:
        orderName.at(i) = "Coffer          ";
        orderPrice.at(i) = 30;
        orderQuantity.at(i) = qty;
        break;
      }
      std::cout << std::endl;
      for (size_t x{0}; x <= i; x++) {
        std::cout << "Item " << x << " : " << orderName.at(x)
                  << " | Quantity : " << orderQuantity.at(x)
                  << " | Unit Price : " << orderPrice.at(x)
                  << " | Total Price : "
                  << (orderPrice.at(x) * orderQuantity.at(x)) << std::endl;
      }

      std::cout
          << "\nDo you want to order again?\n('Y' for Yes | 'any' for No) : ";
      std::cin >> respond;

      if (!(respond == "Y" || respond == "y")) {
        break;
      }
      i++;
    } while (true);

    std::cout << "\nReceipt : \n";
    std::cout << "Cashier : " << username << std::endl;
    int total{0}, cash, amount;

    std::cout << std::endl;
    for (size_t x{0}; x <= i; x++) {
      amount = (orderPrice.at(x) * orderQuantity.at(x));
      total += amount;
      std::cout << "Item " << x << " : " << orderName.at(x)
                << " | Quantity : " << orderQuantity.at(x)
                << " | Unit Price : " << orderPrice.at(x)
                << " | Total Price : "
                << (orderPrice.at(x) * orderQuantity.at(x)) << std::endl;
    }
    std::cout << "\nTotal: " << total << std::endl;
    while (true) {
      std::cout << "Enter Cash : ";
      std::cin >> cash;

      while (std::cin.fail()) {
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

    if (!(respond == "Y" || respond == "y")) {
      break;
    }
  }
  std::cout << "\nOkay have a nice day!";

  return 0;
}