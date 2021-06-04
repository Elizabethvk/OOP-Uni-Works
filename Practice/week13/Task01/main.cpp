#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator> // Iterators

using std::cout; 
using std::cin; 
using std::endl;
using std::string; 
using std::vector;


int main() {
    vector<int> numbers;

    vector<int>::iterator itVec;

    cout << "5 ints -> " << endl;

    int n = 0;

    for(unsigned int i = 0; i < 5; ++i) {
        cin >> n;
        numbers.push_back(n);

    }

    cout << "What we got: " << endl;

    for (itVec = numbers.begin(); itVec < numbers.end(); ++itVec) {
        cout << *itVec << " ";
    }

    cout << endl;

    return 0;
}