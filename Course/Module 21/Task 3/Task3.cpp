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
};

void get_coordinates(vector& vec)
{
    std::cout << "Input x of begin vector:" << std::endl;
    std::cin >> vec.x1;
    std::cout << "Input y of begin vector:" << std::endl;
    std::cin >> vec.y1;
    std::cout << "Input x of end for vector:" << std::endl;
    std::cin >> vec.x2;
    std::cout << "Input y of end for vector:" << std::endl;
    std::cin >> vec.y2;
}

int get_length(float n1, float n2)
{
    return n2 - n1;
}

void adding()
{
    vector vec[2];
    float length_x[2];
    float length_y[2];
    for (int i = 0; i < 2; ++i)
    {
        get_coordinates(vec[i]);
        length_x[i] = get_length(vec[i].x2, vec[i].x1);
        length_y[i] = get_length(vec[i].y2, vec[i].y1);
    }
    std::cout << "Summ of this vectors:";
    std::cout << "{" << length_x[0] + length_x[1] << ";" << length_y[0] + length_y[1] << "}" << std::endl;
}

void substracting()
{
    vector vec[2];
    float length_x[2];
    float length_y[2];
    for (int i = 0; i < 2; ++i)
    {
        get_coordinates(vec[i]);
        length_x[i] = get_length(vec[i].x2, vec[i].x1);
        length_y[i] = get_length(vec[i].y2 , vec[i].y1);
    }
    std::cout << "Substract of this vectors:";
    std::cout << "{" << length_x[0] - length_x[1] << ";" << length_y[0] - length_y[1] << "}" << std::endl;
}

void on_scale()
{
    vector vec;
    get_coordinates(vec);
    float length_x = get_length(vec.x2, vec.x1);
    float length_y = get_length(vec.y2 , vec.y1);
    float scalar;
    std::cout << "Input scalar:";
    std::cin >> scalar;
    std::cout << "Result vector:" << std::endl;
    std::cout << "{" << length_x * scalar << ";" << length_y * scalar << "}";
}

float length()
{
    vector vec;
    get_coordinates(vec);
    float length_x = get_length(vec.x2 , vec.x1);;
    float length_y = get_length(vec.y2 , vec.y1);
    return sqrt(pow(length_x, 2) + pow(length_y, 2));
}

void normalizing()
{
    vector vec;
    get_coordinates(vec);
    float length_x = vec.x2 - vec.x1;
    float length_y = vec.y2 - vec.y1;
    std::cout << "Normalized vector:" << std::endl;
    std::cout << "{" << length_x / sqrt(pow(length_x, 2) + pow(length_y, 2)) << ";" << length_y / sqrt(pow(length_x, 2) + pow(length_y, 2)) << "}";
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