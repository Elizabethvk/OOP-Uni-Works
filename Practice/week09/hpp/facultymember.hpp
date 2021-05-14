#ifndef FACULTYMEMBER_H
#define FACULTYMEMBER_H

#include "student.hpp"
#include "lecturer.hpp"

#include <fstream>

using std::ifstream;
using std::ofstream;

class FacultyMember : public Student, public Lecturer {
private:


public:

    FacultyMember(string name, string number, double salary);
    void setFacultyMember();
    void printInfo();

    FacultyMember loadFromFile(string filename);
    void writeInFile(string filename);
};


#endif