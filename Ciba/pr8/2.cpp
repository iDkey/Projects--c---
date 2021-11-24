#include <iostream>

int main()
{
    int matrix[3][3] = {{1, 3, 7},
                        {3, 9, 6},
                        {4, 1, 8}};
    int sumUp = 0, sumDown = 0, maxInDiagonal = 0, pos;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //std::cout << "Input element of matrix:" << std::endl;
            //std::cin >> matrix[i][j];
            if (i < j)
                sumUp += matrix[i][j];
            if (i > j)
                sumDown += matrix[i][j];
            if (i == j and matrix[i][j] > maxInDiagonal)
            {
                pos = i;
                maxInDiagonal = matrix[i][j];
            }
        }
    }

    if (sumUp > sumDown)
        matrix[pos][pos] = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}