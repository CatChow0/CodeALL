// Exo 1 - create a rectangle class with a aidth and height. Create member function that compute the area of the rectangle
#include <iostream>
#include <stdio.h>
#include <cstdlib>

class Rectangle {

    public:

        int width;
        int height;

        int area() {
            return width * height;
        }

};


int main (void) {

    Rectangle rect;

    std::cout << "Entré la longeur puis la largeur du rectangle" << std::endl;
    std::cin >> rect.width >>  rect.height;
    if (rect.width == rect.height) {
        std::cout << "Air du carré" << rect.area() << std::endl;
    } else {
        std::cout << "Air du rectangle " << rect.area() << std::endl;
    }

    return 0;
}

