#pragma once

#include "Component.h"


class Cpu : public Component
{
private:
    static const double PRICE_PER_CORE;
    unsigned short clockSpeed;
    unsigned short cores;

public:
    Cpu(unsigned short cores, unsigned short clockSpeed);

};