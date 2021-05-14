#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;


class B {
public:
    B() {
        cout<<"B in process\n";
        throw -1;
    }
    B(int i){
        cout<<"Bi\n";
        throw -2;
    }
};

class A{
    public: 
   // A()=delete;
    A(const B& b) {
        std::cout<<"A created\n";
    }
};

int main(){
    try{
        cout<<"Tryying\n";
        //B b;
        
        A a(B());
        //A aa(B(10));
      }
    catch(int i){
        cout<<"i="<<i<<endl;
    }
  
}