#pragma once
#include "Window.h"

class Monitor {
public:
    bool screen[50][80];

    static void clearScreen(Monitor&);
    void display(Monitor&, Window&);
};

