#include <iostream>

#define MACRO(func) for(int i = 0; i < 10; i++) func(train[i], i);
#define MACRO_SUMM(func) for(int i = 0; i < 10; i++) func(train[i], summ);

void more(int count, int i)
{
    if(count > 20) std::cout << "More" << std::endl;
}

void less(int count, int i)
{
    if(count < 20) std::cout << "Less" << std::endl;
}

void filling(int& count, int i)
{
    std::cout << "Input count of passengers in " << i + 1 << " train car:" << std::endl;
    std::cin >> count;
}

void summ_count(int count, int& summ)
{
    summ += count;
}

int main()
{
    int train[10];
    int summ = 0;
    std::cout << "Input count passengers in train:" << std::endl;
    MACRO(filling);
    MACRO(more);
    MACRO(less);
    MACRO_SUMM(summ_count);
    std::cout << summ << " passengers in train" << std::endl;
}

