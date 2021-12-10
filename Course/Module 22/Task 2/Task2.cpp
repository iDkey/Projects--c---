#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> registry;
    std::string data_in;
    while(data_in != "exit")
    {
        std::cout << "Input a string:" << std::endl;
        std::cin >> data_in;
        if(data_in == "Next")
        {
            std::map<std::string, int>::iterator it = registry.begin();
            std::cout << it -> first << std::endl;
            it -> second -= 1;
            if (it -> second == 0)
            {
                registry.erase(it);
            }
            
        }
        else
        {
            if(registry.count(data_in) > 0)
            {
                registry[data_in] += 1;
            }
            else
            {
                registry.insert(std::pair<std::string, int> (data_in, 1));
            }
        }
    }
}