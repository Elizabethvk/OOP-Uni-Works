#include "Square.hpp"

// Square::Square(string name, double side) 
//     : Shape(name)
// {
//     this-> side = side;
// }

Square::Square(double side) 
    : Shape("Square")
{
    this-> side = side;
}

void Square::print() {
    Shape::print();
    cout << "Side: " << side << endl;
}