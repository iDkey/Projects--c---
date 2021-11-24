#include <iostream>

int r_function(int num_step, int max_step = 3)
{
    if (num_step <= max_step)
    {
        int x = 1;
        for (int i = 1; i < num_step; ++i)
            x *= 2;
        return x;
    }
    if (num_step > max_step)
    {
        int count = 0;
        for (int i = 0; i < max_step; ++i)
        {
            count += r_function(num_step - max_step + i, max_step);
        }
        return count;
    }
    else
    {
        std::cout << "Wrong number of step. Try again!";
        return -1;
    }
}

int main()
{
    int num_step = 5;
    int max_step = 4;
    std::cout << r_function(num_step,max_step);

    //smth wrong with test num_step = 3; max_step = 2; real answer: 6 program answer: 5
}