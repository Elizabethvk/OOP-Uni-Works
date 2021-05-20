#include "space.hpp"
#include <cstring>

int main() {
    NASA cheti;
    cheti.readFile("Leti.txt");
    cheti.print();

    cout << "---------" << endl;

    cheti.saveBinary("BinarnoLet.txt");

    cheti.readBinary("BinarnoLet.txt");


    //cheti.readBinary("BinaryLet.txt");

    cout << "---------" << endl;

    cheti.print();


    // struct person {
    //     char name[30];
    //     int age;
    // };

    // person p;
    // strcpy(p.name, "Some Name");

    // p.age = 10;
    
    // std::ofstream file;
    // file.open("BinaryTest.txt");

    // file.write((char*)& p, sizeof(person));



    //NASA binChet;
    
    //binChet.saveBinary("BinarnoLetim.bin");
    //binChet.print();

    return 0;
}