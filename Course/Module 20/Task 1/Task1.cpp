#include <iostream>
#include <fstream>

int main()
{
        std::ofstream file("A:\\Programs\\Projects (c++)\\Course\\Module 20\\Task 1\\file.txt", std::ios::app);
        std::string name;
        std::string surname;
        std::string date_salary;
        int salary;

        std::cout << "Input name:" << std::endl;
        std::cin >> name;
        std::cout << "Input surname:" << std::endl;
        std::cin >> surname;
        std::cout << "Input date of salary:" << std::endl;
        std::cin >> date_salary;
        std::cout << "Input size of salary in RUB:" << std::endl;
        std::cin >> salary;

        file << name << " ";
        file << surname << " ";
        file << date_salary << " ";
        file << salary << " ";
        file << "RUB\n";
        file.close();
}