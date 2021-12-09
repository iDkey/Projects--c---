#include <iostream>
#include <map> 
#include <string>

bool check_anagram(std::string& word, std::string& anagram)
{
    std::map<char, int> word_map;
    for(int i = 0; i < word.size(); ++i)
    {
        if(word_map.count(word[i]) == 0)
        {
            word_map.insert(std::pair<char, int> (word[i], 1));
        }
        else
        {
            std::map<char, int>::iterator it = word_map.find(word[i]);
            it -> second += 1;
        }
    }
    for(int i = 0; i < anagram.size(); ++i)
    {
        if(word_map.count(anagram[i]) > 0)
        {
            std::map<char, int>::iterator it = word_map.find(anagram[i]);
            if(it -> second > 0)
            {
                it -> second -= 1;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    for(std::map<char, int>::iterator it = word_map.begin(); it != word_map.end(); it++)
    {
        if(it->second != 0)
            return false;
    }
    return true;
}

int main()
{
    std::string word;
    std::cout << "Input a start word:" << std::endl;
    std::cin >> word;

    std::string anagram;
    std::cout << "Include an anagram:" << std::endl;
    std::cin >> anagram;

    (check_anagram(word, anagram) ? std::cout << "This is a anagram." << std::endl : std::cout << "This is not an anagram." << std::endl);
}