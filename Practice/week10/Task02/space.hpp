#pragma once

#include <fstream>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


class Poleti {
    int year;
    string name;

public:
    Poleti(int yearN, string nameN) 
        : year(yearN), name(nameN)
    {}

    int getYear() { return year; }

    string getName() { return name; }

    friend std::ostream& operator<<(std::ostream& out, Poleti& polet) {
        out << polet.getYear() << " " << polet.getName();
        return out;
    }

};

class NASA {
    Poleti** poletiN;
    int size;
    int capacity;

    // void getSz() {
    //     for(int i = 0; i < )
    // }
public:
    NASA() : poletiN(nullptr) 
    {}

    ~NASA() {
        for (int i = 0; i < size; ++i) {
            delete poletiN[i];
        }
        delete[] poletiN;
    }

    void readFile(string fileName) {
        std::ifstream file;
        file.open(fileName);

        poletiN = new Poleti*[10];
        capacity = 10;
        size = 0;


        if(file.good()) {
            //cout << "im in" << endl;


            while(!file.eof()) {
                int i = -1;
                string s;

                //if(file.peek()!= EOF) {
                    
                    file >> i;
                    if (i == -1)
                        break;
                    //file.ignore();
                    string c;
                    file >> c;
                            //cout << c << endl;
                            // cout << "i num: " << i << endl;
                    //while(getline(file, s)) {
                        //-getline(file,s);
                        //-file >> s;
                        //-cout << "s whil num: " << s << endl;

                    //}
                    //!cout << "s num: " << s << endl;

                        // Poleti* polet = new Poleti(i, s);
                        // poletiN[size] = polet;
                    poletiN[size] = new Poleti(i, c);
                    ++size;
                //}
                // else {
                //     break;
                // }
            }
        }

        file.close();
    }

    void saveBinary(string fileName) {
        std::ofstream file;
        file.open(fileName, std::ofstream::binary | std::ofstream::ate);

        if (file.is_open()) {
            for (int i = 0; i < size; ++i) {
                file << *poletiN[i] << endl;
            }
            
            
        }


        file.close();
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            //cout << "i: " << i << endl;
            cout << *poletiN[i] << endl;
        }
    }
};