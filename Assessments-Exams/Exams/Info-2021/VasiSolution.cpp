#define _CRT_SECURE_NO_WARNINGS 

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::ostream;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Component
{
private:
    string label;

public:
    Component(const char* label);
    Component(const Component& other) = delete;

    Component& operator=(const Component& other) = delete;

    virtual double price() const = 0;
    void output(std::ostream& out) const;

    const char* getLabel();
};

Component::Component(const char* label) 
    : label(label)
{}

void Component::output(std::ostream& out) const
{
    out << label << " " << price() << "\n";
}

const char* Component::getLabel()
{
    return label.c_str();
}

class Cpu : public Component
{
private:
    const double PRICE_OF_CORE = 29.99;
    const int CORES_MAX_CNT = 8;
    unsigned short cores;
    unsigned short clockSpeed;

public:
    Cpu(unsigned short cores, unsigned short clockSpeed);
    Cpu(const Cpu& other) = delete;

    Cpu& operator=(const Cpu& other) = delete;

    double price() const override;

    unsigned short getCores();
    unsigned short getClockSpeed();
};

Cpu::Cpu(unsigned short cores, unsigned short clockSpeed)
    : Component("cpu"), cores(cores), clockSpeed(clockSpeed)
{
    if(cores < 1 || cores > CORES_MAX_CNT)
    {
        throw std::invalid_argument("Invalid cores count!");
    }
}

double Cpu::price() const
{
    return cores * PRICE_OF_CORE;
}

unsigned short Cpu::getCores()
{
    return cores;
}
unsigned short Cpu::getClockSpeed()
{
    return clockSpeed;
}


class Memory : public Component
{
private:
    const double PRICE_PER_GB = 89.99;
    const int MAX_CAPACITY = 10000;

    unsigned short capacity;

public:
    Memory(unsigned short capacity);
    Memory(const Memory& other) = delete;

    Memory& operator=(const Memory& other) = delete;

    double price() const override;

    unsigned short getCapacity();
};

Memory::Memory(unsigned short capacity)
    : Component("memory"), capacity(capacity)
{
    if(capacity < 1 || capacity > MAX_CAPACITY)
    {
        throw std::invalid_argument("Invalid capacity!");
    }
}

double Memory::price() const
{
    return capacity * PRICE_PER_GB;
}

unsigned short Memory::getCapacity()
{
    return capacity;
}

class ComponentFactory
{
private:
    enum ComponentTypes
    {
        cpu,
        memory
    };
    
    static Component* create_cpu_component();
    static Component* create_memory_component();

public:
    static unsigned short readNumber(const char* message);
    static Component* create_component();
};

Component* ComponentFactory::create_component()
{
    string input;

    cout << "Enter component type: ";
    cin >> input;
    
    if(input.compare("cpu") == 0)
    {
        return create_cpu_component();
    }
    else if(input.compare("memory") == 0)
    {
        return create_memory_component();
    }

    return nullptr;
}

unsigned short ComponentFactory::readNumber(const char* message)
{
    unsigned short number = 0;

    while(!number)
    {
        cout<<message;
        cin >> number;
        if(!cin)
        {
            number = 0;
            cin.clear();
            cout<<"Invalid input. Try again.\n";
        }
        else
        {
            break;
        }
    }
    return number;
}

Component* ComponentFactory::create_cpu_component()
{
    unsigned short cores, clockSpeed;

    cores = readNumber("Enter cores: ");
    clockSpeed = readNumber("Enter clockSpeed: ");

    try
    {
        return new Cpu(cores, clockSpeed);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        return nullptr;
    }
}
Component* ComponentFactory::create_memory_component()
{
    unsigned short capacity;

    capacity = readNumber("Enter capacity: ");
    try
    {
        return new Memory(capacity);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return nullptr;
    }
    
}


class Configuration
{
private:
    vector<const Component*> components;
    Configuration();

    void insert(const Component* c);
    friend Configuration* create_configuration();
public:
    Configuration(const Configuration& other) = delete;
    Configuration& operator=(const Configuration& other) = delete;
    ~Configuration();

    const Component& operator[](size_t index);
    friend ostream& operator<<(ostream& out, const Configuration& config);

    double price() const;
    std::size_t size() const;
};

Configuration::Configuration()
{}

void Configuration::insert(const Component* c)
{
    for (size_t i = 0; i < components.size(); i++)
    {
        if(strcmp(typeid(*components[i]).name(), typeid(*c).name()) == 0)
        {
            throw std::invalid_argument("This component is already added!");
        }
    }
    components.push_back(c);
}
Configuration::~Configuration()
{
    for (size_t i = 0; i < components.size(); i++)
    {
        delete components[i];
        components[i] = nullptr;
    }
}

const Component& Configuration::operator[](size_t index)
{
    if(index >= components.size())
    {
        throw std::out_of_range("Index is out of range!");
    }
    return *components[index];
}
ostream& operator<<(ostream& out, const Configuration& config)
{
    for (size_t i = 0; i < config.components.size(); i++)
    {
        config.components[i]->output(out);
    }
    out<<"Configuration price: "<<config.price()<<endl;

    return out;
}

double Configuration::price() const
{
    double result = 0;
    for (size_t i = 0; i < components.size(); i++)
    {
        result+= components[i]->price();
    }
    return result;
}
std::size_t Configuration::size() const
{
    return components.size();
}


Configuration* create_configuration()
{
    Configuration* config = new Configuration();
    unsigned short components_cnt = ComponentFactory::readNumber("Enter components cnt for the new configuration: ");
    try
    {
        while(components_cnt > 0)
        {
            config->insert(ComponentFactory::create_component());
            --components_cnt;
        }
    }
    catch(const std::exception& e)
    {
        return nullptr;
    }
    
    return config;
}


int main()
{
    Configuration* config = create_configuration();
    if(config == nullptr)
    {
        cout<<"Unexpected error! Configuration wasn't created!\n";
        return 1;
    }

    cout<<*config;

    cout<<"Enter name of the file in which to save the configuration: ";
    string input;
    cin>>input;

    std::fstream file(input, std::ios::out);

    file<<*config;

    file.close();

    delete config;
	return 0;
}