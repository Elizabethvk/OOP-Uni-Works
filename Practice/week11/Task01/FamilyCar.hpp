#ifndef FCAR_H
#define FCAR_H

#include "Car.hpp"

class FamilyCar : public Car {

public:
    FamilyCar();
    FamilyCar(double newMaxSpeed, double newCurrentSpeed, double newPrice);

    void startMovement();
    void stopMovement();
    // void startEngine();
    // void stopEngine();
    void print();
    void accelerate(double kmh);


};


#endif