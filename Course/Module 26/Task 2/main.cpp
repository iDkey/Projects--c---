#include <iostream>
#include <string>
#include <vector>

class Abonent
{
public:
    unsigned long numAbonent{};
    std::string nameAbonent;
};

class Telephone
{
public:
    unsigned long number{};
    std::string name;
    static std::vector<Abonent> phoneBook;

    static void add()
    {
        Abonent abonent = *new Abonent();
        std::cout << "Input a number of person in 10-digit format:" << std::endl;
        std::cin >> abonent.numAbonent;
        std::cout << "Input a name:" << std::endl;
        std::cin >> abonent.nameAbonent;
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
            if(checkName(name))
            {
                std::cout << "Call : " << name;
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

    static bool checkName(std::string& name)
    {
        bool ok = false;
        for(auto & i : phoneBook)
        {
            if (i.nameAbonent == name)
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
        std::cout << "Call by name or number?" << std::endl;
        std::cin >> plug;
        if(plug == "name")
        {
            std::cout << "Enter the name: " << std::endl;
            std::cin >> name;
            if(checkName(name))
            {
                std::cout << "Input a text of sms:" << std::endl;
                std::getline(std::cin, plug);
                std::cout << "Message: " << plug << std::endl;
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
            std::getline(std::cin, plug);
            std::cout << "Message: '" << plug << "'" << std::endl;
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
            Telephone::add();
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