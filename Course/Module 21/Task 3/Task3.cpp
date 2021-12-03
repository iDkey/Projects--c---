#include <iostream>
#include <vector>
#include <string>
#include <math.h>

struct vector
{
    float x1;
    float x2;
    float y1;
    float y2;
    float length_x;
    float length_y;
};

void adding()
{
    vector vec[2];
    for (int i = 0; i < 2; ++i)
    {
        std::cout << "Input x of begin for " << i + 1 << " vector:" << std::endl;
        std::cin >> vec[i].x1;
        std::cout << "Input y of begin for " << i + 1 << " vector:" << std::endl;
        std::cin >> vec[i].y1;
        std::cout << "Input x of end for " << i + 1 << " vector:" << std::endl;
        std::cin >> vec[i].x2;
        std::cout << "Input y of end for " << i + 1 << " vector:" << std::endl;
        std::cin >> vec[i].y2;
        vec[i].length_x = vec[i].x2 - vec[i].x1;
        vec[i].length_y = vec[i].y2 - vec[i].y1;
    }
    std::cout << "Summ of this vectors:";
    std::cout << "{" << vec[0].length_x + vec[1].length_x << ";" << vec[0].length_y + vec[1].length_y << "}" << std::endl;
}

void substracting()
{
    vector vec[2];
    for (int i = 0; i < 2; ++i)
    {
        std::cout << "Input x of begin for " << i + 1 << " vector:" << std::endl;
        std::cin >> vec[i].x1;
        std::cout << "Input y of begin for " << i + 1 << " vector:" << std::endl;
        std::cin >> vec[i].y1;
        std::cout << "Input x of end for " << i + 1 << " vector:" << std::endl;
        std::cin >> vec[i].x2;
        std::cout << "Input y of end for " << i + 1 << " vector:" << std::endl;
        std::cin >> vec[i].y2;
        vec[i].length_x = vec[i].x2 - vec[i].x1;
        vec[i].length_y = vec[i].y2 - vec[i].y1;
    }
    std::cout << "Substract of this vectors:";
    std::cout << "{" << vec[0].length_x - vec[1].length_x << ";" << vec[0].length_y - vec[1].length_y << "}" << std::endl;
}

void on_scale()
{
    vector vec;
    std::cout << "Input x of begin for vector:" << std::endl;
    std::cin >> vec.x1;
    std::cout << "Input y of begin for vector:" << std::endl;
    std::cin >> vec.y1;
    std::cout << "Input x of end for vector:" << std::endl;
    std::cin >> vec.x2;
    std::cout << "Input y of end for vector:" << std::endl;
    std::cin >> vec.y2;
    vec.length_x = vec.x2 - vec.x1;
    vec.length_y = vec.y2 - vec.y1;
    float scalar;
    std::cout << "Input scalar:";
    std::cin >> scalar;
    std::cout << "Result vector:" << std::endl;
    std::cout << "{" << vec.length_x * scalar << ";" << vec.length_y * scalar << "}";
}

float length()
{
    vector vec;
    std::cout << "Input x of begin for vector:" << std::endl;
    std::cin >> vec.x1;
    std::cout << "Input y of begin for vector:" << std::endl;
    std::cin >> vec.y1;
    std::cout << "Input x of end for vector:" << std::endl;
    std::cin >> vec.x2;
    std::cout << "Input y of end for vector:" << std::endl;
    std::cin >> vec.y2;
    vec.length_x = vec.x2 - vec.x1;
    vec.length_y = vec.y2 - vec.y1;
    return sqrt(pow(vec.length_x, 2) + pow(vec.length_y, 2));
}

void normalizing()
{
    vector vec;
    std::cout << "Input x of begin for vector:" << std::endl;
    std::cin >> vec.x1;
    std::cout << "Input y of begin for vector:" << std::endl;
    std::cin >> vec.y1;
    std::cout << "Input x of end for vector:" << std::endl;
    std::cin >> vec.x2;
    std::cout << "Input y of end for vector:" << std::endl;
    std::cin >> vec.y2;
    vec.length_x = vec.x2 - vec.x1;
    vec.length_y = vec.y2 - vec.y1;
    std::cout << "Normalized vector:" << std::endl;
    std::cout << "{" << vec.length_x / sqrt(pow(vec.length_x, 2) + pow(vec.length_y, 2)) << ";" << vec.length_y / sqrt(pow(vec.length_x, 2) + pow(vec.length_y, 2)) << "}";
}

int main()
{
    std::cout << "Avaible commands:" << std::endl;
    std::cout << "Adding two vectors (add)" << std::endl;
    std::cout << "Subtracting two vectors (substract)" << std::endl;
    std::cout << "Multiplying a vector by a scalar (scale)" << std::endl;
    std::cout << "Finding the length of a vector (length)" << std::endl;
    std::cout << "Vector normalization (normalize)" << std::endl;
    std::cout << "Choose the operation:" << std::endl;

    std::string command;
    std::cin >> command;

    if (command == "add")
    {
        adding();
    }
    if (command == "substract")
    {
        substracting();
    }
    if (command == "scale")
    {
        on_scale();
    }
    if (command == "length")
    {
        float result = length();
        std::cout << "Length of vector:" << std::endl;
        std::cout << result << std::endl;
    }
    if (command == "normalize")
    {
        normalizing();
    }
}