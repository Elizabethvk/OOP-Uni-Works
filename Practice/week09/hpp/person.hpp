#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

class Person {
private:
    string name;
    size_t strLen;

public:
    Person();
    Person(string userName);
    string getName();
};


#endif