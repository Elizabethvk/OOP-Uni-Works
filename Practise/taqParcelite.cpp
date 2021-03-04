#include <iostream>
using std::cin;
using std::cout;
using std::nothrow;
using std::endl;

unsigned** iskamPamet(unsigned n, unsigned m){
    unsigned** matrix = new(nothrow) unsigned*[m];
    if(!matrix) return matrix;

    for(unsigned i = 0; i < m; i++){
        matrix[i] = new(nothrow) unsigned[n];
        if(!matrix[i]){
            
        }
    }
}

int main(){
    unsigned n=0, m=0;
    cin >> n >> m;

    unsigned** snimka = 0;
    snimka = iskamPamet(n,m);



    for(unsigned i = 0; i < m; i++){
        delete[][i] snimka; 
    }
    delete[] snimka;
    return 0;
}