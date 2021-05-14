#include "../hpp/lecturer.hpp"

Lecturer::Lecturer(string name, double personSalary) 
    : Person(name), salary(personSalary)
{    
}

Lecturer::Lecturer(double personSalary) 
    : salary(personSalary)
{
}

double Lecturer::getSalary() {
    return salary;
}