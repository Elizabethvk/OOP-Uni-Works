#ifndef FURNITURE_H
#define FURNITURE_H

#include <string>
using std::string;

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum Type {
    everyday = 0,
    kitchen,
    wooden,
    metal,
    plastic
};

class Furniture {
private:
    static unsigned int id;
    double height;
    double width; 
    double length;
    unsigned int quantity;
    double price;
    Type type;
    // bool isAvailable;
    // TODO: remove bool
public:
    Furniture() = default;
    Furniture(double height, double width, double length, unsigned int quantity, double price, unsigned int n);
    Furniture(double height, double width, double length, unsigned int quantity, double price);
    bool getAvailabilty();
    void increaseQuantity(unsigned int num);
    void decreaseQuantity(unsigned int num);
    bool decreaseQuantityCheck(unsigned int num);

    double getHeight() const;
    double getWidth() const;
    double getLength() const;
    unsigned getQuantity() const;
    double getPrice() const;
    Type getType() const;

    void print();
    void printForFile(std::ostream& out);
};


#endif