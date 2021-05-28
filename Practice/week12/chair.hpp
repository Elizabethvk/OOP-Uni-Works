#ifndef CHAIR_H
#define CHAIR_H

#include "furniture.hpp"

enum Type {
    wooden = 0,
    metal,
    plastic
};


class Chair : public Furniture {
private:
    Type type;
public:
    Chair(double height, double width, double length, unsigned int quantity, double price, Type type);
    void print();
    void printForFile(std::ostream& out);
    
};




#endif