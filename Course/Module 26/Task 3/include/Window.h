#pragma once

class Window {
    int xPosition;
    int yPosition;
    int height;
    int weight;
public:
    static void firstWindow(Window&);

    void move(Window&);
    void resize(Window&);

    int getXPosition();
    int getYPosition();
    int getHeight();
    int getWeight();
};

