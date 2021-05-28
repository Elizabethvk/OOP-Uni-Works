#include "stock.hpp"

Stock::~Stock() {
    for (unsigned i = 0; i < furniture.size(); ++i) {
        delete furniture[i];
    }
}

const std::vector<Furniture*>* Stock::getStockPtr() const {
    return &furniture;
}

void Stock::addFurniture(const unsigned int& furniture) {
    
}