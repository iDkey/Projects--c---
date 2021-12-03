#include<iostream>
#include<string>
#include <random>
#include <ctime>


int main()
{
    std::mt19937 gen(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<> rand_x(1,10);
    int x = rand_x(gen);
    std::cout << x;
} 