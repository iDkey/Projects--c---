#include <iostream>
#include <cmath>

void output(bool ok)
{
    std::cout << (ok ? "Yes" : "No");
}

int converting_to_int(std::string octade)
{
    int octade_int;

    for (int i = 0, j = pow(10, octade.length()-1); i < octade.length(); i++, j/=10)
    {
        octade_int += (j * (octade[i] - '0'));
    }
    return octade_int;
}

bool check(std::string octade)
{
    bool ok = true;
    for (int i = 0; i < octade.length(); i++)
    {
        if (octade[i] < '0' or octade[i] > '9')
            ok = false;
        else
            if (octade[i] == '0' and i == 0 and octade.length() > 1)
                ok = false;
    }
    return ok;
}

void separate(std::string IP)
{
    int dot = 0;
    bool ok = true;
    int point1, point2, point3;

    for (int i = 0; i < IP.length(); i++)
    {
        if (IP[i] == '.')
        {
            dot++;

            if (dot == 1)
                point1 = i;
            if (dot == 2)
                point2 = i;
            if (dot == 3)
                point3 = i;
        }
    }

    std::string octade1, octade2, octade3, octade4;
    if (dot > 3 or point2 - point1 == 1 or point3 - point2 == 1)
        output(!ok);
    else 
    {
        for (int i = 0; i < IP.length(); i++)
        {
            if (i < point1)
                octade1 += IP[i];
            if (i < point2 and i > point1)
                octade2 += IP[i];
            if (i < point3 and i > point2)
                octade3 += IP[i];
            if (i > point3)
                octade4 += IP[i];
        }
    
        bool ok_octade1 = check(octade1), ok_octade2 = check(octade2);
        bool ok_octade3 = check(octade3), ok_octade4 = check(octade4);
        if (ok_octade1 and ok_octade2 and ok_octade3 and ok_octade4)
        {
            int octade1_int = converting_to_int(octade1), octade2_int = converting_to_int(octade2);
            int octade3_int = converting_to_int(octade3), octade4_int = converting_to_int(octade4);
            if (octade1_int > 255 or octade2_int > 255 or octade3_int > 255 or octade4_int > 255)
                output(!ok);
            else
                output(ok);
        }
        else
            output(!ok);
    }

}

int main()
{
    std::string IP;
    std::cout << "Input IP:\n";
    std::cin >> IP;

    separate(IP);
}