#include <iostream>

int r_function(int num_step)
{
    if (num_step == 1)
    {
        return 1;
    }
    if (num_step == 2)
    {
        return 2;
    }
    if (num_step == 3)
    {
        return 4;
    }
    if (num_step > 3)
        return r_function(num_step - 1) + r_function(num_step - 2) + r_function(num_step - 3);
    else
    {
        std::cout << "Wrong number of step. Try again!";
        return -1;
    }
}

int main()
{
    int num_step = 4;
    
    std::cout << r_function(num_step);
}