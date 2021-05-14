#include "../hpp/facultymember.hpp"

FacultyMember::FacultyMember(string name, string number, double salary) 
    : Person(name), Student(name, number), Lecturer(name, salary)
{
}

void FacultyMember::setFacultyMember() {
    cout << "Name: " << endl;
    string userName;
    getline(cin, userName);

    cout << "Number: " << endl;
    string userNumber;
    getline(cin, userNumber);

    cout << "Salary: " << endl;
    double userSalary;
    cin >> userSalary;

    //Person(userName);

}

void FacultyMember::printInfo() {
    cout << "Name: " << getName() << endl;
    //Person::getName();

    cout << "Number: " << getNumber() << endl;;
    //Student::getNumber();

    //Student::getInfoStud();

    cout << "Salary: "  << getSalary() << endl;;
    //Lecturer::getSalary();
}

FacultyMember FacultyMember::loadFromFile(string filename) {
    string name;
    string number;
    double salary;

    ifstream in(filename);
    if(in.is_open()){
        in >> name;
        in >> number;
        in >> salary;

    }
    in.close();
    return FacultyMember(name, number, salary);
}

void FacultyMember::writeInFile(string filename) {
    //ofstream out(filename);
    ofstream file;
    file.open(filename);
    file << Person::getName() << " " << Student::getNumber() << " " << Lecturer::getSalary() << endl;
    //file << *this;

    file.close();
}
