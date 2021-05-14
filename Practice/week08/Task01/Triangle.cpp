#include "Triangle.hpp"

// Triangle::Triangle(string name, double side1, double side2, double side3) 
//     : Shape(name)
// {
//     this->side1 = side1;
//     this->side2 = side2;
//     this->side3 = side3;

//}

Triangle::Triangle(double side1, double side2, double side3)
    : Shape("Triangle")
{
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}

void Triangle::print() {
    Shape::print();
    cout << "Side 1: " << side1 << endl;
    cout << "Side 2: " << side2 << endl;
    cout << "Side 3: " << side3 << endl;

}