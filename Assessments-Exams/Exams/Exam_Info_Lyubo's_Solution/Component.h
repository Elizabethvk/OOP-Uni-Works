#pragma once

#include <iostream>
#include <string>

#include "ComponentType.h"


class Component
{
protected:
    std::string label;
    double myPrice;
    ComponentType type;

public:
    Component() = default;

    double price() const;
    void output(std::ostream& out) const;

    ComponentType getType() const;

};