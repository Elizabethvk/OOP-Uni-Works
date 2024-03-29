#pragma once

#include "registration.hpp"

class RegistrationList() {
private:
    size_t capacity;


public:
    //Регистрациите в списъка трябва да се пазят сортирани в нарастващ ред.
    
    RegistrationList(std::size_t capacity) създава списък, който може да съдържа най-много capacity на брой регистрации.

    // Всички функции от rule of 3 (по желание: всички от rule of 5). 
    //Забележете, че RegistrationList не е като класа за гараж от домашното. 
    //RegistrationList притежава обектите съхранени в него и трябва да ги почиства в деструктора си. 
    //При копиране на списък, новото копие трябва да създаде за себе си нови обекти от тип Registration; 
    //то не трябва да сочи към тези на оригинала. Копието трябва да бъде със същия капацитет като оригинала. 
    //Операторът за присвояване да дава strong exception safety guarantee.

    void insert(const std::string& id, const Date& date)
    // добавя регистрацията с номер id и дата date. Тъй като класът трябва да поддържа регистрациите сортирани в нарастващ ред, тази операция трябва да вмъкне новия запис на подходящо място в списъка. Ако операцията не успее (например няма повече място), да се хвърля изключение от тип std::exception. Операцията да дава strong exception guarantee.

    const Registration& at(std::size_t index) const
    // достъп до елемента намиращ се на позиция index. Ако такъв няма, да се хвърля изключение std::out_of_range.

    const Registration& operator[](std::size_t index) const
    // достъп до елемента намиращ се на позиция index. Функцията да не прави проверка за коректност дали index е валидна позиция. (В debug режим assert-вайте дали index е валидна позиция).

    bool empty() const
    // Проверява дали списъка е празен (т.е. в него не е била добавена нито една регистрация).

    std::size_t capacity() const
    // капацитет на списъка.

    std::size_t size() const
    // брой регистрации добавени в списъка.


};