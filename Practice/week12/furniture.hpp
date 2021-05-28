#ifndef FURNITURE_H
#define FURNITURE_H

#include <string>
using std::string;

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


class Furniture {
private:
    static unsigned int id;
    double height;
    double width; 
    double length;
    unsigned int quantity;
    double price;
    // Type type;
    bool isAvailable;
    // TODO: remove bool
public:
    Furniture() = default;
    Furniture( double height, double width, double length, unsigned int quantity, double price);
    bool getAvailabilty();
    void increaseQuantity(unsigned int num);
    void decreaseQuantity(unsigned int num);
    void print();
    void printForFile(std::ostream& out);
};


#endif