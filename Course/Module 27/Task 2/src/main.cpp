#include <iostream>
#include <string>
#include <cmath>

class Figure {
public:
    double xCentre{};
    double yCentre{};
    std::string color;
};

class Circle : Figure
{
    double radius{};
    double pi = 3.141592;

public:
    void addRadius(double& inRadius)
    {
        radius = inRadius;
    }

    double getFigureArea()
    {
        return pi * radius * radius;
    };
    double getUpFigureArea()
    {
        return pow(2 * radius, 2);
    };
};

class Triangle : Figure
{
    double ribLength{};
    double p = (ribLength * 3) / 2;

public:
    void addRibLength(double& inRibLength)
    {
        ribLength = inRibLength;
    }

    double getFigureArea()
    {
        return sqrt(p * pow((p - ribLength), 3));
    };
    double getUpFigureArea()
    {
        return pow(2 * sqrt(p * pow((p - ribLength), 3)) / ribLength, 2);
    };
};

class Square : Figure
{
    double ribLength{};

public:
    void addRibLength(double& inRibLength)
    {
        ribLength = inRibLength;
    }

    double getFigureArea()
    {
        return ribLength * ribLength;
    };
    double getUpFigureArea()
    {
        return ribLength * ribLength;
    };
};

class Rectangle : Figure
{
    double height{};
    double weight{};

public:
    void addHeigth(double& inHeight)
    {
        height = inHeight;
    }
    void addWeigth(double& inWeigth)
    {
        weight = inWeigth;
    }

    double getFigureArea()
    {
        return weight * height;
    };
    double getUpFigureArea()
    {
        return weight * height;
    };
};

int main() {
    std::string needFigure;
    std::cout << "Input name of figure (rectangle, square, triangle, circle):" << std::endl;
    std::cin >> needFigure;
    auto* figure = new Figure();
    if(needFigure == "circle")
    {
        std::cout << "Input a centre coordinates:" << std::endl;
        std::cin >> figure -> xCentre;
        std::cin >> figure -> yCentre;
        std::cout << "Input a figure's color:" << std::endl;
        std::cin >> figure -> color;
        auto* circle = new Circle();
        std::cout << "Input a radius of circle:" << std::endl;
        double inRadius;
        std::cin >> inRadius;
        circle ->addRadius(inRadius);
        std::cout << "Area of circle : ";
        std::cout << circle ->getFigureArea() << std::endl;
        std::cout << "Area of rectangle around circle: ";
        std::cout << circle ->getUpFigureArea();
        delete circle;
    }
    if(needFigure == "triangle")
    {
        std::cout << "Input a centre coordinates:" << std::endl;
        std::cin >> figure -> xCentre;
        std::cin >> figure -> yCentre;
        std::cout << "Input a figure's color:" << std::endl;
        std::cin >> figure -> color;
        auto* triangle = new Triangle();
        std::cout << "Input a rib length of triangle:" << std::endl;
        double inRibLength;
        std::cin >> inRibLength;
        triangle ->addRibLength(inRibLength);
        std::cout << "Area of triangle : ";
        std::cout << triangle ->getFigureArea() << std::endl;
        std::cout << "Area of rectangle around triangle: ";
        std::cout << triangle ->getUpFigureArea();
        delete triangle;
    }
    if(needFigure == "square")
    {
        std::cout << "Input a centre coordinates:" << std::endl;
        std::cin >> figure -> xCentre;
        std::cin >> figure -> yCentre;
        std::cout << "Input a figure's color:" << std::endl;
        std::cin >> figure -> color;
        auto* square = new Square();
        std::cout << "Input a rib length of square:" << std::endl;
        double inRibLength;
        std::cin >> inRibLength;
        square ->addRibLength(inRibLength);
        std::cout << "Area of square : ";
        std::cout << square ->getFigureArea() << std::endl;
        std::cout << "Area of rectangle around square: ";
        std::cout << square ->getUpFigureArea();
        delete square;
    }
    if(needFigure == "rectangle")
    {
        std::cout << "Input a centre coordinates:" << std::endl;
        std::cin >> figure -> xCentre;
        std::cin >> figure -> yCentre;
        std::cout << "Input a figure's color:" << std::endl;
        std::cin >> figure -> color;
        auto* rectangle = new Rectangle();
        std::cout << "Input a height of rectangle:" << std::endl;
        double inHeigth;
        std::cin >> inHeigth;
        rectangle ->addHeigth(inHeigth);
        std::cout << "Input a weight of rectangle:" << std::endl;
        double inWeigth;
        std::cin >> inWeigth;
        rectangle ->addWeigth(inWeigth);
        std::cout << "Area of square : ";
        std::cout << rectangle ->getFigureArea() << std::endl;
        std::cout << "Area of rectangle around rectangle: ";
        std::cout << rectangle ->getUpFigureArea();
        delete rectangle;
    }
    delete figure;
}
