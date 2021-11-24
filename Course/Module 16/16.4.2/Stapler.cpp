#include <iostream>
#include <string>

int main()
{
    int left, right;

    std::cout << "Onput left part:" << std::endl;
    std::cin >> left;
    std::cout << "Onput left part:" << std::endl;
    std::cin >> right;

    std::string str = std::to_string(left) + '.' + std::to_string(right);

    double result = std::stod(str);
    
    std::cout<< result;
}