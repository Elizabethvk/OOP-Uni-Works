#ifndef STUDENT_H
#define STUDENT_H

#include "person.hpp"

class Student : virtual public Person {
private:
    string number;

public:
    Student();
    Student(string name, string nmbr);
    string getNumber();
    void getInfoStud();
};


#endif