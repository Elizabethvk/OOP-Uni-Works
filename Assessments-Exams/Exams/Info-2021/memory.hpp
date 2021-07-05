#pragma once

#include "component.hpp"

class Memory : public Component {
private:
    unsigned short capacity; // 1 & 10 000

public:
    Memory(const string& label, const unsigned short& capacity) 
            : Component(label), capacity(capacity) 
    {
        if (capacity < 1 || capacity > 10000) {
            throw std::invalid_argument("Capacity should be between 1 and 10 000!");
        }
    }


    double price() const {
        return capacity * 89.99;
    }

    void output(std::ostream& out) const {
        Component::output(out);
        out << "Price: " << capacity * 89.99 << "$" << endl;
    }
};