#include <iostream>
#include <ctime>

int main()
{
    srand(time(0));

    std::cout << "Input size of massive:" << std::endl;
    int x, y;
    std::cin >> x >> y;

    int sum = 0;

    int mass[y][x];
    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
        {
            mass[i][j] = rand() % 7 + 2;
            std::cout << mass[i][j] << " ";
            if (i + j % 2)
                sum += mass[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << sum;
}