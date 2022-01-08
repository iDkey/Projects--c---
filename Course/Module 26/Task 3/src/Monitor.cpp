#include "Monitor.h"
#include <iostream>

void Monitor::clearScreen(Monitor & monitor)
{
    for(auto & i : monitor.screen)
    {
        for(bool & j : i)
        {
            j = false;
        }
    }
}

void Monitor::display(Monitor & monitor, Window & window)
{
    clearScreen(monitor);

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 80; ++j)
        {
            if(i >= window.yPosition and i <= (window.yPosition + window.height)
                    and j >= window.xPosition and j <= (window.xPosition + window.weight))
            {
                screen[i][j] = true;
            }
        }
    }

    for(auto & i : screen)
    {
        for(bool j : i)
        {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}
