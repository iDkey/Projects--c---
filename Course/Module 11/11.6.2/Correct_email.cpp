#include <iostream>

void output(bool okLeft, bool okRight)
{
    std::cout << (okLeft * okRight == 1 ? "Yes\n" : "No\n");
}

bool checkLeft (std::string left)
{
    bool ok;
    std::string chars = "!#$%&'*+-/=?^_`{|}~";

    for (int i = 0; i < left.length(); i++)
    {
        bool in = false;
        
        for (int j=0; j < chars.length(); j++)
            if (left[i] == chars[j])
                in = true;
        if (in == true or left[i] >= 'A' and left[i] <= 'Z' or left[i] >= 'a' and left[i] <= 'z')
            ok = true;
        else 
            if (left[i] == '.' and left[i + 1] != '.' and i != 0 and i != left.length() - 1)
                ok = true;
            else
            {
                ok = false;
                break;
            }
    }
    return ok;
}

bool checkRight(std::string right)
{
    bool ok;

    for (int i = 0; i < right.length(); i++)
    {
        if (right[i] >= 'A' and right[i] <= 'Z' or right[i] >= 'a' and right[i] <= 'z')
            ok = true;
        else 
            if (right[i] == '-' or right[i] == '.' and right[i + 1] != '.'
                and i != 0 and i != right.length())
                ok = true;
            else
            {
                ok = false;
                break;
            }
    }
    return ok;
}

void separation(std::string email)
{
    std::string left, right;
    int a;
    bool x = false;

    for (int i=0; i < email.length(); i++)
    {
        if (email[i] == '@') 
        {
            a = i;
            x = true;
            break;
        }
        else 
            x = false;
    }
    for (int i = 0; i < email.length(); i++)
    {
        if (i < a)
            left += email[i];
        if (i > a)
            right += email[i];
    }
    
    if (x == true)
        output(checkLeft(left),checkLeft(right));
    else
        output(x, x);
}

int main(){
    std::string email;
    std::cout << "Input email:\n";
    std::cin >> email;

    separation(email);
}