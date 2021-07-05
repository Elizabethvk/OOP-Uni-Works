#include "Configuration.h"

#include <fstream>

Configuration* createConfiguration()
{
    Configuration* resultConfig = new Configuration();
    unsigned componentsCnt;

    std::cout << "How many components do you want to enter: ";
    std::cin >> componentsCnt;

    if (componentsCnt > (unsigned)ComponentType::COMPONENT_COUNT) {
        delete resultConfig;
        return nullptr;
    }


    for (size_t i = 0; i < componentsCnt; ++i) {
        Component* newComponent = Utils::createComponent();
        if (newComponent != nullptr) {
            resultConfig->insert(newComponent);
        }
    }

    return resultConfig;
}

int main()
{
    std::vector<Configuration*> configStorage;
    Configuration* myConfig = nullptr;

    char c = 'a';

    std::ofstream out;
    
    Utils::printMenu();
    while(c != 'e') {
        std::cout << "Enter command: ";
        std::cin >> c;

        
        switch (c)
        {
        case 'a':
            try {
                myConfig = createConfiguration();
                configStorage.push_back(myConfig);
            }
            catch(const std::exception& e) {
                std::cerr << e.what() << '\n';
            }
            
            break;
        
        case 'e':
            break;

        case 's':
            out.open("Potok.txt");

            if (!out.is_open()) {
                std::cerr << "Cannot open file\n";
            }

            for (Configuration* config : configStorage) {
                out << *config << '\n';
            }

            out.close();

            break;
        
        case 'h':
            Utils::printMenu();
            break;

        case 'p':
            for (Configuration* config : configStorage) {
                std::cout << *config << '\n';
            }

            break;

        default:
            std::cout << "Unknown command\n";
            Utils::printMenu();
            break;
        }
    }

    for (Configuration* config : configStorage) {
        delete config;
    }

    return 0;
}