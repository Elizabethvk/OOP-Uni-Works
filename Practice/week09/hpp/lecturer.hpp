#ifndef LECTURER_H
#define LECTURER_H

#include "person.hpp"

class Lecturer : virtual public Person{
private:
    double salary;
public:
    Lecturer(string name, double personSalary);
    Lecturer(double personSalary);
    double getSalary();
};    

#endif