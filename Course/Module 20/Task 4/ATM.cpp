#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

void filling()
{
    std::ifstream stash("A:\\Programs\\Projects (c++)\\Course\\Module 20\\Task 4\\stash.txt");
    int count_bills = 0;
    std::string plug;
    while(!stash.eof())
    {
        stash >> plug;
        count_bills++;
    }
    stash.close();
    if (count_bills <= 1000)
    {
        int mass_of_bills[] = {100, 200, 500, 1000, 2000, 5000};
        std::ofstream stash("A:\\Programs\\Projects (c++)\\Course\\Module 20\\Task 4\\stash.txt", std::ios::app);
        srand(time(0));
        while (1001 - count_bills > 0)
        {
            stash << mass_of_bills[rand() % 6] << "\n";
            count_bills++;
        }
        stash.close();
    }
    else
        std::cout << "ATM is already full." << std::endl;
}

void withdrawal_of_funds(int sum)
{
    int count_of_bills[] = {0, 0, 0, 0, 0, 0};
    while (sum - 5000 >= 0)
    {
        sum -= 5000;
        count_of_bills[5] += 1;
    }
    while (sum - 2000 >= 0)
    {
        sum -= 2000;
        count_of_bills[4] += 1;
    }
    while (sum - 1000 >= 0)
    {
        sum -= 1000;
        count_of_bills[3] += 1;
    }
    while (sum - 500 >= 0)
    {
        sum -= 500;
        count_of_bills[2] += 1;
    }
    while (sum - 200 >= 0)
    {
        sum -= 200;
        count_of_bills[1] += 1;
    }
    while (sum - 100 >= 0)
    {
        sum -= 100;
        count_of_bills[0] += 1;
    }
    
    int count_of_bills_in[] = {0, 0, 0, 0, 0, 0};
    std::vector<int> vec;
    std::ifstream stash_o("A:\\Programs\\Projects (c++)\\Course\\Module 20\\Task 4\\stash.txt");
    while(!stash_o.eof())
    {
        int plug;
        stash_o >> plug;
        vec.push_back(plug);
        if (plug == 100)
        {
            count_of_bills_in[0] += 1;
        }
        if (plug == 200)
        {
            count_of_bills_in[1] += 1;
        }
        if (plug == 500)
        {
            count_of_bills_in[2] += 1;
        }
        if (plug == 1000)
        {
            count_of_bills_in[3] += 1;
        }
        if (plug == 2000)
        {
            count_of_bills_in[4] += 1;
        }
        if (plug == 5000)
        {
            count_of_bills_in[5] += 1;
        }
    }
    stash_o.close();

    vec.resize(vec.size() - 1);

    if (count_of_bills[0] <= count_of_bills_in[0] and count_of_bills[1] <= count_of_bills_in[1] and count_of_bills[2] <= count_of_bills_in[2] and
        count_of_bills[3] <= count_of_bills_in[3] and count_of_bills[4] <= count_of_bills_in[4] and count_of_bills[5] <= count_of_bills_in[5])
    {
            for (int i = 0; i < vec.size(); ++i)
            {
                bool back = true;
                if (vec[i] == 5000 and count_of_bills[5] > 0)
                {
                    std::swap(vec[i], vec[vec.size() - 1]);
                    vec.resize(vec.size() - 1);
                    count_of_bills[5] -= 1;
                    back = false;
                }
                if (vec[i] == 2000 and count_of_bills[4] > 0)
                {
                    std::swap(vec[i], vec[vec.size() - 1]);
                    vec.resize(vec.size() - 1);
                    count_of_bills[5] -= 1;
                    back = false;
                }
                if (vec[i] == 1000 and count_of_bills[3] > 0)
                {
                    std::swap(vec[i], vec[vec.size() - 1]);
                    vec.resize(vec.size() - 1);
                    count_of_bills[5] -= 1;
                    back = false;
                }
                if (vec[i] == 500 and count_of_bills[2] > 0)
                {
                    std::swap(vec[i], vec[vec.size() - 1]);
                    vec.resize(vec.size() - 1);
                    count_of_bills[5] -= 1;
                    back = false;
                }
                if (vec[i] == 200 and count_of_bills[1] > 0)
                {
                    std::swap(vec[i], vec[vec.size() - 1]);
                    vec.resize(vec.size() - 1);
                    count_of_bills[5] -= 1;
                    back = false;
                }
                if (vec[i] == 100 and count_of_bills[0] > 0)
                {
                    std::swap(vec[i], vec[vec.size() - 1]);
                    vec.resize(vec.size() - 1);
                    count_of_bills[5] -= 1;
                    back = false;
                }
                if (!back)
                    i--;
            }
            std::ofstream stash_i("A:\\Programs\\Projects (c++)\\Course\\Module 20\\Task 4\\stash.txt");
            for (int i = 0; i < vec.size(); i++)
            {
                stash_i << vec[i] << "\n";
            }
    }
    else
    {
        std::cout << "Not enough bills" << std::endl;
    }
    
}

int main()
{
    char oper;
    std::cin >> oper;
    if (oper == '+')
    {
        filling();
    }
    if (oper == '-')
    {
        int sum;
        std::cout << "Input a summ: " << std::endl;
        std::cin >> sum;
        withdrawal_of_funds(sum);
    }
}