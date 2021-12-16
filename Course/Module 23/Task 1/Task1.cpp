#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7
#define DAY(day_name) #day_name

int main()
{
    int day_number;
    std::cout << "Include day's number:" << std::endl;
    std::cin >> day_number;
    if(day_number == MONDAY)
    {
        std::cout << DAY(MONDAY);
    }
    if(day_number == TUESDAY)
    {
        std::cout << DAY(TUESDAY);
    }
    if(day_number == WEDNESDAY)
    {
        std::cout << DAY(WEDNESDAY);
    }
    if(day_number == THURSDAY)
    {
        std::cout << DAY(THURSDAY);
    }
    if(day_number == FRIDAY)
    {
        std::cout << DAY(FRIDAY);
    }
    if(day_number == SATURDAY)
    {
        std::cout << DAY(SATURDAY);
    }
    if(day_number == SUNDAY)
    {
        std::cout << DAY(SUNDAY);
    }
}