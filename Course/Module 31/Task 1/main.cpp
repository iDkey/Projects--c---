#include <iostream>
#include <string>
#include <memory>

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
	int *count = new int(0);

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
		*count+=1;
		obj = new Toy(*oth.obj);
	}
	shared_ptr_toy& operator = (const shared_ptr_toy& oth)
	{
		std::cout << "copy = obj" << std::endl;
		*count += 1;
		if(this == &oth)
			return *this;
		if(obj != nullptr)
			delete obj;
		obj = new Toy(*oth.obj);
		return *this;
	}

	~shared_ptr_toy()
	{
		if(*count == 0)
		{
			delete count;
			std::cout << "Del count" << std::endl;
		}
		else
		{
			*count -= 1;
			delete obj;
			std::cout << "del obj" << std::endl;
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

void make_shared(shared_ptr_toy& toy)
{
	std::unique_ptr<Dog> d1 = std::make_unique<Dog>("sharik", toy, 5);
}

int main() {
	shared_ptr_toy ball("ball");
	make_shared(ball);
	std::unique_ptr<Dog> d1 = std::make_unique<Dog>("sharik", ball, 5);
	std::unique_ptr<Dog> d2 = std::make_unique<Dog>("bobik", ball, 5);
}