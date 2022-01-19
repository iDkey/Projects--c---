#include <iostream>
#include <string>
#include <cmath>

class Figure {
public:
    double xCentre{};
    double yCentre{};
    std::string color;
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

    double getFigureArea() const
    {
        return weight * height;
    };
    double getUpFigureArea() const
    {
        return weight * height;
    };
    Rectangle getRactangle()
    {
        return Rectangle();
    }
    Rectangle()
    {

    }
    Rectangle(double sideA, double sideB): height(sideA), weight(sideB)
    {

    }
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
    double getFigureArea() const
    {
        return pi * radius * radius;
    };
    Rectangle getRactangle()
    {
        Rectangle rectangle(radius * 2, radius * 2);
        return Rectangle();
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
    double getFigureArea() const
    {
        return sqrt(p * pow((p - ribLength), 3));
    };
    Rectangle getRactangle() const
    {
        Rectangle rectangle(sqrt(3 * ribLength * ribLength / 4), ribLength);
        return Rectangle();
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

    double getFigureArea() const
    {
        return ribLength * ribLength;
    };
    Rectangle getRactangle()
    {
        Rectangle rectangle(ribLength, ribLength);
        return Rectangle();
    };
};

void getGeneralData(Figure* figure)
{
    std::cout << "Input a centre coordinates:" << std::endl;
    std::cin >> figure -> xCentre;
    std::cin >> figure -> yCentre;
    std::cout << "Input a figure's color:" << std::endl;
    std::cin >> figure -> color;
}

int main() {
    std::string needFigure;
    std::cout << "Input name of figure (rectangle, square, triangle, circle):" << std::endl;
    std::cin >> needFigure;
    auto* figure = new Figure();
    if(needFigure == "circle")
    {
        getGeneralData(figure);
        auto* circle = new Circle();
        std::cout << "Input a radius of circle:" << std::endl;
        double inRadius;
        std::cin >> inRadius;
        circle ->addRadius(inRadius);
        std::cout << "Area of circle : ";
        std::cout << circle ->getFigureArea() << std::endl;
        delete circle;
    }
    if(needFigure == "triangle")
    {
        getGeneralData(figure);
        auto* triangle = new Triangle();
        std::cout << "Input a rib length of triangle:" << std::endl;
        double inRibLength;
        std::cin >> inRibLength;
        triangle ->addRibLength(inRibLength);
        std::cout << "Area of triangle : ";
        std::cout << triangle ->getFigureArea() << std::endl;
        delete triangle;
    }
    if(needFigure == "square")
    {
        getGeneralData(figure);
        auto* square = new Square();
        std::cout << "Input a rib length of square:" << std::endl;
        double inRibLength;
        std::cin >> inRibLength;
        square ->addRibLength(inRibLength);
        std::cout << "Area of square : ";
        std::cout << square ->getFigureArea() << std::endl;
        delete square;
    }
    if(needFigure == "rectangle")
    {
        getGeneralData(figure);
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
        delete rectangle;
    }
    delete figure;
}
