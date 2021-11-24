#include <iostream>
#include <fstream>

void search(std::string* need_word)
{
    std::ifstream words;
    words.open("A:\\Programs\\Projects (c++)\\Course\\Module 19\\Task 1\\words.txt");

    int count = 0;
    while(!words.eof())
    {
        std::string word;
        words >> word;

        if (word == *need_word)
        count++;
    }
    std::cout << "Word " << *need_word << " met " << count << " times" << std::endl;
    words.close();
}

int main()
{
    std::string need_word;
    std::cin >> need_word;
    search(&need_word);
}