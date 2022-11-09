#include <iostream>

int main(){

    // brace initializer
    int female_count {23}, male_count {15}; 
    int total (female_count + male_count);

    std::cout << "Total count : " << total << std::endl;

    /*
     //Brace Initializer. compiler error
     int alcohol_netW {500.5}, softDrinks_netW {500.62}
     int total_liquidz {alcohol_netW + softDrinks_netW};

     cout << total_liquidz;
    */

   // functional notation. narrowing if there is a decimal

   int juice_netW (200), water_bottle (500.4);
   int total_liquid (juice_netW + water_bottle);

   std::cout << "Total liquid : " << total_liquid << std::endl;

   // assignment the standard
   int word_count = 1000, sentence_count = 5;
   int total_letters = (word_count * sentence_count) * .42135;

   std::cout << "Total letters : " << total_letters << std::endl;

   // check the size
    std::cout << "Sizeof int : " << sizeof(double) << std::endl;
    std::cout << "Sizeof word count : " << sizeof(word_count);

    return 0;
}