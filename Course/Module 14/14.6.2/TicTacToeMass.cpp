#include <iostream>

void output (char moveChar)
{
    if (moveChar == 'd')
        std::cout << "Draw" << std::endl;
    else
        std::cout << moveChar << " is winner!";
}

bool checkMove (int x, int y, char moveChar, char playingField[3][3])
{
    if (playingField[y - 1][x - 1] == ' ' and (moveChar == 'X' or moveChar == 'O')
        and (x > 0 and y > 0 and x < 4 and y < 4))
        return true;
    else
        return false;
}

void saveMove (char playingField[][3], int x, int y, char moveChar)
{
    playingField[y - 1][x - 1] = moveChar;
}

bool checkLine (std::string line)
{
        if (line[0] == line[1] and line[1] == line[2] and (line[0] == 'X' or line[0] == 'O'))
            return true;
        else 
            return false;
}

bool checkWin (char playingField[][3])
{
    bool win = false;

    // check for columns
    for (int i = 0; i < 3; i++)
    {
        std::string line;
        for (int j = 0; j < 3; j++)
        {
            line += playingField[i][j];
        }
        if (checkLine(line))
        {
            win = true;
            return win;
        }
    }

    //check for lines
    for (int j = 0; j < 3; j++)
    {
        std::string line;
        for (int i = 0; i < 3; i++)
        {
            line += playingField[i][j];
        }
        if (checkLine(line))
        {
            win = true;
            return win;
        }
    }
    return win;
}

int main()
{
    char playingField[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int win = 0;
    int step = 0;
    int countStep = 0;
    while(win != 1 or win != 2)
    {
        char charX, charO, moveChar;
        int x, y;
        if (step % 2 == 0)
        {
            std::cout << "Turn to go to crosses" << std::endl;
            moveChar = 'X';
        }
        else
        {
            std::cout << "Turn to go to zero" << std::endl;
            moveChar = 'O';
        }
        std::cout << "chose a place (x form 1 to 3): " << std::endl;
        std::cin >> x;
        std::cout << "chose a place (y form 1 to 3): " << std::endl;
        std::cin >> y;
        if (checkMove(x, y, moveChar, playingField))
        {
            saveMove(playingField, x, y, moveChar);
            if (checkWin(playingField))
            {
                output(moveChar);
                break;
            }
            else
                countStep++;
        }
        else
        {
            std::cout << "Wrong data. Try again:" << std::endl;
            step--;
        }
            step++;
            if (countStep == 9)
                {
                    char draw = 'd';
                    output(draw);
                    break;
                }
            std::cout << "The current state of the playing field:" << std::endl;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    std::cout << playingField[i][j] << " ";
                }
                std::cout << std::endl;
            }
    }
}