#include <iostream>
#include <string>
#include <memory>

struct ControlBlock
{
	int countLinks = 0;
};

class Toy
{
public:
	Toy() : name("SameToy") {};
	Toy(std::string inName) : name(inName) {};

private:
	std::string name;
};

class shared_ptr_toy
{
private:
	Toy* obj;
	ControlBlock* block = new ControlBlock();

public:
	shared_ptr_toy()
	{
		std::cout << "create obj" << std::endl;
		obj = new Toy("SomeName");
	}
	shared_ptr_toy(std::string inName)
	{
		std::cout << "create obj" << std::endl;
		obj = new Toy(inName);
	}

	shared_ptr_toy(const shared_ptr_toy& oth)
	{
		std::cout << "copy obj" << std::endl;
		this->block = oth.block;
		block->countLinks++;
		obj = oth.obj;

	}
	shared_ptr_toy& operator = (const shared_ptr_toy& oth)
	{
		std::cout << "copy = obj" << std::endl;

		if(this == &oth)
			return *this;
		if(obj != nullptr)
			delete obj;
		obj = oth.obj;
		this->block = oth.block;
		block->countLinks++;
		return *this;
	}

	~shared_ptr_toy()
	{
		if(block->countLinks == 0)
		{
			delete block;
			std::cout << "Del count" << std::endl;
			delete obj;
			std::cout << "del obj" << std::endl;
		}
		else
		{
			block->countLinks--;
		}
	}
};

class Dog
{
private:
	std::string name = "";
	int age = 0;
	shared_ptr_toy lovelyToy;
public:
	Dog(std::string inNameDog, shared_ptr_toy& inNameToy, int inAge) : name(inNameDog), lovelyToy(inNameToy)
	{
		if(inAge > 0 and inAge < 30)
			age = inAge;
	}
	Dog() : Dog("SomeName", lovelyToy, 0) {};
	Dog(std::string inName) : Dog(inName, lovelyToy, 0) {};
	Dog(int inAge) : Dog("SomeName", lovelyToy, inAge) {};

	void copyToy(const Dog& oth)
	{
		lovelyToy = oth.lovelyToy;
	}

};

shared_ptr_toy make_shared(std::string toyName)
{
	shared_ptr_toy d1 = shared_ptr_toy(toyName);
	return d1;
}

int main() {
	shared_ptr_toy toy1 = make_shared("ball");

	auto d1 = new Dog("bobik", toy1, 5);
	auto d2 = new Dog("bobik", toy1, 5);

	delete d1;
	delete d2;
}