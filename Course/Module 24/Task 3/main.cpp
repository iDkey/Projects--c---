#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

int main()
{
    std::time_t end_time_time_t = time(nullptr);
    std::tm end_time_tm = *localtime(&end_time_time_t);
    std::cin >> std::get_time(&end_time_tm, "%M:%S");
    std::time_t now_time_t = time(nullptr);
    std::tm now_tm = *localtime(&now_time_t);
    if(end_time_tm.tm_sec + now_tm.tm_sec > 59)
    {
        if(end_time_tm.tm_min != 59)
        {
            end_time_tm.tm_min += 1;
            end_time_tm.tm_sec = end_time_tm.tm_sec - 60 + now_tm.tm_sec;
        }
        else
        {
            end_time_tm.tm_hour += 1;
            end_time_tm.tm_min = 1;
        }
    }
    else
    {
        end_time_tm.tm_sec += now_tm.tm_sec;
    }
    if(end_time_tm.tm_min + now_tm.tm_min > 59)
    {
        if(end_time_tm.tm_hour != 23)
        {
            end_time_tm.tm_hour += 1;
            end_time_tm.tm_min = end_time_tm.tm_min - 60 + now_tm.tm_min;
        }
        else
        {
            end_time_tm.tm_mday += 1;
            end_time_tm.tm_hour = 0;
        }
    }
    else
    {
        end_time_tm.tm_min += now_tm.tm_min;
    }

    do
    {
        now_time_t = time(nullptr);
        now_tm = *localtime(&now_time_t);
        std::cout << end_time_tm.tm_min - now_tm.tm_min << " " << end_time_tm.tm_sec - now_tm.tm_sec << std::endl;
        _sleep(1000);
    }while(end_time_tm.tm_min - now_tm.tm_min >= 0 and end_time_tm.tm_sec - now_tm.tm_sec > 1);
    now_time_t = time(nullptr);
    now_tm = *localtime(&now_time_t);
    bool flag;
    if(end_time_tm.tm_min - now_tm.tm_min == 0 and end_time_tm.tm_sec - now_tm.tm_sec == 0)
        flag = true;
    else
        flag = false;
    if(flag)
        std::cout << "DING!DING!DING!" << std::endl;
}