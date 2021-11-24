#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int pars_salary(std::string salary_str)
{
    return std::stoi(salary_str);
}

int main()
{
    int max_salary = 0;
    std::string name_of_richest;
    int total_salary = 0;

    std::ifstream file;
    file.open("A:\\Programs\\Projects (c++)\\Course\\Module 19\\Task 3\\file.txt");

    while(!file.eof())
    {
        std::string r_data;
        file >> r_data;

        std::string name_surname;
        name_surname += r_data;
        name_surname += ' ';
        file >> r_data;
        name_surname += r_data;

        std::string salary_str;
        file >> r_data;
        salary_str += r_data;
        int salary = pars_salary(salary_str);
        total_salary += salary;

        if (salary > max_salary)
        {
            max_salary = salary;
            name_of_richest = name_surname;
        }

        std::string b_date_str;
        file >> r_data;
        b_date_str += r_data;
    }

    std::cout << "Total salary is " << total_salary << std::endl;
    std::cout << name_of_richest << " get maximum money!" << std::endl;
    file.close();
}