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
            if(i >= window.getYPosition() and i <= (window.getYPosition() + window.getHeight())
                    and j >= window.getXPosition() and j <= (window.getXPosition() + window.getWeight()))
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
