// Exo 1 - create a rectangle class with a aidth and height. Create member function that compute the area of the rectangle
#include <iostream>
#include <stdio.h>
#include <cstdlib>


class Rectangle {

    int width;
    int height;

    int area() {
        return width * height;
    }

};


int main (void) {

    Rectangle rect = Rectangle();
    rect.width = 10;
    rect.height = 20;
    std::cout << rect.area() << endl;

    return 0;
}