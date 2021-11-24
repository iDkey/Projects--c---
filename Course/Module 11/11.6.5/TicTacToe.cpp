#include <iostream>

bool check(std::string line)
{
    bool ok = true;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != 'X' and line[i] != 'O' and line[i] != '.')
        {
            ok = false;
            break;
        }
    }
    return ok;
}

bool checkWin(int winners, int countX, int countO, char winner)
{
    bool ok;
    if (winners <2)
        ok = true;
    
    if (winner == 'O')
    {
        if (countX - countO == 0 or countX - countO == 1)
            ok = true;
        else
            ok = false;
    }
    else
    {
        if (winner == 'X')
            if (countX - countO == 0 or countX - countO == 1)
                ok = true;
            else
                ok = false;
    }
    if (countX == 0 or countO == 0)
        ok = false;
    return ok;
}

void output(bool ok, char winner)
{
    if (ok)
    {
        if (winner == 'X')
            std::cout << "Petya won\n";
        else
            if (winner == 'O')
                std::cout << "Vanya won\n";
            else 
                std::cout << "Nobody\n";
    }  
    else
        std::cout << "Incorrect\n";
}

std::string diagonal(std::string line1, std::string line2, std::string line3, int mainDiagonal)
{
    std::string line;
    if (mainDiagonal == 1)
    {
            for (int i = 0, j = 0; j < 3; j++, i++)
            {
                if (j == 0)
                    line += line1[i];
                if (j == 1)
                    line += line2[i];
                if (j == 2)
                    line += line3[i];
            }
    }
    else 
        if (mainDiagonal == 0)
        {
                for (int i = 0, j = 0; j < 3; j++, i++)
                {
                    if (j == 0)
                        line += line1[2 - i];
                    if (j == 1)
                        line += line2[2 - i];
                    if (j == 2)
                        line += line3[2 - i];
                }
        }
        else
            return "Error";
        return line;
}

std::string column(std::string line1, std::string line2, std::string line3, int numColumn)

{
    std::string column;
    column += line1[numColumn];
    column += line2[numColumn];
    column += line3[numColumn];
    return column;
}

void findWinner (std::string line1, std::string line2, std::string line3)
{
    int mainDiagonal, numColumn;
    std::string line;
    int winners = 0;
    char winner = ' ';
    int countO = 0, countX = 0;

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
            line = line1;
        if (i == 1)
            line = line2;
        if (i == 2)
            line = line3;
        for (int j = 0; j < 3; j++)
        {
            if (line[j] == 'O')
                countO++;
            if (line[j] == 'X')
                countX++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
            line = line1;
        if (i == 1)
            line = line2;
        if (i == 2)
            line = line3;
        
        if (line[0] == line[1] and line[1] == line[2] and (line[0] == 'X' or line[0] == 'O'))
        {
            winners ++;
            winner = line[0];
        }
    }
        
    for (int i = 0; i < 3; i++)
    {
        line = column(line1, line2, line3, i);
        if (line[0] == line[1] and line[1] == line[2] and (line[0] == 'X' or line[0] == 'O'))
        {
            winners ++;
            winner = line[0];
            }
        }
    for (int i = 0; i < 2; i++)
    {
        line = diagonal(line1, line2, line3, i);
            
        if (line[0] == line[1] and line[1] == line[2] and (line[0] == 'X' or line[0] == 'O'))
        {
            winners ++;
            winner = line[0];
        }
    }

    bool ok = checkWin(winners, countX, countO, winner);
    output(ok, winner);
}

int main()
{
    std::string line1, line2, line3;
    std::cout << "Input fist line:\n";
    std::cin >> line1;
    std::cout << "Input second line:\n";
    std::cin >> line2;
    std::cout << "Input third line:\n";
    std::cin >> line3;

    bool ok1 = check(line1), ok2 = check(line2), ok3 = check(line3);
    

    if (ok1  and ok2 and ok3)
    {
        findWinner(line1, line2, line3);
    }
    else 
        std::cout << "Incorrect\n";
}