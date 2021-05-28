#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <fstream>

#include "stock.hpp"

class Repository {
private:
    // std::vector<Furniture*> allFurniture;

    Repository()
    {
    }

    // friend class Stock;

public:
    Repository(const Repository& otherRepo) = delete;
    Repository operator=(const Repository& otherRepo) = delete;
    Repository(Repository&& otherRepo) = delete;
    Repository operator=(Repository& otherRepo) = delete;

    void saveFile(const string& fileName, const std::vector<Furniture*>& furniture);

};

#endif
