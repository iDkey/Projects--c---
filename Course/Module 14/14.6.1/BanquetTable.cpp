#include <iostream>

int main()
{
    int VIP1, VIP2;
    while (1)
    {
        std::cin >> VIP1 >> VIP2;
        if (abs(VIP1 - VIP2) == 1 and (VIP1 == 1 or VIP1 == 2 or VIP1 >= 5 and VIP1 <= 8 
            or VIP1 == 11 or VIP1 == 12))
            break;
        else
            std::cout << "!";
    }

    int number_of_cutlery[2][6];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == 0 and (j == VIP1 - 1 or j == VIP2 - 1)
                or i == 1 and (j + 6 == VIP1 - 1 or j + 6 == VIP2 - 1))
                number_of_cutlery[i][j] = 4;
            else
                number_of_cutlery[i][j] = 3;
        }
    }

    int number_of_plates[2][6];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == 0 and (j == VIP1 - 1 or j == VIP2 - 1)
                or i == 1 and (j + 6 == VIP1 - 1 or j + 6 == VIP2 - 1))
                number_of_plates[i][j] = 3;
            else
                
                number_of_plates[i][j] = 2;
        }
    }

    int number_of_chairs[2][6];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            number_of_chairs[i][j] = 1;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == 0)
            {
                std::cout << "for " << j + 1 << " place:" << std::endl;
                std::cout << "Cutlery " << number_of_cutlery[i][j] << std::endl;
                std::cout << "Plates " << number_of_plates[i][j] << std::endl;
                std::cout << "Chairs " << number_of_chairs[i][j] << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "for " << j + 7 << " place:" << std::endl;
                std::cout << "Cutlery " << number_of_cutlery[i][j] << std::endl;
                std::cout << "Plates " << number_of_plates[i][j] << std::endl;
                std::cout << "Chairs " << number_of_chairs[i][j] << std::endl;
                std::cout << std::endl;
            }
        }
    }

    std::cout << "Incident:" << std::endl;
    std::cout << "Add 1 chair for 5 place and remove 1 plate from 3 place:";
    std::cout << std::endl;
    number_of_chairs[0][4] += 1;
    if (VIP1 <= 6)
        number_of_plates[0][VIP1 - 1] -= 1;
    else 
        number_of_plates[1][VIP1 - 7] -= 1;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == 0)
            {
                std::cout << "for " << j + 1 << " place:" << std::endl;
                std::cout << "Cutlery " << number_of_cutlery[i][j] << std::endl;
                std::cout << "Plates " << number_of_plates[i][j] << std::endl;
                std::cout << "Chairs " << number_of_chairs[i][j] << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "for " << j + 7 << " place:" << std::endl;
                std::cout << "Cutlery " << number_of_cutlery[i][j] << std::endl;
                std::cout << "Plates " << number_of_plates[i][j] << std::endl;
                std::cout << "Chairs " << number_of_chairs[i][j] << std::endl;
                std::cout << std::endl;
            }
        }
    }
}