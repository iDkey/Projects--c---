#include <iostream>
#include <string>

class Animal
{
protected:
    std::string sound;
public:

    virtual void voice(std::string animal1, std::string animal2)
    {
        std::cout << "unknown voice" << std::endl;
    }
    void setSound(std::string inSound)
    {
        sound = inSound;
    }
};

class Cat : virtual public Animal
{
public:
    virtual void voice(std::string animal1, std::string animal2)
    {
        if(animal1 == "cat" and animal2 == "cat")
        {
            setSound("Purr");
            std::cout << sound;
        }
        else
        {
            setSound("Meow");
            std::cout << sound;
        }
    }

};

class Dog: virtual public Animal
{
public:

    virtual void voice(std::string animal1, std::string animal2)
    {
        if(animal1 == "dog" and animal2 == "dog")
        {
            setSound("Woof");
            std::cout << sound;
        }
        else
        {
            setSound("Bark");
            std::cout << sound;
        }
    }
};

void meeting(Animal* a, Animal* b)
{
    std::string inSound;
    std::cout << "Input first animal (dog or cat):" << std::endl;
    std::string animal1;
    std::cin >> animal1;
    std::cout << "Input second animal (dog or cat):" << std::endl;
    std::string animal2;
    std::cin >> animal2;
    if(animal1 == "dog" and animal2 == "dog")
    {
        a->voice(animal1, animal2);
        std::cout << "-";
        a->voice(animal1, animal2);
        std::cout << std::endl;
    }
    if(animal1 == "dog" and animal2 == "cat")
    {
        a->voice(animal1, animal2);
        std::cout << " ";
        b->voice(animal1, animal2);
        std::cout << std::endl;
    }
    if(animal1 == "cat" and animal2 == "dog")
    {
        b->voice(animal1, animal2);
        std::cout << " ";
        a->voice(animal1, animal2);
        std::cout << std::endl;
    }
    if(animal1 == "cat" and animal2 == "cat")
    {
        b->voice(animal1, animal2);
        std::cout << " ";
        b->voice(animal1, animal2);
        std::cout << std::endl;
    }
}

int main() {
    Animal* a = new Dog();
    Animal* b = new Cat();
    meeting(a, b);

}