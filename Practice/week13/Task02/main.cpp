

#include "park.hpp"

int main() {
    vector<Park> parks;

    vector<Park>::iterator itV;

    string name;

    cout << "5 Names: " << endl;

    for(unsigned int i = 0; i < 5; ++i) {
        getline(cin, name);
        Park userPark(name);
        parks.push_back(userPark);
    }


    for (itV = parks.begin(); itV < parks.end(); ++itV) {
        itV.pop_back(1);
        cout << *itV << endl;
    }

    cout << "Names: " << endl;

    for (itV = parks.begin(); itV < parks.end(); ++itV) {
        cout << *itV << endl;
    }

    return 0;
}