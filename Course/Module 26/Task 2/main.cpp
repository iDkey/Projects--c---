#include <iostream>
#include <string>
#include <vector>

class Abonent
{
    unsigned long numAbonent{};
    std::string nameAbonent;

public:
    long long getNumber(){
        return numAbonent;
    }
    void setNumber(long long number){
        numAbonent = number;
    }
    std::string getName()
    {
        return nameAbonent;
    }
    void setName(std::string& name)
    {
        nameAbonent = name;
    }
};

class Telephone
{
    unsigned long number{};
    std::string name;
    std::vector<Abonent> phoneBook;
public:
    void add()
    {
        Abonent abonent;
        std::cout << "Input a number of person in 10-digit format:" << std::endl;
        std::cin >> number;
        abonent.setNumber(number);
        std::cout << "Input a name:" << std::endl;
        std::cin >> name;
        abonent.setName(name);
        phoneBook.push_back(abonent);
    }

    void call()
    {
        std::string plug;
        std::cout << "Call by name or number?" << std::endl;
        std::cin >> plug;
        if(plug == "name")
        {
            std::cout << "Enter the name: " << std::endl;
            std::cin >> name;
            if(checkName())
            {
                std::cout << "Call : " << name << std::endl;
            }
            else
            {
                std::cout << "Cant find it name in phone book..." << std::endl;
            }
        }
        if(plug == "number")
        {
            std::cout << "Input the number: " << std::endl;
            std::cin >> number;
            std::cout << "Call: +7 " << number << std::endl;
        }
    }

    bool checkName()
    {
        bool ok = false;
        for(auto & i : phoneBook)
        {
            if (i.getName() == name)
            {
                ok = true;
                break;
            }
        }
        return ok;
    }

    void sms()
    {
        std::string plug;
        std::cout << "Write sms by name or number?" << std::endl;
        std::cin >> plug;
        if(plug == "name")
        {
            std::cout << "Enter the name: " << std::endl;
            std::cin >> name;
            if(checkName())
            {
                std::cout << "Input a text of sms:" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, plug);
                std::cout << "Message: " << plug;
                std::cout << " was sent to " << name << std::endl;
            }
            else
            {
                std::cout << "Cant find it name in phone book..." << std::endl;
            }
        }
        if(plug == "number")
        {
            std::cout << "Input the number: " << std::endl;
            std::cin >> number;
            std::cout << "Input a text of sms:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, plug);
            std::cout << "Message: " << plug;
            std::cout << " was sent on number +7 " << number << std::endl;
        }
    }

};

int main()
{
    Telephone telephone = Telephone();
    std::string action;
    while(action != "exit")
    {
        if(action == "add")
        {
            telephone.add();
        }
        if(action == "call")
        {
            telephone.call();
        }
        if(action == "sms")
        {
            telephone.sms();
        }
        std::cout << "Choose the action (add, call, sms, exit):" << std::endl;
        std::cin >> action;
    }
}