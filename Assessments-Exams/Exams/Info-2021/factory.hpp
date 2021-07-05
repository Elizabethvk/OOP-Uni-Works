#pragma once

#include "component.hpp" // Dali ?
#include "memory.hpp"
#include "cpu.hpp"
#include "type.hpp"

class Factory {
private:

public:
    Component* create_component() {
        cout << "Component - CPU or Memory?" << endl;
        string answer;

        getline(cin, answer);

        if (answer == "CPU") {
            cout << "Name: ";
            string name;
            getline(cin, name);

            cout << "Cores: ";
            unsigned short cores;
            cin >> cores;

            cout << "Clock Speed: ";
            unsigned short cSpeed;
            cin >> cSpeed;
            
            try {
                Cpu* userCPU = new Cpu(name, cores, cSpeed);
            }
            catch (const std::bad_alloc&) {
                return nullptr;
            }
        }
        else if (answer == "Memory") {
             cout << "Name: ";
            string name;
            getline(cin, name);

            cout << "Capacity: ";
            unsigned short capacity;
            cin >> capacity;

            try {
                Memory* userCPU = new Memory(name, capacity);
            }
            catch (const std::bad_alloc&) {
                return nullptr;
            }
        }
        else {
            return nullptr;
        }
    }

    void print() {

    }

};