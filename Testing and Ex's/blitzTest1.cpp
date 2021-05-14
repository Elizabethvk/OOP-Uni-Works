#include <iostream>
#include <cstdint>

int main() {

    struct Test {
        std::uint8_t a;
        std::uint32_t b;

        struct{
            std::uint32_t c;
            std::uint16_t d;
        };
        
    };

    std::uint8_t as;
    std::uint32_t bs;
    std::uint16_t ds;
    std::cout << sizeof(as) << std::endl;
    std::cout << sizeof(bs) << std::endl;
    std::cout << sizeof(ds) << std::endl;


    std::cout << sizeof(Test) << std::endl;
    //std::cout << sizeof(Anonstr) << std::endl;


    return 0;
}