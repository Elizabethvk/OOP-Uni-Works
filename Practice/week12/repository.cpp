#include "repository.hpp"

void Repository::saveFile(const string& fileName) {
    std::ofstream file;
    file.open(fileName, std::ios_base::trunc);

    if (!file.is_open()) {
        cout << "Couldn't open the file!" << endl;
        return;
    }
    else {
        for (unsigned i = 0; i < furniture.size(); ++i) {

        }
    }

    file.close();
}
