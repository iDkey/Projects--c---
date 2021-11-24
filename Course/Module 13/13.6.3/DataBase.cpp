#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec(20);
    int next = 1;
    int i = 0;
    for (i; next != -2; i++)
    {
        if (next == -1)
        {
            if (i != 0)
            {
                for (int j = i; j < vec.size(); j++)
                {
                    std::cout << vec[j] << "  ";
                }
                for (int j = 0; j < i; j++)
                {
                    std::cout << vec[j] << "  ";
                }
                
            }
            else
            {
                for (int j = i; j < vec.size(); j++)
                    std::cout << vec[i] << "  ";
            }
            i--;
        }
        else
            if (i > vec.size() - 1)
            {
                i = 0;
                vec[i] = next;
            }
            else
            {
                vec[i] = next;
            }
        std::cout << "Input: ";
        std::cin >> next;
    }
}
