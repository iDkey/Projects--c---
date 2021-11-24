#include <iostream>
#include <cmath>

void output(float num1_float, float num2_float)
{
    if (num1_float == num2_float)
        std::cout << "Equal\n";
    if (num1_float > num2_float)
        std::cout << "More\n";
    if (num1_float < num2_float) 
        std::cout << "Less\n";
}

void outputError()
{
    std::cout << "Wrong input data\n";
}

bool check(std::string line)
{
    bool ok = true;
    int dot = 0;
    int countSigns = 0;

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] < '0' and line[i] > '9' and line[i] != '.' and line[i] != '-')
        {
            ok = false;
            break;
        }
        else
        {
            if (line[i] != '.' and dot == 0)
                dot++;
            else 
                if (line[i] != '-' and countSigns == 0)
                    countSigns++;
        }
    }
    return ok;
}

float converting (std::string num)
{   
    float num_float = 0;
    int dot = 0;
    float j = 1;
    
    for (int i = 0; i < num.length(); i++)
        if (num[i] == '.')
            dot = i;

    if (dot == 1)
    {
        if (num[0] == '-')
        {
            for (int i = 1; i < num.length(); i++, round(j/=10))
            {
                if (num[i] >= '0' and num[i] <= '9')
                    num_float += j * (num[i] - '0');
                else 
                    j *=10; 
            }
            num_float = -num_float;
        }
        else
        {    
            for (int i = 0; i < num.length(); i++, round(j/=10))
            {
                if (num[i] >= '0' and num[i] <= '9')
                    num_float += j * float((num[i] - '0'));
                else
                    j *=10; 
            }
        }
    }
    else
        if (dot != 0)
        {
            if (num[0] == '-')
            {
                for (int i = 1, j = pow(10, dot); i < num.length(); i++, round(j/=10))
                {
                    if (num[i] >= '0' and num[i] <= '9')
                        num_float += j * (num[i] - '0');
                    else 
                        j *=10; 
                }
                num_float = -num_float;
            }
            else
            {
                j = pow(10, dot - 1);
                for (int i = 0; i < num.length(); i++, j /= 10)
                {
                    if (num[i] >= '0' and num[i] <= '9' )
                        num_float += j * float((num[i] - '0'));
                    else 
                        j *=10;
                }
            }
        }
        else 
            if (num[0] == '-')
            {   
                if (num.length() > 2)
                for (int i = 1, j = pow(10, num.length() - 1); i < num.length() - 1; i++, round(j/=10))
                {
                    if (num[i] >= '0' and num[i] <= '9')
                        num_float += j * (num[i] - '0');
                }
                else 
                    for (int i = 1, j = 1; i < num.length(); i++, round(j/=10))
                    {
                        if (num[i] >= '0' and num[i] <= '9')
                            num_float += j * (num[i] - '0');
                    }
                num_float = -num_float;
            }
            else
            {
                if (num.length() > 1)
                for (int i = 0, j = pow(10, num.length() - 1); i < num.length(); i++, round(j/=10))
                {
                    if (num[i] >= '0' and num[i] <= '9')
                        num_float += j * (num[i] - '0');
                }
                else 
                    for (int i = 0, j = 1; i < num.length(); i++, round(j/=10))
                    {
                        if (num[i] >= '0' and num[i] <= '9')
                            num_float += j * (num[i] - '0');
                    }
            }
    
    return num_float;
}

int main() {
    std::string num1, num2;
    std::cout << "Input number 1:\n";
    std::cin >> num1;
    std::cout << "Input number 2:\n";
    std::cin >> num2;
    int countNumbers = 0;
    int countSign = 0;
    int points = 0;

    bool ok1 = check(num1);
    bool ok2 = check(num2);

    if (ok1 and ok2)
    {
        float num1_float = converting(num1);
        float num2_float = converting(num2);
        output(num1_float, num2_float);
    }
    else
        outputError();
}