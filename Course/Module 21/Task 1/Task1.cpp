#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct form
{
    std::string name = "unknown";
    std::string surname = "unknown";
    std::string date = "unknown";
    int salary = -1;
    std::string units = "RUB";
};

void writing()
{
    std::ofstream file("A:\\Programs\\Projects (c++)\\Course\\Module 21\\Task 1\\file.txt", std::ios::app);
    form output;

    std::cout << "Input name:" << std::endl;
    std::cin >> output.name;
    std::cout << "Input surname:" << std::endl;
    std::cin >> output.surname;
    std::cout << "Input date of payout:" << std::endl;
    std::cin >> output.date;
    std::cout << "Input summ of payout:" << std::endl;
    std::cin >> output.salary;

    file << "\n" << output.name << " " << output.surname << " " << output.date << output.salary << " RUB\n";

    file.close();
}

void listing()
{
    std::ifstream file("A:\\Programs\\Projects (c++)\\Course\\Module 21\\Task 1\\file1.txt");
    if (file.is_open())
    {
        form output;
        while (!file.eof())
        {
            file >> output.name;
            file >> output.surname;
            file >> output.date;
            file >> output.salary;
            file >> output.units;
            if (output.name == "unknown" or output.surname == "unknown" or output.date == "unknown" or output.salary == -1)
            {
                std::cout << "File is empty";
            }
            else
            {
                std::cout << output.name << " " << output.surname << " " << output.date << " " << output.salary << " " << output.units << std::endl;
            }
        }
        file.close();
    }
    else
        std::cout << "File is not found" << std::endl;
    
}

int main()
{
    std::string action;
    std::cout << "Chose a action:" << std::endl;
    std::cin >> action;

    if (action == "list")
    {
        listing();
    }
    else
        if (action == "add")
        {
            writing();
        }
        else
        {
            std::cout << "Wrong command. Try again..." << std::endl;
        }
}