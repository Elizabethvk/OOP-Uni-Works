#ifndef COLORED_REC_H
#define COLORED_REC_H

#include "Rectangular.hpp"

class ColoredRectangular : public Rectangular

{
private:
    string color;

public:
    //ColoredRectangular(string name, double width, double height, string color);
    ColoredRectangular(double width, double height, string color);
    void print();
};


#endif
