#include <iostream>
#include <fstream>
#include <string>

void caugth(std::string &need_fish)
{
    std::ifstream caugth_fish("A:\\Programs\\Projects (c++)\\Course\\Module 20\\Task 3\\caugth_fish.txt");
    std::string fish;
    bool find = false;
    while (!caugth_fish.eof() and !find)
    {
        caugth_fish >> fish;
        if (fish == need_fish)
        {
            find = true;
        }
    }

    caugth_fish.close();

    if (!find)
    {
        std::ofstream caugth_fish("A:\\Programs\\Projects (c++)\\Course\\Module 20\\Task 3\\caugth_fish.txt", std::ios::app);
        caugth_fish << need_fish << "\n";
        caugth_fish.close();
    }
}

void search_fish(std::string &need_fish)
{
    std::ifstream fish_in_river("A:\\Programs\\Projects (c++)\\Course\\Module 20\\Task 3\\fish_in_river.txt");
    bool find = false;
    while (!fish_in_river.eof() and !find)
    {
        std::string fish;
        fish_in_river >> fish;
        if (fish == need_fish)
        {
            find = true;
            caugth(need_fish);
        }
    }
    if (!find)
        std::cout << "This fish is not live in this river!" << std::endl;
    fish_in_river.close();
}

int main()
{
    std::cout << "Input name of fish wich you want to catch:" << std::endl;
    std::string need_fish;
    std::cin >> need_fish;

    search_fish(need_fish);
}