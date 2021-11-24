#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream file;
    std::vector<std::string> vec;
    while (true)
    {
        std::string path;
        std::cout << "Include path to txt file:" << std::endl;
        getline(std::cin,path);
        file.open(path);
        if (file.is_open())
            break;
        else
            std::cout << "Somthing wrong with a path. Try again!" << std::endl;
    }

    while (!file.eof())
    {
        std::string data;
        file >> data;
        vec.push_back(data);
    }
    
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    file.close();
}
//A:\Programs\Projects (c++)\Course\Module 19\Task 2\file.txt