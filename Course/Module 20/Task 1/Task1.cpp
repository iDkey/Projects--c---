#include <iostream>
#include <fstream>

int main()
{
        std::ofstream file("A:\\Programs\\Projects (c++)\\Course\\Module 20\\Task 1\\file.txt", std::ios::app);
        std::string name;
        std::string surname;
        std::string date_salary;
        int salary;

        while(1)
        {
                std::cout << "Input name:" << std::endl;
                std::cin >> name;
                std::cout << "Input surname:" << std::endl;
                std::cin >> surname;
                std::cout << "Input date of salary:" << std::endl;
                std::cin >> date_salary;
                std::cout << "Input size of salary in RUB:" << std::endl;
                std::cin >> salary;
                int x = std::stoi(date_salary.substr(0, 2));
                x = std::stoi(date_salary.substr(3, 2));
                x = std::stoi(date_salary.substr(6, 4));
                if (std::stoi(date_salary.substr(0, 2)) < 1 or std::stoi(date_salary.substr(0, 2)) > 31 
                        or std::stoi(date_salary.substr(3, 2)) < 0 or std::stoi(date_salary.substr(3, 2)) > 12
                        or std::stoi(date_salary.substr(6, 4)) < 0 or std::stoi(date_salary.substr(6, 4)) > 2021)
                                std::cout << "Wrong data. Try again" << std::endl;
                else
                        break;
        }

        file << name << " ";
        file << surname << " ";
        file << date_salary << " ";
        file << salary << " ";
        file << "RUB\n";
        file.close();
}