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
public:
    double radius{};
    double pi = 3.141592;
    double getFigureArea()
    {
        return pi * radius * radius;
    };
    double upFigureArea()
    {
        return pow(2 * radius, 2);
    };
};

class Triangle : Figure
{
public:
    double ribLength{};
    double p = (ribLength * 3) / 2;
    double getFigureArea()
    {
        return sqrt(p * pow((p - ribLength), 3));
    };
    double upFigureArea()
    {
        return pow(2 * sqrt(p * pow((p - ribLength), 3)) / ribLength, 2);
    };
};

class Square : Figure
{
public:
    double ribLength{};
    double getFigureArea()
    {
        return ribLength * ribLength;
    };
    double upFigureArea()
    {
        return ribLength * ribLength;
    };
};

class Rectangle : Figure
{
public:
    double height{};
    double weight{};
    double getFigureArea()
    {
        return weight * height;
    };
    double upFigureArea()
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
        std::cin >> circle -> radius;
        std::cout << "Area of circle : ";
        std::cout << circle ->getFigureArea() << std::endl;
        std::cout << "Area of rectangle around circle: ";
        std::cout << circle ->upFigureArea();
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
        std::cin >> triangle -> ribLength;
        std::cout << "Area of triangle : ";
        std::cout << triangle ->getFigureArea() << std::endl;
        std::cout << "Area of rectangle around triangle: ";
        std::cout << triangle ->upFigureArea();
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
        std::cin >> square -> ribLength;
        std::cout << "Area of square : ";
        std::cout << square ->getFigureArea() << std::endl;
        std::cout << "Area of rectangle around square: ";
        std::cout << square ->upFigureArea();
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
        std::cin >> rectangle -> height;
        std::cout << "Input a weight of rectangle:" << std::endl;
        std::cin >> rectangle -> weight;
        std::cout << "Area of square : ";
        std::cout << rectangle ->getFigureArea() << std::endl;
        std::cout << "Area of rectangle around rectangle: ";
        std::cout << rectangle ->upFigureArea();
        delete rectangle;
    }
    delete figure;
}
