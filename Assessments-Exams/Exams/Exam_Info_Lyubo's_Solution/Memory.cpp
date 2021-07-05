#include "Memory.h"

const double Memory::PRICE_PER_GIGABYTE = 89.99;

Memory::Memory(unsigned short capacity)
    : capacity(capacity)
{
    if (!capacity || capacity > 10000) {
        throw std::out_of_range("Mnogo losho");
    }

    label = "memory";
    myPrice = capacity * PRICE_PER_GIGABYTE;
    type = ComponentType::MEMORY;
}