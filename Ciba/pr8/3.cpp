#include <iostream>

int main()
{
    int mass[2][5] = {{2,4,5,5,4},
                      {5,5,5,3,2}};
    
    /*for (int i = 0; i < 2; i++)
    {
        if (i == 0)
            std::cout << "Input marks for chemistry:" << std::endl;
        else
            std::cout << "Input marks for computer science:" << std::endl;
        for (int j = 0; j < 5; j++)
        {
            std::cin >> mass[i][j];
        }
    }*/
    for (int j = 0; j < 5; j++)
    {
        if (mass[0][j] == 5 and mass[1][j] == 5)
            std::cout << "Student number " << j + 1 << " is excellent student" << std::endl;
    }
}