#include <iostream>
#include <ctime>

int main()
{
    int mass[10];
    int count = 0;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        mass[i] = rand() % 10 - 5;
        std::cout << mass[i] << " ";
        if (mass[i] < 0)
            count++;
    }
    std::cout << std::endl << "Count of negative numbers is " << count;
}