#include "ram.h"
#include <iostream>

void write(std::stringstream& data)
{
    int num;
    data.clear();
    for(int i = 0; i < 8; ++i)
    {
        std::cout << "Input a number:" << std::endl;
        std::cin >> num;
        data << num << " ";
    }
}

void read(std::stringstream& data)
{
    std::cout << data.str() << std::endl;
}