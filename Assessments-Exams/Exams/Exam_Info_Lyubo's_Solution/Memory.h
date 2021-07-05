#pragma once

#include "Component.h"


class Memory : public Component
{
private:
    static const double PRICE_PER_GIGABYTE;
    unsigned short capacity;

public:
    Memory(unsigned short capacity);

};