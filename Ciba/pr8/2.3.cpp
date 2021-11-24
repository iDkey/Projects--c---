#include <iostream>
#include <ctime>

int main()
{
    int mass[10];
    int sum = 0;

    srand(time(0));

    std::cout << "Input position whick should be replace: " << std::endl;
    int pos;
    std::cin >> pos;

    for (int i = 0; i < 10; i++)
    {
        mass[i] = rand() % 5 + 2;
        std::cout << mass[i] << " ";
        if (i == pos - 1)
        mass[i] = 0;
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << mass[i] << " ";
    }
}