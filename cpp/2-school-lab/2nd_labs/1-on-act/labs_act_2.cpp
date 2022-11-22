// user input a grade and the grade will compare if one one the is the grade.
#include <iostream>

int main(){

    float o_grade;

    std::cout << "Enter your grade : \n>> ";
    std::cin >> o_grade;

    (o_grade >= 96) ? std::cout << " [1.00] A+ Excellent." : 
        (o_grade >= 91) ? std::cout << " [1.25] A Very Good." :
            (o_grade >= 86) ? std::cout << " [1.50] A- Very Good." :
                (o_grade >= 81) ? std::cout << " [1.75] B+ Good." :
                    (o_grade >= 75) ? std::cout << " [2.00] B Good." :
                        (o_grade >= 69) ? std::cout << " [2.25] B- Fair." :
                            (o_grade >= 63) ? std::cout << " [2.50] C+ Fair." :
                                (o_grade >= 57) ? std::cout << " [2.75] C Fair." :
                                    (o_grade >= 50) ? std::cout << " [3.00] C- Fair." :
                                        std::cout << " [5.00] F Failed.";

    return 0;
}