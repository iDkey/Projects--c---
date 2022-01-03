#include <iostream>
#include <string>
#include "kbd.h"
#include "gpu.h"
#include "cpu.h"
#include "disk.h"

int main() {
    std::string command = "";
    std::stringstream data;
    while(command != "exit")
    {
        std::cout << "Input a command (summ, save, load, input, display, exit):" << std::endl;
        std::cin >> command;
        if(command == "input")
        {
            callWrite(data);
        }
        if(command == "display")
        {
            callRead(data);
        }
        if(command == "summ")
        {
            compute(data);
        }
        if(command == "save")
        {
            save(data);
        }
        if(command == "load")
        {
            load(data);
        }
    }
}
