#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>
#include <string>

int main() {
    std::map<int, std::string> birthdays;
    std::cout << "Input dates of birthdays and names yours friends:" << std::endl;
    std::string name = "";
    std::time_t t = std::time(nullptr);
    std::tm* local = std::localtime(&t);
    while(true)
    {
        std::cout << "Input a name:" << std::endl;
        std::cin >> name;
        if(name == "end")
            break;
        std::cout << "Input a date of birthday like YYYY/MM/DD:" << std::endl;
        std::cin >> std::get_time(local, "%Y/%m/%d");
        int date = local->tm_mon * 100 + local->tm_mday;
        if (birthdays.count(date) > 0)
        {
            birthdays[date] += ", " + name;
        }
        else
        {
            birthdays.insert(std::pair<int, std::string> (date, name));
        }
    }

    std::time_t t_now = std::time(nullptr);
    std::tm* local_now = std::localtime(&t_now);
    std::cout << "Today: " << local_now->tm_year + 1900<< "/" << local_now->tm_mon + 1 << "/" << local_now->tm_mday << std::endl;
    int date_now = local_now->tm_mon * 100 + local_now->tm_mday;
    if(birthdays.count(date_now) > 0)
    {
        std::cout << "Today " << birthdays[date_now] << " birthday" << std::endl;
    }
    std::map<int, std::string>::iterator it = birthdays.upper_bound(date_now);
    int date_d = it->first % 100;
    int date_m = it->first / 100 % 100;
    std::cout << date_m << "/" << date_d << " " << it->second << " birthday" << std::endl;
}
