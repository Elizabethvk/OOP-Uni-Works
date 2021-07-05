#pragma once

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <stdexcept>

class Component {
private:
    string label;

public:
    Component(const string& label) 
        : label(label)
    {
    }

    virtual double price() const {}

    virtual void output(std::ostream& out) const {
        out << "Name: " << label << endl;
    }
};