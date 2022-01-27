#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

std::mutex kitchenWork;
std::vector<std::string> workDone;
std::vector<std::string> waitingForDelivery;
bool delivered = false;
bool cooked = false;
std::string dishes[] = {"pizza", "soup", "steak", "salad", "sushi"};

int getRandomNumber(int leftBorder, int rightBorder)
{
    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<> randomNumber(leftBorder, rightBorder);
    return randomNumber(gen);
}

void cooking(const std::string& dish)
{
    std::this_thread::sleep_for(std::chrono::seconds(getRandomNumber(5, 15)));
    kitchenWork.lock();
    std::cout << "The " << dish << " is getting ready" << std::endl;
    waitingForDelivery.push_back(dish);
    kitchenWork.unlock();
}

void delivering()
{
    std::this_thread::sleep_for(std::chrono::seconds(30));
    kitchenWork.lock();
    for(auto & i : waitingForDelivery)
    {
        std::cout << "The " << i << " is delivered" << std::endl;
        workDone.push_back(i);
    }
    waitingForDelivery.clear();
    kitchenWork.unlock();
    delivered = false;
}

void order(int sleepTime)
{
    std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
    std::thread dishOrder (cooking, dishes[getRandomNumber(0,4)]);
    dishOrder.detach();
}

int main() {

    while(workDone.size() < 10)
    {
        if(!cooked)
        {
            std::thread ordering(order, getRandomNumber(5, 10));
            ordering.join();
        }
        if(!delivered)
        {
            delivered = true;
            std::thread delivery (delivering);
            delivery.detach();
        }
    }
}
