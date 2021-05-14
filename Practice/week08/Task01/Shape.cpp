#include "Shape.hpp"

Shape::Shape(string name) {
    type = name;
}

void Shape::print() {
    cout << "Type: " << type << endl;
}