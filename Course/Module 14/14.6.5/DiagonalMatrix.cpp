#include <iostream>

int main()
{
    int matrix[4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j)
                matrix[i][j] = 0;
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}