#ifndef TABLE_H
#define TABLE_H

#include "furniture.hpp"

// enum Type {
//     // living_room = 0,
//     everyday = 0,
//     kitchen
// };

class Table : public Furniture {
private:
    // Type type;
public:
    Table(double height, double width, double length, unsigned int quantity, double price, Type type);
    Type getType() const;
    void print();
    void printForFile(std::ostream& out);
};




#endif