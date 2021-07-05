#pragma once

#include <vector>

#include "Utils.h"



class Configuration
{
private:
    std::vector<const Component*> components;

    Configuration() = default;
    Configuration(const Configuration& other) = default;
    Configuration& operator=(const Configuration& other) = default;

    void insert(const Component* c);

public:
    ~Configuration();

    double price() const;
    size_t size() const;

    const Component& operator[](size_t index) const;

    friend std::ostream& operator<<(std::ostream& out, const Configuration& config);

    friend Configuration* createConfiguration();

};