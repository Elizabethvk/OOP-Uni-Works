#pragma once

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <stdexcept> 
using std::exception;

#include "Message.hpp"

/*
enum Type {
    INFO,
    WARNING,
    ERROR,
    CRITICAL_ERROR
};*/

class Logger {
private:
    string fileName;

    ofstream file;

    static int numberOfMess[4];

public:
    Logger(const string& fileInfo) 
        : fileName(fileInfo)
    {
        openFile();
    }

    Logger();
    
    void write(const Message& msg) {
        if (!file.is_open()) {
            throw exception();
        }

        file << msg << endl;
    }

    static int getInformation(const string& type) {
        if (type == "INFO") {
            return numberOfMess[0];
        }
        else if (type == "WARNING") {
            return numberOfMess[1];
            
        }
        else if (type == "ERROR") {
            return numberOfMess[2];
        }
        else if (type == "CRITICAL_ERROR") {
            return numberOfMess[3];
        }
        else {
            cout << "No type is recognized!" << endl;
            return;
        }
    }

    void openFile() {
        // ofstream file;
        file.open(fileName, std::ios_base::out | std::ios::app);

        if (!file.is_open()) {
            // cout << "Couldn't open the file!" << endl;
            // return;

            throw exception();
        }
    }

    friend Logger& operator<<(Logger& log, const Message& user) {
        if (!log.file.is_open()) {
            throw exception();
        }
        
        log.write(user);

        switch (user.getType())
        {
        case INFO:
            ++numberOfMess[0];
            break;
        
        case WARNING:
            ++numberOfMess[1];
            break;
        case ERROR:
            ++numberOfMess[2];
            break;
        case CRITICAL_ERROR:
            ++numberOfMess[3];
            break;
        }

        return log;
    }

    ~Logger() {
        file.close();
    }
};

int Logger::numberOfMess[] = {0,};