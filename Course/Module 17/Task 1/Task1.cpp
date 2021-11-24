#include <iostream>

void swap(int* pa, int* pb)
{
    std::swap(*pa, *pb);
    std::cout << *pa << " " << *pb;
}

int main()
{
    int a = 10;
    int b = 20;

    int* pa = &a;
    int* pb = &b;
    swap(pa, pb);
}