#include <iostream>
#include <sstream>

bool compare(float speed, float epsilon)
{
    bool ok = (speed - epsilon > 0) and (speed + epsilon > 0);
    return ok;
}

int main()
{
    float speed = 0;
    float delta;
    double epsilon = 0.01;
    std::stringstream str;

    std::cout << "Input speed delta: " << std::endl;
    std::cin >> delta;

    speed += delta;
    if ((speed - epsilon > 150) and (speed + epsilon > 150))
            {
                speed = 150;
                std::cout << "You reached maximum speed! " << std::endl;
            }

    str << speed << " km/h";
    std::cout << str.str() << std::endl;
    
    while (compare(speed, epsilon))
    {
        str.str("");

        std::cout << "Input speed delta: " << std::endl;
        std::cin >> delta;
        
        speed += delta;

        if ((speed - epsilon > 150) and (speed + epsilon > 150))
            {
                speed = 150;
                std::cout << "You reached maximum speed! " << std::endl;
            }
        if (!compare(speed, epsilon))
            {
                speed = 0;
                std::cout << "You stoped" << std::endl;
            }
        str << speed << " km/h";
        std::cout << str.str() << std::endl;
    }
}

