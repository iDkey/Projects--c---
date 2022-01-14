#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <cassert>

int getRandomNum(int leftBorder, int rightBorder)
{
    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<> randNum (leftBorder, rightBorder);
    int s = randNum(gen);
    return s;
}

class MidBranch
{

    std::string elfName;

public:

    std::string getElfName() const
    {
        return elfName;
    }

    MidBranch(std::string name): elfName(name)
    {
        assert(name != "None");
    }

};

class BigBranch
{
    int countMidBranch = 0;
    MidBranch** midBranch;

public:

    void addCountMidBranch(int inCountMidBranch)
    {
        countMidBranch = inCountMidBranch;
    }
    int getCountMidBranch() const
    {
        return countMidBranch;
    }
    MidBranch* getMidBranchAt(int index)
    {
        return midBranch[index];
    }
    BigBranch(int inCountMidBranch): countMidBranch(inCountMidBranch)
    {
        assert(inCountMidBranch == 2 or inCountMidBranch == 3);
        midBranch = new MidBranch*[countMidBranch];
        for(int i = 0; i < countMidBranch; ++i)
        {
            std::cout << "Elf's name:" << std::endl;
            std::string name;
            std::cin >> name;
            midBranch[i] = new MidBranch(name);
        }
    }
};

class Tree
{
    int countBigBranch = 0;
    BigBranch** bigBranch;

public:

    void addCountBigBranch(int inCount)
    {
        countBigBranch = inCount;
    }
    int getCountBigBranch() const
    {
        return countBigBranch;
    }
    BigBranch* getBigBranchAt(int index)
    {
        return bigBranch[index];
    }
    Tree(int inCountBigBranch): countBigBranch(inCountBigBranch)
    {
        assert(inCountBigBranch >= 3 and inCountBigBranch <= 5);
        bigBranch = new BigBranch*[countBigBranch];
        for(int i = 0; i < countBigBranch; ++i)
        {
            bigBranch[i] = new BigBranch(getRandomNum(2, 3));
        }
    }
};

class Forest {

    int countTrees = 0;
    Tree** trees = nullptr;

public:

    void addCountTrees(int inCountTrees)
    {
        countTrees = inCountTrees;
    }
    int getCountTrees() const
    {
        return countTrees;
    }
    Tree* getTreesAt(int index)
    {
        if(this == nullptr) return nullptr;
        if(index < 0) return nullptr;
        if(index >= this->countTrees) return nullptr;
        return trees[index];
    }
    Forest(int inCountTrees): countTrees(inCountTrees)
    {
        assert(inCountTrees == 5);
        trees = new Tree*[countTrees];
        for(int i = 0; i < countTrees; ++i)
        {
            trees[i] = new Tree(getRandomNum(3, 5));
        }
    }
};

int findElfName(auto& needElfName, auto& forest)
{
    int neighbors = -1;
    for(int  i = 0; i < forest->getCountTrees(); ++i)
    {
        for(int j = 0; j < forest->getTreesAt(i)->getCountBigBranch(); j++)
        {
            for(int k = 0; k < forest->getTreesAt(i)->getBigBranchAt(j)->getCountMidBranch(); k++)
            {
                if(needElfName == forest->getTreesAt(i)->getBigBranchAt(j)->getMidBranchAt(k)->getElfName())
                {
                    neighbors = forest->getTreesAt(i)->getBigBranchAt(j)->getCountMidBranch() - 1;
                }
            }
        }
    }
    return neighbors;
}

int main()
{
    auto* forest = new Forest(5);

    for(int i = 0; i < forest->getCountTrees(); ++i)
    {
        std::cout << "Tree #" << i + 1 << ": ";
        std::cout << forest->getTreesAt(i)->getCountBigBranch() << std::endl;
    }

    std::string needElfName;
    std::cout << "Input elf's name which you want to find:" << std::endl;
    std::cin >> needElfName;

    int neighbors = findElfName(needElfName, forest);
    if(neighbors != -1)
    {
        std::cout << needElfName << "'s has " << neighbors << " neighbors";
    }
    else
    {
        std::cout << needElfName << " has not living here." << std::endl;
    }
}
