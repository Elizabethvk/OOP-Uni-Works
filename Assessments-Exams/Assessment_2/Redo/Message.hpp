#pragma once

#include <string>
using std::string; 

#include <iostream>
using std::ostream;

using std::cout; 
using std::cin; 
using std::endl;


enum Type {
    INFO,
    WARNING,
    ERROR,
    CRITICAL_ERROR
};

class Message {
    Type type;
    string description;

public:
    Message(const Type& type, const string& description) 
        : type(type), description(description)
    {
    }

    Type getType() const {
        return type;
    }

    friend ostream& operator<<(ostream& out, const Message& user) {
        switch (user.type)
        {
        case INFO:
            out << "Info: ";
            break;
        
        case WARNING:
            out << "Warning: ";
            break;
        case ERROR:
            out << "Error: ";
            break;
        case CRITICAL_ERROR:
            out << "Critical Error: ";
            break;
        }

        out << user.description;
    }
};