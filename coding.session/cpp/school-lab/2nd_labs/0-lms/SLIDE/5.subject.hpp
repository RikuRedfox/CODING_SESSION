// Andrew Jules Miyajima - 10.22.2022
#include <string>
#include <sstream>

class Subject{
    private:
        std::string m_title, m_code;
        short m_units;
    
    public:
        Subject(std::string title, std::string code, short units){
            m_title = title;
            m_code = code;
            m_units = units;
        }

        std::string get_subject(){
            std::ostringstream s;
            s << "[" << m_code << "]" << m_title;
            s << " (" << m_units << " units)";
            return s.str();
        }
};