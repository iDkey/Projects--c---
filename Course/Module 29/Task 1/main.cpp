#include <iostream>
#include <string>

class Animal
{
protected:
    std::string sound;
public:

    virtual void voice()
    {
        std::cout << "unknown voice" << std::endl;
    }
    void setSound(std::string& inSound)
    {
        sound = inSound;
    }
};

class Cat : virtual public Animal
{
public:
    virtual void voice()
    {
        std::cout << sound;
    }

};

class Dog: virtual public Animal
{
public:

    virtual void voice()
    {
        std::cout << sound;
    }
};

void meeting(Animal*& a, Animal*& b)
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
        inSound = "Woof";
        a->setSound(inSound);
        a->voice();
        std::cout << "-";
        inSound = "Woof";
        a->voice();
        std::cout << std::endl;
    }
    if(animal1 == "dog" and animal2 == "cat")
    {
        inSound = "Bark";
        a->setSound(inSound);
        a->voice();
        std::cout << " ";
        inSound = "Meow";
        b->setSound(inSound);
        b->voice();
        std::cout << std::endl;
    }
    if(animal1 == "cat" and animal2 == "dog")
    {
        inSound = "Meow";
        b->setSound(inSound);
        b->voice();
        std::cout << " ";
        inSound = "Bark";
        a->setSound(inSound);
        a->voice();
        std::cout << std::endl;
    }
    if(animal1 == "cat" and animal2 == "cat")
    {
        inSound = "Purr";
        b->setSound(inSound);
        b->voice();
        std::cout << " ";
        inSound = "Purr";
        b->voice();
        std::cout << std::endl;
    }
}

int main() {
    Animal* a = new Dog();
    Animal* b = new Cat();
    meeting(a, b);

}
