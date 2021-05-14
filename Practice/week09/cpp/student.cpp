#include "../hpp/student.hpp"

Student::Student(string name, string nmbr) 
    : Person(name), number(nmbr)
{
}

string Student::getNumber() {
    return number;
}

void Student::getInfoStud() {
    cout << "Name: ";
    Person::getName();

    cout << "Number: ";
    cout << number << endl;
}