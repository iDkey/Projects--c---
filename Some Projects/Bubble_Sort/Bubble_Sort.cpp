#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {7, 1, 5, 4, 6, -20, 100, 5, 3};

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            if (vec[j] > vec[j + 1])
                std::swap(vec[j],vec[j + 1]);
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
}