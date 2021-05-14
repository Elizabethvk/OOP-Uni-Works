#include "Shape.hpp"

class Square : public Shape 
{
private:
    double side;
public:
    //Square(string name, double side);
    Square(double side);
    void print();

};