#include <iostream>
#include <string>

std::string str_array [3] {"PRELIM ","MIDTERM ", "FINAL "};
float 
lec_quiz_1[3], lec_quiz_2[3], lec_exam[3],lec_grade[3],
lab_quiz_1[3], lab_quiz_2[3], lab_exam[3], lab_grade[3];

void lecture_grade(){
    size_t i{0};
    for( ; i < 3; i++ ){

        std::cout << std::endl;
        //inputs
        std::cout << str_array[i] << "Lecture Grades.\n";
        std::cout << "Enter " << str_array[i] << "Quiz 1: ";
        std::cin >> lec_quiz_1[i];
        std::cout << "Enter " << str_array[i] << "Quiz 2: ";
        std::cin >> lec_quiz_2[i];

        std::cout << "Enter " << str_array[i] << "Exam: ";
        std::cin >> lec_exam[i];

        //computation / results
        lec_grade[i] = (lec_quiz_1[i] * 0.25) + (lec_quiz_2[i] * 0.25) + (lec_exam[i] * 0.5);
        std::cout << "\nYour " << str_array[i] << "Lecture Grade is: " << lec_grade[i] << std::endl;
    }
}

void laboratory_grade(){
    size_t i{0};
    for( ; i < 3; i++ ){

        std::cout << std::endl;
        //inputs
        std::cout << str_array[i] << "Laboratory Grades.\n";
        std::cout << "Enter " << str_array[i] << "Quiz 1: ";
        std::cin >> lab_quiz_1[i];
        std::cout << "Enter " << str_array[i] << "Quiz 2: ";
        std::cin >> lab_quiz_2[i];

        std::cout << "Enter " << str_array[i] << "Exam: ";
        std::cin >> lab_exam[i];

        //computation / results
        lab_grade[i] = (lab_quiz_1[i] * 0.25) + (lab_quiz_2[i] * 0.25) + (lab_exam[i] * 0.5);
        std::cout << "\nYour " << str_array[i] << "Laboratory Grade is: " << lab_grade[i] << std::endl;
    }
}

void final_grade(){

    // Lec ((PQ1 * 0.25) + (PQ2 * 0.25) + (PEXAM * 0.50) * 0.3) + ((MQ1 * 0.25) + (MQ2 * 0.25) + (MEXAM * 0.50) * 0.3) + ((FQ1 * 0.25) + (FQ2 * 0.25) + (FEXAM * 0.50) * 0.4)
    std::cout << "Overall Grade for the Lecture: " << (lec_grade[0] * 0.3) + (lec_grade[1] * 0.3) + (lec_grade[2] * 0.4) << std::endl;

    // Lab	((PMP1 * 0.25) + (PMP2 * 0.25) + (PEXAM * 0.50) * 0.3) + ((MMP1 * 0.25) + (MMP2 * 0.25) + (MEXAM * 0.50) * 0.3) + ((FMP1 * 0.25) + (FMP2 * 0.25) + (FEXAM * 0.50) * 0.4)
    std::cout << "Overall Grade for the Laboratory: " << (lab_grade[0] * 0.3) + (lab_grade[1] * 0.3) + (lab_grade[2] * 0.4) << std::endl;

    // LecLab	((PQ1 * 0.25) + (PQ2 * 0.25) + (PEXAM * 0.50) * 0.60) + (PMP1 * 0.25) + (PMP2 * 0.25) + (PEXAM * 0.50) * 0.40) + (MQ1 * 0.25) + (MQ2 * 0.25) + (MEXAM * 0.50) * 0.60) + (MMP1 * 0.25) + (MMP2 * 0.25) + (MEXAM * 0.50) * 0.40) + (FQ1 * 0.25) + (FQ2 * 0.25) + (FEXAM * 0.50) * 0.60) + (FMP1 * 0.25) + (FMP2 * 0.25) + (FEXAM * 0.50) * 0.40)
    float overall { ((((lec_grade[0] * 0.6) + (lab_grade[0] * 0.4)) + ((lec_grade[1] * 0.6) + (lab_grade[1] * 0.4)) + ((lec_grade[2] * 0.6) + (lab_grade[2] * 0.4))) / 3) };
    std::cout << "Overall Grade (Lec and Lab): " << overall;

    (overall >= 96) ? std::cout << " [1.00] A+ Excellent." :
        (overall >= 91) ? std::cout << " [1.25] A Very Good." :
            (overall >= 86) ? std::cout << " [1.50] A- Very Good." :
                (overall >= 81) ? std::cout << " [1.75] B+ Good." :
                    (overall >= 75) ? std::cout << " [2.00] B Good." :
                        (overall >= 69) ? std::cout << " [2.25] B- Fair." :
                            (overall >= 63) ? std::cout << " [2.50] C+ Fair." :
                                (overall >= 57) ? std::cout << " [2.75] C Fair." :
                                    (overall >= 50) ? std::cout << " [3.00] C- Fair." :
                                                        std::cout << " [5.00] F Failed.";
}

int main(){

    std::cout << "AMA GRADING SYSTEM" << std::endl;

    lecture_grade();

    std::cout << "\n================================\n";

    laboratory_grade();

    std::cout << "\n================================\n";

    final_grade();

    return 0;
}
