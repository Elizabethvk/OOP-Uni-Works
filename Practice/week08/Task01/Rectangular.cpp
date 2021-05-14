#include "Rectangular.hpp"

Rectangular::Rectangular(string name, double width, double height) 
    : Shape(name)
{
    this-> width = width;
    this-> height = height;
}

Rectangular::Rectangular(double width, double height) 
    : Shape("Rectangular")
{
    this-> width = width;
    this-> height = height;
}

void Rectangular::print() {
    Shape::print();
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
}