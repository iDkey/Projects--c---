#include <iostream>

bool substr(const char* a,const char* s_str)
{
    bool in = false;
    for (int i = 0; *(a + i) != '\0'; ++i)
    {
        for (int j = 0; *(s_str + j) != '\0'; ++j)
        {
            if (*(a + i + j) == *(s_str + j))
            in = true;
            else
                break;
        }
    }
    return in;
}

int main()
{
    const char* a = "Hello world";

    const char* b = "wor";

    const char* c = "banana";

    if (substr(a, b))
        std::cout << "String b is in string a" << std::endl;
    else
        std::cout << "String b is not in string a" << std::endl;
    if (substr(a, c))
        std::cout << "String c is in string a" << std::endl;
    else
        std::cout << "String c is not in string a" << std::endl;
}