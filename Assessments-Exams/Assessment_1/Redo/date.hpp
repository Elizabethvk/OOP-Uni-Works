#pragma once

#include <stdexcept>
#include <cstdint>

using std::uint8_t;

const int NUM_OF_MONTHS = 12;

class Date {
private:
uint8_t m_day;
uint8_t m_month;
uint16_t m_year;

bool isLeapYear() {
    return (m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0 );
}

bool checkDate() {
    // 1 - 31, 2- 28/29, 3- 31, 4- 30, 5-31 , 6- 30, 7-31, 8-31, 9-30,10-31,11-30,12-31

    int daysInMonth[NUM_OF_MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear()) {
        daysInMonth[1] = 29;
    }

    if ( m_month < 1 || m_month > 12) {
        return false;
    }

    if (m_day > daysInMonth[m_month - 1] || m_day == 0) {
        return false;
    }

    return true;

}

public:
    Date(unsigned int day, unsigned int month, unsigned int year) 
        : m_day(day), m_month(month), m_year(year)
    {
        if (checkDate()) {
            throw std::invalid_argument("Argument is invalid!");
        }
    }
    // конструктор, който създава нов обект за дата с ден day, месец month и година year. Ако датата не е валидна, да се хвърля изключение от тип std::invalid_argument.

    unsigned int day() const {
        return m_day;
    }
    // връща деня като unsigned int.

    unsigned int month() const {
        return m_month;
    }
    // връща месеца като unsigned int.

    unsigned int year() const {
        return m_year;
    }
    // връща годината като unsigned int.

    bool operator==(const Date& rhs) const {
        return (m_day == rhs.day() && m_month == rhs.month() && m_year == rhs.year());
    }
    // Връща истина, ако датата съхранена в текущия обект е същата като тази в rhs.

    bool operator<(const Date& rhs) const {
        return (m_day < rhs.day() || m_month < rhs.month() || m_year < rhs.year());
    }
    // връща истина, ако датата съхранена в текущия обект е по-ранна от тази съхранена в обекта rhs.
};