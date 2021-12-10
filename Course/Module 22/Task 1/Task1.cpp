#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, std::string> hand_book;   
    for(int i = 0; i < 5; ++i)
    {
        hand_book.insert(std::make_pair<std::string, std::string> ("69-70-0" + std::to_string(i), "Ivanov"));
    }

    std::string request;
    std::cout << "Input a request:" <<std::endl;
    getline(std::cin, request);
    bool space_f = false;
    bool dash_f = false;
    int mark;
    std::string number;
    std::string name;
    for(int i = 0; !space_f and i < request.length(); i++)
    {
        if(request[i] == ' ')
        {
            mark = i;
            space_f = true;
        }
        if (request[i] == '-')
            dash_f = true;
    }
    if(space_f)
    {
        for (int i = 0; i < mark; ++i)
        {
            number += request[i];
        }
        for(int i = mark + 1; i < request.length(); ++i)
        {
            name += request[i];
        }
    }
    else
    {
        if (!dash_f)
        {
            name = request;
        }
        else
        {
            number = request;
        }
    }
    
    if (name != "" and number != "")
    {
        hand_book.insert(std::pair<std::string, std::string> (number, name));
        
    }
    hand_book.insert(std::pair<std::string, std::string> ("33-44-55", "Danila"));
    hand_book.insert(std::pair<std::string, std::string> ("33-44-56", "Zab"));

    if(name == "")
    {
        if(hand_book.count(number) > 0)
            std::cout << hand_book[number];
    }
    if(number == "")
    {
        for(std::map<std::string, std::string>::iterator it = hand_book.begin(); it != hand_book.end(); it++)
        {
            if(it->second == request)
            {
                std::cout << it->first << " ";
            }
        }
    }
}