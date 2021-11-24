#include <iostream>

int main()
{
    int matrix1[4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    int matrix2[4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};

    /*std::cout << "Input first matrix:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cin >> matrix1[i][j];
        }
    }
    std::cout << "Input second matrix:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cin >> matrix2[i][j];
        }
    }*/

    bool equality = true;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
                equality = false;
                break;
            }
        }
    }
    if (equality)
        std::cout << "Matrix are equal" << std::endl;
    else
        std::cout << "Matrix are not equal" << std::endl;
}