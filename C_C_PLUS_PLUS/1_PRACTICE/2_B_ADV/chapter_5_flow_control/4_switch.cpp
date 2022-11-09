#include <iostream>

const int PEN {10};
const int MARKER (20);
const int ERASER (30);
const int RECTANGLE {40};
const int CIRCLE {50};
const int ELLIPSE {60};

int main(){

    int tool {PEN};

    switch (tool) {
    case PEN:
        std::cout << "Active tool is Pen." << std::endl;
        break;
    
    case MARKER:
        std::cout << "Active tool is Marker." << std::endl;
        break;

    case ERASER:
        std::cout << "Active tool is Eraser." << std::endl;
        break;

    case RECTANGLE:
        std::cout << "Active tool is Rectangle." << std::endl;
        break;

    case CIRCLE:
        std::cout << "Active tool is Circle." << std::endl;
        break;

    case ELLIPSE:
        std::cout << "Active tool is Ellipse." << std::endl;
        break;

    default:
        std::cout << "No match found!" << std::endl;
        break;
    }

    return 0;
}