#include "FamilyCar.hpp"

FamilyCar::FamilyCar() 
    : Car(0, 0, 0)
{    
}

FamilyCar::FamilyCar(double newMaxSpeed, double newCurrentSpeed, double newPrice) 
    : Car(newMaxSpeed, newCurrentSpeed, newPrice)
{        
}

void FamilyCar::startMovement() {
    // Car(currentSpeed) = 
    currentSpeed = 30;
}

void FamilyCar::stopMovement() {
    currentSpeed = 0;
}

void FamilyCar::accelerate(double kmh) {
    if (currentSpeed + kmh <= maxSpeed) {
        currentSpeed += kmh;
    }
    else {
        currentSpeed = maxSpeed;
        // std::cout << ""
    }
}

void FamilyCar::print() {
    FamilyCar::print();
}

