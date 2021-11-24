#include <iostream>
#include <vector>

int main()
{
    std::vector<float> price = {2.5, 4.25, 3.0, 10.0};
    std::vector<int> purchase = {1, 1, 0, 3};
    float total_price = 0;

    for(int i = 0; i < purchase.size(); i++)
    {
        total_price += price[purchase[i]];
    }

    std::cout << "Total price is " << total_price << std::endl;
}