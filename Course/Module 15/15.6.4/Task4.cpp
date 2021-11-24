#include <iostream>
#include <vector>

std::vector<int> sorting(std::vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            if (abs(vec[j]) > abs(vec[j + 1]))
                std::swap(vec[j],vec[j + 1]);
        }
    }
    return vec;
}

int main()
{
    std::vector<int> vec = {-100,-50, -5, 1, 10, 15};

    vec = sorting(vec);

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
}