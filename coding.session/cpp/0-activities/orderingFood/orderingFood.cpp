#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#define LOG_CLEAR std::cout << "\033[2J\033[1;1H";

int main(void) {
  std::string respond;
  for (unsigned short i = 0; true; i = 0) {
    std::vector<std::string> orderName;
    std::vector<int> orderPrice;
    std::vector<int> orderQty;
    unsigned short order{};
    unsigned short qty{};
    unsigned short cash{};
    unsigned short total{};

    printf("Press Enter");
    do {
      while (true) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        LOG_CLEAR;
        
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
        try {
          std::cout << "\nOrder: ";
          std::cin >> order;
          if (order < 1 || order > 16)
            continue;
          std::cout << "Quantity: ";
          std::cin >> qty;
        } catch (...) {
          continue;
        }

        switch (order) {
        case 1:
          orderName.emplace_back("Ham & Cheese    ");
          orderPrice.emplace_back(55);
          orderQty.emplace_back(qty);
          break;
        case 2:
          orderName.emplace_back("Burger          ");
          orderPrice.emplace_back(60);
          orderQty.emplace_back(qty);
          break;
        case 3:
          orderName.emplace_back("Clubhouse       ");
          orderPrice.emplace_back(85);
          orderQty.emplace_back(qty);
          break;
        case 4:
          orderName.emplace_back("Tune            ");
          orderPrice.emplace_back(50);
          orderQty.emplace_back(qty);
          break;
        case 5:
          orderName.emplace_back("Spaghetti       ");
          orderPrice.emplace_back(85);
          orderQty.emplace_back(qty);
          break;
        case 6:
          orderName.emplace_back("Carbonara       ");
          orderPrice.emplace_back(85);
          orderQty.emplace_back(qty);
          break;
        case 7:
          orderName.emplace_back("Lasagna         ");
          orderPrice.emplace_back(90);
          orderQty.emplace_back(qty);
          break;
        case 8:
          orderName.emplace_back("Baked Mac       ");
          orderPrice.emplace_back(90);
          orderQty.emplace_back(qty);
          break;
        case 9:
          orderName.emplace_back("Friend Chiken   ");
          orderPrice.emplace_back(110);
          orderQty.emplace_back(qty);
          break;
        case 10:
          orderName.emplace_back("Pork Chop       ");
          orderPrice.emplace_back(115);
          orderQty.emplace_back(qty);
          break;
        case 11:
          orderName.emplace_back("Steak           ");
          orderPrice.emplace_back(150);
          orderQty.emplace_back(qty);
          break;
        case 12:
          orderName.emplace_back("Fish Fillet     ");
          orderPrice.emplace_back(140);
          orderQty.emplace_back(qty);
          break;
        case 13:
          orderName.emplace_back("Soda            ");
          orderPrice.emplace_back(20);
          orderQty.emplace_back(qty);
          break;
        case 14:
          orderName.emplace_back("Iced Tea        ");
          orderPrice.emplace_back(25);
          orderQty.emplace_back(qty);
          break;
        case 15:
          orderName.emplace_back("Orange Juice    ");
          orderPrice.emplace_back(25);
          orderQty.emplace_back(qty);
          break;
        case 16:
          orderName.emplace_back("Coffee          ");
          orderPrice.emplace_back(30);
          orderQty.emplace_back(qty);
          break;
        default:
          continue;
          break;
        }
        break;
      }
      std::cout << "\n";

      for (unsigned short int j{}; j <= i; j++) {
        std::cout << "Item " << j << " : " << orderName.at(j)
                  << " | Quantity: " << orderQty.at(j)
                  << " | Unit Price: " << orderPrice.at(j)
                  << " | Total Price: " << (orderPrice.at(j) * orderQty.at(j))
                  << "\n";
      }
      std::cout << "\nDo you want to order again?"
                   "\n('Y' for Yes | 'any key' for No) > ";
      std::cin >> respond;
      std::transform(respond.begin(), respond.end(), respond.begin(),
                     ::tolower);

      if (!(respond == "y"))
        break;

      i++;
    } while (true);
    LOG_CLEAR;
    std::cout << "\nReceipt: \n";

    for (unsigned short int j{}; j <= i; j++) {
      total += (orderPrice.at(j) * orderQty.at(j));
      std::cout << "Item " << j << " : " << orderName.at(j)
                << " | Quantity: " << orderQty.at(j)
                << " | Unit Price: " << orderPrice.at(j)
                << " | Total Price: " << (orderPrice.at(j) * orderQty.at(j))
                << "\n";
    }

    while (true) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      try {
        std::cout << "\nTotal: " << total;
        std::cout << "\nEnter Cash: ";
        std::cin >> cash;
      } catch (...) {
        continue;
      }
      if (cash >= total)
        break;

      std::cout << "Unsufficient funds.\n";
    }
    // clear all elements inside of vector
    orderName.clear();
    orderPrice.clear();
    orderQty.clear();

    std::cout << "\nChange: " << (cash - total);
    std::cout << "\nDo you want to make another order?"
                 "\n('Y' for yes | 'any key' to exit) > ";
    std::cin >> respond;
    std::transform(respond.begin(), respond.end(), respond.begin(), ::tolower);
    if (!(respond == "y"))
      break;
  }
  std::cout << "\nThank you for your patronage!" << std::endl;
  return 0;
}