#include <iostream>
#include <fstream>
#include <string>

struct area
{
    int unic_num = 0;
    int count_of_buildings = 0;
};

struct buildings_str
{
    std::string type_of_building;
    int square;
    int count_of_floors = 1;
    bool preference_pipe = 0;
    bool preference_bake = 0;
};

struct floor_str
{
    int count_of_rooms = 2;
    struct room_str
    {
        std::string type_of_room;
        int square;
    };
    int height;
};

int main()
{
    int count_of_areas;
    std::cout << "Imput count of areas in township:" << std::endl;
    std::cin >> count_of_areas;

    
}