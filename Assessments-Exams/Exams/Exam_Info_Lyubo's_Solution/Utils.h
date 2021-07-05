#pragma once

#include "Cpu.h"
#include "Memory.h"
#include "ComponentType.h"



class Utils
{
private:
    static const std::string components[];

public:
    static Component* createComponent();

    static void printMenu();

};