#pragma once

#include "date.hpp"

#include <string>
using std::string;

class Registration() {
public:
    string id;
    Date date;

    // Класът ДА НЯМА конструктор по подразбиране
    Registration(const std::string& id, const Date& date) 
        : id(id), date(date)
    {
    }

    
    // Връща истина, ако номерът и датата на текущия обект съвпадат с тези на rhs.
    bool operator==(const Registration& rhs) const {
        return id == rhs.id && date == rhs;
    }


    // Проверява дали текущата регистрация предхожда тази в rhs. 
    //Считаме, че една регистрация A предхожда друга регистрация B или (1) ако датата на A е преди тази на B, или (2) 
    //ако двете дати съвпадат, но регистрационният номер на A предхожда лексикографски този на B.
    bool operator<(const Registration& rhs) const {
        return date < rhs.date || id < rhs.id;
    }

};