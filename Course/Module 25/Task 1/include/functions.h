#pragma once
#include <iostream>

void scalpel(double x_start, double y_start, double x_end, double y_end)
{
    std::cout << "A cut was made from a point (" <<  x_start << ";" << y_start << ") to point (" <<  x_end << ";" << y_end << ")" << std::endl;
}

void hemostat(double x, double y)
{
    std::cout << "The hemostat was placed on the point (" <<  x << ";" << y << ")" << std::endl;
}

void tweezers(double x, double y)
{
    std::cout << "The tweezers was placed on the point (" <<  x << ";" << y << ")" << std::endl;
}

void suture(double x_start, double y_start, double x_end, double y_end)
{
    std::cout << "A suture was applied from a point (" <<  x_start << ";" << y_start << ") to point (" <<  x_end << ";" << y_end << ")" << std::endl;
}

bool comp(double a, double b)
{
    if(a + 0.01 >= b and a - 0.01 <= b)
        return true;
    else
        return false;
}

bool check_end(double x1_start, double y1_start, double x2_start, double y2_start, double x1_end, double y1_end, double x2_end, double y2_end)
{
    bool end = false;
    if (comp(x1_start, x1_end) and comp(y1_start, y1_end) and comp(x2_start, x2_end) and comp(y2_start, y2_end)
        or comp(x2_start, x1_end) and comp(y2_start, y1_end) and comp(x1_start, x2_end) and comp(y1_start, y2_end))
        end = true;
    return end;
}