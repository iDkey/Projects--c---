#include <iostream>
#include <fstream>
#include <ctime>

int main()
{
    int size_x, size_y;

    std::cout << "Input width of picture:" << std::endl;
    std::cin >> size_x;
    std::cout << "Input height of picture:" << std::endl;
    std::cin >> size_y;
    std::srand(std::time(0));
    int pic[size_y][size_x];
    for (int i = 0; i < size_y; ++i)
    {
        for (int j = 0; j < size_x; ++j)
        {
            pic[i][j] = rand() % 2;
        }
    }

    std::ofstream picture("A:\\Programs\\Projects (c++)\\Course\\Module 20\\Task 2\\pic.txt");
    for (int i = 0; i < size_y; ++i)
    {
        for (int j = 0; j < size_x; ++j)
        {
            picture << pic[i][j] << " ";
        }
        picture << "\n";
    }
}