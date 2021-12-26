#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names;
    std::vector<std::tm> dates;
    std::string name = "";
    std::time_t time_birthday = std::time(nullptr);
    std::tm time_birthday_tm = *localtime(&time_birthday);
    while(true)
    {
        std::cout << "Input a name:" << std::endl;
        std::cin >> name;
        if(name == "end")
            break;
        names.push_back(name);
        std::cout << "Input a date of birthday for " << name << std::endl;
        std::cin >> std::get_time(&time_birthday_tm, "%Y/%m/%d");
        dates.push_back(time_birthday_tm);
    }

    std::time_t time_now = time(nullptr);
    std::tm time_now_tm = *localtime(&time_now);
    for(int i = 0; i < dates.size(); i++)
    {
        if(dates[i].tm_mday == time_now_tm.tm_mday and dates[i].tm_mon == time_now_tm.tm_mon)
            std::cout << "Today " << names[i] << "'s birthday" << std::endl;
    }
    int dif_month;
    int dif_day;
    int min_day = 32;
    int min_month = 13;
    std::tm next_birthday;
    std::string n_names = "";
    for(int i = 0; i < dates.size(); ++i)
    {
        if(dates[i].tm_mon >= time_now_tm.tm_mon and dates[i].tm_mday >= time_now_tm.tm_mday)
        {
            dif_month = dates[i].tm_mon - time_now_tm.tm_mon;
            dif_day = dates[i].tm_mday - time_now_tm.tm_mday;
        }
        if(dates[i].tm_mon < time_now_tm.tm_mon and dates[i].tm_mday < time_now_tm.tm_mday)
        {
            dif_month = 12 - time_now_tm.tm_mon + dates[i].tm_mon;
            dif_day = 31 - time_now_tm.tm_mday + dates[i].tm_mday;
        }
        if(dates[i].tm_mon < time_now_tm.tm_mon and dates[i].tm_mday >= time_now_tm.tm_mday)
        {
            dif_month = 12 - time_now_tm.tm_mon + dates[i].tm_mon;
            dif_day = dates[i].tm_mday - time_now_tm.tm_mday;
        }
        if(dates[i].tm_mon > time_now_tm.tm_mon and dates[i].tm_mday < time_now_tm.tm_mday)
        {
            dif_month = dates[i].tm_mon - time_now_tm.tm_mon;
            dif_day = 31 - time_now_tm.tm_mday + dates[i].tm_mday;
        }
        if(dates[i].tm_mon == time_now_tm.tm_mon and dates[i].tm_mday < time_now_tm.tm_mday)
        {
            dif_month = 12 - time_now_tm.tm_mon + dates[i].tm_mon;
            dif_day = time_now_tm.tm_mday - dates[i].tm_mday;
        }

        if((dif_month <= min_month and dif_day <= min_day) and !(dates[i].tm_mday == time_now_tm.tm_mday and dates[i].tm_mon == time_now_tm.tm_mon))
        {
            if (dif_month <= min_month and dif_day <= min_day)
            {
                if(dif_month == min_month and dif_day == min_day)
                    n_names += "'s, " + names[i];
                else
                    n_names = names[i];
            }

            else
                n_names = names[i];
            min_month = dif_month;
            min_day = dif_day;
            next_birthday = dates[i];
        }


    }
    std::cout << n_names << "'s next birthdays (" << next_birthday.tm_mon + 1 << "/" << next_birthday.tm_mday << ")" << std::endl;
}
