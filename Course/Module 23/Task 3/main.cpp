#include <iostream>

#define WINTER 0
#define SPRING 0
#define SUMMER 0
#define AUTUMN 1


int main() {
#if WINTER == 1
    std::cout << WINTER << std::endl;
#endif
#if SPRING == 1
    std::cout << SPRING << std::endl;
#endif
#if SUMMER == 1
    std::cout << SUMMER << std::endl;
#endif
#if AUTUMN == 1
    std::cout << AUTUMN << std::endl;
#endif
}


