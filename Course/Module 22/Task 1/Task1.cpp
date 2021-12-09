#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<int, std::string> hand_book_names;
    std::map<int, std::string> hand_book_numbers;
    
    for(int i = 0; i < 5; ++i)
    {
        hand_book_names.insert(std::make_pair<int, std::string> (i + 1, "Ivanov"));
        hand_book_numbers.insert(std::make_pair<int, std::string> (i + 1, "69-70-0" + std::to_string(i)));
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
        hand_book_names.insert(std::pair<int, std::string> (hand_book_numbers.size() + 1, name));
        hand_book_numbers.insert(std::pair<int, std::string> (hand_book_numbers.size() + 1, number));
    }
    hand_book_names.insert(std::pair<int, std::string> (hand_book_numbers.size() + 1, "Danila"));
    hand_book_numbers.insert(std::pair<int, std::string> (hand_book_numbers.size() + 1, "33-44-55"));
    hand_book_names.insert(std::pair<int, std::string> (hand_book_numbers.size() + 1, "Zab"));
    hand_book_numbers.insert(std::pair<int, std::string> (hand_book_numbers.size() + 1, "33-44-56"));


    if(name == "")
    {
        for(std::map<int, std::string>::iterator it = hand_book_numbers.begin(); it != hand_book_names.end() or it -> second <= number; it++)
        {
            if(it -> second == number)
                std::cout << hand_book_names[it->first];
        }
    }
    if(number == "")
    {
        for(std::map<int, std::string>::iterator it = hand_book_names.begin(); it != hand_book_names.end(); it++)
        {
            if(it->second == name)
            {
                std::cout << hand_book_numbers[it -> first] << " ";
            }
        }
    }
}