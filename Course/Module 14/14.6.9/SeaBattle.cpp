#include <iostream>

int winner;

void output()
{
    if (winner == 1)
        std::cout << "First player winer";
    if (winner == 2)
        std::cout << "Secind player winer";
}

void clear(bool field[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            field[i][j] = false;
        }
    }
}

bool check_coordinates(int x1,int x2,int y1,int y2, bool field[][10], int size)
{
    bool ok = false;
    if (x1 >= 0 and x1 <= 9 and x2 >= 0 and x2 <= 9 and y1 >= 0 and y1 <=9 and y2 >= 0 and y2 <=9)
    {
        if (x1 == x2)
        {
            if (y1 <= y2 and abs(y2 - y1) == size - 1)
            {
                for (int i = y1; i <= y2; i++)
                {
                    if (field[i][x1] == true)
                    {
                        ok = false;
                        break;
                    }   
                    else
                        ok = true;
                }
            }
            else
                if (abs(y2 - y1) == size - 1)
                {
                    for (int i = y1; i >= y2; i--)
                    {
                        if (field[i][x1] == true)
                        {
                            ok = false;
                            break;
                        }   
                        else
                            ok = true;
                    }
                }
        }
        else
            if (y1 == y2)
            {
                if (x1 <= x2 and abs(x2 - x1) == size - 1)
                {
                    for (int i = x1; i <= x2; i++)
                    {
                        if (field[y1][i] == true)
                        {
                            ok = false;
                            break;
                        }   
                        else
                            ok = true;
                    }
                }
                else
                    if (abs(x2 - x1) == size - 1)
                    {
                        for (int i = x1; i >= x2; i--)
                        {
                            if (field[y1][i] == true)
                            {
                                ok = false;
                                break;
                            }   
                            else
                                ok = true;
                            }
                    }
            }
    }
    return ok;
}

void ship(bool field[][10], int size, int i)
{
    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
    while (1)
    {
        if (size == 1)
        {
            std::cout << "Ship 1x" << size << std::endl;
            std::cout << "Input coordinates for " << i + 1 << " ship"<< std::endl;
            std::cin >> x1 >> y1;
            x2 = x1;
            y2 = y1;
        }
        else 
        {
            std::cout << "Ship 1x" << size << std::endl;
            std::cout << "Input coordinates first point for " << i + 1 << " ship"<< std::endl;
            std::cin >> x1 >> y1;
            std::cout << "Input coordinates second point for " << i + 1 << " ship"<< std::endl;
            std::cin >> x2 >> y2;
        }
        if (check_coordinates(x1, x2, y1, y2, field, size))
            break;
        else
            std::cout << "Wrong data. Try again!" << std::endl;
    }

    if (size == 1)
    {
        field[y1][x1] = true;
    }
    else
    {
        if (x1 == x2)
        {
            if (y1 < y2)
            {
                for (int i = y1; i <= y2; i++)
                {
                    field[i][x1] = true;
                }
            }
            else
            {
                for (int i = y1; i >= y2; i--)
                {
                    field[i][x1] = true;
                }
            }
        }

        if (y1 == y2)
        {
            if (x1 < x2)
            {
                for (int i = x1; i <= x2; i++)
                {
                    field[y1][i] = true;
                }
            }
            else
            {
                for (int i = x1; i >= x2; i--)
                {
                    field[i][y1] = true;
                }
            }
        } 
    }
}

void filling(bool field[][10])
{
    int size;
    //for 1x1
    size = 1;
    for (int i = 0; i < 4; i++)
        ship(field, size, i);
    //for 2x1
    size = 2;
    for (int i = 0; i < 3; i++)
        ship(field, size, i);
    //for3x1
    size = 3;
    for (int i = 0; i < 2; i++)
        ship(field, size, i);
    //for 4x1
    size = 4;
        ship(field, size, 0);  
}

bool checkEnd(bool field[][10])
{
    bool end = false;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (field[i][j] == true)
            {
                end = true;
                return end;
            }
        }
    }
    return end;
}

bool check_move(int x_move, int y_move)
{
    if (x_move >= 0 and x_move <= 9 and y_move >= 0 and y_move <= 9)
        return true;
    else 
        return false;
}

void game(bool field1[][10], bool field2[][10], int first_move)
{
    
        int x_move, y_move;
        while (1)
        {
            if (!checkEnd(field1))
            {
                winner = 1;
                break;
            }
            if (!checkEnd(field2))
            {
                winner = 2;
                break;
            }
            if (first_move % 2 == 0)
                std::cout << "Turn second player: " << std::endl;
            else
                std::cout << "Turn first player " << std::endl;
                std::cin >> x_move >> y_move;
            if (!check_move(x_move, y_move))
            {
                std::cout << "Wrong data. Try again" << std::endl;
                break;
            }
                
            if (first_move % 2 == 0)
            {
                if (field1[y_move][x_move])
                {
                    std::cout << "Hit" << std::endl;
                    field2[y_move][x_move] = false;
                }
                else
                {
                    std::cout << "Miss" << std::endl;
                }
            }
            else
            {
                if (field2[y_move][x_move])
                {
                    std::cout << "Hit" << std::endl;
                    field2[y_move][x_move] = false;
                }
                else
                {
                    std::cout << "Miss" << std::endl;
                }
            }

            first_move++;

            for (int i = 0; i <10;i++)
            {
                for(int j = 0; j<10;j++)
                {
                    std::cout << field1[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            for (int i = 0; i <10;i++)
            {
                for(int j = 0; j<10;j++)
                {
                    std::cout << field2[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }  
    }

int main()
{
    bool field1[10][10];
    clear(field1);
    std::cout << "1 player" << std::endl;
    filling(field1);

    bool field2[10][10];
    clear(field2);
    std::cout << "2 player" << std::endl;
    filling(field2);
    
    std::cout << "Choose whose start:" << std::endl;
    int first_move;
    std::cin >> first_move;

    game(field1, field2, first_move);

    output();
}