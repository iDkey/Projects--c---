#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>

struct personage
{
    std::string name = "unknown";
    int health = 0;
    int armor = -1;
    int damage = 0;
};

struct position
{
    int x;
    int y;
};

std::mt19937 gen(static_cast<unsigned int>(time(0)));

int get_rand_num(int a, int b)
{
    std::uniform_int_distribution<> rand_x(a,b);
    int x = rand_x(gen);
    return x;
}

bool check_pos(char (&field)[40][40], int x, int y)
{
    if (x < 0 or x > 39 or y < 0 or y > 39 or field[y][x] != '.')
        return false;
    else
        return true;
}

void filling_en(char (&field)[40][40], position* pos, int i, personage* pers)
{
    while (!check_pos(field, pos[i].x, pos[i].y))
    {
        pos[i].x = get_rand_num(0, 39);
        pos[i].y = get_rand_num(0, 39);
    }
    field[pos[i].y][pos[i].x] = 'E';
    pers[i].name = "Enemy #" + std::to_string(i + 1);
    pers[i].health = get_rand_num(50, 150);
    pers[i].armor = get_rand_num(0, 50);
    pers[i].damage = get_rand_num(15, 30);
}

void filling_field(char (&field)[40][40])
{
    for(int i = 0; i < 40; ++i)
    {
        for(int j = 0; j < 40; ++j)
        {
            field[i][j] = '.';
        }
    }
}

int find_enemy(position* pos, int x, int y)
{
    for (int i = 0; i < 5; ++i)
    {
        if (pos[i].x == x and pos[i].y == y)
            return i;
    }
    return -1;
}

void saving(std::ofstream& saves, personage& pers, position& pos, int& i)
{
    int len = pers.name.length();
    saves.write((char*)&len, sizeof(len));
    saves.write(pers.name.c_str(), len);
    saves.write((char*)&pers.health, sizeof(pers.health));
    saves.write((char*)&pers.armor, sizeof(pers.armor));
    saves.write((char*)&pers.damage, sizeof(pers.damage));
    saves.write((char*)&pos.x, sizeof(pos.x));
    saves.write((char*)&pos.y, sizeof(pos.y));
    saves.write((char*)&i, sizeof(i));
}

void loading(std::ifstream& saves, personage& pers, position& pos, int& i)
{
    int len;
    saves.read((char*)&len, sizeof(len));
    pers.name.resize(len);
    saves.read((char*)pers.name.c_str(), len);
    saves.read((char*)&pers.health, sizeof(pers.health));
    saves.read((char*)&pers.armor, sizeof(pers.armor));
    saves.read((char*)&pers.damage, sizeof(pers.damage));
    saves.read((char*)&pos.x, sizeof(pos.x));
    saves.read((char*)&pos.y, sizeof(pos.y));
    saves.read((char*)&i, sizeof(i));
}

bool check_winner(char (&field)[40][40])
{
    int count_enemy = 0;
    int count_player = 0;
    for(int i = 0; i < 40; ++i)
    {
        for(int j = 0; j < 40; ++j)
        {
            if (field[i][j] == 'P')
                count_player++;
            if (field[i][j] == 'E')
                count_enemy++;
        }
    }
    if (count_enemy > 0 and count_player > 0)
        return false;
    else
    {
        if(count_enemy <= 0)
            std::cout << "I'm lose.";
        if(count_player <= 0)
            std::cout << "I'm win.";
        return true;
    }
}

void map_out(char (&field)[40][40])
{
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 40; ++j)
        {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}



int main()
{
    char field[40][40];
    filling_field(field);
    position pos[6];
    personage pers[6];
    for(int i = 0; i < 5; ++i)
    {
        filling_en(field, pos, i, pers);
    }

    std::cout << "Choose name for your character:" << std::endl;
    std:: cin >> pers[5].name;
    while (pers[5].health < 50 or pers[5].health > 150)
    {
        std::cout << "Enter health (from 50 to 150) for " << pers[5].name << std::endl;
        std:: cin >> pers[5].health;
    }
    while (pers[5].armor < 0 or pers[5].armor > 50)
    {
        std::cout << "Enter armor (from 0 to 50) for " << pers[5].name << std::endl;
        std:: cin >> pers[5].armor;
    }
    while (pers[5].damage < 15 or pers[5].damage > 30)
    {
        std::cout << "Enter damage (from 15 to 30) for " << pers[5].name << std::endl;
        std:: cin >> pers[5].damage;
    }
    
    while (!check_pos(field, pos[5].x, pos[5].y))
    {
        pos[5].x = get_rand_num(0, 39);
        pos[5].y = get_rand_num(0, 39);
    }
    field[pos[5].y - 1][pos[5].x - 1] = 'P';
    map_out(field);
    for (int i = 0; !check_winner(field); ++i)
    {
        
        std::string move;
        std::cout << pers[i].name << " make a move" << std::endl;
        if (i == 5)
        {
            std::cin >> move;
        }
        else
        {
            std::uniform_int_distribution<> rand_x(0,3);
            if (rand_x(gen) == 0)
                move = "left";
            if (rand_x(gen) == 1)
                move = "right";
            if (rand_x(gen) == 2)
                move = "top";
            if (rand_x(gen) == 3)
                move = "bottom";
        }
        
        if (move == "load")
        {
            std::ifstream saves("A:\\Programs\\Projects (c++)\\Course\\Module 21\\Task 4\\saves.bin", std::ios::binary);
            for (int i = 0; i < 6; ++i)
            {
                loading(saves, pers[i], pos[i], i);
            }
            for (int i = 0; i < 6; ++i)
            {
                std::cout << pers[i].name << std::endl;
            }
            i--;
        }
        if (move == "save")
        {
            std::ofstream saves("A:\\Programs\\Projects (c++)\\Course\\Module 21\\Task 4\\saves.bin", std::ios::binary);
            for (int i = 0; i < 6; ++i)
            {
                saving(saves, pers[i], pos[i], i);
            }
            i--;
        }
        if (move == "left")
        {
            if (check_pos(field, pos[i].x - 1, pos[i].y))
            {
                std::swap(field[pos[i].y][pos[i].x - 1], field[pos[i].y][pos[i].x]);
            }
            else
            {
                if(field[pos[i].y][pos[i].x - 1] == 'P')
                {
                    pers[5].armor -= pers[i].damage;
                    if (pers[5].armor < 0)
                    {
                        pers[5].health += pers[5].armor;
                        pers[5].armor = 0;
                    }
                    if (pers[5].health <= 0)
                    {
                        field[pos[5].y][pos[5].x] = '.';
                    }
                }
                if(field[pos[i].y][pos[i].x - 1] == 'E' and i == 5)
                {
                    int j = find_enemy(pos, pos[i].x - 1, pos[i].y);
                    pers[j].armor -= pers[5].damage;
                    if (pers[j].armor < 0)
                    {
                        pers[j].health += pers[j].armor;
                        pers[j].armor = 0;
                    }
                    if (pers[j].health <= 0)
                    {
                        field[pos[j].y][pos[j].x] = '.';
                    }
                }
            }
        }
        if (move == "right")
        {
            if (check_pos(field, pos[i].x + 1, pos[i].y))
            {
                std::swap(field[pos[i].y][pos[i].x + 1], field[pos[i].y][pos[i].x]);
            }
            else
            {
                if(field[pos[i].y][pos[i].x + 1] == 'P')
                {
                    pers[5].armor -= pers[i].damage;
                    if (pers[5].armor < 0)
                    {
                        pers[5].health += pers[5].armor;
                        pers[5].armor = 0;
                    }
                    if (pers[5].health <= 0)
                    {
                        field[pos[5].y][pos[5].x] = '.';
                    }
                }
                if(field[pos[i].y][pos[i].x + 1] == 'E' and i == 5)
                {
                    int j = find_enemy(pos, pos[i].x + 1, pos[i].y);
                    pers[j].armor -= pers[5].damage;
                    if (pers[j].armor < 0)
                    {
                        pers[j].health += pers[j].armor;
                        pers[j].armor = 0;
                    }
                    if (pers[j].health <= 0)
                    {
                        field[pos[j].y][pos[j].x] = '.';
                    }
                }
            }
        }
        if (move == "top")
        {
            if (check_pos(field, pos[i].x, pos[i].y - 1))
            {
                std::swap(field[pos[i].y - 1][pos[i].x], field[pos[i].y][pos[i].x]);
            }
            else
            {
                if(field[pos[i].y - 1][pos[i].x] == 'P')
                {
                    pers[5].armor -= pers[i].damage;
                    if (pers[5].armor < 0)
                    {
                        pers[5].health += pers[5].armor;
                        pers[5].armor = 0;
                    }
                    if (pers[5].health <= 0)
                    {
                        field[pos[5].y][pos[5].x] = '.';
                    }
                }
                if(field[pos[i].y - 1][pos[i].x] == 'E' and i == 5)
                {
                    int j = find_enemy(pos, pos[i].x, pos[i].y - 1);
                    pers[j].armor -= pers[5].damage;
                    if (pers[j].armor < 0)
                    {
                        pers[j].health += pers[j].armor;
                        pers[j].armor = 0;
                    }
                    if (pers[j].health <= 0)
                    {
                        field[pos[j].y][pos[j].x] = '.';
                    }
                }
            }
        }
        if (move == "bottom")
        {
            if (check_pos(field, pos[i].x, pos[i].y + 1))
            {
                std::swap(field[pos[i].y + 1][pos[i].x], field[pos[i].y][pos[i].x]);
            }
            else
            {
                if(field[pos[i].y + 1][pos[i].x] == 'P')
                {
                    pers[5].armor -= pers[i].damage;
                    if (pers[5].armor < 0)
                    {
                        pers[5].health += pers[5].armor;
                        pers[5].armor = 0;
                    }
                    if (pers[5].health <= 0)
                    {
                        field[pos[5].y][pos[5].x] = '.';
                    }
                }
                if(field[pos[i].y + 1][pos[i].x] == 'E' and i == 5)
                {
                    int j = find_enemy(pos, pos[i].x, pos[i].y + 1);
                    pers[j].armor -= pers[5].damage;
                    if (pers[j].armor < 0)
                    {
                        pers[j].health += pers[j].armor;
                        pers[j].armor = 0;
                    }
                    if (pers[j].health <= 0)
                    {
                        field[pos[j].y][pos[j].x] = '.';
                    }
                }
            }
        }
        if (i == 5)
        {
            i = -1;
        }
        map_out(field);
        check_winner(field);
    }
}