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

        switch (intRespond1)
        {
        case 1: // in
            switch (intRespond2)
            {
            case 1: // in
                result = value * 1;
                break;
            case 2: // ft
                result = value / 144;
                break;
            case 3: // yd
                result = value / 1296;
                break;
            case 4: // mi
                result = value / 4014000000;
                break;
            case 5: // acre
                result = value / 6273000;
                break;
            case 6: // ha
                result = value / 15500000;
                break;
            case 7: // mm
                result = value * 645.2;
                break;
            case 8: // cm
                result = value * 6.452;
                break;
            case 9: // m
                result = value / 1550;
                break;
            case 10: // km
                result = value / 1550000000;
                break;
            }
            break;
        case 2: // ft
            switch (intRespond2)
            {
            case 1: // in
                result = value * 144;
                break;
            case 2: // ft
                result = value * 1;
                break;
            case 3: // yd
                result = value / 9;
                break;
            case 4: // mi
                result = value / 27880000;
                break;
            case 5: // acre
                result = value / 43560;
                break;
            case 6: // ha
                result = value / 107600;
                break;
            case 7: // mm
                result = value * 92900;
                break;
            case 8: // cm
                result = value * 929;
                break;
            case 9: // m
                result = value / 10.76;
                break;
            case 10: // km
                result = value / 10760000;
                break;
            }
            break;
        case 3: // yd
            switch (intRespond2)
            {
            case 1: // in
                result = value * 1296;
                break;
            case 2: // ft
                result = value * 9;
                break;
            case 3: // yd
                result = value * 1;
                break;
            case 4: // mi
                result = value / 3098000;
                break;
            case 5: // acre
                result = value / 4840;
                break;
            case 6: // ha
                result = value / 11960;
                break;
            case 7: // mm
                result = value * 836100;
                break;
            case 8: // cm
                result = value * 8361;
                break;
            case 9: // m
                result = value * 1.196;
                break;
            case 10:
                result = value / 1196000;
                break;
            }
            break;
        case 4: // mi
            switch (intRespond2)
            {
            case 1: // in
                result = value * 4014000000;
                break;
            case 2: // ft
                result = value * 27880000;
                break;
            case 3: // yd
                result = value * 3098000;
                break;
            case 4: // mi
                result = value * 1;
                break;
            case 5: // ac
                result = value * 640;
                break;
            case 6: // ha
                result = value * 259;
                break;
            case 7: // mm
                result = value * 2590000000000;
                break;
            case 8: // cm
                result = value * 25900000000;
                break;
            case 9: // m
                result = value * 2590000;
                break;
            case 10: // km
                result = value * 2.59;
                break;
            }
            break;
        case 5: // ac
            switch (intRespond2)
            {
            case 1: // in
                result = value * 6273000;
                break;
            case 2: // ft
                result = value * 43560;
                break;
            case 3: // yd
                result = value * 4840;
                break;
            case 4: // mi
                result = value / 640;
                break;
            case 5: // ac
                result = value * 1;
                break;
            case 6: // ha
                result = value / 2.471;
                break;
            case 7: // mm
                result = value * 4047000000;
                break;
            case 8: // cm
                result = value * 40470000;
                break;
            case 9: // m
                result = value * 4047;
                break;
            case 10: // km
                result = value * 247.1;
                break;
            }
            break;
        case 6: // ha
            switch (intRespond2)
            {
            case 1: // in
                result = value * 15500000;
                break;
            case 2: // ft
                result = value * 107600;
                break;
            case 3: // yd
                result = value * 11960;
                break;
            case 4: // mi
                result = value / 259;
                break;
            case 5: // ac
                result = value / 259;
                break;
            case 6: //
                break;
            case 7: //
                break;
            case 8: //
                break;
            case 9: //
                break;
            case 10: //
                break;
            }
            break;
        case 7:
            switch (intRespond2)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            }
            break;
        case 8:
            switch (intRespond2)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            }
            break;
        case 9:
            switch (intRespond2)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            }
            break;
        case 10:
            switch (intRespond2)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            }
            break;
        }
        std::cout << "\nResult: " << result << " " << choice.at(--intRespond2) << "\n\n(Press Enter to continue)";
        std::cin.get();
    }
}
