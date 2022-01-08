#pragma once

class Window {
public:
    int xPosition;
    int yPosition;
    int height;
    int weight;

    static void firstWindow(Window&);

    void move(Window&);
    void resize(Window&);
};

