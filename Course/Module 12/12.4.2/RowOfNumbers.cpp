#include <iostream>

int main()
{
    int numbers[15] = {114,111, 106, 107, 108, 105, 115,  108, 110, 109, 112, 113, 116, 117, 118};
    int min = MAX_INT;
    int Sum1 = 0;
    for (int i = 0; i < 15; i++)
    {
        //std::cout << "Input number:\n";
        //std::cin >> numbers[i];
        if (numbers[i] < min)
            min = numbers[i];
        Sum1 += numbers[i];
    }

    int Sum2 = (min + min + 13) * 14 / 2;

    std::cout << "Number "<< Sum1 - Sum2 <<" reapeated."<< std::endl;
}
