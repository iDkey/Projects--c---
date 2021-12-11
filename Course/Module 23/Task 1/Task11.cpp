#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

int main()
{
    int day_number;
    std::cout << "Include day's number:" << std::endl;
    std::cin >> day_number;
    if(day_number == MONDAY)
    {
        std::cout << "Monday" << std::endl;
    }
    if(day_number == TUESDAY)
    {
        std::cout << "Tuesday" << std::endl;
    }
    if(day_number == WEDNESDAY)
    {
        std::cout << "Wednesday" << std::endl;
    }
    if(day_number == THURSDAY)
    {
        std::cout << "Thursday" << std::endl;
    }
    if(day_number == FRIDAY)
    {
        std::cout << "Friday" << std::endl;
    }
    if(day_number == SATURDAY)
    {
        std::cout << "Saturday" << std::endl;
    }
    if(day_number == SUNDAY)
    {
        std::cout << "Sunday" << std::endl;
    }
}