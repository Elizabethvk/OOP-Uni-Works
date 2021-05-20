#include "Car.hpp"

Car::Car() 
    : maxSpeed(0), currentSpeed(0), price(0)
{
}

Car::Car(double newMaxSpeed, double newCurrentSpeed, double newPrice) 
    : maxSpeed(newMaxSpeed), currentSpeed(newCurrentSpeed), price(newPrice)
{
}

void Car::startMovement() {
    currentSpeed = 40;
    //maxSpeed = 55;
}

void Car::stopMovement() {
    currentSpeed = 0;
}

void Car::startEngine() 
    
{
    Engine::start();
    std::cout << "The engine started!" << std::endl;
}

void Car::stopEngine() {
    Engine::stop();
    std::cout << "The engine stopped!" << std::endl;
}

// void Car::accelerate() {
    
// }

void Car::print() {
    std::cout << "Max Speed: " << maxSpeed << std::endl;
    std::cout << "Current Speed: " << currentSpeed << std::endl;
    std::cout << "Price: " << price << std::endl;
}