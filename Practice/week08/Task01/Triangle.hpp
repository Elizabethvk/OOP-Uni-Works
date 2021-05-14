#include "Shape.hpp"

class Triangle : public Shape

{
private:
    double side1;
    double side2;
    double side3;

public:
    //Triangle(string name, double side1, double side2, double side3);
    Triangle(double side1, double side2, double side3);
    void print();
};