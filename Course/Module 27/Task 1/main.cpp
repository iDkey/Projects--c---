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
    std::string elfNameBB;
    int countElf = 1;
public:


    int getCountMidBranch() const
    {
        return countMidBranch;
    }
    MidBranch* getMidBranchAt(int index)
    {
        return midBranch[index];
    }
    BigBranch(int inCountMidBranch,std::string inElfNameBB):
            countMidBranch(inCountMidBranch), elfNameBB(inElfNameBB)
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

    int getCountElf() const
    {
        return 1;
    }
    std::string getElfName()
    {
        return elfNameBB;
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
            std::string inElfName;
            std::cout << "Input name for elf:" << std::endl;
            std::cin >> inElfName;
            bigBranch[i] = new BigBranch(getRandomNum(2, 3), inElfName);
        }
    }
};

class Forest {

    int countTrees = 0;
    Tree** trees = nullptr;

public:

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
            if(needElfName == forest->getTreesAt(i)->getBigBranchAt(j)->getElfName())
            {
                neighbors = 1;
                neighbors += forest->getTreesAt(i)->getBigBranchAt(j)->getCountElf();
                for(int k = 0; k < forest->getTreesAt(i)->getBigBranchAt(j)->getCountMidBranch(); k++)
                {
                    neighbors += forest->getTreesAt(i)->getBigBranchAt(j)->getCountMidBranch();
                }
            }
            for(int k = 0; k < forest->getTreesAt(i)->getBigBranchAt(j)->getCountMidBranch(); k++)
            {
                if(needElfName == forest->getTreesAt(i)->getBigBranchAt(j)->getMidBranchAt(k)->getElfName())
                {
                    neighbors = forest->getTreesAt(i)->getBigBranchAt(j)->getCountMidBranch() - 1;
                    neighbors += forest->getTreesAt(i)->getBigBranchAt(j)->getCountElf();
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
