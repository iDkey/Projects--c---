#include <iostream>
#include <vector>
#include <string>

struct Rectangle
{
    int xLeft = 0;
    int yLeft = 0;
    int xRight = 0;
    int yRight = 0;

};

Rectangle convertToInt(std::string& str ,Rectangle rectangle)
{
    int countSpace = 0;
    std::string substr = "";
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == ' ')
        {

            if(countSpace == 0)
            {
                rectangle.xLeft = std::atoi(substr.c_str());
            }
            if(countSpace == 1)
            {
                rectangle.yLeft = std::atoi(substr.c_str());
            }
            if(countSpace == 2)
            {
                rectangle.xRight = std::atoi(substr.c_str());
            }
            substr = "";
            countSpace++;
        }
        else
        {
            substr += str[i];
        }

    }
    rectangle.yRight = std::atoi(substr.c_str());
    return rectangle;
}

int main() {
    int countRectangles = 0;
    std::cin >> countRectangles;

    Rectangle rectangle;
    std::vector<Rectangle> masRect;
    std::string str = "";
    std::cin.ignore();
    for(int i = 0; i < countRectangles; ++i)
    {
        getline(std::cin, str);
        masRect.push_back(convertToInt(str, rectangle));
    }

    int intersections[countRectangles];
    for (int i = 0; i < countRectangles; ++i)
    {
        intersections[i] = 0;
    }

    for(int i = 0; i < countRectangles; ++i)
    {
        for(int j = 0; j < countRectangles; ++j)
        {
            if(i != j)
            {


                if(((masRect[i].xLeft > masRect[j].xLeft and masRect[i].xLeft < masRect[j].xRight)
                    or (masRect[i].xRight > masRect[j].xLeft and masRect[i].xRight < masRect[j].xRight))
                    and ((masRect[i].yLeft > masRect[j].yLeft and masRect[i].yLeft < masRect[j].yRight)
                    or (masRect[i].yRight > masRect[j].yLeft and masRect[i].yRight < masRect[j].yRight))
                    or ((masRect[i].xLeft < masRect[j].xLeft and masRect[j].xLeft < masRect[i].xRight)
                    or (masRect[i].xLeft < masRect[j].xRight and masRect[j].xRight < masRect[i].xRight))
                    and ((masRect[i].yLeft < masRect[j].yLeft and masRect[j].yLeft < masRect[i].yRight)
                    or (masRect[i].yLeft < masRect[j].yRight and masRect[j].yRight < masRect[i].yRight))
                    or ((masRect[i].xLeft == masRect[j].xLeft) and ((masRect[i].yLeft > masRect[j].yLeft
                    and masRect[j].yLeft < masRect[i].yRight) or (masRect[i].yLeft < masRect[j].yLeft
                    and masRect[j].yLeft < masRect[i].yRight))) or ((masRect[i].yLeft == masRect[j].yLeft)
                    and ((masRect[i].xLeft > masRect[j].xLeft and masRect[j].xLeft < masRect[i].xRight)
                    or (masRect[i].xLeft < masRect[j].xLeft and masRect[j].xLeft < masRect[i].xRight))))
                intersections[i]++;
            }
        }
    }
    for (int i = 0; i < countRectangles; ++i)
    {
        std::cout << intersections[i] << " ";
    }
}
