#include <string>

class Question{
    private:
        std::string Question_Text;
        std::string Answer_1;
        std::string Answer_2;
        std::string Answer_3;
        std::string Answer_4;
        int Correct_Answer;
        int Question_Score;

    public:
    // Setter Function
        void setValues(std::string, std::string, std::string, std::string, std::string, int, int);

    // Function to ask questions
        void askQuestion();
};