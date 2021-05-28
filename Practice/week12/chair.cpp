#include "chair.hpp"

Chair::Chair(double height, double width, double length, unsigned int quantity, double price, Type type)
    : Furniture(height, width, length, quantity, price, type)
{
    // this->type = type;
}

// Type Chair::getType() const {
//     return type;
// }

void Chair::print() {
    Furniture::print();
    // cout << "Type: " << type << endl;
}

void Chair::printForFile(std::ostream& out) {
    Furniture::printForFile(out);
    // out << type << endl;
}

/*
    ofstream file;
    for(...) {
        // file << "ffs";
        (*furniture[i]).printToFile(file);
    }



*/