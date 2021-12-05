#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct room_str
{
    std::string room_type;
    int square;
};

struct floor_str
{
    std::vector<room_str> rooms;
    int height;
};

struct building_str
{
    std::string type_of_building;
    int square;
    std::vector<floor_str> flors;
    bool preference_pipe = 0;
    bool preference_bake = 0;
};

struct plot_str
{
    int number;
    std::vector<building_str> buildings;
    double area;
};

int main()
{
    std::vector<plot_str> village;

    room_str room;
    floor_str floor;
    building_str building;
    plot_str plot;

    int cout_areas;
    std::cout << "Imput count of areas in village:" << std::endl;
    std::cin >> cout_areas;

    double sum_area_plots = 0;
    double sum_area_houses = 0;
    for(int i = 0; i < cout_areas; ++i)
    {
        std::cout << "Input count of buildings on area " << i + 1 << std::endl;
        int count_buildings;
        std::cin >> count_buildings;
        std::cout << "Input square of area " << i + 1 << std::endl;
        std::cin >> plot.area;
        sum_area_plots += plot.area;
        std::cout << "Input number of area " << i + 1 << std::endl;
        std::cin >> plot.number;
        for(int j = 0; j < count_buildings; ++j)
        {
            std::cout << "Input count of floors in building " << j + 1 << std::endl;
            int count_floors;
            std::cin >> count_floors;
            std::cout << "Input type of building " << j + 1 << std::endl;
            std::cin >> building.type_of_building;
            std::cout << "Input the square of building " << j + 1 << std::endl;
            std::cin >> building.square;
            sum_area_houses += building.square;
            std::cout << "There is a pipe in the building?" << std::endl;
            std::string ans;
            std::cin >> ans;
            (ans == "Yes" ? building.preference_pipe = true : building.preference_pipe = false);
            std::cout << "There is a bake in the building?" << std::endl;
            std::cin >> ans;
            (ans == "Yes" ? building.preference_bake = true : building.preference_bake = false);
            for(int x = 0; x < count_floors; ++x)
            {
                std::cout << "Input count of rooms on " << x + 1 << " floor" << std::endl;
                int count_rooms;
                std::cin >> count_rooms;
                std::cout << "Input the ceiling height on " << x + 1 << " floor" << std::endl;
                std::cin >> floor.height;
                for(int k = 0; k < count_rooms; k++)
                {
                    std::cout << "Input type of " << k + 1 << " room" << std::endl;
                    std::cin >> room.room_type;
                    std::cout << "Input a square of " << k + 1 << " room" << std::endl;
                    std::cin >> room.square;
                    floor.rooms.push_back(room);
                }
                building.flors.push_back(floor);
            }
            plot.buildings.push_back(building);
        }
        village.push_back(plot);
    }
    std::cout << "Buildings occupy " << sum_area_houses / sum_area_plots * 100 << "% of village"; 
}