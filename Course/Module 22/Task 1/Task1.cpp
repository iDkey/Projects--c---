#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, std::string> hand_book;
    std::map<std::string, std::string> name_number;

    for(int i = 0; i < 5; ++i)
    {
        hand_book.insert(std::make_pair<std::string, std::string> ("69-70-0" + std::to_string(i), "Ivanov"));
        if (name_number.count("Ivanov"))
            name_number["Ivanov"] += " 69-70-0" + std::to_string(i);
        else
            name_number.insert(std::make_pair<std::string, std::string> ("Ivanov", "69-70-0" + std::to_string(i)));
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
        if (name_number.count(name))
            name_number[name] += (" " + number);
        else
            name_number.insert(std::pair<std::string, std::string> (name, number));
    }

    hand_book.insert(std::pair<std::string, std::string> ("33-44-55", "Danila"));
    if (name_number.count("Danila"))
        name_number["Danila"] += " 33-44-55";
    else
        name_number.insert(std::make_pair<std::string, std::string> ("Danila", "33-44-55"));

    hand_book.insert(std::pair<std::string, std::string> ("33-44-56", "Zab"));
    if (name_number.count("Zab"))
        name_number["Zab"] += " 33-44-56";
    else
        name_number.insert(std::make_pair<std::string, std::string> ("Zab", "33-44-56"));
    
    hand_book.insert(std::pair<std::string, std::string> ("11-22-56", "Ivanov"));
    if (name_number.count("Ivanov"))
        name_number["Ivanov"] += " 11-22-56";
    else
        name_number.insert(std::make_pair<std::string, std::string> ("Ivanov", "11-22-56"));

    if(name == "")
    {
        if(hand_book.count(number) > 0)
            std::cout << hand_book[number];
    }
    if(number == "")
    {
        std::cout << name_number[name];
    }
}