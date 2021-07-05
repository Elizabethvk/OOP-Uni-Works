#pragma once

#include "component.hpp"
#include <vector>
using std::vector;

#include <iterator>

class Configuration {
private:
    vector<Component*> components;

    Configuration() = default;

    void insert (const Component* c) {
        for (unsigned int i = 0; i < components.size(); ++i) {
            if ()
        }

        components.push_back(c); 
    }

    Configuration(const Configuration& user)= default;

    Configuration& operator=(const Configuration& other) = default; // ???

public:
    ~Configuration() {
        for (unsigned int i = 0; i < components.size(); ++i) {
            delete components[i];
        }
    }

    double price() const {
        double price = 0.0;

        // vector<Component*>::iterator it;

        // for (it = components.begin(); it < components.end(); ++it) {
        // }

        for (unsigned int i = 0; i < components.size(); ++i ) {
            price += components[i]->price();
        }

        return price;
    }

    size_t size() const {
        return components.size();
    }

    const Component* operator[](size_t pos) const {
        if (pos < 0 || pos > Configuration::size()-1) {
            throw std::out_of_range("No element!");
        }
        return components[pos];
    }

    friend std::ostream& operator<<(std::ostream& out, const Configuration& userConf) {
        for (unsigned int i = 0; i < userConf.components.size(); ++i) {
            userConf[i]->output(out);
        }

        out << "Price for everything: " << userConf.price() << endl;
    }

};