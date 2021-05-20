#include "FamilyCar.hpp"
#include "SportCar.hpp"

int main() {
    // Car newCar(150, 45, 1212);
    FamilyCar famCar(150, 45, 1212);
    SportCar sporty(325, 100, 12323);

    famCar.print();
    sporty.print();

    Car* ptrFamCar = new FamilyCar(222, 13, 12321);
    Car* ptrSportCar = new SportCar(342, 64, 10023);

    ptrFamCar->print();

    ptrFamCar->startMovement();
    ptrFamCar->accelerate(12);

    ptrFamCar->print();
    ptrSportCar->print();

    return 0;
}