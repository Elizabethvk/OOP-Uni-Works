#include "furniture.hpp"

Furniture::Furniture(double height, double width, double length, unsigned int quantity, double price)
    : height(height), width(width), length(length), quantity(quantity), price(price), isAvailable(true)
{
}

bool Furniture::getAvailabilty() {
    return isAvailable;
}

void Furniture::increaseQuantity(unsigned int num) {
    ++quantity;
    ++id;
    if (!isAvailable) {
        isAvailable = true;
    }
}

void Furniture::decreaseQuantity(unsigned int num) {
    --quantity;
    if (quantity == 0) { // Better that way, cus int 
        isAvailable = false;
    }
}



void Furniture::print() {
    cout << "ID: " << id << endl;
    cout << "Height: " << height << endl;
    cout << "Width: " << width << endl;
    cout << "Length: " << length << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Price: " << price << endl;
    // cout << "Type: " << type << endl;
}

void Furniture::printForFile(std::ostream& out) {
    out << id << " " << height << " " << width << " " << length << " " << quantity << " " << price << " ";
}

unsigned int Furniture::id = 0;