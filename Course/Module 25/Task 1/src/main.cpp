#include <iostream>
#include <string>
#include <vector>
#include "functions.h"

struct str
{
    std::string name_action;
    double x1;
    double y1;
    double x2;
    double y2;
};

void input_points(str& points)
{

    if(points.name_action == "scalpel")
    {
        std::cout << "x1:";
        std::cin >> points.x1;
        std::cout << "y1:";
        std::cin >> points.y1;
        std::cout << "x2:";
        std::cin >> points.x2;
        std::cout << "y2:";
        std::cin >> points.y2;
        scalpel(points.x1, points.y1, points.x2, points.y2);
    }
    if(points.name_action == "hemostat")
    {
        std::cout << "x1:";
        std::cin >> points.x1;
        std::cout << "y1:";
        std::cin >> points.y1;
        hemostat(points.x1, points.y1);
    }
    if(points.name_action == "tweezers")
    {
        std::cout << "x1:";
        std::cin >> points.x1;
        std::cout << "y1:";
        std::cin >> points.y1;
        tweezers(points.x1, points.y1);
    }
    if(points.name_action == "suture")
    {
        std::cout << "x1:";
        std::cin >> points.x1;
        std::cout << "y1:";
        std::cin >> points.y1;
        std::cout << "x2:";
        std::cin >> points.x2;
        std::cout << "y2:";
        std::cin >> points.y2;
        suture(points.x1, points.y1, points.x2, points.y2);
    }
}

int main() {
    std::string action = "scalpel";
    std::cout << "The first action always is scalpel." << std::endl;
    str points;
    std::vector<struct str> actions;
    std::cout << "Input coordinates for command " << action << std::endl;
    points.name_action = action;
    input_points(points);
    actions.push_back(points);
    while(true)
    {
        while(true)
        {
            std::cout << "Chose action (scalpel, hemostat, tweezers, suture):" << std::endl;
            std::cin >> action;
            if(action != "scalpel" or action != "hemostat" or action != "tweezers" or action != "suture")
                std::cout << "Wrong command. Try again." << std::endl;
            else
                break;
        }
        std::cout << "Input coordinates for command " << action << std::endl;
        input_points(points);
        actions.push_back(points);
        if(action == "suture" and check_end(actions[0].x1, actions[0].y1,
            actions[0].x2, actions[0].y2, points.x1, points.y1, points.x2, points.y2))
        {
            std::cout << "Operation completed!" << std::endl;
            break;
        }
    }
}
