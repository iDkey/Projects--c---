#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    std::string command;
    cpr::Response answer;
    while(command != "ext")
    {
        if(command == "get")
        {
            answer = cpr::Get(cpr::Url("http://httpbin.org/get"));
            std::cout << answer.text << std::endl;
        }
        if(command == "post")
        {
            answer = cpr::Post(cpr::Url("http://httpbin.org/post"));
            std::cout << answer.text << std::endl;
        }
        if(command == "put")
        {
            answer = cpr::Put(cpr::Url("http://httpbin.org/put"));
            std::cout << answer.text << std::endl;
        }
        if(command == "delete")
        {
            answer = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
            std::cout << answer.text << std::endl;
        }
        if(command == "patch")
        {
            answer = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
            std::cout << answer.text << std::endl;
        }
        std::cout << "Input a command (get, post, put, delete, patch, ext):" << std::endl;
        std::cin >> command;
    }
}
