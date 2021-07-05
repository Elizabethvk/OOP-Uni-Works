#include "Component.h"


double Component::price() const
{
    return myPrice;
}

void Component::output(std::ostream& out) const
{
    out << label << ' ' << myPrice << '\n';
}

ComponentType Component::getType() const
{
    return type;
}