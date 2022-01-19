//check
#include <iostream>
#include <ctime>
#include <random>
#include <cassert>
#include <vector>

int getRandomNumber(int leftBorder, int rightBorder)
{
    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution randNumber (leftBorder, rightBorder);
    return randNumber(gen);
}

class Worker
{
    bool isBusy = false;

public:

    bool getIsBusy() const
    {
        return isBusy;
    }
    void setIsBusy()
    {
        isBusy = true;
    }
    explicit Worker(bool inIsBusy): isBusy(inIsBusy)
    {
        assert(inIsBusy == false);
    }
};

class MidManager
{
    int countWorkers{};
    int midManagerIndex{};
    //Worker** workers = nullptr;
    std::vector<Worker*> workers;
    int countTasksForCommand{};

public:

    int getCountTasksForCommand() const
    {
        return countTasksForCommand;
    }
    void setCountTasksForCommand(int inCountTasksForCommand)
    {
        countTasksForCommand = inCountTasksForCommand;
    }
    int getCountWorkers() const
    {
        return countWorkers;
    }
    Worker* getWorkersAt(int index)
    {
        if(index < 0) return nullptr;
        if(index >= countWorkers) return nullptr;
        return workers[index];
    }
    void setMidManagerIndex(int& index)
    {
        midManagerIndex = index;
    }
    int getMidManagerIndex() const
    {
        return midManagerIndex;
    }
    explicit MidManager(int inCountWorkers): countWorkers(inCountWorkers)
    {
        assert(inCountWorkers > 0);
        //workers = new Worker*[countWorkers];
        for(int i = 0; i < countWorkers; ++i)
        {
            //workers[i] = new Worker(false);
            auto* worker = new Worker(false);
            workers.push_back(worker);
        }
    }
};

class HeadMaster
{
    int generalTask{};
    int countCommand{};
    //MidManager** midManagers = nullptr;
    std::vector<MidManager*> midManagers;

public:

    void setGeneralTask(int inGeneralTask)
    {
        generalTask = inGeneralTask;
    }
    int getCountCommand() const
    {
        return countCommand;
    }
    MidManager* getMidManagerAt(int index)
    {
        if(index < 0) return nullptr;
        if(index >= countCommand) return nullptr;
        return midManagers[index];
    }
    explicit HeadMaster(int inCountCommand): countCommand(inCountCommand)
    {
        assert(inCountCommand > 0);
        //midManagers = new MidManager*[countCommand];
        for(int i = 0; i < countCommand; ++i)
        {
            int inCountWorkers;
            std::cout << "Input count of workers in command #" << i + 1 << std::endl;
            std::cin >> inCountWorkers;
            auto* midManager = new MidManager(inCountWorkers);
            midManagers.push_back(midManager);
            //midManagers[i] = new MidManager(inCountWorkers);
            midManagers[i]->setMidManagerIndex(i);
        }
    }

};

HeadMaster * firstSetting()
{
    int countCommand;
    std::cout << "Input count of command:" << std::endl;
    std::cin >> countCommand;
    auto headMaster = new HeadMaster(countCommand);
    return headMaster;
}

bool checkBusyWorkers(auto& headMaster)
{
    bool allBusy = true;
    for(int i = 0; i < headMaster->getCountCommand(); i++)
    {
        for(int j = 0; j < headMaster->getMidManagerAt(i)->getCountWorkers(); j++)
        {
            if(!headMaster->getMidManagerAt(i)->getWorkersAt(j)->getIsBusy())
            {
                allBusy = false;
                return allBusy;
            }
        }
    }
    return allBusy;
}

void setWork(auto& headMaster)
{
    while(!checkBusyWorkers(headMaster))
    {
        std::cout << "Input a task:" << std::endl;
        int inGeneralTask;
        std::cin >> inGeneralTask;
        headMaster->setGeneralTask(inGeneralTask);
        for(int i = 0; i < headMaster->getCountCommand(); i++)
        {
            auto midManager = headMaster->getMidManagerAt(i);
            int inCountTasksForCommand = getRandomNumber(1, inGeneralTask + midManager->getMidManagerIndex());
            midManager->setCountTasksForCommand(inCountTasksForCommand);
            for(int j = 0; j < midManager->getCountWorkers() and midManager->getCountTasksForCommand() != 0; j++)
            {
                auto worker = midManager->getWorkersAt(j);
                if(!worker->getIsBusy())
                {
                    worker->setIsBusy();
                    inCountTasksForCommand = midManager->getCountTasksForCommand() - 1;
                    midManager->setCountTasksForCommand(inCountTasksForCommand);
                }
            }
        }
    }
    std::cout << "All workers are busy" << std::endl;
}

int main() {
    auto headMaster = firstSetting();
    setWork(headMaster);
}
