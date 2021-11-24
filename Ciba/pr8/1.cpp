#include <iostream>

int main()
{
    int size;
    std::cout << "Input massive size:" << std::endl;
    std::cin >> size;

    int min = 2147483647;

    int mass[size];
    for (int i = 0; i < size; i++)
    {
        std::cin >> mass[i];
        if (mass[i] < min)
            min = mass[i];
    }

    std::cout << "Minimum element of mass is " << min;
}