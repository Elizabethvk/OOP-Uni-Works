#ifndef STOCK_H
#define STOCK_H

#include "table.hpp"
#include "chair.hpp"

#include <vector>

class Stock {
private:
    std::vector<Furniture*> furniture;
    // friend class Repository;
public:
    Stock() = default;
    ~Stock();
    const std::vector<Furniture*>* getStockPtr() const;
    void addFurniture(const unsigned int& number);
    void printById(const unsigned& id);
};


#endif
