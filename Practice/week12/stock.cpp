#include "stock.hpp"

Stock::~Stock() {
    for (unsigned i = 0; i < furniture.size(); ++i) {
        delete furniture[i];
    }
}

const std::vector<Furniture*>* Stock::getStockPtr() const {
    return &furniture;
}

void Stock::addFurniture() {
    double height;
    double width; 
    double length;
    unsigned int quantity;
    double price;
    unsigned int type;

    cout << "Height: " << endl;
    cin >> height;

    cout << "Width: " << endl;
    cin >> width;

    cout << "Length: " << endl;
    cin >> length;

    cout << "Quantity: " << endl;
    cin >> quantity;

    cout << "Price: " << endl;
    cin >> price;

    cout << "Type: " << endl;
    cout << "Choose -" << endl
        << "For tables: 1. Everyday, 2. Kitchen" << endl
        << "For chair: 3. Wooden, 4. Metal, 5. Plastic" << endl
        << "If you don't want a type - 6." << endl;
    cin >> type; 
    --type;

    if (type == 5) {
        Furniture* userInput = new Furniture(height, width, length, quantity, price);
    }
    else {
        Furniture* userInput = new Furniture(height, width, length, quantity, price, type);
    }

    furniture.push_back(userInput);
}

void Stock::printById(const unsigned& id) {
    for (unsigned i = 0; i < furniture.size(); ++i) {
        if (i == id) {
            (*furniture)[i].print();
        }
    }
}