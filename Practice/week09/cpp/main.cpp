#include "../hpp/facultymember.hpp"



int main() {
    ifstream in("FacultyMembers.txt");
    ofstream out("FacultyMembers.txt");

    cout << "Name: " << endl;
    string userName;
    getline(cin, userName);

    cout << "Number: " << endl;
    string userNumber;
    getline(cin, userNumber);

    cout << "Salary: " << endl;
    double userSalary;
    cin >> userSalary;

    FacultyMember userPerson(userName, userNumber, userSalary);
    


    //in >> userPerson;

    //Person test("Drago");
    //test.getName();

    FacultyMember someone("Blago", "12345", 1234.5);
    someone.printInfo();

    someone.writeInFile("Faculty.txt");

    someone.loadFromFile("Faculty.txt");

    


    return 0;
}