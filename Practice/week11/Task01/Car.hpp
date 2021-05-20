#ifndef CAR_H
#define CAR_H

#include "Vehicle.hpp"
#include "Engine.hpp"

#include <iostream>


class Car : public Vehicle, public Engine {
protected:
    double maxSpeed;
    double currentSpeed;
    double price;

public:
    Car();
    Car(double newMaxSpeed, double newCurrentSpeed, double newPrice);
    
    virtual void startMovement();
    virtual void stopMovement();
    virtual void startEngine();
    virtual void stopEngine();
    virtual void accelerate(double kmh) = 0;
    virtual void print();
};


#endif