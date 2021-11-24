#include <iostream>

int main()
{
    float matrix[4][4] ={{1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 10, 11, 12},
                         {13, 14, 15, 16}};
    float vector[4] = {1, 2, 3, 4};
    float result[4];

    /*
    std::cout << "Input vector:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cin >> result[i];
    }*/

    std::cout << "Input matrix:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            //std::cin >> matrix[i][j];
            matrix[i][j] *= vector[j];
        }
        result[i] = matrix[i][0] + matrix[i][1] + matrix[i][2] + matrix[i][3];
    }
    
    std::cout << "Result of multiplication:" << std::endl;
    for(int i = 0; i < 4; i++)
    {
            std::cout << result[i] << " ";
    }
}