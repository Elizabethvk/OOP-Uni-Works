#include <iostream>
#include <string>
#include <fstream>


int main() {
    std::string defaultFile = "Database.txt";
    std::ifstream defaultInput(defaultFile);

    if (!defaultInput.is_open()) {
        std::cout << "The file you've input " << defaultFile << " failed to open! :(" << std::endl
                << "Data base wasn't loaded." << std::endl;
    }
    else {
        std::cout << "Loading the data from the file." << std::endl;
        std::string argument;
        int i = 0;
        // while(!defaultInput.eof()) {
        while (getline(defaultInput, argument)) { 
            // getline(defaultInput, argument);
            std::cout << i << " # " << argument << std::endl;
            //newInteract.userPreference(argument);
            ++i;
            // if (argument.empty()) {
            //     // return 0;
            //     break;
            // }
        }
        std::cout << "Loaded the data from the file with name " << defaultFile << std::endl;
    }



    
    return 0;
}