#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream image;
    std::string path;
    std::cout << "Input" << std::endl;
    getline(std::cin, path);
    //A:\\Programs\\Projects (c++)\\Course\\Module 19\\Task 4\\image.png
    //A:\\Programs\\Projects (c++)\\Course\\Module 19\\Task 3\\file.txt
    if (path.substr(path.length() - 3, path.length()) == "png")
    {
        image.open(path, std::ios::binary);
        char f_bite[1];
        image.read(f_bite, sizeof(f_bite));
        if (f_bite[0] == -119)
            std::cout << "It's a png file" << std::endl;
        else
            std::cout << "It's not a png file" << std::endl;
        image.close();
    }
    else
        std::cout << "It's not a png file" << std::endl;
}