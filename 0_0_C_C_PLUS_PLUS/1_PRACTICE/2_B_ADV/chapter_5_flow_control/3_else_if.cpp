#include <iostream>

//TOOLS
const int PEN {10};
const int MARKER (20);
const int ERASER (30);
const int RECTANGLE {40};
const int CIRCLE {50};
const int ELLIPSE {60};

int main(){

    int tool (PEN);

    if (tool == PEN){
        std::cout << "Active tool is PEN " << std::endl; 
    } 
    else if (tool == MARKER){
        std::cout << "Active tool is MARKER " << std::endl;
    } 
    else if (tool == ERASER){
        std::cout << "Active tool is ERASER " << std::endl;
    } 
    else if (tool == RECTANGLE){
        std::cout << "Active tool is RECTANGLE " << std::endl;
    } 
    else if (tool == CIRCLE){
        std::cout << "Active tool is CITCLE " << std::endl;
    } 
    else if (tool == ELLIPSE){
        std::cout << "Active tool is ELLIPSE " << std::endl;
    } 
    else {
        std::cout << "Can't match any tools." << std::endl;
    }

    return 0;
}