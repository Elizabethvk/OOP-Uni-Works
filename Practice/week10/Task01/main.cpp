#include "order.hpp"

int main() {
    List<int> set1;

    // cout << "There are: " << set1.areThereElements() << endl;

    // set1.addElement(2);
    // set1.addElement(3);

    // cout << "Elements: " << endl;
    // set1.print();

    // cout << "Size: " << set1.getSize() << endl;

    // set1.removeElement(2);
    // cout << "Elements: " << endl;
    // set1.print();

    // cout << "Element 1: " << set1.getElement(0) << endl;

    // set1.save("fileInput.txt");

    set1.read("fileInput.txt");

    set1.print();

    cout << "Size: " << set1.getSize() << endl;

    return 0;
}