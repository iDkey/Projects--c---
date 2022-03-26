#include <iostream>
#include <vector>

struct Rectangle
{
    int xLeft = 0;
    int yLeft = 0;
    int xRight = 0;
    int yRight = 0;
};

bool checkInside(Rectangle& rect1, Rectangle& rect2, int resultMas[], const int countRect)
{
    if(rect1.xLeft < rect2.xLeft and rect1.yLeft < rect2.yLeft
        and rect1.xRight > rect2.xRight and rect1.yRight > rect2.yRight)
        return true;
    else
        return false;
}

bool checkTop(Rectangle& rect,int (&resultMas)[])
{

}

bool checkRight(Rectangle& rect,int (&resultMas)[])
{

}

bool checkBottom(Rectangle& rect,int (&resultMas)[])
{

}

bool checkLeft(Rectangle& rect,int (&resultMas)[])
{

}

int main() {
    int countRect = 0;
    std::cout << "Input count of rectangles:" << std::endl;
    std::cin >> countRect;
    std::vector<Rectangle> rectVec;

    /*int result[countRect];
    for(int i = 0; i < countRect; ++i)
    {
        result[i] = 0;
    }*/

    int x1[8] = {-4,-3, -6, -6, 1, 1, -2, -7};
    int y1[8] = {-4, -3, -5, 1, 1, -1, -6, -2};
    int x2[8] = {4, 3, 1, -1, 6, 6, 2, 7};
    int y2[8] = {4, 3, 1, 5, 5, -5, 6, 2};
    for(int i = 0; i < rectVec.size(); ++i)
    {
        Rectangle rect;
        //std::cout << "Input coordinates:" << std::endl;
        //std::cin >> rect.xLeft >> rect.yLeft >> rect.xRight >> rect.yRight;
        rect.xLeft = x1[i];
        rect.yLeft = y1[i];
        rect.xRight = x2[i];
        rect.yRight = y2[i];
        rectVec.push_back(rect);
    }

    /*for(int i = 0; i < rectVec.size(); i++)
    {
        for(int j = 0; j < rectVec.size(); j++)
        {
            if(i != j)
            {
                if(checkInside(rectVec[i], rectVec[j], result,countRect))
                    result[i]++;
            }
        }
    }
    for(auto i : result)
        std::cout << i << " ";*/
    //output coord;
    for(int i = 0; i < rectVec.size(); ++i)
    {
        //std::cout << "Input coordinates:" << std::endl;
        std::cout << i + 1 << " (" << rectVec[i].xLeft << ", " << rectVec[i].yLeft << ") (" << rectVec[i].xRight << ", " << rectVec[i].yRight << ")" << std::endl;
    }

}
