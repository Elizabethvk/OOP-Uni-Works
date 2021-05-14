#include <fstream>
#include <iostream>
#include <string>


int main()
{
    std::fstream file;
    file.open("main.cpp", std::ios::in);

    std::string all;
    if (file.is_open()) {
        std::string s;

        while(std::getline(file, s)) {
            all += s + '\n';
        }

        file.close();
    }

    file.open("Test.txt", std::ios::in | std::ios::out | std::ios::trunc);

    if (file.is_open()) {
        file << all;

        // std::string str;

        // while(std::getline(file, str)) {
        //     std::cout << str << 'a';
        // }

        // file.close();

        // file.open("Test.txt", std::ios::in);

        std::cout << file.rdbuf();

        file.close();
    }


    return 0;
}