#include <iostream>

void filling(int (&train)[10])
{
    for(int i = 0; i < 10; ++i)
    {
        std::cout << i + 1 << " train car:" << std::endl;
        std::cin >> train[i];
    }
}

int main()
{
    int train[10];
    int summ = 0;
    std::cout << "Input count in train:" << std::endl;
    filling(train);

}