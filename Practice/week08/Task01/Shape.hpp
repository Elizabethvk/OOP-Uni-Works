#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// enum Shapes {
//     rectangular = 0,
//     coloredRectangular,
//     square,
//     triangle
// };

class Shape {

private:
    string type;
public:
    Shape();
    Shape(string name);
    void print();
};

#endif