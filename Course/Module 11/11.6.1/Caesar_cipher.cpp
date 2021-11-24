#include <iostream>

bool character (char x)
{
    return x >= 'a' and x <= 'z' or x >= 'A' and x <= 'Z' ? true : false;
}

std::string encrypt_plus(std::string str, int countPosition, std::string new_str)
{
    for (int i=0; i < str.length(); i++)
    {
        if (character(str[i])){ 
            if (str[i] >= 'a' and str[i] <= 'z')
            {
                if (str[i] + countPosition <= 'z')
                    new_str += str[i] + countPosition;
                else 
                    new_str += 'a' + countPosition - ('z' - str[i]) - 1;
            }
            else 
            {
                if (str[i] + countPosition <= 'Z')
                    new_str += str[i] + countPosition;
                else 
                    new_str += 'A' + countPosition - ('Z' - str[i]) - 1;
            }
        }
        else 
            new_str += str[i];
    }
    return new_str;
}

std::string encrypt_minus(std::string str, int countPosition, std::string new_str)
{
    for (int i=0; i < str.length(); i++)
    {
        if (character(str[i])){
            if (str[i] >= 'a' and str[i] <= 'z')
            {
                if (str[i] + countPosition >= 'a')
                    new_str += str[i] + countPosition;
                else
                    new_str += 'z' + countPosition + (str[i] - 'a') + 1;
            }
            else 
            {
                if (str[i] + countPosition >= 'A')
                    new_str += str[i] + countPosition;
                else
                    new_str += 'Z' + countPosition + (str[i] - 'A') + 1;
            }
        }
        else
            new_str += str[i];
    }
    return new_str;
}

std::string encrypt_caesar(std::string str, int countPosition)
{
    std::string new_str;
    if (countPosition>0) 
        return encrypt_plus(str, countPosition, new_str);
    else 
        return encrypt_minus(str, countPosition, new_str);
}

std::string decrypt_plus(std::string str, int countPosition, std::string new_str)
{
    for (int i=0; i < new_str.length(); i++)
    {
        if (character(new_str[i])){
            if (new_str[i] >= 'a' and new_str[i] <= 'z')
            {
                if (new_str[i] - countPosition >= 'a')
                    str += new_str[i] - countPosition;
                else
                    str += 'z' - countPosition + (new_str[i] - 'a') + 1;
            }
            else 
                if (new_str[i] - countPosition >= 'A')
                    str += new_str[i] - countPosition;
                else
                    str += 'Z' - countPosition + (new_str[i] - 'A') + 1;
        }
        else 
            str += new_str[i];
    }
    return str;
}

std::string decrypt_minus(std::string str, int countPosition, std::string new_str)
{
    for (int i=0; i < new_str.length(); i++)
    {
        if (character(new_str[i])){
            if (new_str[i] >= 'a' and new_str[i] <= 'z')
            {
                if (new_str[i] - countPosition <= 'z')
                    str += new_str[i] - countPosition;
                else
                    str += 'a' - countPosition - ('z' - new_str[i]) - 1;
            }
            else 
            {
                if (new_str[i] - countPosition <= 'Z')
                    str += new_str[i] -countPosition;
                else
                    str += 'A' - countPosition - ('Z' - new_str[i]) - 1;
            }
        }
        else 
            str += new_str[i];
    }
    return str;
}

std::string decrypt_caesar(std::string new_str, int countPosition) 
{
    std::string str;
    if (countPosition>0) 
        return decrypt_plus(str, countPosition, new_str);
    else 
        return decrypt_minus(str, countPosition, new_str);
}

int main()
{
    std::string str;
    std::cout << "Input text:\n";
    std::getline(std::cin, str);
    
    int countPosition;
    std::cout << "Input number of positions to shift:\n";
    std::cin >> countPosition;

    std::string new_str = encrypt_caesar(str, countPosition);
    std::cout << "Encrypted text:\n";
    std::cout << new_str<< std::endl;

    std::cout << "Decrypted text:\n";
    std::cout << decrypt_caesar(new_str, countPosition);
}