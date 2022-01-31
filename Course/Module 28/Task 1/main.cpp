#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <vector>

std::vector<int> results = {0, 0, 0, 0, 0, 0};
std::vector<int> swimmerDistance = {0, 0, 0, 0, 0, 0};
std::mutex aces;

bool checkEnd(int swimmerNumber)
{
    return swimmerDistance[swimmerNumber] >= 100 ? true : false;
}

void swimming(int speed, int numSwimmer, std::string name)
{
    int countTime = 0;
    aces.lock();
    while(!checkEnd(numSwimmer))
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        countTime++;
        if(swimmerDistance[numSwimmer] < 100) {
            swimmerDistance[numSwimmer] += speed;
            if (swimmerDistance[numSwimmer] >= 100) {
                swimmerDistance[numSwimmer] = 100;
                results[numSwimmer] = countTime;
            }
        }
        std::cout << name << " swam " << swimmerDistance[numSwimmer] << " meters" << std::endl;
    }
    aces.unlock();
}

void sortingForResults(std::vector<std::string>& swimmerName)
{
    for(int i = 0; i < results.size(); i++)
    {
        for(int j = 0; j < results.size() - 1 - i; ++j)
        {
            if(results[j] > results[j + 1])
            {
                std::swap(results[j], results[j + 1]);
                std::swap(swimmerName[j], swimmerName[j + 1]);
            }
        }
    }
    std::cout << "Results:" << std::endl;
    for(int i = 0; i < results.size(); i++)
    {
        std::cout << swimmerName[i] << " end swim with result in " << results[i] << " seconds" << std::endl;
    }
}

int main() {
    std::vector<std::string> swimmerName(6);
    std::vector<int> swimmerSpeed(6);
    for(int i = 0; i < swimmerName.size(); ++i)
    {
        std::cout << "Input name for " << i + 1 << " swimmer:" << std::endl;
        std::cin >> swimmerName[i];
        std::cout << "Input speed like m/s for " << i + 1 << " swimmer:" << std::endl;
        std::cin >> swimmerSpeed[i];
    }
    std::thread swim1(swimming, swimmerSpeed[0], 0, swimmerName[0]);
    std::thread swim2(swimming, swimmerSpeed[1], 1, swimmerName[1]);
    std::thread swim3(swimming, swimmerSpeed[2], 2, swimmerName[2]);
    std::thread swim4(swimming, swimmerSpeed[3], 3, swimmerName[3]);
    std::thread swim5(swimming, swimmerSpeed[4], 4, swimmerName[4]);
    std::thread swim6(swimming, swimmerSpeed[5], 5, swimmerName[5]);
    swim1.join();
    swim2.join();
    swim3.join();
    swim4.join();
    swim5.join();
    swim6.join();
    sortingForResults(swimmerName);
}
