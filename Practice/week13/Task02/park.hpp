#pragma once
#include <string>
#include <vector>
#include <iterator> // Iterators

#include <iostream>

using std::cout; 
using std::cin; 
using std::endl;


using std::string; 
using std::vector;


class Park {
private:
    string name;
public:
    Park(const string& name) : name(name) {}

    friend std::ostream& operator<<(std::ostream& out, const Park& otherPark) {
        out << otherPark.name;
        return out;
    }
};