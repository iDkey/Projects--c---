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
    int x;
    int y;
};

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

void create_hero(personage& pers, std::mt19937& gen)
{
    pers.name = "Danila";
    /*while (pers.health < 50 or pers.health > 150)
    {
        std::cout << "Input HP for your character:" << std::endl;
        std::cin >> pers.health;
    }*/
    pers.health = 100;
    /*while (pers.armor < 50 or pers.armor > 150)
    {
        std::cout << "Input armor for your character:" << std::endl;
        std::cin >> pers.armor;
    }*/
    pers.armor = 30;
    /*while (pers.damage < 50 or pers.damage > 150)
    {
        std::cout << "Input damage for your character:" << std::endl;
        std::cin >> pers.damage;
    }*/
    pers.damage = 25;
    std::uniform_int_distribution<> rand_x(0, 39);
    pers.x = rand_x(gen);
    std::uniform_int_distribution<> rand_y(0, 39);
    pers.y = rand_y(gen);
}

void create_enemy(personage& pers, std::mt19937& gen, int i, char (&field)[40][40])
{
    pers.name = "Enemy #" + std::to_string(i + 1);
    std::uniform_int_distribution<> rand_health(50, 150);
    pers.health = rand_health(gen);
    std::uniform_int_distribution<> rand_armor(0, 50);
    pers.armor = rand_armor(gen);
    std::uniform_int_distribution<> rand_damage(15, 30);
    pers.damage = rand_damage(gen);
    std::uniform_int_distribution<> rand_x(0, 39);
    std::uniform_int_distribution<> rand_y(0, 39);
    do
    {
        pers.x = rand_x(gen);
        pers.y = rand_y(gen);
    }while(field[pers.y][pers.x] != '.');

    field[pers.y][pers.x] = 'E';
}

int check_position_to_move(char (&field)[40][40], int x, int y)
{
    if (x > 0 and x < 39 and y > 0 and y < 39)
    {
        if(field[y][x] == '.')
            return 1;
        if(field[y][x] == 'E')
            return 2;
        if(field[y][x] == 'P')
            return 3;
    }
    return 0;
}

int find_enemy(int x, int y, personage* pers)
{
    bool find = false;
    for(int i = 0; i < 5 or !find; ++i)
    {
        if((pers + i)->x == x and (pers + i)->y == y)
            return i;
    }
    return -1;
}
// -> field, i, -1, 0, pers
void make_move(char (&field)[40][40], int i, int a, int b, personage* pers)
{
    if(check_position_to_move(field, (pers + i) -> x + a, (pers + i) -> y + b) == 1)
    {
        std::swap(field[(pers + i) -> y][(pers + i) -> x], field[(pers + i) -> y + b][(pers + i) -> x + a]);
    }
    if(check_position_to_move(field, (pers + i) -> x + a, (pers + i) -> y + b) == 2 and i == 5)
    {
        int num_enemy = find_enemy((pers + i) -> x + a, (pers + i) -> y + b, pers);
        (pers + num_enemy) -> armor -= (pers + i) -> damage;
        if ((pers + num_enemy) -> armor < 0)
        {
            (pers + num_enemy) -> health += (pers + num_enemy) -> armor;
            (pers + num_enemy) -> armor = 0;
        }
        if ((pers + num_enemy) -> health <= 0)
        {
            field[(pers + num_enemy) -> y + b][(pers + num_enemy) -> x + a] = '.';
            (pers + num_enemy) -> health = 0;
        }
    }
    if(check_position_to_move(field, (pers + i) -> x + a, pers[i].y + b) == 3 and i != 5)
    {
        (pers + 5) -> armor -= (pers + i) -> damage;
        if((pers + 5) -> armor < 0)
        {
            (pers + 5) -> health += (pers + 5) -> armor;
            (pers + 5) -> armor = 0;
        }
        if ((pers + 5) -> health <= 0)
        {
            field[(pers + 5) -> y + b][(pers + 5) -> x + a] = '.';
            (pers + 5) -> health = 0;
        }
    }
}

bool check_win(char (&field)[40][40])
{
    int count_players = 0;
    int count_enemy = 0;
    for(int i = 0; i < 40; ++i)
    {
        for(int j = 0; j < 40; ++j)
        {
            if(field[i][j] == 'P')
                count_players++;
            if(field[i][j] == 'E')
                count_enemy++;
        }
    }
    if(count_enemy > 0 and count_players > 0)
        return true;
    else
        return false;
}

void field_output(char (&field)[40][40])
{
    for(int i = 0; i < 40; ++i)
    {
        for(int j = 0; j < 40; ++j)
        {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::mt19937 gen(static_cast<unsigned int>(time(0)));
    char field[40][40];
    filling_field(field);

    personage pers[6];
    for(int i = 0; i < 5; ++i)
    {
        create_enemy(pers[i], gen, i, field);
    }
    
    create_hero(pers[5], gen);
    field[pers[5].y][pers[5].x] = 'P';

    field_output(field);
    std::string move;
    for(int i = 0; check_win(field); i++)
    {
        if (i == 5)
        {
            std::cout << pers[5].name << ", your turn to make a move:" << std::endl;
            std::cin >> move;
        }
        else
        {
            std::cout << pers[i].name << " make a move" << std::endl;
            std::uniform_int_distribution<> rand_move(0,3);
            int plug = rand_move(gen);
            if(plug == 0)
            {
                move = "left";
            }
            if(plug == 1)
            {
                move = "right";
            }
            if(plug == 2)
            {
                move = "top";
            }
            if(plug == 3)
            {
                move = "bottom";
            }
        }

        if (move == "left")
        {
            make_move(field, i, -1, 0, pers);
        }
        if (move == "right")
        {
            make_move(field, i, 1, 0, pers);
        }
        if (move == "top")
        {
            make_move(field, i, 0, -1, pers);
        }
        if (move == "bottom")
        {
            make_move(field, i, 0, 1, pers);
        }
        if(i == 5)
        {
            i = -1;
        }

        check_win(field);
        field_output(field);
    }
}