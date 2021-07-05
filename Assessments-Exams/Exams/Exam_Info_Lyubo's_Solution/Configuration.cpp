#include "Configuration.h"

#include <typeinfo>

Configuration::~Configuration()
{
    for (const Component* comp : components) {
        delete comp;
    }
}

void Configuration::insert(const Component* c)
{
    for (const Component* comp : components) {
        if (c->getType() == comp->getType()) {
            throw std::invalid_argument("Typanar");
        }
    }

    components.push_back(c);
}


double Configuration::price() const
{
    double result = 0.0;
    for (const Component* comp : components) {
        result += comp->price();
    }

    return result;
}

size_t Configuration::size() const
{
    return components.size();
}

const Component& Configuration::operator[](size_t index) const
{
    if (index > size() - 1) {
        throw std::out_of_range("Obyrka indeksa we");
    }

    return *components[index];
}

std::ostream& operator<<(std::ostream& out, const Configuration& config)
{
    for (const Component* component : config.components) {
        component->output(out);
    }
    out << "Total price: " << config.price() << '\n';

    return out;
}