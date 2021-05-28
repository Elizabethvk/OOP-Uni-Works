#include "table.hpp"


Table::Table(double height, double width, double length, unsigned int quantity, double price, Type type)
    : Furniture(height, width, length, quantity, price)
{
    this->type = type;
}


void Table::print() {
    Furniture::print();
    cout << "Type: " << type << endl;
}

void Table::printForFile(std::ostream& out) {
    Furniture::printForFile(out);
    out << type << endl;
}