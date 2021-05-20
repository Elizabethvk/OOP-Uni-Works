#include "SportCar.hpp"


SportCar::SportCar() 
    : Car(0, 0, 0)
{    
}

SportCar::SportCar(double newMaxSpeed, double newCurrentSpeed, double newPrice) 
    : Car(newMaxSpeed, newCurrentSpeed, newPrice)
{        
}

void SportCar::startMovement() {
    // Car(currentSpeed) = 
    currentSpeed = 50;
}

void SportCar::stopMovement() {
    currentSpeed = 0;
}

void SportCar::accelerate(double kmh) {
    if (currentSpeed + kmh <= maxSpeed) {
        currentSpeed += kmh;
    }
    else {
        currentSpeed = maxSpeed;
        // std::cout << ""
    }
}

void SportCar::print() {
    Car::print();
}