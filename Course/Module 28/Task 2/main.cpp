#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::mutex acesToArrival;
bool stationIsFree = true;

void moveTrain(int timeTrain, char typeTrain)
{
    std::cout << "Train " << typeTrain << " starts its travel" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(timeTrain));
    bool x = true;
    while(true)
    {
        if(acesToArrival.try_lock())
        {
            acesToArrival.try_lock();
            std::cout << "Train " << typeTrain << " has arrived" << std::endl;
            stationIsFree = false;
            std::string departure;
            while(departure != "depart")
            {
                std::cout << "Input 'depart' when train release the station" << std::endl;
                std::cin >> departure;
            }
            std::cout << "Train " << typeTrain << " has departed" << std::endl;
            stationIsFree = true;
            acesToArrival.unlock();
            break;
        }
        else
        {
            if(x)
            {
                std::cout << "Train " << typeTrain << " is waiting for free station" << std::endl;
                x = false;
            }
        }
    }




}

int getTravelTime(int trainNumber)
{
    int timeTrain = 0;
    std::cout << "Input time for travel for train " << trainNumber << ": " << std::endl;
    std::cin >> timeTrain;
    return timeTrain;
}

int main() {
    int timeTrainA;
    int timeTrainB;
    int timeTrainC;
    timeTrainA = getTravelTime(1);
    timeTrainB = getTravelTime(2);
    timeTrainC = getTravelTime(3);

    std::thread travelTrain1(moveTrain, timeTrainA, 'A');
    std::thread travelTrain2(moveTrain, timeTrainB, 'B');
    std::thread travelTrain3(moveTrain, timeTrainC, 'C');
    travelTrain1.join();
    travelTrain2.join();
    travelTrain3.join();
    std::cout << "All trains has arrived" << std::endl;
}