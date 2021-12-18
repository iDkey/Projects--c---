#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

void out_time(std::time_t start, std::time_t end)
{
    int dif = std::difftime(end, start);
    if(dif < 60)
    {
        if (dif == 1)
            std::cout << dif << " second" << std::endl;
        else
        std::cout << dif << " seconds " << std::endl;
    }
    else
    {
        int min = dif / 60;
        dif %= 60;
        if (min < 60)
        {
            if (min == 1)
                std::cout << min << " minute " << dif << " seconds " << std::endl;
            else
            std::cout << min << " minutes " << dif << " seconds" << std::endl;
        }
        else
        {
            int hours = min / 60;
            min %= 60;
            if (hours == 1)
                std::cout << hours << " hour " << min << " minutes " << dif << " seconds " << std::endl;
            else
                std::cout << hours << " hours " << min << " minutes " << dif << " seconds " << std::endl;
        }
    }
}

int main() {
    std::string command = "";
    bool task_status = false;
    std::time_t t = std::time(nullptr);
    while(command != "exit")
    {
        std::cout << "Input a command:" << std::endl;
        std::cin >> command;
        if (command == "begin")
        {
            if(!task_status)
            {
                std::string task_name;
                std::cout << "Input a task's name:" << std::endl;
                std::cin >> task_name;
                std::ofstream saves("A:\\Programs\\Projects(c++)\\Course\\Module 24\\Task 1\\saves.txt", std::ios::app);
                saves << task_name << " " << std::time(nullptr); // start a new task
                saves.close();
                task_status = true;
            }
            else
            {
                std::ofstream saves("A:\\Programs\\Projects(c++)\\Course\\Module 24\\Task 1\\saves.txt", std::ios::app);
                saves << " " << std::time(nullptr) << " "; //end the last task
                std::string task_name;
                std::cout << "Input a task's name:" << std::endl;
                std::cin >> task_name;
                saves << " " << task_name << " " << std::time(nullptr); // start a new task
                saves.close();
            }
        }
        if (command == "end")
        {
            std::ofstream saves("A:\\Programs\\Projects(c++)\\Course\\Module 24\\Task 1\\saves.txt", std::ios::app);
            saves << " " << std::time(nullptr) << " "; //end the last task
            saves.close();
            task_status = false;
        }
        if (command == "status")
        {
            std::ifstream saves("A:\\Programs\\Projects(c++)\\Course\\Module 24\\Task 1\\saves.txt");
            while(!saves.eof())
            {
                std::string task_name;
                std::time_t start;
                std::time_t end;
                saves >> task_name;
                saves >> start;
                saves >> end;
                std::tm* start_f = std::localtime(&start);
                std::tm* end_f = std::localtime(&end);
                if (task_name != "")
                {
                    std::cout << task_name << " continue ";
                    out_time(start, end);
                }


            }
            saves.close();
        }
    }
}
