#ifndef SCAR_H
#define SCAR_H

#include "Car.hpp"

class SportCar : public Car {

public:
    SportCar();
    SportCar(double newMaxSpeed, double newCurrentSpeed, double newPrice);

    void startMovement();
    void stopMovement();
    // void startEngine();
    // void stopEngine();
    void accelerate(double kmh);
    void print();

};


#endif