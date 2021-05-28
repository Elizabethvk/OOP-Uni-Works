#include "bed.hpp"

Bed::Bed(double height, double width, double length, unsigned int quantity, double price) 
    : Furniture(height, width, length, quantity, price)
{
}

void Bed::print() {
    Furniture::print();
}

void Bed::printForFile(std::ostream& out) {
    Furniture::printForFile(out);
}