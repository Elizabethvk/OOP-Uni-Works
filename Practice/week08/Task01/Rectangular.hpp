#ifndef RECTANGULAR_H
#define RECTANGULAR_H

#include "Shape.hpp"

class Rectangular : public Shape 
{

protected:
    double width;
    double height;
    Rectangular(string name, double width, double height);

public:
    Rectangular(double width, double height);
    void print();

};


#endif