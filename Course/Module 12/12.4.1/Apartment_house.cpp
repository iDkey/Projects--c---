#include <iostream>

int main()
{
    std::string surnames[10];

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Input surname of the tenant:\n";
        std::cin >> surnames[i];
    }

    for (int i = 0; i < 3; i++)
    {
        int apartment;
        std::cout << "Input apartment number:\n";
        std::cin >> apartment;
        if (apartment > surnames->length() or apartment < 1)
            std::cout << "Еhere isn't such apartment in this house\n";
        else
            std::cout << "In apartment number "<< apartment << " is living "<<surnames[apartment - 1]<< std::endl; 
    }
}