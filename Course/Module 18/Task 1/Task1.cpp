#include <iostream>
#include <vector>

void swapvec(std::vector<int>& vec, int* mas)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::swap(vec[i], *(mas + i));
    }
}

int main()
{
    std::vector<int> vec = {1,2,3,4};
    int mas[] = {2,4,6,8};

    swapvec(vec, mas);

    for(int i = 0; i < 4; ++i)
        std::cout << vec[i];

    std::cout << std::endl;

    for(int i = 0; i < 4; ++i)
        std::cout << mas[i];
}