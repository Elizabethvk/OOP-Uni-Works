#ifndef ORDER_H
#define ORDER_H

#include "list.hpp"

/* Да се направи темплейтен клас Order, който наследява List и спазва свойството всичките му елементи 
да са в нарастващ или намалящ ред (по избор). */


template <typename T>
class Order : public List<T> {
private:
    using List<T>::list;

    void sort(const std::string& orderType) {
        std::string desc = "desc";
        std::string asc = "asc";

        if(orderType == desc) {
            for(size_t i = 0; i < list.size(); ++i) {
                for(size_t j = i+1; j < list.size(); ++j) {
                    if (list[i] < list[j]) {
                        T temp = list[j];
                        list[j] = list[i];
                        list[i] = temp;
                    }
                }
            }
        }
        else if (orderType == asc) {
            for(size_t i = 0; i < list.size(); ++i) {
                for(size_t j = i+1; j < list.size(); ++j) {
                    if (list[i] > list[j]) {
                        T temp = list[i];
                        list[i] = list[j];
                        list[j] = temp;
                    }
                }
            }
        }
        else {
            cout << "only desc or esc order!" << endl;
            return;
        }
        
    }

public:
    Order() : List<T>::List() {};
    void add(const T& newElement) {
        List<T>::addElement(newElement);
        sort();
    }
};



#endif