#include "Cpu.h"


const double Cpu::PRICE_PER_CORE = 29.99;

Cpu::Cpu(unsigned short cores, unsigned short clockSpeed)
    : cores(cores), clockSpeed(clockSpeed)
{
    if (!cores || cores > 8) {
        throw std::out_of_range("Losho");
    }

    label = "CPU";
    myPrice = PRICE_PER_CORE * cores;
    type = ComponentType::CPU;
}