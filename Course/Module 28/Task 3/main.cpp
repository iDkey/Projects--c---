#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

std::mutex accesCook;
std::mutex accesReadyForDeliver;
std::mutex accesDeliver;
int workDone = 0;
std::vector<std::string> waitingForDelivery;

std::string dishes[] = {"pizza", "soup", "steak", "salad", "sushi"};

int getRandomNumber(int leftBorder, int rightBorder)
{
    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<> randomNumber(leftBorder, rightBorder);
    return randomNumber(gen);
}

void delivering()
{
    bool exit = false;
    do
    {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        accesReadyForDeliver.lock();
        for(auto & i : waitingForDelivery)
        {
            accesDeliver.lock();
            workDone++;

            accesDeliver.unlock();
            std::cout << i << " has delivered" << std::endl;
        }
        waitingForDelivery.clear();

        accesReadyForDeliver.unlock();

        accesDeliver.lock();
        exit = workDone >= 10;
        accesDeliver.unlock();
    }while(!exit);
}

void cooking(std::string dish)
{
    std::cout << dish << " waiting for cooking" << std::endl;

    accesCook.lock();
    std::cout << dish << " is cooking" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << dish << " is ready for delivering" << std::endl;

    accesReadyForDeliver.lock();
    waitingForDelivery.push_back(dish);
    accesReadyForDeliver.unlock();

    accesCook.unlock();
}

int main()
{
    std::thread delivery (delivering);
    bool exit = false;
    do
    {
        std::this_thread::sleep_for(std::chrono::seconds(getRandomNumber(5,5)));
        std::thread kitchen (cooking, dishes[getRandomNumber(0, 4)]);
        kitchen.detach();

        accesDeliver.lock();
        exit = workDone >= 10;

        accesDeliver.unlock();
    }while(!exit);
    delivery.join();
}