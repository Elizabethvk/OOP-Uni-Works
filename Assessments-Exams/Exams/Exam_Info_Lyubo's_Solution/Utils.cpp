#include "Utils.h"


const std::string Utils::components[] = {"CPU", "Memory"};

Component* Utils::createComponent()
{
    std::cout << "Choose option from the list below:\n";
    for (size_t i = 0; i < (size_t)ComponentType::COMPONENT_COUNT; ++i) {
        std::cout << i << ' ' << components[i] << '\n';
    }

    int choice;
    std::cin >> choice;

    unsigned short cores, clockSpeed, capacity;
    Component* result = nullptr;

    switch ((ComponentType)choice)
    {
    case ComponentType::CPU:
        std::cout << "Enter number of cores: ";
        std::cin >> cores;
        std::cout << "Enter the clockSpeed: ";
        std::cin >> clockSpeed;


        try {
            result = new Cpu(cores, clockSpeed);
        }
        catch(const std::out_of_range& e) {
            delete result;
            result = nullptr;
        }
        
        break;
    case ComponentType::MEMORY:
        std::cout << "Enter capacity of the memory: ";
        std::cin >> capacity;

        try {
            result = new Memory(capacity);
        }
        catch(const std::out_of_range& e) {
            delete result;
            result = nullptr;
        }

        break;
    
    default:
        return nullptr;
    }

    return result;
}


void Utils::printMenu()
{
    std::cout << "a - Add new configuration\n" <<
                 "s - Save your configuration\n" <<
                 "p - Print your configuration\n" <<
                 "h - Help/Prints this menu again\n" <<
                 "e - Exits\n";
}