#include <iostream>
#include <cstring>

int main(){
    //std::strlen : Find the length of the string
    const char message1 [] {"The sky is blue."};

    // Arry decays into pointer when we use const char*
    const char* message2[] {"The sky is blue."};
    std::cout << "message1 : " << message1 << std::endl;

    //strlen ignores null character
    std::cout << "strlen(message1) : " << std::strlen(message1) << std::endl;

    //Includes the null character
    std::cout << "sizeof(message1) : " << sizeof(message1) << std::endl;

    // strlen still works with decayed arrays
    std::cout << "strlen(message2) : " << std::strlen(*message2) << std::endl;

    //Prints size of pointer
    std::cout << "sizeof(message2) : " << sizeof(*message2) << std::endl;
    std::cin.get();

    //std::strcmp - signature : int strcmp(const char *1hs, const char rhs);
    //Returns negative value if 1hs appers before rhs in lexicographic order,
    //Zero if 1hs and rhs compare equal.
    //and Positive value if 1hs appers after rhs in lexicographic order
    std::cout << "std::strcmp : " << std::endl;
    const char *string_data1 {"Alabama"};
    const char *string_data2 {"Blabama"};

    //Print out the comparison
    std::cout << "std::strcmp {" << string_data1 << ", " << string_data2 << "} : " << std::strcmp(string_data1, string_data2) << std::endl;

    string_data1 = "Alabama"; string_data2 = "Alabamb";

    //Print out the comparison
    std::cout << "std::strcmp {" << string_data1 << ", " << string_data2 << "} : " << std::strcmp(string_data1, string_data2) << std::endl;

    string_data1 = "Alacama"; string_data2 = "Alabama";

    //Print out the comparison
    std::cout << "std::strcmp {" << string_data1 << ", " << string_data2 << "} : " << std::strcmp(string_data1, string_data2) << std::endl;
    std::cin.get();
    //std::strcmp : int strcmo(const char *1hs, const char *rhs, std::size_t count);
    //Compares n characters in the strings
    //Returns : Negative value if 1hs appers before rhs in lexicographic order.
    //Zero if 1hs and rhs compare equal, or if count is zero.
    // Positive value if 1hs appears after rhs in lexicographic order.

    // Print out the comparison
    size_t n{3};
    std::cout << "std::strncmp : " << std::endl;
    std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : " << std::strncmp(string_data1, string_data2,n) <<std::endl;

    string_data1 = "aaaia"; string_data2 = "aaance";

    std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : " << std::strncmp(string_data1, string_data2,n) <<std::endl;

    std::cin.get();

    // Find the first occurence of a character
    std::cout << "std::strchr : " << std::endl;
    //doc : https://en.cppreference.com/w/cpp/string/byte/strchr

    // we use std::strchr to find all the character one by one.

    const char *str{"Try not. Do, or do not. There is no try."};
    char target {'T'};
    const char *result = str;
    int i{};

    while((result = std::strchr(result, target)) != nullptr){
        std::cout << "Found '" << target << "' starting at '" << result << "'\n";

        //Increment result, otherwise we'll find target at the same location
        ++result; ++i;
    }
    std::cout << "i : " << i << std::endl;
    std::cin.get();

    //find last occurence
    std::cout << "std::strrchr : " << std::endl;
    // doc : https://en.cppreference.com/w/cpp/string/byte/strrchr

    char input[] = "/home/user/hello.cpp";
    char *output = std::strrchr(input, '/');
    if (output)
        std::cout << output+1 << std::endl;
    // +1 becuase we want to start printing past
    // the character found by std::strrchr.
}