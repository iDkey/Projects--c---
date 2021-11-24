#include <iostream>

void output(bool field[][12])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            std::cout << (field[i][j] ? "o" : "x");
        }
        std::cout << std::endl;
    }
}

void start(bool field[][12])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            field[i][j] = true;
        }
    }
}

bool condition(bool field[][12])
{
    bool ok = false;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (field[i][j])
            {
                ok = true;
                break;
            }
        }
    }
    return ok;
}

bool check(int x0, int y0, int x1, int y1)
{
    bool ok = false;
    if (x0 >= 1 and x0 <= 12 and y0 >= 1 and y0 <= 12 and x1 >= 1 and x1 <= 12 and y1 >= 1 and y1 <= 12)
        ok = true;
    else
        {
            std::cout << "Wrong data! Try again." << std::endl;
        }
    return ok;
}

void pop(bool field[][12], int x0, int y0, int x1, int y1)
{
    int count = 0;
    if (x0 < x1)
    {
        if (y0 < y1)
        {
           for (int i = y0 - 1; i < y1; i++) // 1
            {
                for (int j = x0 - 1; j < x1; j++)
                {
                    if (field[i][j])
                    {
                        field[i][j] = false;
                        //std::cout << "Pop!" << std::endl;
                        count++;
                    }
                }
            } 
        }
        else
        {
            for (int i = y0 - 1; i > y1 - 2; i--) // 3
            {
                for (int j = x0 - 1; j < x1; j++)
                {
                    if (field[i][j])
                    {
                        field[i][j] = false;
                        //std::cout << "Pop!" << std::endl;
                        count++;
                    }
                }
            }
        }
    }
    else
        if (y0 < y1)
        {
           for (int i = y0 - 1; i < y1; i++) // 2
            {
                for (int j = x0 - 1; j > x1 - 2; j--)
                {
                    if (field[i][j])
                    {
                        field[i][j] = false;
                        //std::cout << "Pop!" << std::endl;
                        count++;
                    }
                }
            } 
        }
        else
        {
            for (int i = y0 - 1; i > y1 - 2; i--) // 4
            {
                for (int j = x0 - 1; j > x1 - 2; j--)
                {
                    if (field[i][j])
                    {
                        field[i][j] = false;
                        //std::cout << "Pop!" << std::endl;
                        count++;
                    }
                }
            }
        }
    std::cout << "Pop! x" << count << std::endl;
}

int main()
{
    bool field[12][12];

    start(field);

    output(field);

    while (condition(field))
    {
        std::cout << "Input coordinate first point: " << std::endl;
        int x0, y0;
        std::cin >> x0 >> y0;
        std::cout << "Input coordinate second point: " << std::endl;
        int x1, y1;
        std::cin >> x1 >> y1;
        if (check(x0, y0, x1, y1))
        {
            pop(field, x0, y0, x1, y1);

            output(field);
        }
    }
}