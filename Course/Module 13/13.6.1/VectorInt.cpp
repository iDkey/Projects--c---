#include <iostream>
#include <vector>


std::vector<int> remove(std::vector<int> vec, int del)
{   
    int count = 0;
    for(int i = 0; i < vec.size() - count; i++)
    {
        if (vec[i] == del)
        {
            count++;
            int a = vec[i];
            for (int j = i; j < vec.size() - 1; j++)
            {
                vec[j] = vec[j + 1];
            }
            vec[vec.size() - 1] = a;
            i--;
        }

    }
    vec.resize(vec.size() - count);
    return vec;
}

int main()
{

    int co;
    while (1){
    std::cout << "Input count numbers:"<< std::endl;
    std::cin >> co;
    if (co > 0)
        break;
    else
        std::cout << "Wrong data!\n";
    }

    std::vector<int> vec(co);

    for (int i = 0; i < co; i++)
    {
        std::cout << "Input number:" << std::endl;
        std::cin >> vec[i];
    }

    int del;
    std::cout << "Input number for deleting:" << std::endl;
    std::cin >> del;
    
    vec = remove(vec, del);
        
        for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
}