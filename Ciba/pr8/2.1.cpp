#include <iostream>
#include <ctime>

int main()
{
    int mass[10];
    int sum = 0;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        mass[i] = rand() % 5;
        std::cout << mass[i] << " ";
        sum += mass[i];
    }
    std::cout << std::endl << "Summ is " << sum;
}