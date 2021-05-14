#ifndef ID_H
#define ID_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class UniqueID {
private:
    static unsigned uniqueID;

protected:
    unsigned serialNumb;

public:
    UniqueID();
};

#endif