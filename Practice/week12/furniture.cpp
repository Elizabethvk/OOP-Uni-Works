#include "furniture.hpp"

Furniture::Furniture(double height, double width, double length, unsigned int quantity, double price, Type type)
    : height(height), width(width), length(length), quantity(quantity), price(price), type(type) //, isAvailable(true)
{
}

// bool Furniture::getAvailabilty() {
//     return isAvailable;
// }

void Furniture::increaseQuantity(unsigned int num) {
    ++quantity;
    ++id;
    // if (!isAvailable) {
        // isAvailable = true;
    // }
}

void Furniture::decreaseQuantity(unsigned int num) {
    --quantity;
    if (quantity == 0) { // Better that way, cus int 
        // isAvailable = false;

    }
}

bool Furniture::decreaseQuantityCheck(unsigned int num) {
    --quantity;
    return quantity == 0; // Better that way, cus int 
}

double Furniture::getHeight() const {
    return height;
}

double Furniture::getWidth() const {
    return width;
}

double Furniture::getLength() const {
    return length;
}

unsigned Furniture::getQuantity() const {
    return quantity;
}

double Furniture::getPrice() const {
    return price;
}

Type Furniture::getType() const {
    return type;
}


void Furniture::print() {
    cout << "ID: " << id << endl;
    cout << "Height: " << height << endl;
    cout << "Width: " << width << endl;
    cout << "Length: " << length << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Price: " << price << endl;
    cout << "Type: " << type << endl;
}

void Furniture::printForFile(std::ostream& out) {
    out << id << " " << height << " " << width << " " << length << " " << quantity << " " << price << " " << type << endl;
}

unsigned int Furniture::id = 0;