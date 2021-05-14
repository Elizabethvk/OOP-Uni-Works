#include "space.hpp"
#include <cstring>

int main() {
    NASA cheti;
    cheti.readFile("Leti.txt");
    cheti.print();
   // std::cout<<"Size of string:"<<sizeof(string)<<std::endl;
    cout << "---------" << endl;

    cheti.saveBinary("BinarnoLet.txt");

   /* struct person {
        char name[30];
        int age;
    };

    person p;
    strcpy(p.name, "Some Name");

    p.age = 10;
    
    std::ofstream file;
    file.open("BinaryTest.txt", std::ios::binary);
    if(!file.is_open())
    {
        std::cout<<"File not opened BinaryTest.txt\n";
        return -1;
    }
    
  //  char a[10]="Hi";
    file.write((const char*)& p, sizeof(person));
    //file.write((const char*)& a, sizeof(a));
    std::cout<<"size of person "<<sizeof(person)<<" adress "<<& p<<std::endl;
    std::cout<<"------\nPerson name:"<<p.name<<" age:"<<p.age<<std::endl;
    file.close();
    std::ifstream file2;
    file2.open("BinaryTest.txt", std::ios::binary);
    if(!file2.is_open())
    {
        std::cout<<"File not opened BinaryTest.txt 2\n";
        return -1;
    }
    person snd={"Hi",100};
    file2.read((char*)&snd,sizeof(person));
    
    std::cout<<"Person:\n Name"<<snd.name<<"\nAge:"<<snd.age<<"\n";
    file2.close();
    //NASA binChet;
    
    //binChet.saveBinary("BinarnoLetim.bin");
    //binChet.print();
    */


   std::fstream file;
   file.open("BinarnoLet.txt" , std::ios::in | std::ios::out | std::ios::binary);
   Poleti polet(1,"");
   while(!file.eof()){
   file.read((char*)&polet,sizeof(Poleti));
   //file.seekg(std::ios::beg,sizeof(Poleti));
   std::cout<<"\nRead first polet:\n";
   std::cout<<polet.getYear()<<" "<<polet.getName()<<std::endl;
   }
    file.close();


    return 0;
}