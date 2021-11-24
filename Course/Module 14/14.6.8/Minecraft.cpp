#include <iostream>

int get_height()
{
    int height;
    while(1)
    {
        std::cout << "Input  height of block:" << std::endl;
        std::cin >> height;
        if (height >= 0 and height <= 10)
            break;
        else
            std::cout << "Wrong data. Try again" << std::endl;
    }
    return height;
}

void output(bool mass[][5][10], int level)
{
    std::cout << "Level " << level + 1 << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << mass[i][j][level] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    bool mass[5][5][10];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int height = get_height();
            for (int k = 0; k < 10; k++)
            {
                if (k < height)
                    mass[i][j][k] = 1;
                else
                    mass[i][j][k] = 0;
            }
        }
    }

    int level = 0;
    for (int i = 0; i < 10; i++, level++)
    {
        output(mass, level);
    }
}