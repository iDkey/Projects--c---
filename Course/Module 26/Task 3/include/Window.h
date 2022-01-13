#pragma once

class Window {
private:
    int xPosition;
    int yPosition;
    int height;
    int weight;

public:
    int getXPosition();
    int getYPosition();
    int getHeight();
    int getWeight();

    void move(Window&);
    void resize(Window&);
    
    static void firstWindow(Window&);
};

