#include "ColoredRectangular.hpp"


ColoredRectangular::ColoredRectangular(double width, double height, string color) 
    : Rectangular("Colored Rectangular", width, height)
{
    this-> color = color;
}

// ColoredRectangular::ColoredRectangular(string name, double width, double height, string color) 
//     : Rectangular(name, width, height)
// {
//     this-> color = color;
// }

void ColoredRectangular::print() {
    Rectangular::print();
    cout << "Color: " << color << endl;
}