#include <iostream>
#include "Monitor.h"
#include "Window.h"
#include <string>

int main() {
    Monitor monitor{};
    Window window{};
    Window::firstWindow(window);
    monitor.display(monitor, window);

    std::string command;
    while(command != "close")
    {
        if(command == "move")
        {
            window.move(window);
            monitor.display(monitor, window);
        }
        if(command == "resize")
        {
            window.resize(window);
            monitor.display(monitor, window);
        }
        std::cout << "Input command:" << std::endl;
        std::cin >> command;
    }
}
