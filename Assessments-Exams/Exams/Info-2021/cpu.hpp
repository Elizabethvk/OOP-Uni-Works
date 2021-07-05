#pragma once

#include "component.hpp"

class Cpu : public Component {
private:
    unsigned short cores; // 1 & 8
    unsigned short clockSpeed;

public:
    Cpu(const string& label, const unsigned short& cores, const unsigned short& clockSpeed) 
        : Component(label), cores(cores), clockSpeed(clockSpeed) 
    {
        if (cores < 1 || cores > 8) {
            throw std::invalid_argument("Cores should be between 1 and 8!");
        }
    }

    double price() const {
        return cores * 29.99;
    }

    void output(std::ostream& out) const {
        Component::output(out);
        out << "Price: " << cores * 29.99 << "$" << endl;
    }
};