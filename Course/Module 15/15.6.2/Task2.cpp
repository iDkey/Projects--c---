#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1, 4, 5, 4, 15};
    int sum = 8;
    
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 1; j < vec.size(); j++)
        {
            if (vec[i] + vec[j] == sum and i != j)
                {
                    std::cout << vec[i] << " and " << vec[j];
                    return 0;
                }
        }
    }
}