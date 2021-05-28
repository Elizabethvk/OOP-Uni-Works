#include "repository.hpp"

void Repository::saveFile(const string& fileName, const std::vector<Furniture*>& furniture) {
    std::ofstream file;
    file.open(fileName, std::ios::binary | std::ios::app);

    if (!file.is_open()) {
        cout << "Couldn't open the file!" << endl;
        return;
    }
    else {
        for (unsigned i = 0; i < furniture.size(); ++i) {
            // double n = (*furniture[i]).getHeight();
            file.write((char*)& (*furniture[i]), sizeof(*furniture[i]));
        }
    }

    file.close();
}
