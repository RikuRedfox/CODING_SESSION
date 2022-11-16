#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>

int main(){

    std::string username, password;

    while (1){ // cashier credentials
        std::cout << "Enter Username: ";
        std::cin >> username;
        std::cout << "Enter Password: ";
        std::cin >> password;

        if (username == "Xulio" && password == "admin"){
            break;
        }
        else{
            std::cout << "Wrong Credentials.\n";
        }
    }

    while (1){ //
        std::string summaryOrders[99][99];
        int i{0};

        while (1){
            int order, qty, price, total; // menu

            std::cout << "\n\tSandwiches" << std::setw(50) << "\t\t\tMain Dish w/ Rice\n";
            std::cout << "[1] Ham & Cheese\t - - - - Php 55\t\t\t" << std::setw(20) << "[9] Fried Chicken\t - - - - Php 110\n";
            std::cout << "[2] Burger\t\t - - - - Php 60\t\t\t" << std::setw(20) << "[10] Pork Chop\t\t - - - - Php 115\n";
            std::cout << "[3] Clubhouse\t\t - - - - Php 85\t\t\t" << std::setw(20) << "[11] Steak\t\t - - - - Php 150\n";
            std::cout << "[4] Tuna\t\t - - - - Php 50\t\t\t" << std::setw(20) << "[12] Fish Fillet\t - - - - Php 140\n";

            std::cout << "\n\tPasta" << std::setw(50) << "\t\t\tDrinks\n";
            std::cout << "[5] Spaghetti\t\t - - - - Php 85\t\t\t" << std::setw(20) << "[13] Soda\t\t - - - - Php 20\n";
            std::cout << "[6] Carbonara \t\t - - - - Php 85\t\t\t" << std::setw(20) << "[14] Iced tea\t\t - - - - php 25\n";
            std::cout << "[7] Lasagna\t\t - - - - Php 90\t\t\t" << std::setw(20) << "[15] Orange Juice\t - - - - Php 25\n";
            std::cout << "[8] Baked Mac\t\t - - - - Php 90\t\t\t" << std::setw(20) << "[16] Coffee \t\t - - - - Php 30\n";

            std::cout << "Order: "; // 
            std::cin >> order;
            std::cout << "Quantity: "; // qty 
            std::cin >> qty;

            switch (order){
                case 1:
                    summaryOrders[i][0] = "Ham & Cheese ";
                    summaryOrders[i][1] = "55";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 2:
                    summaryOrders[i][0] = "Burger       ";
                    summaryOrders[i][1] = "60";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 3:
                    summaryOrders[i][0] = "Clubhouse    ";
                    summaryOrders[i][1] = "85";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 4:
                    summaryOrders[i][0] = "Tuna         ";
                    summaryOrders[i][1] = "50";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 5:
                    summaryOrders[i][0] = "Spaghetti    ";
                    summaryOrders[i][1] = "85";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 6:
                    summaryOrders[i][0] = "Carbona      ";
                    summaryOrders[i][1] = "85";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 7:
                    summaryOrders[i][0] = "Lasagna      ";
                    summaryOrders[i][1] = "90";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 8:
                    summaryOrders[i][0] = "Baked Mac    ";
                    summaryOrders[i][1] = "90";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 9:
                    summaryOrders[i][0] = "Fried Chiken ";
                    summaryOrders[i][1] = "110";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 10:
                    summaryOrders[i][0] = "Pork Chop    ";
                    summaryOrders[i][1] = "115";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 11:
                    summaryOrders[i][0] = "Steak        ";
                    summaryOrders[i][1] = "150";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 12:
                    summaryOrders[i][0] = "Fish Fillet  ";
                    summaryOrders[i][1] = "140";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 13:
                    summaryOrders[i][0] = "Soda         ";
                    summaryOrders[i][1] = "20";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 14:
                    summaryOrders[i][0] = "Iced Tea     ";
                    summaryOrders[i][1] = "25";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 15:
                    summaryOrders[i][0] = "Orange Juice ";
                    summaryOrders[i][1] = "25";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
                case 16:
                    summaryOrders[i][0] = "Coffee       ";
                    summaryOrders[i][1] = "30";
                    summaryOrders[i][2] = std::to_string(qty);
                    break;
            }

            for (size_t x{0}; x <= i; x++){
                std::cout << "Item " << x << " : " << summaryOrders[x][0] << " | Quantity : " << summaryOrders[x][2] << " | Unit price : " << summaryOrders[x][1] << " | Amount of Sale : " << (stoi(summaryOrders[x][1]) * stoi(summaryOrders[x][2]) )<< std::endl;
            }

            std::cout << "\nDo you want to order again? [1] Yes [0] No : ";
            int dec;
            std::cin >> dec;

            if (dec != 1){
                break;
            }

            i++;
        }

        std::cout << "Order Summary: \n";
        std::cout << "Cashier: " << username << std::endl;
        int total {0}, cash, amount;

        for (int x{0}; x <= i; x++){
            amount = stoi(summaryOrders[x][1]) * stoi(summaryOrders[x][2]);
            total += amount;
            std::cout << "Item " << x << " : " << summaryOrders[x][0] << " | Quantity : " << summaryOrders[x][2] << " | Unit Price : " << summaryOrders[x][1] << " | Amount of sale : " << (stoi(summaryOrders[x][1]) * stoi(summaryOrders[x][2]) ) << std::endl;
        }
        std::cout << "Total: " << total << std::endl;
        while(1){
            std::cout << "Enter Cash: ";
            std::cin >> cash;

            if(cash >= total){
                break;
            }
            std::cout << "Unsufficient funds\n";
        }
        std::cout << "Change: " << cash - total << std::endl;

        int dec;
        std::cout << "Do you want to make another transaction? [1] Yes | [0] No: ";
        std::cin >> dec ;

        if(dec != 1){
            break;
        }
    }

    std::cout << "Okay have a nice day!" << std::endl;

    return 0;
}