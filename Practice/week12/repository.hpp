#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <fstream>

#include "stock.hpp"

// class Stock;

class Repository {
private:
    // std::оfstream file;
    std::vector<Furniture*> allFurniture;

    Repository()
    {
    }

    // friend class Stock;

public:
    Repository(const Repository& otherRepo) = delete;
    Repository operator=(const Repository& otherRepo) = delete;
    Repository(Repository&& otherRepo) = delete;
    Repository operator=(Repository& otherRepo) = delete;

    void saveFile(const string& fileName, std::vector);

};

#endif
