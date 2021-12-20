#include <iostream>
#include <ctime>
#include <string>

void out_time(int time)
{
    if(time < 60)
    {
        std::cout << time << " seconds" << std::endl;
    }
    else
    {
        int min = time / 60;
        if(min < 60)
        {
            std::cout << min << " minutes " << time % 60 << " seconds" << std::endl;
        }
        else
        {
            int hour = min / 60;
            if(hour < 60)
            {
                std::cout << hour << " hours "<< min << " minutes " << time % 60 << " seconds" << std::endl;
            }
        }
    }
}

int main() {
    std::string command = "";
    std::string task_name;
    bool task_status = false;
    std::time_t t_start;
    std::time_t t_end;
    while(command != "exit")
    {
        std::cout << "Input a command:" << std::endl;
        std::cin >> command;
        if (command == "begin")
        {
            if(!task_status)
            {
                std::cout << "Input task's name: " << std::endl;
                std::cin >> task_name;
                t_start = std::time(nullptr);
                task_status = true;
            }
            else
            {
                t_end = std::time(nullptr);
                int d = std::difftime(t_end, t_start);
                std::cout << task_name << " end in: ";
                out_time(d);
                std::cout << "Input task's name: " << std::endl;
                std::cin >> task_name;
                t_start = std::time(nullptr);
            }
        }
        if (command == "end")
        {
            t_end = std::time(nullptr);
            int d = std::difftime(t_end, t_start);
            std::cout << task_name << " end in: ";
            out_time(d);
        }
        if (command == "status")
        {
            t_end = std::time(nullptr);
            int d = std::difftime(t_end, t_start);
            std::cout << task_name << " continue: ";
            out_time(d);
        }
    }
}
