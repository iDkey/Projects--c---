#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {7, 1, 5, 4, 6, -20, 100, 5, 3};

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        int maxind = 0;
        for (int j = 0; j <= i; j++)
        {
            if (vec[j] > vec[maxind])
                maxind = j;
        }
        int temp = vec[i];
        vec[i] = vec[maxind];
        vec[maxind] = temp;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
}