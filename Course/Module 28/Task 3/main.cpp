#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

std::mutex acesKitchenMtx;
std::mutex acesDeliveryMtx;
std::vector<std::string> workDone;
std::vector<std::string> waitingForDelivery;

std::string dishes[] = {"pizza", "soup", "steak", "salad", "sushi"};

int getRandomNumber(int leftBorder, int rightBorder)
{
    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<> randomNumber(leftBorder, rightBorder);
    return randomNumber(gen);
}

void cooking(std::string dish)
{
    std::cout << dish << " waiting for cooking" << std::endl;
    acesKitchenMtx.lock();
    std::cout << dish << " is cooking" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << dish << " is ready for delivering" << std::endl;
    acesDeliveryMtx.lock();
    waitingForDelivery.push_back(dish);
    acesDeliveryMtx.unlock();
    acesKitchenMtx.unlock();
}

void delivering()
{
    std::this_thread::sleep_for(std::chrono::seconds(30));
    acesDeliveryMtx.lock();
    for(auto & i : waitingForDelivery)
    {
        workDone.push_back(i);
        std::cout << i << " has delivered" << std::endl;
    }
    waitingForDelivery.clear();
    acesDeliveryMtx.unlock();
}

void order()
{
    //acesKitchenMtx.lock();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::thread kitchen (cooking, dishes[getRandomNumber(0, 4)]);
    kitchen.detach();
    //acesKitchenMtx.unlock();
}

int main() {
    while(workDone.size() < 10)
    {
        std::thread orders (order);
        std::thread deliver (delivering);
        orders.detach();
        //std::thread kitchen (cooking, dishes[getRandomNumber(0, 4)]);
        //kitchen.detach();
        deliver.join();
    }


}
