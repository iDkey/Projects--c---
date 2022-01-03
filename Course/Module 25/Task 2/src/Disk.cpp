#include "disk.h"
#include <fstream>
#include <iostream>

void save(std::stringstream& data)
{
    std::ofstream file;
    file.open("A:\\Programs\\Projects(c++)\\Course\\Module 25\\Task 2\\data.txt");
    int plug;
    for(int i = 0; i < 8; i++)
    {
        data >> plug;
        file << plug << " ";
    }
    file.close();
}

void load(std::stringstream& data)
{
    std::ifstream file;
    file.open("A:\\Programs\\Projects(c++)\\Course\\Module 25\\Task 2\\data.txt");
    if(file.is_open())
    {
        int plug;
        for(int i = 0; i < 8; i++)
        {
            file >> plug;
            data << plug << " ";
        }
        file.close();
        std::cout << data.str() << " was loaded from the file" << std::endl;
    }
    else
    {
        std::cout << "No save files. Try to save some data before loading it." << std::endl;
    }
}