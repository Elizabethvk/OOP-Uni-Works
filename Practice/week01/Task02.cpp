#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::nothrow;
using std::endl;

struct Point{
    double x, y;

    void readCoordinates(){
        cout << "x: " <<endl;
        cin >> x;
        cout << "y: " <<endl;
        cin >> y;
    }

    void printCoordinates(){
        cout << "(" << x << ", " << y << ")" << endl;
    }

    double distanceStart(){
        return sqrt(x*x+y*y);
    }

    double distanceTwoPoints(){
        double 
    }

};


int main(){

}