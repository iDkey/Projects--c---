#include "ValidateData.h"
#include <iostream>

bool checkData(std::string& log)
{
    int i = 0;
    bool flag = false;
    while(i < log.length())
    {
        if(log[i] >= 65 and log[i] <= 90 or log[i] >= 97 and log[i] <= 122)
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
        i++;
    }
    if(flag)
        return true;

    return false;
}

