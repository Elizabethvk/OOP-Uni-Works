#include "../hpp/person.hpp"

Person::Person() 
    : name(""), strLen(0)
{
}

Person::Person(string userName) {
    name = userName;
    strLen = userName.length();
}

string Person::getName() {
    return name;
}