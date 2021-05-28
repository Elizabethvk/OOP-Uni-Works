#ifndef BED_H
#define BED_H

#include "furniture.hpp"

class Bed : public Furniture {
private:
    //
public:
    Bed(double height, double width, double length, unsigned int quantity, double price);
    void print();
    void printForFile(std::ostream& out);
};


#endif