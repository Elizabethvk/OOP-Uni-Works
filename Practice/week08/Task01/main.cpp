#include "ColoredRectangular.hpp"
#include "Square.hpp"
#include "Triangle.hpp"

int main() {
    Shape shape("circle");
    shape.print();

    cout << "------" << endl;

    Rectangular rect(12, 14);
    rect.print();

    cout << "------" << endl;

    ColoredRectangular colRect(10, 20, "blue");
    colRect.print();

    cout << "------" << endl;

    Square sqr( 2.4);
    sqr.print();

    cout << "------" << endl;

    Triangle trig( 12, 23.2, 21);
    trig.print();


    return 0;
}