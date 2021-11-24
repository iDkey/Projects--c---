#include <iostream>

void swap_mas(int* mas)
{
    for (int i = 0; i < 5; ++i)
    {
        std::swap(*(mas + i), *(mas + 9 - i));
    }
    for (int i = 0; i < 10; ++i)
    {
        std::cout << *(mas + i) << " ";
    }
}

int main()
{
    int mas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    swap_mas(mas);
}