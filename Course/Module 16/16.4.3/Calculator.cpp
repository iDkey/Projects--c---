#include <iostream>
#include <cmath>

int main()
{
    std::string str;
    std::cin >> str;

    bool sign_found = false;
    char sign;
    std::string left_num, right_num;
    for (int i = 0; !sign_found; i++)
    {
        if (str[i] == '+' or str[i] == '-' or str[i] == '*' or str[i] == '/')
        {
            for (int j = 0; j < i; j++)
            {
                left_num += str[j];
            }
            for (int j = i + 1; j < str.length(); j++)
            {
                right_num += str[j];
            }
            sign = str[i];
            sign_found = true;
        }
    }

    double num1 = std::stod(left_num);
    double num2 = std::stod(right_num);

    switch (sign)
    {
    case '+':
        std::printf("%.4f", num1 + num2);
        break;
    
    case '-':
        std::printf("%.4f", num1 - num2);
        break;
    
    case '*':
        std::printf("%.4f", num1 * num2);
        break;
    
    case '/':
        std::printf("%.4f", num1 / num2);
        break;
    
    default:
        break;
    }
}