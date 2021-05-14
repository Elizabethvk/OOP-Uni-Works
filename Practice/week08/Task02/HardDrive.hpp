#ifndef HARD_DR_H
#define HARD_DR_H

#include "IDs.hpp"



class HardDrive : public UniqueID {
private:
    string hddDescr;

public:
    HardDrive(string hddDescription);


};



#endif