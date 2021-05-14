#include "space.hpp"

int main() {
    NASA cheti;
    cheti.readFile("Leti.txt");
    cheti.print();

    cheti.saveBinary("BinarnoLetim.txt");

    return 0;
}