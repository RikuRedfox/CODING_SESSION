// Andrew Jules Miyajima - 10.22.2022
// Inheritance
#include <string>
#include "5.subject.hpp"

class Math : public Subject{
    public:
        Math() : Subject("Mathematics", "CAS001", 5){ }
        std::string get_subject(){
            return Subject::get_subject();
        }
};


