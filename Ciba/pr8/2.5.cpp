#include <iostream>
#include <ctime>

int main()
{
    srand(time(0));

    std::cout << "Input size of massive:" << std::endl;
    int x, y;
    std::cin >> x >> y;

    int min = 2147483647, min_i, min_j;

    int mass[y][x];
    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
        {
            mass[i][j] = rand() % 6 + 5;
            std::cout << mass[i][j] << " ";
            if (mass[i][j] < min)
            {
                min = mass[i][j];
                min_i = i;
                min_j = j;
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Minimum element is " << mass[min_i][min_j];
}