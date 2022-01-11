#pragma once
#include "Window.h"

class Monitor {
    bool screen[50][80];
public:
    static void clearScreen(Monitor&);
    void display(Monitor&, Window&);
};

