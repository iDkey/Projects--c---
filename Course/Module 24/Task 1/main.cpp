#include <iostream>
#include <ctime>
#include <string>
#include <vector>

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
    std::vector<std::string> tasks;
    std::vector<int> time;
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
                tasks.push_back(task_name);
                time.push_back(d);
                std::cout << "Input task's name: " << std::endl;
                std::cin >> task_name;
                t_start = std::time(nullptr);
            }
        }
        if (command == "end")
        {
            if (task_status)
            {
                t_end = std::time(nullptr);
                int d = std::difftime(t_end, t_start);
                std::cout << task_name << " end in: ";
                out_time(d);
                tasks.push_back(task_name);
                time.push_back(d);
                task_status = false;
            }
            else
            {
                std::cout << "No active tasks" << std::endl;
            }
        }
        if (command == "status")
        {
            t_end = std::time(nullptr);
            int d = std::difftime(t_end, t_start);
            if (!task_status)
            {
                for (int i = 0; i < tasks.size(); ++i)
                    std::cout << tasks[i] << " continue: " << time[i] << "seconds" << std::endl;
            }
            else
            {
                tasks.push_back(task_name);
                time.push_back(d);
                for (int i = 0; i < tasks.size(); ++i)
                    std::cout << tasks[i] << " continue: " << time[i] << "seconds" << std::endl;
            }
        }
    }
}
