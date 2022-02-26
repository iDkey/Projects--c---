/*#include <iostream>
#include <string>

class Animal
{
public:
    virtual void meet(Animal*&) = 0;
};

class Cat : public Animal
{
public:
    virtual void meet(Animal*&);
};

class Dog: public Animal
{
public:
    virtual void meet(Animal*&);
};

void Cat::meet(Animal*& f)
{
    const std::type_info& objType = typeid(f);
    if(objType == typeid(*this))
    {
        std::cout << "Meow";
    }
    else
        std::cout << "Murr";
}

void Dog::meet(Animal*& f)
{
    const std::type_info& objType = typeid(f);
    if(objType == typeid(*this))
    {
        std::cout << "Bark";
    }
    else
        std::cout << "Woof";
}

void meeting(Animal* a, Animal* b)
{
    a->meet(b);
    std::cout << " ";
    b->meet(a);
}

int main() {
    Animal* a = new Dog();
    Animal* b = new Cat();
    meeting(a, b);

}*/

#include <iostream>
#include <string>

class Dog;
class Cat;

class Animal
{
public:
    virtual void meet(Animal*) = 0;
    virtual void meet(Cat*) = 0;
    virtual void meet(Dog*) = 0;
};

class Cat : public Animal
{
public:
    Cat() = default;
    virtual void meet(Animal* f)
    {
        f->meet(this);
    };
    virtual void meet(Cat* a)
    {
        std::cout << "Murr Murr";
    };
    virtual void meet(Dog*)
    {
        std::cout << "Bark Meow";
    };
};

class Dog: public Animal
{
public:
    Dog() = default;
    virtual void meet(Animal* f)
    {
        f->meet(this);
    };
    virtual void meet(Cat*)
    {
        std::cout << "Meow Bark";
    };
    virtual void meet(Dog*)
    {
        std::cout << "Woof-Woof";
    };
};

void meeting(Animal* a, Animal* b)
{
    a->meet(b);
}

int main() {
    Animal* a = new Dog();
    Animal* b = new Cat();
    meeting(a, b);

}