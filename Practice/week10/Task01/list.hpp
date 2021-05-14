#ifndef LIST_H
#define LIST_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;


/*
Да се направи темплейтен клас List, който има следните функционалности:

    съдържа произволен брой уникални елементи

    да се добавят нови елементи
    да се премахва елемент на определена позиция
    да се достъпват елементите във вида list[3]
    да дава информация за броя елементи
    да дава информация дали е празен
    да има функция за записване на елементите във файл
    да има функция за зареждане на елементите от файл
*/

template <typename T>
class List {
private:
    //T element;
    //unique ?
    std::vector<T> list;

    int findPosition(T newElement) {
        for(size_t i = 0; i < list.size(); ++i) {
            if (list[i] == newElement) {
                return i;
            }
        }
        return -1;
    }
    
public:
    List() {
        try
        {
            list.reserve(3);
        }
        catch(const std::bad_alloc& e)
        {
            std::cerr << "No memory!" << '\n';
        }
        
    }

    // no need
    // ~List() {
    //     list.clear();
    // }

    void addElement(T newElement) {
        if(findPosition(newElement)== -1) {
            list.push_back(newElement);
        }
        else {
            cout << "The element already exists! :/" << endl;
            return;
        }
    }
    void removeElement(T newElement) {
        int position = findPosition(newElement);

        if(position != -1) {
            list.erase(list.begin()+position);
        }
        else {
            cout << "Non-existent element!" << endl;
        }
    }
    T getElement(size_t pos) {
        if(pos >= 0 && pos < list.size()) {
            return list[pos];
        }
        else {
            cout << "" << endl;
            // TO DO: Custom exception
            throw -1;

        }

        // try
        // {
        //     return [pos];
        // }
        // catch(const std::exception& e)
        // {
        //     std::cerr << e.what() << '\n';
        // }
        
    }
    size_t getSize() {
        return list.size();
    }

    bool areThereElements() {
        // return list.empty();
        return list.size()>=1;
    }

    void save(std::string fileName) {
        std::ofstream ofile; //(fileName, std::fstream::in | std::fstream::ate);
        ofile.open(fileName, std::fstream::in | std::fstream::ate);

        //ofile << print();

        for(size_t i = 0; i < list.size(); ++i) {
            ofile << list[i] << endl;
        }

        ofile.close();
    }

    //std::vector<T> read(std::string fileName) {
    void read(std::string fileName) {

        //std::vector<T> fileList;

        //std::ifstream ifile(fileName);
        std::ifstream ifile;
        ifile.open (fileName, std::ifstream::in);


        if(ifile.good()) {
            size_t i = 0;

            while(1) {
                T newElement;
                if (ifile >> newElement) {
                    //fileList
                    list.push_back(newElement);
                }
                else {
                    break;
                }
            }
        }
        

        ifile.close();

        //return fileList;

    }    

    void print() {
        for(size_t i = 0; i < getSize(); ++i) {
            cout << list[i] << endl;
        }
        
    }
};




#endif