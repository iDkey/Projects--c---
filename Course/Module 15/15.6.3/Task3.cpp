#include <iostream>
#include <vector>

std::vector<int> sorting(std::vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            if (vec[j] > vec[j + 1])
                std::swap(vec[j],vec[j + 1]);
        }
    }
    return vec;
}

int main()
{
    std::vector<int> vec;
    int num = 2147483647;
    int i = 0;
    int count = 0;
    while (num != -2)
    {
        if (num == -1)
        {
            if (vec.size() < 5)
                std::cout << vec[vec.size() - 2] << std::endl;
            else
                std::cout << vec[4] << std::endl;
        }
        else
        {
            vec = sorting(vec);
            if (count < 5)
                vec.push_back(num);
            else
            {
                if (num < vec[vec.size() - 1])
                {
                    vec.resize(4);
                    vec.push_back(num);
                }
            }
            vec = sorting(vec);
            count++;
        }
        std::cout <<"Input next number:" << std::endl;
        std::cin >> num;
    }
}