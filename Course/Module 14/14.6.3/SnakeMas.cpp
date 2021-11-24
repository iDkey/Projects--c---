#include <iostream>

int main()
{
    int x = 0;
    int mass[5][5];
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mass[i][j] = x;
            x++;
        }
    }
    
    for (int i = 0; i < 4; i+=2)
    {
            for (int j = 0; j < 5; j++)
            {
                std::cout << mass[i][j] << " ";
            }
            std::cout << std::endl;
            for (int j = 4; j >= 0; j--)
            {
                std::cout << mass[i+1][j] << " ";
            }
            std::cout << std::endl;
    }
    for (int j = 0; j < 5; j++)
    {
        std::cout << mass[4][j] << " ";
    }
}
