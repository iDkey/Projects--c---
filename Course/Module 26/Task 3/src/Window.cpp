#include "Window.h"
#include <iostream>

void Window::firstWindow(Window& window) {
    window.xPosition = 0;
    window.yPosition = 0;
    window.height = 25;
    window.weight = 40;
}

void Window::move(Window & window)
{
    int newPositionX;
    int newPositionY;
    std::cout << "newPositionX" << std::endl;
    std::cin >> newPositionX;
    std::cout << "newPositionY" << std::endl;
    std::cin >> newPositionY;
    if(newPositionX > 0)
    {
        if(newPositionX + xPosition + weight > 80)
        {
            xPosition = 80 - weight;
        }
        else
        {
            xPosition += newPositionX;
        }
    }
    else
    {
        if(newPositionX + xPosition < 0)
        {
            xPosition = 0;
        }
        else
        {
            xPosition += newPositionX;
        }
    }

    if(newPositionY > 0)
    {
        if(newPositionY + yPosition + height > 50)
        {
            yPosition = 50 - height;
        }
        else
        {
            yPosition += newPositionY;
        }
    }
    else
    {
        if(newPositionY + yPosition < 0)
        {
            yPosition = 0;
        }
        else
        {
            yPosition += newPositionY;
        }
    }
}

void Window::resize(Window & window)
{
    int newHeight;
    int newWeight;
    std::cout << "newHeight" << std::endl;
    std::cin >> newHeight;
    std::cout << "newWeight" << std::endl;
    std::cin >> newWeight;
    if(newHeight > 0 and newHeight <= 50 and newWeight > 0 and newWeight <= 80)
    {
        window.height = newHeight;
        window.weight = newWeight;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}
